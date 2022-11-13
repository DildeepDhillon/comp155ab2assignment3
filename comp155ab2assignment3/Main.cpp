#pragma once

#include <iostream>
#include <string>
#include <cstdlib>
#include "CustomerAccount.h"
#include "BankCustomer.h"
#include "Subaccount.h"
#include "BankInterfaceNewAccount.h"
#include <time.h>

using namespace std;

void accountIntialization();

int main() {
	srand(time(NULL));
	
	accountIntialization();





	return 0;
}

void accountIntialization() {
	cout << "Lets start by setting up your Bank Account" << endl;
	cout << "Please Enter your name (min. 6 characters long):" << endl;
	string name;
	cin >> name;

	BankCustomer b1{ name };

	cout << "Please enter your cell phone number (Ex.7784852142)" << endl;
	string cphone;
	cin >> cphone;
	b1.setPhone(cphone, "", "");

	cout << "Please enter your house number and street number" << endl;
	string address1;
	cin >> address1;
	b1.setAddress(address1, "");

	cout << "Please enter the city you live in" << endl;
	string city;
	cin >> city;
	b1.setCity(city);

	cout << "Please enter the province you live in" << endl;
	string province;
	cin >> province;
	b1.setProvince(province);

	cout << "Please enter your postal code" << endl;
	string pcode;
	getline(cin, pcode);
	b1.setPostal(pcode);
	
	cout << "Thanks for setting up your account!" << endl;
	int anumber = rand() % 20000 + 10000;
	cout << anumber << " is your account number!" << endl;
	int pin = rand() % 9999 + 1000;
	
	CustomerAccount c1{ anumber, b1 };
	
}