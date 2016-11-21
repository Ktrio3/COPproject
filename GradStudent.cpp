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
GradStudent::GradStudent(int UnivID, string fullname, string BD, string gend, string lvl, string prog)
: Student(UnivID, fullname, BD, gend, lvl)
{
	program = prog;
}

/*************************************
/choosePrgm()
/
/Assigns a program to a graduate student
**************************************/
void GradStudent::choosePrgm(string prog)
{
	program = prog;
}

/*************************************
/getPrgm()
/
/Returns the program the Grad Student is in
**************************************/
string GradStudent::getPrgm()
{
	return program;
}

/*************************************
/print()
/
/Print function for graduate student
**************************************/
void GradStudent::print()
{
	this->Student::print();
	cout << " Program: " << this->getPrgm();
}

//Destructor for graduate student
GradStudent::~GradStudent(){};
