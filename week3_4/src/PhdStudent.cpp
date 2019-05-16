/*
 * PhdStudent.cpp
 *
 *  Created on: 3 jun. 2017
 *      Author: Tycho
 */

#include "PhdStudent.hpp"

PhdStudent::PhdStudent(std::string name, double fines, double fees, bool fullTime) :GraduateStudent(){
	this->name = name;
	SetLibraryFines(fines);
	tuition_fees = fees;
	this->fullTime = fullTime;
}

double PhdStudent::MoneyOwed() const{
	return 0.0;
}

