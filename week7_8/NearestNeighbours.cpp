/*
 * NearestNeighbours.cpp
 *
 *  Created on: 10 jun. 2017
 *      Author: Tycho
 */

#include <fstream>
#include <iostream>
#include <string>
#include <cassert>
#include <vector>

#include "GetData.h"
#include "armadillo.hpp"


using namespace std;
using namespace arma;


int calcLabel(vector<pair<double,int> > sortedScorePairs, int k){
	int positive = 0;
	int negative = 0;
	for(int i = 0; i < k; i++){
		if(sortedScorePairs[i].second == 1){
			positive++;
		}
		else{
			negative++;
		}
	}
	if(positive > negative){
		return 1;
	}
	else{
		return -1;
	}
}




void kNearestNeighbours(){
	GetData data;
	ofstream outFile("NN.dat");
	assert(outFile.is_open());
	int k = 5;
	for(unsigned int i = 0; i < data.getXTestData().size(); i++){
		vector<pair<double,int> > scorePairs;
		for(unsigned int j = 0; j < data.getXData().size(); j++){
			pair<double,int> foo;
			scorePairs.push_back(make_pair(norm(data.getXTestData()[i] - data.getXData()[j]), data.getYdata()[j]));
		}
		sort(scorePairs.begin(), scorePairs.end());
		int label = calcLabel(scorePairs, k);
		//TODO: write label to file: NN.dat
		outFile << label << "\n";
		cout << label << "\n";
	}
	outFile.close();
}

int main(){
	kNearestNeighbours();
}
