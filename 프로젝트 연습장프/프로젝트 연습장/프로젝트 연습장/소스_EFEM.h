#include <vector>
#include <thread>
#include <iostream>
#include <future>
#include <atlstr.h>
#include "소스_ModuleBase.h"

using namespace std;

#pragma once

class ATMRobot : public ModuleBase
{
#pragma region 필드
private:
	int m_nPickTime;					// RobotArm으로 Wafer를 가져오는 시간
	int m_nPlaceTime;					// RobotArm의 Wafer를 대상 Module로 놓는 시간
	int m_nRotateTime;					// Robot의 회전시간
	double m_dRotateZCoordinateTime;	// Robot의 Z축 회전 시간
	bool m_bIsInputWafer;				// TRUE : FOUP >> PM	FALSE : PM >> FOUP



#pragma endregion

#pragma region 생성자/소멸자
public:
	ATMRobot();
	~ATMRobot();
#pragma endregion

#pragma region Get/Set 메서드
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

#pragma region 메서드
public:
	void Pick();
	void Place();
	void Rotate();
	//virtual double Run();

	void work(ModuleBase* pM);
	void Run(ModuleBase* pM);
#pragma endregion
};