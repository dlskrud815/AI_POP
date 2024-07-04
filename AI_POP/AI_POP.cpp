
// AI_POP.cpp : Defines the class behaviors for the application.
//

#include "pch.h"
#include "framework.h"
#include "AI_POP.h"
#include "AI_POPDlg.h"

#include <gdiplus.h>
#pragma comment(lib, "gdiplus")
using namespace Gdiplus;


#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CAIPOPApp

BEGIN_MESSAGE_MAP(CAIPOPApp, CWinApp)
	ON_COMMAND(ID_HELP, &CWinApp::OnHelp)
END_MESSAGE_MAP()


// CAIPOPApp construction

CAIPOPApp::CAIPOPApp()
{
	// TODO: add construction code here,
	// Place all significant initialization in InitInstance
}


// The one and only CAIPOPApp object

CAIPOPApp theApp;
//GDI+ 토큰
ULONG_PTR gdiplusToken;

// CAIPOPApp initialization

BOOL CAIPOPApp::InitInstance()
{
	GdiplusStartupInput gdiplusStartupInput;
	if (::GdiplusStartup(&gdiplusToken, &gdiplusStartupInput, NULL) != Ok) {
		AfxMessageBox(_T("GDI+ 라이브러리의 초기화에 실패하였습니다!"));
		return FALSE;
	}

	CWinApp::InitInstance();

	// Create the shell manager, in case the dialog contains
	// any shell tree view or shell list view controls.
	CShellManager *pShellManager = new CShellManager;

	// Activate "Windows Native" visual manager for enabling themes in MFC controls
	CMFCVisualManager::SetDefaultManager(RUNTIME_CLASS(CMFCVisualManagerWindows));

	// Standard initialization
	// If you are not using these features and wish to reduce the size
	// of your final executable, you should remove from the following
	// the specific initialization routines you do not need
	// Change the registry key under which our settings are stored
	// TODO: You should modify this string to be something appropriate
	// such as the name of your company or organization
	SetRegistryKey(_T("Local AppWizard-Generated Applications"));

	CAIPOPDlg dlg;
	m_pMainWnd = &dlg;
	INT_PTR nResponse = dlg.DoModal();
	if (nResponse == IDOK)
	{
		// TODO: Place code here to handle when the dialog is
		//  dismissed with OK
	}
	else if (nResponse == IDCANCEL)
	{
		// TODO: Place code here to handle when the dialog is
		//  dismissed with Cancel
	}
	else if (nResponse == -1)
	{
		TRACE(traceAppMsg, 0, "Warning: dialog creation failed, so application is terminating unexpectedly.\n");
		TRACE(traceAppMsg, 0, "Warning: if you are using MFC controls on the dialog, you cannot #define _AFX_NO_MFC_CONTROLS_IN_DIALOGS.\n");
	}

	// Delete the shell manager created above.
	if (pShellManager != nullptr)
	{
		delete pShellManager;
	}

#if !defined(_AFXDLL) && !defined(_AFX_NO_MFC_CONTROLS_IN_DIALOGS)
	ControlBarCleanUp();
#endif

	// Since the dialog has been closed, return FALSE so that we exit the
	//  application, rather than start the application's message pump.
	return FALSE;
}



int CAIPOPApp::ExitInstance()
{
	// TODO: Add your specialized code here and/or call the base class
	::GdiplusShutdown(gdiplusToken);

	return CWinApp::ExitInstance();
}
