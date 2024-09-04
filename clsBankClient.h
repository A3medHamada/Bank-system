#pragma once
#include<iostream>
#include<vector>
#include"clsPerson.h"
#include"ClsString.h"
#include"clsInputValidate.h"
#include"clsUtil.h"
#include<fstream>
#include<iomanip>
using namespace std;
class clsBankClient :public clsperson
{

private:

	string _AccountNumber = "";
	string _PinCode = "";
	double _AccountBalance;
	bool _MarkedforDellete = false;

	enum enMode {
		EmptyMode = 0,
		UpdateMode = 1,
		AddMode = 2
	};
	enMode _Mode;

	static clsBankClient _ConvertLinetoClinentObject(string line, string separator = "//#//") {
		vector<string>vClientData;

		vClientData = ClsString::split(line, separator);

		return clsBankClient(enMode::UpdateMode, vClientData[0], vClientData[1], vClientData[2], vClientData[3], vClientData[4], vClientData[5], stof(vClientData[6]));
	}

	static clsBankClient _GetEmetyClientObject() {

		return clsBankClient(enMode::EmptyMode, "", "", "", "", "", "", 0);
	}

	static vector<clsBankClient> _LoadClientDatafromFile() {
		vector<clsBankClient>vClientobjects;
		string line;
		fstream myfile;

		myfile.open("client.txt", ios::in);

		if (myfile.is_open()) {
			while (getline(myfile,line))
			{
				clsBankClient x = _ConvertLinetoClinentObject(line);

				vClientobjects.push_back(x);
			}
		}
		myfile.close();

		return vClientobjects;
	}

	static string _ConvertObjecttoLine(clsBankClient x, string separator = "//#//") {
		string line;
		line += x.firstname() + separator;
		line += x.lastname() + separator;
		line += x.email() + separator;
		line += x.phone() + separator;
		line += x._AccountNumber + separator;
		line += x._PinCode + separator;
		line += to_string(x._AccountBalance);

		return line;
	}

	static void _SaveClientDatatoFile(vector<clsBankClient>vClient) {
		fstream myfile;
		string line;
		myfile.open("client.txt", ios::out);

		if (myfile.is_open()) {
			for (clsBankClient x : vClient)
			{
				if (x.MarkedForDellete() == false)
				{
					line = _ConvertObjecttoLine(x);

					myfile << line << endl;
				}
			}

			myfile.close();
		}
	}

	void _Update() {
		vector<clsBankClient>x = _LoadClientDatafromFile();
		fstream myfile;
		myfile.open("client.txt", ios::out|ios::app);
		if (myfile.is_open()) {
			for (clsBankClient& z : x) {
				if (z.AccountNumber() == AccountNumber()) {
					z = *this;
				}
			}

			_SaveClientDatatoFile(x);

		}

	}

	void _AddNew() {
		string line;
		line = _ConvertObjecttoLine(*this);
		fstream myfile;

		myfile.open("client.txt", ios::out | ios::app);

		if (myfile.is_open()) {
			myfile << line << endl;
		}

		
	}

	static string _converttransferlogtoline(clsBankClient SourceClient, clsBankClient DestintionClient, float amount,string separator="//#//") {
		clsDate date;
		string line = "";

		line+= date.Stringtotext() + "-" + date.Time() + separator;
		line += SourceClient.$accountNumber + separator;
		line += DestintionClient.$accountNumber + separator;
		line +=to_string( amount) + separator;
		line +=to_string(SourceClient.$accountBalance) + separator;
		line +=to_string(DestintionClient.$accountBalance) + separator;
		line += CurrentUser.ID;

		return line;

	}

	static void _saveTransferLog(clsBankClient SourceClient, clsBankClient DestintionClient, float amount) {

		string line;
		line = _converttransferlogtoline(SourceClient, DestintionClient, amount);

		fstream myfile;

		myfile.open("TransferLog.txt", ios::out | ios::app);

		if (myfile.is_open()) {
			myfile << line << endl;
		}


	}

	

	struct sttransferdata;

	static sttransferdata converttransferlinetostruct(string line) {
		vector<string>x=ClsString::split(line, "//#//");
		sttransferdata data;

		data.Date = x[0];
		data.sourceId = x[1];
		data.destintionID = x[2];
		data.amount = stof(x[3]);
		data.sourcebalance = stod(x[4]);
		data.destintionbalance = stod(x[5]);
		data.userId = x[6];

		return data;
	}

	static vector<sttransferdata> _LoadTransferDatafromFile() {
		vector<sttransferdata>vTransferstruct;
		string line;
		fstream myfile;

		myfile.open("TransferLog.txt", ios::in);

		if (myfile.is_open()) {
			while (getline(myfile, line))
			{
				sttransferdata x = converttransferlinetostruct(line);

				vTransferstruct.push_back(x);
			}
		}
		myfile.close();

		return vTransferstruct;
	}


public:
	clsBankClient(enMode x, string firstname, string lastname, string Email, string phone, string accountnumber, string pincode, double accountbalance) :
		clsperson(firstname, lastname, Email, phone) {
		_Mode = x;
		_AccountBalance = accountbalance;
		_AccountNumber = accountnumber;
		_PinCode = pincode;
	}

	struct sttransferdata {
		string Date;
		string sourceId;
		string destintionID;
		float amount;
		double sourcebalance;
		double destintionbalance;
		string userId;
	}; 

	bool MarkedForDellete() {
		return _MarkedforDellete;
	}

	void SetAccountBalance(double accountbalance) {

		_AccountBalance = accountbalance;
	}

	double AccountBalance() {
		return _AccountBalance;
	}

	_declspec(property (get = AccountBalance, put = SetAccountBalance)) double $accountBalance;

	void setaccountnumber(string accountnumber) {
		_AccountNumber = accountnumber;
	}

	string AccountNumber() {
		return _AccountNumber;
	}
	_declspec(property (get = AccountNumber, put = setaccountnumber))string $accountNumber;


	void setPinCode(string pin) {
		_PinCode = pin;
	}

	string PinCode() {
		return _PinCode;
	}

	_declspec(property (get = PinCode, put = setPinCode)) string $pinCode;





	void print() {

		cout << "------------------------------\n";
		cout << left << setw(15) << "\nFirst Name: " << firstname() << endl;
		cout << left << setw(15) << "\nLast Name: " << lastname() << endl;
		cout << left << setw(15) << "\nFull Name: " << firstname() << " " << lastname() << endl;
		cout << left << setw(15) << "\nEmail: " << email() << endl;
		cout << left << setw(15) << "\nPhone: " << phone() << endl;
		cout << left << setw(15) << "\nAccount Number: " << _AccountNumber << endl;
		cout << left << setw(15) << "\nPinCode: " << _PinCode << endl;
		cout << left << setw(15) << "\nAccount Balance: " << _AccountBalance << endl;
		cout << left << setw(15) << "\n------------------------------\n";
	}

	static clsBankClient find(string AccountNumber) {
		vector<clsBankClient>vclient = _LoadClientDatafromFile();
		for (clsBankClient& x : vclient) {
			if (x.AccountNumber() == AccountNumber) {
				return x;
			}
		}
		return _GetEmetyClientObject();
	}

	static clsBankClient find(string AccountNumber, string pincode) {
		vector<clsBankClient>vclient = _LoadClientDatafromFile();
		for (clsBankClient& x : vclient) {
			if ((x.AccountNumber() == AccountNumber) && (x._PinCode == pincode)) {
				return x;
			}
		}
		return _GetEmetyClientObject();
	}

	bool IsEmpty() {

		return(_Mode == enMode::EmptyMode);
	}

	static bool IsClientExist(string Account) {

		clsBankClient client = clsBankClient::find(Account);

		return (!client.IsEmpty());
	}
	bool Dellete() {
		vector<clsBankClient>x;
		x = _LoadClientDatafromFile();
		for (clsBankClient& z : x) {
			if (z.AccountNumber() == AccountNumber()) {
				z._MarkedforDellete = true;
			}
		}

		_SaveClientDatatoFile(x);
		*this = _GetEmetyClientObject();
		return true;
	}
	enum enSave {
		failedEmpty = 0,
		sucess = 1,
		FalidAccountExist = 2
	};

	enSave save() {
		switch (_Mode)
		{
		case clsBankClient::EmptyMode:
			return enSave::failedEmpty;
			break;
		case clsBankClient::UpdateMode:
			_Update();
			return enSave::sucess;
			break;
		case clsBankClient::AddMode:
			if (clsBankClient::IsClientExist(_AccountNumber)) {
				return enSave::FalidAccountExist;
			}
			else {
				_AddNew();
				_Mode = enMode::UpdateMode;
				return enSave::sucess;
			}
		default:
			break;
		}
	}

	static clsBankClient GetNewCLient(string AccountNumber) {
		return clsBankClient(enMode::AddMode, "", "", "", "", AccountNumber, "", 0);
	}

	static vector<clsBankClient>GetClientList() {
		return _LoadClientDatafromFile();
	}
	static double ToTalBalance() {
		vector<clsBankClient>x=_LoadClientDatafromFile();
		double e;
		e = 0;
		for (clsBankClient& z : x) {
			e += z.$accountBalance;
		}
		return e;
	}

	 void WithDraw(double WithDrawnum) {
		 
		 $accountBalance -= WithDrawnum;
		save();
	}
	 void Deposite(double amount) {
		 $accountBalance += amount;
		 save();
	 }
	static bool ManageTransfer(clsBankClient& SourceClient, clsBankClient& DestintionClient, float amount) {
		if (amount > SourceClient.$accountBalance) {
			return false;

			
		}
		else {
			SourceClient.WithDraw(amount);
			DestintionClient.Deposite(amount);
			clsBankClient::_saveTransferLog(SourceClient, DestintionClient, amount);
			return true;

		}
	}

	static vector<sttransferdata> LoadTransferLogData(){
		return _LoadTransferDatafromFile();
	}
};


