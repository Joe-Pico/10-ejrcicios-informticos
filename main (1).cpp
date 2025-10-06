/******************************************************************************

                              Online C++ Compiler.
               Code, Compile, Run and Debug C++ program online.
Write your code in this editor and press "Run" button to compile and execute it.

*******************************************************************************/

#include <iostream>
using namespace std;

int main() {
    int numero;

    cout << "Ingrese un número entero: ";
    cin >> numero;

    if (numero % 2 == 0) {
        cout << numero << " es un número par." << endl;
    } else {
        cout << numero << " es un número impar." << endl;
    }

    return 0;
}