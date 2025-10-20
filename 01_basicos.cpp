// Codigo 1: Hola Mundo
#include <iostream>
using namespace std;

int main() {
    cout << "Hola Mundo!" << endl;
    return 0;
}

// Codigo 2: Variables y Tipos de Datos
#include <iostream>
#include <string>
using namespace std;

int main() {
    int entero = 25;
    float flotante = 3.14f;
    double doble = 2.71828;
    char caracter = 'A';
    string cadena = "Hola C++";
    bool booleano = true;
    
    cout << "Entero: " << entero << endl;
    cout << "Flotante: " << flotante << endl;
    cout << "Doble: " << doble << endl;
    cout << "Caracter: " << caracter << endl;
    cout << "Cadena: " << cadena << endl;
    cout << "Booleano: " << booleano << endl;
    
    return 0;
}

// Codigo 3: Suma de Dos Numeros
#include <iostream>
using namespace std;

int main() {
    int num1, num2, suma;
    
    cout << "Ingrese el primer numero: ";
    cin >> num1;
    cout << "Ingrese el segundo numero: ";
    cin >> num2;
    
    suma = num1 + num2;
    cout << "La suma es: " << suma << endl;
    
    return 0;
}

// Codigo 4: Area de un Rectangulo
#include <iostream>
using namespace std;

int main() {
    float base, altura, area;
    
    cout << "Ingrese la base del rectangulo: ";
    cin >> base;
    cout << "Ingrese la altura del rectangulo: ";
    cin >> altura;
    
    area = base * altura;
    cout << "El area del rectangulo es: " << area << endl;
    
    return 0;
}

// Codigo 5: Conversion de Temperatura
#include <iostream>
using namespace std;

int main() {
    float celsius, fahrenheit;
    
    cout << "Ingrese la temperatura en Celsius: ";
    cin >> celsius;
    
    fahrenheit = (celsius * 9.0/5.0) + 32;
    cout << celsius << " grados Celsius = " << fahrenheit << " grados Fahrenheit" << endl;
    
    return 0;
}

// Codigo 6: Numero Par o Impar
#include <iostream>
using namespace std;

int main() {
    int numero;
    
    cout << "Ingrese un numero: ";
    cin >> numero;
    
    if (numero % 2 == 0) {
        cout << numero << " es par" << endl;
    } else {
        cout << numero << " es impar" << endl;
    }
    
    return 0;
}

// Codigo 7: Mayor de Tres Numeros
#include <iostream>
using namespace std;

int main() {
    int a, b, c;
    
    cout << "Ingrese tres numeros: ";
    cin >> a >> b >> c;
    
    if (a >= b && a >= c) {
        cout << "El mayor es: " << a << endl;
    } else if (b >= a && b >= c) {
        cout << "El mayor es: " << b << endl;
    } else {
        cout << "El mayor es: " << c << endl;
    }
    
    return 0;
}

// Codigo 8: Calculadora Basica
#include <iostream>
using namespace std;

int main() {
    float num1, num2, resultado;
    char operador;
    
    cout << "Ingrese primer numero: ";
    cin >> num1;
    cout << "Ingrese operador (+, -, *, /): ";
    cin >> operador;
    cout << "Ingrese segundo numero: ";
    cin >> num2;
    
    switch(operador) {
        case '+':
            resultado = num1 + num2;
            break;
        case '-':
            resultado = num1 - num2;
            break;
        case '*':
            resultado = num1 * num2;
            break;
        case '/':
            if (num2 != 0) {
                resultado = num1 / num2;
            } else {
                cout << "Error: Division por cero" << endl;
                return 1;
            }
            break;
        default:
            cout << "Operador invalido" << endl;
            return 1;
    }
    
    cout << "Resultado: " << resultado << endl;
    return 0;
}

// Codigo 9: Tabla de Multiplicar
#include <iostream>
using namespace std;

int main() {
    int numero;
    
    cout << "Ingrese un numero para su tabla de multiplicar: ";
    cin >> numero;
    
    cout << "Tabla de multiplicar del " << numero << ":" << endl;
    for (int i = 1; i <= 10; i++) {
        cout << numero << " x " << i << " = " << numero * i << endl;
    }
    
    return 0;
}

// Codigo 10: Intercambio de Variables
#include <iostream>
using namespace std;

int main() {
    int a, b;
    
    cout << "Ingrese primer numero: ";
    cin >> a;
    cout << "Ingrese segundo numero: ";
    cin >> b;
    
    cout << "Antes del intercambio: a = " << a << ", b = " << b << endl;
    
    // Intercambio sin variable temporal
    a = a + b;
    b = a - b;
    a = a - b;
    
    cout << "Despues del intercambio: a = " << a << ", b = " << b << endl;
    
    return 0;
}