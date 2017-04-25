#include <string>

using namespace std;

class Faculty
{
	private:
		int ID;
		string name;
		string level;
		string dept;
		int numAdvisees;
		int *advisees;
		
	public:
		Faculty();
		Faculty(int myID, string myName, string myLevel, string myDept);
		~Faculty();
		
		void setID(int myID);
		void setName(string myName);
		void setLevel(string myLevel);
		void setDept(string myDept);
		
		void printRecord();
		int getID();
		string getName();
		string getLevel();
		string getDept();

		int* getAllAdvisees();
		int getNumAdvisees();
		int getStudent(int n);		
		void addStudent(int id);
		void removeStudent(int id);

		bool isEqual(Faculty n);
		bool isLesser(Faculty n);
		void serialize(ofstream& file);
};
