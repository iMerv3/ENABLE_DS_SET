// Search:
	bool	IsActiveDragonSoul(LPITEM pItem) const;
// Add after:
#ifdef ENABLE_DS_SET
	float	GetWeight(DWORD dwVnum);
	int		GetApplyCount(DWORD dwVnum);
	int		GetBasicApplyValue(DWORD dwVnum, int iType, bool bAttr = false);
	int		GetAdditionalApplyValue(DWORD dwVnum, int iType, bool bAttr = false);
#endif