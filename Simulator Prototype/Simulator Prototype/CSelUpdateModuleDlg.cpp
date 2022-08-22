// CSelDoubleOptionsDlg.cpp: 구현 파일
//

#include "pch.h"
#include "Simulator Prototype.h"
#include "afxdialogex.h"
#include "CSelUpdateModuleDlg.h"
#include "Simulator PrototypeDlg.h"


// CSelDoubleOptionsDlg 대화 상자

IMPLEMENT_DYNAMIC(CSelUpdateModuleDlg, CDialogEx)

CSelUpdateModuleDlg::CSelUpdateModuleDlg(CWnd* pParent /*=nullptr*/)
	: CDialogEx(IDD_SEL_OPTION2, pParent)
{
	m_pParent = pParent;
}

CSelUpdateModuleDlg::~CSelUpdateModuleDlg()
{
}

void CSelUpdateModuleDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_LIST_UPDATE_MODULE, m_ctrlOption);
}


BEGIN_MESSAGE_MAP(CSelUpdateModuleDlg, CDialogEx)
	
	ON_LBN_SELCHANGE(IDC_LIST_UPDATE_MODULE, &CSelUpdateModuleDlg::OnLbnSelchangeList2)
END_MESSAGE_MAP()

BOOL CSelUpdateModuleDlg::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// TODO:  여기에 추가 초기화 작업을 추가합니다.
	SetWindowPos(m_pParent, m_ptPos.x, m_ptPos.y, 0, 0, SWP_NOSIZE | SWP_NOZORDER);

	m_ctrlOption.AddString(SEL_DOPTION1);
	m_ctrlOption.AddString(SEL_DOPTION2);
	m_ctrlOption.AddString(SEL_DOPTION3);
	

	return TRUE;  // return TRUE unless you set the focus to a control
				  // 예외: OCX 속성 페이지는 FALSE를 반환해야 합니다.
}

// CSelDoubleOptionsDlg 메시지 처리기

void CSelUpdateModuleDlg::OnLbnSelchangeList2()
{
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
	CSimulatorPrototypeDlg* pDlg = (CSimulatorPrototypeDlg*)(AfxGetApp()->GetMainWnd());
	int nSel = m_ctrlOption.GetCurSel();

	// 향후 모듈 추가 구현시 수정 ============================================================
	
	switch (nSel)
	{
	case 0:
		pDlg->m_ctrlListFabInfo.SetItemText(pDlg->m_nCurRow, pDlg->m_nCurCol, SEL_DOPTION1);
		DestroyWindow();
		break;

	case 1:
		pDlg->m_ctrlListFabInfo.SetItemText(pDlg->m_nCurRow, pDlg->m_nCurCol, SEL_DOPTION2);
		DestroyWindow();
		break;

	case 2:
		pDlg->m_ctrlListFabInfo.SetItemText(pDlg->m_nCurRow, pDlg->m_nCurCol, SEL_DOPTION3);
		DestroyWindow();
		break;
		
	default:
		DestroyWindow();
	}

	// ======================================================================================
}
