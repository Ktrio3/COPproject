//********************************************
// File name: Teacher.h
// Purpose: Header file for Teacher class
// Authors: Kevin Dennis and V. Liana Peralta
//********************************************

#ifndef TEACHER_H
#define TEACHER_H

#include <iostream>
#include <string>
#include <vector>
#include "Course.h"

using namespace std;

class Teacher : public Person
{
	public:
		Teacher(int UnivID, string fullname,int BD, char gend, string role); //Prototype for constructor
		void assignGrade(int crsID, int UnivID, int grade); //Prototype for assign grade function
		void print(); //Prototype for print function
		~Teacher(); //Prototype for destructor

	protected:
		string role; //String for teacher role (e.g. adjunct, lecturer, etc.)
		vector<Course *> lectures; //Vector of courses the teacher is the instructor of
};
#endif
