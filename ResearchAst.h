//******************************************************
// File name: ResearchAst.h
// Purpose: Header file for Research Assistant class
// Authors: Kevin Dennis and V. Liana Peralta
//******************************************************

#ifndef RESEARCHAST_H
#define RESEARCHAST_H

#include <iostream>
#include <string>
#include "GradStudent.h"

using namespace std;

class ResearchAst : public GradStudent
{
	public:
		ResearchAst(int UnivID, string fullname, string BD, string gend, string lvl, string prog, string proj); //Prototype for constructor

		void assignProj(string proj); //Prototype for assign project function
		string getProj();

		virtual void print(); //Prototype for print function
		
		virtual ~ResearchAst(); //Prototype for destructor

	protected:
		string project; //string for program

};
#endif
