#include "Course.h"
#include <string>
#include <iostream>

using namespace std;

Course::Course(string subj, int num, int cred, char level, string newTitle)
: subject(subj), number(num), credits(cred), lvl(level), title(newTitle)
{
}

Course::~Course()
{
}

void Course::assignTA(TeachingAst *TA)
{
  TAs.push_back(TA);
}
void Course::assignTeacher(Teacher *teacher)
{
  instructors.push_back(teacher);
}
void Course::addStudent(Student *student)
{
  roster.push_back(student);
}

Teacher &Course::getTeacher(int num)
{
  return *instructors[num];
}
Student &Course::getStudent(int num)
{
  return *roster[num];
}
TeachingAst &Course::getTA(int num)
{
  return *TAs[num];
}

void Course::removeTeacher(int num)
{
  //instructors.erase(num);
}
void Course::removeStudent(int num)
{
  int studentID = roster[num]->getUID();
  gradeBook.erase(studentID);
  roster.erase(roster.begin() + num);
}
void Course::removeTA(int num)
{
  TAs.erase(TAs.begin() + num);
}

int Course::getGrade(int studentID)
{
  return gradeBook[studentID];
}
void Course::assignGrade(int studentID, int grade)
{
  gradeBook[studentID] = grade;
}

void Course::addGrade(int studentID)
{
  gradeBook.insert( make_pair(studentID, 100) );
}

void Course::print()
{

}

void Course::setSubject(string subj)
{
  subject = subj;
}

string Course::getSubject()
{
  return subject;
}

void Course::setNumber(int num)
{
  number = num;
}

int Course::getNumber()
{
  return number;
}

void Course::setCredits(int newCredits)
{
  credits = newCredits;
}

int Course::getCredits()
{
  return credits;
}

void Course::setLvl(char newLvl)
{
  lvl = newLvl;
}

char Course::getLvl()
{
  return lvl;
}

void Course::setTitle(string newTitle)
{
  title = newTitle;
}
string Course::getTitle()
{
  return title;
}
