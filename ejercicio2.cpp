#include <iostream>
#include <vector>
#include <random>
#include <iomanip>

using namespace std;

int main() {
    int n;
    cout << "Ingrese un numero entero positivo: ";
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
    }

    cout << fixed << setprecision(2);
    cout << "Media de los numeros: " << media << endl;
    cout << "Elementos mayores que la media: ";
    if (mayorqm.empty()) {
        cout << "Ninguno de los elementos supera la media." << endl;
    } else {
        cout << "[ ";
        for (size_t i = 0; i < mayorqm.size(); ++i) {
            cout << mayorqm[i] << (i < mayorqm.size() - 1 ? ", " : " ");
        }
        cout << "]" << endl;
    }

    return 0;
}