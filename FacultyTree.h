#include <iostream>
#include "BSTree.h"
#include "Faculty.h"
using namespace std;

class FacultyTree{
private:
	BSTree<Faculty> myTree;	
public:
	FacultyTree();
	~FacultyTree();
	
	void addFaculty(int k);
	void deleteFaculty(int k);
	Faculty getFaculty(int k);
	
	void serializeFaculty();
	void treeTraversal(TreeNode<Faculty> *n, ofstream& file);
	void deserializeFaculty(string file);
};
