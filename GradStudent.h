//******************************************************
// File name: GradStudent.h
// Purpose: Header file for Graduate Student class
// Authors: Kevin Dennis and V. Liana Peralta
//******************************************************

#ifndef GRADSTUDENT_H
#define GRADSTUDENT_H

#include <iostream>
#include <string>

class GradStudent : public Student
{
	public:
		GradStudent(int UnivID, String fullname,int BD, char gend, String lvl); //Prototype for constructor
		void choosePrgm(String prog); //Prototype for choose graduate program function
		void print(); //Prototype for print function
		~GradStudent(); //Prototype for destructor
	
	protected:
		String program; //String for program
#endif
};
