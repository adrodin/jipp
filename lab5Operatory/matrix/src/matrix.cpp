#include <iostream>
#include "matrix.hpp"
#include <fstream>
#include <string>
#include <exception>


Matrix::Matrix(int n) {

    if(n<0){
        throw std::invalid_argument("n should be greather than 0");
    }

    this->col = n;
    this->row = n;

    this->matrixArray = new double* [n];
    for (int i = 0; i < n; i++)
        this->matrixArray[i] = new double[n];

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            this->matrixArray[i][j] = 0;
        }
    }

}



Matrix::Matrix(int n, int m) {
    if(n<0 || m<0){
        throw std::invalid_argument("n and m should be greather than 0");
    }

    this->col = n;
    this->row = m;
    this->matrixArray = new double* [n];
    for (int i = 0; i < n; i++)
        this->matrixArray[i] = new double[m];

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            this->matrixArray[i][j] = 0;
        }
    }
}

Matrix::Matrix(std::string filePath) {

    std::ifstream  file;
    file.open(filePath, std::ios_base::in);
    int n, m;
    double value;
    if(file.bad()){
        throw std::runtime_error("Can't open the file");
    }

    file >> n >> m;
    if(n<0 || m<0){
        throw std::runtime_error("File is bad");
    }
    this->row = n;
    this->col = m;

    this->matrixArray = new double* [n];
    for (int i = 0; i < n; i++)
        this->matrixArray[i] = new double[m];

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (file.peek() == file.eof()){
                throw std::runtime_error("File is bad");
            }
            file >> value;
            this->matrixArray[i][j] = value;
        }
    }
    file.close();

}

Matrix::~Matrix() {
    for (int i = 0; i < this->cols(); i++)
        delete[] matrixArray[i];

    delete[] matrixArray;
}

void Matrix::checkIndex(int n, int m){
    if(n<0 || n>this->row || m<0 || m>this->col){
        throw std::out_of_range("n and m must be greather than 0 and less than number of columns or rows");
    }

}

void Matrix::set(int n, int m, double value) {
    checkIndex(n,m);
    this->matrixArray[n][m] = value;
}

double Matrix::get(int n, int m) {
    checkIndex(n,m);
    return this->matrixArray[n][m];
}

Matrix Matrix::add(Matrix &m2) {
    if (this->cols() != m2.cols() || this->rows() != m2.cols()) {
        throw std::invalid_argument("unable to add - dimension mismatch");
    }

    Matrix newMatrix(this->cols(), this->rows());
    double sum;
    for (int i = 0; i < this->col; i++) {
        for (int j = 0; j < this->row; j++) {
            sum = this->matrixArray[i][j] + m2.matrixArray[i][j];
            newMatrix.set(i, j, sum);
        }
    }
    return newMatrix;
}


Matrix Matrix::substract(Matrix &m2) {
    if (this->cols() != m2.cols() || this->rows() != m2.cols()) {
        throw std::invalid_argument("unable to substract - dimension mismatch");
    }

    Matrix newMatrix(this->cols(), this->rows());
    double sub;
    for (int i = 0; i < this->col; i++) {
        for (int j = 0; j < this->row; j++) {
            sub = this->get(i, j) - m2.matrixArray[i][j];
            newMatrix.set(i, j, sub);
        }
    }
    return newMatrix;
}

Matrix Matrix::multiply(Matrix &m2) {
    if (this->rows() != m2.cols()) {
        throw std::invalid_argument("unable to multiply - dimension mismatch");
    }
    Matrix newMatrix(this->cols(), m2.rows());
    double value=0;
    for (int i = 0; i < this->cols(); i++) {
        for (int j = 0; j < m2.rows(); j++) {
            for (int k = 0; k < m2.rows(); k++) {
                value += this->get(i, k) + m2.matrixArray[k][j];
            }
            newMatrix.set(i, j, value);
            value = 0;
        }
    }
    return newMatrix;

}

int Matrix::cols() {
    return this->col;
}

int Matrix::rows() {
    return this->row;
}


void Matrix::print() {
    for (int i = 0; i < this->col; i++) {
        for (int j = 0; j < this->row; j++) {
            std::cout << this->matrixArray[i][j] << " ";
        }
        std::cout << std::endl;
    }


}

void Matrix::store(std::string fileName, std::string path) {
    path = path + '/' + fileName;

    std::ofstream  file;
    file.open(path, std::ios_base::out);
    if(file.bad()){
        throw std::runtime_error("Can't open the file");
    }

    file << this->rows() << " " << this->cols() << std::endl;

     for (int i = 0; i < this->rows(); i++) {
        for (int j = 0; j < this->cols(); j++) {
            file << this->matrixArray[i][j] << " ";
        }
        file << std::endl;
    }
    file.close();

}


Matrix Matrix::operator+(Matrix &m2){
     if (this->cols() != m2.cols() || this->rows() != m2.cols()) {
        throw std::invalid_argument("unable to add - dimension mismatch");
    }

    Matrix newMatrix(this->cols(), this->rows());
    double sum;
    for (int i = 0; i < this->col; i++) {
        for (int j = 0; j < this->row; j++) {
            sum = this->matrixArray[i][j] + m2.matrixArray[i][j];
            newMatrix.set(i, j, sum);
        }
    }
    return newMatrix;
}

Matrix Matrix::operator-(Matrix &m2){
     if (this->cols() != m2.cols() || this->rows() != m2.cols()) {
        throw std::invalid_argument("unable to substract - dimension mismatch");
    }

    Matrix newMatrix(this->cols(), this->rows());
    double sub;
    for (int i = 0; i < this->col; i++) {
        for (int j = 0; j < this->row; j++) {
            sub = this->get(i, j) - m2.matrixArray[i][j];
            newMatrix.set(i, j, sub);
        }
    }
    return newMatrix;
}

Matrix Matrix::operator*(Matrix &m2){
    if (this->rows() != m2.cols()) {
        throw std::invalid_argument("unable to multiply - dimension mismatch");
    }
    Matrix newMatrix(this->cols(), m2.rows());
    double value=0;
    for (int i = 0; i < this->cols(); i++) {
        for (int j = 0; j < m2.rows(); j++) {
            for (int k = 0; k < m2.rows(); k++) {
                value += this->get(i, k) + m2.matrixArray[k][j];
            }
            newMatrix.set(i, j, value);
            value = 0;
        }
    }
    return newMatrix;
}

bool Matrix::operator==(Matrix &m2){
    if(this->row!=m2.rows() || this->col!=m2.cols()) return false;

    for(int i=0;i<this->row;i++){
        for(int j=0;j<this->col;j++){
            if(this->get(i,j)!=m2.get(i,j)) return false;
        }

    }
    return true;
}

void operator<< (std::ofstream &out, Matrix &m){
    if(out.is_open()){
    out<<m.rows()<<" "<<m.cols();
    for (int i = 0; i < m.cols(); i++) {
        for (int j = 0; j < m.rows(); j++) {
            out<< m.get(i,j) << " ";
        }
        out << std::endl;
    }
    out.close();
    }
    else{
        throw std::runtime_error("Can't open the file");
    }
}

double* Matrix::operator[](int index){

    return this->matrixArray[index];
}

bool Matrix::operator!=(Matrix &m2){
    if(this->row!=m2.rows() || this->col!=m2.cols()) return true;

    for(int i=0;i<this->row;i++){
        for(int j=0;j<this->col;j++){
            if(this->get(i,j)==m2.get(i,j)) return false;
        }

    }
    return true;
}

void Matrix::operator--(int value){
    for (int i = 0; i < this->col; i++) {
        for (int j = 0; j < this->row; j++) {
            this->matrixArray[i][j]--;
        }
    }
}

void Matrix::operator++(int value){
    for (int i = 0; i < this->col; i++) {
        for (int j = 0; j < this->row; j++) {
            this->matrixArray[i][j]++;
        }
    }
}
