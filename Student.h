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
#include "Person.h"

using namespace std;

class Course;

class Student : public Person
{
	public:
		Student(int UnivID, string fullname, string BD, string gend, string lvl); //Prototype for constructor
		void registerCrs(Course *course); //Prototype for register course function
		Course &getSchedule(int num); //Prototype for getSchedule function
		virtual void print(); //Prototype for print function
		string getLvl();
		void setLvl(string lvl);
		virtual ~Student(); //Prototype for destructor

	protected:
		string level; //String for student level (e.g. PhD, Post-BS/A)
		vector< const Course *> Schedule; //List of courses the student is registered for
};
#endif
