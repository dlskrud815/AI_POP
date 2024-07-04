
// AI_POPDlg.cpp : implementation file
//

#include "pch.h"
#include "framework.h"
#include "AI_POP.h"
#include "AI_POPDlg.h"
#include "afxdialogex.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CAboutDlg dialog used for App About

class CAboutDlg : public CDialogEx
{
public:
	CAboutDlg();

// Dialog Data
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_ABOUTBOX };
#endif

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support

// Implementation
protected:
	DECLARE_MESSAGE_MAP()
};

CAboutDlg::CAboutDlg() : CDialogEx(IDD_ABOUTBOX)
{
}

void CAboutDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}

BEGIN_MESSAGE_MAP(CAboutDlg, CDialogEx)
END_MESSAGE_MAP()


// CAIPOPDlg dialog



CAIPOPDlg::CAIPOPDlg(CWnd* pParent /*=nullptr*/)
	: CDialogEx(IDD_AI_POP_DIALOG, pParent)
{
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CAIPOPDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_BUTTON_LOGIN, m_skinBtn);
	DDX_Text(pDX, IDC_EDIT_ID, m_userID);
	DDX_Text(pDX, IDC_EDIT_PW, m_userPW);
}

BEGIN_MESSAGE_MAP(CAIPOPDlg, CDialogEx)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_BN_CLICKED(IDC_BUTTON_LOGIN, &CAIPOPDlg::OnBnClickedButtonLogin)
	ON_WM_LBUTTONDOWN()
	ON_BN_CLICKED(IDC_BUTTON2, &CAIPOPDlg::OnExitClicked)
END_MESSAGE_MAP()


// CAIPOPDlg message handlers

BOOL CAIPOPDlg::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// Add "About..." menu item to system menu.

	// IDM_ABOUTBOX must be in the system command range.
	ASSERT((IDM_ABOUTBOX & 0xFFF0) == IDM_ABOUTBOX);
	ASSERT(IDM_ABOUTBOX < 0xF000);

	CMenu* pSysMenu = GetSystemMenu(FALSE);
	if (pSysMenu != nullptr)
	{
		BOOL bNameValid;
		CString strAboutMenu;
		bNameValid = strAboutMenu.LoadString(IDS_ABOUTBOX);
		ASSERT(bNameValid);
		if (!strAboutMenu.IsEmpty())
		{
			pSysMenu->AppendMenu(MF_SEPARATOR);
			pSysMenu->AppendMenu(MF_STRING, IDM_ABOUTBOX, strAboutMenu);
		}
	}

	// Set the icon for this dialog.  The framework does this automatically
	//  when the application's main window is not a dialog
	SetIcon(m_hIcon, TRUE);			// Set big icon
	SetIcon(m_hIcon, FALSE);		// Set small icon

	// TODO: Add extra initialization here



	return TRUE;  // return TRUE  unless you set the focus to a control
}

void CAIPOPDlg::OnSysCommand(UINT nID, LPARAM lParam)
{
	if ((nID & 0xFFF0) == IDM_ABOUTBOX)
	{
		CAboutDlg dlgAbout;
		dlgAbout.DoModal();
	}
	else
	{
		CDialogEx::OnSysCommand(nID, lParam);
	}
}

// If you add a minimize button to your dialog, you will need the code below
//  to draw the icon.  For MFC applications using the document/view model,
//  this is automatically done for you by the framework.

void CAIPOPDlg::OnPaint()
{
	if (IsIconic())
	{
		CPaintDC dc(this); // device context for painting

		SendMessage(WM_ICONERASEBKGND, reinterpret_cast<WPARAM>(dc.GetSafeHdc()), 0);

		// Center icon in client rectangle
		int cxIcon = GetSystemMetrics(SM_CXICON);
		int cyIcon = GetSystemMetrics(SM_CYICON);
		CRect rect;
		GetClientRect(&rect);
		int x = (rect.Width() - cxIcon + 1) / 2;
		int y = (rect.Height() - cyIcon + 1) / 2;

		// Draw the icon
		dc.DrawIcon(x, y, m_hIcon);
	}
	else
	{
		CPaintDC dc(this); // 그리기를 위한 장치 컨텍스트

		// 배경을 채우는 사각형 그리기
		CRect rect;
		GetClientRect(&rect);
		dc.FillSolidRect(rect, RGB(53, 58, 64)); // 흰색 배경

		CDialogEx::OnPaint();
	}
}

// The system calls this function to obtain the cursor to display while the user drags
//  the minimized window.
HCURSOR CAIPOPDlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}

void CAIPOPDlg::OnBnClickedButtonLogin()
{
	// TODO: Add your control notification handler code here
	//AfxMessageBox(_T("SkinButton!"));

	UpdateData(TRUE);  // 다이얼로그 컨트롤 값 업데이트

	CStringA strIdA(m_userID), strPwA(m_userPW);
	string stdID(strIdA.GetBuffer()), stdPW(strPwA.GetBuffer());


	// MySQLConnector 객체 생성
	MySQL_Connector mysql;

	// 데이터베이스 서버 연결
	if (mysql.connect("tcp://127.0.0.1:3306", "user", "1234")) {
		// 로그인 처리
		if (mysql.login(stdID, stdPW)) {
			MessageBox(_T("로그인 성공"), _T("알림"), MB_OK | MB_ICONINFORMATION);
			// 로그인 성공 후 다음 작업 수행
		}
		else {
			MessageBox(_T("아이디 또는 비밀번호가 틀렸습니다."), _T("오류"), MB_OK | MB_ICONERROR);
		}
	}
	else {
		MessageBox(_T("데이터베이스 연결 실패"), _T("오류"), MB_OK | MB_ICONERROR);
	}
}


void CAIPOPDlg::OnLButtonDown(UINT nFlags, CPoint point)
{
	//다이얼로그 드래그
	SendMessage(WM_NCLBUTTONDOWN, HTCAPTION, MAKELPARAM(point.x, point.y));

	CDialogEx::OnLButtonDown(nFlags, point);
}


void CAIPOPDlg::OnExitClicked()
{
	// 종료 버튼 클릭 시 수행할 작업 추가
	OnOK(); // 기본 종료 동작 (EndDialog(IDOK)과 동일)
}
