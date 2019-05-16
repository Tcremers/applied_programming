/*
 * Matrix2x2.cpp
 *
 *  Created on: 2 jun. 2017
 *      Author: Tycho
 */

#include "Matrix2x2.hpp"
#include <cassert>
#include <cmath>
using namespace std;

// Override default constructor
// Set real and imaginary parts to zero
Matrix2x2::Matrix2x2 (){
	val00 = 0; // first row, first column
	val01 = 0; // first row, second column
	val10 = 0; // second row, first colum
	val11 = 0; // second row, second column
}

Matrix2x2::Matrix2x2(const Matrix2x2& other){
	val00 = other.val00;
	val01 = other.val01;
	val10 = other.val10;
	val11 = other.val11;
}

Matrix2x2::Matrix2x2(double a, double b, double c, double d){
	val00 = a;
	val01 = b;
	val10 = c;
	val11 = d;
}

double Matrix2x2::CalcDeterminant() const{
	return val00*val11 - val01*val10;
}

Matrix2x2 Matrix2x2::CalcInverse() const{
	double det = 1/CalcDeterminant();
	Matrix2x2 w;
	w.val00 = val11 * det;
	w.val01 = (-val01) * det;
	w.val10 = (-val10) * det;
	w.val11 = val00 * det;
	return w;
}

Matrix2x2& Matrix2x2::operator=(const Matrix2x2& z){
	val00 = z.val00;
	val01 = z.val01;
	val10 = z.val10;
	val11 = z.val11;
	return *this;
}

Matrix2x2 Matrix2x2::operator-() const{
	Matrix2x2 w;
	w.val00 = -val00;
	w.val01 = -val01;
	w.val10 = -val10;
	w.val11 = -val11;
	return w;
}

Matrix2x2 Matrix2x2::operator+(const Matrix2x2& z) const{
	Matrix2x2 w;
	w.val00 = val00 + z.val00;
	w.val01 = val01 + z.val01;
	w.val10 = val10 + z.val10;
	w.val11 = val11 + z.val11;
	return w;
}

Matrix2x2 Matrix2x2::operator-(const Matrix2x2& z) const{
	Matrix2x2 w;
	w.val00 = val00 - z.val00;
	w.val01 = val01 - z.val01;
	w.val10 = val10 - z.val10;
	w.val11 = val11 - z.val11;
	return w;
}

void Matrix2x2::MultScalar(double scalar){
	val00 *= scalar;
	val01 *= scalar;
	val10 *= scalar;
	val11 *= scalar;
}

void Matrix2x2::Print() const{
	cout << val00 << " " <<val01 << endl;
	cout << val10 << " " << val11 << endl;
}









