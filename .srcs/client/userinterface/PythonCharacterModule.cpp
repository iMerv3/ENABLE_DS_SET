// Search:
	PyModule_AddIntConstant(poModule, "NEW_AFFECT_DRAGON_SOUL_DECK2", CInstanceBase::NEW_AFFECT_DRAGON_SOUL_DECK2);
// Add after:
#ifdef ENABLE_DS_SET
	PyModule_AddIntConstant(poModule, "NEW_AFFECT_DS_SET", CInstanceBase::NEW_AFFECT_DS_SET);
#endif