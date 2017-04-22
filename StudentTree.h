#include <iostream>
#include "BSTree.h"
#include "Student.h"
using namespace std;

class StudentTree{
private:
	BSTree<Student> myTree;	
public:
	StudentTree();
	~StudentTree();
	
	void addStudent(int k);
	void deleteStudent(int k);
	Student getStudent(int k);
	
	void serializeStudent();
	void treeTraversal(TreeNode<Student> *n, ofstream& file);
};
