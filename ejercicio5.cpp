#include <iostream>
#include <vector>

using namespace std;

int main() {
    int n;
    cout << "Ingrese el tamano de la matriz cuadrada (n): ";
    cin >> n;// pide al usuario un numero para crear la matriz

    if (n <= 0) {
        cout << "El tamano de la matriz debe ser mayor a 0." << endl;
        return 0;
    }

    vector<vector<double>> matriz(n, vector<double>(n));// crea matriz nxn para almecenar hasta decimales

    cout << "\nIngrese los elementos de la matriz (" << n << " x " << n << "):\n";
    
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {// recorre la matriz i las filas y j las columnas, para luego llenarlas
            cout << "Elemento [" << i << "][" << j << "]: ";// imprime en que posicion de la matriz donde uno esta
            cin >> matriz[i][j];// recibe el numero que usuario ponga
        }
    }
    
    bool esD = true;
    bool esTSup = true;// crea las variables para clasificar la matriz
    bool esTInf = true;

    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            if (i != j && matriz[i][j] != 0) {// revisa si la matriz es diagonal o no, en este caso revisando si i y j son iguales
                esD = false;
            }
            if (i > j && matriz[i][j] != 0) {// si no es igual a 0 la parte inferior de la diagonal, el programa descarta esta opcion
                esTSup = false;
            }
            if (i < j && matriz[i][j] != 0) {// viceversa, si no son 0 en la parte superior entonces se descarta
                esTInf = false;
            }
        }
    }
    
    cout << "\nEn conclusion... \n";// imprime si de los condicicionales anteriores hubo algun true
    
    if (esD) {
        cout << "La matriz es de tipo diagonal " << endl;
    } else {
        if (esTSup) {
            cout << " La matriz es triangular superior " << endl;
        }
        if (esTInf) {
            cout << " La matriz es triangular inferior " << endl;
        }
        if (!esTSup && !esTInf) {
            cout << " La matriz no es ni triangular superior ni inferior" << endl;
        }
    }

    return 0;
}