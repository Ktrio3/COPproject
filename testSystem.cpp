/***********************************************

***********************************************/

#include <iostream>
#include <fstream>
#include <vector>
#include <iomanip>

//#include "Person.h"
//#include "Student.h"
//#include "Teacher.h"
//#include "UGradStudent.h"
//#include "GradStudent.h"
//#include "ResearchAst.h"
//#include "TeachingAst.h"
#include "Course.h"
//#include "Department.h"

using namespace std;

int main(void)
{
  //vector<Student *> students; //May want to make map with UID as key.
  //vector<Teacher *> teachers; //Map will make it very easier to add to course after reading.
  //vector<Course *> courses;
  //vector<Department *> departments;
  ifstream file;

  //Open student file
  file.open("Students.txt");
  //Read in student

  file.close();
  //Open teachers file
  //Read in teachers

  //TAs

  cout << "It ran...";

  //Read in courses
  file.open("Courses.txt");

  while(!file.eof())
  {
    string prefix2;
    int number;
    int lvl;
    file >> prefix2;
    file >> number;
    file >> lvl;

    cout << prefix2 << number;
  }



  //Once course read in, add students by UID in file
  file.close();

  //Read in departments
  //Once in, add members by UID and course by subj/num

  //Print students

  //Print teachers

  //Print courses

  //Print departments

  //Print the students in a course

  //Print the grades for a student in the course

  //Change the grade for a student in the course

  //Print TA for the course

  //Add TA to the course

  //Add instructor to the course

  //Print Department members

  //Print department courses

  //Add member to department

  //Add course to department
}
