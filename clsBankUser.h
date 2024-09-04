#pragma once
#include<iostream>
#include"clsInputValidate.h"
#include"clsUtil.h"
#include"clsPerson.h"
#include"ClsString.h"
#include<fstream>
using namespace std;
class clsBankUser :public clsperson
{
private:

	enum _enmode {
		EmptyMode,
		UpdatedMode,
		AddMode
	};
	_enmode _mode;

	string _Id = "";
	string _Password = "";
	int _premission=0;
	bool _MarkedforDellete = false;

	static clsBankUser _ConvertLineToObject(string line,string separator="//#//") {
		vector<string>x;
		x = ClsString::split(line,separator);

		return clsBankUser(_enmode::UpdatedMode,x[0], x[1], x[2], x[3], x[4],clsUtil::Decryptztext(x[5],5),stoi(x[6]));
	}


	static clsBankUser _GetEmetyUserObject() {

		return clsBankUser(_enmode::EmptyMode, "", "", "", "", "", "",0);
	}


	static vector<clsBankUser> _loadDatafromFiletoVector() {
		vector<clsBankUser>x;
		fstream myfile;
		string line;

		myfile.open("BankUser.txt", ios::in);

		if (myfile.is_open()) {

			while (getline(myfile, line)) {

				clsBankUser cls = _ConvertLineToObject(line);

				x.push_back(cls);
			}
		}
		myfile.close();

		return x;
	}

	static string _ConvertObjecttoLine(clsBankUser x, string separator = "//#//") {
		string line;
		line += x.firstname() + separator;
		line += x.lastname() + separator;
		line += x.email() + separator;
		line += x.phone() + separator;
		line += x._Id + separator;
		line += clsUtil::Encryptztext(x._Password,5) + separator;
		line +=to_string( x._premission);

		return line;
	}

	static void _SaveUserDatatoFile(vector<clsBankUser>vUser) {
		fstream myfile;
		string line;
		myfile.open("BankUser.txt", ios::out);

		if (myfile.is_open()) {

			for (clsBankUser& x : vUser) {
				if (x.MarkedForDelleted() == false) {
					line = _ConvertObjecttoLine(x);

					myfile << line << endl;
				}
			}
		}
		myfile.close();
	}

	

	void _Update() {
		vector<clsBankUser>x = _loadDatafromFiletoVector();
		fstream myfile;
		myfile.open("BankUser.txt", ios::out | ios::app);
		if (myfile.is_open()) {
			for (clsBankUser& z : x) {
				if (z._Id == _Id) {
					z = *this;
				}
			}

			_SaveUserDatatoFile(x);

		}

	}

	void _AddNew() {
		string line;
		line = _ConvertObjecttoLine(*this);
		fstream myfile;

		myfile.open("BankUser.txt", ios::out | ios::app);

		if (myfile.is_open()) {
			myfile << line << endl;
		}


	}
public:
	clsBankUser(_enmode mode,string firstname, string lastname, string email, string phone, string id, string password,int premission)
		:clsperson(firstname, lastname, email, phone) {

		_mode = mode;
		_Id = id;
		_Password = password;
		_premission = premission;
	}
	bool MarkedForDelleted() {
		return _MarkedforDellete;
	}
	void setpassword(string password) {
		_Password = password;
	}

	string getpassword() {
		return _Password;
	}
	_declspec(property(get = getpassword, put = setpassword))string password;

	string getId() {
		return _Id;
	}
	_declspec(property(get = getId))string ID;

	void setpremission(int premission) {
		_premission = premission;
	}

	int getpremission() {
		return _premission;
	}
	_declspec(property(get = getpremission,put=setpremission))int $premission;


	static clsBankUser find(string id) {
		vector<clsBankUser>x = _loadDatafromFiletoVector();
		for (clsBankUser& z : x) {
			if (z._Id == id) {
				return z;
			}
		}
		return _GetEmetyUserObject();
	}

	static clsBankUser find(string id,string password) {
		vector<clsBankUser>x = _loadDatafromFiletoVector();
		for (clsBankUser& z : x) {
			if (z._Id == id && z.password==password) {
				return z;
			}
		}
		return _GetEmetyUserObject();
	}
	 
	bool Dellete() {
		vector<clsBankUser>x;
		x = _loadDatafromFiletoVector();
		for (clsBankUser& z : x) {

			if (z.ID == _Id) {
				z._MarkedforDellete = true;
				break;
			}

		}

		_SaveUserDatatoFile(x);
		*this = _GetEmetyUserObject();
		return true;
	}
	 void print() {
		cout << "------------------------------\n";
		cout << left << setw(15) << "\nFirst Name: " << firstname() << endl;
		cout << left << setw(15) << "\nLast Name: " << lastname() << endl;
		cout << left << setw(15) << "\nFull Name: " << firstname() << " " << lastname() << endl;
		cout << left << setw(15) << "\nEmail: " << email() << endl;
		cout << left << setw(15) << "\nPhone: " << phone() << endl;
		cout << left << setw(15) << "\nID: " << _Id << endl;
		cout << left << setw(15) << "\nPassword: " << _Password << endl;
		cout << left << setw(15) << "\nPremission: " << _premission << endl;
		cout << left << setw(15) << "\n------------------------------\n";
	}
	 
	 static bool Isempty(clsBankUser user) {
		 if (user._mode == _enmode::EmptyMode) {
			 return true;
		 }
		 return false;
	 }

	 static bool IsExistUser(string Accountnumber) {
		 clsBankUser User = User.find(Accountnumber);

		 return(!Isempty(User));
	 }

	 enum enSave {
		 failedEmpty = 0,
		 sucess = 1,
		 FalidAccountExist = 2
	 };

	 enSave save() {
		 switch (_mode)
		 {
		 case clsBankUser::EmptyMode:
			 return enSave::failedEmpty;
			 break;
		 case clsBankUser::UpdatedMode:
			 _Update();
			 return enSave::sucess;
			 break;
		 case clsBankUser::AddMode:
			 if (clsBankUser::IsExistUser(_Id)) {
				 return enSave::FalidAccountExist;
			 }
			 else {
				 _AddNew();
				 _mode = _enmode::UpdatedMode;
				 return enSave::sucess;
			 }
		 default:
			 break;
		 }
	 }

	 static clsBankUser GetNewUser(string Id) {
		 return clsBankUser(_enmode::AddMode, "", "", "", "", Id, "", 0);
	 }

	 static vector<clsBankUser>GetUserList() {
		 return _loadDatafromFiletoVector();
	 }
	 
	

};

