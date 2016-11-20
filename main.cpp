/***********************************************

***********************************************/

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
    getline(file, junk); //Ignore \n

    cout << name << endl;
    cout << lvl << endl;
    cout << role << endl;
    cout << id << endl;
    cout << date << endl;
    cout << gender << endl;
    cout << program << endl << endl;

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
  }

  //Print students
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
  }

  file.close();

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

    cout << name << endl;
    cout << role << endl;
    cout << id << endl;
    cout << date << endl;
    cout << gender << endl << endl;
  }
  
    //Declare and instantiate teacher objects
    Teacher *teacher = new Teacher(stoi(id), name, date, gender, rol);
    teachers.insert(make_pair(stoi(id), teacher));

  //Print teachers
  for(teacher_iter iterator_t = teachers.begin(); iterator_t != teachers.end(); iterator_t++) {
  	Teacher *teach = iterator_t->second;
    if(teach != nullptr)
    {
      teach->print();
    }
  }

  file.close();

  //Open Courses.txt file
  file.open("Courses.txt");

  //Read in courses
  while(true)
  {
    //Variables for Course constructor
    string subject = "";
    int number;
    int credits;
    string lvl;
    string title;
    string teachers;
    string teachAsts;
    string students; 
    string junk; //Used to discard extra \n char at end of line

    getline(file, name, '|');

    if(subject == "") //End of file if no name found
      break;

    getline(file, number, '|');
    getline(file, credits, '|');
    getline(file, lvl, '|');    
    getline(file, title, '|');
    getline(file, teachers, '|');
    getline(file, teachAsts, '|');
    getline(file, students, '|');
    getline(file, junk); //Ignore \n
    
    //Create Course objects

	//Seperate teachers string into separate teachers
	int start = 0;
	int end = teachers.find(',');
	string token = "";
	
	while (end != -1)
	{
		token = teachers.substr(start, end);
		start = end + 1;
		end = teachers.find(',', start);
		if (end == -1)
		{
			token = teachers.substr(start, teachers.length());
		}
		
	}

	//Seperate teachAsts string into separate TAs
	
	//Seperate students string into separate students

    cout << name << endl;
    cout << role << endl;
    cout << id << endl;
    cout << date << endl;
    cout << gender << endl << endl;
  }

  //file.open("Courses.txt");


  //Once course read in, add students by UID in file


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
