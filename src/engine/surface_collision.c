#include <ultra64.h>

#include "sm64.h"
#include "game/level_update.h"
#include "game/debug.h"
#include "game/camera.h"
#include "game/mario.h"
#include "behavior_script.h"
#include "surface_collision.h"
#include "surface_load.h"
#include "game/object_list_processor.h"

#define gaiseki(a, b, c, d, e, f) (d - b) * (e - c) - (c - a) * (f - d)

struct Plane move_mapplane;

/**
 * Basically a local variable that passes through floor geo info.
 */
struct Plane sFloorGeo;

struct Plane hit_roofplane;

struct Surface Xwall[4];

/**************************************************
 *                      WALLS                      *
 **************************************************/

/**
 * Iterate through the list of walls until all walls are checked and
 * have given their wall push.
 */
static s32 BG_WallCheck(struct SurfaceNode *bgcheck_list, struct WallCollisionData *wallcheckp) {
    f32 A, B, C, D, dR, dRf;
    f32 x1, x2, x3, y1, y2, y3;

    f32 px = wallcheckp->x;
    f32 py = wallcheckp->y + wallcheckp->offsetY;
    f32 pz = wallcheckp->z;
    f32 r = wallcheckp->radius;

    s32 wallflag = 0;
    s32 g_flag;
    struct Surface *wall;

    while (bgcheck_list != NULL) {
        wall = bgcheck_list->surface;
        bgcheck_list = bgcheck_list->next;

        if (wall->normal.x < -0.707 || 0.707 < wall->normal.x) {
            x1 = -(wall->vertex1[2]); x2 = -(wall->vertex2[2]); x3 = -(wall->vertex3[2]);
            y1 = wall->vertex1[1]; y2 = wall->vertex2[1]; y3 = wall->vertex3[1];
            g_flag = 0;
            if (gaiseki(-pz, py, x1, y1, x2, y2) > 0) g_flag++;
            if (gaiseki(-pz, py, x2, y2, x3, y3) > 0) g_flag++;
            if (gaiseki(-pz, py, x3, y3, x1, y1) > 0) g_flag++;
            if (g_flag == 1 || g_flag == 2) continue;
        } else {
            x1 = wall->vertex1[0]; x2 = wall->vertex2[0]; x3 = wall->vertex3[0];
            y1 = wall->vertex1[1]; y2 = wall->vertex2[1]; y3 = wall->vertex3[1];
            g_flag = 0;
            if (gaiseki(px, py, x1, y1, x2, y2) > 0) g_flag++;
            if (gaiseki(px, py, x2, y2, x3, y3) > 0) g_flag++;
            if (gaiseki(px, py, x3, y3, x1, y1) > 0) g_flag++;
            if (g_flag == 1 || g_flag == 2) continue;
        }

        A = wall->normal.x;
        B = wall->normal.y;
        C = wall->normal.z;
        D = wall->originOffset;

        dR = A * px + B * py + C * pz + D;
        dRf = dR >=0 ? dR : -dR;

        if (dRf < r) {
            wallcheckp->x += A * (r - dR);
            wallcheckp->z += C * (r - dR);

            if (wallcheckp->numWalls < 4) {
                wallcheckp->walls[wallcheckp->numWalls] = &Xwall[wallcheckp->numWalls];
                Xwall[wallcheckp->numWalls].normal.x = wall->normal.x;
                Xwall[wallcheckp->numWalls].normal.y = wall->normal.y;
                Xwall[wallcheckp->numWalls].normal.z = wall->normal.z;
                Xwall[wallcheckp->numWalls].originOffset = wall->originOffset;

                wallcheckp->numWalls++;
            }

            wallflag++;
        }
    }

    return wallflag;
}

/**
 * Formats the position and wall search for mcWallCheck.
 */
s32 WallCheck(f32 *wX, f32 *wY, f32 *wZ, f32 offsetY, f32 r) {
    struct WallCollisionData wall;
    s32 wallcount = 0;

    wall.offsetY = offsetY;
    wall.radius = r;
    wall.x = *wX; wall.y = *wY; wall.z = *wZ;

    wallcount = mcWallCheck(&wall);

    *wX = wall.x; *wY = wall.y; *wZ = wall.z;

    return wallcount;
}

/**
 * Find wall collisions and receive their push.
 */
s32 mcWallCheck(struct WallCollisionData *wall) {
    struct SurfaceNode *bgcheck_list;
    s16 area_x, area_z;
    s32 wallcount = 0;
    wall->numWalls = 0;

    if (wall->x < -LEVEL_BOUNDARY_MAX || LEVEL_BOUNDARY_MAX < wall->x) return wallcount;
    if (wall->z < -LEVEL_BOUNDARY_MAX || LEVEL_BOUNDARY_MAX < wall->z) return wallcount;

    area_x = (wall->x + LEVEL_BOUNDARY_MAX) / CELL_SIZE;
    area_z = (wall->z + LEVEL_BOUNDARY_MAX) / CELL_SIZE;
    bgcheck_list = gStaticSurfacePartition[area_z][area_x][SPATIAL_PARTITION_WALLS].next;
    wallcount += BG_WallCheck(bgcheck_list, wall);

    bgcheck_list = gDynamicSurfacePartition[SPATIAL_PARTITION_WALLS].next;
    wallcount += BG_WallCheck(bgcheck_list, wall);

    return wallcount;
}

/**************************************************
 *                     CEILINGS                    *
 **************************************************/

/**
 * Iterate through the list of ceilings and find the first ceiling over a given point.
 */
static struct Surface *BG_RoofCheck(struct SurfaceNode *bgcheck_list, s32 x, s32 y, s32 z, f32 *planeY) {
    struct Surface *bgcheck_data, *bgcheck_hitdata;
    f32 x1, z1, x2, z2, x3, z3;
    f32 A, B, C, D, roofY;

    bgcheck_hitdata = NULL;

    while (bgcheck_list != NULL) {
        bgcheck_data = bgcheck_list->surface;
        bgcheck_list = bgcheck_list->next;

        x1 = bgcheck_data->vertex1[0]; x2 = bgcheck_data->vertex2[0]; x3 = bgcheck_data->vertex3[0];
        z1 = bgcheck_data->vertex1[2]; z2 = bgcheck_data->vertex2[2]; z3 = bgcheck_data->vertex3[2];

        if (gaiseki(x, z, x1, z1, x2, z2) > 0) continue;
        if (gaiseki(x, z, x2, z2, x3, z3) > 0) continue;
        if (gaiseki(x, z, x3, z3, x1, z1) > 0) continue;

        A = bgcheck_data->normal.x;
        B = bgcheck_data->normal.y;
        C = bgcheck_data->normal.z;
        D = bgcheck_data->originOffset;
        roofY = -(A * x + C * z + D) / B;

        if (y - (roofY - (-78.0f)) > 0) continue;

        *planeY = roofY;
        bgcheck_hitdata = bgcheck_data;
        break;
    }

    return bgcheck_hitdata;
}

f32 RoofCheck(f32 px, f32 py, f32 pz, struct Plane **hitplane) {
    f32 planeY = 20000.0f;
    *hitplane = NULL;
    planeY = mcRoofCheck(px, py, pz, hitplane);
    return planeY;
}

/**
 * Find the lowest ceiling above a given position and return the height.
 */
f32 mcBGRoofCheck(f32 px, f32 py, f32 pz, struct Surface **bgdata) {
    s16 area_z, area_x;
    struct Surface *bgcheck_data;
    struct Surface *bgcheck_data_dynamic;
    struct SurfaceNode *bgcheck_list;
    f32 planeY = 20000.0f;
    f32 planeY_dynamic = 20000.0f;
    *bgdata = NULL;

    if (px < -LEVEL_BOUNDARY_MAX || LEVEL_BOUNDARY_MAX < px) return planeY;
    if (pz < -LEVEL_BOUNDARY_MAX || LEVEL_BOUNDARY_MAX < pz) return planeY;

    bgcheck_list = gDynamicSurfacePartition[SPATIAL_PARTITION_CEILS].next;
    bgcheck_data_dynamic = BG_RoofCheck(bgcheck_list, px, py, pz, &planeY_dynamic);

    area_x = (s16)((px + LEVEL_BOUNDARY_MAX) / CELL_SIZE);
    area_z = (s16)((pz + LEVEL_BOUNDARY_MAX) / CELL_SIZE);
    bgcheck_list = gStaticSurfacePartition[area_z][area_x][SPATIAL_PARTITION_CEILS].next;
    bgcheck_data = BG_RoofCheck(bgcheck_list, px, py, pz, &planeY);

    if (planeY_dynamic < planeY) {
        bgcheck_data = bgcheck_data_dynamic;
        planeY = planeY_dynamic;
    }

    *bgdata = bgcheck_data;

    return planeY;
}

f32 mcRoofCheck(f32 px, f32 py, f32 pz, struct Plane **hitplane) {
    f32 planeY;
    struct Surface *bgcheck_data;
    *hitplane = NULL;

    planeY = mcBGRoofCheck(px, py, pz, &bgcheck_data);

    if (bgcheck_data != NULL) {
        hit_roofplane.normalX = bgcheck_data->normal.x;
        hit_roofplane.normalY = bgcheck_data->normal.y;
        hit_roofplane.normalZ = bgcheck_data->normal.z;
        hit_roofplane.originOffset = bgcheck_data->originOffset;
        *hitplane = &hit_roofplane;
    }

    return planeY;
}

/**************************************************
 *                     FLOORS                      *
 **************************************************/

/**
 * Iterate through the list of floors and find the first floor under a given point.
 */
static struct Surface *BG_GroundCheck(struct SurfaceNode *bgcheck_list, s32 x, s32 y, s32 z, f32 *planeY) {
    struct Surface *bgcheck_data, *bgcheck_hitdata;
    f32 x1, z1, x2, z2, x3, z3;
    f32 A, B, C, D, groundY;

    bgcheck_hitdata = NULL;

    while (bgcheck_list != NULL) {
        bgcheck_data = bgcheck_list->surface;
        bgcheck_list = bgcheck_list->next;

        x1 = bgcheck_data->vertex1[0]; x2 = bgcheck_data->vertex2[0]; x3 = bgcheck_data->vertex3[0];
        z1 = bgcheck_data->vertex1[2]; z2 = bgcheck_data->vertex2[2]; z3 = bgcheck_data->vertex3[2];

        if (gaiseki(x, z, x1, z1, x2, z2) < 0) continue;
        if (gaiseki(x, z, x2, z2, x3, z3) < 0) continue;
        if (gaiseki(x, z, x3, z3, x1, z1) < 0) continue;

        A = bgcheck_data->normal.x;
        B = bgcheck_data->normal.y;
        C = bgcheck_data->normal.z;
        D = bgcheck_data->originOffset;
        groundY = -(A * x + C * z + D) / B;

        if (y - (groundY + -78.0f) < 0) continue;

        *planeY = groundY;
        bgcheck_hitdata = bgcheck_data;
        break;
    }

    return bgcheck_hitdata;
}

/**
 * Find the height of the highest floor below a point.
 */
f32 BGcheck(f32 px, f32 py, f32 pz) {
    struct Surface *bgdata;
    f32 planeY;

    planeY = mcBGGroundCheck(px, py, pz, &bgdata);

    return planeY;
}

f32 GroundCheck(f32 px, f32 py, f32 pz, struct Plane **hitplane) {
    f32 planeY;
    *hitplane = NULL;
    planeY = mcGroundCheck(px, py, pz, hitplane);
    return planeY;
}

/**
 * Find the highest dynamic floor under a given position. Perhaps originally static and
 * and dynamic floors were checked separately.
 */
f32 mcMoveGroundCheck(f32 px, f32 py, f32 pz, struct Surface **bgcheck_data) {
    struct SurfaceNode *bgcheck_list;
    struct Surface *bgcheck_data_dynamic;
    f32 planeY = -11000.0f;

    bgcheck_list = gDynamicSurfacePartition[SPATIAL_PARTITION_FLOORS].next;
    bgcheck_data_dynamic = BG_GroundCheck(bgcheck_list, px, py, pz, &planeY);

    *bgcheck_data = bgcheck_data_dynamic;

    return planeY;
}

/**
 * Find the highest floor under a given position and return the height.
 */
f32 mcBGGroundCheck(f32 px, f32 py, f32 pz, struct Surface **bgdata) {
    s16 area_z, area_x;
    struct Surface *bgcheck_data;
    struct Surface *bgcheck_data_dynamic;
    struct SurfaceNode *bgcheck_list;
    f32 planeY = -11000.0f;
    f32 planeY_dynamic = -11000.0f;
    *bgdata = NULL;

    if (px < -LEVEL_BOUNDARY_MAX || LEVEL_BOUNDARY_MAX < px) return planeY;
    if (pz < -LEVEL_BOUNDARY_MAX || LEVEL_BOUNDARY_MAX < pz) return planeY;

    bgcheck_list = gDynamicSurfacePartition[SPATIAL_PARTITION_FLOORS].next;
    bgcheck_data_dynamic = BG_GroundCheck(bgcheck_list, px, py, pz, &planeY_dynamic);

    area_x = (s16)((px + LEVEL_BOUNDARY_MAX) / CELL_SIZE);
    area_z = (s16)((pz + LEVEL_BOUNDARY_MAX) / CELL_SIZE);
    bgcheck_list = gStaticSurfacePartition[area_z][area_x][SPATIAL_PARTITION_FLOORS].next;
    bgcheck_data = BG_GroundCheck(bgcheck_list, px, py, pz, &planeY);

    if (bgcheck_data == NULL) gNumFindFloorMisses++;

    if (planeY_dynamic > planeY) {
        bgcheck_data = bgcheck_data_dynamic;
        planeY = planeY_dynamic;
    }

    *bgdata = bgcheck_data;

    return planeY;
}

/**
 * Return the floor height underneath (xPos, yPos, zPos) and populate `floorGeo`
 * with data about the floor's normal vector and origin offset. Also update
 * sFloorGeo.
 */
f32 mcGroundCheck(f32 px, f32 py, f32 pz, struct Plane **hitplane) {
    f32 planeY;
    struct Surface *bgcheck_data;
    *hitplane = NULL;
    planeY = mcBGGroundCheck(px, py, pz, &bgcheck_data);

    if (bgcheck_data != NULL) {
        sFloorGeo.normalX = bgcheck_data->normal.x;
        sFloorGeo.normalY = bgcheck_data->normal.y;
        sFloorGeo.normalZ = bgcheck_data->normal.z;
        sFloorGeo.originOffset = bgcheck_data->originOffset;
        *hitplane = &sFloorGeo;
    }

    return planeY;
}

/**************************************************
 *               ENVIRONMENTAL BOXES               *
 **************************************************/

/**
 * Finds the height of water at a given location.
 */
f32 mcWaterCheck(f32 x, f32 z) {
    s32 i;
    s32 numRegions;
    s16 val;
    f32 loX, hiX, loZ, hiZ;
    f32 waterLevel = -11000.0f;
    s16 *p = gEnvironmentRegions;

    if (p != NULL) {
        numRegions = *p++;

        for (i = 0; i < numRegions; i++) {
            val = *p++;
            loX = *p++;
            loZ = *p++;
            hiX = *p++;
            hiZ = *p++;

            // If the location is within a water box and it is a water box.
            // Water is less than 50 val only, while above is gas and such.
            if (loX < x && x < hiX && loZ < z && z < hiZ && val < 50) {
                // Set the water height. Since this breaks, only return the first height.
                waterLevel = *p;
                break;
            }
            p++;
        }
    }

    return waterLevel;
}

/**
 * Finds the height of the poison gas (used only in HMC) at a given location.
 */
f32 find_poison_gas_level(f32 x, f32 z) {
    s32 i;
    s32 numRegions;
    UNUSED s32 unused;
    s16 val;
    f32 loX, hiX, loZ, hiZ;
    f32 gasLevel = -11000.0f;
    s16 *p = gEnvironmentRegions;

    if (p != NULL) {
        numRegions = *p++;

        for (i = 0; i < numRegions; i++) {
            val = *p;

            if (val >= 50) {
                loX = *(p + 1);
                loZ = *(p + 2);
                hiX = *(p + 3);
                hiZ = *(p + 4);

                // If the location is within a gas's box and it is a gas box.
                // Gas has a value of 50, 60, etc.
                if (loX < x && x < hiX && loZ < z && z < hiZ && val % 10 == 0) {
                    // Set the gas height. Since this breaks, only return the first height.
                    gasLevel = *(p + 5);
                    break;
                }
            }

            p += 6;
        }
    }

    return gasLevel;
}

/**************************************************
 *                      DEBUG                      *
 **************************************************/

/**
 * Finds the length of a surface list for debug purposes.
 */
static s32 surface_list_length(struct SurfaceNode *list) {
    s32 count = 0;

    while (list != NULL) {
        list = list->next;
        count++;
    }

    return count;
}

/**
 * Print the area,number of walls, how many times they were called,
 * and some allocation information.
 */
void debug_surface_list_info(f32 xPos, f32 zPos) {
    struct SurfaceNode *list;
    s32 numFloors = 0;
    s32 numWalls = 0;
    s32 numCeils = 0;

    s32 cellX = (xPos + LEVEL_BOUNDARY_MAX) / CELL_SIZE;
    s32 cellZ = (zPos + LEVEL_BOUNDARY_MAX) / CELL_SIZE;

    list = gStaticSurfacePartition[cellZ & 0x0F][cellX & 0x0F][SPATIAL_PARTITION_FLOORS].next;
    numFloors += surface_list_length(list);

    list = gDynamicSurfacePartition[SPATIAL_PARTITION_FLOORS].next;
    numFloors += surface_list_length(list);

    list = gStaticSurfacePartition[cellZ & 0x0F][cellX & 0x0F][SPATIAL_PARTITION_WALLS].next;
    numWalls += surface_list_length(list);

    list = gDynamicSurfacePartition[SPATIAL_PARTITION_WALLS].next;
    numWalls += surface_list_length(list);

    list = gStaticSurfacePartition[cellZ & 0x0F][cellX & 0x0F][SPATIAL_PARTITION_CEILS].next;
    numCeils += surface_list_length(list);

    list = gDynamicSurfacePartition[SPATIAL_PARTITION_CEILS].next;
    numCeils += surface_list_length(list);

    print_debug_top_down_mapinfo("area   %x", cellZ * 16 + cellX);

    // Names represent ground, walls, and roofs as found in SMS.
    print_debug_top_down_mapinfo("dg %d", numFloors);
    print_debug_top_down_mapinfo("dw %d", numWalls);
    print_debug_top_down_mapinfo("dr %d", numCeils);

    set_text_array_x_y(80, -3);

    print_debug_top_down_mapinfo("%d", gNumCalls.floor);
    print_debug_top_down_mapinfo("%d", gNumCalls.wall);
    print_debug_top_down_mapinfo("%d", gNumCalls.ceil);

    set_text_array_x_y(-80, 0);

    // listal- List Allocated?, statbg- Static Background?, movebg- Moving Background?
    print_debug_top_down_mapinfo("listal %d", gSurfaceNodesAllocated);
    print_debug_top_down_mapinfo("statbg %d", gNumStaticSurfaces);
    print_debug_top_down_mapinfo("movebg %d", gSurfacesAllocated - gNumStaticSurfaces);

    gNumCalls.floor = 0;
    gNumCalls.ceil = 0;
    gNumCalls.wall = 0;
}

/**
 * An unused function that finds and interacts with any type of surface.
 * Perhaps an original implementation of surfaces before they were more specialized.
 */
s32 unused_resolve_floor_or_ceil_collisions(s32 checkCeil, f32 *px, f32 *py, f32 *pz, f32 radius,
                                            struct Surface **psurface, f32 *surfaceHeight) {
    f32 nx, ny, nz, oo;
    f32 x = *px;
    f32 y = *py;
    f32 z = *pz;
    f32 offset, distance;

    *psurface = NULL;

    if (checkCeil) {
        *surfaceHeight = mcBGRoofCheck(x, y, z, psurface);
    } else {
        *surfaceHeight = mcBGGroundCheck(x, y, z, psurface);
    }

    if (*psurface == NULL) {
        return -1;
    }

    nx = (*psurface)->normal.x;
    ny = (*psurface)->normal.y;
    nz = (*psurface)->normal.z;
    oo = (*psurface)->originOffset;

    offset = nx * x + ny * y + nz * z + oo;
    distance = offset >= 0 ? offset : -offset;

    // Interesting surface interaction that should be surf type independent.
    if (distance < radius) {
        *px += nx * (radius - offset);
        *py += ny * (radius - offset);
        *pz += nz * (radius - offset);

        return 1;
    }

    return 0;
}
