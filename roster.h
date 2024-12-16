#ifndef ROSTER_H
#define ROSTER_H

#include <string>
#include "student.h"
using namespace std;

//Create a roster class

class Roster {
	private:
		int mSize;
		int lastInd;
		student *classRosterArr;
	public:
		Roster();
		//E3 functions
		void add(string studentID, string firstName, string lastName, string emailAddress, int studentAge, int numDaysInProgram1, int numDaysInProgram2, int numDaysInProgram3, DegreeProgram type);
		void remove(string studentID);
		void printAll();
		void AverageDaysInProgram(string studentID);
		void printInvalidEmails();
		void printByDegreeProgram(DegreeProgram degree);
		student findStudent(int index);
		~Roster();
};

#endif
