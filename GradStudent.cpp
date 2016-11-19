//******************************************************
// File name: GradStudent.cpp
// Purpose: Source code for graduate student class
// Authors: Kevin Dennis and V. Liana Peralta
//******************************************************

#include <iostream>
#include <string>
#include "GradStudent.h"

using namespace std;

//Constructor for graduate student
GradStudent::GradStudent(int UnivID, String fullname,int BD, char gend, String lvl, String prog) : Student(UnivID, fullname, BD, gend, lvl)
{
	program = prog;
}

//Function for assigning a program to a graduate student
void GradStudent::choosePrgm(String prog)
{
	program = prog;
}

//Print function for graduate student
void GradStudent::print()
{
	
}

//Destructor for graduate student
GradStudent::~GradStudent(){};
