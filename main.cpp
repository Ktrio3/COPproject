/***********************************************

***********************************************/

#include <iostream>
#include <fstream>
#include <vector>
#include <map>
#include <iomanip>
#include <string>

#include "Person.h"
#include "Student.h"
#include "Teacher.h"
#include "UGradStudent.h"
#include "GradStudent.h"
#include "ResearchAst.h"
#include "TeachingAst.h"
#include "Course.h"
#include "Department.h"

using namespace std;

int main(void)
{
  map<int, Student> students; //May want to make map with UID as key.
  map<int, Teacher> teachers; //Map will make it very easier to add to course after reading.
  vector<Course> courses;
  vector<Department> departments;


  ifstream file("Students.txt", ios::in);
  //Read in student
  while(true)
  {
    //Variables for Student constructor
    string name = "";
    string lvl;
    string role;
    string id;
    string date;
    string gender;
    string program = "";

    string junk; //Used to discard extra \n char at end of line

    getline(file, name, '|');

    if(name == "") //End of file if no name found
      break;

    getline(file, lvl, '|');
    getline(file, role, '|');
    getline(file, id, '|');
    getline(file, date, '|');
    getline(file, gender, '|');
    getline(file, program, '|');
    getline(file, junk); //Ignore \n

    cout << name << endl;
    cout << lvl << endl;
    cout << role << endl;
    cout << id << endl;
    cout << date << endl;
    cout << gender << endl;
    cout << program << endl << endl;

    std::string::size_type sz;
    if(role == "U")
      students.insert(make_pair(stoi(id), UGradStudent(stoi(id), name, date, gender, lvl, program)));
  }

  //Test if SavingsAccount
  //UGradStudent *student =
  //  dynamic_cast < UGradStudent * > (&(students[0]));

  Student student = UGradStudent(0, "Kevin", "00/11/11", "M", "PHD", "Physophy");
  student.print();

  file.close();
  //Open teachers file
  //Read in teachers

  //TAs

  //Read in courses
  //file.open("Courses.txt");

  /*while(!file.eof())
  {
    string swag;
    file >> swag >> swag >> swag >> swag >> swag >> swag >> swag >> swag >> swag >> swag >> swag >> swag >> swag >> swag >> swag >> swag >> swag >> swag >> swag >> swag >> swag >> swag >> swag >> swag >> swag >> swag >> swag >> swag;
  }*/

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
