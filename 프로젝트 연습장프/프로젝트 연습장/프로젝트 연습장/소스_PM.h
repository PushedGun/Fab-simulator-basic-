#pragma once
#include <vector>
#include <thread>
#include <iostream>
#include <future>
#include <atlstr.h>

#include "�ҽ�_ModuleBase.h"

using namespace std;

class ProcessChamber : public ModuleBase
{
#pragma region �ʵ�
private:
	CString m_strModuleName;
	// �⺻ �䱸����
	int m_nProcessTime;					// Process ���� �ð�
	int m_nCleanTime;					// Clean ���� �ð�
	int m_nCleanCount;					// Process ��� ���� �� Clean ������ ������ ���� ��ġ
	int m_nSlotValveOpenTime;			// LL ���� VALVE ���� �ð�
	int m_nSlotValveCloseTime;			// LL ���� VALVE �ݴ� �ð�


	HANDLE hMutex;

#pragma endregion

#pragma region ������/�Ҹ���
public:
	ProcessChamber();
	~ProcessChamber();
#pragma endregion

#pragma region Get/Set �޼���
public:
	void SetWaferMax(int _value);
	int GetWaferMax();
	void SetProcessTime(int _value);
	int GetProcessTime();
	void SetCleanTime(int _value);
	int GetCleanTime();
	void SetCleanCount(int _value);
	int GetCleanCount();
	void SetSlotValveOpenTime(int _value);
	int GetSlotValveOpenTime();
	void SetSlotValveCloseTime(int _value);
	int GetSlotValveCloseTime();

#pragma endregion

#pragma region �޼���
public:
	void Process();
	void Clean();
};
