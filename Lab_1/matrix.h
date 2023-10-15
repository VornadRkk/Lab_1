﻿#pragma once
#include <iostream>
#include <string>
#include <ctime>
#include <exception>
using namespace std;
namespace matrix {
    //заменить this на геттеры 
    template <typename T>
    class Matrix {
    private:
        int _rows;
        int _cols;
        T** _array;
    public:
        Matrix() : _rows(0), _cols(0), _array(nullptr) {}

        Matrix(int rows, int cols, const T& value);

        Matrix(int rows, int cols, T upper_bound, T lower_bound);

        int get_rows() const;

        int get_cols() const;

        T operator()(int index_one, int index_two) const;

        T& operator()(int index_one, int index_two);

        Matrix<T>& operator+(const Matrix<T>& arr);

        Matrix<T>& operator-(const Matrix<T>& arr);

        Matrix<T> operator*(const Matrix<T>& arr);

        Matrix<T>& operator*=(const T& value);

        Matrix<T>& operator/=(const T& value);
        /*Matrix<T>& operator=(const Matrix<T>& other);
        void Swap(Matrix<T>& other);*/

        T trace();
        /*friend ostream& operator <<(ostream& stream, const Matrix<T>& matrix);*/
        ~Matrix();
    };

   
    /*template <typename T>
    Matrix<T>& Matrix<T>::operator=(const Matrix<T>& other) {

    }

    template <typename T>
    void Matrix<T>::Swap(Matrix<T>& other) {
        swap(this->_rows, other._rows);
        swap(this->_cols, other._cols);
        this->_array.Swap(other._array);
    }*/

    template <typename T>
    int Matrix<T>::get_rows() const {
        return _rows;
    }

    template <typename T>
    int Matrix<T>::get_cols() const {
        return _cols;
    }


   /* template <typename T>
    T** get_array() {
        return _array;
    }*/

    template <typename T>
    Matrix<T>::Matrix(int rows, int cols, const T& value) {
        if (rows <= 0 || cols <= 0) {
            throw runtime_error("Invalid sizes of matrix");
        }
        this->_rows = rows;
        this->_cols = cols;
        this->_array = new T * [_rows];
        for (int i = 0; i < _rows; ++i) {
            this->_array[i] = new T[_cols];
        }
        for (int i = 0; i < _rows; ++i) {
            for (int j = 0; j < _cols; ++j) {
                this->_array[i][j] = value;
            }
        }
    }

    template <typename T>
    Matrix<T>::Matrix(int rows, int cols, T upper_bound, T lower_bound) {
        if (rows <= 0 || cols <= 0) {
            throw runtime_error("Invalid sizes of matrix");
        }
        this->_rows = rows;
        this->_cols = cols;
        _array = new T * [_rows];
        for (int i = 0; i < _rows; ++i) {
            _array[i] = new T[_cols];
        }
        for (int i = 0; i < _rows; ++i) {
            for (int j = 0; j < _cols; ++j) {
                _array[i][j] = rand() % upper_bound + lower_bound;
            }
        }
    }

    template <typename T>
    T Matrix<T>::operator()(int index_one, int index_two) const {
        if (index_one < 0 || index_two < 0 || index_one > this->_rows || index_two > this->_cols) {
            throw runtime_error("Invalid arguments");
        }
        return this->_array[index_one][index_two];
    }

    template <typename T>
    T& Matrix<T>::operator()(int index_one, int index_two) {
        if (index_one < 0 || index_two < 0 || index_one >= this->_rows || index_two >= this->_cols) {
            throw runtime_error("Index out of range");
        }
        return this->_array[index_one][index_two];
    }

    template <typename T>
    Matrix<T>& Matrix<T>::operator + (const Matrix<T>& arr) {
        if (this->_rows != arr.get_rows() || this->_cols != arr.get_cols()) {
            throw runtime_error("Size mismatch");
        }
        Matrix<T>* temp = new Matrix<T>(get_rows(), get_cols(), 0);
        for (int i = 0; i < this->_rows; ++i) {
            for (int j = 0; j < this->_cols; ++j) {
                temp->_array[i][j] = this->_array[i][j] + arr._array[i][j];
            }
        }
        return *temp;
    }

    template <typename T>
    Matrix<T>& Matrix<T>::operator - (const Matrix<T>& arr) {
        if (this->_rows != arr.get_rows() || this->_cols != arr.get_cols()) {
            throw runtime_error("Size mismatch");
        }
        Matrix<T>* temp = new Matrix<T>(get_rows(), get_cols(), 0);
        for (int i = 0; i < this->_rows; ++i) {
            for (int j = 0; j < this->_cols; ++j) {
                temp->_array[i][j] = this->_array[i][j] - arr._array[i][j];
            }
        }
        return *temp;
    }

    template<typename T>
    ostream& operator <<(ostream& stream, const Matrix<T>& matrix) {
        for (int i = 0; i < matrix.get_rows(); ++i) {
            for (int j = 0; j < matrix.get_cols(); ++j) {
                stream << matrix(i, j) << "\t";
            }
            stream << endl;
        }
        return stream;
    }

    template <typename T>
    Matrix<T> Matrix<T>:: operator * (const Matrix<T>& arr) {
        if (this->_cols != arr._rows) {
            throw runtime_error("Incompatible matrix sizes for multiplication");
        }
        Matrix<T> temp(this->_rows,arr.get_cols(),0);
        for (int i = 0; i < this->_rows; ++i) {
            for (int j = 0; j < arr._cols; ++j) {
                for (int k = 0; k < this->_cols; k++) {
                    temp._array[i][j] += this->_array[i][k] * arr._array[k][j];
                }
            }
        }
        return temp;
    }

    template <typename T>
    Matrix<T>& Matrix<T>::operator *= (const T& value) {
        for (int i = 0; i < this->_rows; ++i) {
            for (int j = 0; j < this->_cols; ++j) {
                this->_array[i][j] *= value;
            }
        }
        return *this;
    }

    template <typename T>
    Matrix<T>& Matrix<T>::operator /= (const T& value) {
        if (value == 0) {
            throw runtime_error("Invalid argument");
        }
        for (int i = 0; i < this->_rows; ++i) {
            for (int j = 0; j < this->_cols; ++j) {
                this->_array[i][j] /= value;
            }
        }
        return *this;
    }

    template <typename T>
    T Matrix<T>::trace() {
        if (this->_rows != this->_cols) {
            throw runtime_error("Impossible to calculate the trace");
        }
        T temp = 0;
        for (int i = 0; i < this->_rows; ++i) {
            for (int j = i; j <= i; ++j) {
                temp += this->_array[i][j];
            }
        }
        return temp;
    }

    template <typename T>
    Matrix<T>::~Matrix() {
        for (int i = 0; i < this->_rows; ++i) {
            delete this->_array[i];
        }
        delete[] this->_array;
    }
}
