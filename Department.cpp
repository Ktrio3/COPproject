//********************************************
// File name: Department.cpp
// Purpose: Contains function definitions for class Department from Department.h
// Authors: Kevin Dennis and V. Liana Peralta
//********************************************
#include "Department.h"
#include <string>
#include <iostream>

using namespace std;

Department::Department(string newName) : name(newName)
{
}

Department::~Department()
{
}

/*************************************
/addMember()
/
/Adds a Student to the department by pushing onto members vector.
**************************************/
void Department::addMember(Student *student)
{
  members.push_back(student);
}

/*************************************
/addFaculty()
/
/Adds a Teacher to the department by pushing onto faculty vector.
**************************************/
void Department::addFaculty(Teacher *teacher)
{
  faculty.push_back(teacher);
}

/*************************************
/getMember()
/
/Returns the student at position num
**************************************/
Student &Department::getMember(int num)
{
	if ((num >= 0) && (num <= numMembers()))
	{
		return *members[num];
	}
  	else
  	{
  		cerr << "Index for getting member is out of range." << endl;
	}
}

/*************************************
/getFaculty()
/
/Returns the teacher at position num
**************************************/
Teacher &Department::getFaculty(int num)
{
	if ((num >= 0) && (num <= numFaculty()))
	{
		return *faculty[num];
	}
  	else
  	{
  		cerr << "Index for getting faculty member is out of range." << endl;
	}
}

/*************************************
/numMembers()
/
/Returns the number of students in the department
**************************************/
int Department::numMembers()
{
  return members.size();
}

/*************************************
/numFaculty()
/
/Returns the number of teachers in the department
**************************************/
int Department::numFaculty()
{
  return faculty.size();
}

/*************************************
/addCourse()
/
/Adds a course to the department
**************************************/
void Department::addCourse(Course *course)
{
  courses.push_back(course);
}


/*************************************
/getCourse()
/
/Returns the course at position num
**************************************/
Course &Department::getCourse(int num)
{
	if ((num >= 0) && (num <= numCourses()))
	{
		return *courses[num];
	}
  	else
  	{
  		cerr << "Index for getting course is out of range." << endl;
	}
}


/*************************************
/numCourses()
/
/Returns the number of  courses in the Department
**************************************/
int Department::numCourses()
{
  return courses.size();
}


/*************************************
/setName()
/
/Sets the name of the department
**************************************/
void Department::setName(string newName)
{
  name = newName;
}


/*************************************
/getName()
/
/Returns the name of the department
**************************************/
string Department::getName()
{
  return name;
}


/*************************************
/print()
/
/Prints the department information
**************************************/
void Department::print()
{
  cout << this->getName();
}

/*************************************
/printMembers()
/
/Prints the students of the department
**************************************/
void Department::printMembers()
{
  for(Student *student : members)
  {
    student->print();
    cout << endl;
  }
}

/*************************************
/printFaculty()
/
/Prints the teachers of the department
**************************************/
void Department::printFaculty()
{
  for(Teacher *teacher : faculty)
  {
    teacher->print();
    cout << endl;
  }
}

/*************************************
/printCourses()
/
/Prints the courses of the department
**************************************/
void Department::printCourses()
{
  for(Course *course : courses)
  {
    course->print();
    cout << endl;
  }
}
