/*
 * OutOfRangeException.cpp
 *
 *  Created on: 3 jun. 2017
 *      Author: Tycho
 */

#include "OutOfRangeException.hpp"


OutOfRangeException::OutOfRangeException(std::string prob) :Exception(){
	SetMProblem(prob);
	SetMTag("IndexOutOfRange");
}
