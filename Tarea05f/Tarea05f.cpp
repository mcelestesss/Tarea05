#include <iostream>
#include "Matrix.h"

using namespace std;

int main() {


    Matrix<int> m(3, 4);
    cout << "Matriz creada. " << endl;

    // Asignar val
    int valor = 1;
    for (int i = 0; i < m.getRows(); i++)
        for (int j = 0; j < m.getColumns(); j++)
            m.setValue(i, j, valor++);


    cout << "Contenido:" << endl;
    for (int i = 0; i < m.getRows(); i++) {
        for (int j = 0; j < m.getColumns(); j++)
            cout << m.getValue(i, j) << "\t";
        cout << endl;
    }

};