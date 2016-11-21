//******************************************************
// File name: TeachingAst.h
// Purpose: Header file for Teaching Assistant class
// Authors: Kevin Dennis and V. Liana Peralta
//******************************************************

#include <iostream>
#include <string>
#include <vector>
#include "Course.h"
#include "TeachingAst.h"

using namespace std;

//Constructor for TA
TeachingAst::TeachingAst(int UnivID, string fullname, string BD, string gend, string lvl, string prog)
: GradStudent(UnivID, fullname, BD, gend, lvl, prog){}

/*************************************
/getTACourse()
/
/Returns the teachers role (adjunct, professor, etc)
**************************************/
Course &TeachingAst::getTACourse(int num)
{
	return *TACourses[num];
}

void TeachingAst::assignCourse(Course * course)
{
	TACourses.push_back(course);
}

/*************************************
/print()
/
/Prints information about the TeachingAst
**************************************/
void TeachingAst::print()
{
	this->GradStudent::print();
}

/*************************************
/printTACourses()
/
/Prints the courses the TA is assigned to
**************************************/
void TeachingAst::printTACourses()
{

}

//Destructor for TA
TeachingAst::~TeachingAst(){};
