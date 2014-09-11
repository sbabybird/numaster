// NumMasterDlg.h : header file
//

#if !defined(AFX_NUMMASTERDLG_H__C5848271_490E_4CBE_A830_C58C3A1CE36F__INCLUDED_)
#define AFX_NUMMASTERDLG_H__C5848271_490E_4CBE_A830_C58C3A1CE36F__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#include "Specker.h"
/////////////////////////////////////////////////////////////////////////////
// CNumMasterDlg dialog

class CNumMasterDlg : public CDialog
{
// Construction
public:
	CNumMasterDlg(CWnd* pParent = NULL);	// standard constructor

// Dialog Data
	//{{AFX_DATA(CNumMasterDlg)
	enum { IDD = IDD_NUMMASTER_DIALOG };
	CString	m_strQusetion;
	CString	m_strAnswer;
	CString	m_strInfo;
	//}}AFX_DATA

	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CNumMasterDlg)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV support
	//}}AFX_VIRTUAL

	CFont   font;  

private:
		CString GetQuestion();
		int		GetAnswer(CString str);
		BOOL	CheckAnswer(CString strQue, CString strAns);

		CSpecker m_iSpecker;

		int m_iRight;
		int m_iWrong;

		void RefashInfo();
// Implementation
protected:
	HICON m_hIcon;

	// Generated message map functions
	//{{AFX_MSG(CNumMasterDlg)
	virtual BOOL OnInitDialog();
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	afx_msg void OnIask();
	afx_msg void OnYouask();
	afx_msg void OnCalc();
	virtual void OnOK();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_NUMMASTERDLG_H__C5848271_490E_4CBE_A830_C58C3A1CE36F__INCLUDED_)
