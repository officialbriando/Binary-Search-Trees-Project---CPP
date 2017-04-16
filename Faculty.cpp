#include <iostream>
#include <string>
#include "Faculty.h"
using namespace std;

Faculty::Faculty(){
	studentNum = 0;
}

Faculty::~Faculty(){
	
}

void Faculty::initFac(){
	cout << "ID: ";		cin >> id;
	cout << "Name: ";	cin >> name;
	cout << "Level: ";	cin >> level;
	cout << "Department: ";	cin >> dept;	
}

void Faculty::setId(int myId){
	id = myId;
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

int Faculty::getId(){
	return id;
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
	return students[n];
}

void Faculty::addStudent(int id){
	if(studentNum >=10) cout << "Cannot hold anymore students.\n";
	else{
		for(int i=0; i < studentNum; ++i){
			if(students[i] == 0) students[i] = id;
		}
		studentNum++;
	}
}

void Faculty::removeStudent(int id){
	int temp, check = 0;
	for(int i=0; i<studentNum; ++i){
		temp = students[i];
		if(temp == id){
			students[i] = 0;
			check = 1;
			studentNum--;
		}
	}
	if(check == 0) cout << "Student not found under this advisor.\n";
	else cout << "Student has been removed.\n";
}

bool Faculty::isEqual(Faculty n){
	int x = id;
	int y = n.getId();
	if(x=y) return true;
	else return false;
}

bool Faculty::isLesser(Faculty n){
	int x = id;
	int y = n.getId();
	if(x<y) return true;
	else return false;
}

void Faculty::serialize(ofstream& file){
	file << getId() << endl;
	file << getName() << endl;
	file << getLevel() << endl;
	file << getDept() << endl;
	for(int i = 0; i < studentNum; ++i) file << getStudent(i) << endl;
}
