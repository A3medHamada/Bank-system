#pragma once
#include<iostream>
#include"clsBankClient.h"
#include"clsScreen.h"
using namespace std;
class clsTatalBalance:protected clsScreen
{
private:
	static void printdataBalanceformClassfromvector(clsBankClient Client) {

		cout << "| " << left << setw(15) << Client.$accountNumber;
		cout << "| " << left << setw(20) << Client.Fullname();
		cout << "| " << left << setw(12) << Client.$accountBalance;

	}
public:
	static void printtotalbalance() {
		vector<clsBankClient>vData = clsBankClient::GetClientList();

		DrawScreenheader("   Blance list screen", to_string(vData.size()) + " Client(s)");

		cout << "\n\t\t\t\t\t Client List (" << vData.size() << ") Client(s). ";
		cout << "\n---------------------------------------------------------";
		cout << "-------------------------------------------\n" << endl;
		cout << "| " << left << setw(15) << "Account Number";
		cout << "| " << left << setw(20) << "Client Name";
		cout << "| " << left << setw(12) << "Balance ";
		cout << "\n---------------------------------------------------------";
		cout << "-------------------------------------------\n" << endl;
		double totalbalance = clsBankClient::ToTalBalance();
		if (vData.size() == 0) {
			cout << "\nNo find Client";
		}
		for (clsBankClient& x : vData) {
			printdataBalanceformClassfromvector(x);
			cout << endl;
		}
		cout << "\n---------------------------------------------------------";
		cout << "-------------------------------------------\n" << endl;

		cout << "                      Total Balance: " << totalbalance << endl;
		cout << "                         (" << clsUtil::NumberToText(totalbalance) << ")";

		

	}
};

