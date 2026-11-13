#include <iostream>
#include <vector>
#include <random>
#include <cmath>
#include <iomanip>

bool nprimo(int num) { // esta funcion para mirar si el num que puso el usuario sea primo
    if (num <= 1) return false;  
    if (num <= 3) return true; 
    if (num % 2 == 0 || num % 3 == 0) return false;
    for (int i = 5; i * i <= num; i += 6) {
        if (num % i == 0 || num % (i + 2) == 0) return false;
    }// Aceptan numeros como 2 y 3 y se descartan numeros como 1 menores a uno y los  multiplos de 2 y 3
    return true;
}
