#pragma once
#include<iostream>
#include"clsBankClient.h"
#include"clsClientList.h"
#include"clsScreen.h"
#include"clsTatalBalance.h"
#include"clsDepositeScreen.h"
#include"clsWithDrawScreen.h"
#include"clsTransferScreen.h"
using namespace std;
class clsTransactionsScreen
{
	
private:
	enum enTransactionOption {
		show = 1,
		deposite = 2,
		withdraw = 3,
		totalbalance = 4,
		etransfer=5,
		etransferLog=6,
		menue = 7
	};

	static short _ReadTransactionnOption() {

		cout << setw(30) << left << "" << "     choose what do you want to do[1 to 7] :";

		short option = clsInputValidate::ReadIntNumbetween(1, 7);
		return option;
	}

	static void _GobacktoMainUser() {
		cout << "\nenter any key to go back to main......";
		system("pause>0");
		system("color 0f");
		ShowTransactionnMenu();
	}

	static void _PerformTransactionOption(enTransactionOption option) {
		//clsMainScreen xx;
		switch (option)
		{
		case clsTransactionsScreen::show:
			system("cls");
			clsClientList::showlist();
			_GobacktoMainUser();
			break;
		case clsTransactionsScreen::deposite:
			system("cls");
			clsDepositeScreen::deposite();
			_GobacktoMainUser();
			break;
		case clsTransactionsScreen::withdraw:
			system("cls");
			clsWithDrawSreen::WithDraw();
			_GobacktoMainUser();
			break;
		case clsTransactionsScreen::totalbalance:
			system("cls");
			clsTatalBalance::printtotalbalance();
			_GobacktoMainUser();
			break;
		case clsTransactionsScreen::etransfer:
			system("cls");
			clsTransferScreen::Transfer();
			_GobacktoMainUser();
		case clsTransactionsScreen::etransferLog:
			system("cls");
			clsTransferScreen::ShowTransferLogin();
			_GobacktoMainUser();
		case clsTransactionsScreen::menue:
		//	xx.ShowMainMenu();
			break;
		default:
			break;
		}
	}

public:
	
	static void ShowTransactionnMenu() {
		system("cls");
		clsScreen::DrawScreenheader("  Transaction Screen");

		cout << setw(30) << left << "" << "          \tTransaction Menu Screen\n";
		cout << setw(30) << left << "" << "================================================================\n";
		cout << setw(30) << left << "" << "================================================================\n";
		cout << setw(30) << left << "" << "         [1] show client list\n";
		cout << setw(30) << left << "" << "         [2] Deposite\n";
		cout << setw(30) << left << "" << "         [3] Withdraw\n";
		cout << setw(30) << left << "" << "         [4] Total Balances\n";
		cout << setw(30) << left << "" << "         [5] Transfer\n";
		cout << setw(30) << left << "" << "         [6] Transfer Log\n";
		cout << setw(30) << left << "" << "         [7] Main Menu\n";
		cout << setw(30) << left << "" << "================================================================\n";
		
		_PerformTransactionOption(enTransactionOption(_ReadTransactionnOption()));
	}

	
};

