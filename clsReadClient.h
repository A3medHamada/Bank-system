#pragma once
#include<iostream>
#include"clsBankClient.h"
using namespace std;
class clsReadClient
{
public:
	static void ReadClient(clsBankClient& clientt) {

		cout << "\nplease enter First Name : ";
		clientt.$FirstName = clsInputValidate::ReadString();

		cout << "\nplease enter Last Name : ";
		clientt.$LastName = clsInputValidate::ReadString();

		cout << "\nplease enter Email : ";
		clientt.$Email = clsInputValidate::ReadString();

		cout << "\nplease enter phone : ";
		clientt.$Phone = clsInputValidate::ReadString();

		cout << "\nplease enter pincode : ";
		clientt.$pinCode = clsInputValidate::ReadString();

		cout << "\nplease enter Salary : ";
		clientt.$accountBalance = clsInputValidate::readfloatnum();
	}
};

