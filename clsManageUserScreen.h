#pragma once
#include<iostream>
#include"clsBankUser.h"
#include"clsScreen.h"
#include"clsInputValidate.h"
#include"clsFindUserScreen.h"
#include"clsUpdateUserScreen.h"
#include"clsAddUserScreen.h"
#include"clsUserList.h"
#include"clsDelleteUserScreen.h"
using namespace std;
class clsManageUserScreen:protected clsScreen
{
private:
	enum enUserOption {
		showlist = 1,
		adduser = 2,
		delleteuser = 3,
		updateuser = 4,
		finduser = 5,
		manemenue = 6
	};

	static short _ReadManageMenueOption() {
		short num;
		cout << setw(30) << left << "" << "    Choose what do you want to do ? [1 to 6] : ";
		num = clsInputValidate::ReadIntNumbetween(1, 6);

		return num;
	}

	

	static void _ShowFinduserScreen() {
		clsFindUserScreen::findClientScreen();
	}

	static void _ShowUpdateuserScreen() {
		clsUpdateUserScreen::UpdateUser();
	}

	static void _ShowAdduserScreen() {
		clsAddUserScrren::AddUser();
	}

	static void _ShowuserListScreen() {
		clsUserList::showlist();
	}

	static void _ShowDelleteUserScreen() {
		clsDelleteUserScreen::DelleteClient();
	}
	static void _GobacktoManageUser() {
	cout << "\nenter any key to go back to main......";
	system("pause>0");
		system("color 0f");
		showManageMenue();
	}
	static void _performManageUserOption(enUserOption option) {
		switch (option)
		{
		case clsManageUserScreen::showlist:
			system("cls");
			_ShowuserListScreen();
			_GobacktoManageUser();
			break;
		case clsManageUserScreen::adduser:
			system("cls");
			_ShowAdduserScreen();
			_GobacktoManageUser();
			break;
		case clsManageUserScreen::delleteuser:
			system("cls");
			_ShowDelleteUserScreen();
			_GobacktoManageUser();
			break;
		case clsManageUserScreen::updateuser:
			system("cls");
			_ShowUpdateuserScreen();
			_GobacktoManageUser();
			break;
		case clsManageUserScreen::finduser:
			system("cls");
			_ShowFinduserScreen();
			_GobacktoManageUser();
			break;
		case clsManageUserScreen::manemenue:
			break;
		default:
			break;
		}
	}
public:
	static void showManageMenue() {

		system("cls");

		DrawScreenheader("Manage User Menue");

		 cout << setw(30) << left << "" << "================================================================\n";
		 cout << setw(30) << left << "" << "          Manage User Menu Screen\n";
		 cout << setw(30) << left << "" << "================================================================\n";
		 cout << setw(30) << left << "" << "         [1] show User list\n";
		 cout << setw(30) << left << "" << "         [2] Add new User\n";
		 cout << setw(30) << left << "" << "         [3] Dellete User\n";
		 cout << setw(30) << left << "" << "         [4] Update User\n";
		 cout << setw(30) << left << "" << "         [5] Find User\n";
		 cout << setw(30) << left << "" << "         [6] Main Menu\n";
		 cout << setw(30) << left << "" << "================================================================\n";
		 _performManageUserOption(enUserOption(_ReadManageMenueOption()));
		 
	}
};

