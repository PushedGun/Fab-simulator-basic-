#include "pch.h"
#include <future>
#include <thread>

#pragma once
// 모든 모듈 클래스의 부모 클래스 (추상클래스)
// 자식클래스 오버라이딩 강제

class ModuleBase
{
#pragma region 필드
protected:								// 자식 클래스들의 Get/Set 메서드를 통한 Wafer Max 수치 제한이 다를 수 있음을 생각, 접근이 허용되어야 함.. 그래서 protected
	CString m_strModuleName;			// 현재 모듈의 이름(기계명)
	int m_nWaferCount;					// 현재 ATMRobot이 가지는 Wafer 개수
	int m_nWaferMax;					// 현재 모듈이 가질 수 있는 Wafer Max 수치
	CPoint m_ptPos;						// 모듈 설정 위치
	bool m_bIsWorking;					// 현재 모듈이 동작중임을 나타내는 필드

	HANDLE m_hMutex;
	///쓰레드///
	std::future<void> th;
#pragma endregion

#pragma region Get/Set 메서드
public:
	void SetModuleName(CString _value);
	CString GetModuleName() const;
	void SetWaferCount(int _value);
	int GetWaferCount() const;
	void SetWaferMax(int _value);
	int GetWaferMax() const;
	void SetPos(int _X, int _Y);
	void SetPos(CPoint _value);
	CPoint GetPos() const;
	//void SetIsWorking(bool _value);
	bool GetIsWorking() const;

#pragma endregion

public:
	virtual void Run(ModuleBase* pM) = 0;					// 동작 메서드, 쓰레드 콜백함수 예상
	//virtual void Serialize(CArchive& ar);		// FileIO를 위한 Serialize 재정의 (추후 기능 구현 시 INI 파일 저장으로 변경 예상?)
};