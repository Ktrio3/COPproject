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
#include "Person.h"

using namespace std;

class Course;

class Teacher : public Person
{
	public:
		Teacher(int UnivID, string fullname, string BD, string gend, string rol); //Prototype for constructor
		void assignGrade(int crsID, int UnivID, int grade); //Prototype for assign grade function
		virtual void print(); //Prototype for print function
		virtual ~Teacher(); //Prototype for destructor

	protected:
		string role; //String for teacher role (e.g. adjunct, lecturer, etc.)
		vector<Course *> Lectures; //Vector of courses the teacher is the instructor of

};
#endif
