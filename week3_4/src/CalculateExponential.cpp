/*
 * CalculateEponential.cpp
 *
 *  Created on: 1 jun. 2017
 *      Author: Tycho
 */

#include "ComplexNumber.hpp"
#include <cmath>
using namespace std;


//non mandatory
void printMatrix(ComplexNumber **A, int rows, int cols){
	for(int i = 0; i < rows; i++){
		for(int j = 0; j < cols; j++){
			cout << A[i][j] << " ";
		}
		cout << endl;
	}
	cout << endl;
}


//Calculate the factorial of a given int
double factorial(double n){
  return (n == 1 || n == 0) ? 1 : factorial(n - 1) * n;
}

//Add 3x3 complex number matrix: B to matrix: A.
void addMatrix(ComplexNumber **A, ComplexNumber **B){
	for(int i = 0; i < 3; i++){
		for(int j = 0; j < 3; j++){
			A[i][j] = A[i][j] + B[i][j];
		}
	}
}

//Multiply two 3x3 complex number matrices
void Multiply(ComplexNumber **A, ComplexNumber **B, ComplexNumber **result){
	//Temporary matrices to store powers of initial matrix
	for(int i = 0; i < 3; ++i){
		for(int j = 0; j < 3; ++j){
			for(int k=0; k < 3; ++k){
				result[i][j] = result[i][j] + (A[i][k] * B[k][j]);
			}
		}
	}
}

//Devide a 3x3 complex number matrix by a scalar.
void Devide(ComplexNumber **A, double scalar){
	ComplexNumber complexScalar(scalar);
	for(int i = 0; i < 3; ++i){
		for(int j = 0; j < 3; ++j){
			A[i][j] = A[i][j] / complexScalar;
		}
	}
}

//Raise a 3x3 complex number matrix to the power: nMax. Store the resulting matrix in: res.
void CalculateExponential(ComplexNumber **A, int nMax, ComplexNumber **res){
	//Create complex number of real value "1" for the identity matrix
	ComplexNumber idValue(1.0);

	//Execute first 2 steps of calculating the exponent of the matrix. (addition of identity matrix and initial matrix)
	res[0][0] = idValue, res[1][1] = idValue, res[2][2] = idValue;
	addMatrix(res, A);



	//Temporary matrices to store powers of initial matrix
	ComplexNumber** powerPrevious = new ComplexNumber*[3];
	ComplexNumber** powerNext = new ComplexNumber*[3];
	for(int i = 0; i < 3; i++){
		powerPrevious[i] = new ComplexNumber[3];
		powerNext[i] = new ComplexNumber[3];
	}
	for(int i = 0; i < 3; ++i){
		for(int j = 0; j < 3; ++j){
			powerPrevious[i][j] = A[i][j];
		}
	}


	for(int n = 2; n < nMax; n++){
		//Calculate the matrix: A^n by multiplying the previous power by A. Store in powerNext.
		Multiply(powerPrevious, A, powerNext);
		//Make powerPrevious equal to powerNext
		for(int x = 0; x < 3; ++x){
			for(int y = 0; y < 3; ++y){
				powerPrevious[x][y] = powerNext[x][y];
			}
		}


		//Devide by the factorial of n.
		Devide(powerNext, factorial(n));

		//Add A^2/n! to result matrix
		addMatrix(res, powerNext);

		//Set powerNext to 0.
		for(int x = 0; x < 3; ++x){
			for(int y = 0; y < 3; ++y){
				powerNext[x][y] = ComplexNumber();
			}
		}
	}

	for(int i = 0; i < 3; i++){
			delete[] powerPrevious[i];
			delete[] powerNext[i];
	}
	delete[] powerPrevious;
	delete[] powerNext;
}



