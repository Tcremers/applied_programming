/*
 * main.cpp
 *
 *  Created on: 5 jun. 2017
 *      Author: Tycho
 */

#include <iostream>
#include <string>
#include <math.h>
#include <typeinfo>
#include "Vector.hpp"
#include "matrix.hpp"
#include "SparseVector.hpp"

using namespace std;



int main() {
	//TODO: everything.
	//CalculateExponential()
//	SparseVector<int> bar(10);
//	bar.setValue(3,5);

	SparseVector<int> foo(3);
	foo.setValue(0,1);
	foo.setValue(1,2);
	foo.setValue(2,3);

	Vector<int> res(3) ;
	Matrix<int> bar(3,3);
	bar(0,0) = 2; bar(0,1) = 2; bar(0,2) = 2;
	bar(1,0) = 2; bar(1,1) = 2; bar(1,2) = 2;
	bar(2,0) = 2; bar(2,1) = 2; bar(2,2) = 2;

	res = (bar * foo);


	cout << res[0] << endl;
	cout << res[1] << endl;
	cout << res[2] << endl;
//	for (int i = 0; i < 3; ++i) {
//		cout << foo.unWind()[i] << " ";
//	}
//	cout << endl;

}
