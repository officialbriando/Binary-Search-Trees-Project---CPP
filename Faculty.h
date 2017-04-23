using namespace std;
class Faculty{
private:
	int id;
	string name;
	string level;
	string dept;
	int studentNum;
	int *students;
	
public:
	Faculty();
	~Faculty();
	
	void initFac(int k);
	void setId(int myId);
	void setName(string myName);
	void setLevel(string myLevel);
	void setDept(string myDept);
	
	void printRecord();
	int getId();
	string getName();
	string getLevel();
	string getDept();
	int getStudent(int n);
	
	void addStudent(int id);
	void removeStudent(int id);
	bool isEqual(Faculty n);
	bool isLesser(Faculty n);
	void serialize(ofstream& file);
};
