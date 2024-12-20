// Lights
Lights1 fire_bubble_lights = gdSPDefLights1(
	0x3F, 0x3F, 0x3F,
	0xFF, 0xFF, 0xFF, 0x28, 0x28, 0x28);

// Materials
Gfx mat_FireBubbleShit_Material[] = {
	gsDPPipeSync(),
	gsDPSetCombineLERP(TEXEL0, 0, SHADE, 0, TEXEL0, 0, PRIMITIVE, 0, TEXEL0, 0, SHADE, 0, TEXEL0, 0, PRIMITIVE, 0),
	gsSPClearGeometryMode(G_CULL_BACK),
	gsSPTexture(65535, 65535, 0, 0, 1),
	gsDPTileSync(),
	gsDPSetTextureImage(G_IM_FMT_RGBA, G_IM_SIZ_16b_LOAD_BLOCK, 1, fire_09009000),
	gsDPSetTile(G_IM_FMT_RGBA, G_IM_SIZ_16b_LOAD_BLOCK, 0, 0, 7, 0, G_TX_WRAP | G_TX_NOMIRROR, 5, 0, G_TX_WRAP | G_TX_NOMIRROR, 5, 0),
	gsDPLoadSync(),
	gsDPLoadBlock(7, 0, 0, 1023, 256),
	gsDPPipeSync(),
	gsDPSetTile(G_IM_FMT_RGBA, G_IM_SIZ_16b, 8, 0, 0, 0, G_TX_WRAP | G_TX_NOMIRROR, 5, 0, G_TX_WRAP | G_TX_NOMIRROR, 5, 0),
	gsDPSetTileSize(0, 0, 0, 124, 124),
	gsDPSetPrimColor(0, 0, 254, 254, 254, 191),
	gsSPSetLights1(fire_bubble_lights),
	gsSPEndDisplayList(),
};

Gfx mat_fire_bubble_BrickMaterial[] = {
	gsDPPipeSync(),
	gsDPSetCombineLERP(TEXEL0, 0, SHADE, 0, 0, 0, 0, SHADE, TEXEL0, 0, SHADE, 0, 0, 0, 0, SHADE),
	gsSPTexture(65535, 65535, 0, 0, 1),
	gsDPTileSync(),
	gsDPSetTextureImage(G_IM_FMT_RGBA, G_IM_SIZ_16b, 32, lll_seg7_texture_07004800),
	gsDPSetTile(G_IM_FMT_RGBA, G_IM_SIZ_16b, 8, 0, 7, 0, G_TX_WRAP | G_TX_NOMIRROR, 5, 0, G_TX_WRAP | G_TX_NOMIRROR, 5, 0),
	gsDPLoadSync(),
	gsDPLoadTile(7, 0, 0, 124, 124),
	gsDPPipeSync(),
	gsDPSetTile(G_IM_FMT_RGBA, G_IM_SIZ_16b, 8, 0, 0, 0, G_TX_WRAP | G_TX_NOMIRROR, 5, 0, G_TX_WRAP | G_TX_NOMIRROR, 5, 0),
	gsDPSetTileSize(0, 0, 0, 124, 124),
	gsSPSetLights1(fire_bubble_lights),
	gsSPEndDisplayList(),
};

Gfx mat_fire_bubble_PolkaDotMaterial[] = {
	gsDPPipeSync(),
	gsDPSetCombineLERP(TEXEL0, 0, SHADE, 0, 0, 0, 0, SHADE, TEXEL0, 0, SHADE, 0, 0, 0, 0, SHADE),
	gsSPTexture(65535, 65535, 0, 0, 1),
	gsDPTileSync(),
	gsDPSetTextureImage(G_IM_FMT_RGBA, G_IM_SIZ_16b, 32, lll_seg7_texture_0700EC00),
	gsDPSetTile(G_IM_FMT_RGBA, G_IM_SIZ_16b, 8, 0, 7, 0, G_TX_WRAP | G_TX_NOMIRROR, 5, 0, G_TX_WRAP | G_TX_NOMIRROR, 5, 0),
	gsDPLoadSync(),
	gsDPLoadTile(7, 0, 0, 124, 124),
	gsDPPipeSync(),
	gsDPSetTile(G_IM_FMT_RGBA, G_IM_SIZ_16b, 8, 0, 0, 0, G_TX_WRAP | G_TX_NOMIRROR, 5, 0, G_TX_WRAP | G_TX_NOMIRROR, 5, 0),
	gsDPSetTileSize(0, 0, 0, 124, 124),
	gsSPSetLights1(fire_bubble_lights),
	gsSPEndDisplayList(),
};

Gfx mat_fire_bubble_PolkaDotDarkMaterial[] = {
	gsDPPipeSync(),
	gsDPSetCombineLERP(TEXEL0, 0, SHADE, 0, 0, 0, 0, SHADE, TEXEL0, 0, SHADE, 0, 0, 0, 0, SHADE),
	gsSPTexture(65535, 65535, 0, 0, 1),
	gsDPTileSync(),
	gsDPSetTextureImage(G_IM_FMT_RGBA, G_IM_SIZ_16b, 32, lll_seg7_texture_0700F400),
	gsDPSetTile(G_IM_FMT_RGBA, G_IM_SIZ_16b, 8, 0, 7, 0, G_TX_WRAP | G_TX_NOMIRROR, 5, 0, G_TX_WRAP | G_TX_NOMIRROR, 5, 0),
	gsDPLoadSync(),
	gsDPLoadTile(7, 0, 0, 124, 124),
	gsDPPipeSync(),
	gsDPSetTile(G_IM_FMT_RGBA, G_IM_SIZ_16b, 8, 0, 0, 0, G_TX_WRAP | G_TX_NOMIRROR, 5, 0, G_TX_WRAP | G_TX_NOMIRROR, 5, 0),
	gsDPSetTileSize(0, 0, 0, 124, 124),
	gsSPSetLights1(fire_bubble_lights),
	gsSPEndDisplayList(),
};

Gfx mat_fire_bubble_CheckerboardStoneMaterial[] = {
	gsDPPipeSync(),
	gsDPSetCombineLERP(TEXEL0, 0, SHADE, 0, 0, 0, 0, SHADE, TEXEL0, 0, SHADE, 0, 0, 0, 0, SHADE),
	gsSPTexture(65535, 65535, 0, 0, 1),
	gsDPTileSync(),
	gsDPSetTextureImage(G_IM_FMT_RGBA, G_IM_SIZ_16b, 32, lll_seg7_texture_07002000),
	gsDPSetTile(G_IM_FMT_RGBA, G_IM_SIZ_16b, 8, 0, 7, 0, G_TX_WRAP | G_TX_NOMIRROR, 5, 0, G_TX_WRAP | G_TX_NOMIRROR, 5, 0),
	gsDPLoadSync(),
	gsDPLoadTile(7, 0, 0, 124, 124),
	gsDPPipeSync(),
	gsDPSetTile(G_IM_FMT_RGBA, G_IM_SIZ_16b, 8, 0, 0, 0, G_TX_WRAP | G_TX_NOMIRROR, 5, 0, G_TX_WRAP | G_TX_NOMIRROR, 5, 0),
	gsDPSetTileSize(0, 0, 0, 124, 124),
	gsSPSetLights1(fire_bubble_lights),
	gsSPEndDisplayList(),
};

Gfx mat_fire_bubble_WallMaterial[] = {
	gsDPPipeSync(),
	gsDPSetCombineLERP(TEXEL0, 0, SHADE, 0, 0, 0, 0, SHADE, TEXEL0, 0, SHADE, 0, 0, 0, 0, SHADE),
	gsSPTexture(65535, 65535, 0, 0, 1),
	gsDPTileSync(),
	gsDPSetTextureImage(G_IM_FMT_RGBA, G_IM_SIZ_16b, 32, fire_09007800),
	gsDPSetTile(G_IM_FMT_RGBA, G_IM_SIZ_16b, 8, 0, 7, 0, G_TX_CLAMP | G_TX_NOMIRROR, 5, 0, G_TX_WRAP | G_TX_NOMIRROR, 5, 0),
	gsDPLoadSync(),
	gsDPLoadTile(7, 0, 0, 124, 124),
	gsDPPipeSync(),
	gsDPSetTile(G_IM_FMT_RGBA, G_IM_SIZ_16b, 8, 0, 0, 0, G_TX_CLAMP | G_TX_NOMIRROR, 5, 0, G_TX_WRAP | G_TX_NOMIRROR, 5, 0),
	gsDPSetTileSize(0, 0, 0, 124, 124),
	gsSPSetLights1(fire_bubble_lights),
	gsSPEndDisplayList(),
};

Gfx mat_fire_bubble_LightBlueGravelMaterial[] = {
	gsDPPipeSync(),
	gsDPSetCombineLERP(TEXEL0, 0, SHADE, 0, 0, 0, 0, SHADE, TEXEL0, 0, SHADE, 0, 0, 0, 0, SHADE),
	gsSPTexture(65535, 65535, 0, 0, 1),
	gsDPTileSync(),
	gsDPSetTextureImage(G_IM_FMT_RGBA, G_IM_SIZ_16b, 32, fire_09002800),
	gsDPSetTile(G_IM_FMT_RGBA, G_IM_SIZ_16b, 8, 0, 7, 0, G_TX_WRAP | G_TX_NOMIRROR, 5, 0, G_TX_WRAP | G_TX_NOMIRROR, 5, 0),
	gsDPLoadSync(),
	gsDPLoadTile(7, 0, 0, 124, 124),
	gsDPPipeSync(),
	gsDPSetTile(G_IM_FMT_RGBA, G_IM_SIZ_16b, 8, 0, 0, 0, G_TX_WRAP | G_TX_NOMIRROR, 5, 0, G_TX_WRAP | G_TX_NOMIRROR, 5, 0),
	gsDPSetTileSize(0, 0, 0, 124, 124),
	gsSPSetLights1(fire_bubble_lights),
	gsSPEndDisplayList(),
};

Gfx mat_fire_bubble_BridgeMaterial[] = {
	gsDPPipeSync(),
	gsDPSetCombineLERP(TEXEL0, 0, SHADE, 0, 0, 0, 0, SHADE, TEXEL0, 0, SHADE, 0, 0, 0, 0, SHADE),
	gsSPTexture(65535, 65535, 0, 0, 1),
	gsDPTileSync(),
	gsDPSetTextureImage(G_IM_FMT_RGBA, G_IM_SIZ_16b, 32, fire_0900B800),
	gsDPSetTile(G_IM_FMT_RGBA, G_IM_SIZ_16b, 8, 0, 7, 0, G_TX_WRAP | G_TX_NOMIRROR, 5, 0, G_TX_WRAP | G_TX_NOMIRROR, 5, 0),
	gsDPLoadSync(),
	gsDPLoadTile(7, 0, 0, 124, 124),
	gsDPPipeSync(),
	gsDPSetTile(G_IM_FMT_RGBA, G_IM_SIZ_16b, 8, 0, 0, 0, G_TX_WRAP | G_TX_NOMIRROR, 5, 0, G_TX_WRAP | G_TX_NOMIRROR, 5, 0),
	gsDPSetTileSize(0, 0, 0, 124, 124),
	gsSPSetLights1(fire_bubble_lights),
	gsSPEndDisplayList(),
};

Gfx mat_fire_bubble_DarkGravelMaterial[] = {
	gsDPPipeSync(),
	gsDPSetCombineLERP(TEXEL0, 0, SHADE, 0, 0, 0, 0, SHADE, TEXEL0, 0, SHADE, 0, 0, 0, 0, SHADE),
	gsSPTexture(65535, 65535, 0, 0, 1),
	gsDPTileSync(),
	gsDPSetTextureImage(G_IM_FMT_RGBA, G_IM_SIZ_16b, 32, lll_seg7_texture_07004000),
	gsDPSetTile(G_IM_FMT_RGBA, G_IM_SIZ_16b, 8, 0, 7, 0, G_TX_WRAP | G_TX_NOMIRROR, 5, 0, G_TX_WRAP | G_TX_NOMIRROR, 5, 0),
	gsDPLoadSync(),
	gsDPLoadTile(7, 0, 0, 124, 124),
	gsDPPipeSync(),
	gsDPSetTile(G_IM_FMT_RGBA, G_IM_SIZ_16b, 8, 0, 0, 0, G_TX_WRAP | G_TX_NOMIRROR, 5, 0, G_TX_WRAP | G_TX_NOMIRROR, 5, 0),
	gsDPSetTileSize(0, 0, 0, 124, 124),
	gsSPSetLights1(fire_bubble_lights),
	gsSPEndDisplayList(),
};

Gfx mat_fire_bubble_LavaMaterial[] = {
	gsDPPipeSync(),
	gsDPSetCombineLERP(TEXEL0, 0, SHADE, 0, 0, 0, 0, SHADE, TEXEL0, 0, SHADE, 0, 0, 0, 0, SHADE),
	gsSPTexture(65535, 65535, 0, 0, 1),
	gsDPTileSync(),
	gsDPSetTextureImage(G_IM_FMT_RGBA, G_IM_SIZ_16b, 32, fire_09009000),
	gsDPSetTile(G_IM_FMT_RGBA, G_IM_SIZ_16b, 8, 0, 7, 0, G_TX_WRAP | G_TX_NOMIRROR, 5, 0, G_TX_WRAP | G_TX_NOMIRROR, 5, 0),
	gsDPLoadSync(),
	gsDPLoadTile(7, 0, 0, 124, 124),
	gsDPPipeSync(),
	gsDPSetTile(G_IM_FMT_RGBA, G_IM_SIZ_16b, 8, 0, 0, 0, G_TX_WRAP | G_TX_NOMIRROR, 5, 0, G_TX_WRAP | G_TX_NOMIRROR, 5, 0),
	gsDPSetTileSize(0, 0, 0, 124, 124),
	gsSPSetLights1(fire_bubble_lights),
	gsSPEndDisplayList(),
};

Gfx mat_fire_bubble_VolcanoOutsideMaterial[] = {
	gsDPPipeSync(),
	gsDPSetCombineLERP(TEXEL0, 0, SHADE, 0, 0, 0, 0, SHADE, TEXEL0, 0, SHADE, 0, 0, 0, 0, SHADE),
	gsSPTexture(65535, 65535, 0, 0, 1),
	gsDPTileSync(),
	gsDPSetTextureImage(G_IM_FMT_RGBA, G_IM_SIZ_16b, 32, fire_09003000),
	gsDPSetTile(G_IM_FMT_RGBA, G_IM_SIZ_16b, 8, 0, 7, 0, G_TX_WRAP | G_TX_NOMIRROR, 5, 0, G_TX_WRAP | G_TX_NOMIRROR, 5, 0),
	gsDPLoadSync(),
	gsDPLoadTile(7, 0, 0, 124, 124),
	gsDPPipeSync(),
	gsDPSetTile(G_IM_FMT_RGBA, G_IM_SIZ_16b, 8, 0, 0, 0, G_TX_WRAP | G_TX_NOMIRROR, 5, 0, G_TX_WRAP | G_TX_NOMIRROR, 5, 0),
	gsDPSetTileSize(0, 0, 0, 124, 124),
	gsSPSetLights1(fire_bubble_lights),
	gsSPEndDisplayList(),
};

Gfx mat_fire_bubble_VolcanoInsideMaterial[] = {
	gsDPPipeSync(),
	gsDPSetCombineLERP(TEXEL0, 0, SHADE, 0, 0, 0, 0, SHADE, TEXEL0, 0, SHADE, 0, 0, 0, 0, SHADE),
	gsSPTexture(65535, 65535, 0, 0, 1),
	gsDPTileSync(),
	gsDPSetTextureImage(G_IM_FMT_RGBA, G_IM_SIZ_16b, 32, fire_09009800),
	gsDPSetTile(G_IM_FMT_RGBA, G_IM_SIZ_16b, 8, 0, 7, 0, G_TX_WRAP | G_TX_NOMIRROR, 5, 0, G_TX_WRAP | G_TX_NOMIRROR, 5, 0),
	gsDPLoadSync(),
	gsDPLoadTile(7, 0, 0, 124, 124),
	gsDPPipeSync(),
	gsDPSetTile(G_IM_FMT_RGBA, G_IM_SIZ_16b, 8, 0, 0, 0, G_TX_WRAP | G_TX_NOMIRROR, 5, 0, G_TX_WRAP | G_TX_NOMIRROR, 5, 0),
	gsDPSetTileSize(0, 0, 0, 124, 124),
	gsSPSetLights1(fire_bubble_lights),
	gsSPEndDisplayList(),
};

// Data
Vtx FireBubbleShit_mesh_vtx_0[9] = {
	{{{0, 0, -8192},0, {3088, -5141},{0x0, 0x7F, 0x0, 0xFF}}},
	{{{-8191, 0, -8192},0, {-11434, -5141},{0x0, 0x7F, 0x0, 0xFF}}},
	{{{-8191, 0, 0},0, {-11434, 9381},{0x0, 0x7F, 0x0, 0xFF}}},
	{{{0, 0, 0},0, {3088, 9380},{0x0, 0x7F, 0x0, 0xFF}}},
	{{{-8191, 0, 8191},0, {-11434, 23904},{0x0, 0x7F, 0x0, 0xFF}}},
	{{{0, 0, 8191},0, {3088, 23904},{0x0, 0x7F, 0x0, 0xFF}}},
	{{{8191, 0, 0},0, {17611, 9381},{0x0, 0x7F, 0x0, 0xFF}}},
	{{{8191, 0, 8191},0, {17611, 23904},{0x0, 0x7F, 0x0, 0xFF}}},
	{{{8191, 0, -8192},0, {17611, -5141},{0x0, 0x7F, 0x0, 0xFF}}},
};

Gfx FireBubbleShit_mesh_tri_0[] = {
	gsSPVertex(FireBubbleShit_mesh_vtx_0 + 0, 9, 0),
	gsSP1Triangle(0, 1, 2, 0),
	gsSP1Triangle(3, 0, 2, 0),
	gsSP1Triangle(3, 2, 4, 0),
	gsSP1Triangle(4, 5, 3, 0),
	gsSP1Triangle(3, 5, 6, 0),
	gsSP1Triangle(5, 7, 6, 0),
	gsSP1Triangle(3, 6, 8, 0),
	gsSP1Triangle(8, 0, 3, 0),
	gsSPEndDisplayList(),
};

Vtx fire_bubble_1_dl_mesh_vtx_0[16] = {
	{{{-255, 154, 4224},0, {974, 566},{0x81, 0x0, 0x0, 0xFF}}},
	{{{-255, 230, 4224},0, {974, -16},{0x81, 0x0, 0x0, 0xFF}}},
	{{{-255, 230, 4096},0, {-16, -16},{0x81, 0x0, 0x0, 0xFF}}},
	{{{-255, 154, 4096},0, {-16, 566},{0x81, 0x0, 0x0, 0xFF}}},
	{{{256, 154, 4096},0, {-16, 566},{0x7F, 0x0, 0x0, 0xFF}}},
	{{{256, 230, 4224},0, {974, -16},{0x7F, 0x0, 0x0, 0xFF}}},
	{{{256, 154, 4224},0, {974, 566},{0x7F, 0x0, 0x0, 0xFF}}},
	{{{256, 230, 4096},0, {-16, -16},{0x7F, 0x0, 0x0, 0xFF}}},
	{{{-255, 230, 4224},0, {-16, 974},{0x0, 0x7F, 0x0, 0xFF}}},
	{{{256, 230, 4224},0, {4040, 974},{0x0, 0x7F, 0x0, 0xFF}}},
	{{{256, 230, 4096},0, {4040, -16},{0x0, 0x7F, 0x0, 0xFF}}},
	{{{-255, 230, 4096},0, {-16, -16},{0x0, 0x7F, 0x0, 0xFF}}},
	{{{256, 154, 4224},0, {4040, 566},{0x0, 0x0, 0x7F, 0xFF}}},
	{{{-255, 230, 4224},0, {-16, -16},{0x0, 0x0, 0x7F, 0xFF}}},
	{{{-255, 154, 4224},0, {-16, 566},{0x0, 0x0, 0x7F, 0xFF}}},
	{{{256, 230, 4224},0, {4040, -16},{0x0, 0x0, 0x7F, 0xFF}}},
};

Gfx fire_bubble_1_dl_mesh_tri_0[] = {
	gsSPVertex(fire_bubble_1_dl_mesh_vtx_0 + 0, 16, 0),
	gsSP1Triangle(0, 1, 2, 0),
	gsSP1Triangle(0, 2, 3, 0),
	gsSP1Triangle(4, 5, 6, 0),
	gsSP1Triangle(4, 7, 5, 0),
	gsSP1Triangle(8, 9, 10, 0),
	gsSP1Triangle(8, 10, 11, 0),
	gsSP1Triangle(12, 13, 14, 0),
	gsSP1Triangle(12, 15, 13, 0),
	gsSPEndDisplayList(),
};

Vtx fire_bubble_1_dl_mesh_vtx_1[12] = {
	{{{-383, 307, -7231},0, {2556, -1080},{0x0, 0x7F, 0x0, 0xFF}}},
	{{{512, 307, -7103},0, {2044, 2530},{0x0, 0x7F, 0x0, 0xFF}}},
	{{{384, 307, -7231},0, {2556, 2013},{0x0, 0x7F, 0x0, 0xFF}}},
	{{{512, 307, -6335},0, {-1054, 2530},{0x0, 0x7F, 0x0, 0xFF}}},
	{{{384, 307, -6207},0, {-1566, 2013},{0x0, 0x7F, 0x0, 0xFF}}},
	{{{-383, 307, -6207},0, {-1566, -1080},{0x0, 0x7F, 0x0, 0xFF}}},
	{{{-511, 307, -6335},0, {-1054, -1533},{0x0, 0x7F, 0x0, 0xFF}}},
	{{{-511, 307, -7103},0, {2044, -1533},{0x0, 0x7F, 0x0, 0xFF}}},
	{{{-1662, 307, -7105},0, {2307, -1315},{0x0, 0x7F, 0x0, 0xFF}}},
	{{{-1662, 307, -6209},0, {-1315, -1315},{0x0, 0x7F, 0x0, 0xFF}}},
	{{{-766, 307, -6209},0, {-1315, 2307},{0x0, 0x7F, 0x0, 0xFF}}},
	{{{-766, 307, -7105},0, {2307, 2307},{0x0, 0x7F, 0x0, 0xFF}}},
};

Gfx fire_bubble_1_dl_mesh_tri_1[] = {
	gsSPVertex(fire_bubble_1_dl_mesh_vtx_1 + 0, 12, 0),
	gsSP1Triangle(0, 1, 2, 0),
	gsSP1Triangle(0, 3, 1, 0),
	gsSP1Triangle(0, 4, 3, 0),
	gsSP1Triangle(0, 5, 4, 0),
	gsSP1Triangle(0, 6, 5, 0),
	gsSP1Triangle(0, 7, 6, 0),
	gsSP1Triangle(8, 9, 10, 0),
	gsSP1Triangle(8, 10, 11, 0),
	gsSPEndDisplayList(),
};

Vtx fire_bubble_1_dl_mesh_vtx_2[136] = {
	{{{76, 793, -6360},0, {5062, -3114},{0x5A, 0x59, 0x0, 0xFF}}},
	{{{76, 793, -6207},0, {-16, -3114},{0x5A, 0x59, 0x0, 0xFF}}},
	{{{229, 639, -6207},0, {-16, 1220},{0x5A, 0x59, 0x0, 0xFF}}},
	{{{229, 639, -6360},0, {5062, 1220},{0x5A, 0x59, 0x0, 0xFF}}},
	{{{-77, 793, -6360},0, {5062, -2092},{0x0, 0x7F, 0x0, 0xFF}}},
	{{{-77, 793, -6207},0, {-16, -2092},{0x0, 0x7F, 0x0, 0xFF}}},
	{{{76, 793, -6207},0, {-16, 974},{0x0, 0x7F, 0x0, 0xFF}}},
	{{{76, 793, -6360},0, {5062, 974},{0x0, 0x7F, 0x0, 0xFF}}},
	{{{-230, 639, -6360},0, {-16, 974},{0xA6, 0x59, 0x0, 0xFF}}},
	{{{-230, 639, -6207},0, {5062, 974},{0xA6, 0x59, 0x0, 0xFF}}},
	{{{-77, 793, -6207},0, {5062, -3362},{0xA6, 0x59, 0x0, 0xFF}}},
	{{{-77, 793, -6360},0, {-16, -3362},{0xA6, 0x59, 0x0, 0xFF}}},
	{{{-230, 307, -6360},0, {-16, 974},{0x81, 0x0, 0x0, 0xFF}}},
	{{{-230, 639, -6207},0, {5062, -5668},{0x81, 0x0, 0x0, 0xFF}}},
	{{{-230, 639, -6360},0, {-16, -5668},{0x81, 0x0, 0x0, 0xFF}}},
	{{{-230, 307, -6207},0, {5062, 974},{0x81, 0x0, 0x0, 0xFF}}},
	{{{-77, 716, -6360},0, {974, -1070},{0x5A, 0xA6, 0x0, 0xFF}}},
	{{{-154, 639, -6207},0, {-4134, 1096},{0x5A, 0xA6, 0x0, 0xFF}}},
	{{{-154, 639, -6360},0, {974, 1096},{0x5A, 0xA6, 0x0, 0xFF}}},
	{{{-77, 716, -6207},0, {-4134, -1070},{0x5A, 0xA6, 0x0, 0xFF}}},
	{{{76, 716, -6360},0, {974, -2092},{0x0, 0x81, 0x0, 0xFF}}},
	{{{-77, 716, -6207},0, {-4134, 974},{0x0, 0x81, 0x0, 0xFF}}},
	{{{-77, 716, -6360},0, {974, 974},{0x0, 0x81, 0x0, 0xFF}}},
	{{{76, 716, -6207},0, {-4134, -2092},{0x0, 0x81, 0x0, 0xFF}}},
	{{{153, 639, -6360},0, {-16, 974},{0xA6, 0xA6, 0x0, 0xFF}}},
	{{{153, 639, -6207},0, {5062, 974},{0xA6, 0xA6, 0x0, 0xFF}}},
	{{{76, 716, -6207},0, {5062, -1194},{0xA6, 0xA6, 0x0, 0xFF}}},
	{{{76, 716, -6360},0, {-16, -1194},{0xA6, 0xA6, 0x0, 0xFF}}},
	{{{153, 307, -6360},0, {-16, 974},{0x81, 0x0, 0x0, 0xFF}}},
	{{{153, 639, -6207},0, {5062, -5668},{0x81, 0x0, 0x0, 0xFF}}},
	{{{153, 639, -6360},0, {-16, -5668},{0x81, 0x0, 0x0, 0xFF}}},
	{{{153, 307, -6207},0, {5062, 974},{0x81, 0x0, 0x0, 0xFF}}},
	{{{-154, 639, -6360},0, {4040, -5158},{0x7F, 0x0, 0x0, 0xFF}}},
	{{{-154, 307, -6207},0, {-1068, 1482},{0x7F, 0x0, 0x0, 0xFF}}},
	{{{-154, 307, -6360},0, {4040, 1484},{0x7F, 0x0, 0x0, 0xFF}}},
	{{{-154, 639, -6207},0, {-1068, -5158},{0x7F, 0x0, 0x0, 0xFF}}},
	{{{229, 639, -6360},0, {5062, -5158},{0x7F, 0x0, 0x0, 0xFF}}},
	{{{229, 639, -6207},0, {-16, -5158},{0x7F, 0x0, 0x0, 0xFF}}},
	{{{229, 307, -6207},0, {-16, 1484},{0x7F, 0x0, 0x0, 0xFF}}},
	{{{229, 307, -6360},0, {5062, 1484},{0x7F, 0x0, 0x0, 0xFF}}},
	{{{-230, 639, -6207},0, {-7710, -5158},{0x0, 0x0, 0x7F, 0xFF}}},
	{{{-230, 307, -6207},0, {-7710, 1482},{0x0, 0x0, 0x7F, 0xFF}}},
	{{{-154, 307, -6207},0, {-6178, 1482},{0x0, 0x0, 0x7F, 0xFF}}},
	{{{-154, 639, -6207},0, {-6178, -5158},{0x0, 0x0, 0x7F, 0xFF}}},
	{{{-77, 716, -6207},0, {-4644, -6690},{0x0, 0x0, 0x7F, 0xFF}}},
	{{{-77, 793, -6207},0, {-4644, -8224},{0x0, 0x0, 0x7F, 0xFF}}},
	{{{76, 716, -6207},0, {-1578, -6690},{0x0, 0x0, 0x7F, 0xFF}}},
	{{{76, 793, -6207},0, {-1580, -8224},{0x0, 0x0, 0x7F, 0xFF}}},
	{{{76, 716, -6207},0, {-1578, -6690},{0x0, 0x0, 0x7F, 0xFF}}},
	{{{153, 639, -6207},0, {-16, -5158},{0x0, 0x0, 0x7F, 0xFF}}},
	{{{76, 793, -6207},0, {-1580, -8224},{0x0, 0x0, 0x7F, 0xFF}}},
	{{{229, 639, -6207},0, {1484, -5158},{0x0, 0x0, 0x7F, 0xFF}}},
	{{{229, 307, -6207},0, {1486, 1482},{0x0, 0x0, 0x7F, 0xFF}}},
	{{{153, 307, -6207},0, {-16, 1482},{0x0, 0x0, 0x7F, 0xFF}}},
	{{{-154, 307, -6360},0, {6596, 1484},{0x0, 0x0, 0x81, 0xFF}}},
	{{{-230, 307, -6360},0, {8128, 1484},{0x0, 0x0, 0x81, 0xFF}}},
	{{{-230, 639, -6360},0, {8128, -5158},{0x0, 0x0, 0x81, 0xFF}}},
	{{{-154, 639, -6360},0, {6596, -5158},{0x0, 0x0, 0x81, 0xFF}}},
	{{{-77, 793, -6360},0, {5062, -8224},{0x0, 0x0, 0x81, 0xFF}}},
	{{{-77, 716, -6360},0, {5062, -6690},{0x0, 0x0, 0x81, 0xFF}}},
	{{{76, 793, -6360},0, {1996, -8224},{0x0, 0x0, 0x81, 0xFF}}},
	{{{76, 716, -6360},0, {1996, -6690},{0x0, 0x0, 0x81, 0xFF}}},
	{{{229, 639, -6360},0, {-1068, -5158},{0x0, 0x0, 0x81, 0xFF}}},
	{{{153, 639, -6360},0, {464, -5158},{0x0, 0x0, 0x81, 0xFF}}},
	{{{229, 639, -6360},0, {-1068, -5158},{0x0, 0x0, 0x81, 0xFF}}},
	{{{153, 307, -6360},0, {464, 1484},{0x0, 0x0, 0x81, 0xFF}}},
	{{{153, 639, -6360},0, {464, -5158},{0x0, 0x0, 0x81, 0xFF}}},
	{{{229, 307, -6360},0, {-1068, 1482},{0x0, 0x0, 0x81, 0xFF}}},
	{{{-357, 793, -6643},0, {5062, -3114},{0x0, 0x59, 0x5A, 0xFF}}},
	{{{-510, 793, -6643},0, {-16, -3114},{0x0, 0x59, 0x5A, 0xFF}}},
	{{{-510, 639, -6490},0, {-16, 1220},{0x0, 0x59, 0x5A, 0xFF}}},
	{{{-357, 639, -6490},0, {5062, 1220},{0x0, 0x59, 0x5A, 0xFF}}},
	{{{-357, 793, -6796},0, {5062, -2092},{0x0, 0x7F, 0x0, 0xFF}}},
	{{{-510, 793, -6796},0, {-16, -2092},{0x0, 0x7F, 0x0, 0xFF}}},
	{{{-510, 793, -6643},0, {-16, 974},{0x0, 0x7F, 0x0, 0xFF}}},
	{{{-357, 793, -6643},0, {5062, 974},{0x0, 0x7F, 0x0, 0xFF}}},
	{{{-357, 639, -6949},0, {-16, 974},{0x0, 0x59, 0xA6, 0xFF}}},
	{{{-510, 639, -6949},0, {5062, 974},{0x0, 0x59, 0xA6, 0xFF}}},
	{{{-510, 793, -6796},0, {5062, -3362},{0x0, 0x59, 0xA6, 0xFF}}},
	{{{-357, 793, -6796},0, {-16, -3362},{0x0, 0x59, 0xA6, 0xFF}}},
	{{{-357, 307, -6949},0, {-16, 974},{0x0, 0x0, 0x81, 0xFF}}},
	{{{-510, 639, -6949},0, {5062, -5668},{0x0, 0x0, 0x81, 0xFF}}},
	{{{-357, 639, -6949},0, {-16, -5668},{0x0, 0x0, 0x81, 0xFF}}},
	{{{-510, 307, -6949},0, {5062, 974},{0x0, 0x0, 0x81, 0xFF}}},
	{{{-357, 716, -6796},0, {974, -1070},{0x0, 0xA6, 0x5A, 0xFF}}},
	{{{-510, 639, -6873},0, {-4134, 1096},{0x0, 0xA6, 0x5A, 0xFF}}},
	{{{-357, 639, -6873},0, {974, 1096},{0x0, 0xA6, 0x5A, 0xFF}}},
	{{{-510, 716, -6796},0, {-4134, -1070},{0x0, 0xA6, 0x5A, 0xFF}}},
	{{{-357, 716, -6643},0, {974, -2092},{0x0, 0x81, 0x0, 0xFF}}},
	{{{-510, 716, -6796},0, {-4134, 974},{0x0, 0x81, 0x0, 0xFF}}},
	{{{-357, 716, -6796},0, {974, 974},{0x0, 0x81, 0x0, 0xFF}}},
	{{{-510, 716, -6643},0, {-4134, -2092},{0x0, 0x81, 0x0, 0xFF}}},
	{{{-357, 639, -6566},0, {-16, 974},{0x0, 0xA6, 0xA6, 0xFF}}},
	{{{-510, 639, -6566},0, {5062, 974},{0x0, 0xA6, 0xA6, 0xFF}}},
	{{{-510, 716, -6643},0, {5062, -1194},{0x0, 0xA6, 0xA6, 0xFF}}},
	{{{-357, 716, -6643},0, {-16, -1194},{0x0, 0xA6, 0xA6, 0xFF}}},
	{{{-357, 307, -6566},0, {-16, 974},{0x0, 0x0, 0x81, 0xFF}}},
	{{{-510, 639, -6566},0, {5062, -5668},{0x0, 0x0, 0x81, 0xFF}}},
	{{{-357, 639, -6566},0, {-16, -5668},{0x0, 0x0, 0x81, 0xFF}}},
	{{{-510, 307, -6566},0, {5062, 974},{0x0, 0x0, 0x81, 0xFF}}},
	{{{-357, 639, -6873},0, {4040, -5158},{0x0, 0x0, 0x7F, 0xFF}}},
	{{{-510, 307, -6873},0, {-1068, 1482},{0x0, 0x0, 0x7F, 0xFF}}},
	{{{-357, 307, -6873},0, {4040, 1484},{0x0, 0x0, 0x7F, 0xFF}}},
	{{{-510, 639, -6873},0, {-1068, -5158},{0x0, 0x0, 0x7F, 0xFF}}},
	{{{-357, 639, -6490},0, {5062, -5158},{0x0, 0x0, 0x7F, 0xFF}}},
	{{{-510, 639, -6490},0, {-16, -5158},{0x0, 0x0, 0x7F, 0xFF}}},
	{{{-510, 307, -6490},0, {-16, 1484},{0x0, 0x0, 0x7F, 0xFF}}},
	{{{-357, 307, -6490},0, {5062, 1484},{0x0, 0x0, 0x7F, 0xFF}}},
	{{{-510, 639, -6949},0, {-7710, -5158},{0x81, 0x0, 0x0, 0xFF}}},
	{{{-510, 307, -6949},0, {-7710, 1482},{0x81, 0x0, 0x0, 0xFF}}},
	{{{-510, 307, -6873},0, {-6178, 1482},{0x81, 0x0, 0x0, 0xFF}}},
	{{{-510, 639, -6873},0, {-6178, -5158},{0x81, 0x0, 0x0, 0xFF}}},
	{{{-510, 639, -6949},0, {-7710, -5158},{0x81, 0x0, 0x0, 0xFF}}},
	{{{-510, 639, -6873},0, {-6178, -5158},{0x81, 0x0, 0x0, 0xFF}}},
	{{{-510, 716, -6796},0, {-4644, -6690},{0x81, 0x0, 0x0, 0xFF}}},
	{{{-510, 793, -6796},0, {-4644, -8224},{0x81, 0x0, 0x0, 0xFF}}},
	{{{-510, 716, -6643},0, {-1578, -6690},{0x81, 0x0, 0x0, 0xFF}}},
	{{{-510, 793, -6643},0, {-1580, -8224},{0x81, 0x0, 0x0, 0xFF}}},
	{{{-510, 639, -6566},0, {-16, -5158},{0x81, 0x0, 0x0, 0xFF}}},
	{{{-510, 639, -6490},0, {1484, -5158},{0x81, 0x0, 0x0, 0xFF}}},
	{{{-510, 307, -6490},0, {1486, 1482},{0x81, 0x0, 0x0, 0xFF}}},
	{{{-510, 307, -6566},0, {-16, 1482},{0x81, 0x0, 0x0, 0xFF}}},
	{{{-357, 307, -6873},0, {6596, 1484},{0x7F, 0x0, 0x0, 0xFF}}},
	{{{-357, 307, -6949},0, {8128, 1484},{0x7F, 0x0, 0x0, 0xFF}}},
	{{{-357, 639, -6949},0, {8128, -5158},{0x7F, 0x0, 0x0, 0xFF}}},
	{{{-357, 639, -6873},0, {6596, -5158},{0x7F, 0x0, 0x0, 0xFF}}},
	{{{-357, 793, -6796},0, {5062, -8224},{0x7F, 0x0, 0x0, 0xFF}}},
	{{{-357, 716, -6796},0, {5062, -6690},{0x7F, 0x0, 0x0, 0xFF}}},
	{{{-357, 716, -6796},0, {5062, -6690},{0x7F, 0x0, 0x0, 0xFF}}},
	{{{-357, 793, -6796},0, {5062, -8224},{0x7F, 0x0, 0x0, 0xFF}}},
	{{{-357, 793, -6643},0, {1996, -8224},{0x7F, 0x0, 0x0, 0xFF}}},
	{{{-357, 716, -6643},0, {1996, -6690},{0x7F, 0x0, 0x0, 0xFF}}},
	{{{-357, 639, -6490},0, {-1068, -5158},{0x7F, 0x0, 0x0, 0xFF}}},
	{{{-357, 639, -6566},0, {464, -5158},{0x7F, 0x0, 0x0, 0xFF}}},
	{{{-357, 307, -6566},0, {464, 1484},{0x7F, 0x0, 0x0, 0xFF}}},
	{{{-357, 307, -6490},0, {-1068, 1482},{0x7F, 0x0, 0x0, 0xFF}}},
};

Gfx fire_bubble_1_dl_mesh_tri_2[] = {
	gsSPVertex(fire_bubble_1_dl_mesh_vtx_2 + 0, 16, 0),
	gsSP1Triangle(0, 1, 2, 0),
	gsSP1Triangle(0, 2, 3, 0),
	gsSP1Triangle(4, 5, 6, 0),
	gsSP1Triangle(4, 6, 7, 0),
	gsSP1Triangle(8, 9, 10, 0),
	gsSP1Triangle(8, 10, 11, 0),
	gsSP1Triangle(12, 13, 14, 0),
	gsSP1Triangle(12, 15, 13, 0),
	gsSPVertex(fire_bubble_1_dl_mesh_vtx_2 + 16, 16, 0),
	gsSP1Triangle(0, 1, 2, 0),
	gsSP1Triangle(0, 3, 1, 0),
	gsSP1Triangle(4, 5, 6, 0),
	gsSP1Triangle(4, 7, 5, 0),
	gsSP1Triangle(8, 9, 10, 0),
	gsSP1Triangle(8, 10, 11, 0),
	gsSP1Triangle(12, 13, 14, 0),
	gsSP1Triangle(12, 15, 13, 0),
	gsSPVertex(fire_bubble_1_dl_mesh_vtx_2 + 32, 16, 0),
	gsSP1Triangle(0, 1, 2, 0),
	gsSP1Triangle(0, 3, 1, 0),
	gsSP1Triangle(4, 5, 6, 0),
	gsSP1Triangle(4, 6, 7, 0),
	gsSP1Triangle(8, 9, 10, 0),
	gsSP1Triangle(8, 10, 11, 0),
	gsSP1Triangle(8, 11, 12, 0),
	gsSP1Triangle(13, 8, 12, 0),
	gsSP1Triangle(13, 12, 14, 0),
	gsSP1Triangle(14, 15, 13, 0),
	gsSPVertex(fire_bubble_1_dl_mesh_vtx_2 + 48, 16, 0),
	gsSP1Triangle(0, 1, 2, 0),
	gsSP1Triangle(1, 3, 2, 0),
	gsSP1Triangle(1, 4, 3, 0),
	gsSP1Triangle(1, 5, 4, 0),
	gsSP1Triangle(6, 7, 8, 0),
	gsSP1Triangle(9, 6, 8, 0),
	gsSP1Triangle(9, 8, 10, 0),
	gsSP1Triangle(11, 9, 10, 0),
	gsSP1Triangle(11, 10, 12, 0),
	gsSP1Triangle(12, 13, 11, 0),
	gsSP1Triangle(12, 14, 13, 0),
	gsSP1Triangle(14, 15, 13, 0),
	gsSPVertex(fire_bubble_1_dl_mesh_vtx_2 + 64, 16, 0),
	gsSP1Triangle(0, 1, 2, 0),
	gsSP1Triangle(0, 3, 1, 0),
	gsSP1Triangle(4, 5, 6, 0),
	gsSP1Triangle(4, 6, 7, 0),
	gsSP1Triangle(8, 9, 10, 0),
	gsSP1Triangle(8, 10, 11, 0),
	gsSP1Triangle(12, 13, 14, 0),
	gsSP1Triangle(12, 14, 15, 0),
	gsSPVertex(fire_bubble_1_dl_mesh_vtx_2 + 80, 16, 0),
	gsSP1Triangle(0, 1, 2, 0),
	gsSP1Triangle(0, 3, 1, 0),
	gsSP1Triangle(4, 5, 6, 0),
	gsSP1Triangle(4, 7, 5, 0),
	gsSP1Triangle(8, 9, 10, 0),
	gsSP1Triangle(8, 11, 9, 0),
	gsSP1Triangle(12, 13, 14, 0),
	gsSP1Triangle(12, 14, 15, 0),
	gsSPVertex(fire_bubble_1_dl_mesh_vtx_2 + 96, 16, 0),
	gsSP1Triangle(0, 1, 2, 0),
	gsSP1Triangle(0, 3, 1, 0),
	gsSP1Triangle(4, 5, 6, 0),
	gsSP1Triangle(4, 7, 5, 0),
	gsSP1Triangle(8, 9, 10, 0),
	gsSP1Triangle(8, 10, 11, 0),
	gsSP1Triangle(12, 13, 14, 0),
	gsSP1Triangle(12, 14, 15, 0),
	gsSPVertex(fire_bubble_1_dl_mesh_vtx_2 + 112, 16, 0),
	gsSP1Triangle(0, 1, 2, 0),
	gsSP1Triangle(3, 0, 2, 0),
	gsSP1Triangle(3, 2, 4, 0),
	gsSP1Triangle(4, 5, 3, 0),
	gsSP1Triangle(4, 6, 5, 0),
	gsSP1Triangle(6, 7, 5, 0),
	gsSP1Triangle(6, 8, 7, 0),
	gsSP1Triangle(6, 9, 8, 0),
	gsSP1Triangle(10, 11, 12, 0),
	gsSP1Triangle(13, 10, 12, 0),
	gsSP1Triangle(13, 12, 14, 0),
	gsSP1Triangle(15, 13, 14, 0),
	gsSPVertex(fire_bubble_1_dl_mesh_vtx_2 + 128, 8, 0),
	gsSP1Triangle(0, 1, 2, 0),
	gsSP1Triangle(2, 3, 0, 0),
	gsSP1Triangle(2, 4, 3, 0),
	gsSP1Triangle(4, 5, 3, 0),
	gsSP1Triangle(4, 6, 5, 0),
	gsSP1Triangle(4, 7, 6, 0),
	gsSPEndDisplayList(),
};

Vtx fire_bubble_1_dl_mesh_vtx_3[112] = {
	{{{256, 0, 4224},0, {11888, 976},{0x7F, 0x0, 0x0, 0xFF}}},
	{{{256, 154, 4224},0, {11888, -16},{0x7F, 0x0, 0x0, 0xFF}}},
	{{{256, 154, 6016},0, {-16, -16},{0x7F, 0x0, 0x0, 0xFF}}},
	{{{256, 0, 6016},0, {-16, 976},{0x7F, 0x0, 0x0, 0xFF}}},
	{{{-255, 0, 6016},0, {-16, 976},{0x81, 0x0, 0x0, 0xFF}}},
	{{{-255, 154, 6016},0, {-16, -16},{0x81, 0x0, 0x0, 0xFF}}},
	{{{-255, 154, 4224},0, {11888, -16},{0x81, 0x0, 0x0, 0xFF}}},
	{{{-255, 0, 4224},0, {11888, 976},{0x81, 0x0, 0x0, 0xFF}}},
	{{{995, 0, 6400},0, {3568, 1008},{0x0, 0x0, 0x7F, 0xFF}}},
	{{{995, 154, 6400},0, {3568, -16},{0x0, 0x0, 0x7F, 0xFF}}},
	{{{384, 154, 6400},0, {-16, -16},{0x0, 0x0, 0x7F, 0xFF}}},
	{{{384, 0, 6400},0, {-16, 1008},{0x0, 0x0, 0x7F, 0xFF}}},
	{{{384, 0, 6144},0, {-16, 1008},{0x0, 0x0, 0x81, 0xFF}}},
	{{{384, 154, 6144},0, {-16, -16},{0x0, 0x0, 0x81, 0xFF}}},
	{{{995, 154, 6144},0, {3568, -16},{0x0, 0x0, 0x81, 0xFF}}},
	{{{995, 0, 6144},0, {3568, 1008},{0x0, 0x0, 0x81, 0xFF}}},
	{{{768, 0, -5055},0, {4624, 976},{0x7F, 0x0, 0x0, 0xFF}}},
	{{{768, 307, -3647},0, {-16, -16},{0x7F, 0x0, 0x0, 0xFF}}},
	{{{768, 0, -3647},0, {-16, 976},{0x7F, 0x0, 0x0, 0xFF}}},
	{{{768, 307, -5055},0, {4624, -16},{0x7F, 0x0, 0x0, 0xFF}}},
	{{{-767, 0, -5055},0, {-16, 976},{0x0, 0x0, 0x81, 0xFF}}},
	{{{768, 307, -5055},0, {5072, -16},{0x0, 0x0, 0x81, 0xFF}}},
	{{{768, 0, -5055},0, {5072, 976},{0x0, 0x0, 0x81, 0xFF}}},
	{{{-767, 307, -5055},0, {-16, -16},{0x0, 0x0, 0x81, 0xFF}}},
	{{{768, 0, -3647},0, {5072, 976},{0x0, 0x0, 0x7F, 0xFF}}},
	{{{-767, 307, -3647},0, {-16, -16},{0x0, 0x0, 0x7F, 0xFF}}},
	{{{-767, 0, -3647},0, {-16, 976},{0x0, 0x0, 0x7F, 0xFF}}},
	{{{768, 307, -3647},0, {5072, -16},{0x0, 0x0, 0x7F, 0xFF}}},
	{{{-767, 0, -3647},0, {-16, 976},{0x81, 0x0, 0x0, 0xFF}}},
	{{{-767, 307, -3647},0, {-16, -16},{0x81, 0x0, 0x0, 0xFF}}},
	{{{-767, 307, -5055},0, {4624, -16},{0x81, 0x0, 0x0, 0xFF}}},
	{{{-767, 0, -5055},0, {4624, 976},{0x81, 0x0, 0x0, 0xFF}}},
	{{{995, 0, 6144},0, {6416, 1008},{0x81, 0x0, 0x0, 0xFF}}},
	{{{995, 154, 6016},0, {5584, -16},{0x81, 0x0, 0x0, 0xFF}}},
	{{{995, 0, 6016},0, {5584, 1008},{0x81, 0x0, 0x0, 0xFF}}},
	{{{995, 154, 6144},0, {6416, -16},{0x81, 0x0, 0x0, 0xFF}}},
	{{{-383, 0, -7231},0, {3056, 1008},{0xA6, 0x0, 0xA6, 0xFF}}},
	{{{-511, 307, -7103},0, {3504, -16},{0xA6, 0x0, 0xA6, 0xFF}}},
	{{{-383, 307, -7231},0, {3056, -16},{0xA6, 0x0, 0xA6, 0xFF}}},
	{{{-511, 0, -7103},0, {3504, 1008},{0xA6, 0x0, 0xA6, 0xFF}}},
	{{{384, 0, -6207},0, {-2000, 1008},{0x5A, 0x0, 0x5A, 0xFF}}},
	{{{512, 307, -6335},0, {-1552, -16},{0x5A, 0x0, 0x5A, 0xFF}}},
	{{{384, 307, -6207},0, {-2000, -16},{0x5A, 0x0, 0x5A, 0xFF}}},
	{{{512, 0, -6335},0, {-1552, 1008},{0x5A, 0x0, 0x5A, 0xFF}}},
	{{{384, 307, -6207},0, {-2000, -16},{0x0, 0x0, 0x7F, 0xFF}}},
	{{{-383, 0, -6207},0, {-4112, 1008},{0x0, 0x0, 0x7F, 0xFF}}},
	{{{384, 0, -6207},0, {-2000, 1008},{0x0, 0x0, 0x7F, 0xFF}}},
	{{{-383, 307, -6207},0, {-4112, -16},{0x0, 0x0, 0x7F, 0xFF}}},
	{{{-511, 0, -6335},0, {-4560, 1008},{0xA6, 0x0, 0x5A, 0xFF}}},
	{{{-383, 0, -6207},0, {-4112, 1008},{0xA6, 0x0, 0x5A, 0xFF}}},
	{{{-383, 307, -6207},0, {-4112, -16},{0xA6, 0x0, 0x5A, 0xFF}}},
	{{{-511, 307, -6335},0, {-4560, -16},{0xA6, 0x0, 0x5A, 0xFF}}},
	{{{512, 0, -7103},0, {528, 1008},{0x5A, 0x0, 0xA6, 0xFF}}},
	{{{384, 307, -7231},0, {976, -16},{0x5A, 0x0, 0xA6, 0xFF}}},
	{{{512, 307, -7103},0, {528, -16},{0x5A, 0x0, 0xA6, 0xFF}}},
	{{{384, 0, -7231},0, {976, 1008},{0x5A, 0x0, 0xA6, 0xFF}}},
	{{{512, 307, -7103},0, {528, -16},{0x7F, 0x0, 0x0, 0xFF}}},
	{{{512, 307, -6335},0, {-1552, -16},{0x7F, 0x0, 0x0, 0xFF}}},
	{{{512, 0, -6335},0, {-1552, 1008},{0x7F, 0x0, 0x0, 0xFF}}},
	{{{512, 0, -7103},0, {528, 1008},{0x7F, 0x0, 0x0, 0xFF}}},
	{{{-383, 307, -7231},0, {3056, -16},{0x0, 0x0, 0x81, 0xFF}}},
	{{{384, 307, -7231},0, {976, -16},{0x0, 0x0, 0x81, 0xFF}}},
	{{{384, 0, -7231},0, {976, 1008},{0x0, 0x0, 0x81, 0xFF}}},
	{{{-383, 0, -7231},0, {3056, 1008},{0x0, 0x0, 0x81, 0xFF}}},
	{{{-511, 307, -6335},0, {5584, -16},{0x81, 0x0, 0x0, 0xFF}}},
	{{{-511, 307, -7103},0, {3504, -16},{0x81, 0x0, 0x0, 0xFF}}},
	{{{-511, 0, -7103},0, {3504, 1008},{0x81, 0x0, 0x0, 0xFF}}},
	{{{-511, 0, -6335},0, {5584, 1008},{0x81, 0x0, 0x0, 0xFF}}},
	{{{1510, 154, 6528},0, {-1168, -16},{0x7F, 0x0, 0x0, 0xFF}}},
	{{{1510, 0, 6528},0, {-1168, 1008},{0x7F, 0x0, 0x0, 0xFF}}},
	{{{1510, 0, 6016},0, {2192, 1008},{0x7F, 0x0, 0x0, 0xFF}}},
	{{{1510, 154, 6016},0, {2192, -16},{0x7F, 0x0, 0x0, 0xFF}}},
	{{{995, 154, 6528},0, {-4560, -16},{0x0, 0x0, 0x7F, 0xFF}}},
	{{{995, 0, 6528},0, {-4560, 1008},{0x0, 0x0, 0x7F, 0xFF}}},
	{{{1510, 0, 6528},0, {-1168, 1008},{0x0, 0x0, 0x7F, 0xFF}}},
	{{{1510, 154, 6528},0, {-1168, -16},{0x0, 0x0, 0x7F, 0xFF}}},
	{{{995, 0, 6528},0, {-4560, 1008},{0x81, 0x0, 0x0, 0xFF}}},
	{{{995, 154, 6528},0, {-4560, -16},{0x81, 0x0, 0x0, 0xFF}}},
	{{{995, 154, 6400},0, {-5392, -16},{0x81, 0x0, 0x0, 0xFF}}},
	{{{995, 0, 6400},0, {-5392, 1008},{0x81, 0x0, 0x0, 0xFF}}},
	{{{995, 0, 6016},0, {5584, 1008},{0x0, 0x0, 0x81, 0xFF}}},
	{{{995, 154, 6016},0, {5584, -16},{0x0, 0x0, 0x81, 0xFF}}},
	{{{1510, 154, 6016},0, {2192, -16},{0x0, 0x0, 0x81, 0xFF}}},
	{{{1510, 0, 6016},0, {2192, 1008},{0x0, 0x0, 0x81, 0xFF}}},
	{{{-766, 0, -6849},0, {1648, 976},{0x0, 0x0, 0x81, 0xFF}}},
	{{{-766, 307, -6849},0, {1648, -16},{0x0, 0x0, 0x81, 0xFF}}},
	{{{-510, 307, -6849},0, {-16, -16},{0x0, 0x0, 0x81, 0xFF}}},
	{{{-510, 0, -6849},0, {-16, 976},{0x0, 0x0, 0x81, 0xFF}}},
	{{{-510, 0, -6593},0, {-16, 976},{0x0, 0x0, 0x7F, 0xFF}}},
	{{{-510, 307, -6593},0, {-16, -16},{0x0, 0x0, 0x7F, 0xFF}}},
	{{{-766, 307, -6593},0, {1648, -16},{0x0, 0x0, 0x7F, 0xFF}}},
	{{{-766, 0, -6593},0, {1648, 976},{0x0, 0x0, 0x7F, 0xFF}}},
	{{{-1662, 0, -7105},0, {4079, 976},{0x0, 0x0, 0x81, 0xFF}}},
	{{{-1662, 307, -7105},0, {4079, -16},{0x0, 0x0, 0x81, 0xFF}}},
	{{{-766, 307, -7105},0, {1648, -16},{0x0, 0x0, 0x81, 0xFF}}},
	{{{-766, 0, -7105},0, {1648, 976},{0x0, 0x0, 0x81, 0xFF}}},
	{{{-766, 0, -6593},0, {7952, 976},{0x7F, 0x0, 0x0, 0xFF}}},
	{{{-766, 307, -6593},0, {7952, -16},{0x7F, 0x0, 0x0, 0xFF}}},
	{{{-766, 307, -6209},0, {6608, -16},{0x7F, 0x0, 0x0, 0xFF}}},
	{{{-766, 0, -6209},0, {6608, 976},{0x7F, 0x0, 0x0, 0xFF}}},
	{{{-1662, 307, -6209},0, {4560, -16},{0x81, 0x0, 0x0, 0xFF}}},
	{{{-1662, 307, -7105},0, {2053, -16},{0x81, 0x0, 0x0, 0xFF}}},
	{{{-1662, 0, -7105},0, {2053, 976},{0x81, 0x0, 0x0, 0xFF}}},
	{{{-1662, 0, -6209},0, {4560, 976},{0x81, 0x0, 0x0, 0xFF}}},
	{{{-766, 307, -6209},0, {6608, -16},{0x0, 0x0, 0x7F, 0xFF}}},
	{{{-1662, 307, -6209},0, {3532, -16},{0x0, 0x0, 0x7F, 0xFF}}},
	{{{-1662, 0, -6209},0, {3532, 976},{0x0, 0x0, 0x7F, 0xFF}}},
	{{{-766, 0, -6209},0, {6608, 976},{0x0, 0x0, 0x7F, 0xFF}}},
	{{{-766, 0, -6849},0, {-17, 1010},{0x7F, 0x0, 0x0, 0xFF}}},
	{{{-766, 0, -7105},0, {996, 1010},{0x7F, 0x0, 0x0, 0xFF}}},
	{{{-766, 307, -7105},0, {996, -13},{0x7F, 0x0, 0x0, 0xFF}}},
	{{{-766, 307, -6849},0, {-17, -13},{0x7F, 0x0, 0x0, 0xFF}}},
};

Gfx fire_bubble_1_dl_mesh_tri_3[] = {
	gsSPVertex(fire_bubble_1_dl_mesh_vtx_3 + 0, 16, 0),
	gsSP1Triangle(0, 1, 2, 0),
	gsSP1Triangle(0, 2, 3, 0),
	gsSP1Triangle(4, 5, 6, 0),
	gsSP1Triangle(4, 6, 7, 0),
	gsSP1Triangle(8, 9, 10, 0),
	gsSP1Triangle(8, 10, 11, 0),
	gsSP1Triangle(12, 13, 14, 0),
	gsSP1Triangle(12, 14, 15, 0),
	gsSPVertex(fire_bubble_1_dl_mesh_vtx_3 + 16, 16, 0),
	gsSP1Triangle(0, 1, 2, 0),
	gsSP1Triangle(0, 3, 1, 0),
	gsSP1Triangle(4, 5, 6, 0),
	gsSP1Triangle(4, 7, 5, 0),
	gsSP1Triangle(8, 9, 10, 0),
	gsSP1Triangle(8, 11, 9, 0),
	gsSP1Triangle(12, 13, 14, 0),
	gsSP1Triangle(12, 14, 15, 0),
	gsSPVertex(fire_bubble_1_dl_mesh_vtx_3 + 32, 16, 0),
	gsSP1Triangle(0, 1, 2, 0),
	gsSP1Triangle(0, 3, 1, 0),
	gsSP1Triangle(4, 5, 6, 0),
	gsSP1Triangle(4, 7, 5, 0),
	gsSP1Triangle(8, 9, 10, 0),
	gsSP1Triangle(8, 11, 9, 0),
	gsSP1Triangle(12, 13, 14, 0),
	gsSP1Triangle(12, 15, 13, 0),
	gsSPVertex(fire_bubble_1_dl_mesh_vtx_3 + 48, 16, 0),
	gsSP1Triangle(0, 1, 2, 0),
	gsSP1Triangle(0, 2, 3, 0),
	gsSP1Triangle(4, 5, 6, 0),
	gsSP1Triangle(4, 7, 5, 0),
	gsSP1Triangle(8, 9, 10, 0),
	gsSP1Triangle(8, 10, 11, 0),
	gsSP1Triangle(12, 13, 14, 0),
	gsSP1Triangle(12, 14, 15, 0),
	gsSPVertex(fire_bubble_1_dl_mesh_vtx_3 + 64, 16, 0),
	gsSP1Triangle(0, 1, 2, 0),
	gsSP1Triangle(0, 2, 3, 0),
	gsSP1Triangle(4, 5, 6, 0),
	gsSP1Triangle(4, 6, 7, 0),
	gsSP1Triangle(8, 9, 10, 0),
	gsSP1Triangle(8, 10, 11, 0),
	gsSP1Triangle(12, 13, 14, 0),
	gsSP1Triangle(12, 14, 15, 0),
	gsSPVertex(fire_bubble_1_dl_mesh_vtx_3 + 80, 16, 0),
	gsSP1Triangle(0, 1, 2, 0),
	gsSP1Triangle(0, 2, 3, 0),
	gsSP1Triangle(4, 5, 6, 0),
	gsSP1Triangle(4, 6, 7, 0),
	gsSP1Triangle(8, 9, 10, 0),
	gsSP1Triangle(8, 10, 11, 0),
	gsSP1Triangle(12, 13, 14, 0),
	gsSP1Triangle(12, 14, 15, 0),
	gsSPVertex(fire_bubble_1_dl_mesh_vtx_3 + 96, 16, 0),
	gsSP1Triangle(0, 1, 2, 0),
	gsSP1Triangle(0, 2, 3, 0),
	gsSP1Triangle(4, 5, 6, 0),
	gsSP1Triangle(4, 6, 7, 0),
	gsSP1Triangle(8, 9, 10, 0),
	gsSP1Triangle(8, 10, 11, 0),
	gsSP1Triangle(12, 13, 14, 0),
	gsSP1Triangle(12, 14, 15, 0),
	gsSPEndDisplayList(),
};

Vtx fire_bubble_1_dl_mesh_vtx_4[4] = {
	{{{-767, 307, -3647},0, {-4134, 974},{0x0, 0x7F, 0x0, 0xFF}}},
	{{{768, 307, -5055},0, {974, -3710},{0x0, 0x7F, 0x0, 0xFF}}},
	{{{-767, 307, -5055},0, {-4134, -3710},{0x0, 0x7F, 0x0, 0xFF}}},
	{{{768, 307, -3647},0, {974, 974},{0x0, 0x7F, 0x0, 0xFF}}},
};

Gfx fire_bubble_1_dl_mesh_tri_4[] = {
	gsSPVertex(fire_bubble_1_dl_mesh_vtx_4 + 0, 4, 0),
	gsSP1Triangle(0, 1, 2, 0),
	gsSP1Triangle(0, 3, 1, 0),
	gsSPEndDisplayList(),
};

Vtx fire_bubble_1_dl_mesh_vtx_5[12] = {
	{{{-255, 154, 6016},0, {974, -6180},{0x0, 0x7F, 0x0, 0xFF}}},
	{{{256, 154, 6016},0, {-16, -6180},{0x0, 0x7F, 0x0, 0xFF}}},
	{{{256, 154, 4224},0, {-16, 974},{0x0, 0x7F, 0x0, 0xFF}}},
	{{{-255, 154, 4224},0, {974, 974},{0x0, 0x7F, 0x0, 0xFF}}},
	{{{995, 154, 6144},0, {-17, -1541},{0x0, 0x7F, 0x0, 0xFF}}},
	{{{384, 154, 6400},0, {1005, 1009},{0x0, 0x7F, 0x0, 0xFF}}},
	{{{995, 154, 6400},0, {1005, -1541},{0x0, 0x7F, 0x0, 0xFF}}},
	{{{384, 154, 6144},0, {-17, 1009},{0x0, 0x7F, 0x0, 0xFF}}},
	{{{-766, 307, -6593},0, {3018, 462},{0x0, 0x7F, 0x0, 0xFF}}},
	{{{-510, 307, -6849},0, {1996, -560},{0x0, 0x7F, 0x0, 0xFF}}},
	{{{-766, 307, -6849},0, {1996, 462},{0x0, 0x7F, 0x0, 0xFF}}},
	{{{-510, 307, -6593},0, {3018, -560},{0x0, 0x7F, 0x0, 0xFF}}},
};

Gfx fire_bubble_1_dl_mesh_tri_5[] = {
	gsSPVertex(fire_bubble_1_dl_mesh_vtx_5 + 0, 12, 0),
	gsSP1Triangle(0, 1, 2, 0),
	gsSP1Triangle(0, 2, 3, 0),
	gsSP1Triangle(4, 5, 6, 0),
	gsSP1Triangle(4, 7, 5, 0),
	gsSP1Triangle(8, 9, 10, 0),
	gsSP1Triangle(8, 11, 9, 0),
	gsSPEndDisplayList(),
};

Vtx fire_bubble_1_dl_mesh_vtx_6[6] = {
	{{{1510, 154, 6016},0, {2071, 1972},{0x0, 0x7F, 0x0, 0xFF}}},
	{{{995, 154, 6016},0, {2071, -2123},{0x0, 0x7F, 0x0, 0xFF}}},
	{{{995, 154, 6144},0, {1052, -2123},{0x0, 0x7F, 0x0, 0xFF}}},
	{{{995, 154, 6400},0, {-987, -2123},{0x0, 0x7F, 0x0, 0xFF}}},
	{{{1510, 154, 6528},0, {-2006, 1972},{0x0, 0x7F, 0x0, 0xFF}}},
	{{{995, 154, 6528},0, {-2006, -2123},{0x0, 0x7F, 0x0, 0xFF}}},
};

Gfx fire_bubble_1_dl_mesh_tri_6[] = {
	gsSPVertex(fire_bubble_1_dl_mesh_vtx_6 + 0, 6, 0),
	gsSP1Triangle(0, 1, 2, 0),
	gsSP1Triangle(0, 2, 3, 0),
	gsSP1Triangle(3, 4, 0, 0),
	gsSP1Triangle(3, 5, 4, 0),
	gsSPEndDisplayList(),
};

Gfx FireBubbleShit_mesh[] = {
	gsSPDisplayList(mat_FireBubbleShit_Material),
	gsSPDisplayList(FireBubbleShit_mesh_tri_0),
};

Gfx fire_bubble_1_dl_mesh[] = {
	gsSPDisplayList(mat_fire_bubble_BrickMaterial),
	gsSPDisplayList(fire_bubble_1_dl_mesh_tri_0),
	gsSPDisplayList(mat_fire_bubble_PolkaDotMaterial),
	gsSPDisplayList(fire_bubble_1_dl_mesh_tri_1),
	gsSPDisplayList(mat_fire_bubble_CheckerboardStoneMaterial),
	gsSPDisplayList(fire_bubble_1_dl_mesh_tri_2),
	gsSPDisplayList(mat_fire_bubble_WallMaterial),
	gsSPDisplayList(fire_bubble_1_dl_mesh_tri_3),
	gsSPDisplayList(mat_fire_bubble_LightBlueGravelMaterial),
	gsSPDisplayList(fire_bubble_1_dl_mesh_tri_4),
	gsSPDisplayList(mat_fire_bubble_BridgeMaterial),
	gsSPDisplayList(fire_bubble_1_dl_mesh_tri_5),
	gsSPDisplayList(mat_fire_bubble_DarkGravelMaterial),
	gsSPDisplayList(fire_bubble_1_dl_mesh_tri_6),
	gsDPPipeSync(),
	gsSPSetGeometryMode(G_LIGHTING),
	gsSPClearGeometryMode(G_TEXTURE_GEN),
	gsDPSetCombineLERP(0, 0, 0, SHADE, 0, 0, 0, SHADE, 0, 0, 0, SHADE, 0, 0, 0, SHADE),
	gsSPTexture(65535, 65535, 0, 0, 0),
	gsSPEndDisplayList(),
};
