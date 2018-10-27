// Z_BufferEli.h : main header file for the Z_BUFFERELI application
//

#if !defined(AFX_Z_BUFFERELI_H__4371E3E3_48C8_4455_8FC2_00EA3709034D__INCLUDED_)
#define AFX_Z_BUFFERELI_H__4371E3E3_48C8_4455_8FC2_00EA3709034D__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#ifndef __AFXWIN_H__
	#error include 'stdafx.h' before including this file for PCH
#endif

#include "resource.h"       // main symbols

/////////////////////////////////////////////////////////////////////////////
// CZ_BufferEliApp:
// See Z_BufferEli.cpp for the implementation of this class
//

class CZ_BufferEliApp : public CWinApp
{
public:
	CZ_BufferEliApp();

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CZ_BufferEliApp)
	public:
	virtual BOOL InitInstance();
	//}}AFX_VIRTUAL

// Implementation
	//{{AFX_MSG(CZ_BufferEliApp)
	afx_msg void OnAppAbout();
		// NOTE - the ClassWizard will add and remove member functions here.
		//    DO NOT EDIT what you see in these blocks of generated code !
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};


/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_Z_BUFFERELI_H__4371E3E3_48C8_4455_8FC2_00EA3709034D__INCLUDED_)
