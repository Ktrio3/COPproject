//******************************************************
// File name: UGradStudent.cpp
// Purpose: Source code for Undergraduate Student class
// Authors: Kevin Dennis and V. Liana Peralta
//******************************************************

#include <iostream>
#include <string>
#include "UGradStudent.h"

using namespace std;

//Constructor for undergraduate student
UGradStudent::UGradStudent(int UnivID, string fullname, string BD, string gend, string lvl, string maj) : Student(UnivID, fullname, BD, gend, lvl)
{
	major = maj;
}

/*************************************
/declareMjr()
/
/Assigned the given major to the student
**************************************/
void UGradStudent::declareMjr(string maj)
{
	major = maj;
}

/*************************************
/getMjr()
/
/Returns the major the student is studying
**************************************/
string UGradStudent::getMjr()
{
	return major;
}

/*************************************
/print()
/
/Prints info about the undergraduate student
**************************************/
void UGradStudent::print()
{
	this->Student::print();
	cout << " Major: " << this->getMjr();;
}

//Destructor for undergraduate student
UGradStudent::~UGradStudent(){};
