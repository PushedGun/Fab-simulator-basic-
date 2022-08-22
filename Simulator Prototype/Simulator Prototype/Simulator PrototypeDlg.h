
// Simulator PrototypeDlg.h: 헤더 파일
//

#pragma once


// CSimulatorPrototypeDlg 대화 상자
class CSimulatorPrototypeDlg : public CDialogEx
{
// 생성입니다.
public:
	CSimulatorPrototypeDlg(CWnd* pParent = nullptr);	// 표준 생성자입니다.
	
	int m_nCurRow;
	int m_nCurCol;

// 대화 상자 데이터입니다.
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_SIMULATOR_PROTOTYPE_DIALOG };
#endif

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV 지원입니다.


// 구현입니다.
protected:
	HICON m_hIcon;

	// 생성된 메시지 맵 함수
	virtual BOOL OnInitDialog();
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	DECLARE_MESSAGE_MAP()
public:
	CListCtrl m_ctrlListFabInfo;
	CString m_strModuleName;
	int m_nModuleOptionIdx;
	afx_msg void OnNMCustomdrawListFabInfo(NMHDR* pNMHDR, LRESULT* pResult);
	afx_msg void OnNMClickListFabInfo(NMHDR* pNMHDR, LRESULT* pResult);
	afx_msg void OnBnClickedButtonLinecontrolRun();
	afx_msg void OnNMRClickListFabInfo(NMHDR* pNMHDR, LRESULT* pResult);
	
};
