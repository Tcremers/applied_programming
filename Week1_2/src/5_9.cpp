/*
 * 5_9.cpp
 *
 *  Created on: 24 mei 2017
 *      Author: Tycho
 */

#include <iostream>
#include "5_9.h"
#include "5_6.h"
#include <cmath>
#include <cassert>
#include <numeric>
using namespace std;


//Since we only handle 3x3 matrices we can calculate DET by hard coding the rule of Sarrus.
double determinat3by3(double **A){
	return (A[0][0] * A[1][1] * A[2][2])
			+ (A[0][1] * A[1][2] * A[2][0])
			+ (A[0][2] * A[1][0] * A[2][1])
			- (A[0][2] * A[1][1] * A[2][0])
			- (A[0][1] * A[1][0] * A[2][2])
			- (A[0][0] * A[1][2] * A[2][1]);
}

//Because we only handle 3x3 matrices we can just hard code the method to inverse a 3x3 matrix.
void inverse3by3(double **A, double **inverse, double det){
	double a,b,c,d,e,f,g,h,i;
	a = A[0][0], b = A[0][1], c = A[0][2];
	d = A[1][0], e = A[1][1], f = A[1][2];
	g = A[2][0], h = A[2][1], i = A[2][2];

	A[0][0] = (e*i - f*h), A[0][1] = -(b*i - c*h) , A[0][2] = (b*f - c*e);
	A[1][0] = -(d*i - f*g), A[1][1] = (a*i - c*g), A[1][2] = -(a*f - c*d);
	A[2][0] = (d*h - e*g), A[2][1] = -(a*h - b*g), A[2][2] = (a*e - b*d);


	Multiply(inverse, 1/det, A, 3, 3);
}

//General method to solve a linear 3x3 matrix equation.
//u = A^-1 * b
void solve3by3(double **A, double *b, double *u){
	double **inverse = new double*[3];
	for (int i=0; i < 3; i++){
		inverse[i] = new double [3]();
	}
	//Calculate the determinant.
	double det = determinat3by3(A);
	cout << "Determinent: "<< det << endl;

	//Inverse the input matrix
	inverse3by3(A, inverse, det);

	//Multiply the inversed matrix A by vector b to calculate u.
	Multiply(u, inverse, b, 3, 3, 3);

	for (int i=0; i < 3; i++){
		delete [] inverse[i];
	}
	delete [] inverse;
}
