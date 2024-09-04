#pragma once
#include<iostream>
using namespace std;
class clsperson {
private:

	string _firstname;
	string _lastname;
	string _email;
	string _phone;



public:
	clsperson( string firstname, string lastname, string email, string phone) {
		
		_firstname = firstname;
		_lastname = lastname;
		_email = email;
		_phone = phone;
	}
	
	void setfirstname(string Firstname) {
		_firstname = Firstname;
	}
	string firstname() {
		return _firstname;
	}

	_declspec(property (get = firstname, put = setfirstname))string $FirstName;

	void setlastname(string Lastname) {
		_lastname = Lastname;
	}
	string lastname() {
		return _lastname;
	}

	_declspec(property (get = lastname, put = setlastname))string $LastName;
	void setemail(string Email) {
		_email = Email;
	}
	string email() {
		return _email;
	}

	_declspec(property (get = email, put = setemail))string $Email;
	void setphone(string Phone) {
		_phone = Phone;
	}
	string phone() {
		return _phone;
	}
	string Fullname() {
		string full = _firstname + " " + _lastname;
		return full;
	}
	_declspec(property (get = phone, put = setphone))string $Phone;
	void print() {
		cout << "\nBody: \n";
		cout << "------------------------------\n";
		cout << "\nFirst Name: " << _firstname << endl;
		cout << "\nLast Name: " << _lastname << endl;
		cout << "\nFull Name: " << _firstname << " " << _lastname << endl;
		cout << "\nEmail: " << _email << endl;
		cout << "\nPhone: " << _phone << endl;
		cout << "\n------------------------------\n";

	}

	void messege(string subject, string messege) {
		cout << "\nThe following message sent successfully to email : " << _email << endl;
		cout << "\nSubject: " << subject << endl;
		cout << "\nbody: " << messege << endl;
	}

	void sms(string sms) {
		cout << "\n________________________________\n";
		cout << "\nThe following SMS sent successfully to phone : " << _phone;
		cout << endl << sms;
	}
};

