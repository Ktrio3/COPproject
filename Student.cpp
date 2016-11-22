//********************************************
// File name: Student.cpp
// Purpose: Source code for Student class
// Authors: Kevin Dennis and V. Liana Peralta
//********************************************

#include <iostream>
#include <string>
#include <vector>
#include "Course.h"
#include "Student.h"

using namespace std;

//Constructor for student
Student::Student(int UnivID, string fullname, string BD, string gend, string lvl) : Person(UnivID, fullname, BD, gend)
{
	level = lvl;
}

/*************************************
/registerCrs()
/
/Adds a course to the students schedule
**************************************/
void Student::registerCrs(Course *course)
{
	schedule.push_back(course);
}

/*************************************
/getCourse()
/
/Returns the course at position num
**************************************/
Course &Student::getCourse(int num)
{
	if ((num >= 0) && (num <= numCourses()))
	{
		return *schedule[num];
	}
  else
  {
  		cerr << "Index for getting course is out of range." << endl;
			exit(0);
	}
}

/*************************************
/numCourses()
/
/Returns the number of  courses the student is enrolled in
**************************************/
int Student::numCourses()
{
  return schedule.size();
}

/*************************************
/print()
/
/Prints information about the student
**************************************/
void Student::print()
{
	this->Person::print();
	cout << " Degree Type: " << level;
}

/*************************************
/printCourses()
/
/Prints information about the student
**************************************/
void Student::printCourses()
{
	for (int i = 0; i < numCourses(); i++)
	{
		cout << schedule[i]->getSubject() << " " << schedule[i]->getNumber() << endl;
	}
}

/*************************************
/getLvl()
/
/Returns the degree type of the student
**************************************/
string Student::getLvl()
{
	return level;
}

/*************************************
/setLvl()
/
/Sets the level (degree type) of the student
**************************************/
void Student::setLvl(string lvl)
{
	level = lvl;
}

//Destructor for student
Student::~Student(){};
