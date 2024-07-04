
// AI_POPDlg.h : header file
//

#pragma once
#include "MySQL_Connector.h"
#include "CSkinButton.h"
#include <string>

using namespace std;

// CAIPOPDlg dialog
class CAIPOPDlg : public CDialogEx
{
// Construction
public:
	CAIPOPDlg(CWnd* pParent = nullptr);	// standard constructor

// Dialog Data
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_AI_POP_DIALOG };
#endif

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV support


// Implementation
protected:
	HICON m_hIcon;

	// Generated message map functions
	virtual BOOL OnInitDialog();
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	DECLARE_MESSAGE_MAP()

public:
	CSkinButton m_skinBtn;
	afx_msg void OnBnClickedButtonLogin();
	afx_msg void OnLButtonDown(UINT nFlags, CPoint point);
	afx_msg void OnExitClicked();

	CString m_userID;
	CString m_userPW;
};
