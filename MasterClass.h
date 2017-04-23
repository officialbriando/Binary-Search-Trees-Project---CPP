#include <iostream>
#include <fstream>

#include "FacultyTree.h"
#include "StudentTree.h"
#include "GenStack.h"

using namespace std;

class MasterClass
{
	public:
		MasterClass();
		~MasterClass();

		void run();

		bool checkStudentTables();
		bool checkFacultyTables();
		void printMenu();

};