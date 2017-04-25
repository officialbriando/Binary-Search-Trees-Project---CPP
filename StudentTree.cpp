#include <string>
#include <iostream>
#include <fstream>
#include "StudentTree.h"

using namespace std;

StudentTree::StudentTree()
{

}

StudentTree::~StudentTree(){
	
}

TreeNode<Student>* StudentTree::getRoot()
{
	TreeNode<Student>* node = myTree.getRoot();

	if(node != NULL)
	{
		return node;
	}
	else
	{
		return NULL;
	}
}

int StudentTree::addStudent()
{
	int myID, myAdv; string myName, myLevel, myMajor;

	cout << "Student ID#: "; cin >> myID;
	while(cin.fail()){
		if(cin.fail()){
			cin.clear();
			cin.ignore(256, '\n');
			cout << "Invalid input, please enter a valid ID number: ";
			cin >> myID;
		}
	}
	cout << "Name: "; cin >> myName;
	cout << "Level: "; cin >> myLevel;
	cout << "Major: "; cin >> myMajor;
	cout << "Advisor ID#: "; cin >> myAdv;
	while(cin.fail()){
		if(cin.fail()){
			cin.clear();
			cin.ignore(256, '\n');
			cout << "Invalid input, please enter a valid ID number: ";
			cin >> myAdv;
		}
	}

	Student s(myID, myName, myLevel, myMajor, myAdv);
	myTree.insert(s, myID);

	return myID;
}

void StudentTree::deleteStudent(int k)
{
	myTree.deleteNode(k);
}

TreeNode<Student>* StudentTree::getStudentNode(int k)
{
	TreeNode<Student>* node = myTree.getNode(k);
	if(node == NULL)
	{
		return NULL;
	}
	return node;
}

void StudentTree::changeStudentAdvisor(int k, int j)
{
	TreeNode<Student>* node = getStudentNode(k);
	node->element.setAdvisor(j);
}


int StudentTree::getStudentAdvisor(int k)
{
	TreeNode<Student>* node = getStudentNode(k);
	return node->element.getAdvisor();
}

void StudentTree::printStudent(int k)
{
	TreeNode<Student>* node = getStudentNode(k);
	node->element.printRecord();
}

void StudentTree::printTree(TreeNode<Student>* n)
{
	if(n != NULL)
	{
		printTree(n->left);
		n->element.printRecord();
		printTree(n->right);
	}
}

void StudentTree::serializeStudent()
{
	ofstream outFile("studentTable.txt");
	outFile << myTree.getSize() << endl;
	
	treeTraversal(myTree.getRoot(), outFile);
}

void StudentTree::treeTraversal(TreeNode<Student> *n, ofstream& file)
{
	if(n != NULL)
	{
		n->element.serialize(file);
		treeTraversal(n->left, file);
		treeTraversal(n->right, file);
	}
}

void StudentTree::deserializeStudent(string file)
{
	ifstream inFile;
	inFile.open(file.c_str());
	int loop;	inFile >> loop;
	for(int i = 0; i < loop; ++i){
		Student node = Student();
		int myId;	inFile >> myId;	node.setID(myId); inFile.get();
		string myName;	getline(inFile, myName); node.setName(myName);
		string myLevel;	inFile >> myLevel;	node.setLevel(myLevel);	inFile.get();
		string myMajor;	getline(inFile, myMajor);	node.setMajor(myMajor);
		int myAdv;	inFile >> myAdv;	node.setAdvisor(myAdv);
		myTree.insert(node, myId);
	}
	inFile.close();
}


