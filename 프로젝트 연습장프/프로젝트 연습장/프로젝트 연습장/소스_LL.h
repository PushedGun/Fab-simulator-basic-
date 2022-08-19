#pragma once

#include <vector>
#include <thread>
#include <iostream>
#include <future>
#include <atlstr.h>
#include "소스_ModuleBase.h"

using namespace std;

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


	//void work(ModuleBase* pM);
	//void Run(ModuleBase* pM);
#pragma endregion
};
