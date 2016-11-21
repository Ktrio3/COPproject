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

  void addMember(Student *student); //Adds a student to the department
  void addFaculty(Teacher *teacher); //Adds a teacher to department's faculty
  Student &getMember(int num); //Returns the student at position num
  Teacher &getFaculty(int num); //Returns the teacher at position num
  int numMembers(); //Returns the number of students in the department
  int numFaculty(); //Returns the number of teachers in the department

  void addCourse(Course *); //Adds a course to the department
  Course &getCourse(int num); //Returns the course at position num
  int numCourses(); //Returns the number of courses

  void setName(string newName);
  string getName();

  void print(); //Prints info about the department
  void printMembers();  //Prints the students in the department
  void printFaculty();  //Prints the teachers in the department
  void printCourses();  //Prints the courses in the department

private:
  string name; //The name of the department i.e. Nursing
  vector<Teacher *> faculty; //Contains the teachers in the department
  vector<Student *> members; //Contains the students in the department
  vector<Course *> courses; //Contatins the courses in the department
};

#endif
