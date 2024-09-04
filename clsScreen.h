#pragma once
#include"clsDate.h"
#include"clsGlobal.h"
#include<iostream>

using namespace std;
class clsScreen
{
public:

	

	static void DrawScreenheader(string Title,string suptitle="") {
		cout << "\t\t\t\t\t___________________________________________";

		cout << "\n\n\t\t\t\t\t\t " << Title;

		if (suptitle != "") {
			cout << "\n\t\t\t\t\t\t\t " << suptitle;
		}
		cout << "\n\t\t\t\t\t___________________________________________\n\n";

		cout << "\t\t\t\t\tID: " << CurrentUser.ID << endl;

		clsDate x;

		cout << "\t\t\t\t\tDate: ";
		x.print();
	}

	
};

