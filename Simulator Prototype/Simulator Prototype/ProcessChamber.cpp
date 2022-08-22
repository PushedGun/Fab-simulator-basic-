#include "pch.h"
#include "ProcessChamber.h"

#pragma region 생성자/소멸자
ProcessChamber::ProcessChamber()
{
	m_strModuleName = "ProcessChamber";
	m_nWaferCount = 0;
	m_nWaferMax = 6;
	m_nProcessTime = 600;
	m_nCleanTime = 1200;
	m_nCleanCount = 10;
	m_nSlotValveOpenTime = 2;
	m_nSlotValveCloseTime = 2;
}

ProcessChamber::~ProcessChamber()
{
}
#pragma endregion

#pragma region Get/Set 메서드
void ProcessChamber::SetProcessTime(int _value)
{
	m_nProcessTime = _value;
}

int ProcessChamber::GetProcessTime() const
{
	return m_nProcessTime;
}

void ProcessChamber::SetCleanTime(int _value)
{
	m_nCleanTime = _value;
}

int ProcessChamber::GetCleanTime() const
{
	return m_nCleanTime;
}

void ProcessChamber::SetCleanCount(int _value)
{
	m_nCleanCount = _value;
}

int ProcessChamber::GetCleanCount() const
{
	return m_nCleanCount;
}

void ProcessChamber::SetSlotValveOpenTime(int _value)
{
	m_nSlotValveOpenTime = _value;
}

int ProcessChamber::GetSlotValveOpenTime() const
{
	return m_nSlotValveOpenTime;
}

void ProcessChamber::SetSlotValveCloseTime(int _value)
{
	m_nSlotValveCloseTime = _value;
}

int ProcessChamber::GetSlotValveCloseTime() const
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
double ProcessChamber::Run()
{
	return 0.0;
}
#pragma endregion