//============================================================================
// Name        : Week1_2.cpp
// Author      : Tycho
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
#include <string>
#include "2_6.h"
#include "3_3.h"
#include "5_3.h"
#include "5_4.h"
#include "5_6.h"
#include "5_9.h"
#include "5_10.h"

using namespace std;


void printMatrix(double **A, int r, int c){
	for(int i = 0; i < r; i++){
		for(int j = 0; j < c; j++){
			cout << A[i][j] << " ";
		}
		cout << endl;
	}
	cout << endl;
}

void printVector(double *A, int r){
	for(int i = 0; i < r; i++){
		cout << A[i] << " ";
	}
	cout << endl;
	cout << endl;
}

void testMatrixMulti(){
	int ARows = 3;
	int ACols = 3;

	int BRows = 3;
	int BCols = 3;


	double** A = new double*[ARows];
	double** B = new double*[BRows];

	for (int i=0; i< ARows; i++){
		A[i] = new double [ACols]();

	}
	for (int i=0; i< BRows; i++){
		B[i] = new double [BCols]();
	}

	double** res = new double*[ARows];
	for (int i=0; i < BCols; i++){
		res[i] = new double [BCols]();
	}
	printMatrix(res,ARows,BCols);
	cout << endl;
	fillMatrix(A,ARows,ACols,3);
	fillMatrix(B,BRows,BCols,4);
	A[0][0] = 1, A[1][0] = 1;
	B[0][0] = 1, B[1][0] = 1;
	printMatrix(A,ARows,ACols);
	cout << endl;
	printMatrix(B,BRows,BCols);

	Multiply(res, A, B, ARows, ACols, BRows, BCols);

	cout << endl;
	printMatrix(res,ARows, BCols);

	cout << endl<< res[1][2] << endl;

}

int main() {
	//testMatrixMulti();
	int ACols = 3;
	int BRows = 3;
	int BCols = 3;
	double* u = new double[ACols]();
	double* A = new double[ACols]();
	double** B = new double*[BRows];
	for (int i=0; i< BRows; i++){
			B[i] = new double [BCols]();
	}
	fillMatrix(B,BRows,BCols,4);
	fillVector(A,ACols, 3);
	A[0] = 3, A[1] = 2; A[2] = 6;

	B[0][0] = 1, B[0][1] = 2, B[0][2] = 3;
	B[1][0] = 4, B[1][1] = 5, B[1][2] = 6;
	B[2][0] = 7, B[2][1] = 8, B[2][2] = 8;

	printMatrix(B, BRows, BCols);
	printVector(A,ACols);

	solve3by3(B, A, u);

	printVector(u,3);


}


