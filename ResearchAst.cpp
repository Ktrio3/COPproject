//******************************************************
// File name: ResearchAst.cpp
// Purpose: Source code for Research Assistant class
// Authors: Kevin Dennis and V. Liana Peralta
//******************************************************

#include <iostream>
#include <string>
#include "ResearchAst.h"

//Constructor for research assistant
ResearchAst::ResearchAst(int UnivID, String fullname,int BD, char gend, String lvl) : GradStudent(UnivID, fullname, BD, gend, lvl){};

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
