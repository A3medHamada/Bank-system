#pragma once
#include<iostream>
#include"clsBankUser.h"
using namespace std;
class clsDelleteUserScreen
{
public:
	static void DelleteClient() {
		clsScreen::DrawScreenheader("Dellete User Screen");
		string ID = "";

		cout << "\nPlease enter User Id: ";
		ID = clsInputValidate::ReadString();

		while (!clsBankUser::IsExistUser(ID)) {

			cout << "\nID Is not Found, Choose Another One:  ";
			ID = clsInputValidate::ReadString();
		}
		clsBankUser User = clsBankUser::find(ID);
		User.print();

		char again = 'n';
		cout << "\nAre You Sure You Need Dellete this User:(y/n)?  ";
		cin >> again;

		if (again == 'y' || again == 'Y') {
			if (User.Dellete()) {
				cout << "\nUser is Delleted Succesfully :-)\n";
			}
			else {
				cout << "\nUser Is not Delleted";
			}
		}

	}
};

