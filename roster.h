#ifndef ROSTER_H
#define ROSTER_H

#include <string>
#include "student.h"
using namespace std;

//Create a roster class

class Roster {
	public:
		//Constructor
		Roster(int rosterSize);
		
		//Destructor
		~Roster();

		//E3 functions
		//Parse data
		void parse();

		//Parses a student data line and returns object
		Student* parseLine(string dataLine);

		//Adds to classRosterArr
		void add(string studentID, string firstName, string lastName, string emailAddress, int age, int daysInCourse1, int daysInCourse2, int daysInCourse3, DegreeProgram degreeProgram);

		//Removes from classRosterArr
		void remove(string studentID);

		//Prints all students
		void printAll();

		//Calculates and prints average number of days for each student in their course array
		void AverageDaysInProgram(string studentID);

		//Prints all invalid emails
		void printInvalidEmails();

		//Prints out students based on degree program
		void printByDegreeProgram(DegreeProgram degreeProgram);

		//Cast enum DegreeProgram to string 
		static string castDegreeProgramToString(DegreeProgram degreeEnum);
		static DegreeProgram castToDegreeProgram(string degreeString);

		//Create an array of pointers
		Student* classRosterArray[5];

		int rosterSize;

		//Modify the table to include personal information
		const string studentDataTable[5] = {
		"A1,John,Smith,John1989@gm ail.com,20,30,35,40,SECURITY",
		"A2,Suzan,Erickson,Erickson_1990@gmailcom,19,50,30,40,NETWORK",
		"A3,Jack,Napoli,The_lawyer99yahoo.com,19,20,40,33,SOFTWARE",
		"A4,Erin,Black,Erin.black@comcast.net,22,50,58,40,SECURITY",
		"A5,Dylan,Childers,dylanc95@gmail.com,29,10,30,15,SOFTWARE"
		};
};

#endif
