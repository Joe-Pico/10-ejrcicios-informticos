/******************************************************************************

                              Online C++ Compiler.
               Code, Compile, Run and Debug C++ program online.
Write your code in this editor and press "Run" button to compile and execute it.

*******************************************************************************/

#include <iostream>
using namespace std;

struct Empleado {
    string nombre;
    int edad;
    float salario;
};

void mostrarEmpleado(Empleado e) {
    cout << "Nombre: " << e.nombre << endl;
    cout << "Edad: " << e.edad << endl;
    cout << "Salario: $" << e.salario << endl;
}

int main() {
    Empleado emp;
    cout << "Ingrese nombre: ";
    cin >> emp.nombre;
    cout << "Ingrese edad: ";
    cin >> emp.edad;
    cout << "Ingrese salario: ";
    cin >> emp.salario;

    mostrarEmpleado(emp);
    return 0;
}
