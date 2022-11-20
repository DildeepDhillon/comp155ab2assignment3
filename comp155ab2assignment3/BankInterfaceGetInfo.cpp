#pragma once

#include <iostream>
#include <string>
#include "BankInterfaceNewAccount.h"
#include "BankInterfaceGetInfo.h"


BankInterfaceGetInfo::BankInterfaceGetInfo()
	: BankInterfaceNewAccount(getPin()), getInfoOption{ 0 } {}
BankInterfaceGetInfo::~BankInterfaceGetInfo() {}

int BankInterfaceGetInfo::getSwitch() {
	return getInfoOption;
};
void BankInterfaceGetInfo::setSwitch() {
	std::cout << "\n-----------------------------------------" << std::endl;
	std::cout << "1) To print out account information." << std::endl;
	std::cout << "4) Back to Account Managment Menu" << std::endl;
	std::cout << "Enter the number here: ";
	std::cin >> getInfoOption;
};

void BankInterfaceGetInfo::printName() {
	std::cout << "Full name on the account is:" << std::endl;
}

void BankInterfaceGetInfo::printAddress() {
	std::cout << "Full address on the account is:" << std::endl;
}

void BankInterfaceGetInfo::printPhone() {
	std::cout << "The phone numbers on file are:" << std::endl;
}
