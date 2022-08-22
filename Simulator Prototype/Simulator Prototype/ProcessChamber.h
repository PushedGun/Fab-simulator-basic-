#pragma once
#include "ModuleBase.h"

class ProcessChamber : public ModuleBase
{
#pragma region 필드
private:
	int m_nProcessTime;					// Process 진행 시간
	int m_nCleanTime;					// Clean 진행 시간
	int m_nCleanCount;					// Process 몇번 진행 후 Clean 진행할 것인지 설정 수치
	int m_nSlotValveOpenTime;			// LL 연결 VALVE 여는 시간
	int m_nSlotValveCloseTime;			// LL 연결 VALVE 닫는 시간
#pragma endregion

#pragma region 생성자/소멸자
public:
	ProcessChamber();
	~ProcessChamber();
#pragma endregion

#pragma region Get/Set 메서드
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

#pragma region 메서드
public:
	void Process();
	void Clean();
	virtual double Run();
#pragma endregion
};