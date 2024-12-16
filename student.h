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
		int *numDaysInProgram;
		DegreeProgram degreeProgram;
	public:
		//D2a-Accessors for each variable from part D1
		void	SetStudentID(string stuID);
		void	SetFirstName(string fName);
		void	SetLastName(string lName);
		void	SetEmailAddress(string email);
		void	SetAge(int age);
		void	SetNumDays(int *numDaysInProgram);
		//D2b-Mutators for each variable from part D1
		string	GetStudentID() const;
		string	GetFirstName() const;
		string	GetLastName() const;
		string	GetEmailAddress() const;
		int		GetAge() const;
		int		*GetNumDays() const;
		DegreeProgram	GetDegreeProgram() const;
		void	PrintAll() const; //D2e print student data
		student(); 
		student(string studentID, string firstName, string lastName, string emailAddress, int studentAge, int days1, int days2, int days3, DegreeProgram type);
		~student() {
			cout << "Student destructor activated" << endl;
		}
};

#endif
