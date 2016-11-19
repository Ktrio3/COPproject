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
  void addMember(Person *person);

  Person &getMember(int num);

  int numMembers();

  void addCourse(Course *);

  Course &getCourse(int num);

  int numCourses();

  void setName(string newName);

  string getName();

  void print();
private:
  string name;
  vector<Person *> members;
  vector<Course *> courses;

};

#endif
