// Search:
int CGraphicTextInstance::GetHorizontalAlign()
{
	return m_hAlign;
}
// Add after:
void CGraphicTextInstance::SetLineHeight(int iHeight) {
	m_textHeight = iHeight;
}

int CGraphicTextInstance::GetLineHeight() {
	return m_textHeight;
}