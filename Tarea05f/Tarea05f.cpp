#include <iostream>
#include "Matrix.h"
using namespace std;

int main() {
    Matrix<int>* matriz = new Matrix<int>(3, 4);
    int valor = 1;
    for (int i = 0; i < matriz->getRows(); i++)
        for (int j = 0; j < matriz->getColumns(); j++)
            matriz->setValue(i, j, valor++);

    cout << "Matriz original (3x4):" << endl;
    matriz->print();

    matriz->removeRow(1);
    cout << "\nDespues debe ser 2x4:" << endl;
    matriz->print();
    cout << "Filas: " << matriz->getRows() << ", Columnas: " << matriz->getColumns() << endl;

    matriz->removeColumn(0);
    cout << "\nDespues debe ser 2x3:" << endl;
    matriz->print();
    cout << "Filas: " << matriz->getRows() << ", Columnas: " << matriz->getColumns() << endl;

    delete matriz;
    return 0;
};