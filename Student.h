#include <string>

using namespace std;

class Student
{
	private:
		int ID;
		string name;
		string level;
		string major;
		double gpa;
		int advisorID;
		
	public:
		Student();
		Student(int myID, string myName, string myLevel, string myMajor, double myGpa, int myAdv);
		~Student();
		
		void setID(int myID);
		void setName(string myName);
		void setLevel(string myLevel);
		void setMajor(string myMajor);
		void setGpa(double myGpa);
		void setAdvisor(int myAdv);
		
		void printRecord();
		int getID();
		string getName();
		string getLevel();
		string getMajor();
		double getGpa();
		int getAdvisor();
		
		bool isEqual(Student n);
		bool isLesser(Student n);
		void serialize(ofstream& file);
};
