#pragma once

#include <iostream>
#include <string>
#include "CustomerAccount.h"
#include "BankCustomer.h"
#include "Subaccount.h"
#include "BankInterfaceNewAccount.h"

//Constructor for class, that gets initialized with pin code
BankInterfaceNewAccount::BankInterfaceNewAccount(int pincode)
	: pin{ pincode }, option{ 0 } {}

//Destructor
BankInterfaceNewAccount::~BankInterfaceNewAccount() {}

//Gives the ability to change the pin
void BankInterfaceNewAccount::setPin(int pincode) {
	pin = pincode;
}

//Get the current pin to login into the bank machine
int BankInterfaceNewAccount::getPin() const{
	return pin;
}

//Allows the user to login with the correct pincode
bool BankInterfaceNewAccount::setLogin(int pincode) {
	if (pincode == pin) {
		std::cout << "\n-----------------------------------------" << std::endl;
		std::cout << "\n                LOGGED ON                " << std::endl;
		std::cout << "\n-----------------------------------------" << std::endl;
		std::cout << "\nLogin is successfull, please select from one of the following options below" << std::endl;
		return true;
	}
	else if (pincode != pin) {
		std::cout << "Pin is incorrect, please try again!" << std::endl;
		return false;
		}
	return false;
}

//Return the value for the option selected by the user
int BankInterfaceNewAccount::getSwitch() {
	return option;
}

//Presents the user with the main menu for the bank machine
void BankInterfaceNewAccount::setSwitch() {
	std::cout << "-----------------------------------------" << std::endl;
	std::cout << "1) Account Management" << std::endl;
	std::cout << "2) Accounnt Summary & Withdraw or Deposit" << std::endl;
	std::cout << "3) Subaccount Management" << std::endl;
	std::cout << "4) Logout" << std::endl;
	std::cout << "Enter the number here: ";
	std::cin >> option;
}




		
