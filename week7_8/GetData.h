/*
 * GetData.h
 *
 *  Created on: Jun 13, 2017
 *      Author: Tycho
 */

#ifndef GETDATA_H_
#define GETDATA_H_

#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <cassert>
#include "armadillo.hpp"

namespace std {



class GetData {
private:
	arma::rowvec foo;
	vector<arma::rowvec> mxData;
	vector<arma::rowvec> mxTestData;
	vector<int> myData;
public:
	GetData(){
		ifstream xData("dataX.dat");
		ifstream xTestData("dataXtest.dat");
		ifstream yData("dataY.dat");
		assert(xData.good());
		assert(xTestData.good());
		assert(yData.good());

		string line;
		while (getline(xData, line)) {
			mxData.push_back(arma::rowvec(line));
		}
		while (getline(xTestData, line)) {
			mxTestData.push_back(arma::rowvec(line));
		}

		int y;
		while (yData >> y)
		{
			myData.push_back(y);
		}
		xData.close();
		xTestData.close();
		yData.close();
	}

	vector<arma::rowvec> getXData() const{
		return mxData;
	}
	vector<arma::rowvec> getXTestData() const{
		return mxTestData;
	}

	vector<int> getYdata() const{
		return myData;
	}
};

} /* namespace std */

#endif /* GETDATA_H_ */
