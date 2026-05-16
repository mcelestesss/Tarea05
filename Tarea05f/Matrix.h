#pragma once
#include <stdexcept>
#include <iostream>
using namespace std;

template <typename Element>
class Matrix {
private:
    Element** matrix; 
    int rows;         
    int cols;        

public:
    Matrix(int rows, int cols) {
        if (rows < 1 || cols < 1)
            throw runtime_error("Invalid index.");

        this->rows = rows;
        this->cols = cols;

        matrix = new Element * [rows];

        for (int i = 0; i < rows; i++)
            matrix[i] = new Element[cols];
    }

    ~Matrix() {
        for (int i = 0; i < rows; i++)
            delete[] matrix[i];

        delete[] matrix;
    }

    
    Element getValue(int row, int col) {
        if (row < 0 || row >= rows)
            throw runtime_error("Invalid row.");
        if (col < 0 || col >= cols)
            throw runtime_error("Invalid column.");
        return matrix[row][col];
    }

    
    void setValue(int row, int col, Element value) {
        if (row < 0 || row >= rows)
            throw runtime_error("Invalid row.");
        if (col < 0 || col >= cols)
            throw runtime_error("Invalid column.");
        matrix[row][col] = value;
    }

   
    int getRows() {
        return rows;
    }

  
    int getColumns() {
        return cols;
    }

    void setAll(Element value) {
        for (int i = 0; i < rows; i++)
            for (int j = 0; j < cols; j++)
                matrix[i][j] = value;
    }


    void transpose() {
        Element** newMatrix = new Element * [cols];
        for (int i = 0; i < cols; i++) {
            newMatrix[i] = new Element[rows];
            for (int j = 0; j < rows; j++)
                newMatrix[i][j] = matrix[j][i];
        }

        for (int i = 0; i < rows; i++)
            delete[] matrix[i];
        delete[] matrix;

        matrix = newMatrix;
        int temp = rows;
        rows = cols;
        cols = temp;
    }


    void addRow(Element value) {
        Element** newMatrix = new Element * [rows + 1];

        for (int i = 0; i < rows; i++)
            newMatrix[i] = matrix[i];

        newMatrix[rows] = new Element[cols];
        for (int j = 0; j < cols; j++)
            newMatrix[rows][j] = value;

        delete[] matrix;
        matrix = newMatrix;
        rows++;
    }


    void addColumn(Element value) {
        transpose();   
        addRow(value); 
        transpose();   
    }


    void removeRow(int row) {
        if (row < 0 || row >= rows)
            throw runtime_error("Invalid row.");

        Element** newMatrix = new Element * [rows - 1];

        for (int r = 0; r < row; r++)
            newMatrix[r] = matrix[r];
        for (int r = row + 1; r < rows; r++)
            newMatrix[r - 1] = matrix[r];

        delete[] matrix[row];
        delete[] matrix;

        matrix = newMatrix;
        rows--;
    }

   
    void removeColumn(int col) {
        if (col < 0 || col >= cols)
            throw runtime_error("Invalid column.");
        transpose();    
        removeRow(col); 
        transpose();    
    }


    void print() {
        for (int i = 0; i < rows; i++) {
            for (int j = 0; j < cols; j++)
                cout << matrix[i][j] << "\t";
            cout << endl;
        }
    }
};