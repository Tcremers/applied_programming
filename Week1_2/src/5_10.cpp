/*
 * 5_10.cpp
 *
 *  Created on: 24 mei 2017
 *      Author: Tycho
 */

#include <iostream>
#include "5_10.h"
#include <cmath>
#include <cassert>
#include <vector>
#include <numeric>
using namespace std;

//Function to neatly print a matrix to the concole.
void print(vector< vector<double> > A) {
    int n = A.size();
    for (int i=0; i<n; i++) {
        for (int j=0; j<n+1; j++) {
            cout << A[i][j] << "\t";
            if (j == n-1) {
                cout << "| ";
            }
        }
        cout << "\n";
    }
    cout << endl;
}

//Implementation of the gausian elemination algorithm.
vector<double> gauss(vector< vector<double> > A) {
    int n = A.size();

    for (int i=0; i<n; i++) {
        // Search for maximum in this column
        double maxEl = abs(A[i][i]);
        int maxRow = i;
        for (int k=i+1; k<n; k++) {
            if (abs(A[k][i]) > maxEl) {
                maxEl = abs(A[k][i]);
                maxRow = k;
            }
        }

        // Swap maximum row with current row (column by column)
        for (int k=i; k<n+1;k++) {
            double tmp = A[maxRow][k];
            A[maxRow][k] = A[i][k];
            A[i][k] = tmp;
        }

        // Make all rows below this one 0 in current column
        for (int k=i+1; k<n; k++) {
            double c = -A[k][i]/A[i][i];
            for (int j=i; j<n+1; j++) {
                if (i==j) {
                    A[k][j] = 0;
                } else {
                    A[k][j] += c * A[i][j];
                }
            }
        }
    }

    // Solve equation Ax=b for an upper triangular matrix A
    vector<double> x(n);
    for (int i=n-1; i>=0; i--) {
        x[i] = A[i][n]/A[i][i];
        for (int k=i-1;k>=0; k--) {
            A[k][n] -= A[k][i] * x[i];
        }
    }
    return x;
}

//Solve a linear matrix equation for an N by N matrix with the gausian elimination method.
void guassian_elimination(double **A, double *b, double *u, int n){
	//TODO: eliminate some mister gaussian...

    vector<double> line(n+1,0);
    vector< vector<double> > input(n,line);

    // Read input data
    for (int i=0; i<n; i++) {
        for (int j=0; j<n; j++) {
            input[i][j] = A[i][j];
        }
    }
    for (int i=0; i<n; i++) {
        input[i][n] = b[i];
    }
    // Print input
    print(input);

    // Calculate solution
    vector<double> x(n);
    x = gauss(input);

    // Print result
    cout << "Result:\t";
    for (int i=0; i<n; i++) {
        cout << x[i] << " ";
    }
    cout << endl;
    for (int i=0; i<n; i++) {
    	u[i] = x[i];
	}
}
