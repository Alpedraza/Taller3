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
    }// Aceptan numeros como 2 y 3 y se descartan numeros como 1 y sus menores y los  multiplos de 2 y 3
    return true;
}

int main() {
    
    std::cout << std::fixed << std::setprecision(4); // Coloca decimales con 4 numeros despues de la coma

    int n;
    std::cout << "Ingrese un valor de n para la matriz de n x n: ";
    if (!(std::cin >> n) || n <= 0) {
        std::cerr << "Por favor, ingrese un entero positivo válido." << std::endl;
        return 1;//Se condiciona para que la persona solo ingrese el número para la matriz
    }

    std::vector<std::vector<int>> matriz(n, std::vector<int>(n));
// Estas lineas sirven para crear el vector con n filas y la fila con n enteros a partir de la posicion 0
    std::random_device rd;
    std::mt19937 gen(rd());// Sirve para obtener numeros reales, pero cada que inicie el programa los valores random cambian
    std::uniform_int_distribution<int> distrib(0, 50);

    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) { // Recorre cada fila y columna de la matriz y le mete un numero random, siempre de o a n-1
            matriz[i][j] = distrib(gen);
        }
    }

    std::cout << "\n Matriz generada (" << n << " x " << n << ")   \n";
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {// Imprime el titulo de la matriz, la matriz con los numeros random
            std::cout << std::setw(4) << matriz[i][j] << " ";// el setw es para que se vea aesthetic la matriz
        }
        std::cout << "\n";
    }

    int sprincipal = 0;
    int ssecundaria = 0; // Contadores para sumar los valores de las diagonales
    std::vector<int> dgprincipal; // Aqui se almacenan esos valores por separado
    std::vector<int> dgsecundaria;

    for (int i = 0; i < n; ++i) { // Con i recorre la matriz por fila (f) y columna (c)
        dgprincipal.push_back(matriz[i][i]);
        sprincipal += matriz[i][i]; // Revisa los valores de f y c que sean iguales para guardar la diagonal y suma el contador

        dgsecundaria.push_back(matriz[i][n - 1 - i]);// Aqui va de derecha superior a la izquierda inferior
        ssecundaria += matriz[i][n - 1 - i];// y se guardan en el vector y suma al contador
    }

    std::cout << "Suma de la diagonal principal: " << sprincipal << "\n";
    std::cout << "Suma de la diagonal secundaria: " << ssecundaria << "\n"; // Imprime las diagonales

    std::vector<int> primeraF(n);
    std::vector<int> ultimaCol(n);
    std::vector<double> vectorrsultC(n); // Vectores que guardan primera fila ultima columna y la suma de cuadrados

    for (int j = 0; j < n; ++j) {
        primeraF[j] = matriz[0][j];
    }                                   // Estos dos ciclos, recorre horizontalmente la 1ra fila y verticalmente la ultima columna
    for (int i = 0; i < n; ++i) {
        ultimaCol[i] = matriz[i][n - 1];
    }

    for (int i = 0; i < n; ++i) {
        double cuadF = std::pow(primeraF[i], 2);
        double cuadC = std::pow(ultimaCol[i], 2); // Recorre y eleva a la 2 los valores luego los suma y los imprime en el siguiente ciclo for
        vectorrsultC[i] = cuadF + cuadC;
    }

    std::cout << "\n Vector resultante \n[ ";
    for (double val : vectorrsultC) {
        std::cout << val << " ";
    }
    std::cout << "]\n";

    int cdeprimos = 0;
    for (int i = 0; i < n; ++i) {  
        for (int j = 0; j < n; ++j) {
            if (nprimo(matriz[i][j])) {// Aqui cuenta los primos y los imprime por la funcion definida más arriba
                cdeprimos++;
            }
        }
    }
    
    std::cout << "Numero de elementos primos en la matriz: " << cdeprimos << "\n";

    int pares = 0, impares = 0, divtres = 0;
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {  // Revisa si son pares impares o divisibles entre 3
            int val = matriz[i][j];
            if (val % 2 == 0) pares++;
            else impares++;

            if (val % 3 == 0) divtres++;
        }
    }

    std::cout << "Elementos pares: " << pares << "\n";
    std::cout << "Elementos impares: " << impares << "\n"; // En este se muestran cuantos elementos son de cada tipo
    std::cout << "Elementos divisibles por 3: " << divtres << "\n";

    std::vector<double> sumacolmn(n, 0.0);
    for (int j = 0; j < n; ++j) {
        for (int i = 0; i < n; ++i) {// Aqui se suman las columnas
            sumacolmn[j] += matriz[i][j];
        }
    }

    const double PI = std::acos(-1.0);
    
    std::cout << "\n Tabla suma de columna (x) vs seno en radianes (y) \n"; // Creamos la la funcion de pi y el encabezado de la tabla
    std::cout << std::setw(15) << "suma columna (x)" << std::setw(20) << "seno(Rad) (y)" << "\n";

    for (int j = 0; j < n; ++j) {
        double valX = sumacolmn[j]; 
        double radianes = valX * (PI / 180.0); // toma la suma de la columna y la convierte en radianes y luego le saca el seno 
        double senoVal = std::sin(radianes);

        std::cout << std::setw(15) << valX << std::setw(20) << senoVal << "\n";// Imprime ambos valores de suma y el seno
    }

    std::vector<int> vector1;
    double sumaTotal = 0;
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            vector1.push_back(matriz[i][j]);// Extraen cada valor y lo introducen en el vector mientras se recorre la matriz
            sumaTotal += matriz[i][j]; // el mismo tiempo suma al contador
        }
    }

    double promedio = sumaTotal / (n * n);
    std::cout << "\n Vector con una dimension\n";
    std::cout << "Promedio de todos los elementos: " << promedio << "\n";  // Imprime el promedio apartir de la funcion

    std::cout << "Vector resultante: [ ";  // evita una indeterminacion
    if (promedio == 0) {
        std::cout << "Advertencia: El promedio es 0, no se puede dividir.\n";
    } else {
        for (int val : vector1) {
            double normalizado = static_cast<double>(val) / promedio;
            std::cout << normalizado << " "; // divide cada elemento entre el promedio general
        }
    }
    std::cout << "]\n";

    return 0;
}

