// prjWellLogDisperse.h : main header file for the PRJWELLLOGDISPERSE application
//

#if !defined(AFX_PRJWELLLOGDISPERSE_H__6342CFD0_169D_4A33_A683_D6A0C2264D6E__INCLUDED_)
#define AFX_PRJWELLLOGDISPERSE_H__6342CFD0_169D_4A33_A683_D6A0C2264D6E__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#ifndef __AFXWIN_H__
	#error include 'stdafx.h' before including this file for PCH
#endif

#include "resource.h"		// main symbols

/////////////////////////////////////////////////////////////////////////////
// CPrjWellLogDisperseApp:
// See prjWellLogDisperse.cpp for the implementation of this class
//

class CPrjWellLogDisperseApp : public CWinApp
{
public:
	CPrjWellLogDisperseApp();

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CPrjWellLogDisperseApp)
	public:
	virtual BOOL InitInstance();
	//}}AFX_VIRTUAL

// Implementation

	//{{AFX_MSG(CPrjWellLogDisperseApp)
		// NOTE - the ClassWizard will add and remove member functions here.
		//    DO NOT EDIT what you see in these blocks of generated code !
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};


/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_PRJWELLLOGDISPERSE_H__6342CFD0_169D_4A33_A683_D6A0C2264D6E__INCLUDED_)
