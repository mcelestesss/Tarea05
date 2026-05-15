#pragma once
#include <stdexcept>
#include <iostream>
using namespace std;

template <typename E>
class Matrix {
private:
    E** matrix;
    int rows;
    int cols;

public:
    Matrix(int rows, int cols) {
        if (rows < 1 || cols < 1)
            throw runtime_error("Invalid index.");

        this->rows = rows;
        this->cols = cols;


        matrix = new E * [rows];

        for (int i = 0; i < rows; i++)
            matrix[i] = new E[cols];
    }

    ~Matrix() {
        for (int i = 0; i < rows; i++)
            delete[] matrix[i];
        delete[] matrix;
    }
};