#include <vector>
#include <thread>
#include <iostream>
#include <future>
#include <atlstr.h>
using namespace std;


#pragma once
// ��� ��� Ŭ������ �θ� Ŭ���� (�߻�Ŭ����)
// �ڽ�Ŭ���� �������̵� ����

class ModuleBase
{
#pragma region �ʵ�
protected:								// �ڽ� Ŭ�������� Get/Set �޼��带 ���� Wafer Max ��ġ ������ �ٸ� �� ������ ����, ������ ���Ǿ�� ��.. �׷��� protected
	CString m_strModuleName;			// ���� ����� �̸�(����)
	int m_nWaferCount;					// ���� ATMRobot�� ������ Wafer ����
	int m_nWaferMax;					// ���� ����� ���� �� �ִ� Wafer Max ��ġ

	bool isWorking;

	///������///
	future<void> th;
#pragma endregion

#pragma region Get/Set �޼���
public:
	virtual void SetModuleName(CString _value);
	virtual CString GetModuleName() const;
	void SetWaferCount(int _value);
	int GetWaferCount() const;
	virtual void SetWaferMax(int _value);
	virtual int GetWaferMax() const;

	bool GetIsWorking();
#pragma endregion

public:
	virtual void Run(ModuleBase* pM) = 0;					// ���� �޼���, ������ �ݹ��Լ� ����
	//virtual void Serialize(CArchive& ar);		// FileIO�� ���� Serialize ������ (���� ��� ���� �� INI ���� �������� ���� ����?)
};

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

	HANDLE hMutex;
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
#pragma endregion

#pragma region �޼���
public:
	void Pump();
	void vent();
	//virtual double Run();


	void work(ModuleBase* pM);
	void Run(ModuleBase* pM);
#pragma endregion
};


class ATMRobot : public ModuleBase
{
#pragma region �ʵ�
private:
	int m_nPickTime;					// RobotArm���� Wafer�� �������� �ð�
	int m_nPlaceTime;					// RobotArm�� Wafer�� ��� Module�� ���� �ð�
	int m_nRotateTime;					// Robot�� ȸ���ð�
	double m_dRotateZCoordinateTime;	// Robot�� Z�� ȸ�� �ð�
	bool m_bIsInputWafer;				// TRUE : FOUP >> PM	FALSE : PM >> FOUP

	

#pragma endregion

#pragma region ������/�Ҹ���
public:
	ATMRobot();
	~ATMRobot();
#pragma endregion

#pragma region Get/Set �޼���
public:
	void SetPickTime(int _value);
	int GetPickTime() const;
	void SetPlaceTime(int _value);
	int GetPlaceTime() const;
	void SetRotateTime(int _value);
	int GetRotateTime() const;
	void SetRotateZTime(int _value);
	double GetRotateZTime() const;
	void SetIsInputWafer(bool _value);
	bool GetIsInputWafer() const;
#pragma endregion

#pragma region �޼���
public:
	void Pick();
	void Place();
	void Rotate();
	//virtual double Run();

	void work(ModuleBase* pM);
	void Run(ModuleBase* pM);
#pragma endregion
};