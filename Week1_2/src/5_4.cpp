/*
 * 5_4.cpp
 *
 *  Created on: 23 mei 2017
 *      Author: Tycho
 */

#include <iostream>
#include "5_4.h"
#include <cmath>
#include <cassert>
using namespace std;

//Calculate the standard deviation of the given vector of numbers.
double calc_std(double a[], int length){
	if(length <= 1){
		return 0;
	}
	assert(length > 1);
	double E=0;
	double ave = calc_mean(a, length);
	for(int i = 0; i < length; i++){
		   E+=(a[i] - ave)*(a[i] - ave);
	}
	return sqrt(1/double(length-1)*E);
}

//Calculate the mean (avarage) of the given vector.
double calc_mean(double a[], int length){
	double sum = 0;
	for(int i = 0; i < length; i++){
		sum += a[i];
	}
	return sum/length;
}
