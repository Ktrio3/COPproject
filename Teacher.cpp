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
Teacher::Teacher(int UnivID, String fullname,int BD, char gend, String rol) : Person(UnivId, fullname, BD, gend)
{
	role = rol;
}

//Function for assigning grades to students
void Teacher::assignGrade(int crsID, int UnivID, int grade)
{
	
}

//Print function for teacher
void Teacher::print()
{
	
}

//Destructor for teacher
Teacher::~Teacher(){};
