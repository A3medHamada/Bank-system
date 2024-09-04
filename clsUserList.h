#pragma once
#include<iostream>
#include"clsBankUser.h"
using namespace std;
class clsUserList
{
private:
	static void printalldataformClassfromvector(clsBankUser User) {

		cout << "| " << left << setw(15) << User.ID;
		cout << "| " << left << setw(20) << User.Fullname();
		cout << "| " << left << setw(24) << User.$Email;
		cout << "| " << left << setw(12) << User.$Phone;
		cout << "| " << left << setw(10) << User.password;
		cout << "| " << left << setw(12) << User.$premission;

	}


public:

	static void showlist() {
		vector<clsBankUser>vData = clsBankUser::GetUserList();

		clsScreen::DrawScreenheader("Show User List Screen");

		cout << "\n\t\t\t\t\t User List (" << vData.size() << ") User(s). ";
		cout << "\n---------------------------------------------------------";
		cout << "-------------------------------------------\n" << endl;
		cout << "| " << left << setw(15) << "Id";
		cout << "| " << left << setw(20) << "Client Name";
		cout << "| " << left << setw(24) << "Email";
		cout << "| " << left << setw(12) << "Phone ";
		cout << "| " << left << setw(10) << "PAssword";
		cout << "| " << left << setw(12) << "Premission ";
		cout << "\n---------------------------------------------------------";
		cout << "-------------------------------------------\n" << endl;
		if (vData.size() == 0) {
			cout << "\nNo User Client";
		}
		for (clsBankUser& x : vData) {
			printalldataformClassfromvector(x);
			cout << endl;
		}

		cout << "\n---------------------------------------------------------";
		cout << "-------------------------------------------\n" << endl;

	}
	
};

