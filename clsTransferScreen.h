#pragma once
#include<iostream>
#include"clsBankClient.h"
class clsTransferScreen
{
	static void _printClient(clsBankClient client) {
		cout << "\nClientCard:";
		cout << "\n__________________________\n";
		cout << "\nFull Name: " << client.Fullname();
		cout << "\nAccount Number: " << client.$accountNumber;
		cout << "\nAccount balance: " << client.$accountBalance;
		cout << "\n__________________________\n";
	}

	static string Readaccountnumber() {
		string AccountNumber = "";

		cout << "\nPlease enter Client Account Number: ";
		AccountNumber = clsInputValidate::ReadString();

		while (!clsBankClient::IsClientExist(AccountNumber)) {

			cout << "\nAccount Number Is not Found, Choose Another One:  ";
			AccountNumber = clsInputValidate::ReadString();
		}

		return AccountNumber;
	}

	static float ReadAmount(clsBankClient sourceClient) {
		float amount;
		do {
			cout << "\n\nplease enter your Transfer amount: ";
			amount = clsInputValidate::ReadDblNum();
			if (amount > sourceClient.$accountBalance) {
				cout << "\n\nYou have not enough balance , Your account balance is up to " << sourceClient.$accountBalance;
			}
		} while (amount > sourceClient.$accountBalance);

		return amount;
	}

	static void printalldataformStructfromvector(clsBankClient::sttransferdata x) {
		cout << "| " << left << setw(25) << x.Date;
		cout << "| " << left << setw(15) << x.sourceId;
		cout << "| " << left << setw(15) << x.destintionID;
		cout << "| " << left << setw(12) << x.amount;
		cout << "| " << left << setw(12) << x.sourcebalance;
		cout << "| " << left << setw(12) << x.destintionbalance;
		cout << "| " << left << setw(12) << x.userId;
	}
public:
	static void Transfer() {

		cout << "Source Client\n";
		cout << "______________________\n\n";

		clsBankClient SourceClient = clsBankClient::find(Readaccountnumber());

		_printClient(SourceClient);

		cout << "\n\nDestintion Client\n";
		cout << "______________________\n\n";

		clsBankClient DestintionClient = clsBankClient::find(Readaccountnumber());

		_printClient(DestintionClient);

		float amount = ReadAmount(SourceClient);

		cout << "\nAre You Sure You Need Do this Transfer:(y/n)?  ";
		char again = 'n';
		cin >> again;

		if (again == 'y' || again == 'Y') {
			if (clsBankClient::ManageTransfer(SourceClient,DestintionClient,amount)) {
				cout << "\nTransfer is Done Succesfully :-)\n";
			}
			else {
				cout << "\nTransfer is Not Success\n";
			}
		}
		_printClient(SourceClient);
		_printClient(DestintionClient);
	}

	static void ShowTransferLogin() {
		vector < clsBankClient::sttransferdata > vData = clsBankClient::LoadTransferLogData();

		clsScreen::DrawScreenheader("Transfer Login List Screen");

		cout << "\n\t\t\t\t\t\t\t (" << vData.size() << ") Transfer(s). ";
		cout << "\n---------------------------------------------------------";
		cout << "-------------------------------------------\n" << endl;
		cout << "| " << left << setw(25) << "Date-Time";
		cout << "| " << left << setw(15) << "Sender ID";
		cout << "| " << left << setw(15) << "Resever ID";
		cout << "| " << left << setw(12) << "Amount";
		cout << "| " << left << setw(12) << "SenderBalance";
		cout << "| " << left << setw(12) << "ReseverBalance";
		cout << "| " << left << setw(12) << "User";
		cout << "\n---------------------------------------------------------";
		cout << "-------------------------------------------\n" << endl;
		if (vData.size() == 0) {
			cout << "\nNo find Transfer";
		}
		for (clsBankClient::sttransferdata& x : vData) {
			printalldataformStructfromvector(x);
			cout << endl;
		}

		cout << "\n---------------------------------------------------------";
		cout << "-------------------------------------------\n" << endl;

	}
};

