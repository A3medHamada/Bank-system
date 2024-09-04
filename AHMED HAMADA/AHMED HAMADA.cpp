#pragma once
#include<iostream>
#include<string>
#include<vector>
#include"clsDate.h"
using namespace std;
int main() {
	clsDate date1;
	clsDate date2("1/1/2024");
	clsDate date3(5, 3, 2024);
	clsDate date4(150, 2024);

	date1.print();
	date2.print();
	date3.print();
	date4.print();

	//date1.PrintCalendarYear();

	date1.GetDateFromDayOrderInYear(2024, 70);

	cout<<clsDate::DayNameOfWeek(clsDate("1/1/2024"));
}