#pragma once

#include <iostream>
#include <string>
#include "BankInterfaceNewAccount.h"
#include "BankInterfaceSetInfo.h"


BankInterfaceSetInfo::BankInterfaceSetInfo()
	: BankInterfaceNewAccount(getPin()), setInfoOption{ 0 } {}
BankInterfaceSetInfo::~BankInterfaceSetInfo() {}

int BankInterfaceSetInfo::getSwitch() {
	return setInfoOption;
};
void BankInterfaceSetInfo::setSwitch() {
	std::cout << "\n-----------------------------------------" << std::endl;
	std::cout << "1) Update your name" << std::endl;
	std::cout << "2) Update your full address" << std::endl;
	std::cout << "3) Update phone numbers" << std::endl;
	std::cout << "4) Back to Account Managment Menu" << std::endl;
	std::cout << "Enter the number here: ";
	std::cin >> setInfoOption;
};