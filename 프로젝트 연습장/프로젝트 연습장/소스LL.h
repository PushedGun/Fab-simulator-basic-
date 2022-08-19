#include <vector>
#include <thread>
#include <iostream>
#include <future>
#include <atlstr.h>
using namespace std;


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

	bool isWorking;

	///쓰레드///
	future<void> th;
#pragma endregion

#pragma region Get/Set 메서드
public:
	virtual void SetModuleName(CString _value);
	virtual CString GetModuleName() const;
	void SetWaferCount(int _value);
	int GetWaferCount() const;
	virtual void SetWaferMax(int _value);
	virtual int GetWaferMax() const;

	bool GetIsWorking();
#pragma endregion

public:
	virtual void Run(ModuleBase* pM) = 0;					// 동작 메서드, 쓰레드 콜백함수 예상
	//virtual void Serialize(CArchive& ar);		// FileIO를 위한 Serialize 재정의 (추후 기능 구현 시 INI 파일 저장으로 변경 예상?)
};

class LoadLock : public ModuleBase
{
#pragma region 필드
private:
	int m_nPumpTime;				// 대기 >> 진공 상태 전환 시간
	int m_nPumpStableTime;			// 진공 상태 전환 전/후 소요 시간
	int m_nVentTime;				// 진공 >> 대기 상태 전환 시간
	int m_nVentStableTime;			// 대기 상태 전환 전/후 소요 시간
	int m_nSlotValveOpenTime;		// TM 연결 VALVE 여는 시간
	int m_nSlotValveCloseTime;		// TM 연결 VALVE 닫는 시간
	int m_nDoorValveOpenTime;		// EFEM 연결 VALVE 여는 시간
	int m_nDoorValveCloseTime;		// EFEM 연결 VALVE 닫는 시간
	bool m_bIsInputWafer;			// TRUE : FOUP >> PM	FALSE : PM >> FOUP

	HANDLE hMutex;
#pragma endregion

#pragma region 생성자/소멸자
public:
	LoadLock();
	~LoadLock();
#pragma endregion

#pragma region Get/Set 메서드
public:
	void SetPumpTime(int _value);
	int GetPumpTime() const;
	void SetPumpStableTime(int _value);
	int GetPumpStableTime() const;
	void SetVentTime(int _value);
	int GetVentTime() const;
	void SetVentStableTime(int _value);
	int GetVentStableTime() const;
	void SetSlotValveOpenTime(int _value);
	int GetSlotValveOpenTime() const;
	void SetSlotValveCloseTime(int _value);
	int GetSlotValveCloseTime() const;
	void SetDoorValveOpenTime(int _value);
	int GetDoorValveOpenTime() const;
	void SetDoorValveCloseTime(int _value);
	int GetDoorValveCloseTime() const;
	void SetIsInputWafer(bool _value);
	bool GetIsInputWafer() const;
#pragma endregion

#pragma region 메서드
public:
	void Pump();
	void vent();
	//virtual double Run();


	void work(ModuleBase* pM);
	void Run(ModuleBase* pM);
#pragma endregion
};


class ATMRobot : public ModuleBase
{
#pragma region 필드
private:
	int m_nPickTime;					// RobotArm으로 Wafer를 가져오는 시간
	int m_nPlaceTime;					// RobotArm의 Wafer를 대상 Module로 놓는 시간
	int m_nRotateTime;					// Robot의 회전시간
	double m_dRotateZCoordinateTime;	// Robot의 Z축 회전 시간
	bool m_bIsInputWafer;				// TRUE : FOUP >> PM	FALSE : PM >> FOUP

	

#pragma endregion

#pragma region 생성자/소멸자
public:
	ATMRobot();
	~ATMRobot();
#pragma endregion

#pragma region Get/Set 메서드
public:
	void SetPickTime(int _value);
	int GetPickTime() const;
	void SetPlaceTime(int _value);
	int GetPlaceTime() const;
	void SetRotateTime(int _value);
	int GetRotateTime() const;
	void SetRotateZTime(int _value);
	double GetRotateZTime() const;
	void SetIsInputWafer(bool _value);
	bool GetIsInputWafer() const;
#pragma endregion

#pragma region 메서드
public:
	void Pick();
	void Place();
	void Rotate();
	//virtual double Run();

	void work(ModuleBase* pM);
	void Run(ModuleBase* pM);
#pragma endregion
};