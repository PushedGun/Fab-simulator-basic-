#include "�ҽ�_PM.h"

#include <vector>
#include <thread>
#include <iostream>
#include <future>
#include <atlstr.h>
#include <string>

using namespace std;

#pragma region ������/�Ҹ���
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

#pragma region Get/Set �޼���

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

#pragma region �޼���
void ProcessChamber::Process()
{
}

void ProcessChamber::Clean()
{
}
#pragma endregion