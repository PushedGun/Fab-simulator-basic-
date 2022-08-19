#include <vector>
#include <thread>
#include <iostream>
#include <future>
#include <atlstr.h>
#include "�ҽ�_ModuleBase.h"

using namespace std;

#pragma once

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