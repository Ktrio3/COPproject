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
		TeachingAst(int UnivID, string fullname, string BD, string gend, string lvl, string prog); //Prototype for constructor
		
		Course &getTACourse(int num); //Returns the course at postion num

		virtual void print(); //Prints information about the TA
		void printTACourses(); //Prints courses the TA is assigned to

		virtual ~TeachingAst(); //Prototype for destructor

	protected:
		string project; //string for program
		vector< Course *> TACourses; //Vector of courses the teaching assistant is a TA for

};
#endif
