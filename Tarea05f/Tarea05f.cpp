#include <iostream>
#include <cstdlib>
#include <ctime>
#include "Matrix.h"
using namespace std;

void mostrarMenu() {
    cout << "\n MENU " << endl;
    cout << "  1.  getValue" << endl;
    cout << "  2.  setValue" << endl;
    cout << "  3.  getRows" << endl;
    cout << "  4.  getColumns" << endl;
    cout << "  5.  setAll" << endl;
    cout << "  6.  transpose" << endl;
    cout << "  7.  addRow" << endl;
    cout << "  8.  addColumn" << endl;
    cout << "  9.  removeRow" << endl;
    cout << "  10. removeColumn" << endl;
    cout << "  11. Cargar aleatorios" << endl;
    cout << "  0.  Salir" << endl;
    cout << "Opcion: ";
}

int main() {
    srand((unsigned)time(0));

    int filas, columnas;
    cout << "Ingrese cantidad de filas: ";
    cin >> filas;
    cout << "Ingrese cantidad de columnas: ";
    cin >> columnas;

    Matrix<int>* m = nullptr;
    try {
        m = new Matrix<int>(filas, columnas);
        m->setAll(0);
    }
    catch (runtime_error&) {
        cout << "Error: las dimensiones deben ser mayores a cero" << endl;
        return 1;
    }

    int opcion;
    do {
        cout << "\nMatriz actual:" << endl;
        m->print();
        mostrarMenu();
        cin >> opcion;

        try {
            if (opcion == 1) {
                int r, c;
                cout << "Fila: "; cin >> r;
                cout << "Columna: "; cin >> c;
                cout << "Valor en [" << r << "][" << c << "]: " << m->getValue(r, c) << endl;
            }
            else if (opcion == 2) {
                int r, c, v;
                cout << "Fila: "; cin >> r;
                cout << "Columna: "; cin >> c;
                cout << "Valor: "; cin >> v;
                m->setValue(r, c, v);
                cout << "Valor asignado." << endl;
            }
            else if (opcion == 3) {
                cout << "Filas: " << m->getRows() << endl;
            }
            else if (opcion == 4) {
                cout << "Columnas: " << m->getColumns() << endl;
            }
            else if (opcion == 5) {
                int v;
                cout << "Valor para setAll: "; cin >> v;
                m->setAll(v);
                cout << "Todos los elementos asignados a " << v << endl;
            }
            else if (opcion == 6) {
                m->transpose();
                cout << "Matriz transpuesta." << endl;
            }
            else if (opcion == 7) {
                int v;
                cout << "Valor para la nueva fila: "; cin >> v;
                m->addRow(v);
                cout << "Fila agregada." << endl;
            }
            else if (opcion == 8) {
                int v;
                cout << "Valor para la nueva columna: "; cin >> v;
                m->addColumn(v);
                cout << "Columna agregada." << endl;
            }
            else if (opcion == 9) {
                int r;
                cout << "Fila a eliminar: "; cin >> r;
                m->removeRow(r);
                cout << "Fila " << r << " eliminada." << endl;
            }
            else if (opcion == 10) {
                int c;
                cout << "Columna a eliminar: "; cin >> c;
                m->removeColumn(c);
                cout << "Columna " << c << " eliminada." << endl;
            }
            else if (opcion == 11) {
                for (int i = 0; i < m->getRows(); i++)
                    for (int j = 0; j < m->getColumns(); j++)
                        m->setValue(i, j, rand() % 100);
                cout << "Matriz cargada aleatoriamente." << endl;
            }
            else if (opcion == 0) {
                cout << "Saliendo..." << endl;
            }
            else {
                cout << "Opcion invalida." << endl;
            }
        }
        catch (runtime_error&) {
            cout << "Error: esa operacion no se puede realizar, verifique los indices ingresados" << endl;
        }

    } while (opcion != 0);

    delete m;
    return 0;
}