#include "소스_EFEM.h"

#include <vector>
#include <thread>
#include <iostream>
#include <future>
#include <atlstr.h>
#include <string>

void ATMRobot::work(ModuleBase* pM)
{
	for (int i = 0; i < m_nWaferCount; i++)
	{
		//!!!!!!!!!!!!!!!!//
		isWorking = true;

		//for (int i = 0; i < 10; i++)
			cout << "EFEM" << endl;

		isWorking = false;
		//!!!!!!!!!!!!!!!!//

	}
	
}

void ATMRobot::Run(ModuleBase* pM)
{
	th = thread(&ATMRobot::work, this, pM);
}


#pragma region 생성자/소멸자
ATMRobot::ATMRobot()
{
	m_strModuleName = "EFEM";
	m_nWaferCount = 1;
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