//********************************************
// File name: Person.cpp
// Purpose: Source code for Person class
// Authors: Kevin Dennis and V. Liana Peralta
//********************************************

#include <iostream>
#include <string>
#include "Person.h"

using namespace std;

//Constructor for person
Person::Person(int UnivID, string fullname, string BD, string gend)
{
	UID = UnivID;
	name = fullname;
	birthdate = BD;
	gender = gend;
}

//Get function for University ID number
int Person::getUID() const
{
	return UID;
}

//Get function for name
string Person::getName() const
{
	return name;
}

//Get function for University ID number
string Person::getBirthdate() const
{
	return birthdate;
}

//Get function for University ID number
string Person::getGender() const
{
	return gender;
}

//Print function for Person
void Person::print() const
{
	cout << this->getName() << " UID: U" << this->getUID() << " Birthday: " << this->getBirthdate() << " Gender: " << this->getGender();
}

Person::~Person(){};
