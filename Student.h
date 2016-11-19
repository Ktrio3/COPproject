//********************************************
// File name: Student.h
// Purpose: Header file for Student class
// Authors: Kevin Dennis and V. Liana Peralta
//********************************************

#ifndef STUDENT_H
#define STUDENT_H

#include <iostream>
#include <string>
#include <vector>
#include "Course.h"
#include "Person.h"

using namespace std;

using namespace std;

class Student : public Person
{
	public:
		Student(int UnivID, string fullname,int BD, char gend, string lvl); //Prototype for constructor
		void registerCrs(int Course *course); //Prototype for register course function
		Course &getSchedule(int num); //Prototype for getSchedule function
		void print(); //Prototype for print function
		~Student(); //Prototype for destructor

	protected:
		string level; //String for student level (e.g. PhD, Post-BS/A)
		vector< const Course *> Schedule; //List of courses the student is registered for
};
#endif
