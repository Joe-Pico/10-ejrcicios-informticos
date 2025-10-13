/******************************************************************************

                              Online C++ Compiler.
               Code, Compile, Run and Debug C++ program online.
Write your code in this editor and press "Run" button to compile and execute it.

*******************************************************************************/

#include <iostream>
using namespace std;

int main() {
    int numero, divisor;
    cout << "Ingresa número y divisor: ";
    cin >> numero >> divisor;
    
    if (divisor == 0) {
        cout << "Error: División por cero" << endl;
    } else if (numero % divisor == 0) {
        cout << numero << " es divisible por " << divisor << endl;
    } else {
        cout << numero << " NO es divisible por " << divisor << endl;
    }
    return 0;
}