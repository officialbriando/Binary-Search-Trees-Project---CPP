#include <string>

using namespace std;

class Student
{
	private:
		int ID;
		string name;
		string level;
		string major;
		int advisorID;
		
	public:
		Student();
		Student(int myID, string myName, string myLevel, string myMajor, int myAdv);
		~Student();
		
		void setID(int myID);
		void setName(string myName);
		void setLevel(string myLevel);
		void setMajor(string myMajor);
		void setAdvisor(int myAdv);
		
		void printRecord();
		int getID();
		string getName();
		string getLevel();
		string getMajor();
		int getAdvisor();
		
		bool isEqual(Student n);
		bool isLesser(Student n);
		void serialize(ofstream& file);
};
