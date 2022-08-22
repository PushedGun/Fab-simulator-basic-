// CSelOptionDlg.cpp: 구현 파일
//

#include "pch.h"
#include "Simulator Prototype.h"
#include "afxdialogex.h"
#include "CSelOptionDlg.h"


// CSelOptionDlg 대화 상자

IMPLEMENT_DYNAMIC(CNothing, CDialogEx)

CNothing::CNothing(CWnd* pParent /*=nullptr*/)
	: CDialogEx(IDD_SEL_OPTION, pParent)
{
	m_pParent = pParent;
}

CNothing::~CNothing()
{
}

void CNothing::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_COMBO1, m_ctrlOption);
}


BEGIN_MESSAGE_MAP(CNothing, CDialogEx)
	ON_CBN_SELCHANGE(IDC_COMBO1, &CNothing::OnCbnSelchangeCombo1)
END_MESSAGE_MAP()


// CSelOptionDlg 메시지 처리기


BOOL CNothing::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// TODO:  여기에 추가 초기화 작업을 추가합니다.
	SetWindowPos(m_pParent,
		m_ptPos.x, m_ptPos.y, 0, 0,
		SWP_NOSIZE | SWP_NOZORDER);

	m_ctrlOption.AddString(_T("LL"));
	m_ctrlOption.AddString(_T("MM"));
	m_ctrlOption.AddString(_T("AA"));
	m_ctrlOption.AddString(_T("BB"));

/*
	// 1. 이미지 리스트 생성
	CBitmap Bmp;
	Bmp.LoadBitmap(IDB_DEVICES1);
	
	static CImageList ImgList;
	ImgList.Create(16, 16, ILC_COLOR24, 4, 0);
	ImgList.Add(&Bmp, RGB(0, 0, 0));
	m_ctrlOption.SetImageList(&ImgList);
	

	// 2. 항목(Item) 추가
	CString strTmp = _T("");
	COMBOBOXEXITEM cbi;
	::ZeroMemory(&cbi, sizeof(cbi));
	
	cbi.mask = CBEIF_IMAGE | CBEIF_TEXT;
	for (int i = 0; i < 4; ++i)
	{
		strTmp.Format(_T("%dth Item"), i);

		cbi.iItem = i;
		cbi.iImage = i;
		//cbi.iSelectedImage = i;

		cbi.pszText = (LPWSTR)(LPCTSTR)strTmp;
		m_ctrlOption.InsertItem(&cbi);
	}
	
*/
	return TRUE;  // return TRUE unless you set the focus to a control
				  // 예외: OCX 속성 페이지는 FALSE를 반환해야 합니다.
}

void CNothing::OnCbnSelchangeCombo1()
{
	int nSel = m_ctrlOption.GetCurSel();
	EndDialog(nSel);
}
