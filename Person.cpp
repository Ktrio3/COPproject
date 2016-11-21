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

/*************************************
/getUID()
/
/Returns the person's University ID number
**************************************/
int Person::getUID() const
{
	return UID;
}

/*************************************
/getName()
/
/Returns the person's name
**************************************/
string Person::getName() const
{
	return name;
}

/*************************************
/getName()
/
/Returns the person's name
**************************************/
string Person::getBirthdate() const
{
	return birthdate;
}

/*************************************
/getGender()
/
/Returns the person's gender
**************************************/
string Person::getGender() const
{
	return gender;
}

/*************************************
/print()
/
/Prints information about the person, for example
/		Kevin Dennis UID: U111111111 Birthday: 11/03/1995 Gender: M
**************************************/
void Person::print() const
{
	cout << this->getName() << " UID: U" << this->getUID() << " Birthday: " << this->getBirthdate() << " Gender: " << this->getGender();
}

Person::~Person(){};
