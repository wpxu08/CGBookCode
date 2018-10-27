// ArtistEli.h : main header file for the ARTISTELI application
//

#if !defined(AFX_ARTISTELI_H__EDA67556_7BA3_4E3E_A6D8_517CE6DEDCDA__INCLUDED_)
#define AFX_ARTISTELI_H__EDA67556_7BA3_4E3E_A6D8_517CE6DEDCDA__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#ifndef __AFXWIN_H__
	#error include 'stdafx.h' before including this file for PCH
#endif

#include "resource.h"       // main symbols

/////////////////////////////////////////////////////////////////////////////
// CArtistEliApp:
// See ArtistEli.cpp for the implementation of this class
//

class CArtistEliApp : public CWinApp
{
public:
	CArtistEliApp();

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CArtistEliApp)
	public:
	virtual BOOL InitInstance();
	//}}AFX_VIRTUAL

// Implementation
	//{{AFX_MSG(CArtistEliApp)
	afx_msg void OnAppAbout();
		// NOTE - the ClassWizard will add and remove member functions here.
		//    DO NOT EDIT what you see in these blocks of generated code !
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};


/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_ARTISTELI_H__EDA67556_7BA3_4E3E_A6D8_517CE6DEDCDA__INCLUDED_)
