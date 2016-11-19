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
TeachingAst::TeachingAst(int UnivID, String fullname,int BD, char gend, String lvl) : GradStudent(UnivID, fullname, BD, gend, lvl, prog){}

Course &TeachingAst::getTACourses(int num)
{
	return *TACourses[num];
}

//Print function for TA
void TeachingAst::print()
{
	
}

//Destructor for TA
TeachingAst::~TeachingAst(){};
