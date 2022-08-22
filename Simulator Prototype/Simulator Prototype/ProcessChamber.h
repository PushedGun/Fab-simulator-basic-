#pragma once
#include "ModuleBase.h"

class ProcessChamber : public ModuleBase
{
#pragma region �ʵ�
private:
	int m_nProcessTime;					// Process ���� �ð�
	int m_nCleanTime;					// Clean ���� �ð�
	int m_nCleanCount;					// Process ��� ���� �� Clean ������ ������ ���� ��ġ
	int m_nSlotValveOpenTime;			// LL ���� VALVE ���� �ð�
	int m_nSlotValveCloseTime;			// LL ���� VALVE �ݴ� �ð�
#pragma endregion

#pragma region ������/�Ҹ���
public:
	ProcessChamber();
	~ProcessChamber();
#pragma endregion

#pragma region Get/Set �޼���
public:
	void SetProcessTime(int _value);
	int GetProcessTime() const;
	void SetCleanTime(int _value);
	int GetCleanTime() const;
	void SetCleanCount(int _value);
	int GetCleanCount() const;
	void SetSlotValveOpenTime(int _value);
	int GetSlotValveOpenTime() const;
	void SetSlotValveCloseTime(int _value);
	int GetSlotValveCloseTime() const;
#pragma endregion

#pragma region �޼���
public:
	void Process();
	void Clean();
	virtual double Run();
#pragma endregion
};