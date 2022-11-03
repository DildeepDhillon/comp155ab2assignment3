#pragma once
// Creating Bank Customer Class

//inlcuded account class, so account class can be included in this class
class CustomerAccount;


#include <iostream>
#include <string>
#include "BankCustomer.h"
#include "CustomerAccount.h"



	//Customer constructor initializes values for data members
	BankCustomer::BankCustomer(std::string name)
		: cAccount{ nullptr }, workPhone{ "" }, homePhone{ "" }, cellPhone{ "" }, address1{ "" }, address2{ "" }, city{ "" }, province{ "" }, postalCode{ "" } {

		//Customer name needs to be atleast 6 characters, or it won't be accpeted
		if (name.length() > 5) {
			fullName = name;
		}
		else {
			std::cout << "Full name not set, Full name has to be atleast 6 characters!" << std::endl;
		}
	}

	//function sets the full name for constructor, the full name needs to be atleast 6 characters
	bool BankCustomer::setName(std::string name) {
		if (name.length() > 5) {
			fullName = name;
			return true;
		}
		else {
			std::cout << "Full name not set, Full name needs to be atleast 6 characters in length!" << std::endl;
			return false;
		}
	}

	//returns customer name
	std::string BankCustomer::getName() const {
		return fullName;
	}

	//Sets customer phone number, atleast one type of phone number needs to be provided
	bool BankCustomer::setPhone(std::string wPhone, std::string hPhone, std::string cPhone) {
		if (wPhone.length() == 10 || hPhone.length() == 10 || cPhone.length() == 10) {
			workPhone = wPhone;
			homePhone = hPhone;
			cellPhone = cPhone;
			return true;
		}
		else {
			std::cout << "Atleast one phone number is required and phone number should be 10 digits long!" << std::endl;
			return false;
		}
	}

	//returns customer work phone number
	std::string BankCustomer::getwPhone() const {
		return workPhone;
	}

	//returns customer home phone number
	std::string BankCustomer::gethPhone() const {
		return homePhone;
	}

	//returns customer cell phone number
	std::string BankCustomer::getcPhone() const {
		return cellPhone;
	}

	//sets customer address, but address line 1 is required
	bool BankCustomer::setAddress(std::string add1, std::string add2) {
		if (add1.length() > 0) {
			address1 = add1;
			address2 = add2;
			return true;
		}
		else {
			std::cout << "Address Line 1 is required!" << std::endl;
			return false;
		}
	}

	//returns customer address line 1
	std::string BankCustomer::getAddress1() const {
		return address1;
	}

	//returns customer address line 2
	std::string BankCustomer::getAddress2() const {
		return address2;
	}

	//sets customer city
	void BankCustomer::setCity(std::string town) {
		city = town;
	}

	//returns customer city
	std::string BankCustomer::getCity() const {
		return city;
	}

	//sets customer province
	void BankCustomer::setProvince(std::string prov) {
		province = prov;
	}

	//returns customer province
	std::string BankCustomer::getProvince() const {
		return province;
	}

	//sets customer postal code
	void BankCustomer::setPostal(std::string postal) {
		postalCode = postal;
	}

	//returns customer postal code
	std::string BankCustomer::getPostal() const {
		return postalCode;
	}

	//function to connect Customer with Account
	void BankCustomer::setAccount(CustomerAccount& a) {
		cAccount = &a;
	}
