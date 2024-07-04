#pragma once

class CSkinButton : public CButton
{
public:
	CSkinButton::CSkinButton()
	{
		m_clrBackground = Gdiplus::Color(255, 64, 64, 64);
		m_clrBorder = Gdiplus::Color(255, 128, 128, 128);
		m_clrText = Gdiplus::Color(255, 255, 255, 255);
		m_strText = _T("Button");
		m_fSizeText = 15;
	}
	~CSkinButton() {}

	void SetColorBackground(int a, int r, int g, int b);
	void SetColorBorder(int a, int r, int g, int b);
	void SetColorText(int a, int r, int g, int b);
	void SetSizeText(float size);

private:
	Gdiplus::Color m_clrBackground; // ��� ����. 
	Gdiplus::Color m_clrBorder; // �ܰ��� ����. 
	Gdiplus::Color m_clrText; // �ؽ�Ʈ ����. 
	float m_fSizeText; // �ؽ�Ʈ ũ��. 
	CString m_strText; // ���ڿ�.

	void DrawBackground(Gdiplus::Graphics* pG); // ��� �׸���.
	void DrawBorder(Gdiplus::Graphics* pG); // �ܰ��� �׸���.
	void DrawText(Gdiplus::Graphics* pG); // �ؽ�Ʈ �׸���.
public:
	DECLARE_MESSAGE_MAP()
		afx_msg void OnPaint();
};

