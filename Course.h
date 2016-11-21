//********************************************
// File name: Course.h
// Purpose: Header file for Course class
// Authors: Kevin Dennis and V. Liana Peralta
//********************************************

#ifndef COURSE_H
#define COURSE_H

#include "Student.h"
#include "Teacher.h"
#include "TeachingAst.h"

#include <vector>
#include <map>
#include <string>

using namespace std;

//Forward-declare classes
class Student;
class Teacher;
class TeachingAst;

class Course
{
public:
  Course(string subj, int num, int cred, string level, string newTitle);
  ~Course();

  void assignTA(TeachingAst *TA); //Assigns a TA to the course
  void assignTeacher(Teacher *teacher); //Assigns a teacher to the course
  void addStudent(Student *student);  //Registers a student to the course

  Teacher &getTeacher(int num); //Returns the teacher at position num
  Student &getStudent(int num); //Returns the Student at position num
  TeachingAst &getTA(int num);  //Returns the TA at position num

  void removeTeacher(int num);  //Removes the Teacher at position num
  void removeStudent(int num);  //Removes the Student at position num
  void removeTA(int num); //Removes the TA at position num

  int getGrade(int studentID);  //Returns the grade for the given Student
  void assignGrade(int studentID, int grade); //Changes the grade for this Student

  void print(); //Prints the course info
  void printRoster(); //Prints the name and Unumber of each student in course
  void printGradebook();  //Prints the grade of each student in the course
  void printTeachers(); //Prints the teachers for the course
  void printTAs();  //Prints TAs for the course

  void setSubject(string subj);
  string getSubject();

  void setNumber(int num);
  int getNumber();

  void setCredits(int newCredits);
  int getCredits();

  void setLvl(string newLvl);
  string getLvl();

  void setTitle(string newTitle);
  string getTitle();

private:
  string subject; //Subject (or prefix) for the course (i.e. COP)
  int number; //Number of the course (i.e. 3331)
  int credits; //Number of credits that the course is worth
  string lvl; //The lvl of the course. Either U or G
  string title; //The title of the course
  vector<Teacher *> instructors; //Vector contain Teachers for the course
  vector<TeachingAst *> TAs;  //Vector containing TAs for the course
  vector<Student *> roster; //Vector containing Students for the course
  map<int, int, less<int> > gradeBook;  //Map of grades. StudentID points to grade.

  void addGrade(int studentID); //Adds student to gradebook for first time
};

#endif
