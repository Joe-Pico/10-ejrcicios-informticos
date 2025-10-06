/******************************************************************************

                              Online C++ Compiler.
               Code, Compile, Run and Debug C++ program online.
Write your code in this editor and press "Run" button to compile and execute it.

*******************************************************************************/

#include <iostream>
#include <vector>
#include <string>
using namespace std;

class Mascota {
private:
    string nombre;
    int edad;
    string tipo;
    float peso;

public:
    void ingresarDatos() {
        cout << "Nombre de la mascota: ";
        getline(cin, nombre);
        cout << "Edad: ";
        cin >> edad;
        cin.ignore();
        cout << "Tipo (perro, gato, etc.): ";
        getline(cin, tipo);
        cout << "Peso (kg): ";
        cin >> peso;
        cin.ignore();
    }

    void mostrarDatos() const {
        cout << "Nombre: " << nombre << ", Edad: " << edad
             << ", Tipo: " << tipo << ", Peso: " << peso << " kg" << endl;
    }

    string obtenerNombre() const {
        return nombre;
    }
};

int main() {
    vector<Mascota> mascotas;
    int opcion;

    do {
        cout << "\n--- Menú Veterinaria ---\n";
        cout << "1. Agregar mascota\n";
        cout << "2. Mostrar todas las mascotas\n";
        cout << "3. Buscar mascota por nombre\n";
        cout << "4. Salir\n";
        cout << "Seleccione una opción: ";
        cin >> opcion;
        cin.ignore();

        switch (opcion) {
            case 1: {
                if (mascotas.size() >= 10) {
                    cout << "No se pueden agregar más mascotas (límite alcanzado)." << endl;
                } else {
                    Mascota nueva;
                    nueva.ingresarDatos();
                    mascotas.push_back(nueva);
                    cout << "Mascota agregada correctamente." << endl;
                }
                break;
            }
            case 2: {
                if (mascotas.empty()) {
                    cout << "No hay mascotas registradas." << endl;
                } else {
                    cout << "\n--- Lista de mascotas ---\n";
                    for (const auto& m : mascotas) {
                        m.mostrarDatos();
                    }
                }
                break;
            }
            case 3: {
                string nombreBuscado;
                cout << "Ingrese el nombre de la mascota a buscar: ";
                getline(cin, nombreBuscado);
                bool encontrada = false;
                for (const auto& m : mascotas) {
                    if (m.obtenerNombre() == nombreBuscado) {
                        cout << "Mascota encontrada:\n";
                        m.mostrarDatos();
                        encontrada = true;
                        break;
                    }
                }
                if (!encontrada) {
                    cout << "Mascota no encontrada." << endl;
                }
                break;
            }
            case 4:
                cout << "Saliendo del programa..." << endl;
                break;
            default:
                cout << "Opción inválida." << endl;
        }

    } while (opcion != 4);

    return 0;
}