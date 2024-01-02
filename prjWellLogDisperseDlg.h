// prjWellLogDisperseDlg.h : header file
//

#if !defined(AFX_PRJWELLLOGDISPERSEDLG_H__EE4310D9_676F_464C_B777_3077F49EF1E3__INCLUDED_)
#define AFX_PRJWELLLOGDISPERSEDLG_H__EE4310D9_676F_464C_B777_3077F49EF1E3__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

/////////////////////////////////////////////////////////////////////////////
// CPrjWellLogDisperseDlg dialog
typedef struct Well_Status
{
	CString strWellName;					   //井名称
	BOOL isFind;                               //是否被处理
	int nLayers;                               //层数	
}WELL_STATUS;

typedef struct Layer_Status
{
	CString strLayerName;					   //层名称
	double nStartDepth;                        //起始深度
	double nEndDepth;                          //终止深度
}LAYER_STATUS;

class CPrjWellLogDisperseDlg : public CDialog
{
// Construction
public:
	CPrjWellLogDisperseDlg(CWnd* pParent = NULL);	// standard constructor

// Dialog Data
	//{{AFX_DATA(CPrjWellLogDisperseDlg)
	enum { IDD = IDD_PRJWELLLOGDISPERSE_DIALOG };
	CEdit	m_edit_dn;
	CEdit	m_edit_filepath;
	//}}AFX_DATA

	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CPrjWellLogDisperseDlg)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV support
	//}}AFX_VIRTUAL
public:
	BOOL GetParameter();
	CString strWellNames,strFilePath,strLayerFilePathName,strN;
	
// Implementation
protected:
	HICON m_hIcon;

	// Generated message map functions
	//{{AFX_MSG(CPrjWellLogDisperseDlg)
	virtual BOOL OnInitDialog();
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	afx_msg void OnButtonOpenfile();
	afx_msg void OnButtonOk();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_PRJWELLLOGDISPERSEDLG_H__EE4310D9_676F_464C_B777_3077F49EF1E3__INCLUDED_)
