//********************************************
// File name: Teacher.h
// Purpose: Header file for Teacher class
// Authors: Kevin Dennis and V. Liana Peralta
//********************************************

#ifndef TEACHER_H
#define TEACHER_H

#include <iostream>
#include <string>
#include <vector>
#include "Course.h"
#include "Person.h"

using namespace std;

class Course;

class Teacher : public Person
{
	public:
		Teacher(int UnivID, string fullname, string BD, string gend, string rol); //Prototype for constructor
		~Teacher(); //Prototype for destructor

		void setRole(string newRole);
		string getRole();
		
		void assignCourse(Course *course); //Assigns a lecture course to the teacher
		Course &getCourse(int num);	//Returns the course at position num
		void removeCourse(int num); //Removes a course
		int numCourses(); //Returns the number of courses the teacher is assigned to

		void print(); //Prints information about the teacher
		void printCourses(); //Prints the courses that they are teaching

	protected:
		string role; //String for teacher role (e.g. adjunct, lecturer, etc.)
		vector<Course *> lectures; //Vector of courses the teacher is the instructor of

};
#endif
