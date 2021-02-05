// Search:
	HEADER_GC_RESPOND_CHANNELSTATUS				= 210,
// Add after:
#ifdef ENABLE_DS_SET
	HEADER_GC_DS_TABLE = 212,
#endif



// Search:
typedef struct SChannelStatus
{
	short nPort;
	BYTE bStatus;
} TChannelStatus;
// Add after:
#ifdef ENABLE_DS_SET
typedef struct STPacketDSTable {
	BYTE	bHeader;
	int		iType, iApplyCount, iBasicApplyValue[255], iAditionalApplyValue[255];
	float	fWeight;
} TPacketDSTable;
#endif