// Search:
void CPythonItem::Create()
{
	CEffectManager::Instance().RegisterEffect2("d:/ymir work/effect/etc/dropitem/dropitem.mse", &m_dwDropItemEffectID);
}
// Add after:
#ifdef ENABLE_DS_SET
bool CPythonItem::SetDSTable(TPacketDSTable p) {
	if (m_DSTableMap.end() != m_DSTableMap.find(p.iType))
		m_DSTableMap.erase(m_DSTableMap.find(p.iType));
	
	TDSTable t;
	t.fWeight = p.fWeight;
	t.iApplyCount = p.iApplyCount;
	for (int i = 0; i < 255; i++) {
		t.iBasicApplyValue[i] = p.iBasicApplyValue[i];
		t.iAditionalApplyValue[i] = p.iAditionalApplyValue[i];
	}
	
	m_DSTableMap.insert(make_pair(p.iType, t));
	return true;
}

float CPythonItem::GetDSSetWeight(int iDSType, int iDSGrade) {
	return (m_DSTableMap.end() == m_DSTableMap.find(iDSType) == true ? 0 : m_DSTableMap[iDSType].fWeight);
}

int CPythonItem::GetDSBasicApplyCount(int iDSType, int iDSGrade) {
	return (m_DSTableMap.end() == m_DSTableMap.find(iDSType) == true ? 0 : m_DSTableMap[iDSType].iApplyCount);
}

int CPythonItem::GetDSBasicApplyValue(int iDSType, int iDSApplyType) {
	return (m_DSTableMap.end() == m_DSTableMap.find(iDSType) == true ? 0 : m_DSTableMap[iDSType].iBasicApplyValue[iDSApplyType]);
}

int CPythonItem::GetDSAdditionalApplyValue(int iDSType, int iDSApplyType) {
	return (m_DSTableMap.end() == m_DSTableMap.find(iDSType) == true ? 0 : m_DSTableMap[iDSType].iAditionalApplyValue[iDSApplyType]);
}
#endif



// Search:
	assert(m_GroundItemInstanceMap.empty());
// Add after:
#ifdef ENABLE_DS_SET
	assert(m_DSTableMap.empty());
#endif