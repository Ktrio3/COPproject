//******************************************************
// File name: ResearchAst.h
// Purpose: Header file for Research Assistant class
// Authors: Kevin Dennis and V. Liana Peralta
//******************************************************

#ifndef RESEARCHAST_H
#define RESEARCHAST_H

#include <iostream>
#include <string>

using namespace std;

class ResearchAst : public GradStudent
{
	public:
		ResearchAst(int UnivID, String fullname,int BD, char gend, String lvl, String prog, String proj); //Prototype for constructor
		void assignProj(String proj); //Prototype for assign project function
		void print(); //Prototype for print function
		~ResearchAst(); //Prototype for destructor
	
	protected:
		String project; //String for program
#endif
};
