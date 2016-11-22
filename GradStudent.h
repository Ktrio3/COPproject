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
		GradStudent(int UnivID, string fullname, string BD, string gend, string lvl, string prog); //Prototype for constructor
		virtual ~GradStudent(); //Prototype for destructor

		void choosePrgm(string prog); //Prototype for choose graduate program function
		string getPrgm() const;

		virtual void print(); //Prototype for print function

	protected:
		string program; //String for program
};
#endif
