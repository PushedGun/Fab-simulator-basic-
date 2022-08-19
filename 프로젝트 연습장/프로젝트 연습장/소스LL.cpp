#include "소스LL.h"
#include <vector>
#include <thread>
#include <iostream>
#include <future>
#include <atlstr.h>
#include <string>


using namespace std;



void ModuleBase::SetModuleName(CString _value)
{
	m_strModuleName = _value;
}

CString ModuleBase::GetModuleName() const
{
	return m_strModuleName;
}

void ModuleBase::SetWaferCount(int _value)
{
	if (m_nWaferCount >= m_nWaferMax)			// WaferMax 수치 제한
	{
		return;
	}
	m_nWaferCount = _value;
}

int ModuleBase::GetWaferCount() const
{
	return m_nWaferCount;
}

void ModuleBase::SetWaferMax(int _value)
{
	m_nWaferMax = _value;
}

int ModuleBase::GetWaferMax() const
{
	return m_nWaferMax;
}

bool ModuleBase::GetIsWorking()
{
	return isWorking;
}

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

	isWorking = false;

	hMutex = CreateMutex(NULL, FALSE, NULL);
}

LoadLock::~LoadLock()
{
	CloseHandle(hMutex);
}
#pragma endregion

void ATMRobot::work(ModuleBase* pM)
{
	///////////////////////////일하고 있는지 알림//////////////////////////////
	isWorking = true;

	for (int i = 0; i < 20; i++)
		cout << "ATMRobot" << i << endl;

	isWorking = false;
	//////////////////////////////////////////////////////////////////////////
}

void ATMRobot::Run(ModuleBase* pM)
{
	th = async(&ATMRobot::work, this, pM);
}

void LoadLock::work(ModuleBase* pM)
{

Start:
	while ((pM->GetIsWorking() == false && pM->GetWaferCount() > 0) == false)
	{
	}

	//////////////////////////////////<<뮤텍스로 접근제어>>/////////////////////////////////////
	WaitForSingleObject(hMutex, INFINITE);

	if ((pM->GetIsWorking() == false && pM->GetWaferCount() > 0) == false)
		goto Start;

	pM->SetWaferCount(pM->GetWaferCount() - 1);
	cout << "받은 wafer : " << 1 << endl;

	ReleaseMutex(hMutex);
	//////////////////////////////////////////////////////////////////////////////////

	//!!!!!!!!!!!!!!!!//
	isWorking = true;

	for (int i = 0; i < 50; i++)
		cout << "LL" << i << endl;

	isWorking = false;
	//!!!!!!!!!!!!!!!!//

	goto Start;
}

void LoadLock::Run(ModuleBase* pM)
{
	th = async(&LoadLock::work, this, pM);
}

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
#pragma endregion

#pragma region 메서드
void LoadLock::Pump()
{
	//double result = m_nSlotValveCloseTime + m_nVentTime + m_nVentStableTime + m_nDoorValveOpenTime;			// LL을 진공 >> 대기 상태로 변환하는 시간 (DoorValve 여는 시간 = ATMRobot 회전 시간)
	//return result;
}

void LoadLock::vent()
{
	//double result = m_nDoorValveCloseTime + m_nPumpStableTime + m_nPumpTime + m_nSlotValveOpenTime;			// LL을 대기 >> 진공 상태로 변환하는 시간 (SlotValve 여는 시간 = VACRobot 회전 시간)
	//return result;
}

/*double LoadLock::Run()
{
	double result;
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
}*/
#pragma endregion

#pragma region 생성자/소멸자
ATMRobot::ATMRobot()
{
	m_strModuleName = "EFEM";
	m_nWaferCount = 0;
	m_nWaferMax = 2;
	m_nPickTime = 4;
	m_nPlaceTime = 4;
	m_nRotateTime = 1;
	m_dRotateZCoordinateTime = 0.5;
	m_bIsInputWafer = true;
}

ATMRobot::~ATMRobot()
{
}
#pragma endregion

#pragma region Get/Set 메서드
void ATMRobot::SetPickTime(int _value)
{
	m_nPickTime = _value;
}
int ATMRobot::GetPickTime() const
{
	return m_nPickTime;
}
void ATMRobot::SetPlaceTime(int _value)
{
	m_nPlaceTime = _value;
}
int ATMRobot::GetPlaceTime() const
{
	return m_nPlaceTime;
}
void ATMRobot::SetRotateTime(int _value)
{
	m_nRotateTime = _value;
}
int ATMRobot::GetRotateTime() const
{
	return m_nRotateTime;
}
void ATMRobot::SetRotateZTime(int _value)
{
	m_dRotateZCoordinateTime = _value;
}
double ATMRobot::GetRotateZTime() const
{
	return m_dRotateZCoordinateTime;
}
void ATMRobot::SetIsInputWafer(bool _value)
{
	m_bIsInputWafer = _value;
}
bool ATMRobot::GetIsInputWafer() const
{
	return m_bIsInputWafer;
}
#pragma endregion

#pragma region 메서드
void ATMRobot::Pick()
{
}

void ATMRobot::Place()
{
}

void ATMRobot::Rotate()
{
}
/*double ATMRobot::Run()
{
	double result;
	if (m_bIsInputWafer)
	{
		result = m_nPickTime + m_nPlaceTime + m_nRotateTime + m_dRotateZCoordinateTime;
	}
	else
	{
		result = m_dRotateZCoordinateTime + m_nRotateTime + m_nPlaceTime + m_nPickTime;
	}
	return result;
}*/
#pragma endregion