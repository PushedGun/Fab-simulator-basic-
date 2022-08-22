// CSelOptions.cpp: 구현 파일
//

#include "pch.h"
#include "Simulator Prototype.h"
#include "afxdialogex.h"
#include "CSelInsertModuleDlg.h"
#include "Simulator PrototypeDlg.h"


// CSelOptions 대화 상자

IMPLEMENT_DYNAMIC(CSelInsertModuleDlg, CDialogEx)

CSelInsertModuleDlg::CSelInsertModuleDlg(CWnd* pParent /*=nullptr*/)
	: CDialogEx(IDD_SEL_OPTION, pParent)
{
	m_pParent = pParent;
}

CSelInsertModuleDlg::~CSelInsertModuleDlg()
{
}

void CSelInsertModuleDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_LIST1, m_ctrlOption);
}


BEGIN_MESSAGE_MAP(CSelInsertModuleDlg, CDialogEx)
	ON_LBN_SELCHANGE(IDC_LIST1, &CSelInsertModuleDlg::OnLbnSelchangeList1)
END_MESSAGE_MAP()


// CSelOptionDlg 메시지 처리기
BOOL CSelInsertModuleDlg::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// TODO:  여기에 추가 초기화 작업을 추가합니다.
	SetWindowPos(m_pParent, m_ptPos.x, m_ptPos.y, 0, 0, SWP_NOSIZE | SWP_NOZORDER);

	m_ctrlOption.AddString(SEL_OPTION1);
	m_ctrlOption.AddString(SEL_OPTION2);
	m_ctrlOption.AddString(SEL_OPTION3);
	m_ctrlOption.AddString(SEL_OPTION4);

	return TRUE;  // return TRUE unless you set the focus to a control
				  // 예외: OCX 속성 페이지는 FALSE를 반환해야 합니다.
}

void CSelInsertModuleDlg::OnLbnSelchangeList1()
{
	int nSel = m_ctrlOption.GetCurSel();

	EndDialog(nSel);
}