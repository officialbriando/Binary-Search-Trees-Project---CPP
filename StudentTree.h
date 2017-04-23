#include <string>
#include <iostream>
#include <fstream>
#include "BSTree.h"
#include "Student.h"

using namespace std;

class StudentTree
{
	private:
		BSTree<Student> myTree;	
	public:
		StudentTree();
		~StudentTree();

		TreeNode<Student>* getRoot();
		
		void addStudent(int k);
		void deleteStudent(int k);
		void changeAdvisor(int k, int j);
		Student getStudent(int k);
		int getStudentAdvisor(int k);
		void printStudent(int k);
		
		void serializeStudent();
		void treeTraversal(TreeNode<Student> *n, ofstream& file);
		void deserializeStudent(string file);

		void printTree(TreeNode<Student> *n);
};
