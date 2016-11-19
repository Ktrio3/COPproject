//********************************************
// File name: Person.h
// Purpose: Header file for Person class
// Authors: Kevin Dennis and V. Liana Peralta
//********************************************

#ifndef TEACHINGAST_H
#define TEACHINGAST_H

#include <iostream>
#include <string>

using namespace std;

class TeachingAst
{
	public:
		TeachingAst(int UnivID, string fullname, int BD, char gend); //Prototype for constructor
		int getUID() const;
		void print(); //Prototype for print function
		~TeachingAst(); //Prototype for destructor

	protected:
		int UID; //Integer for University ID number
		string name; //String for full name
		int birthdate; //Integer for birthdate (format: MMDDYYYY)
		char gender; //Character for gender (either F or M)
};
#endif
