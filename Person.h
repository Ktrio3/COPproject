//********************************************
// File name: Person.h
// Purpose: Header file for Person class
// Authors: Kevin Dennis and V. Liana Peralta
//********************************************

#ifndef PERSON_H
#define PERSON_H

#include <iostream>
#include <string>

using namespace std;

class Person
{
	public:
		Person(int UnivID, string fullname, int BD, char gend); //Prototype for constructor
		int getUID() const;
		void print(); //Prototype for print function
		~Person(); //Prototype for destructor

	protected:
		int UID; //Integer for University ID number
		string name; //String for full name
		int birthdate; //Integer for birthdate (format: MMDDYYYY)
		char gender; //Character for gender (either F or M)
};
#endif
