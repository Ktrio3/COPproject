//********************************************
// File name: Department.h
// Purpose: Header file for Department class
// Authors: Kevin Dennis and V. Liana Peralta
//********************************************
#ifndef DEPARTMENT_H
#define DEPARTMENT_H

#include "Person.h"
#include "Course.h"
#include <vector>
#include <string>

using namespace std;

class Department
{
public:
  Department(string title);
  ~Department();

  void addMember(Person *person); //Adds a member to the department
  Person &getMember(int num); //Returns the member at position num
  int numMembers(); //Returns the number of members in the department

  void addCourse(Course *); //Adds a course to the department
  Course &getCourse(int num); //Returns the course at position num
  int numCourses(); //Returns the number of courses

  void setName(string newName);
  string getName();

  void print(); //Prints info about the department
  void printMembers();  //Prints the members in the department
  void printCourses();  //Prints the courses in the department

private:
  string name; //The name of the department i.e. Nursing
  vector<Person *> members; //Contains the people in the department
  vector<Course *> courses; //Contatins the courses in the department
};

#endif
