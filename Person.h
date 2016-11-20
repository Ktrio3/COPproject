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
		Person(int UnivID, string fullname, string BD, string gend); //Prototype for constructor

		int getUID() const;

		string getName() const;

		string getBirthdate() const;
		
		string getGender() const;

		void print() const; //Prototype for print function
		~Person(); //Prototype for destructor

	protected:
		int UID; //Integer for University ID number
		string name; //string for full name
		string birthdate; //Integer for birthdate (format: MM/DD/YYYY)
		string gender; //Character for gender (either F or M)
};
#endif
