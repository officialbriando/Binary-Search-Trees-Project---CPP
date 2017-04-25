#include <string>
#include <iostream>
#include <fstream>
#include "FacultyTree.h"

using namespace std;

FacultyTree::FacultyTree()
{

}

FacultyTree::~FacultyTree() {}

TreeNode<Faculty>* FacultyTree::getRoot()
{
	TreeNode<Faculty>* node = myTree.getRoot();

	if(node != NULL)
	{
		return node;
	}
	else
	{
		return NULL;
	}
}

TreeNode<Faculty>* FacultyTree::getFacultyNode(int k)
{
	TreeNode<Faculty>* node = myTree.getNode(k);
	if(node == NULL)
	{
		return NULL;
	}
	return node;
}

void FacultyTree::addFaculty()
{
	int myID; string myName, myLevel, myDept;
	cout << "Faculty ID#: "; cin >> myID; cin.ignore(256, '\n');
	while(cin.fail()){
		if(cin.fail()){
			cin.clear();
			cin.ignore(256, '\n');
			cout << "Invalid input, please enter a valid ID number: ";
			cin >> myID;
		}
	}
	cout << "Name: "; getline(cin, myName);
	cout << "Level: "; getline(cin, myLevel);
	cout << "Department: "; getline(cin, myDept);
	Faculty f(myID, myName, myLevel, myDept);
	myTree.insert(f, myID);
}

void FacultyTree::deleteFaculty(int k)
{
	myTree.deleteNode(k);
}

int FacultyTree::getNumAdvisees(int k)
{
	TreeNode<Faculty>* node = getFacultyNode(k);
	if(node == NULL)
	{
		return 0;
	}
	return node->element.getNumAdvisees();
}

int* FacultyTree::getFacultyAdvisees(int k)
{
	TreeNode<Faculty>* node = getFacultyNode(k);
	if(node == NULL)
	{
		return NULL;
	}
	return node->element.getAllAdvisees();
}

void FacultyTree::addAdvisee(int k, int j)
{
	TreeNode<Faculty>* node = getFacultyNode(k);
	if(node == NULL)
	{
		return;
	}
	node->element.addStudent(j);
}

void FacultyTree::removeAdvisee(int k, int j)
{
	TreeNode<Faculty>* node = getFacultyNode(k);
	if(node == NULL)
	{
		return;
	}
	node->element.removeStudent(j);
}

void FacultyTree::printFaculty(int k)
{
	TreeNode<Faculty>* node = getFacultyNode(k);
	if(node->element.getID() == -1) return;

	node->element.printRecord();
}

void FacultyTree::serializeFaculty(){
	ofstream outFile("facultyTable.txt");
	outFile << myTree.getSize() << endl;
	
	treeTraversal(myTree.getRoot(), outFile);
}

void FacultyTree::treeTraversal(TreeNode<Faculty> *n, ofstream& file){
	if(n != NULL)
	{
		n->element.serialize(file);
		treeTraversal(n->left, file);
		treeTraversal(n->right, file);
	}
}

void FacultyTree::deserializeFaculty(string file){
	ifstream inFile;
	inFile.open(file.c_str());
	int loop;	inFile >> loop;
	for(int i = 0; i < loop; ++i){
		Faculty node = Faculty();
		int myId;	inFile >> myId;	node.setID(myId); inFile.get();
		string myName;	getline(inFile, myName); node.setName(myName);
		string myLevel;	inFile >> myLevel;	node.setLevel(myLevel);	inFile.get();
		string myDept;	getline(inFile, myDept);	node.setDept(myDept);
		int myNumAdvisees;	inFile >> myNumAdvisees;
		for(int i = 0; i < myNumAdvisees; ++i)
		{
			int myStu;	inFile >> myStu;	inFile.get();
			node.addStudent(myStu);
		}
		myTree.insert(node, myId);
	}
	inFile.close();
}

void FacultyTree::printTree(TreeNode<Faculty> *n)
{
	if(n != NULL)
	{
		printTree(n->left);
		n->element.printRecord();
		printTree(n->right);
	}
}
