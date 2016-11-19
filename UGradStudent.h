//******************************************************
// File name: UGradStudent.h
// Purpose: Header file for UnderGraduate Student class
// Authors: Kevin Dennis and V. Liana Peralta
//******************************************************

#ifndef UGRADSTUDENT_H
#define UGRADSTUDENT_H

#include <iostream>
#include <string>

using namespace std;

class UGradStudent : public Student
{
	public:
		UGradStudent(int UnivID, String fullname,int BD, char gend, String lvl, String maj); //Prototype for constructor
		void declareMjr(String maj); //Prototype for declare major function
		void print(); //Prototype for print function
		~UGradStudent(); //Prototype for destructor
	
	private:
		String major; //String for major
#endif
};
