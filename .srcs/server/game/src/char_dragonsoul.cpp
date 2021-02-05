// Search:
	m_pointsInstant.iDragonSoulActiveDeck = deck_idx;
// Add after:
#ifdef ENABLE_DS_SET
	DragonSoul_SetRefresh();
#endif



// Search:
	RemoveAffect(AFFECT_DRAGON_SOUL_DECK_1);
// Add after:
#ifdef ENABLE_DS_SET
	RemoveAffect(AFFECT_DS_SET);
#endif



// Search:
void CHARACTER::DragonSoul_CleanUp()
{
	for (int i = DRAGON_SOUL_EQUIP_SLOT_START; i < DRAGON_SOUL_EQUIP_SLOT_END; i++)
	{
		DSManager::instance().DeactivateDragonSoul(GetInventoryItem(i), true);
	}
}
// Add after:
#ifdef ENABLE_DS_SET
void CHARACTER::DragonSoul_SetRefresh()
{
	RemoveAffect(AFFECT_DS_SET);
	
	int idx = DragonSoul_GetActiveDeck();
	if (idx < DRAGON_SOUL_DECK_0 || idx >= DRAGON_SOUL_DECK_MAX_NUM)
		return;
	
	std::vector<int> gradeList;
	bool bExpired = false;
	for (int i = 0; i < DS_SLOT_MAX; i++)
		gradeList.push_back(0);
	
	int j = 0;
	for (int i = DRAGON_SOUL_EQUIP_SLOT_START + DS_SLOT_MAX * idx; i < DRAGON_SOUL_EQUIP_SLOT_START + DS_SLOT_MAX * (idx + 1); i++)
	{
		LPITEM pItem = GetInventoryItem(i);
		if (!pItem)
			return;
		
		if (!DSManager::instance().IsTimeLeftDragonSoul(pItem))
			bExpired = true;
		
		gradeList[j] = (pItem->GetVnum() / 1000) % 10;
		j += 1;
	}
	
	if ((!bExpired) && ((gradeList[0] == DRAGON_SOUL_GRADE_LEGENDARY)
#ifdef ENABLE_DS_GRADE_MYTH
		|| (gradeList[0] == DRAGON_SOUL_GRADE_MYTH)
#endif
	)) {
		if (std::equal(gradeList.begin() + 1, gradeList.end(), gradeList.begin())) {
			AddAffect(AFFECT_DS_SET, APPLY_NONE, gradeList[0], 0, INFINITE_AFFECT_DURATION, 0, false);
			
			TPacketDSTable p;
			p.bHeader = HEADER_GC_DS_TABLE;
			for (int i = DRAGON_SOUL_EQUIP_SLOT_START + DS_SLOT_MAX * idx; i < DRAGON_SOUL_EQUIP_SLOT_START + DS_SLOT_MAX * (idx + 1); i++) {
				LPITEM pItem = GetInventoryItem(i);
				if (NULL != pItem) {
					p.iType = pItem->GetVnum() / 10000;
					p.fWeight = DSManager::instance().GetWeight(pItem->GetVnum());
					p.iApplyCount = DSManager::instance().GetApplyCount(pItem->GetVnum());
					
					for (int q = 0; q < 255; q++) {
						p.iBasicApplyValue[q] = 0;
						p.iAditionalApplyValue[q] = 0;
					}
					
					for (int q = 0; q < p.iApplyCount; q++)
						p.iBasicApplyValue[pItem->GetAttributeType(q)] = DSManager::instance().GetBasicApplyValue(pItem->GetVnum(), pItem->GetAttributeType(q));
					
					for (int q = p.iApplyCount; q < ITEM_ATTRIBUTE_MAX_NUM; q++)
						p.iAditionalApplyValue[pItem->GetAttributeType(q)] = DSManager::instance().GetAdditionalApplyValue(pItem->GetVnum(), pItem->GetAttributeType(q));
					
					GetDesc()->Packet(&p, sizeof(p));
				}
			}
		}
	}
}
#endif