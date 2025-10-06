/******************************************************************************

                              Online C++ Compiler.
               Code, Compile, Run and Debug C++ program online.
Write your code in this editor and press "Run" button to compile and execute it.

*******************************************************************************/
Verificar si un número es primo>S
#include <iostream>
using namespace std;

int main() {
    int numero;
    bool esPrimo = true;

    cout << "Ingrese un número entero positivo: ";
    cin >> numero;

    if (cin.fail() || numero <= 0) {
        cout << "Entrada inválida. Por favor ingrese un número entero positivo." << endl;
        return 1;
    }

    if (numero == 1) {
        esPrimo = false;
    } else {
        for (int i = 2; i * i <= numero; ++i) {
            if (numero % i == 0) {
                esPrimo = false;
                break;
            }
        }
    }

    if (esPrimo) {
        cout << numero << " es un número primo." << endl;
    } else {
        cout << numero << " no es un número primo." << endl;
    }

    return 0;
    
    }