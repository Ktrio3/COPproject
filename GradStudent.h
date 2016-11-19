//******************************************************
// File name: GradStudent.h
// Purpose: Header file for Graduate Student class
// Authors: Kevin Dennis and V. Liana Peralta
//******************************************************

#ifndef GRADSTUDENT_H
#define GRADSTUDENT_H

#include <iostream>
#include <string>
#include "Student.h"

using namespace std;

class GradStudent : public Student
{
	public:
		GradStudent(int UnivID, string fullname,int BD, char gend, string lvl); //Prototype for constructor
		void choosePrgm(string prog); //Prototype for choose graduate program function
		void print(); //Prototype for print function
		~GradStudent(); //Prototype for destructor

	protected:
		string program; //String for program
#endif
};
