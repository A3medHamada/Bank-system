#pragma once
#include<iostream>
#include"clsBankUser.h"
class clsFindUserScreen
{
public:
	static void findClientScreen() {
		clsScreen::DrawScreenheader("Find User Screen");
		string AccountNumber = "";

		cout << "\nPlease enter Client Account Number: ";
		AccountNumber = clsInputValidate::ReadString();

		while (!clsBankUser::IsExistUser(AccountNumber)) {

			cout << "\nAccount Number Is not Found, Choose Another One:  ";
			AccountNumber = clsInputValidate::ReadString();
		}
		clsBankUser Client = clsBankUser::find(AccountNumber);
		Client.print();
		
	}
};

