#include <iostream>
#include <fstream>
#include "MasterClass.h"

using namespace std;

MasterClass::MasterClass()
{

}

MasterClass::~MasterClass()
{

}

void MasterClass::run()
{
	StudentTree masterSTree = StudentTree();
	FacultyTree masterFTree = FacultyTree();

	GenStack<StudentTree> studentStack(5);
	GenStack<FacultyTree> facultyStack(5);

	/*if(checkStudentTables())
	{
		masterSTree.deserializeStudent("studentTable.txt");
	}

	if(checkFacultyTables())
	{
		masterFTree.deserializeFaculty("facultyTable.txt");
	}*/

	bool keepGoing = true;
	while(keepGoing)
	{
		int userChoice;
		printMenu();

		cin >> userChoice;

		switch(userChoice)
		{
			case 1:{
				masterSTree.printTree(masterSTree.getRoot());
				break;
			}

			case 2:{
				masterFTree.printTree(masterFTree.getRoot());
				break;
			}

			case 3:{
				int studentID;
				cout << "Enter the student ID you wish to display: " << endl;
				cin >> studentID;

				masterSTree.printStudent(studentID);
				break;
			}

			case 4:{
				int facultyID;
				cout << "Enter the faculty ID you wish to display: " << endl;
				cin >> facultyID;

				masterFTree.printFaculty(facultyID);
				break;
			}

			case 5:{
				int studentID;
				cout << "Enter the student ID you wish to find the advisor of: ";
				cin >> studentID;

				int facultyID = masterSTree.getStudentAdvisor(studentID);
				cout << "Here is the advisor information for this student: " << endl;
				masterFTree.printFaculty(facultyID);
				break;
			}

			case 6:{
				int facultyID;
				cout << "Enter the faculty ID you wish to find the advisee(s) of: ";
				cin >> facultyID;

				int* facultyAdvisees = masterFTree.getFacultyAdvisees(facultyID);

				cout << "Here are the advisees' information for this advisor: " << endl;

				for(int i = 0; i < 100; ++i)
				{
					if(facultyAdvisees[i] != 0)
					{
						masterSTree.printStudent(facultyAdvisees[i]);						
					}
				}
				break;
			}

			case 7:{
				int studentID;
				cout << "Enter the new student's ID: ";
				cin >> studentID;

				masterSTree.addStudent(studentID);
				masterFTree.addAdvisee(masterSTree.getStudentAdvisor(studentID), studentID);
				cout << "Student has been matched with an advisor." << endl;
				cout << "Student has been added." << endl;

				studentStack.push(masterSTree);
				facultyStack.push(masterFTree);
				break;
			}

			case 8:{
				int studentID;
				cout << "Enter the student ID to be deleted: ";
				cin >> studentID;

				masterFTree.removeAdvisee(masterSTree.getStudentAdvisor(studentID), studentID);
				masterSTree.deleteStudent(studentID);
				cout << "Student has been deleted from tree." << endl;

				studentStack.push(masterSTree);
				facultyStack.push(masterFTree);
				break;
			}

			case 9:{
				int facultyID;
				cout << "Enter the new faculty ID: ";
				cin >> facultyID;

				masterFTree.addFaculty(facultyID);

				studentStack.push(masterSTree);
				facultyStack.push(masterFTree);
				break;
			}

			case 10:{
				int facultyID;
				cout << "Enter the faculty ID to be deleted: ";
				cin >> facultyID;

				int* facultyAdvisees = masterFTree.getFacultyAdvisees(facultyID);

				for(int i = 0; i < 100; ++i)
				{
					if(facultyAdvisees[i] != 0)
					{
						masterSTree.changeAdvisor(facultyAdvisees[i], masterFTree.getRoot()->element.getID());
					}
				}

				cout << "Advisees have been repaired with another advisor." << endl;
				masterFTree.deleteFaculty(facultyID);
				cout << "Faculty has been deleted from tree." << endl;

				studentStack.push(masterSTree);
				facultyStack.push(masterFTree);
				break;
			}

			case 11:{
				int studentID, facultyID;
				cout << "Enter the student whose advisor is being changed: ";
				cin >> studentID;

				cout << "Enter the new advisor ID: ";
				cin >> facultyID;

				masterFTree.removeAdvisee(masterSTree.getStudentAdvisor(studentID), studentID);
				masterSTree.changeAdvisor(studentID, facultyID);
				masterFTree.addAdvisee(masterSTree.getStudentAdvisor(studentID), studentID);

				cout << "Student's advisor has been changed." << endl;

				studentStack.push(masterSTree);
				facultyStack.push(masterFTree);
				break;
			}

			case 12:{
				int facultyID, studentID;
				cout << "Enter the advisor to remove a student from: ";
				cin >> facultyID;

				cout << "Enter the student you are removing: ";
				cin >> studentID;

				masterSTree.changeAdvisor(studentID, masterFTree.getRoot()->element.getID());
				masterFTree.removeAdvisee(facultyID, studentID);

				cout << "Student has been removed from advisor's list." << endl;

				studentStack.push(masterSTree);
				facultyStack.push(masterFTree);
				break;
			}

			case 13:{
				masterSTree = studentStack.pop();
				masterFTree = facultyStack.pop();
				break;
			}
			case 14:{
				keepGoing = false;
				break;
			}

			default:
				break;				
		}
	}

	masterSTree.serializeStudent();
	masterFTree.serializeFaculty();
}

/*bool MasterClass::checkStudentTables()
{
	ifstream inputStream;
	string fileName = "studentTable.txt";

	if(inputStream(fileName))
	{
		cout << "Current student table exists." << endl;
		return true;
	}
	else
	{
		return false;
	}
}

bool MasterClass::checkFacultyTables()
{
	ifstream inputStream;
	string fileName = "facultyTable.txt";

	if(inputStream(fileName))
	{
		cout << "Current faculty table exists." << endl;
		return true;
	}
	else
	{
		return false;
	}
}*/

void MasterClass::printMenu()
{
	cout << endl << endl << endl;
	cout << "1. Print all students and information." << endl
		<< "2. Print all faculty and information." << endl
		<< "3. Find and display specific student." << endl
		<< "4. Find and display specific faculty." << endl
		<< "5. Find and display student's advisor information." << endl
		<< "6. Find and display faculty's advisees information." << endl
		<< "7. Add a new student." << endl
		<< "8. Delete a student." << endl
		<< "9. Add a new faculty member." << endl
		<< "10. Delete a faculty member." << endl
		<< "11. Change a student's advisor." << endl
		<< "12. Remove a faculty's advisee." << endl
		<< "13. Rollback changes." << endl
		<< "14. Exit." << endl << endl;
}
