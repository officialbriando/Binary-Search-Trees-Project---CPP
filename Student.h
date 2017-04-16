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
	
	void initStud();
	void setId(int myId);
	void setName(string myName);
	void setLevel(string myLevel);
	void setMajor(string myMajor);
	void setAdvisor(int myAdv);
	
	int getId();
	string getName();
	string getLevel();
	string getMajor();
	int getAdvisor();
	
	bool isEqual(Student n);
	bool isLesser(Student n);
	void serialize(ofstream& file);
};
