#include <iostream>
#include <vector>

using namespace std;

int main() {
    int n;
    cout << "Ingrese el tamano de la matriz cuadrada (n): ";
    cin >> n;

    if (n <= 0) {
        cout << "El tamano de la matriz debe ser mayor a 0." << endl;
        return 0;
    }

    vector<vector<double>> matriz(n, vector<double>(n));

    cout << "\nIngrese los elementos de la matriz (" << n << " x " << n << "):\n";
    
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            cout << "Elemento [" << i << "][" << j << "]: ";
            cin >> matriz[i][j];
        }
    }
    
    bool esD = true;
    bool esTSup = true;
    bool esTInf = true;

    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            if (i != j && matriz[i][j] != 0) {
                esD = false;
            }
            if (i > j && matriz[i][j] != 0) {
                esTSup = false;
            }
            if (i < j && matriz[i][j] != 0) {
                esTInf = false;
            }
        }
    }
    
    cout << "\nEn conclusion... \n";
    
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