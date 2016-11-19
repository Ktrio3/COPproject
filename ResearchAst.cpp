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
ResearchAst::ResearchAst(int UnivID, String fullname,int BD, char gend, String lvl, String prog, String proj) : GradStudent(UnivID, fullname, BD, gend, lvl, prog)
{
	project = proj;
}

//Function to assign a project to research assistant
void ResearchAst::assignProj(String proj)
{
	project = proj;
}

//Print function for research assistant
void ResearchAst::print()
{
	
}

//Destructor for research assistant
ResearchAst::~ResearchAst(){};
