#include <iostream>
#include <string>
#include "Student.h"
using namespace std;

Student::Student(){
	cout << "ID: ";		cin >> id;
	cout << "Name: ";	cin >> name;
	cout << "Level: ";	cin >> level;
	cout << "Major: ";	cin >> major;
	cout << "Advisor ID: ";cin >> advisor;
}

Student::~Student(){
	
}

int Student::getId(){
	return id;
}

string Student::getName(){
	return name;
}

string Student::getLevel(){
	return level;
}

string Student::getMajor(){
	return major;
}

int Student::getAdvisor(){
	return advisor;
}

bool Student::isEqual(Student n){
	int x = id;
	int y = n.getId();
	if(x=y) return true;
	else return false;
}

bool Student::isLesser(Student n){
	int x = id;
	int y = n.getId();
	if(x<y) return true;
	else return false;
}

void Student::serialize(ofstream& file){	//take contents and out to file
	file << getId() << endl;				//file should contain all students
	file << getName() << endl;
	file << getLevel() << endl;
	file << getMajor() << endl;
	file << getAdvisor() << endl;
}