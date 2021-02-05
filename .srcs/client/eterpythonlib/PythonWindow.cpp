// Search:
	void CTextLine::OnChangePosition()
	{
		// FOR_ARABIC_ALIGN
		//if (m_TextInstance.GetHorizontalAlign() == CGraphicTextInstance::HORIZONTAL_ALIGN_ARABIC)
		if( GetDefaultCodePage() == CP_ARABIC )
		{
			m_TextInstance.SetPosition(m_rect.right, m_rect.top);
		}
		else
		{
			m_TextInstance.SetPosition(m_rect.left, m_rect.top);
		}
	}
// Add after:
	void CTextLine::SetLineHeight(int iHeight) {
		m_TextInstance.SetLineHeight(iHeight);
		m_TextInstance.Update();
	}

	int CTextLine::GetLineHeight() {
		return m_TextInstance.GetLineHeight();
	}

	int CTextLine::GetTextLineCount() {
		return m_TextInstance.GetTextLineCount();
	}