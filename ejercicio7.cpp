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
        cin >> m >> p1;// guarda las columnas y filas de la primera matriz

        cout << "Ingrese las dimensiones de la matriz B (filas p y columnas q): ";
        cin >> p2 >> q;
        if (p1 == p2) {
            break;// se condiciona que el tamaño para la matriz b.
            } else {
            cout << "El numero de columnas de A (" << p1 
                 << ") debe ser igual al numero de filas de B (" << p2 
                 << "). Por favor, ingrese las dimensiones nuevamente.\n";
        }
    }
    int p = p1;

    vector<vector<int>> A(m, vector<int>(p));// crea cada matriz segun el tamaño definido por el usuario
    vector<vector<int>> B(p, vector<int>(q));
    vector<vector<int>> C(m, vector<int>(q, 0));// esta la incializa con 0

    cout << "\nMatriz A (" << m << "x" << p << ") " << endl;
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < p; j++) {// recorre cada posicion de la matriz, imprimiendo en que ubicacion esta llenando
            cout << "A[" << i << "][" << j << "]: ";
            cin >> A[i][j];// el usuario llena la posicion indicada
        }
    }

    cout << "\nMatriz B (" << p << "x" << q << ") " << endl;// lo mismo ocurre para esta matriz
    for (int i = 0; i < p; i++) {
        for (int j = 0; j < q; j++) {
            cout << "B[" << i << "][" << j << "]: ";
            cin >> B[i][j];
        }
    }
    for (int i = 0; i < m; i++) {// recorre la fila en A
        for (int j = 0; j < q; j++) {// recorre la columna en B
            for (int k = 0; k < p; k++) {// recorre los p elementos para hace producto punto
                C[i][j] += A[i][k] * B[k][j];// recorre cada ubicacion, multiplica y suma, y lo guarda en C hasta completar la operacion
            }
        }
    }
    
    cout << "\nMatriz A (" << m << "x" << p << ")" << endl;
    
    for (int i = 0; i < m; i++) {
        cout << "[ ";
        for (int j = 0; j < p; j++) {// imprime la matriz A en la pantalla, fila por fila
            cout << setw(6) << A[i][j] << " ";
        }
        cout << "]" << endl;
    }

    cout << "\nMatriz B (" << p << "x" << q << ")" << endl; // muestra la matriz que se esta imprimiendo y su tamaño
    
    for (int i = 0; i < p; i++) {
        cout << "[ ";
        for (int j = 0; j < q; j++) {// imprime la matriz B en la pantalla, fila por fila
            cout << setw(6) << B[i][j] << " ";
        }
        cout << "]" << endl;
    }

    cout << "\nMatriz producto C = A * B (" << m << "x" << q << ")" << endl; // muestra el titulo
    
    for (int i = 0; i < m; i++) {
        cout << "[ ";
        for (int j = 0; j < q; j++) {
            cout << setw(6) << C[i][j] << " ";// recorre la matriz C, calculada
        }
        cout << "]" << endl;
    }
    
   
    for (int i = 0; i < m; i++) {// muestra la suma de la cada fila en la matriz c
        int sumaFilaC = sumarFila(C[i]);
        cout << "Suma de los elementos de la fila " << i << ": " << sumaFilaC << endl;
    }
   
    return 0;
}