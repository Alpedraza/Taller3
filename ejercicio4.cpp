#include <iostream>
#include <vector>
#include <cstdlib>
#include <ctime>

int calcfactor(int num) {
    if (num < 0) return -1;
    int factorial = 1;
    for (int i = 1; i <= num; ++i) {
        factorial *= i;
    }
    return factorial;
}
int main() {
    int n;
    std::cout << "Ingrese un numero entero positivo n: ";
    std::cin >> n;

    if (n <= 0) {
        std::cout << "El numero debe ser mayor que 0." << std::endl;
        return 1;
    }
    std::srand(static_cast<unsigned int>(std::time(nullptr)));
    std::vector<int> vectorV(n);

    std::cout << "\nValores generados en el vector " << std::endl;
    for (int i = 0; i < n; ++i) {
        vectorV[i] = std::rand() % 11; 
        std::cout << "Indice " << i << ": " << vectorV[i] << std::endl;
    }
    std::cout << "\nFactorial de cada elemento " << std::endl;
    for (int i = 0; i < n; ++i) {
        int valor = vectorV[i];
        int resultado = calcfactor(valor);
        std::cout << "El factorial de " << valor << "! es: " << resultado << std::endl;
    }

    return 0;
}
