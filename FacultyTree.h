#include <string>
#include <iostream>
#include "BSTree.h"
#include "Faculty.h"

using namespace std;

class FacultyTree
{
	private:
		BSTree<Faculty> myTree;	
	public:
		FacultyTree();
		~FacultyTree();

		TreeNode<Faculty>* getRoot();
		TreeNode<Faculty>* getFacultyNode(int k);

		void addFaculty();
		void deleteFaculty(int k);

		void printFaculty(int k);

		int* getFacultyAdvisees(int k);
		int getNumAdvisees(int k);
		void addAdvisee(int k, int j);
		void removeAdvisee(int k, int j);
		
		void serializeFaculty();
		void treeTraversal(TreeNode<Faculty> *n, ofstream& file);
		void deserializeFaculty(string file);

		void printTree(TreeNode<Faculty> *n);
		void searchName(string name, TreeNode<Faculty>* n);
};
