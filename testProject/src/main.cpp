//Eulers Method to solve a differential equation
#include <iostream>
#include <iomanip>
#include <cmath>
#include <vector>
#include <iterator>
#include <algorithm>
#include <fstream>
#include <typeinfo>

using namespace std;

double df(double x, double y)            //function for defining dy/dx
{
    double a= -y;                //dy/dx=y
    return a;
}

class A
{
private:
	int mSize;
	vector<int> mData;
public:

	A(int value) : mSize(value), mData(value, 0)
	{
	}
	int getValue(){
		return mSize;
	}
	vector<int> getVector(){
		return mData;
	}
};


class MyInt4 {
  public:
    int x; int y; int z; int w;

    inline MyInt4() {
        x = 0; y = 0; z = 0; w = 0;
    }

    inline MyInt4(const int& a, const int& b, const int& c, const int& d) {
        x = a; y = b; z = c; w = d;
    }

    inline MyInt4(const MyInt4& i4) {
        x = i4.x; y = i4.y; z = i4.z; w = i4.w;
    }

    inline MyInt4& operator=(const MyInt4& i4) {
        x = i4.x; y = i4.y; z = i4.z; w = i4.w;
        return *this;
    }
};


int main()
{
//	vector<int> foo(0);
//	foo.insert(foo.begin() + 3, 5);
//	cout << lower_bound(foo.begin(), foo.end(), 6) - foo.begin() << endl;
//	cout << upper_bound(foo.begin(), foo.end(), 2) - foo.begin() << endl;
//	foo.insert(upper_bound(foo.begin(), foo.end(), 2),2);
//	unsigned int fuck = 123;
//	foo.insert(foo.begin() + 0,fuck);
//	cout << foo[0];
//	float []x = 25;
//	x = pow((x/(x-2.3)),3);
//	cout << x;
//	MyInt4* foo = (MyInt4*) malloc(5 * sizeof(MyInt4));
//	const MyInt4 bar(1,2,3,4);
	{
	float foo = 23;
	for (int i = 0; i < 10; ++i) {
		float *bar;
		bar += i + 312;
		cout << &foo << " " << &bar << endl;
	}

	cout << foo << endl;
	}
}
