#ifndef CASTLE_INSIDE_HEADER_H
#define CASTLE_INSIDE_HEADER_H

#include "types.h"
#include "game/moving_texture.h"

//#include "levels/castle_inside/areas/1/custom/header.h"

// geo
extern const GeoLayout castle_geo[];
extern const GeoLayout castle_geo_000F18[]; //bowser trap

// leveldata

extern struct Painting ccm_painting;
extern struct Painting wf_painting;
extern struct Painting jrb_painting;
extern struct Painting lll_painting;

extern const Gfx inside_castle_seg7_dl_0703BCB8[]; //trap door
extern const Gfx inside_castle_seg7_dl_0703BFA8[]; //star door

extern const Gfx inside_castle_seg7_dl_070512F8[]; //pendulum

extern const Gfx inside_castle_seg7_dl_07058950[]; //clock minute hand
extern const Gfx inside_castle_seg7_dl_07059190[]; //clock hour hand

extern const Gfx inside_castle_seg7_dl_07068B10[]; //water level pillar

extern Gfx castle_inside_main_dl_mesh[];
extern Gfx castle_inside_decal_dl_mesh[];
extern Gfx castle_inside_bowser_dl_mesh[];
extern Gfx castle_inside_bowser_painting_dl_mesh[];
extern Gfx castle_inside_mountain_dl_mesh[];
extern Gfx castle_inside_fire_bubble_dl_mesh[];
extern Gfx castle_inside_fire_bubble_decal_dl_mesh[];
extern Gfx castle_inside_water_land_dl_mesh[];
extern Gfx castle_inside_snow_slider_dl_mesh[];
extern Gfx castle_inside_hallway_dl_mesh[];
extern const Collision castle_inside_collision[];
extern const u8 castle_inside_collision_rooms[];

extern const Collision inside_castle_seg7_collision_floor_trap[]; //trap door
extern const Collision inside_castle_seg7_collision_star_door[]; //can't get rid of this yet
extern const Collision inside_castle_seg7_collision_water_level_pillar[]; //can't get rid of this either
extern const Trajectory *const inside_castle_seg7_trajectory_mips[]; //hah, nope

// script
extern const LevelScript level_castle_inside_entry[];

#endif
