#pragma once
#include<iostream>
#include"clsBankClient.h"
#include"clsScreen.h"
using namespace std;
class clsClientList
{
private:
	static void printalldataformClassfromvector(clsBankClient Client) {

		cout << "| " << left << setw(15) << Client.$accountNumber;
		cout << "| " << left << setw(20) << Client.Fullname();
		cout << "| " << left << setw(24) << Client.$Email;
		cout << "| " << left << setw(12) << Client.$Phone;
		cout << "| " << left << setw(10) << Client.$pinCode;
		cout << "| " << left << setw(12) << Client.$accountBalance;

	}


public:

	static void showlist() {
		vector<clsBankClient>vData = clsBankClient::GetClientList();

		clsScreen::DrawScreenheader("Show Client List Screen");

		cout << "\n\t\t\t\t\t Client List (" << vData.size() << ") Client(s). ";
		cout << "\n---------------------------------------------------------";
		cout << "-------------------------------------------\n" << endl;
		cout << "| " << left << setw(15) << "Account Number";
		cout << "| " << left << setw(20) << "Client Name";
		cout << "| " << left << setw(24) << "Email";
		cout << "| " << left << setw(12) << "Phone ";
		cout << "| " << left << setw(10) << "Pin Code ";
		cout << "| " << left << setw(12) << "Balance ";
		cout << "\n---------------------------------------------------------";
		cout << "-------------------------------------------\n" << endl;
		if (vData.size() == 0) {
			cout << "\nNo find Client";
		}
		for (clsBankClient& x : vData) {
			printalldataformClassfromvector(x);
			cout << endl;
		}

		cout << "\n---------------------------------------------------------";
		cout << "-------------------------------------------\n" << endl;

	}
	
};

