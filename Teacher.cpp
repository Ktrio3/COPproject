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

/*************************************
/getRole()
/
/Returns the teachers role (adjunct, professor, etc)
**************************************/
string Teacher::getRole()
{
	return role;
}

/*************************************
/print()
/
/Prints information about the teacher
**************************************/
void Teacher::print()
{
	this->Person::print();
	cout << " Position: " << this->getRole();
}

/*************************************
/printCourses()
/
/Prints the courses the teacher is assigned to
**************************************/
void Teacher::printCourses()
{
	
}

//Destructor for teacher
Teacher::~Teacher(){};
