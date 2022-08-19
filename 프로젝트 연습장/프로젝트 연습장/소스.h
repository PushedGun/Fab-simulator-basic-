#include <vector>
#include <thread>
#include <iostream>
#include <future>
#include <atlstr.h>
using namespace std;

class Module
{
#pragma region 필드
protected:								// 자식 클래스들의 Get/Set 메서드를 통한 Wafer Max 수치 제한이 다를 수 있음을 생각, 접근이 허용되어야 함.. 그래서 protected
	CString m_strModuleName;			// 현재 모듈의 이름(기계명)
	int m_nWaferCount;					// 현재 ATMRobot이 가지는 Wafer 개수
	int m_nWaferMax;					// 현재 모듈이 가질 수 있는 Wafer Max 수치
#pragma endregion

	bool isWorking;

	///쓰레드///
	future<void> th;

#pragma region Get/Set 메서드
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
	virtual void Run(Module* pM) = 0;					// 동작 메서드, 쓰레드 콜백함수 예상
	//virtual void Serialize(CArchive& ar);		// FileIO를 위한 Serialize 재정의 (추후 기능 구현 시 INI 파일 저장으로 변경 예상?)
};

class VACRobot : public Module
{
#pragma region 필드
private:
	CString m_strModuleName;
	// 기본 요구사항
	int m_nPickTime;					// RobotArm으로 Wafer를 가져오는 시간
	int m_nPlaceTime;					// RobotArm의 Wafer를 대상 Module로 놓는 시간
	int m_nRotateTime;					// Robot의 회전시간

#pragma endregion

#pragma region 생성자/소멸자
public:
	VACRobot();
	~VACRobot();
#pragma endregion

#pragma region Get/Set 메서드
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

#pragma region 메서드
public:
	void Pick();
	void Place();
	void Rotate();

	void work(Module* pM);
	void Run(Module* pM);

};

class ProcessChamber : public Module
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

	void work(Module* pM);
	void Run(Module* pM);
};
