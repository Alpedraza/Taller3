#include <iostream>
#include <vector>
#include <iomanip>

using namespace std;

int main() {
    int n, m;

    cout << "Ingrese el numero de estudiantes (n): ";
    cin >> n;
    cout << "Ingrese el numero de asignaturas (m): ";
    cin >> m;

    vector<vector<double>> calific(n, vector<double>(m));

    
    for (int i = 0; i < n; ++i) {
        cout << "Estudiante " << i + 1 << ":\n";// muestra el numero de un estudiante
        for (int j = 0; j < m; ++j) {
            do {
                cout << "  Asignatura " << j + 1 << ": ";// y le permite ingresar un numero  para guardarlo
                cin >> calific[i][j];
                if (calific[i][j] < 0.0 || calific[i][j] > 5.0) {
                    cout << "  Error: La calificacion debe estar entre 0.0 y 5.0. Intente de nuevo.\n";
                }// todo esto lo ejecuta hasta llegar a n-1 en estudiantes y m-1 en asignaturas que ve cada estudiante
            } while (calific[i][j] < 0.0 || calific[i][j] > 5.0);
        }
    }
    vector<double> promest(n, 0.0);
    for (int i = 0; i < n; ++i) {
        double suma = 0;// recorre la fila de la matriz y va sumando el valor de cada posicion entre su cantidad
        for (int j = 0; j < m; ++j) {// en este caso son las calificaciones para sacar su promedio
            suma += calific[i][j];
        }
        promest[i] = suma / m;
    }

    vector<double> promAsig(m, 0.0);

    for (int j = 0; j < m; ++j) {
        double suma = 0;
        for (int i = 0; i < n; ++i) {// suma toda las notas de la asignatura que cada estudiante obtuvo y lo promedia entre la cantidad de estudiantes
            suma += calific[i][j];
        }
        promAsig[j] = suma / n;
    }
    int idestudM = 0;
    double maxpromest = promest[0];
    for (int i = 1; i < n; ++i) {
        if (promest[i] > maxpromest) {
            maxpromest = promest[i]; // Busca y compara el promedio max obtenido por un estudiante anterior con el q se va arevisar actualmente
            idestudM = i;// si lo encuentra lo actualiza y marca 
        }
    }

    int idasigMin = 0;
    double minPromA = promAsig[0];
    for (int j = 1; j < m; ++j) {
        if (promAsig[j] < minPromA) {
            minPromA = promAsig[j];// revisa el menor promedio, tomando como referencia el inicial y si lo encuentra actualiza los datos 
            idasigMin = j;
        }
    }
    cout << fixed << setprecision(2);
    cout << "\nEntonces...\n";
    
    cout << "\nPromedios de cada estudiante:\n";
    for (int i = 0; i < n; ++i) {// imprime el promedio de cada estudiante
        cout << "Estudiante " << i + 1 << ": " << promest[i] << "\n";
    }

    cout << "\nPromedios de cada asignatura:\n";
    for (int j = 0; j < m; ++j) {// imprime la media por asignatura
        cout << "Asignatura " << j + 1 << ": " << promAsig[j] << "\n";
    }

    cout << "\nDestacados \n";
    cout << "Estudiante con el promedio mas alto: estudiante " << idestudM + 1 
         << " (Promedio: " << maxpromest << ")\n";// muestra quien saco el max y el min, mas el numero de orden
    cout << "Asignatura con el promedio mas bajo: asignatura " << idasigMin + 1 
         << " (Promedio: " << minPromA << ")\n";

    return 0;
}

