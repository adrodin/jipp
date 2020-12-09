#include <iostream>
#ifndef __MATRIX__
#define __MATRIX__

class Matrix {
private:
    int col;
    int row;
    double** matrixArray;
    void checkIndex(int n, int m);
public:
    Matrix(int n);
    Matrix(int n, int m);
    Matrix(std::string filePath);
    ~Matrix();
    void set(int n, int m, double value);
    double get(int n, int m);
    Matrix add(Matrix &m2);
    Matrix substract(Matrix &m2);
    Matrix multiply(Matrix &m2);
    int cols();
    int rows();
    void print();
    void store(std::string fileName, std::string path);


};

#endif