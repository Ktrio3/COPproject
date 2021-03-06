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
: GradStudent(UnivID, fullname, BD, gend, lvl, prog)
{}

//Destructor for TA
TeachingAst::~TeachingAst(){}

/*************************************
/assignCourse()
/
/Assigns acourse to the TA
**************************************/
void TeachingAst::assignCourse(Course * course)
{
	TACourses.push_back(course);
}

/*************************************
/getTACourse()
/
/Returns the teachers role (adjunct, professor, etc)
**************************************/
Course &TeachingAst::getTACourse(int num)
{
	return *TACourses[num];
}

/*************************************
/removeTACourse()
/
/Returns the course
**************************************/
void TeachingAst::removeTACourse(int num)
{
	if ((num >= 0) && (num <= numCourses()))
	{
		TACourses.erase(TACourses.begin() + num);
	}
	else
	{
		cerr << "Index for removing course is out of range." << endl;
		exit(0);
	}
}

/*************************************
/numTACourses()
/
/Returns the number of  courses the TA is a TA for
**************************************/
int TeachingAst::numTACourses()
{
	return TACourses.size();
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
	for (int i = 0; i < this->numTACourses(); i++)
	{
		cout << TACourses[i]->getSubject() << " " << TACourses[i]->getNumber() << endl;
	}
}
