#pragma once
#pragma once

#include <vector>
#include <thread>
#include <iostream>
#include <future>
#include <atlstr.h>
using namespace std;

class ModuleBase
{
#pragma region �ʵ�
protected:								// �ڽ� Ŭ�������� Get/Set �޼��带 ���� Wafer Max ��ġ ������ �ٸ� �� ������ ����, ������ ���Ǿ�� ��.. �׷��� protected
	string m_strModuleName;			// ���� ����� �̸�(����)
	int m_nWaferCount;					// ���� ATMRobot�� ������ Wafer ����
	int m_nWaferMax;					// ���� ����� ���� �� �ִ� Wafer Max ��ġ
#pragma endregion

	bool isWorking;

	///������///
	thread th;
	HANDLE hMutex;

	vector<ModuleBase*> m_v_pModule;

#pragma region ������/�Ҹ���
public:
	ModuleBase();
	~ModuleBase();
#pragma endregion

#pragma region Get/Set �޼���
public:
	virtual void SetModuleName(string _value);
	virtual string GetModuleName() const;
	bool SetWaferCount(int _value);
	int GetWaferCount() const;
	virtual void SetWaferMax(int _value);
	virtual int GetWaferMax() const;

	bool GetIsWorking();
	bool SetIsWorking(bool _value);

	void MoveWafer(ModuleBase* pM);

	void Resume();
	void Suspend();

#pragma endregion

public:
	void work(vector<ModuleBase*> m_v_pModule);
	virtual void Run(vector<ModuleBase*> m_v_pModule);					// ���� �޼���, ������ �ݹ��Լ� ����
	//virtual void Serialize(CArchive& ar);		// FileIO�� ���� Serialize ������ (���� ��� ���� �� INI ���� �������� ���� ����?)
};

class A : public ModuleBase
{

};

class B : public ModuleBase
{

};

class C : public ModuleBase
{

};