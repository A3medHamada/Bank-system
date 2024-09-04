#pragma once
#include"clsScreen.h"
#include<iostream>
#include"clsGlobal.h"
#include"clsMainScreen.h"
#include"clsBankUser.h"
#include"fstream"
#include"clsShowRegisterScreen.h"
using namespace std;
class clsLoginScreen:protected clsScreen
{
private:
	static bool _Login() {
		bool LoginFalid = false;
		string Id, password;
		short count = 0;

		do {

			if (LoginFalid) {
				count++;
				cout << "\nInvalid Id/Password!\n\n";
				cout << "\nYou Have " << 3 - count << " Trial(s) to Login.\n\n";
			}
			if (count == 3) {
				cout << "\nYou Are Locked After 3 Falid Trials \n\n";
				return false;
			}

			cout << "Enter ID? ";
			cin >> Id;

			cout << "Enter Password? ";
			cin >> password;

			CurrentUser = clsBankUser::find(Id, password);

			LoginFalid = clsBankUser::Isempty(CurrentUser);

		} while (LoginFalid);

		clsShowRegisterScreen::_loaddatetologfile();
		clsMainScreen::ShowMainMenu();
		return true;
	}

public:
	static bool ShowLoginScreen() {

		system("cls");

		DrawScreenheader("Login Screen");
		return _Login();
	}

	
};

