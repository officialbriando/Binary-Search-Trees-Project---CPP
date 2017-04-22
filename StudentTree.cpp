#include <iostream>
#include <fstream>
#include "StudentTree.h"
using namespace std;

StudentTree::StudentTree(){
	BSTree<Student> myTree = BSTree<Student>();
}

StudentTree::~StudentTree(){
	
}

void StudentTree::addStudent(int k){
	Student node = Student();
	node.initStud(k);
	myTree.insert(node, k);
}

void StudentTree::deleteStudent(int k){
	myTree.deleteNode(k);
}

Student StudentTree::getStudent(int k){
	TreeNode<Student>* node = myTree.getNode(k);
	return node->element;
}

void StudentTree::serializeStudent(){
	ofstream outFile("studentTable.txt");
	outFile << myTree.getSize() << endl;
	
	treeTraversal(myTree.getRoot(), outFile);
}

void StudentTree::treeTraversal(TreeNode<Student> *n, ofstream& file){
	if(n != NULL)
	{
		n->element.serialize(file);
		treeTraversal(n->left, file);
		treeTraversal(n->right, file);
	}
}
