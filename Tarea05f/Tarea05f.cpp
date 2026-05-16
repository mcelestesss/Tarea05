#include <iostream>
#include "Matrix.h"
using namespace std;

int main() {
   
    Matrix<int>* matriz = new Matrix<int>(2, 3);
    matriz->setAll(1);

    cout << "Matriz original:" << endl;
    matriz->print();

    matriz->addRow(9);
    cout << "\nDespues debe ser 3x3:" << endl;
    matriz->print();
    cout << "Filas: " << matriz->getRows() << ", Columnas: " << matriz->getColumns() << endl;

    matriz->addColumn(5);
    cout << "\nDespues debe ser 3x4:" << endl;
    matriz->print();
    cout << "Filas: " << matriz->getRows() << ", Columnas: " << matriz->getColumns() << endl;

    delete matriz;

    return 0;
};