#pragma once

#include <vector>
#include <thread>
#include <iostream>
#include <future>
#include <atlstr.h>
#include "소스_ModuleBase.h"

using namespace std;

class VACRobot : public ModuleBase
{
#pragma region 필드
private:
	int m_nWaferCount;					// 현재 모듈이 가지는 Wafer 개수
	int m_nWaferMax;					// 현재 모듈이 가질 수 있는 Wafer Max 수치
	int m_nPickTime;					// RobotArm으로 Wafer를 가져오는 시간
	int m_nPlaceTime;					// RobotArm의 Wafer를 대상 Module로 놓는 시간
	int m_nRotateTime;					// Robot의 회전시간

	HANDLE hMutex;

#pragma endregion

#pragma region 생성자/소멸자
public:
	VACRobot();
	~VACRobot();
#pragma endregion

#pragma region Get/Set 메서드
public:

	void SetPickTime(int _value);
	int GetPickTime() const;
	void SetPlaceTime(int _value);
	int GetPlaceTime() const;
	void SetRotateTime(int _value);
	int GetRotateTime() const;
	void SetWaferMax(int _value);
	int GetWaferMax();

#pragma endregion

#pragma region 메서드
public:
	void Pick();
	void Place();
	void Rotate();
#pragma endregion
};