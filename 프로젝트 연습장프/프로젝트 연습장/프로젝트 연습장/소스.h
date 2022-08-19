#include <vector>
#include <thread>
#include <iostream>
#include <future>
#include <atlstr.h>
using namespace std;

class Module
{
#pragma region �ʵ�
protected:								// �ڽ� Ŭ�������� Get/Set �޼��带 ���� Wafer Max ��ġ ������ �ٸ� �� ������ ����, ������ ���Ǿ�� ��.. �׷��� protected
	CString m_strModuleName;			// ���� ����� �̸�(����)
	int m_nWaferCount;					// ���� ATMRobot�� ������ Wafer ����
	int m_nWaferMax;					// ���� ����� ���� �� �ִ� Wafer Max ��ġ
#pragma endregion

	bool isWorking;

	///������///
	future<void> th;

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
	virtual void Run(Module* pM) = 0;					// ���� �޼���, ������ �ݹ��Լ� ����
	//virtual void Serialize(CArchive& ar);		// FileIO�� ���� Serialize ������ (���� ��� ���� �� INI ���� �������� ���� ����?)
};

class VACRobot : public Module
{
#pragma region �ʵ�
private:
	CString m_strModuleName;
	// �⺻ �䱸����
	int m_nPickTime;					// RobotArm���� Wafer�� �������� �ð�
	int m_nPlaceTime;					// RobotArm�� Wafer�� ��� Module�� ���� �ð�
	int m_nRotateTime;					// Robot�� ȸ���ð�

#pragma endregion

#pragma region ������/�Ҹ���
public:
	VACRobot();
	~VACRobot();
#pragma endregion

#pragma region Get/Set �޼���
public:
	void SetWaferMax(int _value);
	int GetWaferMax();
	void SetPickTime(int _value);
	int GetPickTime();
	void SetPlaceTime(int _value);
	int GetPlaceTime();
	void SetRotateTime(int _value);
	int GetRotateTime();

#pragma endregion

#pragma region �޼���
public:
	void Pick();
	void Place();
	void Rotate();

	void work(Module* pM);
	void Run(Module* pM);

};

class ProcessChamber : public Module
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

	void work(Module* pM);
	void Run(Module* pM);
};
