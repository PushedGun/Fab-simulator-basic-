#pragma once
#pragma once

#include <vector>
#include <thread>
#include <iostream>
#include <future>
#include <atlstr.h>
using namespace std;

class ModuleBase
{
#pragma region 필드
protected:								// 자식 클래스들의 Get/Set 메서드를 통한 Wafer Max 수치 제한이 다를 수 있음을 생각, 접근이 허용되어야 함.. 그래서 protected
	string m_strModuleName;			// 현재 모듈의 이름(기계명)
	int m_nWaferCount;					// 현재 ATMRobot이 가지는 Wafer 개수
	int m_nWaferMax;					// 현재 모듈이 가질 수 있는 Wafer Max 수치
#pragma endregion

	bool isWorking;

	///쓰레드///
	thread th;
	HANDLE hMutex;

	vector<ModuleBase*> m_v_pModule;

#pragma region 생성자/소멸자
public:
	ModuleBase();
	~ModuleBase();
#pragma endregion

#pragma region Get/Set 메서드
public:
	virtual void SetModuleName(string _value);
	virtual string GetModuleName() const;
	bool SetWaferCount(int _value);
	int GetWaferCount() const;
	virtual void SetWaferMax(int _value);
	virtual int GetWaferMax() const;

	bool GetIsWorking();
	bool SetIsWorking(bool _value);

	void MoveWafer(ModuleBase* pM);

	void Resume();
	void Suspend();

#pragma endregion

public:
	void work(vector<ModuleBase*> m_v_pModule);
	virtual void Run(vector<ModuleBase*> m_v_pModule);					// 동작 메서드, 쓰레드 콜백함수 예상
	//virtual void Serialize(CArchive& ar);		// FileIO를 위한 Serialize 재정의 (추후 기능 구현 시 INI 파일 저장으로 변경 예상?)
};

class A : public ModuleBase
{

};

class B : public ModuleBase
{

};

class C : public ModuleBase
{

};