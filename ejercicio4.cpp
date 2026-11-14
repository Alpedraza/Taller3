#include <iostream>
#include <vector>
#include <cstdlib>
#include <ctime>

int calcfactor(int num) {
    if (num < 0) return -1;
    int factorial = 1;// condiciona el factorial para solo positivos
    for (int i = 1; i <= num; ++i) {
        factorial *= i;// multiplica en cada vuelta el incremento en i hasta llegar a n
    }
    return factorial;
}
int main() {
    int n;
    std::cout << "Ingrese un numero entero positivo n: ";
    std::cin >> n;

    if (n <= 0) {// condiciona al usuario
        std::cout << "El numero debe ser mayor que 0." << std::endl;
        return 1;
    }
    std::srand(static_cast<unsigned int>(std::time(nullptr))); // crea un punto de inicio usando la hora del sistema
    std::vector<int> vectorV(n);

    std::cout << "\nValores generados en el vector " << std::endl;
    for (int i = 0; i < n; ++i) {// recorre de 0 a n-1 posiciones insertando un numero random de 0 a 10
        vectorV[i] = std::rand() % 11; 
        std::cout << "Indice " << i << ": " << vectorV[i] << std::endl;// y imprime esa generacion de valores
    }
    std::cout << "\nFactorial de cada elemento " << std::endl;
    for (int i = 0; i < n; ++i) {
        int valor = vectorV[i];// extrare cada valor almacenado en el vector y le calcula su factorial y lo imprime
        int resultado = calcfactor(valor);
        std::cout << "El factorial de " << valor << "! es: " << resultado << std::endl;
    }

    return 0;
}
