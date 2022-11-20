#pragma once

#include <iostream>
#include <string>
#include "BankInterfaceNewAccount.h"
#include "BankInterfaceAccountS.h"


BankInterfaceAccountS::BankInterfaceAccountS()
	: BankInterfaceNewAccount(getPin()), accountOption{ 0 } {}
BankInterfaceAccountS::~BankInterfaceAccountS() {}

int BankInterfaceAccountS::getSwitch() {
	return accountOption;
};
void BankInterfaceAccountS::setSwitch() {
	std::cout << "\n-----------------------------------------" << std::endl;
	std::cout << "1) Current Main Account Balance" << std::endl;
	std::cout << "2) Deposit Money into your Main Account" << std::endl;
	std::cout << "3) Withdraw Money from your Main Account" << std::endl;
	std::cout << "4) Return to Main Menu" << std::endl;
	std::cout << "Enter the number here: ";
	std::cin >> accountOption;
};

void BankInterfaceAccountS::setBalance() {
	std::cout << "Current Balance (in cents) is: ";
};

int BankInterfaceAccountS::setDeposit() {
	std::cout << "How much money (in cents) do you want to deposit: ";
	int deposit;
	std::cin >> deposit;
	std::cout << "\n";

	return deposit;
};

int BankInterfaceAccountS::setWidthdraw() {
	std::cout << "How much money (in cents) do you want to widthdraw: ";
	int widthdraw;
	std::cin >> widthdraw;
	std::cout << "\n";

	return widthdraw;
};