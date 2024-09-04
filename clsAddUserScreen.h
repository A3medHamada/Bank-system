#pragma once
#include<iostream>
#include"clsBankUser.h"
#include"clsReadUser.h"
#include"clsScreen.h"
using namespace std;
class clsAddUserScrren
{

public:
	static void AddUser() {
		clsScreen::DrawScreenheader("Add User Screen");
		string Id = "";
		cout << "Please Enter AccountNumber: ";
		Id = clsInputValidate::ReadString();
		while (clsBankUser::IsExistUser(Id))
		{
			cout << "\nID Is not Found, Choose Another One:  ";
			Id = clsInputValidate::ReadString();
		}
		clsBankUser User = clsBankUser::GetNewUser(Id);

		clsReadUser::ReadUser(User);

		clsBankUser::enSave saveresult;

		saveresult = User.save();

		switch (saveresult)
		{
		case clsBankUser::failedEmpty:
			cout << "\nErroe Account not Added Because it's Empty\n";
			break;
		case clsBankUser::sucess:
			cout << "\nAccount Added Succesfully:-)\n";
			User.print();
			break;
		case clsBankUser::FalidAccountExist:
			cout << "\nErroe Account not Added Because Account number is Exist\n";
			break;
		default:
			break;
		}

	}

};
