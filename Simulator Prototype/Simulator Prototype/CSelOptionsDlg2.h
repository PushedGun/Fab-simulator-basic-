#pragma once
#include "afxdialogex.h"


// OnLbnSelchangeList2 대화 상자

class OnLbnSelchangeList2 : public CDialogEx
{
	DECLARE_DYNAMIC(OnLbnSelchangeList2)

public:
	OnLbnSelchangeList2(CWnd* pParent = nullptr);   // 표준 생성자입니다.
	virtual ~OnLbnSelchangeList2();

// 대화 상자 데이터입니다.
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_SEL_OPTION2 };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 지원입니다.

	DECLARE_MESSAGE_MAP()
};
