// Search:
	if (item->GetWearFlag() & WEARABLE_UNIQUE)
	{
		if ((GetWear(WEAR_UNIQUE1) && GetWear(WEAR_UNIQUE1)->IsSameSpecialGroup(item)) ||
			(GetWear(WEAR_UNIQUE2) && GetWear(WEAR_UNIQUE2)->IsSameSpecialGroup(item)))
		{
			ChatPacket(CHAT_TYPE_INFO, LC_TEXT("같은 종류의 유니크 아이템 두 개를 동시에 장착할 수 없습니다."));
			return false;
		}

		if (marriage::CManager::instance().IsMarriageUniqueItem(item->GetVnum()) &&
			!marriage::CManager::instance().IsMarried(GetPlayerID()))
		{
			ChatPacket(CHAT_TYPE_INFO, LC_TEXT("결혼하지 않은 상태에서 예물을 착용할 수 없습니다."));
			return false;
		}
	}
// Add after:
#ifdef ENABLE_DS_SET
	if ((DragonSoul_IsDeckActivated()) && (item->IsDragonSoul())) {
		ChatPacket(CHAT_TYPE_INFO, LC_TEXT("DS_DEACTIVATE_REQ"));
		return false;
	}
#endif



// Search:
	// 영원히 해제할 수 없는 아이템
	if (IS_SET(item->GetFlag(), ITEM_FLAG_IRREMOVABLE))
		return false;
// Add after:
#ifdef ENABLE_DS_SET
	if ((DragonSoul_IsDeckActivated()) && (item->IsDragonSoul())) {
		ChatPacket(CHAT_TYPE_INFO, LC_TEXT("DS_DEACTIVATE_REQ"));
		return false;
	}
#endif