#pragma once
#include <vector>
#include <thread>
#include <iostream>
#include <future>
#include <atlstr.h>

#include "소스_ModuleBase.h"

using namespace std;

class ProcessChamber : public ModuleBase
{
#pragma region 필드
private:
	CString m_strModuleName;
	// 기본 요구사항
	int m_nProcessTime;					// Process 진행 시간
	int m_nCleanTime;					// Clean 진행 시간
	int m_nCleanCount;					// Process 몇번 진행 후 Clean 진행할 것인지 설정 수치
	int m_nSlotValveOpenTime;			// LL 연결 VALVE 여는 시간
	int m_nSlotValveCloseTime;			// LL 연결 VALVE 닫는 시간


	HANDLE hMutex;

#pragma endregion

#pragma region 생성자/소멸자
public:
	ProcessChamber();
	~ProcessChamber();
#pragma endregion

#pragma region Get/Set 메서드
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

#pragma region 메서드
public:
	void Process();
	void Clean();
};
