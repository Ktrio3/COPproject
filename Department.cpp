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
/Adds a Person to the departmentby pushing onto members vector.
**************************************/
void Department::addMember(Person *person)
{
  members.push_back(person);
}

/*************************************
/getMember()
/
/Returns the person at position num
**************************************/
Person &Department::getMember(int num)
{
  return *members[num];
}

/*************************************
/numMembers()
/
/Returns the numbers of members in the department
**************************************/
int Department::numMembers()
{
  return members.size();
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
  return *courses[num];
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

}

/*************************************
/printMembers()
/
/Prints the members of the department
**************************************/
void Department::printMembers()
{

}

/*************************************
/printCourses()
/
/Prints the courses of the department
**************************************/
void Department::printCourses()
{

}
