// prjWellLogDisperseDlg.cpp : implementation file
//

#include "stdafx.h"
#include "prjWellLogDisperse.h"
#include "prjWellLogDisperseDlg.h"

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
// CPrjWellLogDisperseDlg dialog

CPrjWellLogDisperseDlg::CPrjWellLogDisperseDlg(CWnd* pParent /*=NULL*/)
	: CDialog(CPrjWellLogDisperseDlg::IDD, pParent)
{
	//{{AFX_DATA_INIT(CPrjWellLogDisperseDlg)
	//}}AFX_DATA_INIT
	// Note that LoadIcon does not require a subsequent DestroyIcon in Win32
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CPrjWellLogDisperseDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CPrjWellLogDisperseDlg)
	DDX_Control(pDX, IDC_EDIT_DN, m_edit_dn);
	DDX_Control(pDX, IDC_EDIT_FILEPATH, m_edit_filepath);
	//}}AFX_DATA_MAP
}

BEGIN_MESSAGE_MAP(CPrjWellLogDisperseDlg, CDialog)
	//{{AFX_MSG_MAP(CPrjWellLogDisperseDlg)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_BN_CLICKED(IDC_BUTTON_OPENFILE, OnButtonOpenfile)
	ON_BN_CLICKED(ID_BUTTON_OK, OnButtonOk)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CPrjWellLogDisperseDlg message handlers

BOOL CPrjWellLogDisperseDlg::OnInitDialog()
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
	
	// TODO: Add extra initialization here
	
	return TRUE;  // return TRUE  unless you set the focus to a control
}

void CPrjWellLogDisperseDlg::OnSysCommand(UINT nID, LPARAM lParam)
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

void CPrjWellLogDisperseDlg::OnPaint() 
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
HCURSOR CPrjWellLogDisperseDlg::OnQueryDragIcon()
{
	return (HCURSOR) m_hIcon;
}


void CPrjWellLogDisperseDlg::OnButtonOpenfile() 
{
	CFileDialog dlgFileOpen(true);
	int structsize=0;
	CString strAttributeFile;
	DWORD dwVersion,dwWindowsMajorVersion,dwWindowsMinorVersion;
	//���Ŀǰ�Ĳ���ϵͳ
	dwVersion=GetVersion();
	dwWindowsMajorVersion=(DWORD)(LOBYTE(LOWORD(dwVersion)));
    dwWindowsMinorVersion=(DWORD)(HIBYTE(LOWORD(dwVersion)));
	// ������еĲ���ϵͳ��Windows NT/2000
	if (dwVersion < 0x80000000)  
		structsize =88;//��ʾ�µ��ļ��Ի��� 
	else 
	//���еĲ���ϵͳWindows 95/98  
		structsize =76;//��ʾ�ϵ��ļ��Ի��� 

	dlgFileOpen.m_ofn.lpstrFilter ="SEGY�ļ�(*.txt)\0*.txt\0���е��ļ�\0*.*\0";
	dlgFileOpen.m_ofn.lStructSize =structsize;
    char lpstrFilename[MAX_PATH] = ""; 
    dlgFileOpen.m_ofn.lpstrFile=lpstrFilename; 
	if(dlgFileOpen.DoModal()==IDOK)
	{//1
		CString strFile;
		strFile=dlgFileOpen.GetFileName();
		strFile.TrimLeft();
		strFile.TrimRight();
		strAttributeFile=dlgFileOpen.GetPathName();		
		strAttributeFile.TrimLeft();
		strAttributeFile.TrimRight();

		strFilePath=strAttributeFile.Left(strAttributeFile.GetLength()-strFile.GetLength());
		if(strAttributeFile.Right(4).Compare(".txt")!=0)
		{
			strAttributeFile=strAttributeFile+".txt";
		}
		m_edit_filepath.SetWindowText(strAttributeFile);
	}//1
}

BOOL CPrjWellLogDisperseDlg::GetParameter()
{	
	m_edit_filepath.GetWindowText(strLayerFilePathName);

	if(strLayerFilePathName.GetLength()<=0)
	{
		MessageBox("����ȷ�����ļ�·��!");
		return false;
	}

	m_edit_dn.GetWindowText(strN);
	if(strN.GetLength()<=0)
	{
		MessageBox("����ȷ������ɢֵ!");
		return false;
	}
	return true;

}

void CPrjWellLogDisperseDlg::OnButtonOk() 
{
	if(GetParameter())
	{
		CStdioFile  layerFile,wellFile,wellNewFile;
		CFileException e,we,wne;

		if(!layerFile.Open(strLayerFilePathName,CFile::modeRead|CFile::typeText,&e)) //�ж��Ƿ���ļ��ɹ�
		{//if4
			MessageBox("�޷���ָ������Ͳ����ļ�����ȷ��·�����ļ��Ƿ����","���ļ�����",MB_OK);
			return;
		}
		TCHAR BL_CHARACTER='	';
		int bi(-1);
		unsigned int nLayer(0);
		CString strLine;
		layerFile.ReadString(strLine);
		layerFile.ReadString(strLine);
		strLine.TrimLeft();
		strLine.TrimRight();
		while(strLine.GetLength()>0)
		{
			nLayer++;
			layerFile.ReadString(strLine);
			strLine.TrimLeft();
			strLine.TrimRight();
		}

		LAYER_STATUS *layerStatus;
		layerStatus=new LAYER_STATUS[nLayer];

		layerFile.SeekToBegin();
		WELL_STATUS well_status[1024];
		for(unsigned int i=0;i<1024;i++)
		{
			well_status[i].isFind=false;
			well_status[i].nLayers=0;
		}

		layerFile.ReadString(strLine);
		CString strPart;
		unsigned int nW(0);                  //����

		for(i=0;i<nLayer;i++)
		{
			layerFile.ReadString(strLine);
			bi=strLine.Find(BL_CHARACTER);
			if(bi!=-1)
			{
				strPart=strLine.Left(bi+1);
				strPart.TrimLeft();
				strPart.TrimRight();
				if(i==0)
				{
					well_status[nW].strWellName=strPart;
					well_status[nW].nLayers++;
				}
				else
				{
					if(strPart!=well_status[nW].strWellName)
					{
						nW++;
						well_status[nW].strWellName=strPart;
						well_status[nW].nLayers++;										
					}
					else
					{
						well_status[nW].nLayers++;
					}
				}

				strLine=strLine.Right(strLine.GetLength()-bi-1);
				strLine.TrimLeft();
				strLine.TrimRight();
				bi=strLine.Find(BL_CHARACTER);
				if(bi!=-1)
				{
					strPart=strLine.Left(bi+1);
					strPart.TrimLeft();
					strPart.TrimRight();
					layerStatus[i].strLayerName=strPart;

					strLine=strLine.Right(strLine.GetLength()-bi-1);
					strLine.TrimLeft();
					strLine.TrimRight();
					bi=strLine.Find(BL_CHARACTER);
					if(bi!=-1)
					{
						strPart=strLine.Left(bi+1);
						strPart.TrimLeft();
						strPart.TrimRight();
						layerStatus[i].nStartDepth =atof((LPTSTR)(LPCTSTR)strPart);
						strLine=strLine.Right(strLine.GetLength()-bi-1);
						strLine.TrimLeft();
						strLine.TrimRight();
						strPart=strLine;
						strPart.TrimLeft();
						strPart.TrimRight();
						layerStatus[i].nEndDepth =atof((LPTSTR)(LPCTSTR)strPart);						
					}
				}
			}
		}

		layerFile.Close();

		int nPosition(0);
		CString strWellStatus;
		strWellStatus="��ǰ�ļ�����δ�ҵ��ľ���\n";
		CString strDir;
		double nInterval;
		BeginWaitCursor();
		for(i=0;i<=nW;i++)
		{
			CFileFind ff;
			
			strDir=strFilePath+well_status[i].strWellName+".txt";
			BOOL res=ff.FindFile(strDir);
			if(res)
			{
				if(wellFile.Open(strDir,CFile::modeRead|CFile::typeText,&we)) //�ж��Ƿ���ļ��ɹ�
				{//if4
					//����������
					int f1,f2;
					wellFile.ReadString(strLine);
					wellFile.ReadString(strLine);
					strLine.TrimLeft();
					strLine.TrimRight();
					bi=strLine.Find(BL_CHARACTER);
					if(strLine.GetLength()>0)
						f1=(int)(atof(strLine)*1000);
					else
					{
						MessageBox("�ļ���ʽ��������!",well_status[i].strWellName,MB_OK);
						nPosition=nPosition+well_status[i].nLayers ;
						continue;
					}

					wellFile.ReadString(strLine);
					strLine.TrimLeft();
					strLine.TrimRight();
					if(strLine.GetLength()>0)
						f2=(int)(atof(strLine)*1000);
					else
					{
						MessageBox("�ļ���ʽ��������!",well_status[i].strWellName,MB_OK);
						nPosition=nPosition+well_status[i].nLayers ;
						continue;
					}

					nInterval=(f2-f1)/1000.000;
					
					//��tempĿ¼��������һ���ļ�
					strDir=strFilePath+"temp\\"+well_status[i].strWellName+".txt";
					
					wellNewFile.Open(strDir,CFile::modeWrite|CFile::typeText|CFile::modeCreate,&wne);

					wellFile.SeekToBegin();
					wellFile.ReadString(strLine);
					strLine=strLine+"	sand"+"\n";
					
					wellNewFile.WriteString((LPTSTR)(LPCTSTR)strLine);
					wellFile.ReadString(strLine);
					unsigned int ns(0);
					while(strLine.GetLength()>0)
					{
						double nCurrentDepth=f1/1000.000+ns*nInterval;
						BOOL isSand(false);
						for(int j=0;j<well_status[i].nLayers ;j++)
						{
							if(nCurrentDepth >= layerStatus[nPosition+j].nStartDepth && nCurrentDepth <= layerStatus[nPosition+j].nEndDepth  )
							{
								isSand=true;
								break;
							}
						}
						if(isSand)						
							strLine=strLine+"	"+strN+"\n";
						else 
							strLine=strLine+"	0"+"\n";
						
						wellNewFile.WriteString((LPTSTR)(LPCTSTR)strLine);
						wellFile.ReadString(strLine);
						ns++;
					}

					well_status[i].isFind=true;
					wellNewFile.Close();	
				}
				wellFile.Close();
			}//if(res)

			nPosition=nPosition+well_status[i].nLayers ;
			if(!well_status[i].isFind)
				strWellStatus=strWellStatus+well_status[i].strWellName +"\n";

			
		}//for(i=0;i<nW;i++)

		strDir=strFilePath+"temp\\"+"well_infomation.txt";

		wellNewFile.Open(strDir,CFile::modeWrite|CFile::typeText|CFile::modeCreate,&wne);
		wellNewFile.WriteString((LPTSTR)(LPCTSTR)strWellStatus);
		wellNewFile.Close();

		EndWaitCursor();
	}
}
