#include "pch.h"
#include <future>
#include <thread>

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
	CPoint m_ptPos;						// ��� ���� ��ġ
	bool m_bIsWorking;					// ���� ����� ���������� ��Ÿ���� �ʵ�

	HANDLE m_hMutex;
	///������///
	std::future<void> th;
#pragma endregion

#pragma region Get/Set �޼���
public:
	void SetModuleName(CString _value);
	CString GetModuleName() const;
	void SetWaferCount(int _value);
	int GetWaferCount() const;
	void SetWaferMax(int _value);
	int GetWaferMax() const;
	void SetPos(int _X, int _Y);
	void SetPos(CPoint _value);
	CPoint GetPos() const;
	//void SetIsWorking(bool _value);
	bool GetIsWorking() const;

#pragma endregion

public:
	virtual void Run(ModuleBase* pM) = 0;					// ���� �޼���, ������ �ݹ��Լ� ����
	//virtual void Serialize(CArchive& ar);		// FileIO�� ���� Serialize ������ (���� ��� ���� �� INI ���� �������� ���� ����?)
};