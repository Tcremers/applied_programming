/*
 * 5_3.cpp
 *
 *  Created on: 21 mei 2017
 *      Author: Tycho
 */

#include <iostream>
#include "5_3.h"
#include <cmath>
using namespace std;

//Swap the pointer from input variable a, to b and vice versa.
void swap_pointer(double *a, double *b){
	double temp = *a;
	*a = *b;
	*b = temp;
}

//Swap the reference from input variable a, to b and vice versa.
void swap_ref(double &a, double &b){
	double temp = a;
	a = b;
	b = temp;
}



