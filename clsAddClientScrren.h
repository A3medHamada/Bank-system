#pragma once
#include<iostream>
#include"clsBankClient.h"
#include"clsReadClient.h"
#include"clsScreen.h"
class clsAddClientScrren
{

public:
	static void AddClient() {
		clsScreen::DrawScreenheader("Add Client Screen");
		string AccountNumber = "";
		cout << "Please Enter AccountNumber: ";
		AccountNumber = clsInputValidate::ReadString();
		while (clsBankClient::IsClientExist(AccountNumber))
		{
			cout << "\nAccount Number Is not Found, Choose Another One:  ";
			AccountNumber = clsInputValidate::ReadString();
		}
		clsBankClient client = clsBankClient::GetNewCLient(AccountNumber);

		clsReadClient::ReadClient(client);

		clsBankClient::enSave saveresult;

		saveresult = client.save();

		switch (saveresult)
		{
		case clsBankClient::failedEmpty:
			cout << "\nErroe Account not Added Because it's Empty\n";
			break;
		case clsBankClient::sucess:
			cout << "\nAccount Added Succesfully:-)\n";
			client.print();
			break;
		case clsBankClient::FalidAccountExist:
			cout << "\nErroe Account not Added Because Account number is Exist\n";
			break;
		default:
			break;
		}

	}

};

