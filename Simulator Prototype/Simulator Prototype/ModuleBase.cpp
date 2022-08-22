#include "pch.h"
#include "ModuleBase.h"

void ModuleBase::SetModuleName(CString _value)
{
	m_strModuleName = _value;
}

CString ModuleBase::GetModuleName() const
{
	return m_strModuleName;
}

void ModuleBase::SetWaferCount(int _value)
{
	if (m_nWaferCount > m_nWaferMax)			// WaferMax 수치 제한
	{
		return;
	}
	m_nWaferCount = _value;
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

void ModuleBase::SetPos(int _X, int _Y)
{
	m_ptPos.x = _X;
	m_ptPos.y = _Y;
}

void ModuleBase::SetPos(CPoint _value)
{
	m_ptPos = _value;
}

CPoint ModuleBase::GetPos() const
{
	return m_ptPos;
}

//void ModuleBase::SetIsWorking(bool _value)
//{
//	m_bIsWorking = _value;
//}

bool ModuleBase::GetIsWorking() const
{
	return m_bIsWorking;
}
