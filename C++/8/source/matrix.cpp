#include <bits/c++config.h>
#include <ostream>

#include "../headers/matrix.h"

template <class T> Matrix<T>::~Matrix() {
	destroy(matrix);
}

template <class T> void Matrix<T>::fill(T value) {
	for (int i = 0; i < matrix.size(); i++)
		for (int j = 0; j < matrix.at(i).size(); j++)
			matrix.at(i).at(j) = value;
}

template <class T> void Matrix<T>::set(int row, int col, T value) {
	matrix.get(row).get(col) = value;
}

// template <class T> const T& Matrix<T>::get(int row, int col) const {
template <class T> T Matrix<T>::get(int row, int col) {
	return matrix.get(row).get(col);
}

template <class T> std::ostream& operator<<(std::ostream& out, Matrix<T> mat) {
	for (std::vector<T> i : Matrix<T>::matrix) {
		out << "[";
		for (T j : i)
			out << j << ", ";
		out << "]" << std::endl;
	}
	return out;
}

template <class T> std::vector<T>& Matrix<T>::operator[](std::size_t index) {
	return Matrix<T>::matrix[index];
}

template <class T> const std::vector<T>& Matrix<T>::operator[](std::size_t index) const {
	return Matrix<T>::matrix[index];
}
