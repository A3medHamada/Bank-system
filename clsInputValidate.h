#pragma once
#include<iostream>
#include"ClsString.h"
#include"clsDate.h"
using namespace std;
class clsInputValidate
{
public:
	static bool IsNumberBetween(short num, short from, short to) {
		if (num >= from && num <= to) {
			return true;
		}
		return false;
	}

	static bool IsNumberBetween(int num, int from, int to) {
		if (num >= from && num <= to) {
			return true;
		}
		return false;
	}

	static bool IsNumberBetween(float num, float from, float to) {
		if (num >= from && num <= to) {
			return true;
		}
		return false;
	}

	static bool IsNumberBetween(double num, double from, double to) {
		if (num >= from && num <= to) {
			return true;
		}
		return false;
	}

	static bool IsDateBetween(clsDate date,clsDate dateFrom, clsDate dateTo) {
		if (clsDate::IsDateAfterDate2(dateFrom, dateTo)) {
			clsDate::SwapDates(dateFrom, dateTo);
		}

		if (clsDate::IsDateAfterDate2(date, dateTo) || clsDate::IsDateBeforDate2(date, dateFrom)) {
			return false;
		}

		return true;
	}

	static int ReadIntNum(string errorMessege="Invalid Number, Enter again\n") {
		int num;
		while (!(cin >> num)) {
			cin.clear();
			cin.ignore(numeric_limits<streamsize>::max(), '\n');

			cout << errorMessege;
		}
		return num;
	}

	static int ReadIntNumbetween(int from,int to,string errorMessege = "Invalid Number, Enter again\n") {

		int num = ReadIntNum();
		while (!IsNumberBetween(num,from,to)) {
			cout << errorMessege;
			
			num = ReadIntNum();
		}
		return num;
	}

	static double ReadDblNum(string errorMessege = "Invalid Number, Enter again\n") {
		double num;

		while (!(cin >> num)) {
			cin.clear();
			cin.ignore(numeric_limits<streamsize>::max(), '\n');

			cout << errorMessege;
		}
		return num;
	}

	static double ReadIntNumbetween(double from, double to, string errorMessege = "Invalid Number, Enter again\n") {

		double num = ReadDblNum();
		while (!IsNumberBetween(num, from, to)) {
			cout << errorMessege;

			num = ReadDblNum();
		}
		return num;
	}

	static bool IsValidateDate(clsDate x) {
		return clsDate::IsValideDate(x);
	}

	static string ReadString() {
		string x;
		getline(cin >>ws, x);

		return x;
	}

	static float readfloatnum() {
		float x=0;
		cin >> x;
		return x;
	}
};

