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
        cout << "Estudiante " << i + 1 << ":\n";
        for (int j = 0; j < m; ++j) {
            do {
                cout << "  Asignatura " << j + 1 << ": ";
                cin >> calific[i][j];
                if (calific[i][j] < 0.0 || calific[i][j] > 5.0) {
                    cout << "  Error: La calificacion debe estar entre 0.0 y 5.0. Intente de nuevo.\n";
                }
            } while (calific[i][j] < 0.0 || calific[i][j] > 5.0);
        }
    }
    vector<double> promest(n, 0.0);
    for (int i = 0; i < n; ++i) {
        double suma = 0;
        for (int j = 0; j < m; ++j) {
            suma += calific[i][j];
        }
        promest[i] = suma / m;
    }

    vector<double> promAsig(m, 0.0);

    for (int j = 0; j < m; ++j) {
        double suma = 0;
        for (int i = 0; i < n; ++i) {
            suma += calific[i][j];
        }
        promAsig[j] = suma / n;
    }
    int idestudM = 0;
    double maxpromest = promest[0];
    for (int i = 1; i < n; ++i) {
        if (promest[i] > maxpromest) {
            maxpromest = promest[i];
            idestudM = i;
        }
    }

    int idasigMin = 0;
    double minPromA = promAsig[0];
    for (int j = 1; j < m; ++j) {
        if (promAsig[j] < minPromA) {
            minPromA = promAsig[j];
            idasigMin = j;
        }
    }
    cout << fixed << setprecision(2);
    cout << "\nEntonces...\n";
    
    cout << "\nPromedios de cada estudiante:\n";
    for (int i = 0; i < n; ++i) {
        cout << "Estudiante " << i + 1 << ": " << promest[i] << "\n";
    }

    cout << "\nPromedios de cada asignatura:\n";
    for (int j = 0; j < m; ++j) {
        cout << "Asignatura " << j + 1 << ": " << promAsig[j] << "\n";
    }

    cout << "\nDestacados \n";
    cout << "Estudiante con el promedio mas alto: estudiante " << idestudM + 1 
         << " (Promedio: " << maxpromest << ")\n";
    cout << "Asignatura con el promedio mas bajo: asignatura " << idasigMin + 1 
         << " (Promedio: " << minPromA << ")\n";

    return 0;
}

