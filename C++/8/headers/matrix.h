/*
 * File: matrix.h
 * --------------
 * so basically
 * it's a vector
 * but there's TWO of them
 * "bro that's crazy" --rayyan sarkhot
 */

#ifndef _matrix_h
#define _matrix_h

#include <vector>
#include <ostream>

template <typename ValueType>
class Matrix {
	public:
		Matrix();
		Matrix(int rows, int cols);
		~Matrix();

		void fill(ValueType value);
		void set(int row, int col, ValueType value);
		int size() const;
		ValueType get(int row, int col);
		// const ValueType &get(int row, int col) const;

		friend std::ostream& operator<<(std::ostream& out, Matrix& mat);
		std::vector<ValueType>& operator[](std::size_t index);
		const std::vector<ValueType>& operator[](std::size_t index) const;
	private:
		std::vector<std::vector<ValueType>> matrix;
};

#endif
