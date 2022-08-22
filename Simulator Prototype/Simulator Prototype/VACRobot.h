#pragma once
#include "ModuleBase.h"

class VACRobot : public ModuleBase
{
#pragma region �ʵ�
private:
	int m_nWaferCount;					// ���� ����� ������ Wafer ����
	int m_nWaferMax;					// ���� ����� ���� �� �ִ� Wafer Max ��ġ
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
	void SetPickTime(int _value);
	int GetPickTime() const;
	void SetPlaceTime(int _value);
	int GetPlaceTime() const;
	void SetRotateTime(int _value);
	int GetRotateTime() const;
#pragma endregion

#pragma region �޼���
public:
	void Pick();
	void Place();
	void Rotate();
	virtual double Run();
#pragma endregion
};