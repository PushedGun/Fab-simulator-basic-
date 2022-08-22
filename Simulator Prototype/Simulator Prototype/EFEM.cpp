#include "pch.h"
#include "EFEM.h"
#include <future>
#include <thread>

#pragma region 생성자/소멸자
EFEM::EFEM()
{
	m_strModuleName = "EFEM";
	m_nWaferCount = 2;
	m_nWaferMax = 2;
	m_nPickTime = 4;
	m_nPlaceTime = 4;
	m_nRotateTime = 1;
	m_dRotateZCoordinateTime = 0.5;
	m_bIsInputWafer = true;

	m_hMutex = CreateMutex(NULL, FALSE, NULL);
}

EFEM::~EFEM()
{
}
#pragma endregion

#pragma region Get/Set 메서드
void EFEM::SetPickTime(int _value)
{
	m_nPickTime = _value;
}
int EFEM::GetPickTime() const
{
	return m_nPickTime;
}
void EFEM::SetPlaceTime(int _value)
{
	m_nPlaceTime = _value;
}
int EFEM::GetPlaceTime() const
{
	return m_nPlaceTime;
}
void EFEM::SetRotateTime(int _value)
{
	m_nRotateTime = _value;
}
int EFEM::GetRotateTime() const
{
	return m_nRotateTime;
}
void EFEM::SetRotateZTime(int _value)
{
	m_dRotateZCoordinateTime = _value;
}
double EFEM::GetRotateZTime() const
{
	return m_dRotateZCoordinateTime;
}
void EFEM::SetIsInputWafer(bool _value)
{
	m_bIsInputWafer = _value;
}
bool EFEM::GetIsInputWafer() const
{
	return m_bIsInputWafer;
}
void EFEM::work(ModuleBase* pM)
{

Start:
	while ((pM->GetIsWorking() == false && pM->GetWaferCount() > 0) == false)
	{
	}

	//////////////////////////////////<<뮤텍스로 접근제어>>/////////////////////////////////////
	WaitForSingleObject(m_hMutex, INFINITE);

	if ((pM->GetIsWorking() == false && pM->GetWaferCount() > 0) == false)
		goto Start;

	pM->SetWaferCount(pM->GetWaferCount() - 1);
	//cout << "받은 wafer : " << 1 << endl;

	ReleaseMutex(m_hMutex);
	//////////////////////////////////////////////////////////////////////////////////

	//!!!!!!!!!!!!!!!!//
	m_bIsWorking = true;

	/*for (int i = 0; i < 50; i++)
		cout << "PM" << i << endl;*/

	m_bIsWorking = false;
	//!!!!!!!!!!!!!!!!//

	goto Start;
}

void EFEM::Run(ModuleBase* pM)
{
	th = std::async(&EFEM::work, this, pM);
}

#pragma endregion

#pragma region 메서드
void EFEM::Pick()
{
}

void EFEM::Place()
{
}

void EFEM::Rotate()
{
}
double EFEM::Run()
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
}
#pragma endregion