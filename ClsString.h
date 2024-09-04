#pragma once
#include<iostream>
#include<string>
#include<vector>
using namespace std;

class ClsString
{

private:

	string _text;

public:
	ClsString() {

	}

	ClsString(string text) {
		_text = text;
	}

	void SetText(string text) {
		_text = text;
	}

	string Text() {
		return _text;
	}

	static vector<string>split(string S1, string delim) {

		vector <string> x;
		int pos = 0;
		short count = 0;
		string word;
		
		while ((pos = S1.find(delim)) && pos != S1.npos) {

			word = S1.substr(0, pos);
			if (S1 != "") {
				x.push_back(word);
			}
			S1.erase(0, pos + delim.length());
		}

		if (S1 != "") {
			x.push_back(S1);
		}
		return x;
	}

	static void numofwords(string S1) {

		string delim = " ";
		int pos = 0;
		short count = 0;
		string word;

		while ((pos = S1.find(delim)) && pos != S1.npos) {

			word = S1.substr(0, pos);
			if (S1 != "") {
				count++;
			}
			S1.erase(0, pos + delim.length());
		}

		if (S1 != "") {
			count++;
		}
		cout << "sum of words is: " << count<<endl;
	}

	void numofwords() {
		numofwords(_text);
	}

	static void CountCapitalLetters(string S1)
	{
		short Counter = 0;
		for (int i = 0; i < S1.length(); i++)
		{
			if (isupper(S1[i]))
				Counter++;
		}
		cout << "\nCapital Letters Count = " << Counter << endl;
	}

	void CountCapitalLetters() {
		CountCapitalLetters(_text);
	}

	static void CountSmallLetters(string S1) {
		short count = 0;
		for (int i = 0; i < S1.length(); i++) {
			if (isupper(S1[i])) {
				count++;
			}
		}

		cout << "\nSmall Letters Count = " << count << endl;
	}

	void CountSmallLetters() {
		CountSmallLetters(_text);
	}

	static void CountLetter(string S1, char Letter) {
		short count = 0;
		for (int i = 0; i < S1.length(); i++) {
			if (S1[i] == Letter) {
				count++;
			}
		}

		cout << "\nLetter'" << Letter << "'Count: " << count;
	}

	void CountLetter(char Letter) {
		CountLetter(_text, Letter);
	}

	static void CountLetter_matchcase(string S1, char Letter) {
		short count = 0;
		for (int i = 0; i < S1.length(); i++) {
			if (toupper(S1[i]) == toupper(Letter)) {
				count++;
			}
		}

		cout << "\nLetter'" << toupper(Letter) << "'Or"<<tolower(Letter)<<"Count: " << count;
	}
	
	void CountLetter_matchcase(char letter) {
		CountLetter_matchcase(_text, letter);
	}
	
	static void Printeachwordintext(string S1) {
		string delim = " ";
		int pos = 0;
		string word;
		cout<< "\nYour string words are : \n\n";
		while ((pos = S1.find(delim)) && pos != S1.npos) {

			word = S1.substr(0, pos);
			if (S1 != "") {
				cout << word << endl;
			}
			S1.erase(0, pos + delim.length());
		}

		if (S1 != "") {
			cout << S1 << endl;
		}
	}

	void Printeachwordintext() {
		Printeachwordintext(_text);
	}
};


