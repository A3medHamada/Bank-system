#pragma once
#include<iostream>
#include"clsInputValidate.h"
#include"clsBankClient.h"
using namespace std;
class clsFindClientScreen
{
public:
	static void findClientScreen() {
		clsScreen::DrawScreenheader("Find Client Screen");
		string AccountNumber = "";

		cout << "\nPlease enter Client Account Number: ";
		AccountNumber = clsInputValidate::ReadString();

		while (!clsBankClient::IsClientExist(AccountNumber)) {

			cout << "\nAccount Number Is not Found, Choose Another One:  ";
			AccountNumber = clsInputValidate::ReadString();
		}
		clsBankClient Client = clsBankClient::find(AccountNumber);
		Client.print();
	}
	
};

