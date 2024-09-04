#pragma once
#include<iostream>
#include<iomanip>
#include"clsScreen.h"
#include"clsInputValidate.h"
#include"clsClientList.h"
#include"clsAddClientScrren.h"
#include"clsUpdateClientScreen.h"
#include"clsDelleteClientScreen.h"
#include"clsTransactionsScreen.h"
#include"clsFindClientScreen.h"
#include"clsManageUserScreen.h"
#include"clsGlobal.h"
#include"clsReadpremission.h"
#include"clsShowRegisterScreen.h"
using namespace std;
class clsMainScreen:protected clsScreen
{
	 
private:
	enum enoption {

		showclinett = 1,
		addclinett = 2,
		deleteclinett = 3,
		updateclinett = 4,
		findclinett = 5,
		Transaction = 6,
		mangeuser = 7,
		registerlogin=8,
		logout = 9

	};

	static short _ReadMainMenuOption() {

		cout << setw(30) << left << "" << "     choose what do you want to do[1 to 9] :";

		 short option = clsInputValidate::ReadIntNumbetween(1, 9);
		 return option;
	}

	static void _GobacktoMainUser() {
		cout << "\nenter any key to go back to main......";
		system("pause>0");
		system("color 0f");
		ShowMainMenu();
	}

	static void  showaccessdeniedmessege() {

		system("cls");
		cout << "\a";
		cout << "\n---------------------------------------------\n";
		cout << "Access Denied,\n";
		cout << "You don't have premission to do this! \n";
		cout << "please contact your admin. \n";
		cout << "\n---------------------------------------------\n";
	}

	static void _ShowAllClientScreen() {
		if (clsReadpremission::checkaccesspremission(clsReadpremission::eshowclient)) {
			clsClientList::showlist();
		}
		else {

			showaccessdeniedmessege();
		}
	}

	static void _ShowAddClientScreen() {
		if (clsReadpremission::checkaccesspremission(clsReadpremission::eshowclient)) {
			clsAddClientScrren::AddClient();
		}
		else {
		showaccessdeniedmessege();
	    }
	}

	static void _ShowUpdateClientScreen() {
		if (clsReadpremission::checkaccesspremission(clsReadpremission::eupdateclient)) {
			clsUpdateClientScreen::UpdateClient();
		}
		else {
			showaccessdeniedmessege();
		}
	}

	static void _ShowDelleteClientScreen() {

		if (clsReadpremission::checkaccesspremission(clsReadpremission::edelleteclient)) {
			clsDelleteClientScreen::DelleteClient();
		}
		else {
			showaccessdeniedmessege();
		}
	
	}

	static void _ShowFindClientScreen() {
		if (clsReadpremission::checkaccesspremission(clsReadpremission::efindclient)) {
			clsFindClientScreen::findClientScreen();
		}
		else {
			showaccessdeniedmessege();
		}
	}

	static void _showTransactionScreen() {
		if (clsReadpremission::checkaccesspremission(clsReadpremission::etransaction)) {
			clsTransactionsScreen::ShowTransactionnMenu();
		}
		else {
			showaccessdeniedmessege();
		}
	}

	static void _sShowManageUserScreen() {
		/*if (clsReadpremission::checkaccesspremission(clsReadpremission::emanageuser)){*/
				clsManageUserScreen::showManageMenue();
		/*	}
		else {
			showaccessdeniedmessege();
		}*/
	}

	static void _logOut() {

		CurrentUser = clsBankUser::find("", "");
	}

	static void _ShowRegisterLoginScreen() {
		if (clsReadpremission::checkaccesspremission(clsReadpremission::eRegister)) {
			clsShowRegisterScreen::ShowRegisterLogin();
		}
		else {
			showaccessdeniedmessege();
		}

	}

	static void _performMainMenueOption(enoption option) {
		switch (option)
		{
		case clsMainScreen::showclinett:
			system("cls");
			_ShowAllClientScreen();
			_GobacktoMainUser();
			break;
		case clsMainScreen::addclinett:
			system("cls");
			_ShowAddClientScreen();
			_GobacktoMainUser();
			break;
		case clsMainScreen::deleteclinett:
			system("cls");
			_ShowDelleteClientScreen();
			_GobacktoMainUser();
			break;
		case clsMainScreen::updateclinett:
			system("cls");
			_ShowUpdateClientScreen();
			_GobacktoMainUser();
			break;
		case clsMainScreen::findclinett:
			system("cls");
			_ShowFindClientScreen();
			_GobacktoMainUser();
			break;
		case clsMainScreen::Transaction:
			system("cls");
			_showTransactionScreen();
			_GobacktoMainUser();
			break;
		case clsMainScreen::mangeuser:
			system("cls");
			_sShowManageUserScreen();
			_GobacktoMainUser();
			break;
		case clsMainScreen::registerlogin:
			system("cls");
			_ShowRegisterLoginScreen();
			_GobacktoMainUser();
		case clsMainScreen::logout:
			_logOut();
			break;
		default:
			break;
		}
	}

public:

	static void ShowMainMenu() {
		system("cls");
		clsScreen::DrawScreenheader("\tMain Menue");
		cout << setw(30) << left << "" << "----------------------------------------------------------------\n";
		cout << setw(30) << left << "" << "             main menue screen\n";
		cout << setw(30) << left << "" << "---------------------------------------------------------------\n";
		cout << setw(30) << left << "" << "          [1]show client list.\n";
		cout << setw(30) << left << "" << "          [2]add new client.\n";
		cout << setw(30) << left << "" << "          [3]delete client.\n";
		cout << setw(30) << left << "" << "          [4]update  client info.\n";
		cout << setw(30) << left << "" << "          [5]find client.\n";
		cout << setw(30) << left << "" << "          [6]Transactions.\n";
		cout << setw(30) << left << "" << "          [7]Manage Users.\n";
		cout << setw(30) << left << "" << "          [8]Show Register List.\n";
		cout << setw(30) << left << "" << "          [9]Logout.\n";
		cout << setw(30) << left << "" << "----------------------------------------------------------------\n";
		

		_performMainMenueOption(enoption(_ReadMainMenuOption()));

		
	}
	
};