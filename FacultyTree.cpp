#include <iostream>
#include <fstream>
#include "FacultyTree.h"
using namespace std;

FacultyTree::FacultyTree(){
	BSTree<Faculty> myTree = BSTree<Faculty>();
}

FacultyTree::~FacultyTree(){
	
}

void FacultyTree::addFaculty(int k){
	Faculty node = Faculty();
	node.initFac(k);
	myTree.insert(node, k);
}

void FacultyTree::deleteFaculty(int k){
	myTree.deleteNode(k);
}

Faculty FacultyTree::getFaculty(int k){
	TreeNode<Faculty>* node = myTree.getNode(k);
	return node->element;
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
	fstream inFile;
	inFile.open(file.c_str());
	int loop;	inFile >> loop;
	for(int i = 0; i < loop; ++i){
		Faculty node = Faculty();
		int myId;	inFile >> myId;	node.setId(myId); inFile.get();
		string myName;	getline(inFile, myName); node.setName(myName);
		string myLevel;	inFile >> myLevel;	node.setLevel(myLevel);	inFile.get();
		string myDept;	getline(inFile, myDept);	node.setDept(myDept);
		for(int i = 0; i < 5; ++i)
		{
			int myStu;	inFile >> myStu;	inFile.get();
			node.addStudent(myStu);
		}
		myTree.insert(node, myId);
	}
	inFile.close();
}
