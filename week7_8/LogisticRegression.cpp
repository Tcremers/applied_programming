/*
 * LogisticRegression.cpp
 *
 *  Created on: 10 jun. 2017
 *      Author: Tycho
 */


#include <fstream>
#include <iostream>
#include <string>
#include <cassert>
#include <vector>
#include <math.h>

#include "GetData.h"
#include "armadillo.hpp"

using namespace std;
using namespace arma;


rowvec optimW(GetData data, double e){
	double normW = e*2; //Save previous norm to compare against next norm.
	double a = 0.99; //Learning rate
	double n = data.getXData()[0].size(); //Length of x vector

	int yi;
	rowvec w(n, fill::zeros); //Starting guess = vectors with 0s
	rowvec xi;
	int count = 0;

	//While the norm is not smaller than e...
	while(normW > e){
		cout << count << endl; //Print iteration count
		count ++;

		rowvec wNext = zeros<rowvec>(n); //Set empty w next


		//Sum of yi * 1/1+exp(yi*wT*xi) * xi
		double coef;
		for(unsigned int i = 0; i < data.getXData().size(); i++){
			xi = data.getXData()[i];
			yi = data.getYdata()[i];
			coef = 0;
			rowvec wTemp = zeros<rowvec>(n); //Set empty w next

			for(unsigned int j = 0; j < xi.size(); j++){
				coef += w[j] * xi[j];
			}
			coef = yi/( 1 + exp(coef*yi));
			for(unsigned int k = 0; k < xi.size(); k++){
				wNext[k] += xi[k] * coef;
			}
//			wNext += yi * xi / (1 + exp(yi * xi * w.t())[0]);
		}

		wNext *= -(1 / double(data.getXData().size()));
		w = w - a * wNext; //New w
		normW = norm(wNext); //Save norm
		cout << "Norm: " << normW << endl;
	}
	cout << count << endl;
	cout << w << endl;
	return w;
}

void logisticRegression(){
	GetData data;
	ofstream outFile("LogReg.dat");
	assert(outFile.is_open());
	rowvec w = optimW(data, pow(10,-7));


	double yTest;
	rowvec xTest;
	for (unsigned int i=0; i < data.getXTestData().size(); i++)
	{
		yTest = 0;
		xTest = data.getXTestData()[i];
		for(unsigned int j = 0; j < xTest.size(); j++ ){
			yTest += xTest[i] * w[i];
		}
		if (yTest > 0)
		{
			outFile << "1\n";
		}
		else
		{
			outFile << "-1\n";
		}
	}

//	for(unsigned int i = 0; i < data.getXTestData().size(); i++){
//		mat fx;
//
//		fx = w.t() * data.getXTestData()[i];
//		cout << accu(fx) << endl;
//		if(accu(fx) > 0){
//			outFile << "1\n";
//			cout << "1\n";
//		}
//		else{
//			outFile << "-1\n";
//			cout << "-1\n";
//		}
//	}
	outFile.close();
}

int main(){
	logisticRegression();
}
