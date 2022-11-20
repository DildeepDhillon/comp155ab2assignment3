#pragma once

#include <iostream>
#include <string>
#include "BankInterfaceNewAccount.h"
#include "BankInterfaceAccountM.h"


BankInterfaceAccountM::BankInterfaceAccountM()
	: BankInterfaceNewAccount(getPin()), accountOption{ 0 } {}
BankInterfaceAccountM::~BankInterfaceAccountM() {}

int BankInterfaceAccountM::getSwitch() {
	return accountOption;
};
void BankInterfaceAccountM::setSwitch() {
	std::cout << "\n-------------------------------------------------------" << std::endl;
	std::cout << "1) Update or Set-up Name, Address, Pin, etc.." << std::endl;
	std::cout << "2) Account information (current name, address, etc. on file)" << std::endl;
	std::cout << "3) Change account status" << std::endl;
	std::cout << "4) Back to Main Menu" << std::endl;
	std::cout << "Enter the number here: ";
	std::cin >> accountOption;
};

