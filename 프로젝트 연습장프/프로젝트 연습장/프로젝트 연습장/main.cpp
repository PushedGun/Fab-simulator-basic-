#include <vector>
#include <thread>
#include <iostream>
#include <future>
#include <atlstr.h>
#include <string>

#include "�ҽ�_ModuleBase.h"
#include "�ҽ�_LL.h"
#include "�ҽ�_TM.h"
#include "�ҽ�_EFEM.h"
#include "�ҽ�_PM.h"

using namespace std;

CString strWaf = _T("���� Wafer�̴�");

int main()
{
	/*VACRobot tm;
	ProcessChamber pm1, pm2;

	tm.SetWaferCount(1);

	Module* p = NULL;
	tm.Run(p);

	//bool b = tm.GetIsWorking();
	cout << "������ �� : " << tm.GetWaferCount() << endl;
	
	pm1.Run(&tm);
	pm2.Run(&tm);
	*/

	//////////////////////////////////////////////////////////////


	/*ATMRobot atm;
	LoadLock LL1, LL2;

	atm.SetWaferCount(1);

	ModuleBase* p = NULL;
	atm.Run(p);

	cout << "������ �� : " << atm.GetWaferCount() << endl;

	LL1.Run(&atm);
	LL2.Run(&atm);
	*/

	//atm.SetWaferCount(5);

	ATMRobot ATM;
	LoadLock LL1, LL2, LL3, LL4;
	VACRobot TM;
	ProcessChamber PM1, PM2;
	vector<ModuleBase*> vpM;

	ModuleBase* p = NULL;
	Sleep(100);
	ATM.Run(p);

	ATM.SetWaferCount(2);

	cout << "///////////////////////////////////////////////" << endl;
	cout << "ATM ������ �� : " << ATM.GetWaferCount() << endl;
	cout << "LL1 ������ �� : " << LL1.GetWaferCount() << endl;
	cout << "LL2 ������ �� : " << LL2.GetWaferCount() << endl;
	cout << "TM ������ �� : " << TM.GetWaferCount() << endl;
	cout << "PM1 ������ �� : " << PM1.GetWaferCount() << endl;
	cout << "PM2 ������ �� : " << PM2.GetWaferCount() << endl;
	cout << "///////////////////////////////////////////////" << endl;

	Sleep(100);
	cout << "///////////////////////////////////////////////" << endl;
	cout << "ATM ������ �� : " << ATM.GetWaferCount() << endl;
	cout << "LL1 ������ �� : " << LL1.GetWaferCount() << endl;
	cout << "LL2 ������ �� : " << LL2.GetWaferCount() << endl;
	cout << "TM ������ �� : " << TM.GetWaferCount() << endl;
	cout << "PM1 ������ �� : " << PM1.GetWaferCount() << endl;
	cout << "PM2 ������ �� : " << PM2.GetWaferCount() << endl;
	cout << "///////////////////////////////////////////////" << endl;
	vpM.clear();
	vpM.push_back(&ATM);

	LL1.Run(vpM);
	LL2.Run(vpM);

	cout << "�Ͻ�����" << endl;
	ATM.Suspend();
	LL1.Suspend();
	LL2.Suspend();
	TM.Suspend();
	PM1.Suspend();
	PM2.Suspend();

	Sleep(10);

	cout << "�簳" << endl;
	ATM.Resume();
	LL1.Resume();
	LL2.Resume();
	TM.Resume();
	PM1.Resume();
	PM2.Resume();

	Sleep(100);
	cout << "///////////////////////////////////////////////" << endl;
	cout << "ATM ������ �� : " << ATM.GetWaferCount() << endl;
	cout << "LL1 ������ �� : " << LL1.GetWaferCount() << endl;
	cout << "LL2 ������ �� : " << LL2.GetWaferCount() << endl;
	cout << "TM ������ �� : " << TM.GetWaferCount() << endl;
	cout << "PM1 ������ �� : " << PM1.GetWaferCount() << endl;
	cout << "PM2 ������ �� : " << PM2.GetWaferCount() << endl;
	cout << "///////////////////////////////////////////////" << endl;
	vpM.clear();
	vpM.push_back(&LL1);
	vpM.push_back(&LL2);

	TM.Run(vpM);

	Sleep(100);
	cout << "///////////////////////////////////////////////" << endl;
	cout << "ATM ������ �� : " << ATM.GetWaferCount() << endl;
	cout << "LL1 ������ �� : " << LL1.GetWaferCount() << endl;
	cout << "LL2 ������ �� : " << LL2.GetWaferCount() << endl;
	cout << "TM ������ �� : " << TM.GetWaferCount() << endl;
	cout << "PM1 ������ �� : " << PM1.GetWaferCount() << endl;
	cout << "PM2 ������ �� : " << PM2.GetWaferCount() << endl;
	cout << "///////////////////////////////////////////////" << endl;
	vpM.clear();
	vpM.push_back(&TM);

	PM1.Run(vpM);
	PM2.Run(vpM);

	Sleep(3000);
	cout << "///////////////////////////////////////////////" << endl;
	cout << "ATM ������ �� : " << ATM.GetWaferCount() << endl;
	cout << "LL1 ������ �� : " << LL1.GetWaferCount() << endl;
	cout << "LL2 ������ �� : " << LL2.GetWaferCount() << endl;
	cout << "TM ������ �� : " << TM.GetWaferCount() << endl;
	cout << "PM1 ������ �� : " << PM1.GetWaferCount() << endl;
	cout << "PM2 ������ �� : " << PM2.GetWaferCount() << endl;
	cout << "///////////////////////////////////////////////" << endl;

	while(1)
	{ }

	return 0;

}

