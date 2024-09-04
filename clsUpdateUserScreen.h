#pragma once
#include<iostream>
#include"clsBankUser.h"
#include"clsReadUser.h"
using namespace std;
class clsUpdateUserScreen
{
public:
	 static void UpdateUser() {
		 clsScreen::DrawScreenheader("Update User Screen");
		string Id = "";

		cout << "\nPlease enter Client Account Number: ";
		Id = clsInputValidate::ReadString();

		while (!clsBankUser::IsExistUser(Id)) {

			cout << "\nAccount Number Is not Found, Choose Another One:  ";
			Id = clsInputValidate::ReadString();
		}
		clsBankUser User = clsBankUser::find(Id);
		User.print();
		cout << "\n\nUpdate Client Info: ";
		cout << "\n_________________________________\n";

		clsReadUser::ReadUser(User);

		clsBankUser::enSave result;
		result = User.save();
		switch (result)
		{
		case clsBankUser::enSave::sucess:
			cout << "\nUserr Updated Sucessfully:-)\n";
			User.print();
			break;
		case clsBankUser::enSave::failedEmpty:
			cout << "\nError User not Saved because it's Empty";
			break;
		default:
			break;
		}
		
	}
};

