/*
 * 3_3.cpp
 *
 *  Created on: 20 mei 2017
 *      Author: Tycho
 */

#include "3_3.h"
#include <iostream>
#include <cmath>
#include <numeric>
#include <cassert>
#include <fstream>
using namespace std;

//Not (yet) exactly the implementation of the implicit euler method because I couldn't for the life of me figure out how it actually works.
//Calculate step size (h) for given n.
//Then calculate y at x for n points on the interval 0 <= x <= 1.
//Store x and y in a comma dilimeted file called "xy.dat"
void implicit_Euler(int n){
	assert(n > 1);
	double h = 1/double(n);
	double y;
	double x;
	cout << "Implicit euler, writing data to file..." << endl;
	ofstream write_output("xy.dat");
	assert(write_output.is_open());
	for(int i = 0; i <= n; i +=1){
		x = h*i;
		y = exp(-x);
		cout << x << " " << y << endl;
		write_output << x << "," << y << "\n";
	}
	cout << "Done..." << endl;
	write_output.close();
}


