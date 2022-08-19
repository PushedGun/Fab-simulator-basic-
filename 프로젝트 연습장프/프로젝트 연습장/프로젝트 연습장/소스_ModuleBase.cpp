#include <vector>
#include <thread>
#include <iostream>
#include <future>
#include <atlstr.h>
#include "소스_ModuleBase.h"

using namespace std;

#pragma once

ModuleBase::ModuleBase()
{
	hMutex = CreateMutex(NULL, FALSE, NULL);
	isWorking = false;
}

ModuleBase::~ModuleBase()
{
	CloseHandle(hMutex);
	//TerminateThread(th.native_handle(), NULL);
	/*
	LPDWORD pExitCode = 0;
	thread* pTh = &th;

	if (GetExitCodeThread(pTh, pExitCode) != 0)
	{
		ExitThread((DWORD)pExitCode);
		cout << "Thread Closed" << endl;

		if (CloseHandle(pTh))
		{
			cout << "Handle closed" << endl;
		}

	}

	system("pause");*/
	if (th.joinable())
	{
		cout << th.joinable() << "대충 꺼지는 중" << endl;
		th.join();
	}
	else
		cout << th.joinable() << "대충 못꺼지는 중" << endl;

}

void ModuleBase::SetModuleName(string _value)
{
	m_strModuleName = _value;
}

string ModuleBase::GetModuleName() const
{
	return m_strModuleName;
}

bool ModuleBase::SetWaferCount(int _value)
{
	if (m_nWaferCount > m_nWaferMax|| _value > m_nWaferMax|| _value < 0)			// WaferMax 수치 제한
	{
		return false;
	}
	m_nWaferCount = _value;
	return true;
}

int ModuleBase::GetWaferCount() const
{
	return m_nWaferCount;
}

void ModuleBase::SetWaferMax(int _value)
{
	m_nWaferMax = _value;
}

int ModuleBase::GetWaferMax() const
{
	return m_nWaferMax;
}

bool ModuleBase::GetIsWorking()
{
	return isWorking;
}

bool ModuleBase::SetIsWorking(bool _value)
{
	isWorking = _value;
	return true;
}
void ModuleBase::MoveWafer(ModuleBase* pM)
{
	WaitForSingleObject(pM->hMutex, INFINITE);
	while (1)
	{
		if (pM->SetWaferCount(pM->GetWaferCount() - 1) == true)
		{
			m_nWaferCount = m_nWaferCount + 1;
			cout << "받은 wafer : " << 1 << endl;
			break;
		}
		//cout << GetModuleName() << "대기중" << endl;
	}

	//pM->SetWaferCount(pM->GetWaferCount() - 1);
	//m_nWaferCount = m_nWaferCount + 1;
	//cout << "받은 wafer : " << 1 << endl;

	ReleaseMutex(pM->hMutex);
}
void ModuleBase::work(vector<ModuleBase*> m_v_pModule) //LL <--> EFEM
{
	ModuleBase* pM = NULL;

	while (1)
	{
		while (m_v_pModule.size() > 0)
		{
			pM = (ModuleBase*)m_v_pModule.back();
			m_v_pModule.pop_back();

			if (pM->GetIsWorking() == false && pM->GetWaferCount() > 0)
			{
				//!!!!!!!!!!!!!!!!//
				isWorking = true;

				MoveWafer(pM);

				//for (int i = 0; i < 10; i++)
				//	cout << GetModuleName() << endl;

				isWorking = false;
				pM->SetIsWorking(true);
				//!!!!!!!!!!!!!!!!//
			}
		}
	}
	///////////////////////////일하고 있는지 알림//////////////////////////////
	//isWorking = true;

	//for (int i = 0; i < 20; i++)
	//	cout << "VACRobot" << i << endl;

	//isWorking = false;
	//////////////////////////////////////////////////////////////////////////
}
void ModuleBase::Resume()
{
	if (th.joinable())
	{
		cout << GetModuleName() << " thread를 재개합니다." << endl;
		ResumeThread(th.native_handle());
	}
	else
		cout << "재개할" << GetModuleName() << " thread가 없습니다." << endl;

}
void ModuleBase::Suspend()
{
	if (th.joinable())
	{
		cout << GetModuleName() << " thread를 재개합니다." << endl;
		SuspendThread(th.native_handle());
	}
	else
		cout << "재개할" << GetModuleName() << " thread가 없습니다." << endl;
}

void ModuleBase::Run(vector<ModuleBase*> m_v_pModule) //LL <--> EFEM
{
	th = thread(&ModuleBase::work, this, m_v_pModule);
}