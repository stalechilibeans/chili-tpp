#include <ultra64.h>

#include "sm64.h"
#include "game_init.h"
#include "mario.h"
#include "memory.h"
#include "engine/graph_node.h"
#include "geo_misc.h"
#include "area.h"
#include "segment2.h"
#include "level_update.h"
#include "level_table.h"
#include "areamap.h"

#define STATE_HIDDEN 0
#define STATE_SHOWN 1
#define STATE_HIDING 2
#define STATE_APPEARING 3

extern struct AreaMapData castle_grounds_areamap;
extern struct AreaMapData castle_courtyard_areamap;
extern struct AreaMapData mountain_areamap;
extern struct AreaMapData fire_bubble_areamap;
extern struct AreaMapData water_land_area_1_areamap;
extern struct AreaMapData water_land_area_2_areamap;
extern struct AreaMapData snow_slider_areamap;

struct AreaMapData *sAreaMapArray[] = {
    &castle_grounds_areamap,    &castle_courtyard_areamap,  &mountain_areamap,    &fire_bubble_areamap,
    &water_land_area_1_areamap, &water_land_area_2_areamap, &snow_slider_areamap, NULL,
};

f32 sMapX = 274.0f;
f32 sMapY = 301.0f;
s8 sCurrentState = STATE_HIDDEN;

void *create_areamap_ortho_matrix() {
    Mtx *mtx = alloc_display_list(sizeof(Mtx));

    if (mtx != NULL) {
        guOrtho(mtx, 0.0f, SCREEN_WIDTH, 0.0f, SCREEN_HEIGHT, -10.0f, 10.0f, 1.0f);
    }

    return mtx;
}

void update_areamap(UNUSED struct AreaMapData *areaMap) {
    if (gPlayer3Controller->buttonPressed & R_TRIG) {
        switch (sCurrentState) {
            case STATE_SHOWN:
                sCurrentState = STATE_HIDING;
                break;

            case STATE_HIDDEN:
                sCurrentState = STATE_APPEARING;
                break;

            default:
                break;
        }
    }

    switch (sCurrentState) {
        case STATE_HIDING:
            sMapY += 20;
            if (sMapY >= 301) {
                sMapY = 301;
                sCurrentState = STATE_HIDDEN;
            }
            break;

        case STATE_APPEARING:
            sMapY -= 20;
            if (sMapY <= 195) {
                sMapY = 195;
                sCurrentState = STATE_SHOWN;
            }
            break;

        default:
            break;
    }
}

void create_areamap_texture_dlist(Gfx **dlist, struct AreaMapData *areaMap) {
    Mtx *translate = alloc_display_list(sizeof(Mtx));
    Vtx *verts = alloc_display_list(8 * sizeof(Vtx));

    const u8 *const textureTop = segmented_to_virtual(areaMap->image_upper);
    const u8 *const textureBottom = segmented_to_virtual(areaMap->image_lower);

    make_vertex(verts, 0, -32, 0, 0, 0, 1024, 255, 255, 255, 220);
    make_vertex(verts, 1, 32, 0, 0, 2048, 1024, 255, 255, 255, 220);
    make_vertex(verts, 2, 32, 32, 0, 2048, 0, 255, 255, 255, 220);
    make_vertex(verts, 3, -32, 32, 0, 0, 0, 255, 255, 255, 220);
    make_vertex(verts, 4, -32, -32, 0, 0, 1024, 255, 255, 255, 220);
    make_vertex(verts, 5, 32, -32, 0, 2048, 1024, 255, 255, 255, 220);
    make_vertex(verts, 6, 32, 0, 0, 2048, 0, 255, 255, 255, 220);
    make_vertex(verts, 7, -32, 0, 0, 0, 0, 255, 255, 255, 220);

    guTranslate(translate, sMapX, sMapY, 0.0f);
    gSPMatrix((*dlist)++, VIRTUAL_TO_PHYSICAL(translate), G_MTX_MODELVIEW | G_MTX_MUL | G_MTX_PUSH);

    gDPSetTextureFilter((*dlist)++, G_TF_POINT);

    gSPVertex((*dlist)++, VIRTUAL_TO_PHYSICAL(verts), 8, 0);

    gLoadBlockTexture((*dlist)++, 64, 32, G_IM_FMT_RGBA, textureTop);
    gSPDisplayList((*dlist)++, dl_draw_quad_verts_0123);

    gLoadBlockTexture((*dlist)++, 64, 32, G_IM_FMT_RGBA, textureBottom);
    gSPDisplayList((*dlist)++, dl_draw_quad_verts_4567);

    gSPPopMatrix((*dlist)++, G_MTX_MODELVIEW);
}

void create_areamap_arrow_dlist(Gfx **dlist, UNUSED struct AreaMapData *areaMap) {
    Mtx *translate = alloc_display_list(sizeof(Mtx));
    Mtx *rotate = alloc_display_list(sizeof(Mtx));
    Vtx *verts = alloc_display_list(4 * sizeof(Vtx));

    make_vertex(verts, 0, -4, -4, 0, 0, 256, 255, 0, 0, 255);
    make_vertex(verts, 1, 4, -4, 0, 256, 256, 255, 0, 0, 255);
    make_vertex(verts, 2, 4, 4, 0, 256, 0, 255, 0, 0, 255);
    make_vertex(verts, 3, -4, 4, 0, 0, 0, 255, 0, 0, 255);

    guTranslate(translate,
                (f32) (sMapX + (gMarioState->pos[0] / 256) * areaMap->side_g + areaMap->xo_g),
                (f32) (sMapY - (gMarioState->pos[2] / 256) * areaMap->side_g + areaMap->zo_g), 0.0f);
    guRotate(rotate, (f32) (gMarioState->faceAngle[1] / 180) + 180, 0.0f, 0.0f, 1.0f);

    gSPMatrix((*dlist)++, translate, G_MTX_MODELVIEW | G_MTX_MUL | G_MTX_PUSH);
    gSPMatrix((*dlist)++, rotate, G_MTX_MODELVIEW | G_MTX_MUL | G_MTX_NOPUSH);

    gDPSetTextureFilter((*dlist)++, G_TF_POINT);

    gSPVertex((*dlist)++, VIRTUAL_TO_PHYSICAL(verts), 4, 0);
    gSPDisplayList((*dlist)++, dl_draw_quad_verts_0123);

    gSPPopMatrix((*dlist)++, G_MTX_MODELVIEW);
}

Gfx *create_areamap_dlist(struct AreaMapData *areaMap) {
    s32 dlCommandCount = 6 + 6 + 16;
    Gfx *areamap = alloc_display_list(dlCommandCount * sizeof(Gfx));
    Gfx *dlist = areamap;

    if (areamap == NULL) {
        return NULL;
    } else {
        Mtx *ortho = create_areamap_ortho_matrix();

        gSPDisplayList(dlist++, areamap_init_project);
        gSPMatrix(dlist++, VIRTUAL_TO_PHYSICAL(ortho), G_MTX_PROJECTION | G_MTX_LOAD | G_MTX_NOPUSH);

        gSPDisplayList(dlist++, areamap_init_graphic1);
        create_areamap_texture_dlist(&dlist, areaMap);

        gSPDisplayList(dlist++, areamap_init_graphic2);
        create_areamap_arrow_dlist(&dlist, areaMap);

        gSPDisplayList(dlist++, areamap_mode_restore);

        gSPEndDisplayList(dlist);
    }

    return areamap;
}

Gfx *AreaMap(int code, struct GraphNode *node, UNUSED void *data) {
    struct GraphNodeGenerated *generatedNode = (struct GraphNodeGenerated *) node;
    struct AreaMapData *areaMap = segmented_to_virtual(sAreaMapArray[generatedNode->parameter]);
    Gfx *dlist = NULL;

    if (code == GEO_CONTEXT_AREA_INIT) {
        sMapX = 274.0f;
        sMapY = 301.0f;
        sCurrentState = STATE_HIDDEN;
    } else if (code == GEO_CONTEXT_RENDER) {
        generatedNode->fnNode.node.flags =
            (generatedNode->fnNode.node.flags & 0xFF) | (LAYER_TRANSPARENT << 8);

        dlist = create_areamap_dlist(areaMap);
        update_areamap(areaMap);
    }

    return dlist;
}
