#pragma once
#include<iostream>
#include"clsGlobal.h"
using namespace std;
class clsReadpremission
{
public:
	enum enpremission {
		eAll = -1,
		eshowclient = 1,
		eaddclient = 2,
		edelleteclient = 4,
		eupdateclient = 8,
		efindclient = 16,
		etransaction = 32,
		emanageuser = 64,
		eRegister=128
	};

	static  int readpremission() {
		int premission = 0;
		char answer = 'y';

		cout << "\nDo you want to give full access? (y/n)? ";
		cin >> answer;
		if (answer == 'y' || answer == 'Y') {
			return -1;
		}

		cout << "\nDo you want to give access to :  \n";

		cout << "\nshow Client list? (y/n)? ";
		cin >> answer;
		if (answer == 'y' || answer == 'Y') {
			premission += enpremission::eshowclient;
		}

		cout << "\nAdd New Client? (y/n)? ";
		cin >> answer;
		if (answer == 'y' || answer == 'Y') {
			premission += enpremission::eaddclient;
		}

		cout << "\nDellete Client? (y/n)? ";
		cin >> answer;
		if (answer == 'y' || answer == 'Y') {
			premission += enpremission::edelleteclient;
		}

		cout << "\nUpdate Client? (y/n)? ";
		cin >> answer;
		if (answer == 'y' || answer == 'Y') {
			premission += enpremission::eupdateclient;
		}

		cout << "\nFind Client? (y/n)? ";
		cin >> answer;
		if (answer == 'y' || answer == 'Y') {
			premission += enpremission::efindclient;
		}

		cout << "\nTransaction? (y/n)? ";
		cin >> answer;
		if (answer == 'y' || answer == 'Y') {
			premission += enpremission::etransaction;
		}

		cout << "\nManage Users? (y/n)? ";
		cin >> answer;
		if (answer == 'y' || answer == 'Y') {
			premission += enpremission::emanageuser;
		}

		cout << "\Show Register Login List? (y/n)? ";
		cin >> answer;
		if (answer == 'y' || answer == 'Y') {
			premission += enpremission::eRegister;
		}

		return premission;
	}
	static bool checkaccesspremission(enpremission pre) {

		if (CurrentUser.$premission == enpremission::eAll) {
			return true;
		}
		if ((pre & CurrentUser.$premission) == pre) {
			return true;
		}
		else {
			return false;
		}
	}
};

