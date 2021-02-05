# Search:
		elif chr.NEW_AFFECT_DRAGON_SOUL_QUALIFIED == type:
			self.BINARY_DragonSoulGiveQuilification()
# Add after:
		elif app.ENABLE_DS_SET and chr.NEW_AFFECT_DS_SET == type:
			self.interface.DragonSoulSetGrade(value)



# Search:
		if chr.NEW_AFFECT_DRAGON_SOUL_DECK1 == type or chr.NEW_AFFECT_DRAGON_SOUL_DECK2 == type:
			self.interface.DragonSoulDeactivate()
# Add after:
		elif app.ENABLE_DS_SET and chr.NEW_AFFECT_DS_SET == type:
			self.interface.DragonSoulSetGrade(0)