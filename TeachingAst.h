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

class TeachingAst : public GradStudent
{
	public:
		TeachingAst(int UnivID, String fullname,int BD, char gend, String lvl); //Prototype for constructor
		void print(); //Prototype for print function
		~TeachingAst(); //Prototype for destructor
	
	protected:
		String project; //String for program
		vector< const Course *> TACourses; //Vector of courses the teaching assistant is a TA for
#endif
};
