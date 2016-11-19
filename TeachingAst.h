//******************************************************
// File name: TeachingAst.h
// Purpose: Header file for Teaching Assistant class
// Authors: Kevin Dennis and V. Liana Peralta
//******************************************************

#ifndef TEACHINGAST_H
#define TEACHINGAST_H

#include <iostream>
#include <string>
#include <vector>
#include "Course.h"
#include "GradStudent.h"

using namespace std;

class Course;

class TeachingAst : public GradStudent
{
	public:
		TeachingAst(int UnivID, string fullname,int BD, char gend, string lvl, string prog); //Prototype for constructor
		Course &getTACourses(int num); //Prototype for get TA courses function
		void print(); //Prototype for print function
		~TeachingAst(); //Prototype for destructor

	protected:
		string project; //string for program
		vector< Course *> TACourses; //Vector of courses the teaching assistant is a TA for

};
#endif
