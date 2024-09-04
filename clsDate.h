#pragma once
#pragma warning (disable : 4996)
#include<iostream>
#include<ctime>
#include<string>
#include<vector>
#include"clsString.h"
#include<iomanip>
using namespace std;
class clsDate
{
private:
	
		int _day;
		int _month;
		int _year;

public:
	clsDate() {
		time_t t = time(0);
		tm* now = localtime(&t);

		_year = now->tm_year + 1900;
		_month = now->tm_mon + 1;
		_day = now->tm_mday;
	}
	clsDate(string date) {
		vector<string> x;

		x = ClsString::split(date, "/");
		_day = stoi(x[0]);
		_month = stoi(x[1]);
		_year = stoi(x[2]);
	}
	clsDate(int day, int month, int year) {
		_day = day;
		_month = month;
		_year = year;
	}
	clsDate(int days, int year) {

		GetDateFromDayOrderInYear(year, days);
		
	}

	 void print() {
		 cout << to_string(_day) << "/" << to_string(_month) << "/" <<to_string(_year)<<endl;

	}

	 string Stringtotext() {
		 return to_string(_day) +"/"+  to_string(_month) + "/" + to_string(_year);
	 }
	static string Time() {
		time_t t = time(0); // get time now
		// يحتوي على العناصر التي بالأسفل struct هو tm* now
		tm* now = localtime(&t);
		return to_string(now->tm_hour)+":"+ to_string(now->tm_min) + ":"+  to_string(now->tm_sec);
	 }
	static bool IsLeapYear(short year)
	{
		return year % 4 == 0 && (year % 100 != 0 || year % 400 == 0) ? true : false;
	}

	bool IsLeapYear() {
		IsLeapYear(_year);
	}

	static short NumberOfDaysInMonth(short Year, short Month)
	{
		if (Month < 1 || Month > 12)
		{
			return 0;
		}
		short NumberOfDays[12] = { 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };
		return (Month == 2) ? (IsLeapYear(Year) ? 29 : 28) : NumberOfDays[Month - 1];
	}

	 void GetDateFromDayOrderInYear(short Year, short DateOrderInYear)
	{
		short RemainingDays = DateOrderInYear;
		short MonthDays = 0;
		_year = Year;
		_month = 1;
		while (true)
		{
			MonthDays = NumberOfDaysInMonth(Year,_month);
			if (RemainingDays > MonthDays)
			{
				RemainingDays = RemainingDays - MonthDays;
				_month++;
			}
			else
			{
				_day = RemainingDays;
				break;
			}
		}

		print();
	}


	static short NumbersOfDaysInMonth(short Year, short Month) {
		 if (Month < 1 || Month > 12) 
		 {
			 return 0; }

		 short DeysInMonth[12] = { 31,28,31,30,31,30,31,31,30,31,30,31 };
		 return (Month == 2) ? (IsLeapYear(Year) ? 29 : 28) : DeysInMonth[Month - 1]; 
	}

	short NumbersOfDaysInMonth() {
		NumbersOfDaysInMonth(_year, _month);
	}

	static string DayNameOfWeek(clsDate date)
	{
		short a = ((14 - date._month) / 12);
		short y = date._year - a;
		short m = date._month + (12 * a) - 2;
		// For the Greforian Calendar:
		short d = (date._day + y + (y / 4) - (y / 100) + (y / 400) + ((31 * m) / 12)) % 7;

		string DayName[7] = { "Sun", "Mon", "Tue", "Wed", "Thu", "Fri", "Sat" };
		return DayName[d];
		// The value of d is 0 for a Sunday, 1 for a Monday, 2 for a Tuesday etc..
	}
	
	string DayNameOfWeek() {
		DayNameOfWeek(*this);
	}

	static short DayNumberOfWeek(clsDate& date)
	{
		short a = ((14 - date._month) / 12);
		short y = date._year - a;
		short m = date._month + (12 * a) - 2;
		// For the Greforian Calendar:
		short d = (date._day + y + (y / 4) - (y / 100) + (y / 400) + ((31 * m) / 12)) % 7;
		return d;
		// The value of d is 0 for a Sunday, 1 for a Monday, 2 for a Tuesday etc..
	}

	static string ShortNameForMonth(short Month)
	{
		string ShortName[] = { "Jan", "Feb", "Mar", "Apr", "May", "Jun", "Jul", "Aug", "Sept", "Oct", "Nov", "Dec" };
		return ShortName[Month - 1];
	}

	string ShortNameForMonth() {
		ShortNameForMonth(_month);
	}

	static string ShortNameForDay(short Day)
	{
		string ShortName[] = { "Sun", "Mon", "Tue", "Wed", "Thu", "Fri", "Sat" };
		return ShortName[Day - 1];
	}

	static void PrintMonthCalendar(clsDate& date)
	{
		short y = date._day;
		short m = date._month;
		short ND = NumbersOfDaysInMonth(y, m);
		short current = DayNumberOfWeek(date);
		string MN = ShortNameForMonth(m);
		cout << "\n\t_________________";
		cout << MN;
		cout << "_________________\n\n";
		cout << "\t";
		for (short i = 1; i <= 7; i++)
		{
			cout << setw(5) << ShortNameForDay(i);
		}
		cout << endl;
		short k = 0;
		cout << "\t";
		for (k = 0; k < current; k++)
		{
			cout << " ";
		}
		for (short j = 1; j <= ND; j++)
		{
			cout << setw(5) << j;
			if (++k > 6)
			{
				k = 0;
				cout << endl;
				cout << "\t";
			}
		}
		cout << "\n\t_____________________________________\n\n";
	}

	void PrintMonthCalendar() {
		PrintMonthCalendar(*this);
	}
	
	static void PrintCalendarYear(clsDate& date)
	{
		short y = date._year;
		cout << "\n\t=====================================\n";
		cout << "\t Calendar - " << y;
		cout << "\n\t=====================================\n";
		for (short i = 1; i <= 12; i++)
		{
			 PrintMonthCalendar(date);
		}
	}

	void PrintCalendarYear() {
		PrintCalendarYear(*this);
	}

	static short NumberOfDaysFromTheBeginingOfTheYear(clsDate date)
	{
		short TotalDays = 0;
		for (short i = 1; i <= date._month - 1; i++)
		{
			TotalDays += NumberOfDaysInMonth(date._year, i);
		}
		TotalDays += date._day;
		return TotalDays;
	}

	static bool IsValideDate(clsDate Date)
	{
		return Date._day > 0 && Date._day <= (NumberOfDaysInMonth(Date._year, Date._month));
	}

	static void SwapDates(clsDate& Date1, clsDate& Date2)
	{
		clsDate TampDate;
		TampDate._day = Date1._day;
		TampDate._month = Date1._month;
		TampDate._year = Date1._year;
		Date1._day = Date2._day;
		Date1._month = Date2._month;
		Date1._year = Date2._year;
		Date2._day = TampDate._day;
		Date2._month = TampDate._month;
		Date2._year = TampDate._year;
	}

	static bool IsDateBeforDate2(clsDate Date1, clsDate Date2)
	{
		return (Date1._year < Date2._year) ? true : ((Date1._year == Date2._year) ? (Date1._month < Date2._month ? true : (Date1._month == Date2._month ? Date1._day < Date2._day : false)) : false);
	}

	static bool IsDateAfterDate2(clsDate Date1, clsDate Date2)
	{
		return (Date1._year > Date2._year) ? true : ((Date1._year == Date2._year) ? (Date1._month > Date2._month ? true : (Date1._month == Date2._month ? Date1._day > Date2._day : false)) : false);
	}


};

