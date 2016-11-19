//********************************************
// File name: Student.cpp
// Purpose: Source code for Student class
// Authors: Kevin Dennis and V. Liana Peralta
//********************************************

#include <iostream>
#include <string>
#include <vector>
#include "Course.h"
#include "Student.h"

//Constructor for student
Student::Student(int UnivID, String fullname,int BD, char gend, String lvl) : Person(UnivID, fullname, BD, gend)
{
	level = lvl;
}

//Function for student to enroll in courses
void Student::registerCrs(int Course *course)
{
	Schedule.push_back(course);
}

//Print Student Information
void Student::print()
{
	
}

//Destructor for student
Student::~Student(){};
