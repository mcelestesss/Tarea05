#include <iostream>
#include "Matrix.h"

using namespace std;

int main() {

    Matrix<int>* matriz = new Matrix<int>(3, 3);

    cout << "Matriz con setAll(0):" << endl;
    matriz->setAll(0);
    matriz->print();

    cout << "\nMatriz con setAll(7):" << endl;
    matriz->setAll(7);
    matriz->print();

    delete matriz;
};