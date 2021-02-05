// Search:
				if (ia.bType == APPLY_SKILL)
					m_pOwner->ApplyPoint(ia.bType, bAdd ? ia.sValue : ia.sValue ^ 0x00800000);
				else
					m_pOwner->ApplyPoint(ia.bType, bAdd ? ia.sValue : -ia.sValue);
// Replace with:
#ifdef ENABLE_DS_SET
				short sVal = ia.sValue;
				if ((IsDragonSoul()) && (m_pOwner->FindAffect(AFFECT_DS_SET)))
					sVal += i < DSManager::instance().GetApplyCount(GetVnum()) ? DSManager::instance().GetBasicApplyValue(GetVnum(), ia.bType, true) : DSManager::instance().GetAdditionalApplyValue(GetVnum(), ia.bType, true);
				
				if (ia.bType == APPLY_SKILL)
					m_pOwner->ApplyPoint(ia.bType, bAdd ? sVal : sVal ^ 0x00800000);
				else
					m_pOwner->ApplyPoint(ia.bType, bAdd ? sVal : -sVal);
#else
				if (ia.bType == APPLY_SKILL)
					m_pOwner->ApplyPoint(ia.bType, bAdd ? ia.sValue : ia.sValue ^ 0x00800000);
				else
					m_pOwner->ApplyPoint(ia.bType, bAdd ? ia.sValue : -ia.sValue);
#endif