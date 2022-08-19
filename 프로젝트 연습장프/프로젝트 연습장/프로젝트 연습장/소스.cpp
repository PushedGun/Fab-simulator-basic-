#include "소스.h"
#include <vector>
#include <thread>
#include <iostream>
#include <future>
#include <atlstr.h>
#include <string>

using namespace std;

void Module::SetModuleName(CString _value)
{
	m_strModuleName = _value;
}

CString Module::GetModuleName() const
{
	return m_strModuleName;
}

void Module::SetWaferCount(int _value)
{
	if (m_nWaferCount >= m_nWaferMax)			// WaferMax 수치 제한
	{
		return;
	}
	m_nWaferCount = _value;
}

int Module::GetWaferCount() const
{
	return m_nWaferCount;
}

void Module::SetWaferMax(int _value)
{
	m_nWaferMax = _value;
}

int Module::GetWaferMax() const
{
	return m_nWaferMax;
}

bool Module::GetIsWorking()
{
	return isWorking;
}


#pragma region 생성자/소멸자
ProcessChamber::ProcessChamber()  
{
	m_strModuleName = _T("ProcessChamber");
	m_nWaferCount = 0;
	m_nWaferMax = 6;
	m_nProcessTime = 600;
	m_nCleanTime = 1200;
	m_nCleanCount = 10;
	m_nSlotValveOpenTime = 2;
	m_nSlotValveCloseTime = 2;

	isWorking = false;

	hMutex = CreateMutex(NULL, FALSE, NULL);
}

ProcessChamber::~ProcessChamber()
{
	CloseHandle(hMutex);
}
#pragma endregion

void VACRobot::work(Module* pM)
{
	///////////////////////////일하고 있는지 알림//////////////////////////////
	isWorking = true;

	for (int i = 0; i < 20; i++)
		cout << "VACRobot" << i << endl;

	isWorking = false;
	//////////////////////////////////////////////////////////////////////////
}

void VACRobot::Run(Module* pM)
{
	th = async(&VACRobot::work, this, pM);
}

void ProcessChamber::work(Module* pM)
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

	for (int i = 0; i <50; i++)
		cout << "PM" << i << endl;

	isWorking = false;
	//!!!!!!!!!!!!!!!!//
	
	goto Start;
}

void ProcessChamber::Run(Module* pM)
{
	th = async(&ProcessChamber::work, this, pM);
}

#pragma region Get/Set 메서드

void ProcessChamber::SetWaferMax(int _value)
{
	m_nWaferMax = _value;
}

int ProcessChamber::GetWaferMax()
{
	return m_nWaferMax;
}

void ProcessChamber::SetProcessTime(int _value)
{
	m_nProcessTime = _value;
}

int ProcessChamber::GetProcessTime()
{
	return m_nProcessTime;
}

void ProcessChamber::SetCleanTime(int _value)
{
	m_nCleanTime = _value;
}

int ProcessChamber::GetCleanTime()
{
	return m_nCleanTime;
}


void ProcessChamber::SetCleanCount(int _value)
{
	m_nCleanCount = _value;
}

int ProcessChamber::GetCleanCount()
{
	return m_nCleanCount;
}

void ProcessChamber::SetSlotValveOpenTime(int _value)
{
	m_nSlotValveOpenTime = _value;
}

int ProcessChamber::GetSlotValveOpenTime()
{
	return m_nSlotValveOpenTime;
}

void ProcessChamber::SetSlotValveCloseTime(int _value)
{
	m_nSlotValveCloseTime = _value;
}

int ProcessChamber::GetSlotValveCloseTime()
{
	return m_nSlotValveCloseTime;
}
#pragma endregion

#pragma region 메서드
void ProcessChamber::Process()
{
}

void ProcessChamber::Clean()
{
}
#pragma endregion

#pragma region 생성자/소멸자
VACRobot::VACRobot()
{
	m_strModuleName = _T("VACRobot");
	m_nWaferCount = 1;
	m_nWaferMax = 4;
	m_nPickTime = 5;
	m_nPlaceTime = 5;
	m_nRotateTime = 5;

	isWorking = false;
}
VACRobot::~VACRobot()
{
}
#pragma endregion

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

int VACRobot::GetPickTime()
{
	return m_nPickTime;
}

void VACRobot::SetPlaceTime(int _value)
{
	m_nPlaceTime = _value;
}

int VACRobot::GetPlaceTime()
{
	return m_nPlaceTime;
}

void VACRobot::SetRotateTime(int _value)
{
	m_nRotateTime = _value;
}

int VACRobot::GetRotateTime()
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


