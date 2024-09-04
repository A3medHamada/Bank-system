#pragma once
#include<string>
#include<iostream>
#include<cstdlib>
using namespace std;
class clsUtil
{

public:
	enum enChartype {
		SmallLetter = 1,
		CapitalLitter = 2,
		Digit = 3,
		MixChar = 4,
		SpecialCharacter = 5
	};

	static void Srand() {
		srand((unsigned)time(NULL));
	}

	static int RandomNumber(short from, short to) {
		int randum = rand() % (to - from + 1) + from;
		return randum;
	}

	static char GetRandomCharacter(enChartype CharType) {

		if (CharType == MixChar) {

			CharType = enChartype(RandomNumber(1, 3));
		}
		switch (CharType)
		{
		case clsUtil::SmallLetter:
			return char(RandomNumber(97, 122));
			break;
		case clsUtil::CapitalLitter:
			return char(RandomNumber(65, 90));
			break;
		case clsUtil::Digit:
			return char(RandomNumber(48, 57));
			break;
		case clsUtil::SpecialCharacter:
			return char(RandomNumber(33, 47));
			break;
		default:
			return char(RandomNumber(65, 90));
			break;
		}
	}

	static string GetGenerateWord(enChartype CharType, short length) {

		string word = "";

		for (int i = 0; i < length; i++) {
			word += GetRandomCharacter(CharType);
		}
		return word;
	}

	static string GetGenerateKey(enChartype CharType = CapitalLitter) {

		string Key = "";
		string word = GetGenerateWord(CharType,4);

		Key += word + '-';
		Key += word + '-';
		Key += word + '-';
		Key += word ;

		return Key;
	}

	static void GetGenerateKeys(enChartype CharType, short numkeys) {
		for (int i = 1; i <= numkeys; i++) {

			cout << "Key [" << i << "] :";
			cout << GetGenerateKey(CharType) << endl;
		}
	}

	static void FIllArrWithRandomNumber(int arr[100], short arrlength, short from, short to) {
		for (int i = 0; i < arrlength; i++) {
			arr[i] = RandomNumber(from, to);
		}
	}

	static void FIllArrWithRandomWords(string arr[100], short arrlength, enChartype chartype, short wordlenght) {
		for (int i = 0; i < arrlength; i++) {
			arr[i] = GetGenerateWord(chartype,wordlenght);
		}
	}

	static void FIllArrWithRandomKeys(string arr[100], short arrlength, enChartype chartype) {
		for (int i = 0; i < arrlength; i++) {
			arr[i] = GetGenerateKey(chartype);
		}
	}

	static void Swap(int& x, int& y) {
		int temp;
		temp = x;
		x = y;
		y = temp;
	}

	static void Swap(double& x, double& y) {
		double temp;
		temp = x;
		x = y;
		y = temp;
	}

	static void Swap(char& x, char& y) {
		char temp;
		temp = x;
		x = y;
		y = temp;
	}

	static void Swap(string& x, string& y) {
		string temp;
		temp = x;
		x = y;
		y = temp;
	}

	static void Swap(bool& x, bool& y) {
		bool temp;
		temp = x;
		x = y;
		y = temp;
	}

	static void ShuffleArray(string arr[100], short arrlength) {
		for (int i = 0; i < arrlength; i++) {
			swap(arr[RandomNumber(0, arrlength - 1)], arr[RandomNumber(0, arrlength - 1)]);
		}
	}

	static string Taps(short numofTaps) {
		string t = "";
		for (int i = 1; i < numofTaps; i++) {
			t = +"\t";
			cout << t;
		}
		return t;
	}

	static string Encryptztext(string text, short EncryptionKey) {

		for (int i = 0; i < text.length(); i++) {

			text[i] = char((int) text[i] + EncryptionKey);
		}
		return text;
	}

	static string Decryptztext(string text, short DecryptionKey) {

		for (int i = 0; i < text.length(); i++) {

			text[i] = char(int(text[i]) - DecryptionKey);
		}
		return text;
	}

	static string NumberToText(int Number)
	{
		if (Number == 0)
			return"";
		if (Number >= 1 && Number <= 19) {
			string arr[] = { "","One","Two","three","Four","Five","Six","Seven","Eight","Nine","Ten","Eleven","Tweleve","Therteen","Fourteen","Fivteen","Sixteen",
				"Seventeen","Eighteen","Nineteen" };

			return arr[Number] + " ";
		}
		if (Number >= 20 && Number <= 99) {
			string arr[] = { "","" ,"Twenty" ,"Therty", "Forty" , "Fifty" ,
		" Sixty","Seventy" ,"Eighty" ,"Ninety" };
			return arr[Number / 10] + " " + NumberToText(Number % 10);
		}
		if (Number >= 100 && Number <= 199) {
			return "One Hundred " + NumberToText(Number % 100);
		}
		if (Number >= 200 && Number <= 999) {
			return NumberToText(Number / 100) + "Hundreds" + NumberToText(Number % 100);
		}
		if (Number >= 1000 && Number <= 1999) {
			return "One Thousand" + NumberToText(Number % 1000);
		}
		if (Number >= 2000 && Number <= 999999) {
			return NumberToText(Number / 1000) + "Thousands" + NumberToText(Number % 1000);
		}
	}
};

