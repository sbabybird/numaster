// NumMaster.h : main header file for the NUMMASTER application
//

#if !defined(AFX_NUMMASTER_H__F3BBD43C_3B27_43B8_8B59_2BDC9EFDB435__INCLUDED_)
#define AFX_NUMMASTER_H__F3BBD43C_3B27_43B8_8B59_2BDC9EFDB435__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#ifndef __AFXWIN_H__
	#error include 'stdafx.h' before including this file for PCH
#endif

#include "resource.h"		// main symbols

/////////////////////////////////////////////////////////////////////////////
// CNumMasterApp:
// See NumMaster.cpp for the implementation of this class
//

class CNumMasterApp : public CWinApp
{
public:
	CNumMasterApp();

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CNumMasterApp)
	public:
	virtual BOOL InitInstance();
	virtual int ExitInstance();
	//}}AFX_VIRTUAL

// Implementation

	//{{AFX_MSG(CNumMasterApp)
		// NOTE - the ClassWizard will add and remove member functions here.
		//    DO NOT EDIT what you see in these blocks of generated code !
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};


/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_NUMMASTER_H__F3BBD43C_3B27_43B8_8B59_2BDC9EFDB435__INCLUDED_)
