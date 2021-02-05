// Search:
			case HEADER_GC_DRAGON_SOUL_REFINE:
				ret = RecvDragonSoulRefine();
				break;
// Add after:
#ifdef ENABLE_DS_SET
			case HEADER_GC_DS_TABLE:
				ret = RecvDSTablePacket();
				break;
#endif