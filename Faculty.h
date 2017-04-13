using namespace std;
class Faculty{
private:
	int id;
	string name;
	string level;
	string dept;
	int students[10] = {0};
	int studentNum;
	
public:
	Faculty();
	~Faculty();
	
	int getId();
	string getName();
	string getLevel();
	string getDept();
	int getStudent(int n);
	
	void addStudent(int id);
	void removeStudent(int id);
	bool isEqual(Faculty n);
	bool isLesser(Faculty n);
};
