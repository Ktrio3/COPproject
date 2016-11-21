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

/*************************************
/assignProj()
/
/Assigns the ResearchAst to a project
**************************************/
void ResearchAst::assignProj(string proj)
{
	project = proj;
}

/*************************************
/getProj()
/
/Returns the project the research assistant is
/		working on
**************************************/
string ResearchAst::getProj()
{
	return project;
}

/*************************************
/print()
/
/Prints information about the ResearchAst
**************************************/
void ResearchAst::print()
{
	this->GradStudent::print();
	cout << " Research: " << this->getProj();;
}

//Destructor for research assistant
ResearchAst::~ResearchAst(){};
