#include "pch.h"
#include "LoadLock.h"
#include <future>
#include <thread>

#pragma region 생성자/소멸자
LoadLock::LoadLock()
{
	m_strModuleName = "LoadLock";
	m_nWaferCount = 0;
	m_nWaferMax = 6;
	m_nPumpTime = 15;
	m_nPumpStableTime = 5;
	m_nVentTime = 15;
	m_nVentStableTime = 5;
	m_nSlotValveOpenTime = 2;
	m_nSlotValveCloseTime = 2;
	m_nDoorValveOpenTime = 2;
	m_nDoorValveCloseTime = 2;
	m_bIsInputWafer = true;

	m_hMutex = CreateMutex(NULL, FALSE, NULL);
}

LoadLock::~LoadLock()
{
}
#pragma endregion

#pragma region Get/Set 메서드
void LoadLock::SetPumpTime(int _value)
{
	m_nPumpTime = _value;
}

int LoadLock::GetPumpTime() const
{
	return m_nPumpTime;
}

void LoadLock::SetPumpStableTime(int _value)
{
	m_nPumpStableTime = _value;
}

int LoadLock::GetPumpStableTime() const
{
	return m_nPumpStableTime;
}

void LoadLock::SetVentTime(int _value)
{
	m_nVentTime = _value;
}

int LoadLock::GetVentTime() const
{
	return m_nVentTime;
}

void LoadLock::SetVentStableTime(int _value)
{
	m_nVentStableTime = _value;
}

int LoadLock::GetVentStableTime() const
{
	return m_nVentStableTime;
}

void LoadLock::SetSlotValveOpenTime(int _value)
{
	m_nSlotValveOpenTime = _value;
}

int LoadLock::GetSlotValveOpenTime() const
{
	return m_nSlotValveOpenTime;
}

void LoadLock::SetSlotValveCloseTime(int _value)
{
	m_nSlotValveCloseTime = _value;
}

int LoadLock::GetSlotValveCloseTime() const
{
	return m_nSlotValveCloseTime;
}

void LoadLock::SetDoorValveOpenTime(int _value)
{
	m_nDoorValveOpenTime = _value;
}

int LoadLock::GetDoorValveOpenTime() const
{
	return m_nDoorValveOpenTime;
}

void LoadLock::SetDoorValveCloseTime(int _value)
{
	m_nDoorValveCloseTime = _value;
}

int LoadLock::GetDoorValveCloseTime() const
{
	return m_nDoorValveCloseTime;
}
void LoadLock::SetIsInputWafer(bool _value) 
{
	m_bIsInputWafer = _value;
}
bool LoadLock::GetIsInputWafer() const
{
	return m_bIsInputWafer;
}
void LoadLock::work(ModuleBase* pM)
{

Start:
	while ((pM->GetIsWorking() == false && pM->GetWaferCount() > 0) == false)
	{
	}

	WaitForSingleObject(m_hMutex, INFINITE);

	if ((pM->GetIsWorking() == false && pM->GetWaferCount() > 0) == false)
		goto Start;

	pM->SetWaferCount(pM->GetWaferCount() - 1);
	SetWaferCount(GetWaferCount()+1);

	ReleaseMutex(m_hMutex);
	m_bIsWorking = true;

	m_bIsWorking = false;

	goto Start;
}

void LoadLock::Run(ModuleBase* pM)
{
	th = std::async(&LoadLock::work, this, pM);	// 쓰레드 생성?
}
#pragma endregion

#pragma region 메서드
double LoadLock::Pump()
{
	double result = m_nSlotValveCloseTime + m_nVentTime + m_nVentStableTime + m_nDoorValveOpenTime;			// LL을 진공 >> 대기 상태로 변환하는 시간 (DoorValve 여는 시간 = ATMRobot 회전 시간)
	return result;
}

double LoadLock::vent()
{
	double result = m_nDoorValveCloseTime + m_nPumpStableTime + m_nPumpTime + m_nSlotValveOpenTime;			// LL을 대기 >> 진공 상태로 변환하는 시간 (SlotValve 여는 시간 = VACRobot 회전 시간)
	return result;
}

double LoadLock::Run()
{
	//double result;
	if (m_bIsInputWafer)
	{
		double vent = m_nSlotValveCloseTime + m_nVentTime + m_nVentStableTime + m_nDoorValveOpenTime;		
																											// 이 중간에 ATM 로봇이 Wafer를 옮기는 작업 수행
		double pump = m_nDoorValveCloseTime + m_nPumpStableTime + m_nPumpTime + m_nSlotValveOpenTime;		
	}
	else
	{
		
	}
	return 0.0;
}
#pragma endregion