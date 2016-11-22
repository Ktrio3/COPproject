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
Teacher::Teacher(int UnivID, string fullname, string BD, string gend, string rol)
: Person(UnivID, fullname, BD, gend), role(rol)
{
}

//Destructor for teacher
Teacher::~Teacher()
{
}

/*************************************
/setRole()
/
/Sets the teachers role
**************************************/
void Teacher::setRole(string newRole)
{
	role = newRole;
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
/assignCourse()
/
/Adds a course to the students schedule
**************************************/
void Teacher::assignCourse(Course *course)
{
	lectures.push_back(course);
}

/*************************************
/getCourse()
/
/Returns the course
**************************************/
Course &Teacher::getCourse(int num)
{
	if ((num >= 0) && (num <= numCourses()))
	{
		return *lectures[num];
	}
  else
  {
  		cerr << "Index for getting course is out of range." << endl;
			exit(0);
	}
}

/*************************************
/removeCourse()
/
/Returns the course
**************************************/
void Teacher::removeCourse(int num)
{
	if ((num >= 0) && (num <= numCourses()))
	{
		lectures.erase(lectures.begin() + num);
	}
	else
	{
		cerr << "Index for removing course is out of range." << endl;
		exit(0);
	}
}

/*************************************
/numCourses()
/
/Returns the number of  courses the teacher is teaching
**************************************/
int Teacher::numCourses()
{
  return lectures.size();
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
		cout << lectures[i]->getSubject() << " " << lectures[i]->getNumber() << endl;
	}
}
