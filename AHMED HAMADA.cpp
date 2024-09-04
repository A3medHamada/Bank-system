#include<iostream>
#include"clsLoginScreen.h"
using namespace std;
int main() {
	/*clsMainScreen::ShowMainMenu();*/
	while (true) {

		if (clsLoginScreen::ShowLoginScreen() == false) {
			break;
		}
	}

}
