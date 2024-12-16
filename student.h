#ifndef STUDENT_H
#define STUDENT_H

#include <string>
#include "degree.h"
using namespace std;

//D1-Create the class Student  in the files student.h and student.cpp
class student {
	private:
		string studentID;
		string firstName;
		string lastName;
		string emailAddress;
		int studentAge;
		int numDaysInProgramArray[3];
		DegreeProgram degreeProgram;
	public:
		//D2d: constructor w/ input parameters
		student(string studentID, string firstName, string lastName, string emailAddress, int studentAge, int days1, int days2, int days3, DegreeProgram type);
		//D2a-Accessors for each variable from part D1
		void	SetStudentID(string studentID);
		void	SetFirstName(string firstName);
		void	SetLastName(string lastName);
		void	SetEmailAddress(string emailAddress);
		void	SetAge(int studentAge);
		void	SetNumDaysArray(int days1, int days2, int days3);
		void	SetDegreeProgram(DegreeProgram degreeProgram);
		//D2b-Mutators for each variable from part D1
		string	GetStudentID() const;
		string	GetFirstName() const;
		string	GetLastName() const;
		string	GetEmailAddress() const;
		int		GetAge() const;
		int*	GetNumDaysArray() const;
		DegreeProgram	GetDegreeProgram() const;
		void	PrintAll() const; //D2e print student data
};

#endif
