#include <iostream>
#include <string>
#include "Roster.h"
//#include "Student.h"
//#include "Roster.cpp"
//#include "Student.cpp"
using namespace std;


int main() {
	cout << "******************** COURSE TITLE ********************" << endl << endl;
	cout << "     SCRIPTING AND PROGRAMMING APPLICATIONS - C867" << endl << endl;
	cout << "**************** PROGRAMMING LANGUAGE****************" << endl << endl;
	cout << "                         C++ " << endl << endl;
	cout << "**************** STUDENT ID AND NAME *****************" << endl << endl;
	cout << "              #001179962 - JORDAN BURKE" << endl << endl;

	const int numStudents = 5;
	const string studentData[5] =
	{
		"A1,John,Smith,John1989@gm ail.com,20,30,35,40,SECURITY",
		"A2,Suzan,Erickson,Erickson_1990@gmailcom,19,50,30,40,NETWORK",
		"A3,Jack,Napoli,The_lawyer99yahoo.com,19,20,40,33,SOFTWARE",
		"A4,Erin,Black,Erin.black@comcast.net,22,50,58,40,SECURITY",
		"A5,Jordan,Burke,jordanBurke@gmail.com,30,30,40,50,SOFTWARE",
	};


	Roster * classRoster = new Roster();

	int i = 0;
	while (i < classRoster->capacity) {
		classRoster->parseThenAdd(studentData[i]);
		i++;
	};

	classRoster->printAll();
	cout << "***********************************************************************" << endl;
	cout << "Print invalid student emails: " << endl;
	classRoster->printInvalidEmails();
	cout << "***********************************************************************" << endl;
	cout << "Student average days spent on course: " << endl;
	for (int i = 1; i <= classRoster->capacity; i++)
	{
		classRoster->printAverageDaysInCourse("A" + std::to_string(i));
		std::cout << "\n";
	}
	cout << "***********************************************************************" << endl;
	cout << "Students in the software program: " << endl;
	classRoster->printByDegreeProgram(DegreeProgram::Software);
	cout << "***********************************************************************" << endl;
	classRoster->remove("A3");
	cout << "***********************************************************************" << endl;
	classRoster->printAll();
	cout << "***********************************************************************" << endl;
	classRoster->remove("A3");
	cout << "***********************************************************************" << endl;

	
	system("pause");

	return 0;
};
