// Search:
#include "../EterGrnLib/ThingInstance.h"
// Add after:
#ifdef ENABLE_DS_SET
#include "Packet.h"
#endif



// Search:
		typedef std::map<DWORD, TGroundItemInstance *>	TGroundItemInstanceMap;
// Add after:
#ifdef ENABLE_DS_SET
		typedef struct SDSTable
		{
			float	fWeight;
			int		iApplyCount;
			int		iBasicApplyValue[255];
			int		iAditionalApplyValue[255];
		} TDSTable;
		
		typedef std::map<int, TDSTable>	TDSTableMap;
#endif



// Search:
		std::vector<CItemData *> m_NoGradeNameItemData;
// Add after:
#ifdef ENABLE_DS_SET
		TDSTableMap	m_DSTableMap;
	public:
		bool	SetDSTable(TPacketDSTable p);
		float	GetDSSetWeight(int iDSType, int iDSGrade);
		int		GetDSBasicApplyCount(int iDSType, int iDSGrade);
		int		GetDSBasicApplyValue(int iDSType, int iDSApplyType);
		int		GetDSAdditionalApplyValue(int iDSType, int iDSApplyType);
#endif