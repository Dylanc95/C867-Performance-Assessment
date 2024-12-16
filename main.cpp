#include <iostream>
#include <string>
#include "roster.h"
using namespace std;

int main() {
	cout << "C867 - Scripting and Programming: Applications" << endl;
	cout << "Language: C++" << endl;
	cout << "Student ID: 012155657" << endl;
	cout << "Name: Dylan Childers" << endl;

	Roster* classRoster = new Roster(5); //Create class roster, add each student

	classRoster->parse();

	classRoster->printAll();
	cout << endl;

	classRoster->printInvalidEmails();
	cout << endl;

	for (int i = 0; i < 5; ++i) {
		classRoster->AverageDaysInProgram(classRoster->classRosterArray[i]->getStudentID());
	};
	cout << endl;

	classRoster->printByDegreeProgram(DegreeProgram::SOFTWARE);
	cout << endl;

	classRoster->remove("A3");

	classRoster->printAll();
	cout << endl;

	classRoster->remove("A3");
	cout << endl;

	classRoster->~Roster();

	return 0;
}