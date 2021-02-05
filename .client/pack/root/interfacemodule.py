# Search:
		self.tooltipItem = uiToolTip.ItemToolTip()
# Add after:
		if app.ENABLE_DS_SET:
			self.tooltipItem.BindInterface(self)



# Search:
	# ¿ëÈ¥¼®
	def DragonSoulActivate(self, deck):
		self.wndDragonSoul.ActivateDragonSoulByExtern(deck)
# Add after:
	if app.ENABLE_DS_SET:
		def DragonSoulSetGrade(self, grade):
			self.wndDragonSoul.SetDSSetGrade(grade)