#pragma once

#include <iostream>
#include <string>
#include "BankInterfaceNewAccount.h"
#include "BankInterfaceSubAccount.h"
#include "Subaccount.h"


BankInterfaceSubAccount::BankInterfaceSubAccount()
	: BankInterfaceNewAccount(getPin()), getInfoOption{ 0 }, getsubaccount{ 0 }, subaccount{ 0 }, getmodify{ 0 } {}
BankInterfaceSubAccount::~BankInterfaceSubAccount() {}

int BankInterfaceSubAccount::getSwitch() {
	return getInfoOption;
};
void BankInterfaceSubAccount::setSwitch() {
	std::cout << "\n-----------------------------------------" << std::endl;
	std::cout << "1) Add subaccount." << std::endl;
	std::cout << "2) Remove subaccount." << std::endl;
	std::cout << "3) List of subaccounts." << std::endl;
	std::cout << "4) Manage subaccounts." << std::endl;
	std::cout << "5) Exit to Main Menu." << std::endl;
	std::cout << "Enter the number here: ";
	std::cin >> getInfoOption;
};

int BankInterfaceSubAccount::addSubAccount() {
	subaccount++;
	std::string s = "Subaccount " + std::to_string(subaccount);
	std::cout << s << " has been added" << std::endl;
	return subaccount;
};

int BankInterfaceSubAccount::removeSubAccount() {
	subaccount--;
	std::string s = "Subaccount " + std::to_string(subaccount);
	std::cout << "\n";
	std::cout << s << "!" << std::endl;
	return subaccount;
};

void BankInterfaceSubAccount::subAccountList() {
	
	for (int list = 1; list == subaccount; list++) {
		std::cout << list << ") Subaccount " << list << std::endl;
	}
};

void BankInterfaceSubAccount::setSubAccountManageSwitch() {
	std::cout << "\nSelect which subaccount you want to manage." << std::endl;
	for (int list = 1; list <= subaccount; list++) {
		std::cout << list << ") Subaccount " << list << std::endl;
	}
	std::cout << "Enter the subaccount number here: ";
	std::cin >> getsubaccount;
};

int BankInterfaceSubAccount::getSubAccountManageSwitch() {
	return getsubaccount;
};

void BankInterfaceSubAccount::setSubAccountModifySwitch() {
	std::cout << "\n-----------------------------------------" << std::endl;
	std::cout << "1) Get subaccount balance." << std::endl;
	std::cout << "2) Deposit money into the subaccount (in cents)." << std::endl;
	std::cout << "3) Widthdraw money from the subaccount (in cents)." << std::endl;
	std::cout << "4) Back to Subaccount menu." << std::endl;
	std::cout << "Enter the number here: ";
	std::cin >> getmodify;
};

int BankInterfaceSubAccount::getSubAccountModifySwitch() {
	return getmodify;
};

int  BankInterfaceSubAccount::subAccountDeposit() {
	int deposit;
	std::cout << "How much money do you want to deposit (in cents): ";
	std::cin >> deposit;

	return deposit;
};

int  BankInterfaceSubAccount::subAccountWithdraw() {
	int withdraw;
	std::cout << "How much money do you want to withdraw (in cents): ";
	std::cin >> withdraw;

	return withdraw;
};