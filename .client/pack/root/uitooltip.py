# Search:
import constInfo
# Add after:
if app.ENABLE_DS_SET:
	import uiDragonSoul



# Search:
	SPECIAL_POSITIVE_COLOR2 = grp.GenerateColor(0.8824, 0.9804, 0.8824, 1.0)
# Add after:
	if app.ENABLE_DS_SET:
		TEXTLINE_2ND_COLOR_DEFAULT = grp.GenerateColor(1.0, 1.0, 0.6078, 1.0)



# Search:
	def AppendTextLine(self, text, color = FONT_COLOR, centerAlign = True):
		textLine = ui.TextLine()
		textLine.SetParent(self)
		textLine.SetFontName(self.defFontName)
		textLine.SetPackedFontColor(color)
		textLine.SetText(text)
		textLine.SetOutline()
		textLine.SetFeather(False)
		textLine.Show()

		if centerAlign:
			textLine.SetPosition(self.toolTipWidth/2, self.toolTipHeight)
			textLine.SetHorizontalAlignCenter()

		else:
			textLine.SetPosition(10, self.toolTipHeight)

		self.childrenList.append(textLine)

		self.toolTipHeight += self.TEXT_LINE_HEIGHT
		self.ResizeToolTip()

		return textLine
# Add after:
	if app.ENABLE_DS_SET:
		def AppendTwoColorTextLine(self, text, color, text2, color2 = TEXTLINE_2ND_COLOR_DEFAULT, centerAlign = True):
			textLine = ui.TextLine()
			textLine.SetParent(self)
			textLine.SetFontName(self.defFontName)
			textLine.SetPackedFontColor(color)
			textLine.SetText(text)
			textLine.SetOutline()
			textLine.SetFeather(False)
			w, h = textLine.GetTextSize()
			
			textLine2 = ui.TextLine()
			textLine2.SetParent(textLine)
			textLine2.SetFontName(self.defFontName)
			textLine2.SetPackedFontColor(color2)
			textLine2.SetText(text2)
			textLine2.SetOutline()
			textLine2.SetFeather(False)
			textLine2.Show()
			
			w2, h2 = textLine2.GetTextSize()
			
			textLine.SetLineHeight(self.TEXT_LINE_HEIGHT)
			textLine.Show()
			if centerAlign:
				if localeInfo.IsARABIC():
					textLine.SetPosition(self.toolTipWidth/2+w2/2, self.toolTipHeight)
					textLine.SetHorizontalAlignCenter()
					textLine2.SetPosition(-w/2, 0)
				else:
					textLine.SetPosition(self.toolTipWidth/2-w2/2, self.toolTipHeight)
					textLine.SetHorizontalAlignCenter()
					textLine2.SetPosition(w/2, 0)
			else:
				textLine.SetPosition(10, self.toolTipHeight)
			
			self.childrenList.append(textLine)
			self.childrenList.append(textLine2)
			
			lineCount = textLine.GetTextLineCount()
			self.toolTipHeight += self.TEXT_LINE_HEIGHT * lineCount
			
			self.ResizeToolTip()
			return textLine



# Search:
	def __init__(self, *args, **kwargs):
# Add at end of function:
		if app.ENABLE_DS_SET:
			self.interface = None



# Search:
	def __del__(self):
		ToolTip.__del__(self)
# Add after:
	if app.ENABLE_DS_SET:
		def BindInterface(self, interface):
			from _weakref import proxy
			self.interface = proxy(interface)



# Search:
	def __AppendAttributeInformation(self, attrSlot):
		if 0 != attrSlot:

			for i in xrange(player.ATTRIBUTE_SLOT_MAX_NUM):
				type = attrSlot[i][0]
				value = attrSlot[i][1]

				if 0 == value:
					continue

				affectString = self.__GetAffectString(type, value)
				if affectString:
					affectColor = self.__GetAttributeColor(i, value)
					self.AppendTextLine(affectString, affectColor)
# Add after:
	if app.ENABLE_DS_SET:
		def __AppendDragonSoulAttributeInformation(self, attrSlot, dsType = 0, grade = 0):
			if 0 != attrSlot:
				if grade != 0:
					setWeightValue = item.GetDSSetWeight(dsType, grade)
					basicApplyCount = item.GetDSBasicApplyCount(dsType, grade)
					
					for i in xrange(player.ATTRIBUTE_SLOT_MAX_NUM):
						type = attrSlot[i][0]
						value = attrSlot[i][1]
						if 0 == value:
							continue
						
						affectString = self.__GetAffectString(type, value)
						if affectString:
							affectColor = self.__GetAttributeColor(i, value)
							
							setValue = 0
							if i < basicApplyCount:
								setValue = item.GetDSBasicApplyValue(dsType, type)
							else:
								setValue = item.GetDSAdditionalApplyValue(dsType, type)
							
							if setValue != 0:
								setValue = (setValue * setWeightValue - 1)/100 + 1
								if affectString.find('%') == -1:
									self.AppendTwoColorTextLine(affectString, affectColor, " (+%d)" % (setValue))
								else:
									self.AppendTwoColorTextLine(affectString, affectColor, " (+%d%%)" % (setValue))
							else:
								self.AppendTextLine(affectString, affectColor)
				else:
					for i in xrange(player.ATTRIBUTE_SLOT_MAX_NUM):
						type = attrSlot[i][0]
						value = attrSlot[i][1]
						if 0 == value:
							continue
						
						affectString = self.__GetAffectString(type, value)
						if affectString:
							affectColor = self.__GetAttributeColor(i, value)
							self.AppendTextLine(affectString, affectColor)



# Search:
		elif item.ITEM_TYPE_DS == itemType:
			self.AppendTextLine(self.__DragonSoulInfoString(itemVnum))
			self.__AppendAttributeInformation(attrSlot)
# Replace with:
		elif item.ITEM_TYPE_DS == itemType:
			self.AppendTextLine(self.__DragonSoulInfoString(itemVnum))
			if app.ENABLE_DS_SET:
				if window_type == player.EQUIPMENT and self.interface and self.interface.wndDragonSoul:
					self.__AppendDragonSoulAttributeInformation(attrSlot, itemVnum/10000, self.interface.wndDragonSoul.GetDSSetGrade())
				else:
					self.__AppendDragonSoulAttributeInformation(attrSlot)
			else:
				self.__AppendAttributeInformation(attrSlot)