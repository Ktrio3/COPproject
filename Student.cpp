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

using namespace std;

//Constructor for student
Student::Student(int UnivID, string fullname, string BD, char gend, string lvl) : Person(UnivID, fullname, BD, gend)
{
	level = lvl;
}

//Print Student Information
void Student::print()
{

}

//Destructor for student
Student::~Student(){};
