#pragma once
#include<iostream>
#include"ClsString.h"
#include<vector>
#include"fstream"
using namespace std;
class clsCurrency
{
private:
	enum enMode {
		EmptyMOde=0,
		UpdateMode=1
	};

	enMode _mode;

	string _Country;
	string _CurrencyCode;
	string _CurrencyName;
	float _Rate;

	static clsCurrency _ConvertLinetoClinentObject(string line, string separator = "//#//") {

		vector<string>vClientData;

		vClientData = ClsString::split(line, separator);

		return clsCurrency(enMode::UpdateMode, vClientData[0], vClientData[1], vClientData[2], stof(vClientData[3]));
	}

	static clsCurrency _GetEmetyClientObject() {

		return clsCurrency(enMode::EmptyMOde, "", "", "",0);
	}

	static vector<clsCurrency> _LoadClientDatafromFile() {
		vector<clsCurrency>vClientobjects;
		string line;
		fstream myfile;

		myfile.open("Currency.txt", ios::in);

		if (myfile.is_open()) {
			while (getline(myfile, line))
			{
				clsCurrency x = _ConvertLinetoClinentObject(line);

				vClientobjects.push_back(x);
			}
		}
		myfile.close();

		return vClientobjects;
	}

	static string _ConvertObjecttoLine(clsCurrency x, string separator = "//#//") {
		string line;

		line += x._Country + separator;
		line += x._CurrencyCode + separator;
		line += x._CurrencyName + separator;
		line += to_string(x._Rate);

		return line;
	}

	static void _SaveClientDatatoFile(vector<clsCurrency>vClient) {
		fstream myfile;
		string line;
		myfile.open("Currency.txt", ios::out);

		if (myfile.is_open()) {
			for (clsCurrency x : vClient)
			{
			
					line = _ConvertObjecttoLine(x);

					myfile << line << endl;
				}

			myfile.close();
		}
	}

	void _Update() {
		vector<clsCurrency>x = _LoadClientDatafromFile();
		fstream myfile;
		myfile.open("Currency.txt", ios::out | ios::app);
		if (myfile.is_open()) {
			for (clsCurrency& z : x) {
				if (z._Country == _Country) {
					z = *this;
				}
			}

			_SaveClientDatatoFile(x);

		}

	}

	public:
		clsCurrency(enMode mode,string country, string currencycode, string currencyName, float rate) {
			_mode = mode;
			_Country = country;
			_CurrencyName = currencyName;
			_CurrencyCode = currencycode;
			_Rate = rate;
		}

		static clsCurrency findbyCode(string CurrencyCode) {
			vector<clsCurrency>vclient = _LoadClientDatafromFile();
			for (clsCurrency& x : vclient) {
				if (x._CurrencyCode == CurrencyCode) {
					return x;
				}
			}
			return _GetEmetyClientObject();
		}

		static clsCurrency findbycountry(string country) {
			vector<clsCurrency>vclient = _LoadClientDatafromFile();
			for (clsCurrency& x : vclient) {
				if (x._Country == country){
					return x;
				}
			}
			return _GetEmetyClientObject();
		}

		bool IsEmpty() {

			return(_mode == enMode::EmptyMOde);
		}

		static bool IsClientExist(string Country) {

			clsCurrency client = clsCurrency::findbycountry(Country);

			return (!client.IsEmpty());
		}

		enum enSave {
			failedEmpty = 0,
			sucess = 1,
		};

		enSave save() {
			switch (_mode)
			{
			case clsCurrency::EmptyMOde:
				return enSave::failedEmpty;
				break;
			case clsCurrency::UpdateMode:
				_Update();
				return enSave::sucess;
				break;
			default:
				break;
			}
		}

		static vector<clsCurrency>GetClientList() {
			return _LoadClientDatafromFile();
		}
};

