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
Person::Person(int UnivID, String fullname, int BD, char gend)
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

//Print function for Person
void print()
{
	
}

Person::~Person(){};

