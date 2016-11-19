#ifndef COURSE_H
#define COURSE_H

#include "Student.h"
#include "Teacher.h"
#include "TeachingAst.h"

#include <vector>
#include <map>
#include <string>

using namespace std;

class Course
{
public:
  Course(string subj, int num, int cred, char level, string newTitle);
  ~Course();

  void assignTA(TeachingAst *TA);
  void assignTeacher(Teacher *teacher);
  void addStudent(Student *student);

  Teacher &getTeacher(int num);
  Student &getStudent(int num);
  TeachingAst &getTA(int num);

  void removeTeacher(int num);
  void removeStudent(int num);
  void removeTA(int num);

  int getGrade(int studentID);
  void assignGrade(int studentID, int grade);

  void print();

  void setSubject(string subj);
  string getSubject();

  void setNumber(int num);
  int getNumber();

  void setCredits(int newCredits);
  int getCredits();

  void setLvl(char newLvl);
  char getLvl();

  void setTitle(string newTitle);
  string getTitle();

private:
  string subject;
  int number;
  int credits;
  char lvl;
  string title;
  vector<Teacher *> instructors;
  vector<TeachingAst *> TAs;
  vector<Student *> roster;
  map<int, int, less<int> > gradeBook;

  void addGrade(int studentID);
};

#endif
