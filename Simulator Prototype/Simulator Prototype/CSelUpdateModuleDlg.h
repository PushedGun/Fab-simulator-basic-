#pragma once
#include "afxdialogex.h"


// CSelDoubleOptionsDlg 대화 상자

#define SEL_DOPTION1		_T("값 변경")
#define SEL_DOPTION2		_T("모듈 변경")
#define SEL_DOPTION3		_T("모듈 삭제")

class CSelUpdateModuleDlg : public CDialogEx
{
	DECLARE_DYNAMIC(CSelUpdateModuleDlg)

public:
	CSelUpdateModuleDlg(CWnd* pParent = nullptr);   // 표준 생성자입니다.
	virtual ~CSelUpdateModuleDlg();

	CWnd* m_pParent;
	CPoint m_ptPos;
	
	// 리스트 컨트롤 row, column 값을 알아야함..
	int m_nRowIdx;
	int m_nColIdx;

// 대화 상자 데이터입니다.
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_SEL_OPTION2 };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 지원입니다.

	DECLARE_MESSAGE_MAP()

	
public:
	CListBox m_ctrlOption;

	virtual BOOL OnInitDialog();
	afx_msg void OnLbnSelchangeList2();
};
