#include <iostream>
#include <string>
#include <fstream>
#include "Faculty.h"

using namespace std;

Faculty::Faculty(){
	ID = -1;
	numAdvisees = 0;
	advisees = new int[100]();
}

Faculty::Faculty(int myID, string myName, string myLevel, string myDept){
	ID = myID;
	name = myName;
	level = myLevel;
	dept = myDept;

	numAdvisees = 0;
	advisees = new int[100]();
}

Faculty::~Faculty(){
	
}


/*void Faculty::initFac(int k){
	id = k; cin.get();
	cout << "Name: ";	getline(cin, name);
	cout << "Level: ";	cin >> level;	cin.get();
	cout << "Department: ";	getline(cin, dept);
}*/

void Faculty::setID(int myID){
	ID = myID;
}

void Faculty::setName(string myName){
	name = myName;
}

void Faculty::setLevel(string myLevel){
	level = myLevel;
}

void Faculty::setDept(string myDept){
	dept = myDept;
}

void Faculty::printRecord(){
	cout << "Faculty ID: " << ID << endl;
	cout << "Name: " << name << endl;
	cout << "Current Level: " << level << endl;
	cout << "Department: " << dept << endl;
	cout << "Advisee IDs: " << endl;
	for(int i = 0; i < numAdvisees; ++i){
		if(advisees[i] != 0){
			cout << advisees[i] << endl;
		}
	}	
}

int Faculty::getID(){
	return ID;
}

string Faculty::getName(){
	return name;
}

string Faculty::getLevel(){
	return level;
}

string Faculty::getDept(){
	return dept;
}

int Faculty::getStudent(int n){
	return advisees[n];
}

int* Faculty::getAllAdvisees(){
	return advisees;
}

int Faculty::getNumAdvisees(){
	return numAdvisees;
}

void Faculty::addStudent(int id){
	if(numAdvisees >=100) cout << "Cannot hold anymore students.\n";
	else{
		numAdvisees++;
		for(int i = 0; i < 100; ++i){
			if(advisees[i] == 0){
				advisees[i] = id;
				break;
			}
		}
	}
}

void Faculty::removeStudent(int id){
	int temp, check = 0;
	for(int i = 0; i < 100; ++i){
		temp = advisees[i];
		if(temp == id){
			advisees[i] = 0;
			check = 1;
			numAdvisees--;
		}
		if(check == 1) break;
	}
	if(check == 0) cout << "Student not found under this advisor.\n";
	else cout << "Student has been removed from advisor. \n";
}

bool Faculty::isEqual(Faculty n){
	int x = ID;
	int y = n.getID();
	if(x=y) return true;
	else return false;
}

bool Faculty::isLesser(Faculty n){
	int x = ID;
	int y = n.getID();
	if(x<y) return true;
	else return false;
}

void Faculty::serialize(std::ofstream& file){
	file << getID() << endl;
	file << getName() << endl;
	file << getLevel() << endl;
	file << getDept() << endl;
	file << getNumAdvisees() << endl;
	for(int i = 0; i < numAdvisees; ++i) file << getStudent(i) << endl;
}
