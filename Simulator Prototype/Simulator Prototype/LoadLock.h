#pragma once
#include "ModuleBase.h"

class LoadLock : public ModuleBase
{
#pragma region �ʵ�
private:
	int m_nPumpTime;				// ��� >> ���� ���� ��ȯ �ð�
	int m_nPumpStableTime;			// ���� ���� ��ȯ ��/�� �ҿ� �ð�
	int m_nVentTime;				// ���� >> ��� ���� ��ȯ �ð�
	int m_nVentStableTime;			// ��� ���� ��ȯ ��/�� �ҿ� �ð�
	int m_nSlotValveOpenTime;		// TM ���� VALVE ���� �ð�
	int m_nSlotValveCloseTime;		// TM ���� VALVE �ݴ� �ð�
	int m_nDoorValveOpenTime;		// EFEM ���� VALVE ���� �ð�
	int m_nDoorValveCloseTime;		// EFEM ���� VALVE �ݴ� �ð�
	bool m_bIsInputWafer;			// TRUE : FOUP >> PM	FALSE : PM >> FOUP
#pragma endregion

#pragma region ������/�Ҹ���
public:
	LoadLock();
	~LoadLock();
#pragma endregion

#pragma region Get/Set �޼���
public:
	void SetPumpTime(int _value);
	int GetPumpTime() const;
	void SetPumpStableTime(int _value);
	int GetPumpStableTime() const;
	void SetVentTime(int _value);
	int GetVentTime() const;
	void SetVentStableTime(int _value);
	int GetVentStableTime() const;
	void SetSlotValveOpenTime(int _value);
	int GetSlotValveOpenTime() const;
	void SetSlotValveCloseTime(int _value);
	int GetSlotValveCloseTime() const;
	void SetDoorValveOpenTime(int _value);
	int GetDoorValveOpenTime() const;
	void SetDoorValveCloseTime(int _value);
	int GetDoorValveCloseTime() const;
	void SetIsInputWafer(bool _value);
	bool GetIsInputWafer() const;

	void Run(ModuleBase* pM);
	void work(ModuleBase* pM);
#pragma endregion

#pragma region �޼���
public:
	double Pump();
	double vent();
	virtual double Run();
#pragma endregion
};