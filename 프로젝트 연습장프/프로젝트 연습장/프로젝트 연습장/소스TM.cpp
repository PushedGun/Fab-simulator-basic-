#include "소스TM.h"
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

VACRobot::VACRobot()
{
	m_strModuleName = "VAC. Robot";
	m_nWaferCount = 0;
	m_nWaferMax = 4;
	m_nPickTime = 5;
	m_nPlaceTime = 5;
	m_nRotateTime = 5;

	isWorking = false;

	hMutex = CreateMutex(NULL, FALSE, NULL);
}
VACRobot::~VACRobot()
{
	CloseHandle(hMutex);
}
#pragma endregion

void VACRobot::work(ModuleBase* pM)
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
		cout << "TM" << i << endl;

	isWorking = false;
	//!!!!!!!!!!!!!!!!//

	goto Start;
}

void VACRobot::Run(ModuleBase* pM)
{
	th = async(&VACRobot::work, this, pM);
}

void LoadLock::Run(ModuleBase* pM)
{
	th = async(&LoadLock::work, this, pM);
}
#pragma endregion

void LoadLock::work(ModuleBase* pM)
{
	///////////////////////////일하고 있는지 알림//////////////////////////////
	isWorking = true;

	for (int i = 0; i < 20; i++)
		cout << "VACRobot" << i << endl;

	isWorking = false;
	//////////////////////////////////////////////////////////////////////////
}



#pragma region Get/Set 메서드
void VACRobot::SetWaferMax(int _value)
{
	m_nWaferMax = _value;
}

int VACRobot::GetWaferMax()
{
	return m_nWaferMax;
}

void VACRobot::SetPickTime(int _value)
{
	m_nPickTime = _value;
}

int VACRobot::GetPickTime() const
{
	return m_nPickTime;
}

void VACRobot::SetPlaceTime(int _value)
{
	m_nPlaceTime = _value;
}

int VACRobot::GetPlaceTime() const
{
	return m_nPlaceTime;
}

void VACRobot::SetRotateTime(int _value)
{
	m_nRotateTime = _value;
}

int VACRobot::GetRotateTime() const
{
	return m_nRotateTime;
}
#pragma endregion

#pragma region 메서드
void VACRobot::Pick()
{
}
void VACRobot::Place()
{
}
void VACRobot::Rotate()
{
}

#pragma endregion

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
