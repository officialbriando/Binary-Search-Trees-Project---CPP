using namespace std;
class Student{
private:
	int id;
	string name;
	string level;
	string major;
	int advisor;
	
public:
	Student();
	~Student();
	
	int getId();
	string getName();
	string getLevel();
	string getMajor();
	int getAdvisor();
	
	bool isEqual(Student n);
	bool isLesser(Student n);
};
