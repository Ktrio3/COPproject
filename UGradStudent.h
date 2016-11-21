//******************************************************
// File name: UGradStudent.h
// Purpose: Header file for UnderGraduate Student class
// Authors: Kevin Dennis and V. Liana Peralta
//******************************************************

#ifndef UGRADSTUDENT_H
#define UGRADSTUDENT_H

#include <iostream>
#include <string>
#include "Student.h"

using namespace std;

class UGradStudent : public Student
{
	public:
		UGradStudent(int UnivID, string fullname, string BD, string gend, string lvl, string maj); //Prototype for constructor

		void declareMjr(string maj); //Declares a new major for the student
		string getMjr(); //Returns the major the student is studying

		void print(); //Prints the courses the student is in

		~UGradStudent(); //Prototype for destructor
	private:
		string major; //string for major
};
#endif
