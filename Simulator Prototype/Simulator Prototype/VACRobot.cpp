#include "pch.h"
#include "VACRobot.h"

#pragma region 생성자/소멸자
VACRobot::VACRobot()
{
	m_strModuleName = "VAC. Robot";
	m_nWaferCount = 0;
	m_nWaferMax = 4;
	m_nPickTime = 5;
	m_nPlaceTime = 5;
	m_nRotateTime = 5;
}
VACRobot::~VACRobot()
{
}
#pragma endregion

#pragma region Get/Set 메서드
void VACRobot::SetPickTime(int _value)
{
	m_nPickTime = _value;
}

int VACRobot::GetPickTime() const
{
	return m_nPickTime;
}

void VACRobot::SetPlaceTime(int _value)
{
	m_nPlaceTime = _value;
}

int VACRobot::GetPlaceTime() const
{
	return m_nPlaceTime;
}

void VACRobot::SetRotateTime(int _value)
{
	m_nRotateTime = _value;
}

int VACRobot::GetRotateTime() const
{
	return m_nRotateTime;
}
#pragma endregion

#pragma region 메서드
void VACRobot::Pick()
{
}
void VACRobot::Place()
{
}
void VACRobot::Rotate()
{
}
double VACRobot::Run()
{
	return 0.0;
}
#pragma endregion
