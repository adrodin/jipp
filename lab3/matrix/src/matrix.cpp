#include <iostream>
#include "matrix.hpp"
#include <fstream>
#include <string>

Matrix::Matrix(int n) {
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
    if (file.good()) {
        file >> n >> m;
        this->row = n;
        this->col = m;
        this->matrixArray = new double* [n];
        for (int i = 0; i < n; i++)
            this->matrixArray[i] = new double[m];

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                file >> value;
                this->matrixArray[i][j] = value;
            }
        }
        file.close();
    }
    else {
        std::cout << "Błąd pliku" << std::endl;
    }
}

Matrix::~Matrix() {
    for (int i = 0; i < this->cols(); i++)
        delete[] matrixArray[i];

    delete[] matrixArray;
}

void Matrix::set(int n, int m, double value) {
    this->matrixArray[n][m] = value;
}
double Matrix::get(int n, int m) {
    return this->matrixArray[n][m];
}
Matrix Matrix::add(Matrix &m2) {
    if (this->cols() != m2.cols() || this->rows() != m2.cols()) {
        std::cout << "Nie da sie dodac" << std::endl;
        return 0;
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
        std::cout << "Nie da sie odjac" << std::endl;
        return 0;
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
        std::cout << "Nie da sie mnozyc" << std::endl;
        return 0;
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

    if (file.good()) {
        file << this->rows() << " " << this->cols() << std::endl;

        for (int i = 0; i < this->rows(); i++) {
            for (int j = 0; j < this->cols(); j++) {
                file << this->matrixArray[i][j] << " ";
            }
            file << std::endl;
        }
        file.close();
    }
    else {
        std::cout << "Błąd z plikiem" << std::endl;
    }

}

