#include <iostream>
#include <vector>
#include <random>
#include <iomanip>
#include <algorithm>

using namespace std;

int main() {
    int n;
    cout << "Ingrese un numero entero positivo (n): ";
    cin >> n;

    if (n <= 0) {
        cout << "Por favor, ingrese un numero mayor que 0." << endl;
        return 1;
    }
    vector<int> numeros(n);

    random_device rd;
    mt19937 gen(rd());
    uniform_int_distribution<> dis(0, 10);

    for (int i = 0; i < n; ++i) {
        numeros[i] = dis(gen);
    }

    cout << "\nVector original de numeros generados: [ ";
    for (int i = 0; i < n; ++i) {
        cout << numeros[i] << (i < n - 1 ? ", " : " ");
    }
    cout << "]" << endl;

    double suma = 0.0;
    for (int num : numeros) {
        suma += num;
    }
    double media = suma / n;

    vector<int> mayorqm;
    for (int num : numeros) {
        if (num > media) {
            mayorqm.push_back(num);
        }
    }// La explicacion de la parte de arriba se omite dado este ejercicio se deriva del anterior  :V

    sort(mayorqm.begin(), mayorqm.end());// ordena los elementos del vector automaticamente

    cout << fixed << setprecision(2); // impresion de dos decimales despues de la coma
    cout << "Media de los numeros: " << media << endl; // imprime la media
    cout << "Elementos mayores que la media (orden de menor a mayor): ";
    if (mayorqm.empty()) {
        cout << "Ninguno de los elementos supera la media." << endl;
    } else {// En caso de que el vector este vacio 
        cout << "[ ";
        for (size_t i = 0; i < mayorqm.size(); ++i) {
            cout << mayorqm[i] << (i < mayorqm.size() - 1 ? ", " : " ");
        }// si el vector esta lleno, lo recorre e imprime y tambien las comas.
        cout << "]" << endl;
    }

    return 0;
    }