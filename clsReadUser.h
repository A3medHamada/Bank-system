#pragma once
#include<iostream>
#include"clsBankUser.h"
#include"clsReadpremission.h"
using namespace std;
class clsReadUser
{
public:
	static void ReadUser(clsBankUser& User) {

		cout << "\nplease enter First Name : ";
		User.$FirstName = clsInputValidate::ReadString();

		cout << "\nplease enter Last Name : ";
		User.$LastName = clsInputValidate::ReadString();

		cout << "\nplease enter Email : ";
		User.$Email = clsInputValidate::ReadString();

		cout << "\nplease enter phone : ";
		User.$Phone = clsInputValidate::ReadString();

		cout << "\nplease enter Password : ";
		User.password = clsInputValidate::ReadString();

		User.$premission =clsReadpremission::readpremission();
	}
};

