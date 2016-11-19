#include "Department.h"
#include <string>
#include <iostream>

using namespace std;

Department::Department(string newName) : name(newName)
{
}

void Department::addMember(Person *person)
{
  members.push_back(person);
}

Person &Department::getMember(int num)
{
  return *members[num];
}

int Department::numMembers()
{
  return members.size();
}

void Department::addCourse(Course *course)
{
  courses.push_back(course);
}

Course &Department::getCourse(int num)
{
  return *courses[num];
}

int Department::numCourses()
{
  return courses.size();
}

void Department::setName(string newName)
{
  name = newName;
}

string Department::getName()
{
  return name;
}

void Department::print()
{

}
