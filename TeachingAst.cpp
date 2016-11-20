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

Course &TeachingAst::getTACourses(int num)
{
	return *TACourses[num];
}

//Print function for TA
void TeachingAst::print()
{
	this->GradStudent::print();
}

//Destructor for TA
TeachingAst::~TeachingAst(){};
