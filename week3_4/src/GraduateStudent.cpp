/*
 * GraduateStudent.cpp
 *
 *  Created on: 3 jun. 2017
 *      Author: Tycho
 */

#include "GraduateStudent.hpp"


GraduateStudent::GraduateStudent() :Student(){
	fullTime = false;
}

GraduateStudent::GraduateStudent(std::string name, double fines, double fees, bool fullTime) :Student(){
	this->name = name;
	SetLibraryFines(fines);
	tuition_fees = fees;
	this->fullTime = fullTime;
}

double GraduateStudent::MoneyOwed() const{
	return GetLibraryFines();
}


