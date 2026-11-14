#include <iostream>
#include <vector>
#include <iomanip>

using namespace std;

int main() {
   
    int m, n;
    cout << "Ingrese el numero de filas (m): ";
    cin >> m;
    cout << "Ingrese el numero de columnas (n): ";
    cin >> n;

    if (m <= 0 || n <= 0) {
        cout << "Las dimensiones deben ser mayores a cero.\n";
        return 1;// Establece medidas para una matriz no cuadrada
    }

    vector<vector<int>> matriz(m, vector<int>(n));
    cout << "\nIngrese los elementos de la matriz (" << m << "x" << n << "):\n";
    for (int i = 0; i < m; ++i) {
        for (int j = 0; j < n; ++j) {
            cout << "Elemento [" << i << "][" << j << "]: ";// permite al usuario ingresar un valor a cada posicion de la matriz
            cin >> matriz[i][j];
        }
    }
    int max_val = matriz[0][0], min_val = matriz[0][0];// guardan los numeros sean max o min desde la esquina superior izquierda
    int max_r = 0, max_c = 0, min_r = 0, min_c = 0;// guardan las coordenadas de ese valor

    for (int i = 0; i < m; ++i) {
        for (int j = 0; j < n; ++j) {// recorre fila y columna
            if (matriz[i][j] > max_val) {// compara el numero max que ha encontrado con el siguiente 
                max_val = matriz[i][j];// si hay lo actualiza con todo y coordenadas
                max_r = i;
                max_c = j;
            }
            if (matriz[i][j] < min_val) {// lo mismo para los minimos
                min_val = matriz[i][j];
                min_r = i;
                min_c = j;
            }
        }
    }// aqui imprime lo que se guardo anteriormente
    cout << "Elemento maximo: " << max_val << " (Fila: " << max_r << ", Columna: " << max_c << ")\n";
    cout << "Elemento minimo: " << min_val << " (Fila: " << min_r << ", Columna: " << min_c << ")\n";
    
    if (max_r != min_r) {
        swap(matriz[max_r], matriz[min_r]);// revisa si estan en filas distintas
    } else {// sino la deja igual
        cout << "\nEl elemento maximo y minimo se encuentran en la misma fila.\n";
    }

    cout << "\nMatriz con filas intercambiadas \n";
    for (int i = 0; i < m; ++i) {// aqui imprime con las filas modificadas por swap
        for (int j = 0; j < n; ++j) {
            cout << setw(6) << matriz[i][j];// alineacion de los numeros en columnas
        }
        cout << "\n";
    }

    vector<vector<int>> trans(n, vector<int>(m));
    for (int i = 0; i < m; ++i) {
        for (int j = 0; j < n; ++j) {
            trans[j][i] = matriz[i][j];// declara la matriz con dimension invertida
        }
    }
// coloca las filas como columnas y columnas como filas
    cout << "\nMatriz Transpuesta\n";
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            cout << setw(6) << trans[i][j];// matiene alineada la columna
        }
        cout << "\n";
    }

    return 0;
}