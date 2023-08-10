/********************************************************************************
		Hms tree data.
														[ Jan 25, 1996 ]
*********************************************************************************/

extern Gfx  RCP_main_tree[];

/********************************************************************************/
/*	Hierarchy map data of MainTree.												*/
/********************************************************************************/
const GeoLayout bubbly_tree_geo[] = {
	GEO_CULLING_RADIUS(800),
	GEO_OPEN_NODE(),
		GEO_DISPLAY_LIST(LAYER_ALPHA, RCP_main_tree),
	GEO_CLOSE_NODE(),
  	GEO_END(),
};
