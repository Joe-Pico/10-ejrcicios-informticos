// Codigo 21: Funcion para Suma
#include <iostream>
using namespace std;

int suma(int a, int b) {
    return a + b;
}

int main() {
    int num1, num2;
    
    cout << "Ingrese dos numeros: ";
    cin >> num1 >> num2;
    
    int resultado = suma(num1, num2);
    cout << "La suma es: " << resultado << endl;
    
    return 0;
}

// Codigo 22: Funcion para Area del Circulo
#include <iostream>
#include <cmath>
using namespace std;

const double PI = 3.14159265359;

double areaCirculo(double radio) {
    return PI * radio * radio;
}

int main() {
    double radio;
    
    cout << "Ingrese el radio del circulo: ";
    cin >> radio;
    
    double area = areaCirculo(radio);
    cout << "El area del circulo es: " << area << endl;
    
    return 0;
}

// Codigo 23: Funcion Potencia
#include <iostream>
using namespace std;

double potencia(double base, int exponente) {
    double resultado = 1;
    
    for (int i = 0; i < abs(exponente); i++) {
        resultado *= base;
    }
    
    if (exponente < 0) {
        resultado = 1.0 / resultado;
    }
    
    return resultado;
}

int main() {
    double base;
    int exponente;
    
    cout << "Ingrese la base: ";
    cin >> base;
    cout << "Ingrese el exponente: ";
    cin >> exponente;
    
    double resultado = potencia(base, exponente);
    cout << base << " elevado a " << exponente << " es: " << resultado << endl;
    
    return 0;
}

// Codigo 24: Funcion Maximo de Tres
#include <iostream>
using namespace std;

int maximo(int a, int b, int c) {
    int max = a;
    if (b > max) max = b;
    if (c > max) max = c;
    return max;
}

int main() {
    int num1, num2, num3;
    
    cout << "Ingrese tres numeros: ";
    cin >> num1 >> num2 >> num3;
    
    int max = maximo(num1, num2, num3);
    cout << "El maximo es: " << max << endl;
    
    return 0;
}

// Codigo 25: Funcion Palindromo
#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

bool esPalindromo(string palabra) {
    string reversa = palabra;
    reverse(reversa.begin(), reversa.end());
    return palabra == reversa;
}

int main() {
    string palabra;
    
    cout << "Ingrese una palabra: ";
    cin >> palabra;
    
    if (esPalindromo(palabra)) {
        cout << palabra << " es un palindromo" << endl;
    } else {
        cout << palabra << " no es un palindromo" << endl;
    }
    
    return 0;
}

// Codigo 26: Factorial Recursivo
#include <iostream>
using namespace std;

long long factorialRecursivo(int n) {
    if (n <= 1) {
        return 1;
    }
    return n * factorialRecursivo(n - 1);
}

int main() {
    int numero;
    
    cout << "Ingrese un numero: ";
    cin >> numero;
    
    if (numero < 0) {
        cout << "El factorial no esta definido para numeros negativos" << endl;
    } else {
        long long resultado = factorialRecursivo(numero);
        cout << "El factorial de " << numero << " es: " << resultado << endl;
    }
    
    return 0;
}

// Codigo 27: Fibonacci Recursivo
#include <iostream>
using namespace std;

int fibonacciRecursivo(int n) {
    if (n <= 1) {
        return n;
    }
    return fibonacciRecursivo(n - 1) + fibonacciRecursivo(n - 2);
}

int main() {
    int n;
    
    cout << "Ingrese el numero de terminos: ";
    cin >> n;
    
    cout << "Secuencia de Fibonacci:" << endl;
    for (int i = 0; i < n; i++) {
        cout << fibonacciRecursivo(i) << " ";
    }
    cout << endl;
    
    return 0;
}

// Codigo 28: Funciones de Conversion
#include <iostream>
using namespace std;

double metrosAPies(double metros) {
    return metros * 3.28084;
}

double piesAMetros(double pies) {
    return pies / 3.28084;
}

double kgALibras(double kg) {
    return kg * 2.20462;
}

double librasAKg(double libras) {
    return libras / 2.20462;
}

int main() {
    int opcion;
    double valor, resultado;
    
    cout << "Seleccione conversion:" << endl;
    cout << "1. Metros a Pies" << endl;
    cout << "2. Pies a Metros" << endl;
    cout << "3. Kg a Libras" << endl;
    cout << "4. Libras a Kg" << endl;
    cout << "Opcion: ";
    cin >> opcion;
    
    cout << "Ingrese el valor: ";
    cin >> valor;
    
    switch (opcion) {
        case 1:
            resultado = metrosAPies(valor);
            cout << valor << " metros = " << resultado << " pies" << endl;
            break;
        case 2:
            resultado = piesAMetros(valor);
            cout << valor << " pies = " << resultado << " metros" << endl;
            break;
        case 3:
            resultado = kgALibras(valor);
            cout << valor << " kg = " << resultado << " libras" << endl;
            break;
        case 4:
            resultado = librasAKg(valor);
            cout << valor << " libras = " << resultado << " kg" << endl;
            break;
        default:
            cout << "Opcion invalida" << endl;
    }
    
    return 0;
}

// Codigo 29: Funciones Sobrecargadas
#include <iostream>
#include <cmath>
using namespace std;

// Area del rectangulo
double area(double base, double altura) {
    return base * altura;
}

// Area del circulo
double area(double radio) {
    return 3.14159 * radio * radio;
}

// Area del triangulo
double area(double base, double altura, bool esTriangulo) {
    return (base * altura) / 2.0;
}

int main() {
    int opcion;
    
    cout << "Calcular area de:" << endl;
    cout << "1. Rectangulo" << endl;
    cout << "2. Circulo" << endl;
    cout << "3. Triangulo" << endl;
    cout << "Opcion: ";
    cin >> opcion;
    
    switch (opcion) {
        case 1: {
            double base, altura;
            cout << "Ingrese base y altura: ";
            cin >> base >> altura;
            cout << "Area del rectangulo: " << area(base, altura) << endl;
            break;
        }
        case 2: {
            double radio;
            cout << "Ingrese el radio: ";
            cin >> radio;
            cout << "Area del circulo: " << area(radio) << endl;
            break;
        }
        case 3: {
            double base, altura;
            cout << "Ingrese base y altura: ";
            cin >> base >> altura;
            cout << "Area del triangulo: " << area(base, altura, true) << endl;
            break;
        }
        default:
            cout << "Opcion invalida" << endl;
    }
    
    return 0;
}

// Codigo 30: Parametros por Referencia
#include <iostream>
using namespace std;

void intercambiar(int &a, int &b) {
    int temp = a;
    a = b;
    b = temp;
}

int main() {
    int x, y;
    
    cout << "Ingrese dos numeros: ";
    cin >> x >> y;
    
    cout << "Antes del intercambio: x = " << x << ", y = " << y << endl;
    
    intercambiar(x, y);
    
    cout << "Despues del intercambio: x = " << x << ", y = " << y << endl;
    
    return 0;
}