/******************************************************************************

                              Online C++ Compiler.
               Code, Compile, Run and Debug C++ program online.
Write your code in this editor and press "Run" button to compile and execute it.

*******************************************************************************/

#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;

int main() {
    int numeroSecreto, intento;

    srand(time(0));
    numeroSecreto = rand() % 100 + 1;

    cout << "¡Adivina el número secreto entre 1 y 100!" << endl;

    do {
        cout << "Ingresa tu intento: ";
        cin >> intento;

        if (intento < numeroSecreto) {
            cout << "Demasiado bajo. Intenta de nuevo." << endl;
        } else if (intento > numeroSecreto) {
            cout << "Demasiado alto. Intenta de nuevo." << endl;
        } else {
            cout << "¡Felicidades! Adivinaste el número." << endl;
        }
    } while (intento != numeroSecreto);

    return 0;
}