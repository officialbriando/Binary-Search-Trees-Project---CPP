#include <string>
#include <iostream>
#include <fstream>
#include "StudentTree.h"

using namespace std;

StudentTree::StudentTree(){
	BSTree<Student> myTree = BSTree<Student>();
}

StudentTree::~StudentTree(){
	
}

TreeNode<Student>* StudentTree::getRoot()
{
	if(myTree.getRoot() != NULL)
	{
		return myTree.getRoot();
	}
	else
	{
		return 0;
	}
}

void StudentTree::addStudent(int k){
	Student node = Student();
	node.initStud(k);
	myTree.insert(node, k);
}

void StudentTree::deleteStudent(int k){
	myTree.deleteNode(k);
}

void StudentTree::changeAdvisor(int k, int j){
	Student s = getStudent(k);
	s.setAdvisor(j);
}

Student StudentTree::getStudent(int k){
	TreeNode<Student>* node = myTree.getNode(k);
	return node->element;
}

int StudentTree::getStudentAdvisor(int k){
	Student s = getStudent(k);
	return s.getAdvisor();
}

void StudentTree::printStudent(int k){
	Student s = getStudent(k);
	s.printRecord();
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

void StudentTree::deserializeStudent(string file){
	ifstream inFile;
	inFile.open(file.c_str());
	int loop;	inFile >> loop;
	for(int i = 0; i < loop; ++i){
		Student node = Student();
		int myId;	inFile >> myId;	node.setId(myId); inFile.get();
		string myName;	getline(inFile, myName); node.setName(myName);
		string myLevel;	inFile >> myLevel;	node.setLevel(myLevel);	inFile.get();
		string myMajor;	getline(inFile, myMajor);	node.setMajor(myMajor);
		int myAdv;	inFile >> myAdv;	node.setAdvisor(myAdv);
		myTree.insert(node, myId);
	}
	inFile.close();
}

void StudentTree::printTree(TreeNode<Student> *n)
{
	if(n != NULL)
	{
		printTree(n->left);
		n->element.printRecord();
		printTree(n->right);
	}
}
