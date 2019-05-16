/*
 * Student.cpp
 *
 *  Created on: 3 jun. 2017
 *      Author: Tycho
 */


#include "Student.hpp"
#include <string>
#include <iostream>
#include <cassert>
using namespace std;

Student::Student(){
	name = "unkown_student";
	library_fines = 0;
	tuition_fees = 0;
}

Student::Student(std::string name, double fines, double fees){
	this->name = name;
	library_fines = fines;
	tuition_fees = fees;
}

double Student::MoneyOwed() const{
	return library_fines + tuition_fees;
}


void Student::SetLibraryFines(double amount){
	assert(amount > 0);
	library_fines = amount;
}

double Student::GetLibraryFines() const{
	return library_fines;
}
