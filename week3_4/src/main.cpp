/*
 * main.cpp
 *
 *  Created on: 29 mei 2017
 *      Author: Tycho
 */

#include <iostream>
#include <string>
#include "CalculateExponential.hpp"
#include "ComplexNumber.hpp"
#include "Matrix2x2.hpp"
#include "Student.hpp"
#include "GraduateStudent.hpp"
#include "Exercise82.hpp"
#include <math.h>
#include <typeinfo>
#include "FileNotOpenException.hpp"
using namespace std;


void complexNumberTester(){
	ComplexNumber zero;
	ComplexNumber** foo = new ComplexNumber*[3];
	ComplexNumber** res = new ComplexNumber*[3];
	for(int i = 0; i<3 ;i++){
		foo[i] = new ComplexNumber[3];
		res[i] = new ComplexNumber[3];
	}

	foo[0][0] = ComplexNumber(2,3);
	foo[1][1] = ComplexNumber(4,5);
	foo[2][2] = ComplexNumber(6,7);

	printMatrix(foo,3,3);
	CalculateExponential(foo,3,res);
	printMatrix(res,3,3);
}

int main() {
	//TODO: everything.
	//CalculateExponential()
	//complexNumberTester();
	Matrix2x2 foo;
	foo = Matrix2x2(1,2,3,4);
//	foo(double(1),double(2),double(3),double(5));
	cout << foo.Getval01();
}


