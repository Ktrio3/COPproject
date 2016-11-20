//******************************************************
// File name: ResearchAst.cpp
// Purpose: Source code for Research Assistant class
// Authors: Kevin Dennis and V. Liana Peralta
//******************************************************

#include <iostream>
#include <string>
#include "ResearchAst.h"

using namespace std;

//Constructor for research assistant
ResearchAst::ResearchAst(int UnivID, string fullname, string BD, string gend, string lvl, string prog, string proj) : GradStudent(UnivID, fullname, BD, gend, lvl, prog)
{
	project = proj;
}

//Function to assign a project to research assistant
void ResearchAst::assignProj(string proj)
{
	project = proj;
}

//Function to assign a project to research assistant
string ResearchAst::getProj()
{
	return project;
}

//Print function for research assistant
void ResearchAst::print()
{
	this->GradStudent::print();
	cout << " Research: " << this->getProj();;
}

//Destructor for research assistant
ResearchAst::~ResearchAst(){};
