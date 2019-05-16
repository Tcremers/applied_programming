#ifndef MATRIXHEADERDEF
#define MATRIXHEADERDEF
#include "Vector.hpp"

template <typename T>
class Matrix
{
private:

//	int *ary = new int[rows*cols]; is rewritten as:
//  ary[i][j] is then rewritten as
//	ary[i*cols+j]
//	Same idea applies for vectors
	int mNumRows, mNumCols; // dimensions
	vector<T> mData; // entries of matrix


public:
	// Constructor for a matrix of given dimensions
	// Instantiates a vector object with the given dimension
	Matrix(int numRows, int numCols): mNumRows(numRows), mNumCols(numCols), mData(numRows*numCols, 0)
	{
	}

	// Method to get number of rows of matrix
	int GetNumberOfRows() const
	{
		return mNumRows;
	}

	// Method to get number of columns of matrix
	int GetNumberOfColumns() const
	{
		return mNumCols;
	}

	// Overloading the round brackets
	// Note that this uses `zero-based' indexing,
	// and a check on the validity of the index
	T& operator()(int i, int j)
	{
		assert(i >= 0);
		assert(i < mNumRows);
		assert(j >= 0);
		assert(j < mNumCols);
		return mData[i*mNumCols+j];
	}

	// Overloading the round brackets for a const Matrix
	// Note that this uses `zero-based' indexing,
	// and a check on the validity of the index
	T const& operator()(int i, int j) const
	{
		assert(i >= 0);
		assert(i < mNumRows);
		assert(j >= 0);
		assert(j < mNumCols);
		return mData[i*mNumCols+j];
	}

	// Overloading the unary - operator
	Matrix operator-() const
	{
		Matrix mat(mNumRows, mNumCols);
		for (int i=0; i<mNumRows; i++)
		{
			for (int j=0; j<mNumCols; j++)
			{
				mat(i,j) = -mData[i*mNumCols+j];
			}
		}
		return mat;
	}

	// Overloading the binary + operator
	Matrix operator+(const Matrix& m1) const
	{
		assert(mNumRows == m1.mNumRows);
		assert(mNumCols == m1.mNumCols);
		Matrix mat(mNumRows, mNumCols);
		for (int i=0; i<mNumRows; i++)
		{
			for (int j=0; j<mNumCols; j++)
			{
				mat(i,j) = mData[i*mNumCols+j] + m1.mData[i*mNumCols+j];
			}
		}
		return mat;
	}

	// Overloading the binary - operator
	Matrix operator-(const Matrix& m1) const
	{
	   assert(mNumRows == m1.mNumRows);
	   assert(mNumCols == m1.mNumCols);
	   Matrix mat(mNumRows, mNumCols);
	   for (int i=0; i<mNumRows; i++)
	   {
	      for (int j=0; j<mNumCols; j++)
	      {
	         mat(i,j) = mData[i*mNumCols+j] - m1.mData[i*mNumCols+j];
	      }
	   }
	   return mat;
	}

	// Overloading scalar multiplicationn
	Matrix operator*(double a) const
	{
	   Matrix mat(mNumRows, mNumCols);
	   for (int i=0; i<mNumRows; i++)
	   {
	      for (int j=0; j<mNumCols; j++)
	      {
	         mat(i,j) = a*mData[i*mNumCols+j];
	      }
	   }
	   return mat;
	}

	vector<T> const& getStorage(){
		return this->mData;
	}
};

// Overloading matrix multiplied by a vector
template <typename T>
Vector<T> operator*(const Matrix<T>& m, const Vector<T>& v)
{
	int original_vector_size = v.size();
	assert(m.GetNumberOfColumns() == original_vector_size);
	int new_vector_length = m.GetNumberOfRows();
	Vector<T> new_vector(new_vector_length);

	for (int i=0; i<new_vector_length; i++)
	{
		for (int j=0; j<original_vector_size; j++)
		{
			new_vector[i] += m(i,j)*v[j];
		}
	}

	return new_vector;
}

// Overloading vector multiplied by a matrix
template <typename T>
Vector<T> operator*(const Vector<T>& v, const Matrix<T>& m)
{
	int original_vector_size = v.size();
	assert(m.GetNumberOfRows() == original_vector_size);
	int new_vector_length = m.GetNumberOfColumns();
	Vector<T> new_vector(new_vector_length);

	for (int i=0; i<new_vector_length; i++)
	{
		for (int j=0; j<original_vector_size; j++)
		{
			new_vector[i] += v[j]*m(j,i);
		}
	}
	return new_vector;
}






#endif
