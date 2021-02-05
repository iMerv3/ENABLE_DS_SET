// Search:
	Set(HEADER_CG_DRAGON_SOUL_REFINE, sizeof(TPacketCGDragonSoulRefine), "DragonSoulRefine", false);
// Add after:
#ifdef ENABLE_DS_SET
	Set(HEADER_GC_DS_TABLE, sizeof(TPacketDSTable), "DSTable", true);
#endif