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
		virtual ~Student(); //Prototype for destructor

		void registerCrs(Course *course); //Registers a student for a course
		Course &getCourse(int num); //Returns the course at position num
		void removeCourse(int num);
		int numCourses(); //Returns the number of courses

		virtual void print(); //Prints information about the student
		void printCourses();	//Prints courses the student is enrolled in

		string getLvl();
		void setLvl(string lvl);

	protected:
		string level; //String for student level (e.g. PhD, Post-BS/A)
		vector< Course *> schedule; //Vector of courses the student is registered for
};
#endif
