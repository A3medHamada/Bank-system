#pragma once
#include"clsBankClient.h"
class clsDelleteClientScreen
{
public:
	static void DelleteClient() {
		clsScreen::DrawScreenheader("Dellete Client Screen");
		string AccountNumber = "";

		cout << "\nPlease enter Client Account Number: ";
		AccountNumber = clsInputValidate::ReadString();

		while (!clsBankClient::IsClientExist(AccountNumber)) {

			cout << "\nAccount Number Is not Found, Choose Another One:  ";
			AccountNumber=clsInputValidate::ReadString();
		}
		clsBankClient Client = clsBankClient::find(AccountNumber);
		Client.print();

		char again = 'n';
		cout << "\nAre You Sure You Need Dellete this Client:(y/n)?  ";
		cin >> again;

		if (again == 'y' || again == 'Y') {
			if (Client.Dellete()) {
				cout << "\nClient is Delleted Succesfully :-)\n";
			}
			else {
				cout << "\nClient Is not Delleted";
			}
		}

	}
};

