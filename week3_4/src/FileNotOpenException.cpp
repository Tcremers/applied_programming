/*
 * FileNotOpenException.cpp
 *
 *  Created on: 3 jun. 2017
 *      Author: Tycho
 */

#include "FileNotOpenException.hpp"

FileNotOpenException::FileNotOpenException(std::string prob) :Exception(){
	SetMProblem(prob);
	SetMTag("FileNotOpen");
}
