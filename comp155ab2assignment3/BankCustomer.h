#pragma once

//inlcuded account class, so account class can be included in this class
class CustomerAccount;


#include <iostream>
#include <string>
#include "CustomerAccount.h"


#ifndef BANKCUSTOMER_H
#define BANKCUSTOMER_H

class BankCustomer {
public:

	//Customer constructor initializes values for data members
	explicit BankCustomer(std::string);

	//function sets the full name for constructor, the full name needs to be atleast 6 characters
	bool setName(std::string);

	//returns customer name
	std::string getName() const;

	//Sets customer phone number, atleast one type of phone number needs to be provided
	bool setPhone(std::string, std::string, std::string);

	//returns customer work phone number
	std::string getwPhone() const;

	//returns customer home phone number
	std::string gethPhone() const;

	//returns customer cell phone number
	std::string getcPhone() const;

	//sets customer address, but address line 1 is required
	bool setAddress(std::string, std::string);

	//returns customer address line 1
	std::string getAddress1() const;

	//returns customer address line 2
	std::string getAddress2() const;

	//sets customer city
	void setCity(std::string);

	//returns customer city
	std::string getCity() const;

	//sets customer province
	void setProvince(std::string);

	//returns customer province
	std::string getProvince() const;

	//sets customer postal code
	void setPostal(std::string);

	//returns customer postal code
	std::string getPostal() const;

	//function to connect Customer with Account
	void setAccount(CustomerAccount&);

	

private:
	std::string fullName;
	std::string workPhone;
	std::string homePhone;
	std::string cellPhone;
	std::string address1;
	std::string address2;
	std::string city;
	std::string province;
	std::string postalCode;

public:
	//Set account as public so account member functions can be accessed in main cpp file
	CustomerAccount* cAccount;

};

#endif // !BANKCUSTOMER_H

