// Codigo 31: Promedio de Calificaciones
#include <iostream>
using namespace std;

int main() {
    const int MAX_CALIFICACIONES = 10;
    float calificaciones[MAX_CALIFICACIONES];
    int n;
    float suma = 0, promedio;
    
    cout << "Ingrese el numero de calificaciones (max 10): ";
    cin >> n;
    
    if (n > MAX_CALIFICACIONES) n = MAX_CALIFICACIONES;
    
    for (int i = 0; i < n; i++) {
        cout << "Ingrese calificacion " << i + 1 << ": ";
        cin >> calificaciones[i];
        suma += calificaciones[i];
    }
    
    promedio = suma / n;
    cout << "El promedio es: " << promedio << endl;
    
    return 0;
}

// Codigo 32: Mayor y Menor Elemento
#include <iostream>
using namespace std;

int main() {
    const int TAMAÑO = 5;
    int numeros[TAMAÑO];
    int mayor, menor;
    
    cout << "Ingrese " << TAMAÑO << " numeros:" << endl;
    for (int i = 0; i < TAMAÑO; i++) {
        cout << "Numero " << i + 1 << ": ";
        cin >> numeros[i];
    }
    
    mayor = menor = numeros[0];
    
    for (int i = 1; i < TAMAÑO; i++) {
        if (numeros[i] > mayor) {
            mayor = numeros[i];
        }
        if (numeros[i] < menor) {
            menor = numeros[i];
        }
    }
    
    cout << "Mayor elemento: " << mayor << endl;
    cout << "Menor elemento: " << menor << endl;
    
    return 0;
}

// Codigo 33: Busqueda Lineal
#include <iostream>
using namespace std;

int busquedaLineal(int arr[], int tamaño, int objetivo) {
    for (int i = 0; i < tamaño; i++) {
        if (arr[i] == objetivo) {
            return i; // Retorna el indice donde se encontro
        }
    }
    return -1; // No encontrado
}

int main() {
    const int TAMAÑO = 10;
    int numeros[TAMAÑO] = {64, 34, 25, 12, 22, 11, 90, 88, 76, 50};
    int objetivo;
    
    cout << "Array: ";
    for (int i = 0; i < TAMAÑO; i++) {
        cout << numeros[i] << " ";
    }
    cout << endl;
    
    cout << "Ingrese el numero a buscar: ";
    cin >> objetivo;
    
    int posicion = busquedaLineal(numeros, TAMAÑO, objetivo);
    
    if (posicion != -1) {
        cout << "Numero encontrado en la posicion: " << posicion << endl;
    } else {
        cout << "Numero no encontrado" << endl;
    }
    
    return 0;
}

// Codigo 34: Ordenamiento Burbuja
#include <iostream>
using namespace std;

void ordenamientoBurbuja(int arr[], int n) {
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            if (arr[j] > arr[j + 1]) {
                // Intercambiar elementos
                int temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }
}

void imprimirArray(int arr[], int tamaño) {
    for (int i = 0; i < tamaño; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;
}

int main() {
    const int TAMAÑO = 8;
    int numeros[TAMAÑO] = {64, 34, 25, 12, 22, 11, 90, 88};
    
    cout << "Array original: ";
    imprimirArray(numeros, TAMAÑO);
    
    ordenamientoBurbuja(numeros, TAMAÑO);
    
    cout << "Array ordenado: ";
    imprimirArray(numeros, TAMAÑO);
    
    return 0;
}

// Codigo 35: Inversion de Array
#include <iostream>
using namespace std;

void invertirArray(int arr[], int tamaño) {
    int inicio = 0;
    int fin = tamaño - 1;
    
    while (inicio < fin) {
        // Intercambiar elementos
        int temp = arr[inicio];
        arr[inicio] = arr[fin];
        arr[fin] = temp;
        
        inicio++;
        fin--;
    }
}

void imprimirArray(int arr[], int tamaño) {
    for (int i = 0; i < tamaño; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;
}

int main() {
    const int TAMAÑO = 6;
    int numeros[TAMAÑO] = {1, 2, 3, 4, 5, 6};
    
    cout << "Array original: ";
    imprimirArray(numeros, TAMAÑO);
    
    invertirArray(numeros, TAMAÑO);
    
    cout << "Array invertido: ";
    imprimirArray(numeros, TAMAÑO);
    
    return 0;
}

// Codigo 36: Frecuencia de Elementos
#include <iostream>
using namespace std;

int main() {
    const int TAMAÑO = 10;
    int numeros[TAMAÑO] = {1, 2, 2, 3, 3, 3, 4, 4, 4, 4};
    bool visitado[TAMAÑO] = {false};
    
    cout << "Array: ";
    for (int i = 0; i < TAMAÑO; i++) {
        cout << numeros[i] << " ";
    }
    cout << endl << endl;
    
    cout << "Frecuencia de elementos:" << endl;
    
    for (int i = 0; i < TAMAÑO; i++) {
        if (!visitado[i]) {
            int frecuencia = 1;
            
            // Contar occurrencias
            for (int j = i + 1; j < TAMAÑO; j++) {
                if (numeros[i] == numeros[j]) {
                    frecuencia++;
                    visitado[j] = true;
                }
            }
            
            cout << "Numero " << numeros[i] << " aparece " << frecuencia << " veces" << endl;
        }
    }
    
    return 0;
}

// Codigo 37: Arrays Bidimensionales
#include <iostream>
using namespace std;

int main() {
    const int FILAS = 3;
    const int COLUMNAS = 3;
    int matriz[FILAS][COLUMNAS];
    int suma = 0;
    
    cout << "Ingrese los elementos de la matriz 3x3:" << endl;
    for (int i = 0; i < FILAS; i++) {
        for (int j = 0; j < COLUMNAS; j++) {
            cout << "Elemento [" << i << "][" << j << "]: ";
            cin >> matriz[i][j];
            suma += matriz[i][j];
        }
    }
    
    cout << "\nMatriz ingresada:" << endl;
    for (int i = 0; i < FILAS; i++) {
        for (int j = 0; j < COLUMNAS; j++) {
            cout << matriz[i][j] << "\t";
        }
        cout << endl;
    }
    
    cout << "\nSuma de todos los elementos: " << suma << endl;
    
    return 0;
}

// Codigo 38: Multiplicacion de Matrices
#include <iostream>
using namespace std;

int main() {
    const int TAMAÑO = 2;
    int matriz1[TAMAÑO][TAMAÑO] = {{1, 2}, {3, 4}};
    int matriz2[TAMAÑO][TAMAÑO] = {{5, 6}, {7, 8}};
    int resultado[TAMAÑO][TAMAÑO] = {0};
    
    cout << "Matriz 1:" << endl;
    for (int i = 0; i < TAMAÑO; i++) {
        for (int j = 0; j < TAMAÑO; j++) {
            cout << matriz1[i][j] << "\t";
        }
        cout << endl;
    }
    
    cout << "\nMatriz 2:" << endl;
    for (int i = 0; i < TAMAÑO; i++) {
        for (int j = 0; j < TAMAÑO; j++) {
            cout << matriz2[i][j] << "\t";
        }
        cout << endl;
    }
    
    // Multiplicacion de matrices
    for (int i = 0; i < TAMAÑO; i++) {
        for (int j = 0; j < TAMAÑO; j++) {
            for (int k = 0; k < TAMAÑO; k++) {
                resultado[i][j] += matriz1[i][k] * matriz2[k][j];
            }
        }
    }
    
    cout << "\nResultado de la multiplicacion:" << endl;
    for (int i = 0; i < TAMAÑO; i++) {
        for (int j = 0; j < TAMAÑO; j++) {
            cout << resultado[i][j] << "\t";
        }
        cout << endl;
    }
    
    return 0;
}

// Codigo 39: Vector Dinamico
#include <iostream>
#include <vector>
using namespace std;

int main() {
    vector<int> numeros;
    int valor;
    int opcion;
    
    do {
        cout << "\n=== MENU VECTOR ===" << endl;
        cout << "1. Agregar numero" << endl;
        cout << "2. Mostrar vector" << endl;
        cout << "3. Eliminar ultimo" << endl;
        cout << "4. Buscar numero" << endl;
        cout << "0. Salir" << endl;
        cout << "Opcion: ";
        cin >> opcion;
        
        switch (opcion) {
            case 1:
                cout << "Ingrese numero: ";
                cin >> valor;
                numeros.push_back(valor);
                cout << "Numero agregado" << endl;
                break;
                
            case 2:
                cout << "Vector: ";
                for (int i = 0; i < numeros.size(); i++) {
                    cout << numeros[i] << " ";
                }
                cout << "\nTamaño: " << numeros.size() << endl;
                break;
                
            case 3:
                if (!numeros.empty()) {
                    numeros.pop_back();
                    cout << "Ultimo elemento eliminado" << endl;
                } else {
                    cout << "Vector vacio" << endl;
                }
                break;
                
            case 4:
                cout << "Ingrese numero a buscar: ";
                cin >> valor;
                {
                    bool encontrado = false;
                    for (int i = 0; i < numeros.size(); i++) {
                        if (numeros[i] == valor) {
                            cout << "Encontrado en posicion: " << i << endl;
                            encontrado = true;
                            break;
                        }
                    }
                    if (!encontrado) {
                        cout << "Numero no encontrado" << endl;
                    }
                }
                break;
                
            case 0:
                cout << "Saliendo..." << endl;
                break;
                
            default:
                cout << "Opcion invalida" << endl;
        }
    } while (opcion != 0);
    
    return 0;
}

// Codigo 40: Eliminacion de Duplicados
#include <iostream>
#include <vector>
using namespace std;

vector<int> eliminarDuplicados(vector<int>& arr) {
    vector<int> resultado;
    
    for (int i = 0; i < arr.size(); i++) {
        bool esDuplicado = false;
        
        // Verificar si ya existe en el resultado
        for (int j = 0; j < resultado.size(); j++) {
            if (arr[i] == resultado[j]) {
                esDuplicado = true;
                break;
            }
        }
        
        // Si no es duplicado, agregarlo
        if (!esDuplicado) {
            resultado.push_back(arr[i]);
        }
    }
    
    return resultado;
}

int main() {
    vector<int> numeros = {1, 2, 2, 3, 4, 4, 5, 1, 6, 3};
    
    cout << "Vector original: ";
    for (int num : numeros) {
        cout << num << " ";
    }
    cout << endl;
    
    vector<int> sinDuplicados = eliminarDuplicados(numeros);
    
    cout << "Vector sin duplicados: ";
    for (int num : sinDuplicados) {
        cout << num << " ";
    }
    cout << endl;
    
    return 0;
}