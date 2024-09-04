#pragma once
#include<iostream>
#include"ClsString.h"
#include"clsScreen.h"
#include"clsGlobal.h"
class clsShowRegisterScreen
{
private:
	struct registerdata {
		string DateandTime;
		string id;
		string pass;
		string premission;
	};

	static registerdata converttostruct(string line) {
		vector<string>x = ClsString::split(line, "//#//");

		registerdata data;
		data.DateandTime = x[0];
		data.id = x[1];
		data.pass = clsUtil::Decryptztext(x[2],5);
		data.premission = x[3];

		return data;
	}

	static vector<registerdata>converttovector() {
		vector<registerdata>x;
		fstream myfile;
		myfile.open("logfile.txt", ios::in);
		string line;

		if (myfile.is_open()) {
			while (getline(myfile, line)) {
				x.push_back(converttostruct(line));
			}
		}
		myfile.close();
		return x;
	}
	static string _convertRegisterLogtoLine(string separator = "//#//") {
		clsDate date;
		string line;
		line += date.Stringtotext() + "-" + date.Time() + separator;
		line += CurrentUser.ID + separator;
		line += clsUtil::Encryptztext(CurrentUser.password,5) + separator;
		line += to_string(CurrentUser.$premission);

		return line;
	}

	vector<string>loadregisterdatatovector(string line, string separator = "//#//") {
		vector<string>x = ClsString::split(line, separator);
		return x;
	}
	static void printalldataformClassfromvector(registerdata& x) {
		cout << "| " << left << setw(20) << x.DateandTime;
		cout << "| " << left << setw(20) << x.id;
		cout << "| " << left << setw(24) << x.pass;
		cout << "| " << left << setw(12) << x.premission;
	}


	

public:
	static void _loaddatetologfile() {
		string s1 = _convertRegisterLogtoLine();

		fstream myfile;
		myfile.open("logfile.txt", ios::out | ios::app);

		if (myfile.is_open()) {
			myfile << s1 << endl;
		}
		myfile.close();
	}

	static void ShowRegisterLogin() {
		vector<registerdata>vData = converttovector();

		clsScreen::DrawScreenheader("Login Register List Screen");

		cout << "\n\t\t\t\t\t\t\t (" << vData.size() << ") Register(s). ";
		cout << "\n---------------------------------------------------------";
		cout << "-------------------------------------------\n" << endl;
		cout << "| " << left << setw(20) << "Date-Time";
		cout << "| " << left << setw(20) << "ID";
		cout << "| " << left << setw(24) << "Password";
		cout << "| " << left << setw(12) << "Premission";
		cout << "\n---------------------------------------------------------";
		cout << "-------------------------------------------\n" << endl;
		if (vData.size() == 0) {
			cout << "\nNo find Register";
		}
		for (registerdata& x : vData) {
			printalldataformClassfromvector(x);
			cout << endl;
		}

		cout << "\n---------------------------------------------------------";
		cout << "-------------------------------------------\n" << endl;

	}
};

