//
// Created by Pgiac on 22/04/2022.
//
#include <vector>
#include <cstddef>
#include <string>


#ifndef ALGORITHMS_C_MATRIX_H
#define ALGORITHMS_C_MATRIX_H


    template <typename T>  class Matrix {
    private:
        T* values;
        size_t* rowIndexes;
        size_t _cols;
        size_t _rows;
        size_t size=0;
        std::string name;
        long last_elapsed;
        void allocateArray(size_t rows,size_t cols=0);

    public:
        long long sums;
        long long multiplies;
        long long moves;
        Matrix();
        explicit Matrix(size_t rows,size_t cols=0,std::string name="");

        void resetCounters();
        void reset(bool random=false);

        friend Matrix<T> operator+(Matrix<T> const& first, Matrix<T> const& second);

        // Matrix<T>* operator+ (const Matrix<T>* & first,const Matrix<T>* & second) const;
        Matrix<T>* operator- (const Matrix<T>* & second) const;


        Matrix<T>*  Multiply(Matrix* otherMatrix,std::string newName="");
        Matrix<T>*  Quadrant(size_t q);

        // Matrix Multiply(Matrix otherMatrix,std::string newName="");

        // template <size_t rows, size_t cols=0>  Matrix(int (&array)[rows][cols]);
        T get(size_t row,size_t col);

        void set(size_t row,size_t col, T value);
        void add(size_t row,size_t col, T value);

        void print();
        void printStats();

        ~Matrix();
    };







#endif //ALGORITHMS_C_MATRIX_H
