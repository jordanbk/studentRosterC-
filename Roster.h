#pragma once
//#include "DegreeProgram.h"
#include "Student.h"
using namespace std;
class Roster {

private:
	//int capacity;
	int lastIndex;
	//const int numStudents = 5;
	Student *classRosterArray[5];
public:
	int capacity = 5;
	Roster();
	~Roster();

	void parseThenAdd(string datarow);
	void add(string tID, string tFirst, string tLast, string tEmail, int tAge, int tDays0, int tDays1, int tDays2, DegreeProgram tDeg);
	void printAll();
	void remove(string tID);
	void printAverageDaysInCourse(string studentID);
	void printInvalidEmails();
	void printByDegreeProgram(DegreeProgram degreeProgram);

};
