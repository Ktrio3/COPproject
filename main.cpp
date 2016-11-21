//********************************************
// File name: main.cpp
// Purpose: Reads in Students, Courses, Teachers, and Departments from txt
//    files and runs them through testing
// Authors: Kevin Dennis and V. Liana Peralta
//********************************************

#include <iostream>
#include <fstream>
#include <vector>
#include <map>
#include <iomanip>

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
  map<int, Student *> students; //May want to make map with UID as key.
  typedef std::map<int, Student *>::iterator student_iter; //For iterating over students map
  map<int, Teacher *> teachers; //Map will make it very easier to add to course after reading.
  typedef std::map<int, Teacher *>::iterator teacher_iter; //For iterating over students map
  vector<Course *> courses;
  vector<Department *> departments;

  //Open Students.txt file
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

    if(role == "U")
    {
      UGradStudent *student = new UGradStudent(stoi(id), name, date, gender, lvl, program);
      students.insert(make_pair(stoi(id), student));
    }
    else if(role == "TA")
    {
      TeachingAst *student = new TeachingAst(stoi(id), name, date, gender, lvl, program);
      students.insert(make_pair(stoi(id), student));
    }
    else if(role == "RA")
    {
      //Read in the extra project specific to RA
      string project;
      getline(file, project, '|');
      ResearchAst *student = new ResearchAst(stoi(id), name, date, gender, lvl, program, project);
      students.insert(make_pair(stoi(id), student));
    }

    getline(file, junk); //Ignore \n at end of line
  }

  file.close();

  //Print students
  cout << "Scanned in the following students from Students.txt:\n";
  for(student_iter iterator = students.begin(); iterator != students.end(); iterator++) {
    //Test if undergraduate student
    UGradStudent *underStudent = dynamic_cast < UGradStudent * > (iterator->second);
    if(underStudent != nullptr)
    {
      underStudent->print();
    }

    TeachingAst *TA = dynamic_cast < TeachingAst * > (iterator->second);
    if(TA != nullptr)
    {
      TA->print();
    }

    ResearchAst *RA = dynamic_cast < ResearchAst * > (iterator->second);
    if(RA != nullptr)
    {
      RA->print();
    }
    cout << "\n";
  }
  cout << "\n";

  //Open Teachers.txt file
  file.open("Teachers.txt");

  //Read in teachers
  while(true)
  {
    //Variables for Teacher constructor
    string name = "";
    string role;
    string id;
    string date;
    string gender;
    string junk; //Used to discard extra \n char at end of line

    getline(file, name, '|');

    if(name == "") //End of file if no name found
      break;

    getline(file, role, '|');
    getline(file, id, '|');
    getline(file, date, '|');
    getline(file, gender, '|');
    getline(file, junk); //Ignore \n

    //Declare and instantiate teacher objects
    Teacher *teacher = new Teacher(stoi(id), name, date, gender, role);
    teachers.insert(make_pair(stoi(id), teacher));
  }
  file.close();

  //Print teachers
  cout << "Scanned in the following teachers from Teachers.txt:\n";
  for(teacher_iter iterator_t = teachers.begin(); iterator_t != teachers.end(); iterator_t++) {
  	Teacher *teach = iterator_t->second;
    if(teach != nullptr)
    {
      teach->print();
      cout << endl;
    }
  }
  cout << endl;

  //Open Courses.txt file
  file.open("Courses.txt");

  //Read in courses
  while(true)
  {
    //Variables for Course constructor
    string subject = "";
    string number;
    string credits;
    string lvl;
    string title;
    string instructors;
    string teachAsts;
    string pupils;
    string junk; //Used to discard extra \n char at end of line

    getline(file, subject, '|');

    if(subject == "") //End of file if no name found
      break;

    getline(file, number, '|');
    getline(file, credits, '|');
    getline(file, lvl, '|');
    getline(file, title, '|');
    getline(file, instructors, '|');
    getline(file, teachAsts, '|');
    getline(file, pupils, '|');
    getline(file, junk); //Clear \n at end of line

    //Declare and instantiate course objects
    Course *course = new Course(subject, stoi(number), stoi(credits), lvl, title);
    courses.push_back(course);

  	//Seperate teachers string into separate teachers
  	int start = 0;
  	int end = instructors.find(',');
  	string token = "";

  	while (end != -1)
  	{
  		token = instructors.substr(start, end);
  		course->assignTeacher(teachers[stoi(token)]);	//Assign each teacher to course based on UID

      start = end + 1;
      end = instructors.find(',', start);
    }

    //Read in final (or only) value, if any present
    if(end == -1 && pupils.length() != 0)
    {
      token = instructors.substr(start, instructors.length());
      course->assignTeacher(teachers[stoi(token)]);
    }

	  //Seperate teachAsts string into separate TAs
  	start = 0;
  	end = teachAsts.find(',');

  	while (end != -1)
  	{
  		token = teachAsts.substr(start, end);
  		start = end + 1;
  		end = teachAsts.find(',', start);

      TeachingAst *TA = dynamic_cast < TeachingAst * > (students[stoi(token)]);
      if(TA != nullptr)
      {
        course->assignTA(TA);	//Assign each TA to course based on UID
      }
    }

    //Read in final (or only) value, if any present
    if(end == -1 && pupils.length() != 0)
    {
      token = teachAsts.substr(start, teachAsts.length());

      TeachingAst *TA = dynamic_cast < TeachingAst * > (students[stoi(token)]);
      if(TA != nullptr)
      {
        course->assignTA(TA);	//Assign each TA to course based on UID]
      }
    }

  	//Seperate pupils string into separate students
  	start = 0;
  	end = pupils.find(',');

  	while (end != -1)
  	{
  		token = pupils.substr(start, end);
  		start = end + 1;

  		course->addStudent(students[stoi(token)]);	//Add each student to course roster based on UID
      students[stoi(token)]->registerCrs(course);  //Add course to students schedule

      end = pupils.find(',', start);
    }

    //Read in final (or only) value, if any present
    if (end == -1 && pupils.length() != 0)
    {
      token = pupils.substr(start, pupils.length());
      course->addStudent(students[stoi(token)]);
      students[stoi(token)]->registerCrs(course);  //Add course to students schedule
    }
  }

  file.close();

  //Print courses
  cout << "Scanned in the following courses from Courses.txt:\n";
  for(Course *course : courses)
  {
      course->print();
      cout << endl;
  }
  cout << endl;

  //Read in departments

  //Once in, add members by UID and course by subj/num

  //Print departments

  //Print the students in a course
  cout << "Printing students in " << courses[0]->getTitle() << ":" << endl;
  courses[0]->printRoster();
  cout << endl;

  //Print the grades for a student in the course
  cout << "Printing grades for students in " << courses[0]->getTitle() << ":" << endl;
  courses[0]->printGradebook();
  cout << endl;

  //Change the grade for a student in the course
  cout << "Changing grade for " << courses[0]->getStudent(0).getName() << " in "
    << courses[0]->getTitle() << " to a 105%:" << endl;
  courses[0]->assignGrade(courses[0]->getStudent(0).getUID(), 105);
  courses[0]->printGradebook();
  cout << endl;

  //Add Student to the course
  cout << "Creating a new Undergrad Student named Study McFake and enrolling in "
    << courses[0]->getTitle() << ":" << endl;
  UGradStudent *newStudent = new UGradStudent(100056, "Study McFake", "01/11/1992", "M", "BS", "Computer Engineering");
  students.insert(make_pair(newStudent->getUID(), newStudent)); //Add student to our map
  courses[0]->addStudent(newStudent); //Add student to course
  newStudent->registerCrs(courses[0]);  //Add course to students schedule
  courses[0]->printRoster();
  cout << endl;

  //Print instructors
  cout << "Printing instructor(s) for " << courses[0]->getTitle() << ":" << endl;
  courses[0]->printTeachers();
  cout << endl;

  //Add instructor to the course
  cout << "Creating a new professor named Teachy McFake and assigning to "
    << courses[0]->getTitle() << ":" << endl;
  Teacher *newTeacher = new Teacher(100021, "Teachy McFake", "01/11/1992", "M", "Professor");
  teachers.insert(make_pair(newTeacher->getUID(), newTeacher)); //Add teacher to our map
  courses[0]->assignTeacher(newTeacher); //Add teacher to course
  newTeacher->assignCourse(courses[0]);  //Add course to teachers schedule
  courses[0]->printTeachers();
  cout << endl;

  //Print TA for the course
  cout << "Printing TA(s) for " << courses[0]->getTitle() << ":" << endl;
  courses[0]->printTAs();
  cout << endl;

  //Add TA to the course

  //Print Department members

  //Print department courses

  //Add member to department

  //Add course to department
}
