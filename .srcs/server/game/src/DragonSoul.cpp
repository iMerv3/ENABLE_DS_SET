// Search:
DSManager::DSManager()
{
	m_pTable = NULL;
}
// Add before:
#ifdef ENABLE_DS_SET
float DSManager::GetWeight(DWORD dwVnum) {
	BYTE ds_type, grade_idx, step_idx, strength_idx;
	GetDragonSoulInfo(dwVnum, ds_type, grade_idx, step_idx, strength_idx);
	
	float fWeight = 0.f;
	if (!m_pTable->GetWeight(ds_type, grade_idx-1, 0, 0, fWeight))
		return 0.f;
	
	return fWeight;
}

int DSManager::GetApplyCount(DWORD dwVnum) {
	BYTE ds_type, grade_idx, step_idx, strength_idx;
	GetDragonSoulInfo(dwVnum, ds_type, grade_idx, step_idx, strength_idx);
	
	int basic_apply_num, add_min, add_max;
	if (!m_pTable->GetApplyNumSettings(ds_type, grade_idx, basic_apply_num, add_min, add_max))
		return 0;
	
	return basic_apply_num;
}

int DSManager::GetBasicApplyValue(DWORD dwVnum, int iType, bool bAttr) {
	BYTE ds_type, grade_idx, step_idx, strength_idx;
	GetDragonSoulInfo(dwVnum, ds_type, grade_idx, step_idx, strength_idx);
	
	DragonSoulTable::TVecApplys vec_basic_applys;
	int ret = 0;
	if (!m_pTable->GetBasicApplys(ds_type, vec_basic_applys))
		return ret;
	
	for (size_t j = 0; j < vec_basic_applys.size(); j++) {
		if (vec_basic_applys[j].apply_type == iType) {
			if (!bAttr)
				ret = vec_basic_applys[j].apply_value;
			else {
				float fWeight = 0.f;
				if (!m_pTable->GetWeight(ds_type, grade_idx-1, 0, 0, fWeight))
					return 0;
				
				fWeight /= 100.f;
				ret = (short)(ceil((float)vec_basic_applys[j].apply_value * fWeight - 0.01f));
			}
			break;
		}
	}
	
	return ret;
}

int DSManager::GetAdditionalApplyValue(DWORD dwVnum, int iType, bool bAttr) {
	BYTE ds_type, grade_idx, step_idx, strength_idx;
	GetDragonSoulInfo(dwVnum, ds_type, grade_idx, step_idx, strength_idx);
	
	DragonSoulTable::TVecApplys vec_addtional_applys;
	int ret = 0;
	if (!m_pTable->GetAdditionalApplys(ds_type, vec_addtional_applys))
		return ret;
	
	for (size_t j = 0; j < vec_addtional_applys.size(); j++) {
		if (vec_addtional_applys[j].apply_type == iType) {
			if (!bAttr)
				ret = vec_addtional_applys[j].apply_value;
			else {
				float fWeight = 0.f;
				if (!m_pTable->GetWeight(ds_type, grade_idx-1, 0, 0, fWeight))
					return 0;
				
				fWeight /= 100.f;
				ret = (short)(ceil((float)vec_addtional_applys[j].apply_value * fWeight - 0.01f));
			}
			break;
		}
	}
	
	return ret;
}
#endif