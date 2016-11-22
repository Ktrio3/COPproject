//********************************************
// File name: Teacher.cpp
// Purpose: Source code for Teacher class
// Authors: Kevin Dennis and V. Liana Peralta
//********************************************

#include <iostream>
#include <string>
#include <vector>
#include "Course.h"
#include "Teacher.h"

//Constructor for teacher
Teacher::Teacher(int UnivID, string fullname, string BD, string gend, string rol) : Person(UnivID, fullname, BD, gend)
{
	role = rol;
}

/*************************************
/getRole()
/
/Returns the teachers role (adjunct, professor, etc)
**************************************/
string Teacher::getRole()
{
	return role;
}

/*************************************
/assignCrs()
/
/Adds a course to the students schedule
**************************************/
void Teacher::assignCourse(Course *course)
{
	Lectures.push_back(course);
}

/*************************************
/numCourses()
/
/Returns the number of  courses the teacher is teaching
**************************************/
int Teacher::numCourses()
{
  return Lectures.size();
}

/*************************************
/print()
/
/Prints information about the teacher
**************************************/
void Teacher::print()
{
	this->Person::print();
	cout << " Position: " << this->getRole();
}

/*************************************
/printCourses()
/
/Prints the courses the teacher is assigned to
**************************************/
void Teacher::printCourses()
{
	for (int i = 0; i < numCourses(); i++)
	{
		cout << Lectures[i]->getSubject() << " " << Lectures[i]->getNumber() << endl;
	}
}

//Destructor for teacher
Teacher::~Teacher(){};
