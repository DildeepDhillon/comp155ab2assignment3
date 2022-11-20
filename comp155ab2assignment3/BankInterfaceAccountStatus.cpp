#pragma once

#include <iostream>
#include <string>
#include "BankInterfaceNewAccount.h"
#include "BankInterfaceAccountStatus.h"


BankInterfaceAccountStatus::BankInterfaceAccountStatus()
	: BankInterfaceNewAccount(getPin()), accountOption{ 0 } {}
BankInterfaceAccountStatus::~BankInterfaceAccountStatus() {}

int BankInterfaceAccountStatus::getSwitch() {
	return accountOption;
};
void BankInterfaceAccountStatus::setSwitch() {
	std::cout << "\n-------------------------------------------------------" << std::endl;
	std::cout << "1) Set main account status to open" << std::endl;
	std::cout << "2) Set main account status to closed" << std::endl;
	std::cout << "3) Set main account status to frozen" << std::endl;
	std::cout << "4) Back to Main Menu" << std::endl;
	std::cout << "Enter the number here: ";
	std::cin >> accountOption;
};