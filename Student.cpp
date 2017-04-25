#include <iostream>
#include <string>
#include <fstream>
#include "Student.h"

using namespace std;

Student::Student(){
	ID = -1;
}

Student::Student(int myID, string myName, string myLevel, string myMajor, int myAdv){
	ID = myID;
	name = myName;
	level = myLevel;
	major = myMajor;
	advisorID = myAdv;
}

Student::~Student(){
	
}

/*void Student::initStud(int k){
	id = k; cin.get();
	cout << "Name: ";	getline(cin, name);
	cout << "Level: ";	cin >> level;	cin.get();
	cout << "Major: ";	getline(cin, major);
	cout << "Advisor ID: ";	cin >> advisor;
	while(cin.fail()){
		if(cin.fail()){
			cin.clear();
			cin.ignore(256, '\n');
			cout << "Invalid input, please enter a valid ID number: ";
			cin >> advisor;
		}
	}
	cin.get();
}*/

void Student::setID(int myID){
	ID = myID;
}

void Student::setName(string myName){
	name = myName;
}

void Student::setLevel(string myLevel){
	level = myLevel;
}

void Student::setMajor(string myMajor){
	major = myMajor;
}

void Student::setAdvisor(int myAdv){
	advisorID = myAdv;
}

void Student::printRecord(){
	cout << "Student ID: " << ID << endl;
	cout << "Name: " << name << endl;
	cout << "Current Level: " << level << endl;
	cout << "Major: " << major << endl;
	cout << "Advisor: " << advisorID << endl << endl;
}

int Student::getID(){
	return ID;
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
	return advisorID;
}

bool Student::isEqual(Student n){
	int x = ID;
	int y = n.getID();
	if(x=y) return true;
	else return false;
}

bool Student::isLesser(Student n){
	int x = ID;
	int y = n.getID();
	if(x<y) return true;
	else return false;
}

void Student::serialize(std::ofstream& file){	//take contents and out to file
	file << getID() << endl;				//file should contain all students
	file << getName() << endl;
	file << getLevel() << endl;
	file << getMajor() << endl;
	file << getAdvisor() << endl;
}
