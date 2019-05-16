/*
 * 2_6.cpp
 *
 *  Created on: 18 mei 2017
 *      Author: Tycho
 */

#include <iostream>
#include "2_6.h"
#include <cmath>
using namespace std;

//Function to calculate x next from the derivative function and normal function.
double getXNext(double x){
	double function = exp(x) + pow(x,3) - 5;
	double derivative = 3 * pow(x,2) + exp(x);
	double xNext = x - (function / derivative);
	return xNext;
}

//Implementation of the newton rhapson method to solve a non-linear equation.
//The equation is defined in getXNext()
double newton_Raphson(double x, double e) {
	double xPrevious = x;
	double xNext = getXNext(x);
	double count = 0.0;
	cout << xNext << " " << xPrevious << endl;
	while(fabs(xNext - xPrevious) > e){
		xPrevious = xNext;
		xNext = getXNext(xPrevious);
		cout << xNext - xPrevious << endl;
		cout << e << endl;
		count += 1;
	}
	cout << count << endl;
	return xNext;
}




