//********************************************
// File name: Course.cpp
// Purpose: Contains function definitions for class Course from Course.h
// Authors: Kevin Dennis and V. Liana Peralta
//********************************************

#include "Course.h"
#include <string>
#include <iostream>

using namespace std;

//Constructor for course
Course::Course(string subj, int num, int cred, string level, string newTitle)
: subject(subj), number(num), credits(cred), lvl(level), title(newTitle)
{
}

//Destructor for course
Course::~Course()
{
}

/*************************************
/assignTA()
/
/Assigns a TA to a course by pushing
/   a TA pointer into TAs vector
**************************************/
void Course::assignTA(TeachingAst *TA)
{
  TAs.push_back(TA);
}

/*************************************
/assignTeacher()
/
/Assigns a teacher to a course by pushing
/   a teacher pointer into instructors vector
**************************************/
void Course::assignTeacher(Teacher *teacher)
{
  instructors.push_back(teacher);
}

/*************************************
/assignStudent()
/
/Assigns a student to a course by pushing
/   a student pointer into the roster vector
**************************************/
void Course::addStudent(Student *student)
{
  roster.push_back(student);
  this->addGrade(student->getUID());
}

/*************************************
/getTeacher()
/
/Returns a reference to the specified teacher
**************************************/
Teacher &Course::getTeacher(int num)
{
	if ((num >= 0) && (num <= numTeachers()))
	{
		return *instructors[num];
	}
  	else
  	{
  		cerr << "Index for getting teacher is out of range." << endl;
	}
}

/*************************************
/getStudent()
/
/Returns a reference to the specified student
**************************************/
Student &Course::getStudent(int num)
{
	if ((num >= 0) && (num <= numStudents()))
	{
		return *roster[num];
	}
  	else
  	{
  		cerr << "Index for getting student is out of range." << endl;
	}
}

/*************************************
/getTA()
/
/Returns a reference to the specified TeachingAst
**************************************/
TeachingAst &Course::getTA(int num)
{
	if ((num >= 0) && (num <= numTAs()))
	{
		return *TAs[num];
	}
  	else
  	{
  		cerr << "Index for getting TA is out of range." << endl;
	}
}

/*************************************
/removeTeacher()
/
/Removes a teacher from the course
**************************************/
void Course::removeTeacher(int num)
{
	if ((num >= 0) && (num <= numTeachers()))
	{
		instructors.erase(instructors.begin() + num);
	}
  	else
  	{
  		cerr << "Index for getting teacher is out of range." << endl;
	}
}

/*************************************
/removeStudent()
/
/Removes a student from the course
**************************************/
void Course::removeStudent(int num)
{
	if ((num >= 0) && (num <= numStudents()))
	{
	    int studentID = roster[num]->getUID();
 		gradeBook.erase(studentID);
   		roster.erase(roster.begin() + num);
	}
  	else
  	{
  		cerr << "Index for getting student is out of range." << endl;
	}
}

/*************************************
/removeTA()
/
/Removes a TeachingAst from the course
**************************************/
void Course::removeTA(int num)
{
	if ((num >= 0) && (num <= numTAs()))
	{
		TAs.erase(TAs.begin() + num);
	}
  	else
  	{
  		cerr << "Index for getting TA is out of range." << endl;
	}
}

/*************************************
/numStudents()
/
/Retruns the number of students in the course
**************************************/
int Course::numStudents()
{
  return roster.size();
}

/*************************************
/numTeachers()
/
/Retruns the number of teachers in the course
**************************************/
int Course::numTeachers()
{
  return instructors.size();
}

/*************************************
/numTAs()
/
/Retruns the number of TAs in the course
**************************************/
int Course::numTAs()
{
  return TAs.size();
}

/*************************************
/getGrade()
/
/Returns the grade (as a percentage, i.e 98 for 98%)
/   for the student with the given studentID
**************************************/
int Course::getGrade(int studentID)
{
  return gradeBook[studentID];
}

/*************************************
/assignGrade()
/
/Assigns the student with the given studentID
/   the given grade (input as a percentage, ie. 98 for 98%)
**************************************/
void Course::assignGrade(int studentID, int grade)
{
  gradeBook[studentID] = grade;
}

/*************************************
/addGrade()
/
/Private function used when a student is
/   created to register the student in the
/   gradeBook. Students start with a 100%
**************************************/
void Course::addGrade(int studentID)
{
  gradeBook.insert( make_pair(studentID, 100) );
}

/*************************************
/print()
/
/Prints the course, output like:
/   COP 3331 Object Oriented Design Credits: 3
**************************************/
void Course::print()
{
  cout << this->getSubject() << " " << this->getNumber() << " " << this->getTitle()
    << " Credits: " <<  this->getCredits() << " Level: " << this->getLvl();
}

/*************************************
/printRoster()
/
/Prints the name and UNumber of each student
/   in the course roster
**************************************/
void Course::printRoster()
{
  for(Student *Student : roster)
  {
    cout << Student->getName() << " UID: U" << Student->getUID() << endl;
  }
}

/*************************************
/printGradebook()
/
/Prints the name, UNumber, and grade of
/   each student in the course roster
**************************************/
void Course::printGradebook()
{
  for(Student *Student : roster)
  {
    cout << Student->getName() << " UID: U" << Student->getUID() << " Grade: "
      << this->getGrade(Student->getUID()) << "%" << endl;
  }
}

/*************************************
/printTeachers()
/
/Prints the name of each teacher in the course roster
**************************************/
void Course::printTeachers()
{
  for(Teacher *teacher : instructors)
  {
    cout << teacher->getName()  << endl;
  }
}

/*************************************
/printTAs()
/
/Prints the name of each TA in the course roster
**************************************/
void Course::printTAs()
{
  for(TeachingAst *TA : TAs)
  {
    cout << TA->getName()  << endl;
  }
}

/*************************************
/setSubject()
/
/Sets the subject for the course
**************************************/
void Course::setSubject(string subj)
{
  subject = subj;
}

/*************************************
/getSubject()
/
/Returns the subject for the course
**************************************/
string Course::getSubject()
{
  return subject;
}

/*************************************
/setNumber()
/
/Sets the number for the course
**************************************/
void Course::setNumber(int num)
{
  number = num;
}

/*************************************
/getNumber()
/
/Returns the number for the course
**************************************/
int Course::getNumber()
{
  return number;
}

/*************************************
/setCredits()
/
/Sets the credits for the course
**************************************/
void Course::setCredits(int newCredits)
{
  credits = newCredits;
}

/*************************************
/getCredits()
/
/Returns the credits for the course
**************************************/
int Course::getCredits()
{
  return credits;
}

/*************************************
/setLvl()
/
/Sets the level of the course
**************************************/
void Course::setLvl(string newLvl)
{
  lvl = newLvl;
}

/*************************************
/getLvl()
/
/Returns the level of the course
**************************************/
string Course::getLvl()
{
  return lvl;
}

/*************************************
/setTitle()
/
/Sets the title of the course
**************************************/
void Course::setTitle(string newTitle)
{
  title = newTitle;
}

/*************************************
/getTitle()
/
/Returns the title of the course
**************************************/
string Course::getTitle()
{
  return title;
}
