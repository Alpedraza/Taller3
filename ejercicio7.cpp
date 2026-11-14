#include <iostream>
#include <vector>
#include <iomanip>

using namespace std;
int sumarFila(const vector<int>& fila) {
    int suma = 0;
    for (int valor : fila) {
        suma += valor;
    }
    return suma;
}

int main() {
    int m, p1, p2, q;
    while (true) {
        cout << "\nIngrese las dimensiones de la matriz A (filas m y columnas p): ";
        cin >> m >> p1;

        cout << "Ingrese las dimensiones de la matriz B (filas p y columnas q): ";
        cin >> p2 >> q;
        if (p1 == p2) {
            break;
            } else {
            cout << "El numero de columnas de A (" << p1 
                 << ") debe ser igual al numero de filas de B (" << p2 
                 << "). Por favor, ingrese las dimensiones nuevamente.\n";
        }
    }
    int p = p1;

    vector<vector<int>> A(m, vector<int>(p));
    vector<vector<int>> B(p, vector<int>(q));
    vector<vector<int>> C(m, vector<int>(q, 0));

    cout << "\nMatriz A (" << m << "x" << p << ") " << endl;
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < p; j++) {
            cout << "A[" << i << "][" << j << "]: ";
            cin >> A[i][j];
        }
    }

    cout << "\nMatriz B (" << p << "x" << q << ") " << endl;
    for (int i = 0; i < p; i++) {
        for (int j = 0; j < q; j++) {
            cout << "B[" << i << "][" << j << "]: ";
            cin >> B[i][j];
        }
    }
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < q; j++) {
            for (int k = 0; k < p; k++) {
                C[i][j] += A[i][k] * B[k][j];
            }
        }
    }
    
    cout << "\nMatriz A (" << m << "x" << p << ")" << endl;
    
    for (int i = 0; i < m; i++) {
        cout << "[ ";
        for (int j = 0; j < p; j++) {
            cout << setw(6) << A[i][j] << " ";
        }
        cout << "]" << endl;
    }

    cout << "\nMatriz B (" << p << "x" << q << ")" << endl;
    
    for (int i = 0; i < p; i++) {
        cout << "[ ";
        for (int j = 0; j < q; j++) {
            cout << setw(6) << B[i][j] << " ";
        }
        cout << "]" << endl;
    }

    cout << "\nMatriz producto C = A * B (" << m << "x" << q << ")" << endl;
    
    for (int i = 0; i < m; i++) {
        cout << "[ ";
        for (int j = 0; j < q; j++) {
            cout << setw(6) << C[i][j] << " ";
        }
        cout << "]" << endl;
    }
    
    cout << "\nSuma de elementos en C" << endl;
   
    for (int i = 0; i < m; i++) {
        int sumaFilaC = sumarFila(C[i]);
        cout << "Suma de los elementos de la fila " << i << ": " << sumaFilaC << endl;
    }
   
    return 0;
}