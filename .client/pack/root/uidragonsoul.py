# Search:
		self.__LoadWindow()
		self.interface = None
# Add after:
		if app.ENABLE_DS_SET:
			self.setGrade = 0



# Search:
	def SetDeckPage(self, page):
		if page == self.deckPageIndex:
			return
	
		if self.isActivated:
			self.DeactivateDragonSoul()
			net.SendChatPacket("/dragon_soul deactivate")
		self.deckPageIndex = page
		self.deckTab[page].Down()
		self.deckTab[(page+1)%2].SetUp()
		
		self.RefreshEquipSlotWindow()
# Add after:
	if app.ENABLE_DS_SET:
		def SetDSSetGrade(self, grade):
			self.setGrade = grade

		def GetDSSetGrade(self):
			if not self.isActivated:
				return 0
			
			return self.setGrade