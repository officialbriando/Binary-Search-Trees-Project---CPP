#include <iostream>
#include <fstream>
#include "MasterClass.h"

using namespace std;

MasterClass::MasterClass() {}

MasterClass::~MasterClass() {}

void MasterClass::run()
{
	StudentTree masterSTree;
	FacultyTree masterFTree;

	GenStack<StudentTree> studentStack(5);
	GenStack<FacultyTree> facultyStack(5);

	if(checkStudentTables())
	{
		masterSTree.deserializeStudent("studentTable.txt");
	}

	if(checkFacultyTables())
	{
		masterFTree.deserializeFaculty("facultyTable.txt");
	}

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
			} //Confirmed working.

			case 2:{
				masterFTree.printTree(masterFTree.getRoot());
				break;
			} //Confirmed working.

			case 3:{
				int studentID;
				cout << "Enter the student ID you wish to display: " << endl;
				cin >> studentID;
				
				while(cin.fail()){
					if(cin.fail()){
						cin.clear();
						cin.ignore(256, '\n');
						cout << "Invalid input, please enter a valid ID number: ";
						cin >> studentID;
					}
				}

				if(masterSTree.getStudentNode(studentID) == NULL)
				{
					cout << "The student ID does not exist in this tree." << endl;
					break;
				}

				masterSTree.printStudent(studentID);
				break;
			} //Confirmed.

			case 4:{
				int facultyID;
				cout << "Enter the faculty ID you wish to display: " << endl;
				cin >> facultyID;

				while(cin.fail()){
					if(cin.fail()){
						cin.clear();
						cin.ignore(256, '\n');
						cout << "Invalid input, please enter a valid ID number: ";
						cin >> facultyID;
					}
				}
				
				if(masterFTree.getFacultyNode(facultyID) == NULL)
				{
					cout << "The faculty ID does not exist in this tree." << endl;
					break;
				}
				masterFTree.printFaculty(facultyID);
				break;
			} //Confirmed.

			case 5:{
				int studentID;
				cout << "Enter the student ID you wish to find the advisor of: ";
				cin >> studentID;

				while(cin.fail()){
					if(cin.fail()){
						cin.clear();						cin.ignore(256, '\n');
						cout << "Invalid input, please enter a valid ID number: ";
						cin >> studentID;
					}
				}
				
				if(masterSTree.getStudentNode(studentID) == NULL)
				{
					cout << "The student ID does not exist in the tree, unable to look up." << endl;
					break;
				}

				int facultyID = masterSTree.getStudentAdvisor(studentID);
				cout << "Here is the advisor information for this student: " << endl;
				masterFTree.printFaculty(facultyID);
				break;
			} //Confirmed

			case 6:{
				int facultyID;
				cout << "Enter the faculty ID you wish to find the advisee(s) of: ";
				cin >> facultyID;

				while(cin.fail()){
					if(cin.fail()){
						cin.clear();
						cin.ignore(256, '\n');
						cout << "Invalid input, please enter a valid ID number: ";
						cin >> facultyID;
					}
				}
				
				if(masterFTree.getFacultyNode(facultyID) == NULL)
				{
					cout << "The faculty ID does not exist in the tree, unable to look up." << endl;
					break;
				}

				int* facultyAdvisees = masterFTree.getFacultyAdvisees(facultyID);

				cout << "Here are the advisees' information for this advisor: " << endl;

				for(int i = 0; i < 100; ++i)
				{
					if(facultyAdvisees[i] != 0)
					{
						if(masterSTree.getStudentNode(facultyAdvisees[i]) == NULL) continue;
						masterSTree.printStudent(facultyAdvisees[i]);						
					}
				}
				break;
			} //Confirmed.

			case 7:{
				studentStack.push(masterSTree);
				facultyStack.push(masterFTree);

				if(masterFTree.getRoot() == NULL)
				{
					cout << "Unable to add new student, there are no available advisors." << endl;
					break;
				}

				int studentID = masterSTree.addStudent();

				if(masterFTree.getFacultyNode(masterSTree.getStudentAdvisor(studentID)) == NULL)
				{
					cout << "The advisor does not exist, redo the entry." << endl;
					masterSTree.deleteStudent(studentID);
					break;
				}
				masterFTree.addAdvisee(masterSTree.getStudentAdvisor(studentID), studentID);
				cout << "Student has been matched with an advisor." << endl;
				cout << "Student has been added." << endl;

				break;
			} //Confirmed.

			case 8:{
				studentStack.push(masterSTree);
				facultyStack.push(masterFTree);

				int studentID;
				cout << "Enter the student ID to be deleted: ";
				cin >> studentID;

				while(cin.fail()){
					if(cin.fail()){
						cin.clear();
						cin.ignore(256, '\n');
						cout << "Invalid input, please enter a valid ID number: ";
						cin >> studentID;
					}
				}

				if(masterSTree.getStudentNode(studentID) == NULL)
				{
					cout << "The student ID does not exist in the tree, unable to look up." << endl;
					break;
				}
				
				masterFTree.removeAdvisee(masterSTree.getStudentAdvisor(studentID), studentID);
				masterSTree.deleteStudent(studentID);
				cout << "Student has been deleted from tree." << endl;

				break;
			} //Confirmed.

			case 9:{
				studentStack.push(masterSTree);
				facultyStack.push(masterFTree);

				masterFTree.addFaculty();

				break;
			} //Confirmed.

			case 10:{
				studentStack.push(masterSTree);
				facultyStack.push(masterFTree);

				int facultyID;
				cout << "Enter the faculty ID to be deleted: ";
				cin >> facultyID;

				while(cin.fail()){
					if(cin.fail()){
						cin.clear();
						cin.ignore(256, '\n');
						cout << "Invalid input, please enter a valid ID number: ";
						cin >> facultyID;
					}
				}

				if(masterFTree.getFacultyNode(facultyID) == NULL)
				{
					cout << "The faculty ID does not exist in this tree." << endl;
					break;
				}

				int* facultyAdvisees = masterFTree.getFacultyAdvisees(facultyID);

				masterFTree.deleteFaculty(facultyID);
				cout << "Faculty has been deleted from tree." << endl;



				for(int i = 0; i < 100; ++i)
				{
					if (facultyAdvisees == NULL) break;
					else if(facultyAdvisees[i] != 0)
					{
						masterSTree.changeStudentAdvisor(facultyAdvisees[i], masterFTree.getRoot()->element.getID());
						masterFTree.addAdvisee(masterFTree.getRoot()->element.getID(), facultyAdvisees[i]);
					}
				}
				cout << "Advisees have been repaired with another advisor." << endl;



				break;
			} //Confirmed.

			case 11:{
				studentStack.push(masterSTree);
				facultyStack.push(masterFTree);

				int studentID, facultyID;
				cout << "Enter the student whose advisor is being changed: ";
				cin >> studentID;

				while(cin.fail()){
					if(cin.fail()){
						cin.clear();
						cin.ignore(256, '\n');
						cout << "Invalid input, please enter a valid ID number: ";
						cin >> studentID;
					}
				}

				if(masterSTree.getStudentNode(studentID) == NULL)
				{
					cout << "The student ID does not exist in the tree, unable to look up." << endl;
					break;
				}
				
				cout << "Enter the new advisor ID: ";
				cin >> facultyID;

				while(cin.fail()){
					if(cin.fail()){
						cin.clear();
						cin.ignore(256, '\n');
						cout << "Invalid input, please enter a valid ID number: ";
						cin >> facultyID;
					}
				}

				if(masterFTree.getFacultyNode(facultyID) == NULL)
				{
					cout << "The faculty ID does not exist in this tree." << endl;
					break;
				}
				
				masterFTree.removeAdvisee(masterSTree.getStudentAdvisor(studentID), studentID);
				masterSTree.changeStudentAdvisor(studentID, facultyID);
				masterFTree.addAdvisee(facultyID, studentID);

				cout << "Student's advisor has been changed." << endl;

				break;
			} //Confirmed.

			case 12:{
				studentStack.push(masterSTree);
				facultyStack.push(masterFTree);

				int facultyID, studentID;
				cout << "Enter the advisor to remove a student from: ";
				cin >> facultyID;

				while(cin.fail()){
					if(cin.fail()){
						cin.clear();
						cin.ignore(256, '\n');
						cout << "Invalid input, please enter a valid ID number: ";
						cin >> facultyID;
					}
				}

				if(masterFTree.getFacultyNode(facultyID) == NULL)
				{
					cout << "The faculty ID does not exist in this tree." << endl;
					break;
				}
				
				cout << "Enter the student you are removing: ";
				cin >> studentID;

				while(cin.fail()){
					if(cin.fail()){
						cin.clear();
						cin.ignore(256, '\n');
						cout << "Invalid input, please enter a valid ID number: ";
						cin >> studentID;
					}
				}

				if(masterSTree.getStudentNode(studentID) == NULL)
				{
					cout << "The student ID does not exist in the tree, unable to look up." << endl;
					break;
				}
				
				masterSTree.changeStudentAdvisor(studentID, masterFTree.getRoot()->element.getID());
				masterFTree.removeAdvisee(facultyID, studentID);

				cout << "Student has been removed from advisor's list." << endl;

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

			case 15:{
				string studentName;
				cout << "Enter the name of the student you wish to find: "; cin.ignore(); getline(cin, studentName);

				masterSTree.searchName(studentName, masterSTree.getRoot());
				break;
			}

			case 16:{
				string facultyName;
				cout << "Enter the name of the faculty you wish to find: "; cin.ignore(); getline(cin, facultyName);

				masterFTree.searchName(facultyName, masterFTree.getRoot());
				break;
			}

			case 17:{
				int studentID;
				cout << "Enter the student ID you would like to edit: "; cin >> studentID;

				if(masterSTree.getStudentNode(studentID) == NULL)
				{
					cout << "The student ID does not exist in the tree, unable to look up." << endl;
					break;
				}

				TreeNode<Student>* node = masterSTree.getStudentNode(studentID);

				int userChoice;

				cout << "1. Change name." << endl
					<< "2. Change level." << endl
					<< "3. Change major." << endl
					<< "4. Change GPA." << endl << endl;
				cin >> userChoice;

				switch(userChoice)
				{
					case 1:{
						string name;
						cout << "Enter the student's new name: "; cin.ignore(); getline(cin, name);
						node->element.setName(name);
						cout << "The student's name has been changed; here is the student." << endl;
						node->element.printRecord();

						break;
					}

					case 2:{
						string level;
						cout << "Enter the student's new level: "; cin.ignore(); getline(cin, level);
						node->element.setLevel(level);
						cout << "The student's level has been changed; here is the student." << endl;
						node->element.printRecord();

						break;
					}

					case 3:{
						string major;
						cout << "Enter the student's new major: "; cin.ignore(); getline(cin, major);
						node->element.setMajor(major);
						cout << "The student's major has been changed; here is the student." << endl;
						node->element.printRecord();

						break;
					}

					case 4:{
						double gpa;
						cout << "Enter the student's new GPA: "; cin >> gpa;
						while(cin.fail() || gpa < 0 || gpa > 4){
							if(cin.fail()){
								cin.clear();
								cin.ignore(256, '\n');
							}
							cout << "Invalid input, please enter a valid GPA: ";
							cin >> gpa;
						}
						node->element.setGpa(gpa);
						cout << "The student's GPA has been changed; here the student." << endl;
						node->element.printRecord();
					}

					default:{
						break;
					}
				}

				break;
			}

			default:{
				cout << "Incorrect input.\n";
				if(cin.fail())
				{
						cin.clear();
						cin.ignore(256, '\n');
				}
				break;
			}
		}
	}

	masterSTree.serializeStudent();
	masterFTree.serializeFaculty();
}

bool MasterClass::checkStudentTables()
{
	ifstream inputStream;
	inputStream.open("studentTable.txt");

	if(inputStream.is_open())
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
	inputStream.open("facultyTable.txt");

	if(inputStream.is_open())
	{
		cout << "Current faculty table exists." << endl;
		return true;
	}
	else
	{
		return false;
	}
}

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
		<< "14. Exit." << endl << endl
		<< "Extra functions: " << endl
		<< "15. Search students by name." << endl
		<< "16. Search faculty by name." << endl
		<< "17. Change student details." << endl << endl;
}
