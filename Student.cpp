#include <iostream>
#include <string>
#include <fstream>
#include "Student.h"

using namespace std;

Student::Student(){

}

Student::~Student(){
	
}

void Student::initStud(int k){
	id = k;
	cin.ignore();
	cout << "Name: ";	getline(cin, name);
	cout << "Level: ";	cin >> level;	cin.get();
	cout << "Major: ";	getline(cin, major);
	cout << "Advisor ID: ";	cin >> advisor;	cin.get();
}

void Student::setId(int myId){
	id = myId;
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
	advisor = myAdv;
}

void Student::printRecord(){
	cout << "Student ID: " << getId() << endl;
	cout << "Name: " << getName() << endl;
	cout << "Current Level: " << getLevel() << endl;
	cout << "Major: " << getMajor() << endl;
	cout << "Advisor: " << getAdvisor() << endl << endl;
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

void Student::serialize(std::ofstream& file){	//take contents and out to file
	file << getId() << endl;				//file should contain all students
	file << getName() << endl;
	file << getLevel() << endl;
	file << getMajor() << endl;
	file << getAdvisor() << endl;
}
