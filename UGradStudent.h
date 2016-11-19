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
		UGradStudent(int UnivID, string fullname, string BD, char gend, string lvl, string maj); //Prototype for constructor
		void declareMjr(string maj); //Prototype for declare major function
		void print(); //Prototype for print function
		~UGradStudent(); //Prototype for destructor

	private:
		string major; //string for major
};
#endif
