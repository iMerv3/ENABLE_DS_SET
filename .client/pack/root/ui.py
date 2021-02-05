# Search:
class TextLine(Window):
# Add at end of class:
	def SetLineHeight(self, Height):
		wndMgr.SetLineHeight(self.hWnd, Height)

	def GetLineHeight(self):
		return wndMgr.GetLineHeight(self.hWnd)

	def GetTextLineCount(self):
		return wndMgr.GetTextLineCount(self.hWnd)