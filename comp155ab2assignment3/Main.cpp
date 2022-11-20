#pragma once

#include <iostream>
#include <string>
#include <cstdlib>
#include <vector>
#include "CustomerAccount.h"
#include "BankCustomer.h"
#include "Subaccount.h"
#include "BankInterfaceNewAccount.h"
#include "BankInterfaceAccountM.h"
#include "BankInterfaceSetInfo.h"
#include "BankInterfaceGetInfo.h"
#include "BankInterfaceAccountS.h"
#include "BankInterfaceSubAccount.h"
#include "BankInterfaceAccountStatus.h"
#include <time.h>

using namespace std;

void login();

void mainSwitch(BankInterfaceNewAccount,BankInterfaceAccountM, BankInterfaceSetInfo,BankInterfaceGetInfo, BankInterfaceAccountS, BankInterfaceSubAccount, CustomerAccount, BankInterfaceAccountStatus);

void accountSetInfoSwitch(BankInterfaceNewAccount, BankInterfaceAccountM, BankInterfaceSetInfo, BankInterfaceGetInfo, BankInterfaceAccountS, BankInterfaceSubAccount, CustomerAccount, BankInterfaceAccountStatus);

void accountGetInfoSwitch(BankInterfaceNewAccount, BankInterfaceAccountM, BankInterfaceSetInfo, BankInterfaceGetInfo, BankInterfaceAccountS, BankInterfaceSubAccount, CustomerAccount, BankInterfaceAccountStatus);

void accountMSwitch(BankInterfaceNewAccount, BankInterfaceAccountM, BankInterfaceSetInfo, BankInterfaceGetInfo, BankInterfaceAccountS, BankInterfaceSubAccount, CustomerAccount, BankInterfaceAccountStatus);

void accountSSwitch(BankInterfaceNewAccount, BankInterfaceAccountM, BankInterfaceSetInfo, BankInterfaceGetInfo, BankInterfaceAccountS, BankInterfaceSubAccount, CustomerAccount, BankInterfaceAccountStatus);

void subAccountSwitch(BankInterfaceNewAccount, BankInterfaceAccountM, BankInterfaceSetInfo, BankInterfaceGetInfo, BankInterfaceAccountS, BankInterfaceSubAccount, CustomerAccount, BankInterfaceAccountStatus);

void subAccountManageSwitch(BankInterfaceNewAccount, BankInterfaceAccountM, BankInterfaceSetInfo, BankInterfaceGetInfo, BankInterfaceAccountS, BankInterfaceSubAccount, CustomerAccount, BankInterfaceAccountStatus);

void accountStatus(BankInterfaceNewAccount, BankInterfaceAccountM, BankInterfaceSetInfo, BankInterfaceGetInfo, BankInterfaceAccountS, BankInterfaceSubAccount, CustomerAccount, BankInterfaceAccountStatus);

BankCustomer* bankcustomerPTR;

CustomerAccount* customeraccountPTR;

BankInterfaceNewAccount* bankinterfacenewaccountPTR;

vector<Subaccount*> vectorSubMain;

int main() {
	srand((unsigned int)time(NULL));

	//Following code intializes both the BankCustomer and CustomerAccount classes
	cout << "------------New Bank Account Setup------------" << endl;
	cout << "Lets start by setting up your Bank Account" << endl;
	string name{ "TEMPEST" };
	BankCustomer b1{ name };
	bankcustomerPTR = &b1;

	do {
		cout << "\nPlease Enter your full name (min. 6 characters long):" << endl;
		getline(cin, name);
	} while (b1.setName(name) == false);

	string wphone;
	do {
		cout << "\nPlease enter your work phone number (Ex.7784852142)" << endl;
		getline(cin, wphone);
	} while (b1.setPhone(wphone, "", "") == false);

	string address1;
	do {
		cout << "\nPlease enter your house number and street number" << endl;
		getline(cin, address1);
		b1.setAddress(address1, "");
	} while (b1.setAddress(address1, "") == false);

	cout << "\nPlease enter the city you live in" << endl;
	string city;
	getline(cin, city);
	b1.setCity(city);

	cout << "\nPlease enter the province you live in" << endl;
	string province;
	getline(cin, province);
	b1.setProvince(province);

	cout << "\nPlease enter your postal code" << endl;
	string pcode;
	getline(cin, pcode);
	b1.setPostal(pcode);

	//Provided a random account number and pin
	cout << "\nThanks for setting up your account!" << endl;
	int anumber = rand() % 20000 + 10000;
	cout << anumber << " is your account number!\n" << endl;
	int pin = rand() % 9999 + 1000;
	cout << pin << " is your pin number use it to login into the bank machine." << endl;

	//CustomerAccount class initialized
	CustomerAccount c1{ anumber, b1 };

	//Pointer created for CustomerAccount class
	customeraccountPTR = &c1;

	//BankInterfaceNewAccount class initialized and pointer created
	BankInterfaceNewAccount account{ pin };
	bankinterfacenewaccountPTR = &account;

	//login function is used to make sure correct pin is entered
	login();

	//The remaining BankInterface classes are intialized
	BankInterfaceAccountM bankInterfaceAccountM;
	BankInterfaceSetInfo bankInterfaceSetInfo;
	BankInterfaceGetInfo bankInterfaceGetInfo;
	BankInterfaceAccountS bankInterfaceAccountS;
	BankInterfaceSubAccount bankInterfaceSubaccount;
	BankInterfaceAccountStatus bankInterfaceAccountStatus;

	//Function controls the complete bank machine interface
	mainSwitch(account, bankInterfaceAccountM, bankInterfaceSetInfo, bankInterfaceGetInfo, bankInterfaceAccountS, bankInterfaceSubaccount, c1, bankInterfaceAccountStatus);


	return 0;
}

//login function is used to make sure correct pin is entered
void login() {
	int code;

		cout << "\nPlease enter your pin to login into the Bank Machine." << endl;
		cin >> code;

		if (bankinterfacenewaccountPTR->setLogin(code) == false) {
			login();
		}
		
}

//Function that is the main switch function that controls the remaining functions, and acts has the main menu for the Banking Interface
void mainSwitch(BankInterfaceNewAccount account,BankInterfaceAccountM bankInterfaceAccountM, BankInterfaceSetInfo bankInterfaceSetInfo, BankInterfaceGetInfo bankInterfaceGetInfo, BankInterfaceAccountS bankInterfaceAccountS, BankInterfaceSubAccount bankInterfaceSubaccount, CustomerAccount customerAccountPTR, BankInterfaceAccountStatus bankInterfaceAccountStatus) {
	//BankInterface pointer points to the base class object
	bankinterfacenewaccountPTR = &account;
	bankinterfacenewaccountPTR->setSwitch();
	
	//Switch statment controls banking interface, and each case represents a different sub menu, case 4 is if you want to log off the banking machine
	switch (bankinterfacenewaccountPTR->getSwitch()) {
	case 1:
		accountMSwitch(account, bankInterfaceAccountM, bankInterfaceSetInfo, bankInterfaceGetInfo, bankInterfaceAccountS, bankInterfaceSubaccount, customerAccountPTR, bankInterfaceAccountStatus);
		break;
	case 2:
		accountSSwitch(account, bankInterfaceAccountM, bankInterfaceSetInfo, bankInterfaceGetInfo, bankInterfaceAccountS, bankInterfaceSubaccount, customerAccountPTR, bankInterfaceAccountStatus);
		break;
	case 3:
		subAccountSwitch(account, bankInterfaceAccountM, bankInterfaceSetInfo, bankInterfaceGetInfo, bankInterfaceAccountS, bankInterfaceSubaccount, customerAccountPTR, bankInterfaceAccountStatus);
	case 4:
		break;

	default:
		mainSwitch(account, bankInterfaceAccountM, bankInterfaceSetInfo, bankInterfaceGetInfo, bankInterfaceAccountS, bankInterfaceSubaccount, customerAccountPTR, bankInterfaceAccountStatus);
		break;
	}
}

//Switch statment for a derived class object, one of the many sub-menu's for the Banking Interface
void accountSetInfoSwitch(BankInterfaceNewAccount account, BankInterfaceAccountM bankInterfaceAccountM, BankInterfaceSetInfo bankInterfaceSetInfo, BankInterfaceGetInfo bankInterfaceGetInfo, BankInterfaceAccountS bankInterfaceAccountS, BankInterfaceSubAccount bankInterfaceSubaccount, CustomerAccount customerAccountPTR, BankInterfaceAccountStatus bankInterfaceAccountStatus) {
	//BankInterface pointer points to the derived class object
	bankinterfacenewaccountPTR = &bankInterfaceSetInfo;

	//Polymorphism will invoke the correct setSwitch function
	bankinterfacenewaccountPTR->setSwitch();

	//local initialized variables
	string fname;
	string a1;
	string a2;
	string town;
	string prov;
	string postal;
	string cphone;
	string hphone;
	string wphone;

	switch (bankinterfacenewaccountPTR->getSwitch()) {
	case 1:
		//do while loop allows user to set new full name for account and makes sure its atleast 6 digits long
		do {
			cin.ignore(1, '\n');
			cout << "Please enter the new account full name." << endl;
			getline(cin, fname);
			bankcustomerPTR->setName(fname);
		} while (bankcustomerPTR->setName(fname) == false);
		accountSetInfoSwitch(account, bankInterfaceAccountM, bankInterfaceSetInfo, bankInterfaceGetInfo, bankInterfaceAccountS, bankInterfaceSubaccount, customerAccountPTR, bankInterfaceAccountStatus);
	case 2:
		//do while loop allows user to set new full address for account, and makes sure that address line#1 is provided
		do {
			cin.ignore(1, '\n');
			cout << "\nPlease fill out the address for line #1." << endl;
			getline(cin, a1);
			cout << "\nPlease fill out the address for line #2 or press enter to skip." << endl;
			getline(cin, a2);
			bankcustomerPTR->setAddress(a1, a2);
		} while (bankcustomerPTR->setAddress(a1, a2) == false);

		cout << "Please enter your city." << endl;
		getline(cin, town);
		bankcustomerPTR->setCity(town);

		cout << "Please enter your province." << endl;
		getline(cin, prov);
		bankcustomerPTR->setProvince(prov);

		cout << "Please enter your postal code." << endl;
		getline(cin, postal);
		bankcustomerPTR->setProvince(postal);
		accountSetInfoSwitch(account, bankInterfaceAccountM, bankInterfaceSetInfo, bankInterfaceGetInfo, bankInterfaceAccountS, bankInterfaceSubaccount, customerAccountPTR, bankInterfaceAccountStatus);

	case 3:
		//do while loop allows user to change phone numbers on file, and makes sure atleast one phone number is provided
		do {
			cin.ignore(1, '\n');
			cout << "\nPlease fill one of the following phone numbers." << endl;
			cout << "\nPlease fill out the work phone number or press enter to skip." << endl;
			getline(cin, wphone);
			cout << "\nPlease fill out the home phone number or press enter to skip." << endl;
			getline(cin, hphone);
			cout << "\nPlease fill out the cell phone number or press enter to skip." << endl;
			getline(cin, cphone);

			bankcustomerPTR->setPhone(wphone, hphone, cphone);
		} while (bankcustomerPTR->setPhone(wphone, hphone, cphone));
		accountSetInfoSwitch(account, bankInterfaceAccountM, bankInterfaceSetInfo, bankInterfaceGetInfo, bankInterfaceAccountS, bankInterfaceSubaccount, customerAccountPTR, bankInterfaceAccountStatus);
	case 4:
		accountMSwitch(account, bankInterfaceAccountM, bankInterfaceSetInfo, bankInterfaceGetInfo, bankInterfaceAccountS, bankInterfaceSubaccount, customerAccountPTR, bankInterfaceAccountStatus);
		break;
	default:
		accountSetInfoSwitch(account, bankInterfaceAccountM, bankInterfaceSetInfo, bankInterfaceGetInfo, bankInterfaceAccountS, bankInterfaceSubaccount, customerAccountPTR, bankInterfaceAccountStatus);
		break;
	}
}

//Switch statment for a derived class object, provided the user with his current banking details, like full name, address, phone numbers etc.
void accountGetInfoSwitch(BankInterfaceNewAccount account, BankInterfaceAccountM bankInterfaceAccountM, BankInterfaceSetInfo bankInterfaceSetInfo, BankInterfaceGetInfo bankInterfaceGetInfo, BankInterfaceAccountS bankInterfaceAccountS, BankInterfaceSubAccount bankInterfaceSubaccount, CustomerAccount customerAccountPTR, BankInterfaceAccountStatus bankInterfaceAccountStatus) {
	
	//BankInterface pointer points to the derived class object
	bankinterfacenewaccountPTR = &bankInterfaceGetInfo;
	
	//Polymorphism will invoke the correct setSwitch function
	bankinterfacenewaccountPTR->setSwitch();

	switch (bankinterfacenewaccountPTR->getSwitch()) {
	case 1:
		cout << "\nAccount number is: " << customerAccountPTR.getAccountNumber();
		cout << "\n Date account was opened: " << customerAccountPTR.getDateOpened();
		cout << "Account Status: " << customerAccountPTR.getAccountStatus();
		cout << "\n";
		bankInterfaceGetInfo.printName();
		cout << bankcustomerPTR->getName() << endl;

		cout << "\n";
		bankInterfaceGetInfo.printAddress();
		cout << "Address Line #1: " << bankcustomerPTR->getAddress1() << "\n" << endl;
		cout << "Address Line #2: " << bankcustomerPTR->getAddress2() << "\n" << endl;
		cout << "Postal Code: " << bankcustomerPTR->getPostal() << "\n" << endl;
		cout << "City: " << bankcustomerPTR->getCity() << "\n" << endl;
		cout << "Province: " << bankcustomerPTR->getProvince() << "\n" << endl;

		cout << "\n";
		bankInterfaceGetInfo.printPhone();
		cout << "Cell phone number is: " << bankcustomerPTR->getcPhone() << "\n" << endl;
		cout << "Work phone number is: " << bankcustomerPTR->getwPhone() << "\n" << endl;
		cout << "Home phone number is: " << bankcustomerPTR->gethPhone() << "\n" << endl;


		accountGetInfoSwitch(account, bankInterfaceAccountM, bankInterfaceSetInfo, bankInterfaceGetInfo, bankInterfaceAccountS, bankInterfaceSubaccount, customerAccountPTR, bankInterfaceAccountStatus);

	case 4:
		accountMSwitch(account, bankInterfaceAccountM, bankInterfaceSetInfo, bankInterfaceGetInfo, bankInterfaceAccountS, bankInterfaceSubaccount, customerAccountPTR, bankInterfaceAccountStatus);
		break;

	default:
		accountGetInfoSwitch(account, bankInterfaceAccountM, bankInterfaceSetInfo, bankInterfaceGetInfo, bankInterfaceAccountS, bankInterfaceSubaccount, customerAccountPTR, bankInterfaceAccountStatus);
		break;
	}
}


//Switch statment for a derived class object, contains a sub-menu called Account Management
void accountMSwitch(BankInterfaceNewAccount account, BankInterfaceAccountM bankInterfaceAccountM, BankInterfaceSetInfo bankInterfaceSetInfo, BankInterfaceGetInfo bankInterfaceGetInfo, BankInterfaceAccountS bankInterfaceAccountS, BankInterfaceSubAccount bankInterfaceSubaccount, CustomerAccount customerAccountPTR, BankInterfaceAccountStatus bankInterfaceAccountStatus) {
	
	//BankInterface pointer points to the derived class object
	bankinterfacenewaccountPTR = &bankInterfaceAccountM;

	//Polymorphism will invoke the correct setSwitch function
	bankinterfacenewaccountPTR->setSwitch();

	switch (bankinterfacenewaccountPTR->getSwitch()) {
	case 1:
		accountSetInfoSwitch(account, bankInterfaceAccountM, bankInterfaceSetInfo, bankInterfaceGetInfo, bankInterfaceAccountS, bankInterfaceSubaccount, customerAccountPTR, bankInterfaceAccountStatus);
		break;

	case 2:
		accountGetInfoSwitch(account, bankInterfaceAccountM, bankInterfaceSetInfo, bankInterfaceGetInfo, bankInterfaceAccountS, bankInterfaceSubaccount, customerAccountPTR, bankInterfaceAccountStatus);
		break;

	case 3:
		accountStatus(account, bankInterfaceAccountM, bankInterfaceSetInfo, bankInterfaceGetInfo, bankInterfaceAccountS, bankInterfaceSubaccount, customerAccountPTR, bankInterfaceAccountStatus);
		break;

	case 4:
		mainSwitch(account, bankInterfaceAccountM, bankInterfaceSetInfo, bankInterfaceGetInfo, bankInterfaceAccountS, bankInterfaceSubaccount, customerAccountPTR, bankInterfaceAccountStatus);
		break;

	default:
		accountMSwitch(account, bankInterfaceAccountM, bankInterfaceSetInfo, bankInterfaceGetInfo, bankInterfaceAccountS, bankInterfaceSubaccount, customerAccountPTR, bankInterfaceAccountStatus);
		break;
	}
}

//Switch statment for a derived class object, contains a sub-menu called Account Summary & Withdraw or Deposit
void accountSSwitch(BankInterfaceNewAccount account, BankInterfaceAccountM bankInterfaceAccountM, BankInterfaceSetInfo bankInterfaceSetInfo, BankInterfaceGetInfo bankInterfaceGetInfo, BankInterfaceAccountS bankInterfaceAccountS, BankInterfaceSubAccount bankInterfaceSubaccount, CustomerAccount customerAccountPTR, BankInterfaceAccountStatus bankInterfaceAccountStatus) {
	//BankInterface pointer points to the derived class object
	bankinterfacenewaccountPTR = &bankInterfaceAccountS;

	//Polymorphism will invoke the correct setSwitch function
	bankinterfacenewaccountPTR->setSwitch();

	switch (bankinterfacenewaccountPTR->getSwitch()) {
	case 1:
		cout << "\n";
		bankInterfaceAccountS.setBalance();
		cout << customeraccountPTR->getBalance() << endl;
		accountSSwitch(account, bankInterfaceAccountM, bankInterfaceSetInfo, bankInterfaceGetInfo, bankInterfaceAccountS, bankInterfaceSubaccount, customerAccountPTR, bankInterfaceAccountStatus);

	case 2:
		cout << "\n";
		cout << customeraccountPTR->setDeposit(bankInterfaceAccountS.setDeposit()) << endl;
		accountSSwitch(account, bankInterfaceAccountM, bankInterfaceSetInfo, bankInterfaceGetInfo, bankInterfaceAccountS, bankInterfaceSubaccount, customerAccountPTR, bankInterfaceAccountStatus);

	case 3:
		cout << "\n";
		cout << customeraccountPTR->setWithdrawal(bankInterfaceAccountS.setWidthdraw()) << endl;
		accountSSwitch(account, bankInterfaceAccountM, bankInterfaceSetInfo, bankInterfaceGetInfo, bankInterfaceAccountS, bankInterfaceSubaccount, customerAccountPTR, bankInterfaceAccountStatus);

	case 4:
		mainSwitch(account, bankInterfaceAccountM, bankInterfaceSetInfo, bankInterfaceGetInfo, bankInterfaceAccountS, bankInterfaceSubaccount, customerAccountPTR, bankInterfaceAccountStatus);
		break;

	default:
		accountSSwitch(account, bankInterfaceAccountM, bankInterfaceSetInfo, bankInterfaceGetInfo, bankInterfaceAccountS, bankInterfaceSubaccount, customerAccountPTR, bankInterfaceAccountStatus);
		break;
	}
}

//Switch statment for a derived class object, is a sub-menu for subaccount management
void subAccountSwitch(BankInterfaceNewAccount account, BankInterfaceAccountM bankInterfaceAccountM, BankInterfaceSetInfo bankInterfaceSetInfo, BankInterfaceGetInfo bankInterfaceGetInfo, BankInterfaceAccountS bankInterfaceAccountS, BankInterfaceSubAccount bankInterfaceSubaccount, CustomerAccount customerAccountPTR, BankInterfaceAccountStatus bankInterfaceAccountStatus) {
	
	//BankInterface pointer points to the derived class object
	bankinterfacenewaccountPTR = &bankInterfaceSubaccount;

	//Polymorphism will invoke the correct setSwitch function
	bankinterfacenewaccountPTR->setSwitch();

	//Variables initialized for controlling the vector
	int i{ 0 };
	int j{ 0 };

	//Subaccount class intialized 
	Subaccount s;

	switch (bankinterfacenewaccountPTR->getSwitch()) {
	case 1:
		i = bankInterfaceSubaccount.addSubAccount();
		vectorSubMain.push_back(&s);
		j = i - 1;
		customerAccountPTR.AddSubAccount(vectorSubMain[(j)]);
		subAccountSwitch(account, bankInterfaceAccountM, bankInterfaceSetInfo, bankInterfaceGetInfo, bankInterfaceAccountS, bankInterfaceSubaccount, customerAccountPTR, bankInterfaceAccountStatus);
		break;
	case 2:
		customerAccountPTR.RemoveSubAccount();
		subAccountSwitch(account, bankInterfaceAccountM, bankInterfaceSetInfo, bankInterfaceGetInfo, bankInterfaceAccountS, bankInterfaceSubaccount, customerAccountPTR, bankInterfaceAccountStatus);
		break;
	case 3:
		customerAccountPTR.getVectorSub();
		bankInterfaceSubaccount.getSwitch();
		subAccountSwitch(account, bankInterfaceAccountM, bankInterfaceSetInfo, bankInterfaceGetInfo, bankInterfaceAccountS, bankInterfaceSubaccount, customerAccountPTR, bankInterfaceAccountStatus);
		break;
	case 4:
		subAccountManageSwitch(account, bankInterfaceAccountM, bankInterfaceSetInfo, bankInterfaceGetInfo, bankInterfaceAccountS, bankInterfaceSubaccount, customerAccountPTR, bankInterfaceAccountStatus);
		break;
	case 5:
		mainSwitch(account, bankInterfaceAccountM, bankInterfaceSetInfo, bankInterfaceGetInfo, bankInterfaceAccountS, bankInterfaceSubaccount, customerAccountPTR, bankInterfaceAccountStatus);
		break;

	default:
		subAccountSwitch(account, bankInterfaceAccountM, bankInterfaceSetInfo, bankInterfaceGetInfo, bankInterfaceAccountS, bankInterfaceSubaccount, customerAccountPTR, bankInterfaceAccountStatus);
		break;
	}
}


//Switch statment for a derived class object, is a sub-menu under subaccount management
void subAccountManageSwitch(BankInterfaceNewAccount account, BankInterfaceAccountM bankInterfaceAccountM, BankInterfaceSetInfo bankInterfaceSetInfo, BankInterfaceGetInfo bankInterfaceGetInfo, BankInterfaceAccountS bankInterfaceAccountS, BankInterfaceSubAccount bankInterfaceSubaccount, CustomerAccount customerAccountPTR, BankInterfaceAccountStatus bankInterfaceAccountStatus) {
	
	//Calls member function that lists the subaccounts
	bankInterfaceSubaccount.setSubAccountManageSwitch();

	
	//Calls the member function that lists the subaccount options to get the balance, deposit or withdraw money
	bankInterfaceSubaccount.setSubAccountModifySwitch();

	//Variable initialized for controlling the vector
	int j = (bankInterfaceSubaccount.getSubAccountManageSwitch() - 1);

	switch (bankInterfaceSubaccount.getSubAccountModifySwitch()) {
	case 1:
		cout << "\nThe subaccount balance is: " << vectorSubMain[j]->getBalance() << endl;
		subAccountManageSwitch(account, bankInterfaceAccountM, bankInterfaceSetInfo, bankInterfaceGetInfo, bankInterfaceAccountS, bankInterfaceSubaccount, customerAccountPTR, bankInterfaceAccountStatus);
		break;
	case 2:
		vectorSubMain[j]->setDeposit(bankInterfaceSubaccount.subAccountDeposit());
		subAccountManageSwitch(account, bankInterfaceAccountM, bankInterfaceSetInfo, bankInterfaceGetInfo, bankInterfaceAccountS, bankInterfaceSubaccount, customerAccountPTR, bankInterfaceAccountStatus);
		break;
	case 3:
		vectorSubMain[j]->setWithdrawal(bankInterfaceSubaccount.subAccountWithdraw());
		subAccountManageSwitch(account, bankInterfaceAccountM, bankInterfaceSetInfo, bankInterfaceGetInfo, bankInterfaceAccountS, bankInterfaceSubaccount, customerAccountPTR, bankInterfaceAccountStatus);
		break;
	case 4:
		subAccountSwitch(account, bankInterfaceAccountM, bankInterfaceSetInfo, bankInterfaceGetInfo, bankInterfaceAccountS, bankInterfaceSubaccount, customerAccountPTR, bankInterfaceAccountStatus);
		break;
	default:
		subAccountSwitch(account, bankInterfaceAccountM, bankInterfaceSetInfo, bankInterfaceGetInfo, bankInterfaceAccountS, bankInterfaceSubaccount, customerAccountPTR, bankInterfaceAccountStatus);
		break;
	}


	
}

//Switch statment for a derived class object, controls the main account status
void accountStatus(BankInterfaceNewAccount account, BankInterfaceAccountM bankInterfaceAccountM, BankInterfaceSetInfo bankInterfaceSetInfo, BankInterfaceGetInfo bankInterfaceGetInfo, BankInterfaceAccountS bankInterfaceAccountS, BankInterfaceSubAccount bankInterfaceSubaccount, CustomerAccount customerAccountPTR, BankInterfaceAccountStatus bankInterfaceAccountStatus) {
	
	//BankInterface pointer points to the derived class object
	bankinterfacenewaccountPTR = &bankInterfaceAccountStatus;
	
	//Polymorphism will invoke the correct setSwitch function
	bankinterfacenewaccountPTR->setSwitch();

	//Account status is initialized as a empty string
	string account_Status = "";

	switch (bankinterfacenewaccountPTR->getSwitch()) {
	case 1:
		account_Status = "OPEN";
		customerAccountPTR.setStatus(account_Status);
		accountStatus(account, bankInterfaceAccountM, bankInterfaceSetInfo, bankInterfaceGetInfo, bankInterfaceAccountS, bankInterfaceSubaccount, customerAccountPTR, bankInterfaceAccountStatus);
	case 2:
		account_Status = "CLOSED";
		customerAccountPTR.setStatus(account_Status);
		accountStatus(account, bankInterfaceAccountM, bankInterfaceSetInfo, bankInterfaceGetInfo, bankInterfaceAccountS, bankInterfaceSubaccount, customerAccountPTR, bankInterfaceAccountStatus);
	case 3:
		account_Status = "FROZEN";
		customerAccountPTR.setStatus(account_Status);
		accountStatus(account, bankInterfaceAccountM, bankInterfaceSetInfo, bankInterfaceGetInfo, bankInterfaceAccountS, bankInterfaceSubaccount, customerAccountPTR, bankInterfaceAccountStatus);
	case 4:
		accountMSwitch(account, bankInterfaceAccountM, bankInterfaceSetInfo, bankInterfaceGetInfo, bankInterfaceAccountS, bankInterfaceSubaccount, customerAccountPTR, bankInterfaceAccountStatus);
		break;
	default:
		accountStatus(account, bankInterfaceAccountM, bankInterfaceSetInfo, bankInterfaceGetInfo, bankInterfaceAccountS, bankInterfaceSubaccount, customerAccountPTR, bankInterfaceAccountStatus);
		break;
	}



}