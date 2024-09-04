#pragma once
#include<iostream>
#include"clsBankClient.h"
#include"clsReadClient.h"
class clsUpdateClientScreen
{
public:
	static void UpdateClient() {
		clsScreen::DrawScreenheader("Update Client Screen");
		string AccountNumber = "";

		cout << "\nPlease enter Client Account Number: ";
		AccountNumber = clsInputValidate::ReadString();

		while (!clsBankClient::IsClientExist(AccountNumber)) {

			cout << "\nAccount Number Is not Found, Choose Another One:  ";
			clsInputValidate::ReadString();
		}
		clsBankClient Client = clsBankClient::find(AccountNumber);
		Client.print();

		cout << "\n\nUpdate Client Info: ";
		cout << "\n_________________________________\n";

		clsReadClient::ReadClient(Client);

		clsBankClient::enSave result;
		result = Client.save();
		switch (result)
		{
		case clsBankClient::enSave::sucess:
			cout << "\nAccount Updated Sucessfully:-)\n";
			Client.print();
			break;
		case clsBankClient::enSave::failedEmpty:
			cout << "\nError Account not Saved because it's Empty";
			break;
		default:
			break;
		}

	}
};

