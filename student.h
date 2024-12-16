#ifndef STUDENT_H
#define STUDENT_H

#include <string>
#include "degree.h"
using namespace std;

//D1-Create the class Student  in the files student.h and student.cpp
class Student {
	private:
		string studentID;
		string firstName;
		string lastName;
		string emailAddress;
		int age;
		int daysPerCourseArray[3];
		DegreeProgram degreeProgram;
	public:
		//D2d: constructor w/ input parameters
		Student(string sID, string fName, string lName, string email, int sAge, int courseTime1, int courseTime2, int courseTime3, DegreeProgram degreeProg);
		//D2a-Accessors for each variable from part D1
		void setStudentID(string newStudentID);
		void setFirstName(string newFirstName);
		void setLastName(string newLastName);
		void setEmailAddress(string newEmailAddress);
		void setAge(int newAge);
		void setDaysPerCourseArray(int courseTime1, int courseTime2, int courseTime3);
		void setDegreeProgram(DegreeProgram newDegreeProgram);
		//D2b-Mutators for each variable from part D1
		string getStudentID();
		string getFirstName();
		string getLastName();
		string getEmailAddress();
		int getAge();
		int* getDaysPerCourseArray();
		DegreeProgram getDegreeProgram();
		//Print student information
		void print();
};

#endif
