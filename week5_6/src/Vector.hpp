#ifndef VECTORHEADERDEF
#define VECTORHEADERDEF

#include <vector>
#include <cassert>
#include <math.h>
using namespace std;

template <typename T>
class Vector
{
private:
	int mSize; // size of vector
	vector<T> mData; // data stored in vector
public:
	// Constructor for vector of a given size.
	// Instantiates a vector object and initialises entries
	// to zero.
	Vector(int size) : mSize(size), mData(size, 0)
	{
	}

	//get size variable
	int size() const
	{
		return mSize;
	}

	// Overloading square brackets
	// Note that this uses `zero-based' indexing,
	// and a check on the validity of the index
	T& operator[](int i)
	{
		assert(i >= 0);
		assert(i < mSize);
		return mData[i];
	}

	// Overloading square brackets for const Vector
	// Note that this uses `zero-based' indexing,
	// and a check on the validity of the index
	T const& operator[] (int i)const
	{
		assert(i >= 0);
		assert(i < mSize);
		return mData[i];
	}

	// unary -
	Vector operator-() const
	{
		Vector v(mSize);
		for (int i=0; i<mSize; i++)
		{
			v[i] = -mData[i];
		}
		return v;
	}
	// binary +
	Vector operator+(const Vector& v1) const
	{
		assert(mSize == v1.mSize);
		Vector v(mSize);
		for (int i=0; i<mSize; i++)
		{
			v[i] = mData[i] + v1.mData[i];
		}
		return v;
	}
	// binary -
	Vector operator-(const Vector& v1) const
	{
		assert(mSize == v1.mSize);
		Vector v(mSize);
		for (int i=0; i<mSize; i++)
		{
			v[i] = mData[i] - v1.mData[i];
		}
		return v;
	}

	// scalar multiplication
	Vector operator*(double a) const
	{
		Vector v(mSize);
		for (int i=0; i<mSize; i++)
		{
			v[i] = a*mData[i];
		}
		return v;
	}

	// Method to calculate norm (with default value p=2)
	// corresponding to the Euclidean norm
	double CalculateNorm(int p=2) const
	{
		double norm_val, sum = 0.0;
		for (int i=0; i<mSize; i++)
		{
			sum += pow(fabs(mData[i]), p);
		}
		norm_val = pow(sum, 1.0/((double)(p)));
		return norm_val;
	}

	vector<T> const& getStorage(){
		return this->mData;
	}
};

#endif
