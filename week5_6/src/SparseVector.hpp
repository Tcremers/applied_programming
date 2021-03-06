#ifndef SPARSE_VECTOR_HPP
#define SPARSE_VECTOR_HPP

#include "Vector.hpp"
#include "Matrix.hpp"
#include <vector>
#include <algorithm>
#include <cassert>
#include <math.h>


template<class T>
class SparseVector{

private:
	//Add your data members here!
	int mDimensionality;
	vector<int> mIndices;
	vector<T> mValues;

public:
	//creates an empty vector of dimensionality 0.
	SparseVector() : mDimensionality(0), mIndices(0), mValues(0)
	{
	}

	// Creates a vector of dimensionality dim. It starts with 0 nonzero elements
	// which need to be set using setValue
	SparseVector(unsigned int dim) : mDimensionality(dim)
	{
	}

	// assignment operators and copy constructor should be automatically
	// generated by the compiler when using a std::vector for internal storing.
	// However, test that assignment works!

	//sets the value v_i of the vector. if it does not exist it is added 
	void setValue(unsigned int index, T value){
		assert(index <= (unsigned)mDimensionality);
		if(binary_search(mIndices.begin(), mIndices.end(), index)){
			mValues[lower_bound(mIndices.begin(), mIndices.end(), index) - mIndices.begin()] = value;
		}
		else{
			//First index that's not smaller than value:
			auto lower = lower_bound(mIndices.begin(), mIndices.end(), index);
			auto upper = upper_bound(mIndices.begin(), mIndices.end(), index);
			// If there is no smaller index:
			// If vector is empty it will be index 0.
			if(lower == mIndices.end()){
				mValues.insert(mValues.end(), value);
				mIndices.insert(mIndices.end(), index);
			}
			// If there is a smaller index:
			// Add it before the next bigger value.
			else{
				int i = (upper - mIndices.begin());
				mValues.insert(mValues.begin() + i, value);
				mIndices.insert(mIndices.begin() + i, index);
			}
		}
	}
	

	//returns the value v_i of the vector. Returns 0 if the value is not stored
	T getValue(unsigned int index)const{
		if(binary_search(mIndices.begin(), mIndices.end(), index)){
			return mValues[lower_bound(mIndices.begin(), mIndices.end(), index) - mIndices.begin()];
		}
		else{
			return 0;
		}
	}
	
	//returns the dimensionality of the vector
	unsigned int size()const{
		return mDimensionality;
	}
	
	// returns the number stored elements
	unsigned int nonZeroes()const{
		return mValues.size();
	}
	//returns the index of the ith stored nonzero entry (in increasing order)
	unsigned int indexNonZero(unsigned int i)const{
		return mIndices[i];
	}
	//returns the value of the ith stored nonzero entry (in increasing order)
	T valueNonZero(unsigned int i)const{
		return mValues[i];
	}
	
	//adds x too the current vector
	SparseVector<T>& operator+= (SparseVector<T> const& x){
		assert(size() == x.size());
		for(unsigned int i = 0; i < x.nonZeroes(); i++){
			if(binary_search(mIndices.begin(), mIndices.end(), x.indexNonZero(i))){
				mValues[lower_bound(mIndices.begin(), mIndices.end(), x.indexNonZero(i)) - mIndices.begin()] += x.valueNonZero(i);
			}
			else{
				setValue(x.indexNonZero(i),x.valueNonZero(i));
			}
		}
		return *this;
	}
	//subtracts x from the current vector
	SparseVector<T>& operator-= (SparseVector<T> const& x){
		assert(size() == x.size());
		for(unsigned int i = 0; i < x.nonZeroes(); i++){
			if(binary_search(mIndices.begin(), mIndices.end(), x.indexNonZero(i))){
				mValues[lower_bound(mIndices.begin(), mIndices.end(), x.indexNonZero(i)) - mIndices.begin()] -= x.valueNonZero(i);
			}
			else{
				setValue(x.indexNonZero(i),x.valueNonZero(i));
			}
		}
		return *this;
	}

	//Unwinds the sparse vector into a dense vector.
	Vector<T> unWind() const{
		Vector<T> w(mDimensionality);
		for(unsigned int i = 0; i < nonZeroes(); i++){
			w[indexNonZero(i)] = getValue(i);
		}
		return w;
	}
};


// computes z= x+y, equivalent to z=x, z+=y
template<class T>
SparseVector<T> operator+(SparseVector<T> const& x, SparseVector<T> const& y){
	SparseVector<T> z = x;
	z += y;
	return z;
}

// computes z= x-y, equivalent to z=x, z-=y
template<class T>
SparseVector<T> operator-(SparseVector<T> const& x, SparseVector<T> const& y){
	SparseVector<T> z = x;
	z -= y;
	return z;
}


// computes the matrix-vector product of a dense matrix and sparse vector z=Ax.
// The result is a dense vector.
// I just assumed that it would be more efficient and easier to
// unwind the sparse matrix since you're dealing with dense matrices anyway.
template<class T>
Vector<T> operator* (Matrix<T> const& A, SparseVector<T> const& x){
	return A * x.unWind();
}


// computes the matrix-vector product of a dense matrix and sparse vector z=x^TA.
// The result is a dense vector.
// I just assumed that it would be more efficient and easier to
// unwind the sparse matrix since you're dealing with dense matrices anyway.
template<class T>
Vector<T> operator* (SparseVector<T> const& x, Matrix<T> const& A){
	return x.unWind() * A;
}


#endif
