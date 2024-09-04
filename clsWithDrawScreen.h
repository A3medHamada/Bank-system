#pragma once
#pragma once
#include"iostream"
#include"clsBankClient.h"
#include"clsInputValidate.h"
using namespace std;
class clsWithDrawSreen
{
public:
	static void WithDraw() {

		clsScreen::DrawScreenheader("Show WithDraw List Screen");

		string Accountnumber = "";
		cout << "\nPlease enter Client Account Number: ";
		Accountnumber = clsInputValidate::ReadString();
		while (!clsBankClient::IsClientExist(Accountnumber)) {
			cout << "\nAccount Number Is not Found, Choose Another One:  ";
			Accountnumber = clsInputValidate::ReadString();
		}
		clsBankClient Client = clsBankClient::find(Accountnumber);

		Client.print();
		double WithDrawnum;
		do{
		cout << "\n\nplease enter your drawback amount: ";
		WithDrawnum = clsInputValidate::ReadDblNum();
		if (WithDrawnum > Client.$accountBalance) {
			cout << "\n\nYou have not enough balance , Your account balance is up to " << Client.$accountBalance;
		}
		} while (WithDrawnum > Client.$accountBalance);


		cout << "\n\nAre you sure you want this transection ? n/y ?";
		char Answer; cin >> Answer;

		if (Answer == 'y' || Answer == 'Y') {

			Client.$accountBalance -= WithDrawnum;
		}
		clsBankClient::enSave result;

		result = Client.save();

		switch (result)
		{
		case clsBankClient::enSave::sucess:
			cout << "\nTransaction Updated Sucessfully:-)\n";
			Client.print();
			break;
		case clsBankClient::enSave::failedEmpty:
			cout << "\nError Transaction not Saved because Account numberis Empty";
			break;
		default:
			break;
		}
	}
};

