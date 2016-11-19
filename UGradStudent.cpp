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
UGradStudent::UGradStudent(int UnivID, string fullname,int BD, char gend, string lvl, string maj) : Student(UnivID, fullname, BD, gend, lvl)
{
	major = maj;
}

//Function for declaring or changing major
void UGradStudent::declareMjr(string maj)
{
	major = maj;
}

//Print function for undergraduate student
void UGradStudent::print()
{

}

//Destructor for undergraduate student
UGradStudent::~UGradStudent(){};