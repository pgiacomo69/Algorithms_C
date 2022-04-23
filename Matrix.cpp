//
// Created by Pgiac on 22/04/2022.
//

#include "Matrix.h"
#include <cstdlib>
#include <sstream>
#include <iostream>
#include <chrono>

template class Matrix<int>;
template class Matrix<float>;

    /* template<typename T>
    template<size_t rows, size_t cols>
    Matrix<T>::Matrix(int (&array)[rows][cols]) {

    } */

    template<typename T>
    Matrix<T>::Matrix(size_t rows, size_t cols,std::string  name)  :Matrix() {
        allocateArray(rows,cols);
        this->name=name;
    }

    template<typename T>
    Matrix<T>::~Matrix()
    {
        // std::cout << " Deleting ";
        // std::cout << name << std::endl;
         delete[] values;
         delete[] rowIndexes;
    }

    template<typename T>
    T Matrix<T>::get(size_t row, size_t col) {
        return values[rowIndexes[row]+col];
    }

    template<typename T>
    void Matrix<T>::set(size_t row, size_t col, T value) {
        values[rowIndexes[row]+col]=value;
    }


template<typename T>
void Matrix<T>::add(size_t row, size_t col, T value) {
    values[rowIndexes[row]+col]+=value;
}

    template<typename T>
    void Matrix<T>::allocateArray(size_t rows, size_t cols) {
        if (cols==0) cols=rows;
         values = new T[cols*rows];
        _cols=cols;
        _rows=rows;
        size=cols*rows;
        rowIndexes=new size_t[rows];
        for (int  i=0;i<rows;i++)
        {
            rowIndexes[i]=(i*cols);
        }
    }

    template<typename T>
    void Matrix<T>::reset(bool random) {
        if (random) srand(0);
        for (int i = 0; i < size;i++)
            values[i]= !random ? 0: i % _cols;
    }

    template<typename T>
    void Matrix<T>::print() {
        for (int i = 0; i < _rows; i++)
            for (int j = 0; j < _cols; j++)
                // Prints ' ' if j != n-1 else prints '\n'
                std::cout << get(i,j) << " \n"[j == _cols-1];
    }

    template<typename T>
    Matrix<T>::Matrix() {
        resetCounters();
    }

// Matrix Multiply(Matrix otherMatrix,std::string newName="")
template<typename T>
 Matrix<T>* Matrix<T>::Multiply(Matrix<T>* otherMatrix,std::string newName) {
        if (_rows!=otherMatrix->_cols) {
            std::stringstream ss;
            ss << "Second Matrix must have a nuber of columns " <<   " equal to numbero of rows of First Matrix "  << std::endl;
            throw std::invalid_argument(ss.str());
        }
       Matrix<T>* result =new Matrix<T>(_rows,otherMatrix->_rows,newName);
        if (result->_rows!=_rows || result->_cols!=otherMatrix->_rows)
        {
            std::stringstream ss;
            ss << "Result Matrix is not compatible with first and second Matrix"  << std::endl;
            throw std::invalid_argument(ss.str());
        }


        result->reset();
        resetCounters();
    auto t1 = std::chrono::high_resolution_clock::now();
    for (int i = 0; i < result->_cols; i++)
    {
        for (int j = 0; j < result->_rows; j++)
        {
            for (int k = 0; k < _rows; k++)
            {
                multiplies++;
                sums++;
                result->add(i, j,get(i, k) * otherMatrix->get(k, j));
            }
        }
    }
    auto t2 = std::chrono::high_resolution_clock::now();

    /* Getting number of milliseconds as an integer. */
    auto ms_int = std::chrono::duration_cast<std::chrono::milliseconds>(t2 - t1);
    last_elapsed=ms_int.count();
      return result;
    }

template<typename T>
void Matrix<T>::resetCounters() {
    sums=0;
    multiplies=0;
    moves=0;
    last_elapsed=0;
}

template<typename T>
void Matrix<T>::printStats() {

    std::cout << "Sums:" << sums  << "  Moves:" << moves << " Multiplies:"<< multiplies << " Elapsed Time mSec:" << last_elapsed << std::endl;

}

template<typename T>
Matrix<T> *Matrix<T>::operator+(const Matrix<T> *&second) const {
    if (second->_rows!=_rows || second->_cols!=_cols)
    {
        std::stringstream ss;
        ss << "To Sum, First and Second Matrix must ave same sizes"  << std::endl;
        throw std::invalid_argument(ss.str());
    }
    Matrix<T>* result=new Matrix<T>(_rows,_cols);
    for (int i=0;i<size;i++) {
        result->values[i] = values[i] + second->values[i];

    }
    return result;
}

template<typename T>
Matrix<T> *Matrix<T>::operator-(const Matrix<T> *&second) const {
    if (second->_rows!=_rows || second->_cols!=_cols)
    {
        std::stringstream ss;
        ss << "To Subtract, First and Second Matrix must ave same sizes"  << std::endl;
        throw std::invalid_argument(ss.str());
    }
    Matrix<T>* result=new Matrix<T>(_rows,_cols);
    for (int i=0;i<size;i++)
        result->values[i]=values[i]-second->values[i];
    return result;
}

template<typename T>
Matrix<T> *Matrix<T>::Quadrant(size_t quadrant) {
    if (_rows %2 !=0 || _cols %2 !=0 || _cols!=_rows)
    {
        std::stringstream ss;
        ss << "To get a quadsrant, Matrix should be square, with even Cols/Rows"  << std::endl;
        throw std::invalid_argument(ss.str());
    }
    if (quadrant <=0 || quadrant >=4)
    {
        std::stringstream ss;
        ss << "To get a quantrant, Matrix should be square, with even Cols/Rows"  << std::endl;
        throw std::invalid_argument(ss.str());
    }
    size_t half=_rows/2;
    size_t qx=(quadrant-1) % 2;
    size_t qy=(quadrant-1) / 2;
    size_t qRowSize=(quadrant-1) / 2;
    auto result=new Matrix<T>(half);
    size_t baseIndex=(_cols*half*qy)+(half*qx);
    for (int i=0;i<half;i++)
    {

        moves +=half;
    }
    return result;
}






