Vtx castle_grounds_4_dl_mesh_vtx_0[10] = {
	{{{-3104, 3286, -2980},0, {56, 781},{0xFF, 0xFF, 0xFF, 0xFF}}},
	{{{-2790, 3286, -2980},0, {1100, 781},{0xFF, 0xFF, 0xFF, 0xFF}}},
	{{{-2878, 3375, -2980},0, {809, 489},{0xFF, 0xFF, 0xFF, 0xFF}}},
	{{{-3104, 3465, -2980},0, {56, 196},{0xFF, 0xFF, 0xFF, 0xFF}}},
	{{{-2790, 3465, -2980},0, {1100, 196},{0xFF, 0xFF, 0xFF, 0xFF}}},
	{{{3119, 3286, -2982},0, {56, 781},{0xFF, 0xFF, 0xFF, 0xFF}}},
	{{{3433, 3286, -2982},0, {1100, 781},{0xFF, 0xFF, 0xFF, 0xFF}}},
	{{{3345, 3375, -2982},0, {809, 489},{0xFF, 0xFF, 0xFF, 0xFF}}},
	{{{3119, 3465, -2982},0, {56, 196},{0xFF, 0xFF, 0xFF, 0xFF}}},
	{{{3433, 3465, -2982},0, {1100, 196},{0xFF, 0xFF, 0xFF, 0xFF}}},
};

Gfx castle_grounds_4_dl_mesh_tri_0[] = {
	gsSPVertex(castle_grounds_4_dl_mesh_vtx_0 + 0, 10, 0),
	gsSP1Triangle(0, 1, 2, 0),
	gsSP1Triangle(3, 0, 2, 0),
	gsSP1Triangle(4, 3, 2, 0),
	gsSP1Triangle(5, 6, 7, 0),
	gsSP1Triangle(8, 5, 7, 0),
	gsSP1Triangle(9, 8, 7, 0),
	gsSPEndDisplayList(),
};

Vtx castle_grounds_4_dl_mesh_vtx_1[8] = {
	{{{3147, 3286, -2982},0, {495, 1010},{0xFF, 0xFF, 0xFF, 0xFF}}},
	{{{3147, 3171, -2982},0, {495, -12},{0xFF, 0xFF, 0xFF, 0xFF}}},
	{{{3095, 3171, -2982},0, {-15, -12},{0xFF, 0xFF, 0xFF, 0xFF}}},
	{{{3095, 3286, -2982},0, {-15, 1010},{0xFF, 0xFF, 0xFF, 0xFF}}},
	{{{-3076, 3286, -2980},0, {495, 1010},{0xFF, 0xFF, 0xFF, 0xFF}}},
	{{{-3076, 3171, -2980},0, {495, -12},{0xFF, 0xFF, 0xFF, 0xFF}}},
	{{{-3128, 3171, -2980},0, {-15, -12},{0xFF, 0xFF, 0xFF, 0xFF}}},
	{{{-3128, 3286, -2980},0, {-15, 1010},{0xFF, 0xFF, 0xFF, 0xFF}}},
};

Gfx castle_grounds_4_dl_mesh_tri_1[] = {
	gsSPVertex(castle_grounds_4_dl_mesh_vtx_1 + 0, 8, 0),
	gsSP1Triangle(0, 1, 2, 0),
	gsSP1Triangle(0, 2, 3, 0),
	gsSP1Triangle(4, 5, 6, 0),
	gsSP1Triangle(4, 6, 7, 0),
	gsSPEndDisplayList(),
};

Gfx castle_grounds_4_dl_mesh[] = {
	gsSPDisplayList(mat_castle_grounds_FlagMaterial),
	gsSPDisplayList(castle_grounds_4_dl_mesh_tri_0),
	gsSPDisplayList(mat_revert_castle_grounds_FlagMaterial),
	gsSPDisplayList(mat_castle_grounds_FlagPoleMaterial),
	gsSPDisplayList(castle_grounds_4_dl_mesh_tri_1),
	gsSPDisplayList(mat_revert_castle_grounds_FlagPoleMaterial),
	gsDPPipeSync(),
	gsSPSetGeometryMode(G_LIGHTING),
	gsSPClearGeometryMode(G_TEXTURE_GEN),
	gsDPSetCombineLERP(0, 0, 0, SHADE, 0, 0, 0, ENVIRONMENT, 0, 0, 0, SHADE, 0, 0, 0, ENVIRONMENT),
	gsSPTexture(65535, 65535, 0, 0, 0),
	gsSPEndDisplayList(),
};
