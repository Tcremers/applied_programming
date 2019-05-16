/*
 * Exception.cpp
 *
 *  Created on: 3 jun. 2017
 *      Author: Tycho
 */


#include "Exception.hpp"

Exception::Exception(){
	mTag = "Unkown";
	mProblem = "Unkown Error";
}

Exception::Exception(std::string tagString, std::string probString){
	mTag = tagString;
	mProblem = probString;
}

void Exception::PrintDebug() const{
	std::cerr << "** Error ("<<mTag<<") **\n";
	std::cerr << "Problem: " << mProblem << "\n\n";
}

void Exception::SetMTag(std::string tagString){
	mTag = tagString;
}
void Exception::SetMProblem(std::string probString){
	mProblem = probString;
}
