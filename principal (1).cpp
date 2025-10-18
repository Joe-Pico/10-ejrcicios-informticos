/******************************************************************************

                              Online C++ Compiler.
               Code, Compile, Run and Debug C++ program online.
Write your code in this editor and press "Run" button to compile and execute it.

*******************************************************************************/

#include <iostream>
using namespace std;

struct Producto {
    string nombre;
    float precio;
};

void comparar(Producto a, Producto b) {
    if (a.precio < b.precio)
        cout << a.nombre << " es más barato.\n";
    else if (a.precio > b.precio)
        cout << b.nombre << " es más barato.\n";
    else
        cout << "Ambos productos tienen el mismo precio.\n";
}

int main() {
    Producto p1, p2;
    cout << "Producto 1 nombre: "; cin >> p1.nombre;
    cout << "Precio: "; cin >> p1.precio;

    cout << "Producto 2 nombre: "; cin >> p2.nombre;
    cout << "Precio: "; cin >> p2.precio;

    comparar(p1, p2);
    return 0;
}
