// Codigo 61: Introduccion a Punteros
#include <iostream>
using namespace std;

int main() {
    int numero = 42;
    int* puntero = &numero;
    
    cout << "=== INTRODUCCION A PUNTEROS ===" << endl;
    cout << "Valor de numero: " << numero << endl;
    cout << "Direccion de numero: " << &numero << endl;
    cout << "Valor del puntero: " << puntero << endl;
    cout << "Valor apuntado por puntero: " << *puntero << endl;
    
    // Modificar valor a traves del puntero
    *puntero = 100;
    cout << "\nDespues de modificar via puntero:" << endl;
    cout << "Valor de numero: " << numero << endl;
    cout << "Valor apuntado por puntero: " << *puntero << endl;
    
    return 0;
}

// Codigo 62: Aritmetica de Punteros
#include <iostream>
using namespace std;

int main() {
    int arreglo[5] = {10, 20, 30, 40, 50};
    int* ptr = arreglo; // Apunta al primer elemento
    
    cout << "=== ARITMETICA DE PUNTEROS ===" << endl;
    cout << "Arreglo original: ";
    for (int i = 0; i < 5; i++) {
        cout << arreglo[i] << " ";
    }
    cout << endl;
    
    cout << "\nUsando aritmetica de punteros:" << endl;
    for (int i = 0; i < 5; i++) {
        cout << "ptr + " << i << " = " << *(ptr + i) << endl;
    }
    
    cout << "\nRecorriendo con incremento de puntero:" << endl;
    ptr = arreglo; // Reiniciar puntero
    for (int i = 0; i < 5; i++) {
        cout << "Elemento " << i << ": " << *ptr << endl;
        ptr++;
    }
    
    return 0;
}

// Codigo 63: Memoria Dinamica - new y delete
#include <iostream>
using namespace std;

int main() {
    cout << "=== MEMORIA DINAMICA ===" << endl;
    
    // Asignar memoria para un entero
    int* numeroPtr = new int(42);
    cout << "Valor en memoria dinamica: " << *numeroPtr << endl;
    
    // Modificar el valor
    *numeroPtr = 100;
    cout << "Nuevo valor: " << *numeroPtr << endl;
    
    // Liberar memoria
    delete numeroPtr;
    numeroPtr = nullptr; // Buena practica
    
    // Asignar memoria para un arreglo
    int tamaño;
    cout << "\nIngrese el tamaño del arreglo: ";
    cin >> tamaño;
    
    int* arreglo = new int[tamaño];
    
    // Llenar el arreglo
    cout << "Ingrese " << tamaño << " numeros:" << endl;
    for (int i = 0; i < tamaño; i++) {
        cout << "Elemento " << i << ": ";
        cin >> arreglo[i];
    }
    
    // Mostrar el arreglo
    cout << "\nArreglo ingresado: ";
    for (int i = 0; i < tamaño; i++) {
        cout << arreglo[i] << " ";
    }
    cout << endl;
    
    // Liberar memoria del arreglo
    delete[] arreglo;
    arreglo = nullptr;
    
    cout << "Memoria liberada correctamente" << endl;
    
    return 0;
}

// Codigo 64: Punteros a Funciones
#include <iostream>
using namespace std;

// Funciones matematicas
int sumar(int a, int b) {
    return a + b;
}

int restar(int a, int b) {
    return a - b;
}

int multiplicar(int a, int b) {
    return a * b;
}

double dividir(int a, int b) {
    if (b != 0) {
        return (double)a / b;
    }
    return 0;
}

// Funcion que usa punteros a funciones
void calculadora(int x, int y, int (*operacion)(int, int), const string& nombre) {
    cout << x << " " << nombre << " " << y << " = " << operacion(x, y) << endl;
}

int main() {
    cout << "=== PUNTEROS A FUNCIONES ===" << endl;
    
    int a = 10, b = 5;
    
    // Declarar punteros a funciones
    int (*ptr_suma)(int, int) = sumar;
    int (*ptr_resta)(int, int) = restar;
    int (*ptr_mult)(int, int) = multiplicar;
    
    cout << "Usando punteros a funciones:" << endl;
    cout << "a = " << a << ", b = " << b << endl;
    
    // Usar punteros a funciones directamente
    cout << "\nLlamadas directas:" << endl;
    cout << "Suma: " << ptr_suma(a, b) << endl;
    cout << "Resta: " << ptr_resta(a, b) << endl;
    cout << "Multiplicacion: " << ptr_mult(a, b) << endl;
    
    // Usar funcion que acepta punteros a funciones
    cout << "\nUsando funcion calculadora:" << endl;
    calculadora(a, b, sumar, "+");
    calculadora(a, b, restar, "-");
    calculadora(a, b, multiplicar, "*");
    
    // Arreglo de punteros a funciones
    int (*operaciones[])(int, int) = {sumar, restar, multiplicar};
    string nombres[] = {"+", "-", "*"};
    
    cout << "\nUsando arreglo de punteros a funciones:" << endl;
    for (int i = 0; i < 3; i++) {
        calculadora(a, b, operaciones[i], nombres[i]);
    }
    
    return 0;
}

// Codigo 65: Referencias
#include <iostream>
using namespace std;

// Funcion que usa paso por valor
void pasoPorValor(int x) {
    x = x * 2;
    cout << "Dentro de pasoPorValor: x = " << x << endl;
}

// Funcion que usa paso por referencia
void pasoPorReferencia(int& x) {
    x = x * 2;
    cout << "Dentro de pasoPorReferencia: x = " << x << endl;
}

// Funcion que usa paso por puntero
void pasoPorPuntero(int* x) {
    *x = *x * 2;
    cout << "Dentro de pasoPorPuntero: *x = " << *x << endl;
}

// Funcion que retorna una referencia
int& obtenerMayor(int& a, int& b) {
    return (a > b) ? a : b;
}

int main() {
    cout << "=== REFERENCIAS EN C++ ===" << endl;
    
    int numero = 10;
    
    cout << "Valor original: " << numero << endl;
    
    // Paso por valor
    cout << "\n1. Paso por valor:" << endl;
    pasoPorValor(numero);
    cout << "Despues de pasoPorValor: " << numero << endl;
    
    // Paso por referencia
    cout << "\n2. Paso por referencia:" << endl;
    pasoPorReferencia(numero);
    cout << "Despues de pasoPorReferencia: " << numero << endl;
    
    // Restaurar valor
    numero = 10;
    
    // Paso por puntero
    cout << "\n3. Paso por puntero:" << endl;
    pasoPorPuntero(&numero);
    cout << "Despues de pasoPorPuntero: " << numero << endl;
    
    // Referencias como alias
    cout << "\n4. Referencias como alias:" << endl;
    int original = 100;
    int& alias = original;
    
    cout << "original = " << original << endl;
    cout << "alias = " << alias << endl;
    
    alias = 200;
    cout << "Despues de modificar alias:" << endl;
    cout << "original = " << original << endl;
    cout << "alias = " << alias << endl;
    
    // Retornando referencias
    cout << "\n5. Retornando referencias:" << endl;
    int x = 15, y = 25;
    cout << "x = " << x << ", y = " << y << endl;
    
    int& mayor = obtenerMayor(x, y);
    cout << "Mayor es: " << mayor << endl;
    
    mayor = 50; // Modifica y
    cout << "Despues de modificar la referencia:" << endl;
    cout << "x = " << x << ", y = " << y << endl;
    
    return 0;
}

// Codigo 66: Smart Pointers (C++11)
#include <iostream>
#include <memory>
#include <string>
using namespace std;

class Recurso {
private:
    string nombre;
    
public:
    Recurso(const string& n) : nombre(n) {
        cout << "Recurso '" << nombre << "' creado" << endl;
    }
    
    ~Recurso() {
        cout << "Recurso '" << nombre << "' destruido" << endl;
    }
    
    void usar() {
        cout << "Usando recurso '" << nombre << "'" << endl;
    }
    
    string getNombre() const { return nombre; }
};

void demoUniquePtr() {
    cout << "\n=== UNIQUE_PTR ===" << endl;
    
    // Crear unique_ptr
    unique_ptr<Recurso> ptr1 = make_unique<Recurso>("UniqueRecurso1");
    ptr1->usar();
    
    // Transferir propiedad
    unique_ptr<Recurso> ptr2 = move(ptr1);
    
    if (!ptr1) {
        cout << "ptr1 ya no posee el recurso" << endl;
    }
    
    if (ptr2) {
        cout << "ptr2 ahora posee el recurso" << endl;
        ptr2->usar();
    }
    
    // ptr2 se destruira automaticamente al salir del scope
}

void demoSharedPtr() {
    cout << "\n=== SHARED_PTR ===" << endl;
    
    // Crear shared_ptr
    shared_ptr<Recurso> ptr1 = make_shared<Recurso>("SharedRecurso1");
    cout << "Contador de referencias: " << ptr1.use_count() << endl;
    
    {
        shared_ptr<Recurso> ptr2 = ptr1; // Copia el shared_ptr
        cout << "Contador de referencias: " << ptr1.use_count() << endl;
        
        ptr2->usar();
        
        // ptr2 se destruye al salir del bloque
    }
    
    cout << "Contador de referencias despues del bloque: " << ptr1.use_count() << endl;
    ptr1->usar();
    
    // ptr1 se destruira automaticamente
}

void demoWeakPtr() {
    cout << "\n=== WEAK_PTR ===" << endl;
    
    shared_ptr<Recurso> shared = make_shared<Recurso>("WeakRecurso1");
    weak_ptr<Recurso> weak = shared;
    
    cout << "Contador de referencias: " << shared.use_count() << endl;
    
    // Verificar si el recurso aun existe
    if (auto locked = weak.lock()) {
        locked->usar();
        cout << "Recurso accedido via weak_ptr" << endl;
    }
    
    // Destruir el shared_ptr
    shared.reset();
    
    // Intentar acceder via weak_ptr
    if (auto locked = weak.lock()) {
        locked->usar();
    } else {
        cout << "El recurso ya no existe" << endl;
    }
}

int main() {
    cout << "=== SMART POINTERS ===" << endl;
    
    demoUniquePtr();
    demoSharedPtr();
    demoWeakPtr();
    
    cout << "\nPrograma terminado" << endl;
    
    return 0;
}

// Codigo 67: Memoria Dinamica Avanzada
#include <iostream>
#include <vector>
#include <string>
using namespace std;

class Matriz {
private:
    int** datos;
    int filas;
    int columnas;
    
public:
    // Constructor
    Matriz(int f, int c) : filas(f), columnas(c) {
        // Asignar memoria para las filas
        datos = new int*[filas];
        
        // Asignar memoria para cada fila
        for (int i = 0; i < filas; i++) {
            datos[i] = new int[columnas];
            
            // Inicializar con ceros
            for (int j = 0; j < columnas; j++) {
                datos[i][j] = 0;
            }
        }
        
        cout << "Matriz " << filas << "x" << columnas << " creada" << endl;
    }
    
    // Destructor
    ~Matriz() {
        // Liberar memoria de cada fila
        for (int i = 0; i < filas; i++) {
            delete[] datos[i];
        }
        
        // Liberar memoria del array de punteros
        delete[] datos;
        
        cout << "Matriz destruida" << endl;
    }
    
    // Constructor de copia
    Matriz(const Matriz& otra) : filas(otra.filas), columnas(otra.columnas) {
        datos = new int*[filas];
        
        for (int i = 0; i < filas; i++) {
            datos[i] = new int[columnas];
            for (int j = 0; j < columnas; j++) {
                datos[i][j] = otra.datos[i][j];
            }
        }
        
        cout << "Matriz copiada" << endl;
    }
    
    // Operador de asignacion
    Matriz& operator=(const Matriz& otra) {
        if (this != &otra) {
            // Liberar memoria actual
            for (int i = 0; i < filas; i++) {
                delete[] datos[i];
            }
            delete[] datos;
            
            // Copiar nuevos datos
            filas = otra.filas;
            columnas = otra.columnas;
            
            datos = new int*[filas];
            for (int i = 0; i < filas; i++) {
                datos[i] = new int[columnas];
                for (int j = 0; j < columnas; j++) {
                    datos[i][j] = otra.datos[i][j];
                }
            }
        }
        return *this;
    }
    
    // Metodos de acceso
    void setElemento(int i, int j, int valor) {
        if (i >= 0 && i < filas && j >= 0 && j < columnas) {
            datos[i][j] = valor;
        }
    }
    
    int getElemento(int i, int j) const {
        if (i >= 0 && i < filas && j >= 0 && j < columnas) {
            return datos[i][j];
        }
        return 0;
    }
    
    // Llenar matriz con valores
    void llenar() {
        cout << "Ingrese los elementos de la matriz " << filas << "x" << columnas << ":" << endl;
        for (int i = 0; i < filas; i++) {
            for (int j = 0; j < columnas; j++) {
                cout << "Elemento [" << i << "][" << j << "]: ";
                cin >> datos[i][j];
            }
        }
    }
    
    // Mostrar matriz
    void mostrar() const {
        cout << "\nMatriz:" << endl;
        for (int i = 0; i < filas; i++) {
            for (int j = 0; j < columnas; j++) {
                cout << datos[i][j] << "\t";
            }
            cout << endl;
        }
    }
    
    // Obtener dimensiones
    int getFilas() const { return filas; }
    int getColumnas() const { return columnas; }
};

int main() {
    cout << "=== MEMORIA DINAMICA AVANZADA ===" << endl;
    
    int filas, columnas;
    
    cout << "Ingrese numero de filas: ";
    cin >> filas;
    cout << "Ingrese numero de columnas: ";
    cin >> columnas;
    
    // Crear matriz dinamica
    Matriz matriz1(filas, columnas);
    matriz1.llenar();
    matriz1.mostrar();
    
    // Probar constructor de copia
    cout << "\nCreando copia de la matriz:" << endl;
    Matriz matriz2 = matriz1;
    matriz2.mostrar();
    
    // Modificar la copia
    cout << "\nModificando la copia:" << endl;
    matriz2.setElemento(0, 0, 999);
    
    cout << "Matriz original:";
    matriz1.mostrar();
    cout << "Matriz copia:";
    matriz2.mostrar();
    
    return 0;
}

// Codigo 68: Manejo de Excepciones con Memoria
#include <iostream>
#include <stdexcept>
#include <memory>
using namespace std;

class RecursoSeguro {
private:
    int* datos;
    size_t tamaño;
    
public:
    RecursoSeguro(size_t t) : tamaño(t) {
        if (t == 0) {
            throw invalid_argument("Tamaño debe ser mayor que 0");
        }
        
        try {
            datos = new int[tamaño];
            for (size_t i = 0; i < tamaño; i++) {
                datos[i] = 0;
            }
            cout << "Recurso de tamaño " << tamaño << " creado" << endl;
        } catch (bad_alloc& e) {
            cout << "Error al asignar memoria: " << e.what() << endl;
            throw;
        }
    }
    
    ~RecursoSeguro() {
        delete[] datos;
        cout << "Recurso destruido" << endl;
    }
    
    void setElemento(size_t index, int valor) {
        if (index >= tamaño) {
            throw out_of_range("Indice fuera de rango");
        }
        datos[index] = valor;
    }
    
    int getElemento(size_t index) const {
        if (index >= tamaño) {
            throw out_of_range("Indice fuera de rango");
        }
        return datos[index];
    }
    
    void mostrar() const {
        cout << "Elementos: ";
        for (size_t i = 0; i < tamaño; i++) {
            cout << datos[i] << " ";
        }
        cout << endl;
    }
    
    size_t getTamaño() const { return tamaño; }
};

void funcionPeligrosa() {
    cout << "\n=== Funcion que puede lanzar excepciones ===" << endl;
    
    try {
        RecursoSeguro recurso(5);
        
        // Operaciones normales
        recurso.setElemento(0, 10);
        recurso.setElemento(1, 20);
        recurso.setElemento(2, 30);
        
        recurso.mostrar();
        
        // Esto causara una excepcion
        cout << "Intentando acceder a indice invalido..." << endl;
        recurso.setElemento(10, 40); // Fuera de rango
        
    } catch (out_of_range& e) {
        cout << "Excepcion capturada: " << e.what() << endl;
    } catch (invalid_argument& e) {
        cout << "Argumento invalido: " << e.what() << endl;
    } catch (bad_alloc& e) {
        cout << "Error de memoria: " << e.what() << endl;
    }
    
    cout << "Funcion terminada (el destructor se llama automaticamente)" << endl;
}

void demoSmart Pointers() {
    cout << "\n=== Smart Pointers para manejo seguro ===" << endl;
    
    try {
        // Usar smart pointers para evitar memory leaks
        auto recurso = make_unique<RecursoSeguro>(3);
        
        recurso->setElemento(0, 100);
        recurso->setElemento(1, 200);
        recurso->setElemento(2, 300);
        
        recurso->mostrar();
        
        // Simular excepcion
        throw runtime_error("Error simulado");
        
    } catch (exception& e) {
        cout << "Excepcion: " << e.what() << endl;
        cout << "Smart pointer se encarga de la liberacion automatica" << endl;
    }
}

int main() {
    cout << "=== MANEJO DE EXCEPCIONES CON MEMORIA ===" << endl;
    
    funcionPeligrosa();
    demoSmartPointers();
    
    cout << "\nPrograma terminado exitosamente" << endl;
    
    return 0;
}

// Codigo 69: Punteros a Estructuras
#include <iostream>
#include <string>
#include <vector>
using namespace std;

struct Estudiante {
    string nombre;
    int edad;
    float promedio;
    vector<float> calificaciones;
};

struct Nodo {
    int dato;
    Nodo* siguiente;
    
    Nodo(int d) : dato(d), siguiente(nullptr) {}
};

class ListaEnlazada {
private:
    Nodo* cabeza;
    
public:
    ListaEnlazada() : cabeza(nullptr) {}
    
    ~ListaEnlazada() {
        while (cabeza != nullptr) {
            Nodo* temp = cabeza;
            cabeza = cabeza->siguiente;
            delete temp;
        }
    }
    
    void agregar(int dato) {
        Nodo* nuevo = new Nodo(dato);
        nuevo->siguiente = cabeza;
        cabeza = nuevo;
    }
    
    void mostrar() {
        Nodo* actual = cabeza;
        cout << "Lista: ";
        while (actual != nullptr) {
            cout << actual->dato << " -> ";
            actual = actual->siguiente;
        }
        cout << "NULL" << endl;
    }
    
    bool buscar(int dato) {
        Nodo* actual = cabeza;
        while (actual != nullptr) {
            if (actual->dato == dato) {
                return true;
            }
            actual = actual->siguiente;
        }
        return false;
    }
    
    void eliminar(int dato) {
        if (cabeza == nullptr) return;
        
        if (cabeza->dato == dato) {
            Nodo* temp = cabeza;
            cabeza = cabeza->siguiente;
            delete temp;
            return;
        }
        
        Nodo* actual = cabeza;
        while (actual->siguiente != nullptr && actual->siguiente->dato != dato) {
            actual = actual->siguiente;
        }
        
        if (actual->siguiente != nullptr) {
            Nodo* temp = actual->siguiente;
            actual->siguiente = actual->siguiente->siguiente;
            delete temp;
        }
    }
};

void demoEstudiante() {
    cout << "=== PUNTEROS A ESTRUCTURAS ===" << endl;
    
    // Crear estudiante dinamicamente
    Estudiante* estudiante = new Estudiante;
    
    cout << "Ingrese datos del estudiante:" << endl;
    cout << "Nombre: ";
    getline(cin, estudiante->nombre);
    cout << "Edad: ";
    cin >> estudiante->edad;
    cout << "Promedio: ";
    cin >> estudiante->promedio;
    
    int numCalif;
    cout << "Numero de calificaciones: ";
    cin >> numCalif;
    
    for (int i = 0; i < numCalif; i++) {
        float calif;
        cout << "Calificacion " << i + 1 << ": ";
        cin >> calif;
        estudiante->calificaciones.push_back(calif);
    }
    
    // Mostrar informacion
    cout << "\nInformacion del estudiante:" << endl;
    cout << "Nombre: " << estudiante->nombre << endl;
    cout << "Edad: " << estudiante->edad << " años" << endl;
    cout << "Promedio: " << estudiante->promedio << endl;
    cout << "Calificaciones: ";
    for (float calif : estudiante->calificaciones) {
        cout << calif << " ";
    }
    cout << endl;
    
    // Liberar memoria
    delete estudiante;
}

void demoListaEnlazada() {
    cout << "\n=== LISTA ENLAZADA ===" << endl;
    
    ListaEnlazada lista;
    int opcion, valor;
    
    do {
        cout << "\n--- MENU LISTA ENLAZADA ---" << endl;
        cout << "1. Agregar elemento" << endl;
        cout << "2. Mostrar lista" << endl;
        cout << "3. Buscar elemento" << endl;
        cout << "4. Eliminar elemento" << endl;
        cout << "0. Salir" << endl;
        cout << "Opcion: ";
        cin >> opcion;
        
        switch (opcion) {
            case 1:
                cout << "Valor a agregar: ";
                cin >> valor;
                lista.agregar(valor);
                cout << "Elemento agregado" << endl;
                break;
                
            case 2:
                lista.mostrar();
                break;
                
            case 3:
                cout << "Valor a buscar: ";
                cin >> valor;
                if (lista.buscar(valor)) {
                    cout << "Elemento encontrado" << endl;
                } else {
                    cout << "Elemento no encontrado" << endl;
                }
                break;
                
            case 4:
                cout << "Valor a eliminar: ";
                cin >> valor;
                lista.eliminar(valor);
                cout << "Elemento eliminado (si existia)" << endl;
                break;
                
            case 0:
                cout << "Saliendo..." << endl;
                break;
                
            default:
                cout << "Opcion invalida" << endl;
        }
    } while (opcion != 0);
}

int main() {
    cout << "=== PUNTEROS A ESTRUCTURAS Y LISTAS ENLAZADAS ===" << endl;
    
    demoEstudiante();
    demoListaEnlazada();
    
    return 0;
}

// Codigo 70: Gestion de Memoria RAII
#include <iostream>
#include <fstream>
#include <string>
#include <memory>
using namespace std;

// Ejemplo de RAII con manejo de archivos
class ManejadorArchivo {
private:
    ofstream archivo;
    string nombreArchivo;
    
public:
    ManejadorArchivo(const string& nombre) : nombreArchivo(nombre) {
        archivo.open(nombreArchivo);
        if (!archivo.is_open()) {
            throw runtime_error("No se pudo abrir el archivo: " + nombreArchivo);
        }
        cout << "Archivo '" << nombreArchivo << "' abierto" << endl;
    }
    
    ~ManejadorArchivo() {
        if (archivo.is_open()) {
            archivo.close();
            cout << "Archivo '" << nombreArchivo << "' cerrado automaticamente" << endl;
        }
    }
    
    void escribir(const string& texto) {
        if (archivo.is_open()) {
            archivo << texto << endl;
        }
    }
    
    bool estaAbierto() const {
        return archivo.is_open();
    }
};

// Ejemplo de RAII con recursos de red (simulado)
class ConexionRed {
private:
    string servidor;
    bool conectado;
    
public:
    ConexionRed(const string& serv) : servidor(serv), conectado(false) {
        // Simular conexion
        cout << "Conectando a " << servidor << "..." << endl;
        conectado = true;
        cout << "Conexion establecida" << endl;
    }
    
    ~ConexionRed() {
        if (conectado) {
            cout << "Desconectando de " << servidor << "..." << endl;
            conectado = false;
            cout << "Conexion cerrada automaticamente" << endl;
        }
    }
    
    void enviarDatos(const string& datos) {
        if (conectado) {
            cout << "Enviando: " << datos << endl;
        }
    }
    
    bool estaConectado() const {
        return conectado;
    }
};

// Funcion que demuestra RAII
void funcionConRAII() {
    cout << "\n=== Funcion que usa RAII ===" << endl;
    
    try {
        // Los recursos se adquieren al crear los objetos
        ManejadorArchivo archivo("test.txt");
        ConexionRed conexion("servidor.ejemplo.com");
        
        // Usar los recursos
        archivo.escribir("Linea 1 del archivo");
        archivo.escribir("Linea 2 del archivo");
        
        conexion.enviarDatos("Datos importantes");
        conexion.enviarDatos("Mas datos");
        
        // Simular una excepcion
        cout << "\nSimulando error..." << endl;
        throw runtime_error("Error simulado");
        
        // Esta linea nunca se ejecutara
        archivo.escribir("Esta linea no se escribira");
        
    } catch (exception& e) {
        cout << "Excepcion capturada: " << e.what() << endl;
        cout << "Los destructores se llamaran automaticamente" << endl;
    }
    
    cout << "Funcion terminada" << endl;
}

// Ejemplo con smart pointers y RAII
void demoSmartPointersRAII() {
    cout << "\n=== Smart Pointers y RAII ===" << endl;
    
    {
        cout << "Creando recursos con smart pointers..." << endl;
        
        auto archivo = make_unique<ManejadorArchivo>("test2.txt");
        auto conexion = make_shared<ConexionRed>("otro-servidor.com");
        
        archivo->escribir("Usando smart pointers");
        conexion->enviarDatos("Datos via smart pointer");
        
        cout << "Saliendo del bloque..." << endl;
        // Los smart pointers se destruyen automaticamente
    }
    
    cout << "Bloque terminado" << endl;
}

int main() {
    cout << "=== GESTION DE MEMORIA CON RAII ===" << endl;
    cout << "RAII = Resource Acquisition Is Initialization" << endl;
    
    funcionConRAII();
    demoSmartPointersRAII();
    
    cout << "\nPrograma principal terminado" << endl;
    
    return 0;
}