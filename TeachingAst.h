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
		virtual ~TeachingAst(); //Prototype for destructor

		void assignCourse(Course * course); //Assigns the TA to a course
		Course &getTACourse(int num); //Returns the course at postion num
		void removeTACourse(int num);
		int numTACourses(); //Returns number of courses is the TA

		virtual void print(); //Prints information about the TA
		void printTACourses(); //Prints courses the TA is assigned to

	protected:
		string project; //string for program
		vector< Course *> TACourses; //Vector of courses the teaching assistant is a TA for

};
#endif
