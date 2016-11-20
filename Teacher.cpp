//********************************************
// File name: Teacher.cpp
// Purpose: Source code for Teacher class
// Authors: Kevin Dennis and V. Liana Peralta
//********************************************

#include <iostream>
#include <string>
#include <vector>
#include "Course.h"
#include "Teacher.h"

//Constructor for teacher
Teacher::Teacher(int UnivID, string fullname, string BD, string gend, string rol) : Person(UnivID, fullname, BD, gend)
{
	role = rol;
}

//Function for assigning grades to students
void Teacher::assignGrade(int crsID, int UnivID, int grade)
{

}

string Teacher::getRole()
{
	return role;
}

//Print function for teacher
void Teacher::print()
{
	this->Person::print();
	cout << " Position: " << this->getRole();
}

//Destructor for teacher
Teacher::~Teacher(){};
