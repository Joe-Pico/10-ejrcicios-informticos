/******************************************************************************

                              Online C++ Compiler.
               Code, Compile, Run and Debug C++ program online.
Write your code in this editor and press "Run" button to compile and execute it.

*******************************************************************************/
#include <iostream>
#include <string>
using namespace std;

const int MAX_ESTUDIANTES = 5;
const int NUM_NOTAS = 3;

struct Estudiante {
    string nombre;
    int edad;
    string codigo;
    float notas[NUM_NOTAS];
    float promedio;
};

// Función para calcular el promedio
float calcularPromedio(float notas[], int cantidad) {
    float suma = 0;
    for (int i = 0; i < cantidad; ++i) {
        suma += notas[i];
    }
    return suma / cantidad;
}

// Función para mostrar el reporte
void mostrarReporte(Estudiante estudiantes[], int cantidad) {
    int aprobados = 0, reprobados = 0;

    cout << "\n--- REPORTE DE ESTUDIANTES ---\n";
    for (int i = 0; i < cantidad; ++i) {
        cout << "\nEstudiante #" << i + 1 << endl;
        cout << "Nombre: " << estudiantes[i].nombre << endl;
        cout << "Edad: " << estudiantes[i].edad << endl;
        cout << "Código: " << estudiantes[i].codigo << endl;
        cout << "Notas: ";
        for (int j = 0; j < NUM_NOTAS; ++j) {
            cout << estudiantes[i].notas[j] << " ";
        }
        cout << "\nPromedio: " << estudiantes[i].promedio << endl;

        if (estudiantes[i].promedio >= 7) {
            ++aprobados;
        } else {
            ++reprobados;
        }
    }

    cout << "\nTotal de estudiantes: " << cantidad << endl;
    cout << "Aprobados: " << aprobados << endl;
    cout << "Reprobados: " << reprobados << endl;
}

int main() {
    Estudiante estudiantes[MAX_ESTUDIANTES];
    int cantidad;

    cout << "¿Cuántos estudiantes desea ingresar? (máximo " << MAX_ESTUDIANTES << "): ";
    cin >> cantidad;

    if (cantidad < 1 || cantidad > MAX_ESTUDIANTES) {
        cout << "Cantidad inválida. Saliendo del programa." << endl;
        return 1;
    }

    for (int i = 0; i < cantidad; ++i) {
        cout << "\n--- Ingreso de datos del estudiante #" << i + 1 << " ---\n";
        cin.ignore(); // Limpiar buffer
        cout << "Nombre: ";
        getline(cin, estudiantes[i].nombre);

        cout << "Edad: ";
        cin >> estudiantes[i].edad;

        cout << "Código: ";
        cin >> estudiantes[i].codigo;

        cout << "Ingrese las " << NUM_NOTAS << " notas:\n";
        for (int j = 0; j < NUM_NOTAS; ++j) {
            cout << "Nota " << j + 1 << ": ";
            cin >> estudiantes[i].notas[j];
        }

        estudiantes[i].promedio = calcularPromedio(estudiantes[i].notas, NUM_NOTAS);
    }

    mostrarReporte(estudiantes, cantidad);

    return 0;
}