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
		virtual ~Person(); //Prototype for destructor

		void setUID(int UnivID);
		int getUID() const;

		void setName(string newName);
		string getName() const;

		void setBirthdate(string newBday);
		string getBirthdate() const;

		void setGender(string newGender);
		string getGender() const;

		virtual void print(); //Prototype for print function

	protected:
		int UID; //Integer for University ID number
		string name; //string for full name
		string birthdate; //Integer for birthdate (format: MM/DD/YYYY)
		string gender; //Character for gender (either F or M)
};
#endif
