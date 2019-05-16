/*
 * 5_6.cpp
 *
 *  Created on: 24 mei 2017
 *      Author: Tycho
 */

#include <iostream>
#include "5_6.h"
#include <cmath>
#include <cassert>
#include <numeric>
using namespace std;


//Multiply two matrices of given sizes
void Multiply(double **res, double **A, double **B, int ARows, int ACols, int BRows, int BCols){
//	assert(ACols == BRows);
	cout << "I hope it's working at least" << endl;

	for(int i = 0; i < ARows; ++i){
		for(int j = 0; j < BCols; ++j){
			for(int k=0; k<ACols; ++k){
				res[i][j] += A[i][k] * B[k][j];
			}
		}
	}
}

//Multiply a vector by a matrix of given sizes
void Multiply(double *res, double *A, double **B, int ACols, int BRows, int BCols){
//	assert(ACols == BCols);
	for(int i = 0; i < BRows; ++i){
		for(int j = 0; j < BCols; ++j){
			res[i] += B[j][i] * A[j];
		}
	}
}

//Multiply a matrix by vector of given sizes
void Multiply(double *res, double **A, double *B, int ARows, int ACols, int BRows){
//	assert(ACols == BRows);
	for(int i = 0; i < ARows; ++i){
		for(int j = 0; j < ACols; ++j){
			res[i]  += A[i][j] * B[j];
		}
	}
}

//Multiply a matrix by a give scalar
void Multiply(double **res, double scalar, double **B, int BRows, int BCols){
	for(int i = 0; i < BRows; ++i){
		for(int j = 0; j < BCols; ++j){
			res[i][j] = B[i][j] * scalar;
		}
	}
}

//Multiply a matrix by a give scalar
void Multiply(double **res, double **B, double scalar, int BRows, int BCols){
	for(int i = 0; i < BRows; ++i){
			for(int j = 0; j < BCols; ++j){
				res[i][j] = B[i][j] * scalar;
		}
	}
}

//If you want to fill a vector to test the above functions:
//set index [i] of the vector to i*factor
void fillVector(double *X, int cols, double factor){
	for (int i=0; i < cols; i++){
		X[i] = double(i)*factor;
	}
}

//If you want to fill a matrix to test the above functions:
//set index [i][j] of the matrix to j*factor
void fillMatrix(double **X, int rows, int cols, double factor){
	for (int i=0; i < rows; i++){
		for (int j=0; j < cols; j++){
			X[i][j] = double(j)*factor;
		}
	}
}

