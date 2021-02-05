// Search:
			Set(HEADER_GC_DRAGON_SOUL_REFINE,		CNetworkPacketHeaderMap::TPacketType(sizeof(TPacketGCDragonSoulRefine), STATIC_SIZE_PACKET));
// Add after:
#ifdef ENABLE_DS_SET
			Set(HEADER_GC_DS_TABLE, CNetworkPacketHeaderMap::TPacketType(sizeof(TPacketDSTable), STATIC_SIZE_PACKET));
#endif