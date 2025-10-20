// Codigo 11: Numeros del 1 al 100
#include <iostream>
using namespace std;

int main() {
    cout << "Numeros del 1 al 100:" << endl;
    for (int i = 1; i <= 100; i++) {
        cout << i << " ";
        if (i % 10 == 0) cout << endl; // Nueva linea cada 10 numeros
    }
    return 0;
}

// Codigo 12: Suma de Numeros Naturales
#include <iostream>
using namespace std;

int main() {
    int n, suma = 0;
    
    cout << "Ingrese un numero: ";
    cin >> n;
    
    for (int i = 1; i <= n; i++) {
        suma += i;
    }
    
    cout << "La suma de los primeros " << n << " numeros naturales es: " << suma << endl;
    return 0;
}

// Codigo 13: Factorial de un Numero
#include <iostream>
using namespace std;

int main() {
    int n;
    long long factorial = 1;
    
    cout << "Ingrese un numero: ";
    cin >> n;
    
    if (n < 0) {
        cout << "El factorial no esta definido para numeros negativos" << endl;
    } else {
        for (int i = 1; i <= n; i++) {
            factorial *= i;
        }
        cout << "El factorial de " << n << " es: " << factorial << endl;
    }
    
    return 0;
}

// Codigo 14: Numero Primo
#include <iostream>
using namespace std;

int main() {
    int n;
    bool esPrimo = true;
    
    cout << "Ingrese un numero: ";
    cin >> n;
    
    if (n <= 1) {
        esPrimo = false;
    } else {
        for (int i = 2; i * i <= n; i++) {
            if (n % i == 0) {
                esPrimo = false;
                break;
            }
        }
    }
    
    if (esPrimo) {
        cout << n << " es un numero primo" << endl;
    } else {
        cout << n << " no es un numero primo" << endl;
    }
    
    return 0;
}

// Codigo 15: Secuencia de Fibonacci
#include <iostream>
using namespace std;

int main() {
    int n, a = 0, b = 1, siguiente;
    
    cout << "Ingrese el numero de terminos de Fibonacci: ";
    cin >> n;
    
    cout << "Secuencia de Fibonacci:" << endl;
    
    if (n >= 1) cout << a << " ";
    if (n >= 2) cout << b << " ";
    
    for (int i = 3; i <= n; i++) {
        siguiente = a + b;
        cout << siguiente << " ";
        a = b;
        b = siguiente;
    }
    cout << endl;
    
    return 0;
}

// Codigo 16: Menu de Opciones
#include <iostream>
using namespace std;

int main() {
    int opcion;
    
    do {
        cout << "\n=== MENU PRINCIPAL ===" << endl;
        cout << "1. Opcion 1" << endl;
        cout << "2. Opcion 2" << endl;
        cout << "3. Opcion 3" << endl;
        cout << "0. Salir" << endl;
        cout << "Seleccione una opcion: ";
        cin >> opcion;
        
        switch (opcion) {
            case 1:
                cout << "Ha seleccionado la Opcion 1" << endl;
                break;
            case 2:
                cout << "Ha seleccionado la Opcion 2" << endl;
                break;
            case 3:
                cout << "Ha seleccionado la Opcion 3" << endl;
                break;
            case 0:
                cout << "Saliendo del programa..." << endl;
                break;
            default:
                cout << "Opcion invalida" << endl;
        }
    } while (opcion != 0);
    
    return 0;
}

// Codigo 17: Conteo de Digitos
#include <iostream>
using namespace std;

int main() {
    int numero, contador = 0;
    
    cout << "Ingrese un numero: ";
    cin >> numero;
    
    if (numero == 0) {
        contador = 1;
    } else {
        numero = abs(numero); // Valor absoluto
        while (numero > 0) {
            numero /= 10;
            contador++;
        }
    }
    
    cout << "El numero tiene " << contador << " digitos" << endl;
    return 0;
}

// Codigo 18: Suma de Digitos
#include <iostream>
using namespace std;

int main() {
    int numero, suma = 0, digito;
    
    cout << "Ingrese un numero: ";
    cin >> numero;
    
    numero = abs(numero); // Valor absoluto
    
    while (numero > 0) {
        digito = numero % 10;
        suma += digito;
        numero /= 10;
    }
    
    cout << "La suma de los digitos es: " << suma << endl;
    return 0;
}

// Codigo 19: Numero Perfecto
#include <iostream>
using namespace std;

int main() {
    int numero, suma = 0;
    
    cout << "Ingrese un numero: ";
    cin >> numero;
    
    for (int i = 1; i < numero; i++) {
        if (numero % i == 0) {
            suma += i;
        }
    }
    
    if (suma == numero && numero > 0) {
        cout << numero << " es un numero perfecto" << endl;
    } else {
        cout << numero << " no es un numero perfecto" << endl;
    }
    
    return 0;
}

// Codigo 20: Piramide de Asteriscos
#include <iostream>
using namespace std;

int main() {
    int altura;
    
    cout << "Ingrese la altura de la piramide: ";
    cin >> altura;
    
    for (int i = 1; i <= altura; i++) {
        // Espacios en blanco
        for (int j = 1; j <= altura - i; j++) {
            cout << " ";
        }
        // Asteriscos
        for (int k = 1; k <= 2 * i - 1; k++) {
            cout << "*";
        }
        cout << endl;
    }
    
    return 0;
}