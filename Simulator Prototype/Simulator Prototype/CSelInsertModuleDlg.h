#pragma once
#include "afxdialogex.h"


// CSelOptions 대화 상자
#define SEL_OPTION1		_T("EFEM")
#define SEL_OPTION2		_T("LL")
#define SEL_OPTION3		_T("TM")
#define SEL_OPTION4		_T("PM")

class CSelInsertModuleDlg : public CDialogEx
{
	DECLARE_DYNAMIC(CSelInsertModuleDlg)

public:
	CSelInsertModuleDlg(CWnd* pParent = nullptr);   // 표준 생성자입니다.
	virtual ~CSelInsertModuleDlg();

	CWnd* m_pParent;
	CPoint m_ptPos;

// 대화 상자 데이터입니다.
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_SEL_OPTION };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 지원입니다.

	DECLARE_MESSAGE_MAP()
public:
	CListBox m_ctrlOption;
	virtual BOOL OnInitDialog();
	afx_msg void OnLbnSelchangeList1();	
};
