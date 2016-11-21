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

//Delete dynamic memory
//Making sure files are opening
//Check functions in classes -- ie some of the basic ones we don't use have no definition
//Add some more silly functions
//Clean up/style comments

int main(void)
{
  map<int, Student *> students; //May want to make map with UID as key.
  typedef std::map<int, Student *>::iterator student_iter; //For iterating over students map
  map<int, Teacher *> teachers; //Map will make it very easier to add to course after reading.
  typedef std::map<int, Teacher *>::iterator teacher_iter; //For iterating over students map
  map<string, Course *> courses; //Map will make it very easier to add to department after reading.
  typedef std::map<string, Course *>::iterator course_iter; //For iterating over students map
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
    courses.insert(make_pair(subject + ' ' + number, course));

  	//Seperate teachers string into separate teachers
  	int start = 0;
  	int end = instructors.find(',');
  	string token = "";

    //If instructors have been assigned to the course, read in each
  	while (end != -1 && instructors.length() != 0)
  	{
  		token = instructors.substr(start, end - start);
  		course->assignTeacher(teachers[stoi(token)]);	//Assign each teacher to course based on UID

      start = end + 1;
      end = instructors.find(',', start);
    }

    //Read in final (or only) value, if any present
    if(end == -1 && pupils.length() != 0)
    {
      token = instructors.substr(start, instructors.length() - start);
      course->assignTeacher(teachers[stoi(token)]);
    }

	  //Seperate teachAsts string into separate TAs
  	start = 0;
  	end = teachAsts.find(',');

  	while (end != -1 && teachAsts.length() != 0) //A course may not have a TA
  	{
  		token = teachAsts.substr(start, end - start);
  		start = end + 1;
  		end = teachAsts.find(',', start);

      TeachingAst *TA = dynamic_cast < TeachingAst * > (students[stoi(token)]);
      if(TA != nullptr)
      {
        course->assignTA(TA);	//Assign each TA to course based on UID
      }
    }

    //Read in final (or only) value, if any present
    if(end == -1 && teachAsts.length() != 0)
    {
      token = teachAsts.substr(start, teachAsts.length() - start);

      TeachingAst *TA = dynamic_cast < TeachingAst * > (students[stoi(token)]);
      if(TA != nullptr)
      {
        course->assignTA(TA);	//Assign each TA to course based on UID]
      }
    }

  	//Seperate pupils string into separate students
  	start = 0;
  	end = pupils.find(',');
  	int end2;
  	string grd_token = "";
  	string uid_token = "";

  	while(end != -1 && pupils.length() != 0) //A course may not have students yet
  	{
  		token = pupils.substr(start, end - start);
      end2 = token.find(':', 0);
  		uid_token = token.substr(0, end2); //Separate student's uid from token
  		grd_token = token.substr(end2+1, token.length() - end2+1); //Separate student's grade from token

  		course->addStudent(students[stoi(uid_token)]);	//Add each student to course roster based on UID
  		course->assignGrade(stoi(uid_token), stoi(grd_token)); //Add student's grade to course's gradebook

      students[stoi(uid_token)]->registerCrs(course);  //Add course to students schedule

      start = end + 1;
      end = pupils.find(',', start);
    }

    //Read in final (or only) value, if any present
    if (end == -1 && pupils.length() != 0)
    {
      token = pupils.substr(start, pupils.length() - start);
      end2 = token.find(':', 0);
  		uid_token = token.substr(0, end2); //Separate student's uid from token
  		grd_token = token.substr(end2+1, token.length() - end2+1); //Separate student's grade from token

      course->addStudent(students[stoi(uid_token)]);	//Add each student to course roster based on UID
  		course->assignGrade(stoi(uid_token), stoi(grd_token)); //Add student's grade to course's gradebook

      students[stoi(uid_token)]->registerCrs(course);  //Add course to students schedule
    }
  }

  file.close();

  //Print courses
  cout << "Scanned in the following courses from Courses.txt:\n";
  for(course_iter iterator_t = courses.begin(); iterator_t != courses.end(); iterator_t++) {
  	Course *course = iterator_t->second;
    if(course != nullptr)
    {
      course->print();
      cout << endl;
    }
  }
  cout << endl;

  //Read in departments
  file.open("Departments.txt");

  //Read in department
  while(true)
  {
    //Variables for Department constructor
    string deptname = "";
    string fclty;
    string mems;
    string crses;
    string junk; //Used to discard extra \n char at end of line

    getline(file, deptname, '|');

    if(deptname == "") //End of file if no name found
      break;

    getline(file, fclty, '|');
    getline(file, mems, '|');
    getline(file, crses, '|');
    getline(file, junk); //Clear \n at end of line

    //Declare and instantiate department objects
    Department *dept = new Department(deptname);
    departments.push_back(dept);

  	//Separate fclty string into separate faculty members of department
  	int start = 0;
  	int end = fclty.find(',');

  	while (end != -1 && fclty.length() != 0)
  	{
  		string token = fclty.substr(start, end - start);
  		dept->addFaculty(teachers[stoi(token)]);	//Assign each teacher to dept's faculty based on UID

      start = end + 1;
      end = fclty.find(',', start);
    }

    //Read in final (or only) value, if any present
    if(end == -1 && crses.length() != 0)
    {
      string token = fclty.substr(start, fclty.length() - start);
      dept->addFaculty(teachers[stoi(token)]);
    }

    //Separate mems string into separate student members of department
  	start = 0;
  	end = mems.find(',');

  	while (end != -1 && mems.length() != 0)
  	{
  		string token = mems.substr(start, end - start);
  		dept->addMember(students[stoi(token)]);	//Assign each student to dept based on UID

      start = end + 1;
      end = mems.find(',', start);
    }

    //Read in final (or only) value, if any present
    if(end == -1 && crses.length() != 0)
    {
      string token = mems.substr(start, mems.length() - start);
      dept->addMember(students[stoi(token)]);
    }

    //Separate crses string into separate courses for department
  	start = 0;
  	end = crses.find(',');

  	while (end != -1 && crses.length() != 0)
  	{
  		string token = crses.substr(start, end - start);
  		dept->addCourse(courses[token]);	//Assign each student to dept based on UID
		//(Note: Need to make courses vector into map for this to work... can 1st element of map be a string?.. can we merge subj and crs #?
      start = end + 1;
      end = crses.find(',', start);
    }

    //Read in final (or only) value, if any present
    if(end == -1 && crses.length() != 0)
    {
      string token = crses.substr(start, crses.length() - start);
      dept->addCourse(courses[token]);//    (Same issue as above)
    }
  }

  file.close();
  //Print departments
  cout << "Scanned in the following departments from Departments.txt:\n";
  for(Department *department : departments)
  {
    department->print();
    cout << endl;
  }
  cout << endl;

  Course *testCourse = nullptr;
  //Find a course with students in it for testing purposes
  for(course_iter iterator_t = courses.begin(); iterator_t != courses.end(); iterator_t++) {
  	Course *course = iterator_t->second;
    if(course->numStudents() != 0)
    {
      testCourse = course;
      break;
    }
  }

  //If there was course with students, print. Else, skip this
  if(testCourse != nullptr)
  {
    //Print the students in a course
    cout << "Printing students in " << testCourse->getTitle() << ":" << endl;
    testCourse->printRoster();
    cout << endl;

    //Print the grades for a student in the course
    cout << "Printing grades for students in " << testCourse->getTitle() << ":" << endl;
    testCourse->printGradebook();
    cout << endl;
  }
  else
  {
    cout << "No courses in Courses.txt started with students. Adding students now..." << endl;
    testCourse = courses.begin()->second;
  }

  //Add Student to the course
  cout << "Creating a new Undergrad Student named Study McFake and enrolling in "
    << testCourse->getTitle() << ":" << endl;
  UGradStudent *newStudent = new UGradStudent(100056, "Study McFake", "01/11/1992", "M", "BS", "Computer Engineering");
  students.insert(make_pair(newStudent->getUID(), newStudent)); //Add student to our map
  testCourse->addStudent(newStudent); //Add student to course
  newStudent->registerCrs(testCourse);  //Add course to students schedule
  testCourse->printRoster();
  cout << endl;

  //Change the grade for the last student entered in the course. Should be McFake
  int lastStudent = testCourse->numStudents() - 1;
  cout << "Changing grade for " << testCourse->getStudent(lastStudent).getName() << " in "
    << testCourse->getTitle() << " to a 105%:" << endl;
  testCourse->assignGrade(testCourse->getStudent(lastStudent).getUID(), 105);
  testCourse->printGradebook();
  cout << endl;

  if(testCourse->numTeachers() == 0)
  {
    testCourse = nullptr;
    for(course_iter iterator_t = courses.begin(); iterator_t != courses.end(); iterator_t++) {
    	Course *course = iterator_t->second;
      if(course->numTeachers() != 0)
      {
        testCourse = course;
        break;
      }
    }
  }

  if(testCourse != nullptr)
  {
    //Print instructors
    cout << "Printing instructor(s) for " << testCourse->getTitle() << ":" << endl;
    testCourse->printTeachers();
    cout << endl;
  }
  else
  {
    cout << "No courses in Courses.txt contained instructors. Creating one now..." << endl;
    testCourse = courses.begin()->second;
  }

  //Add instructor to the course
  cout << "Creating a new professor named Teachy McFake and assigning to "
    << testCourse->getTitle() << ":" << endl;
  Teacher *newTeacher = new Teacher(100021, "Teachy McFake", "01/11/1992", "M", "Professor");
  teachers.insert(make_pair(newTeacher->getUID(), newTeacher)); //Add teacher to our map
  testCourse->assignTeacher(newTeacher); //Add teacher to course
  newTeacher->assignCourse(testCourse);  //Add course to teachers schedule
  testCourse->printTeachers();
  cout << endl;

  if(testCourse->numTAs() == 0)
  {
    testCourse = nullptr;
    for(course_iter iterator_t = courses.begin(); iterator_t != courses.end(); iterator_t++) {
    	Course *course = iterator_t->second;
      if(course->numTAs() != 0)
      {
        testCourse = course;
        break;
      }
    }
  }

  if(testCourse != nullptr)
  {
    //Print TA for the course
    cout << "Printing TA(s) for " << testCourse->getTitle() << ":" << endl;
    testCourse->printTAs();
    cout << endl;
  }
  else
  {
    cout << "No courses in Courses.txt started with TAs. Adding a TA now..." << endl;
    testCourse = courses.begin()->second;
  }

  //Add TA to the course
  cout << "Creating a new TA named TA McFake and assigning to "
    << testCourse->getTitle() << ":" << endl;
  TeachingAst *newTA = new TeachingAst(100011, "TA McFake", "01/11/1992", "M", "MS", "Cybersecurity");
  students.insert(make_pair(newTA->getUID(), newTA)); //Add TA to our map
  testCourse->assignTA(newTA); //Add teacher to course
  newTA->assignCourse(testCourse);  //Add course to teachers schedule
  testCourse->printTAs();
  cout << endl;

  //Find a department with members
  Department *testDept = nullptr;
  for(Department *department : departments) {
    if(department->numMembers() != 0)
    {
      testDept = department;
      break;
    }
  }

  //Print Department members
  if(testDept != nullptr)
  {
    cout << "Printing student member(s) for " << testDept->getName() << ":" << endl;
    testDept->printMembers();
    cout << endl;
  }
  else
  {
    cout << "No departments in Departments.txt started with members. Adding a member now..." << endl;
    testDept = departments[0];
  }

  //Add member to department
  cout << "Adding Study McFake to " << testDept->getName() << ":" << endl;
  testDept->addMember(newStudent);
  testDept->printMembers();
  cout << endl;

  //Print department faculty
  if(testDept->numFaculty() == 0)
  {
    for(Department *department : departments) {
      if(department->numFaculty() != 0)
      {
        testDept = department;
        break;
      }
    }
  }

  //Print Department faculty
  if(testDept != nullptr)
  {
    cout << "Printing faculty for " << testDept->getName() << ":" << endl;
    testDept->printFaculty();
    cout << endl;
  }
  else
  {
    cout << "No departments in Departments.txt started with faculty. Adding a faculty member now..." << endl;
    testDept = departments[0];
  }

  //Add faculty to department
  cout << "Adding Teachy McFake to " << testDept->getName() << ":" << endl;
  testDept->addFaculty(newTeacher);
  testDept->printFaculty();
  cout << endl;

  //Check if department has courses
  if(testDept->numCourses() == 0)
  {
    for(Department *department : departments) {
      if(department->numCourses() != 0)
      {
        testDept = department;
        break;
      }
    }
  }

  //Print Department courses
  if(testDept != nullptr)
  {
    cout << "Printing course(s) for " << testDept->getName() << ":" << endl;
    testDept->printCourses();
    cout << endl;
  }
  else
  {
    cout << "No departments in Departments.txt started with courses. Adding a course now..." << endl;
    testDept = departments[0];
  }

  //Add course to department
  cout << "Creating a new Course, Underwater Scuba Golfing, and adding to " << testDept->getName() << ":" << endl;
  Course newCourse = Course("SCU", 1234, 4, "U", "Underwater Scuba Golfing");
  string newCourseKey = newCourse.getSubject() + " " + to_string(newCourse.getNumber());
  courses.insert(make_pair(newCourseKey, &newCourse)); //Add Course to our map
  testDept->addCourse(&newCourse); //Add course to department
  testDept->printCourses();
  cout << endl;
}
