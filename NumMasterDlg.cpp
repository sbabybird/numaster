// NumMasterDlg.cpp : implementation file
//

#include "stdafx.h"
#include "NumMaster.h"
#include "NumMasterDlg.h"
#include "time.h"
#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CAboutDlg dialog used for App About

class CAboutDlg : public CDialog
{
public:
	CAboutDlg();

// Dialog Data
	//{{AFX_DATA(CAboutDlg)
	enum { IDD = IDD_ABOUTBOX };
	//}}AFX_DATA

	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CAboutDlg)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:
	//{{AFX_MSG(CAboutDlg)
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

CAboutDlg::CAboutDlg() : CDialog(CAboutDlg::IDD)
{
	//{{AFX_DATA_INIT(CAboutDlg)
	//}}AFX_DATA_INIT
}

void CAboutDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CAboutDlg)
	//}}AFX_DATA_MAP
}

BEGIN_MESSAGE_MAP(CAboutDlg, CDialog)
	//{{AFX_MSG_MAP(CAboutDlg)
		// No message handlers
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CNumMasterDlg dialog

CNumMasterDlg::CNumMasterDlg(CWnd* pParent /*=NULL*/)
	: CDialog(CNumMasterDlg::IDD, pParent)
{
	//{{AFX_DATA_INIT(CNumMasterDlg)
	m_strQusetion = _T("");
	m_strAnswer = _T("");
	m_strInfo = _T("");
	//}}AFX_DATA_INIT
	// Note that LoadIcon does not require a subsequent DestroyIcon in Win32
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
	m_iRight = 0;
	m_iWrong = 0;
}

void CNumMasterDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CNumMasterDlg)
	DDX_Text(pDX, IDC_QUSETION, m_strQusetion);
	DDX_Text(pDX, IDC_ANSWER, m_strAnswer);
	DDX_Text(pDX, IDC_STATIC_INFO, m_strInfo);
	//}}AFX_DATA_MAP
}

BEGIN_MESSAGE_MAP(CNumMasterDlg, CDialog)
	//{{AFX_MSG_MAP(CNumMasterDlg)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_BN_CLICKED(IDC_IASK, OnIask)
	ON_BN_CLICKED(IDC_YOUASK, OnYouask)
	ON_BN_CLICKED(IDC_CALC, OnCalc)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CNumMasterDlg message handlers

BOOL CNumMasterDlg::OnInitDialog()
{
	CDialog::OnInitDialog();

	// Add "About..." menu item to system menu.

	// IDM_ABOUTBOX must be in the system command range.
	ASSERT((IDM_ABOUTBOX & 0xFFF0) == IDM_ABOUTBOX);
	ASSERT(IDM_ABOUTBOX < 0xF000);

	CMenu* pSysMenu = GetSystemMenu(FALSE);
	if (pSysMenu != NULL)
	{
		CString strAboutMenu;
		strAboutMenu.LoadString(IDS_ABOUTBOX);
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
 
	font.CreateFont(22,
	  22,
	  0,
	  0,
	  100,
	  FALSE,
	  FALSE,0,ANSI_CHARSET,OUT_DEFAULT_PRECIS,CLIP_DEFAULT_PRECIS,DEFAULT_QUALITY,FF_SWISS,"黑体");
  
	CWnd* pWnd = NULL;
	pWnd = GetDlgItem(IDC_QUSETION);
	if (pWnd != NULL)
	{
		pWnd->SetFont(&font, FALSE);
	}
	pWnd = GetDlgItem(IDC_ANSWER);
	if (pWnd != NULL)
	{
		pWnd->SetFont(&font, FALSE);
	}
	pWnd = GetDlgItem(IDC_STATIC_INFO);
	if (pWnd != NULL)
	{
		pWnd->SetFont(&font, FALSE);
	}

	pWnd = GetDlgItem(IDC_IASK);
	if (pWnd != NULL)
	{
		pWnd->SetFont(&font, FALSE);
	}
	pWnd = GetDlgItem(IDC_YOUASK);
	if (pWnd != NULL)
	{
		pWnd->SetFont(&font, FALSE);
	}
	pWnd = GetDlgItem(IDC_CALC);
	if (pWnd != NULL)
	{
		pWnd->SetFont(&font, FALSE);
	}
	
	// TODO: Add extra initialization here
	OnIask();
	RefashInfo();
	
	return TRUE;  // return TRUE  unless you set the focus to a control
}

void CNumMasterDlg::OnSysCommand(UINT nID, LPARAM lParam)
{
	if ((nID & 0xFFF0) == IDM_ABOUTBOX)
	{
		CAboutDlg dlgAbout;
		dlgAbout.DoModal();
	}
	else
	{
		CDialog::OnSysCommand(nID, lParam);
	}
}

// If you add a minimize button to your dialog, you will need the code below
//  to draw the icon.  For MFC applications using the document/view model,
//  this is automatically done for you by the framework.

void CNumMasterDlg::OnPaint() 
{
	if (IsIconic())
	{
		CPaintDC dc(this); // device context for painting

		SendMessage(WM_ICONERASEBKGND, (WPARAM) dc.GetSafeHdc(), 0);

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
		CDialog::OnPaint();
	}
}

// The system calls this to obtain the cursor to display while the user drags
//  the minimized window.
HCURSOR CNumMasterDlg::OnQueryDragIcon()
{
	return (HCURSOR) m_hIcon;
}

void CNumMasterDlg::OnIask() 
{
	// TODO: Add your control notification handler code here
	m_strQusetion = GetQuestion();

	m_strAnswer = "";

	UpdateData(FALSE);
	
}

void CNumMasterDlg::OnYouask() 
{
	// TODO: Add your control notification handler code here
	UpdateData(TRUE);

	if (CheckAnswer(m_strQusetion, m_strAnswer))
	{
		m_iSpecker.PlaySoundWithName("IDR_RIGHT");
		m_iRight++;
	}
	else
	{
		m_iSpecker.PlaySoundWithName("IDR_WORNG");
		m_iSpecker.PlaySoundWithName("IDR_ANSWER");
		OnCalc();
		m_iWrong++;
	}

	OnIask();
	
	RefashInfo();
	
}

void CNumMasterDlg::RefashInfo()
{
	m_strInfo.Format("答对%d题 答错%d题", m_iRight, m_iWrong);

	UpdateData(FALSE);
}

void CNumMasterDlg::OnCalc() 
{
	// TODO: Add your control notification handler code here
	UpdateData(TRUE);

	m_strAnswer.Format("%d", GetAnswer(m_strQusetion));

	UpdateData(FALSE);

	m_iSpecker.SpeckerNumber(atoi(m_strAnswer));
}

CString CNumMasterDlg::GetQuestion()
{
	CString str;

	srand( time(NULL) );

	int a = rand()%100;

	int b = rand()%100;

	if (a<b)
	{
		int c = a;

		a = b;

		b = c;
	}

	int symbol = rand()%2;

	if (symbol == 1)
	{
		str.Format("%d+%d", a, b);
	}
	else
	{
		str.Format("%d-%d", a, b);
	}

	return str;
}

int CNumMasterDlg::GetAnswer(CString str)
{
	int iAns = 0;

	int iIndex = str.Find("+");

	if (iIndex>0)
	{
		iAns = GetAnswer(str.Left(iIndex)) + GetAnswer(str.Right(str.GetLength()-iIndex-1));
	}
	else
	{
		iIndex = str.Find("-");

		if (iIndex>0)
		{
			iAns = GetAnswer(str.Left(iIndex)) - GetAnswer(str.Right(str.GetLength()-iIndex-1));
		}
		else
		{
			iAns = atoi(str);
		}
	}

	return iAns;
}

BOOL CNumMasterDlg::CheckAnswer(CString strQue, CString strAns)
{
	BOOL bRet = FALSE;

	if (GetAnswer(strQue) == atoi(strAns))
		bRet = TRUE;

	return bRet;
}

void CNumMasterDlg::OnOK() 
{
	// TODO: Add extra validation here
	OnYouask();
}
