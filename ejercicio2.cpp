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
    }// Condiciona el n que debe introducir el usuario

    vector<int> numeros(n);

    random_device rd; // Es como un punto de inicio impredecible
    mt19937 gen(rd()); // usa el punto para crear una secuencia random de numeros
    uniform_int_distribution<> dis(0, 10); // y aqui condiciona que esa secuencia debe oscilar en un rango

    for (int i = 0; i < n; ++i) {
        numeros[i] = dis(gen);// llena el vector con numeros random tomando como referencia el n
    }

    cout << "\nVector original de numeros generados: [ "; // muestra la secuencia
    for (int i = 0; i < n; ++i) {
        cout << numeros[i] << (i < n - 1 ? ", " : " ");
    }
    cout << "]" << endl;
    double suma = 0.0;
    for (int num : numeros) {// se promedian los valores del vector
        suma += num;
    }
    double media = suma / n;

    vector<int> mayorqm;
    for (int num : numeros) { // revisa si los valores del vector son mayores a la media
        if (num > media) {
            mayorqm.push_back(num);// si lo son entonces los guarde en otro vector
        }
    }

    cout << fixed << setprecision(2);// cantidad de decimales despues de la coma q se imprimen
    cout << "Media de los numeros: " << media << endl;
    cout << "Elementos mayores que la media: ";
    if (mayorqm.empty()) {// condiciona que si durante la revision anterior no hubo ninguno mayor imprima el mensaje
        cout << "Ninguno de los elementos supera la media." << endl;
    } else {
        cout << "[ ";
        for (size_t i = 0; i < mayorqm.size(); ++i) {// revisa si hay elementos y lo imprime
            cout << mayorqm[i] << (i < mayorqm.size() - 1 ? ", " : " ");
        }
        cout << "]" << endl;
    }

    return 0;// NOTA: en el ejercicio 3 es modificar la parte inferior
}