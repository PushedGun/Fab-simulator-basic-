// Simulator PrototypeDlg.cpp: 구현 파일

#include "pch.h"
#include "framework.h"
#include "Simulator Prototype.h"
#include "Simulator PrototypeDlg.h"
#include "afxdialogex.h"
#include "CSelInsertModuleDlg.h"
#include "CSelUpdateModuleDlg.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif

// ***************************************** 내가 추가한 헤더파일 *****************************************
#include "EFEM.h"
#include "LoadLock.h"
#include "VACRobot.h"
#include "ProcessChamber.h"

#pragma region AboutDlg 코드
// 응용 프로그램 정보에 사용되는 CAboutDlg 대화 상자입니다.

class CAboutDlg : public CDialogEx
{
public:
	CAboutDlg();

// 대화 상자 데이터입니다.
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_ABOUTBOX };
#endif

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 지원입니다.

// 구현입니다.
protected:
	DECLARE_MESSAGE_MAP()
};

CAboutDlg::CAboutDlg() : CDialogEx(IDD_ABOUTBOX)
{
}

void CAboutDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}

BEGIN_MESSAGE_MAP(CAboutDlg, CDialogEx)
END_MESSAGE_MAP()

#pragma endregion


// CSimulatorPrototypeDlg 대화 상자

CSimulatorPrototypeDlg::CSimulatorPrototypeDlg(CWnd* pParent /*=nullptr*/)
	: CDialogEx(IDD_SIMULATOR_PROTOTYPE_DIALOG, pParent)
	, m_strModuleName(_T(""))
{
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);

	m_nCurRow = -1;
	m_nCurCol = -1;
}

void CSimulatorPrototypeDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_LIST_FAB_INFO, m_ctrlListFabInfo);
	DDX_Text(pDX, IDC_STATIC_UNIT_OBJECTNAME, m_strModuleName);
}

BEGIN_MESSAGE_MAP(CSimulatorPrototypeDlg, CDialogEx)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_NOTIFY(NM_CLICK, IDC_LIST_FAB_INFO, &CSimulatorPrototypeDlg::OnNMClickListFabInfo)
	ON_NOTIFY(NM_CUSTOMDRAW, IDC_LIST_FAB_INFO, &CSimulatorPrototypeDlg::OnNMCustomdrawListFabInfo)
	ON_BN_CLICKED(IDC_BUTTON_LINECONTROL_RUN, &CSimulatorPrototypeDlg::OnBnClickedButtonLinecontrolRun)
	ON_NOTIFY(NM_RCLICK, IDC_LIST_FAB_INFO, &CSimulatorPrototypeDlg::OnNMRClickListFabInfo)
END_MESSAGE_MAP()


// CSimulatorPrototypeDlg 메시지 처리기
LoadLock ll1;
EFEM efem1;

BOOL CSimulatorPrototypeDlg::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// 시스템 메뉴에 "정보..." 메뉴 항목을 추가합니다.

	// IDM_ABOUTBOX는 시스템 명령 범위에 있어야 합니다.
	ASSERT((IDM_ABOUTBOX & 0xFFF0) == IDM_ABOUTBOX);
	ASSERT(IDM_ABOUTBOX < 0xF000);

	CMenu* pSysMenu = GetSystemMenu(FALSE);
	if (pSysMenu != nullptr)
	{
		BOOL bNameValid;
		CString strAboutMenu;
		bNameValid = strAboutMenu.LoadString(IDS_ABOUTBOX);
		ASSERT(bNameValid);
		if (!strAboutMenu.IsEmpty())
		{
			pSysMenu->AppendMenu(MF_SEPARATOR);
			pSysMenu->AppendMenu(MF_STRING, IDM_ABOUTBOX, strAboutMenu);
		}
	}

	// 이 대화 상자의 아이콘을 설정합니다.  응용 프로그램의 주 창이 대화 상자가 아닐 경우에는
	//  프레임워크가 이 작업을 자동으로 수행합니다.
	SetIcon(m_hIcon, TRUE);			// 큰 아이콘을 설정합니다.
	SetIcon(m_hIcon, FALSE);		// 작은 아이콘을 설정합니다.

	// TODO: 여기에 추가 초기화 작업을 추가합니다.
	m_ctrlListFabInfo.ModifyStyle(LVS_OWNERDRAWFIXED, 0, 0);
	m_ctrlListFabInfo.SetExtendedStyle(LVS_EX_GRIDLINES);
	
	int nMaxCell = 20;

	// 리스트컨트롤 Item 행 높이 조절
	CImageList cImagelist;
	cImagelist.Create(1, 60, ILC_COLORDDB, 1, 0);
	m_ctrlListFabInfo.SetImageList(&cImagelist, LVSIL_SMALL);
	
	CString strColumn;
	// 컬럼
	for (int i = 1; i <= nMaxCell; i++)
	//for (int i = 0; i < nMaxCell; i++)
	{
		strColumn.Format(_T("%d"), i);
		m_ctrlListFabInfo.InsertColumn(i, strColumn, LVCFMT_CENTER, 60, 0);
	}

	// 로우
	for (int i = 0; i < nMaxCell; i++)
	{
		strColumn.Format(_T("%d"), i);
		m_ctrlListFabInfo.InsertItem(i, strColumn, 0);
	}

	// ================= 리스트 컨트롤 기본 설정 코드 (추후 수정 코드) =====================================
	m_ctrlListFabInfo.SetItemText(4, 2, _T("Input : "));
	m_ctrlListFabInfo.SetExtendedStyle(m_ctrlListFabInfo.GetExtendedStyle() 
		| LVS_EX_SIMPLESELECT | LVS_EX_FULLROWSELECT);

	// EFEM efem1;
	efem1.SetPos(4, 4);
	m_ctrlListFabInfo.SetItemText(efem1.GetPos().y, efem1.GetPos().x, efem1.GetModuleName());
	
	//LoadLock ll1;
	ll1.SetModuleName(_T("LL"));
	ll1.SetPos(6, 4);
	m_ctrlListFabInfo.SetItemText(ll1.GetPos().y, ll1.GetPos().x, ll1.GetModuleName());

	//ll1.Run(&efem1);

	//VACRobot tm1;
	//tm1.SetModuleName(_T("TM"));
	//tm1.SetPos(8, 4);
	//m_ctrlListFabInfo.SetItemText(tm1.GetPos().y, tm1.GetPos().x, tm1.GetModuleName());

	//ProcessChamber pm1;
	//pm1.SetModuleName(_T("PM"));
	//pm1.SetPos(10, 4);
	//m_ctrlListFabInfo.SetItemText(pm1.GetPos().y, pm1.GetPos().x, pm1.GetModuleName());

	m_ctrlListFabInfo.SetItemText(4, 12, _T("Output : "));
	// ===================================================================================

	return TRUE;  // 포커스를 컨트롤에 설정하지 않으면 TRUE를 반환합니다.
}

void CSimulatorPrototypeDlg::OnSysCommand(UINT nID, LPARAM lParam)
{
	if ((nID & 0xFFF0) == IDM_ABOUTBOX)
	{
		CAboutDlg dlgAbout;
		dlgAbout.DoModal();
	}
	else
	{
		CDialogEx::OnSysCommand(nID, lParam);
	}
}

// 대화 상자에 최소화 단추를 추가할 경우 아이콘을 그리려면
//  아래 코드가 필요합니다.  문서/뷰 모델을 사용하는 MFC 애플리케이션의 경우에는
//  프레임워크에서 이 작업을 자동으로 수행합니다.

void CSimulatorPrototypeDlg::OnPaint()
{
	if (IsIconic())
	{
		CPaintDC dc(this); // 그리기를 위한 디바이스 컨텍스트입니다.

		SendMessage(WM_ICONERASEBKGND, reinterpret_cast<WPARAM>(dc.GetSafeHdc()), 0);

		// 클라이언트 사각형에서 아이콘을 가운데에 맞춥니다.
		int cxIcon = GetSystemMetrics(SM_CXICON);
		int cyIcon = GetSystemMetrics(SM_CYICON);
		CRect rect;
		GetClientRect(&rect);
		int x = (rect.Width() - cxIcon + 1) / 2;
		int y = (rect.Height() - cyIcon + 1) / 2;

		// 아이콘을 그립니다.
		dc.DrawIcon(x, y, m_hIcon);
	}
	else
	{
		CDialogEx::OnPaint();
	}
}

// 사용자가 최소화된 창을 끄는 동안에 커서가 표시되도록 시스템에서 이 함수를 호출합니다.
HCURSOR CSimulatorPrototypeDlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}


#pragma region 리스트 컨트롤

// 리스트컨트롤 CustomDraw
void CSimulatorPrototypeDlg::OnNMCustomdrawListFabInfo(NMHDR* pNMHDR, LRESULT* pResult)
{
	m_ctrlListFabInfo.SetItemState(-1, 0, LVIS_SELECTED);
	LPNMCUSTOMDRAW pNMCD = reinterpret_cast<LPNMCUSTOMDRAW>(pNMHDR);
	// TODO : 여기에 컨트롤 알림 처리기 코드를 추가합니다.
	NMLVCUSTOMDRAW* pDraw = (NMLVCUSTOMDRAW*)(pNMHDR);
	
	if (pNMCD->dwDrawStage == CDDS_PREPAINT)
	{
		
		*pResult = (LRESULT)CDRF_NOTIFYITEMDRAW;
		return; // 여기서 함수를 빠져 나가야 *pResult 값이 유지된다.
	}
	
	if (pNMCD->dwDrawStage == CDDS_ITEMPREPAINT)
	{
		
		// 한 줄 (row) 가 그려질 때. 여기서만 설정하면 한 줄이 모두 동일하게 설정이 된다.
		if (m_ctrlListFabInfo.GetItemData(pNMCD->dwItemSpec) == 0)
		{
			// dwItemSpec 이 현재 그려지는 row index
			pDraw->clrText = 0xffffff;
			pDraw->clrTextBk = 0x0;
			// *pResult = (LRESULT)CDRF_NEWFONT;//여기서 나가면 sub-item 이 변경되지 않는다.
			*pResult = (LRESULT)CDRF_NOTIFYSUBITEMDRAW;	//sub-item 을 변경하기 위해서. 

			return;	// 여기서 중단해야 *pResult 값이 유지된다.
		}
		else
		{ // When all matrices are already made.

			pDraw->clrText = 0x0;
			pDraw->clrTextBk = RGB(255, 0, 196);
			*pResult = (LRESULT)CDRF_NEWFONT;
			return;
		}
	}

	else if (pNMCD->dwDrawStage == (CDDS_SUBITEM | CDDS_ITEMPREPAINT))
	{

		// sub-item 이 그려지는 순간. 위에서 *pResult 에 CDRF_NOTIFYSUBITEMDRAW 를 해서 여기로 올 수 있었던 것이다.
		CString text = m_ctrlListFabInfo.GetItemText(pNMCD->dwItemSpec, pDraw->iSubItem);

		if (!text.IsEmpty() && pDraw->iSubItem != 0)
		{

			NMLVDISPINFO* pDispInfo = reinterpret_cast<NMLVDISPINFO*>(pNMHDR);

			pDraw->clrText = RGB(255, 255, 255);
			pDraw->clrTextBk = RGB(200, 0, 0);

			//// 아이템 배경색 Black으로 만드는 코드
			//if (pDraw->iSubItem == 0)//1st 컬럼일 경우, 
			//{				
			//	pDraw->clrText = 0xffffff; //RGB(255, 255, 255);
			//	pDraw->clrTextBk = 0x0; //RGB(0, 0, 0);
			//}			
			//else
			//{
			//	pDraw->clrText = RGB(255, 255, 255);
			//	pDraw->clrTextBk = RGB(200, 0, 0);
			//}
			
		}

		else if (m_nCurRow == pNMCD->dwItemSpec && m_nCurCol == pDraw->iSubItem && pDraw->iSubItem != 0)
		{

			pDraw->clrText = RGB(255, 255, 255);
			pDraw->clrTextBk = RGB(0, 0, 255);
			
		}

		//if (pNMCD->uItemState == CDIS_SELECTED)
		//{
		//	// Your color definitions here:
		//	pDraw->clrText = RGB(255, 255, 255);
		//	pDraw->clrTextBk = RGB(0, 0, 0);
		//}

		else
		{

			pDraw->clrText = 0x0;
			pDraw->clrTextBk = 0xffffff;

		}



		*pResult = (LRESULT)CDRF_NEWFONT; // 이렇게 해야 설정한 대로 그려진다.
		
		return;
	}
	
	*pResult = 0;
	//m_ctrlListFabInfo.getcurrent
}

// 리스트컨트롤 마우스 LBUTTON 클릭
void CSimulatorPrototypeDlg::OnNMClickListFabInfo(NMHDR* pNMHDR, LRESULT* pResult)
{
	m_ctrlListFabInfo.SetItemState(-1, 0, LVIS_SELECTED | LVIS_FOCUSED);
	LPNMITEMACTIVATE pNMItemActivate = reinterpret_cast<LPNMITEMACTIVATE>(pNMHDR);				//NM_LISTVIEW* pNMView = (NM_LISTVIEW*)pNMHDR;

	m_nCurRow = pNMItemActivate->iItem;
	m_nCurCol = pNMItemActivate->iSubItem;

	if (m_nCurCol == 0)return;//1st 컬럼은 대화상자 처리 하지 않음


	// 조건문... 
	if (m_ctrlListFabInfo.GetItemText(m_nCurRow, m_nCurCol).IsEmpty())							// 셀 비어있는지 판단해서 셀에 데이터가 있을 때만 (모듈이 들어가 있을때만) 코드 수행
		return;
	 

	// 모듈이 리스트컨트롤의 셀에 들어가 있는 상태임..
	// 모듈에 대한 정보를 GUI 화면 아래의 statictext(textcontrol)에 각기 출력해야하는게 1차목표인데
	// 현재는 모듈에 대한 정보를 listctrl이 가지고 있지 않은 상태이다..
	// 모듈과 합치는 작업 수행 후에 더 늘려나가야 함..
	
	// 1차목표 = 모듈명 출력.
	m_strModuleName = m_ctrlListFabInfo.GetItemText(m_nCurRow, m_nCurCol);

	UpdateData(0);

	//switch (nSelOption)
	//{
	//case 0: m_ctrlListFabInfo.SetItemText(m_nCurRow, m_nCurCol, SEL_OPTION1); break;
	//case 1: m_ctrlListFabInfo.SetItemText(m_nCurRow, m_nCurCol, SEL_OPTION2); break;
	//case 2: m_ctrlListFabInfo.SetItemText(m_nCurRow, m_nCurCol, SEL_OPTION3); break;
	//case 3: m_ctrlListFabInfo.SetItemText(m_nCurRow, m_nCurCol, SEL_OPTION4); break;
	//}

	//init
	//m_nCurRow = -1;
	//m_nCurCol = -1;
	
	// 먼저 현재 선택상태를 해제합니다



	*pResult = 0;
	
	
}

// 리스트컨트롤 마우스 RBUTTON 클릭
void CSimulatorPrototypeDlg::OnNMRClickListFabInfo(NMHDR* pNMHDR, LRESULT* pResult)
{
	LPNMITEMACTIVATE pNMItemActivate = reinterpret_cast<LPNMITEMACTIVATE>(pNMHDR);
	
	// 리스트컨트롤 클릭된 서브아이템 Row, Col idx가져오기
	m_nCurRow = pNMItemActivate->iItem;
	m_nCurCol = pNMItemActivate->iSubItem;

	if (m_nCurCol == 0) //1st 컬럼은 대화상자 처리 하지 않음
		return;

	// if문 필요 (리스트컨트롤 cell의 텍스트가 있는지 비교 후 각기 다른 다이얼로그 생성 & 호출) ====================================

	if(m_ctrlListFabInfo.GetItemText(m_nCurRow, m_nCurCol).IsEmpty()) // ListCtrl 셀 비어있을 시 CSinsertMouduleDlg 인스턴스 생성 및 모달리스 호출 << 현재 모달로 호출, 수정 필요
	{
		CSelInsertModuleDlg dlg(this);
		::GetCursorPos(&dlg.m_ptPos);

		// ==============================================================================
		int nSelOption = (int)dlg.DoModal();

		switch (nSelOption)
		{
		case 0: m_ctrlListFabInfo.SetItemText(m_nCurRow, m_nCurCol, SEL_OPTION1); break;
		case 1: m_ctrlListFabInfo.SetItemText(m_nCurRow, m_nCurCol, SEL_OPTION2); break;
		case 2: m_ctrlListFabInfo.SetItemText(m_nCurRow, m_nCurCol, SEL_OPTION3); break;
		case 3: m_ctrlListFabInfo.SetItemText(m_nCurRow, m_nCurCol, SEL_OPTION4); break;
		}
		// ==============================================================================
	}
	else // ListCtrl 셀 모듈이 있을 시 CSUpdateMouduleDlg 인스턴스 생성 및 모달리스 호출
	{
		CSelUpdateModuleDlg* pDlg = new CSelUpdateModuleDlg;
		::GetCursorPos(&pDlg->m_ptPos);
		pDlg->Create(IDD_SEL_OPTION2, this);
		pDlg->ShowWindow(SW_SHOW);
	}

	// 컬럼, 로우 인덱스 초기화 코드
	m_nCurRow = -1;
	m_nCurCol = -1;
	
	// 먼저 현재 선택상태를 해제합니다
	m_ctrlListFabInfo.SetItemState(-1, 0, LVIS_SELECTED | LVIS_FOCUSED);

	*pResult = 0;
}

#pragma endregion



// Run 버튼
void CSimulatorPrototypeDlg::OnBnClickedButtonLinecontrolRun()
{

	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
	//ll1.Run(&efem1);
}
