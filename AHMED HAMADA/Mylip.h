#pragma once
#include<iostream>
using namespace std;

namespace Mylip {
	void test() {
		cout << "this is first my function\n";
	}

	short readnum(string messege) {
		cout << messege << endl;
		short num; cin >> num;
		return num;
	}
	
		int sumnum(int num1, int num2) {
			int sum = num1 + num2;
		return sum;
	}
}