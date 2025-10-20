// Codigo 56: Clase Vehiculo
#include <iostream>
#include <string>
using namespace std;

class Vehiculo {
protected:
    string marca;
    string modelo;
    int año;
    
public:
    Vehiculo(string m, string mod, int a) : marca(m), modelo(mod), año(a) {}
    
    virtual void mostrarInfo() {
        cout << "Marca: " << marca << endl;
        cout << "Modelo: " << modelo << endl;
        cout << "Año: " << año << endl;
    }
    
    virtual void arrancar() {
        cout << "El vehiculo esta arrancando..." << endl;
    }
    
    virtual ~Vehiculo() {}
};

class Auto : public Vehiculo {
private:
    int numPuertas;
    
public:
    Auto(string m, string mod, int a, int puertas) 
        : Vehiculo(m, mod, a), numPuertas(puertas) {}
    
    void mostrarInfo() override {
        cout << "=== AUTO ===" << endl;
        Vehiculo::mostrarInfo();
        cout << "Numero de puertas: " << numPuertas << endl;
    }
    
    void arrancar() override {
        cout << "El auto esta arrancando con llave..." << endl;
    }
    
    void abrirMaletero() {
        cout << "Maletero abierto" << endl;
    }
};

class Motocicleta : public Vehiculo {
private:
    int cilindrada;
    
public:
    Motocicleta(string m, string mod, int a, int cc) 
        : Vehiculo(m, mod, a), cilindrada(cc) {}
    
    void mostrarInfo() override {
        cout << "=== MOTOCICLETA ===" << endl;
        Vehiculo::mostrarInfo();
        cout << "Cilindrada: " << cilindrada << " cc" << endl;
    }
    
    void arrancar() override {
        cout << "La motocicleta esta arrancando con kickstart..." << endl;
    }
    
    void hacerWheeli() {
        cout << "Haciendo wheeli!" << endl;
    }
};

int main() {
    Auto miAuto("Toyota", "Camry", 2020, 4);
    Motocicleta miMoto("Honda", "CBR600", 2019, 600);
    
    cout << "Informacion del auto:" << endl;
    miAuto.mostrarInfo();
    miAuto.arrancar();
    miAuto.abrirMaletero();
    
    cout << "\nInformacion de la motocicleta:" << endl;
    miMoto.mostrarInfo();
    miMoto.arrancar();
    miMoto.hacerWheeli();
    
    return 0;
}

// Codigo 57: Sobrecarga de Operadores
#include <iostream>
#include <cmath>
using namespace std;

class Complejo {
private:
    double real;
    double imaginario;
    
public:
    // Constructor
    Complejo(double r = 0, double i = 0) : real(r), imaginario(i) {}
    
    // Sobrecarga del operador +
    Complejo operator+(const Complejo& otro) const {
        return Complejo(real + otro.real, imaginario + otro.imaginario);
    }
    
    // Sobrecarga del operador -
    Complejo operator-(const Complejo& otro) const {
        return Complejo(real - otro.real, imaginario - otro.imaginario);
    }
    
    // Sobrecarga del operador *
    Complejo operator*(const Complejo& otro) const {
        double nuevoReal = real * otro.real - imaginario * otro.imaginario;
        double nuevoImaginario = real * otro.imaginario + imaginario * otro.real;
        return Complejo(nuevoReal, nuevoImaginario);
    }
    
    // Sobrecarga del operador ==
    bool operator==(const Complejo& otro) const {
        return (real == otro.real && imaginario == otro.imaginario);
    }
    
    // Sobrecarga del operador <<
    friend ostream& operator<<(ostream& os, const Complejo& c) {
        if (c.imaginario >= 0) {
            os << c.real << " + " << c.imaginario << "i";
        } else {
            os << c.real << " - " << abs(c.imaginario) << "i";
        }
        return os;
    }
    
    // Sobrecarga del operador >>
    friend istream& operator>>(istream& is, Complejo& c) {
        cout << "Ingrese parte real: ";
        is >> c.real;
        cout << "Ingrese parte imaginaria: ";
        is >> c.imaginario;
        return is;
    }
    
    // Metodo para calcular el modulo
    double modulo() const {
        return sqrt(real * real + imaginario * imaginario);
    }
    
    // Getters
    double getReal() const { return real; }
    double getImaginario() const { return imaginario; }
};

int main() {
    Complejo c1, c2;
    
    cout << "Ingrese el primer numero complejo:" << endl;
    cin >> c1;
    
    cout << "\nIngrese el segundo numero complejo:" << endl;
    cin >> c2;
    
    cout << "\nOperaciones con numeros complejos:" << endl;
    cout << "c1 = " << c1 << endl;
    cout << "c2 = " << c2 << endl;
    
    Complejo suma = c1 + c2;
    Complejo resta = c1 - c2;
    Complejo multiplicacion = c1 * c2;
    
    cout << "\nResultados:" << endl;
    cout << "c1 + c2 = " << suma << endl;
    cout << "c1 - c2 = " << resta << endl;
    cout << "c1 * c2 = " << multiplicacion << endl;
    
    cout << "\nModulos:" << endl;
    cout << "|c1| = " << c1.modulo() << endl;
    cout << "|c2| = " << c2.modulo() << endl;
    
    if (c1 == c2) {
        cout << "\nc1 y c2 son iguales" << endl;
    } else {
        cout << "\nc1 y c2 son diferentes" << endl;
    }
    
    return 0;
}

// Codigo 58: Constructor y Destructor
#include <iostream>
#include <string>
using namespace std;

class Recurso {
private:
    string nombre;
    int* datos;
    int tamaño;
    
public:
    // Constructor por defecto
    Recurso() {
        nombre = "Recurso por defecto";
        tamaño = 10;
        datos = new int[tamaño];
        for (int i = 0; i < tamaño; i++) {
            datos[i] = i;
        }
        cout << "Constructor por defecto llamado para " << nombre << endl;
    }
    
    // Constructor parametrizado
    Recurso(const string& n, int t) {
        nombre = n;
        tamaño = t;
        datos = new int[tamaño];
        for (int i = 0; i < tamaño; i++) {
            datos[i] = i * 2;
        }
        cout << "Constructor parametrizado llamado para " << nombre << endl;
    }
    
    // Constructor de copia
    Recurso(const Recurso& otro) {
        nombre = otro.nombre + " (copia)";
        tamaño = otro.tamaño;
        datos = new int[tamaño];
        for (int i = 0; i < tamaño; i++) {
            datos[i] = otro.datos[i];
        }
        cout << "Constructor de copia llamado para " << nombre << endl;
    }
    
    // Destructor
    ~Recurso() {
        cout << "Destructor llamado para " << nombre << endl;
        delete[] datos;
    }
    
    // Metodo para mostrar informacion
    void mostrarInfo() {
        cout << "Recurso: " << nombre << ", Tamaño: " << tamaño << endl;
        cout << "Datos: ";
        for (int i = 0; i < min(5, tamaño); i++) {
            cout << datos[i] << " ";
        }
        if (tamaño > 5) cout << "...";
        cout << endl;
    }
    
    // Operador de asignacion
    Recurso& operator=(const Recurso& otro) {
        if (this != &otro) {
            delete[] datos;
            
            nombre = otro.nombre + " (asignado)";
            tamaño = otro.tamaño;
            datos = new int[tamaño];
            for (int i = 0; i < tamaño; i++) {
                datos[i] = otro.datos[i];
            }
            cout << "Operador de asignacion llamado para " << nombre << endl;
        }
        return *this;
    }
};

void funcionQueUsaRecurso() {
    cout << "\n--- Dentro de funcionQueUsaRecurso ---" << endl;
    Recurso r3("Recurso local", 5);
    r3.mostrarInfo();
    cout << "--- Saliendo de funcionQueUsaRecurso ---" << endl;
}

int main() {
    cout << "=== DEMOSTRACION DE CONSTRUCTORES Y DESTRUCTORES ===" << endl;
    
    cout << "\n1. Creando recurso con constructor por defecto:" << endl;
    Recurso r1;
    r1.mostrarInfo();
    
    cout << "\n2. Creando recurso con constructor parametrizado:" << endl;
    Recurso r2("Mi Recurso", 8);
    r2.mostrarInfo();
    
    cout << "\n3. Creando recurso con constructor de copia:" << endl;
    Recurso r4 = r2;
    r4.mostrarInfo();
    
    cout << "\n4. Usando operador de asignacion:" << endl;
    r1 = r2;
    r1.mostrarInfo();
    
    cout << "\n5. Llamando funcion que crea recurso local:" << endl;
    funcionQueUsaRecurso();
    
    cout << "\n6. Fin del programa (se llamaran destructores):" << endl;
    
    return 0;
}

// Codigo 59: Clase Template
#include <iostream>
#include <vector>
using namespace std;

template<typename T>
class Pila {
private:
    vector<T> elementos;
    
public:
    // Constructor
    Pila() {}
    
    // Agregar elemento a la pila
    void push(const T& elemento) {
        elementos.push_back(elemento);
    }
    
    // Remover y retornar el elemento superior
    T pop() {
        if (estaVacia()) {
            throw runtime_error("Pila vacia");
        }
        T elemento = elementos.back();
        elementos.pop_back();
        return elemento;
    }
    
    // Ver el elemento superior sin removerlo
    T top() const {
        if (estaVacia()) {
            throw runtime_error("Pila vacia");
        }
        return elementos.back();
    }
    
    // Verificar si la pila esta vacia
    bool estaVacia() const {
        return elementos.empty();
    }
    
    // Obtener el tamaño de la pila
    size_t tamaño() const {
        return elementos.size();
    }
    
    // Mostrar todos los elementos
    void mostrar() const {
        if (estaVacia()) {
            cout << "Pila vacia" << endl;
            return;
        }
        
        cout << "Elementos en la pila (desde el top): ";
        for (int i = elementos.size() - 1; i >= 0; i--) {
            cout << elementos[i] << " ";
        }
        cout << endl;
    }
};

int main() {
    cout << "=== DEMOSTRACION DE PILA TEMPLATE ===" << endl;
    
    // Pila de enteros
    cout << "\n1. Pila de enteros:" << endl;
    Pila<int> pilaInt;
    
    pilaInt.push(10);
    pilaInt.push(20);
    pilaInt.push(30);
    pilaInt.mostrar();
    
    cout << "Top: " << pilaInt.top() << endl;
    cout << "Pop: " << pilaInt.pop() << endl;
    pilaInt.mostrar();
    
    // Pila de strings
    cout << "\n2. Pila de strings:" << endl;
    Pila<string> pilaString;
    
    pilaString.push("Hola");
    pilaString.push("Mundo");
    pilaString.push("C++");
    pilaString.mostrar();
    
    cout << "Tamaño: " << pilaString.tamaño() << endl;
    
    // Pila de doubles
    cout << "\n3. Pila de doubles:" << endl;
    Pila<double> pilaDouble;
    
    pilaDouble.push(3.14);
    pilaDouble.push(2.71);
    pilaDouble.push(1.41);
    pilaDouble.mostrar();
    
    // Vaciar la pila
    cout << "\n4. Vaciando pila de doubles:" << endl;
    while (!pilaDouble.estaVacia()) {
        cout << "Removiendo: " << pilaDouble.pop() << endl;
    }
    pilaDouble.mostrar();
    
    return 0;
}

// Codigo 60: Encapsulacion
#include <iostream>
#include <string>
using namespace std;

class Persona {
private:
    string nombre;
    int edad;
    double salario;
    string email;
    
    // Metodos privados de validacion
    bool validarEdad(int e) {
        return e >= 0 && e <= 150;
    }
    
    bool validarSalario(double s) {
        return s >= 0;
    }
    
    bool validarEmail(const string& e) {
        return e.find('@') != string::npos;
    }
    
public:
    // Constructor
    Persona(const string& n, int e, double s, const string& email) {
        setNombre(n);
        setEdad(e);
        setSalario(s);
        setEmail(email);
    }
    
    // Getters
    string getNombre() const {
        return nombre;
    }
    
    int getEdad() const {
        return edad;
    }
    
    double getSalario() const {
        return salario;
    }
    
    string getEmail() const {
        return email;
    }
    
    // Setters con validacion
    void setNombre(const string& n) {
        if (!n.empty()) {
            nombre = n;
        } else {
            cout << "Error: El nombre no puede estar vacio" << endl;
        }
    }
    
    void setEdad(int e) {
        if (validarEdad(e)) {
            edad = e;
        } else {
            cout << "Error: Edad invalida (0-150)" << endl;
        }
    }
    
    void setSalario(double s) {
        if (validarSalario(s)) {
            salario = s;
        } else {
            cout << "Error: Salario no puede ser negativo" << endl;
        }
    }
    
    void setEmail(const string& e) {
        if (validarEmail(e)) {
            email = e;
        } else {
            cout << "Error: Email invalido (debe contener @)" << endl;
        }
    }
    
    // Metodos publicos
    void mostrarInfo() const {
        cout << "=== INFORMACION PERSONAL ===" << endl;
        cout << "Nombre: " << nombre << endl;
        cout << "Edad: " << edad << " años" << endl;
        cout << "Salario: $" << salario << endl;
        cout << "Email: " << email << endl;
    }
    
    void darAumento(double porcentaje) {
        if (porcentaje > 0) {
            salario = salario * (1 + porcentaje / 100);
            cout << "Aumento del " << porcentaje << "% aplicado" << endl;
        } else {
            cout << "Error: Porcentaje debe ser positivo" << endl;
        }
    }
    
    void cumplirAños() {
        edad++;
        cout << "Feliz cumple! Ahora tienes " << edad << " años" << endl;
    }
};

int main() {
    cout << "=== DEMOSTRACION DE ENCAPSULACION ===" << endl;
    
    // Crear persona
    Persona persona("Juan Perez", 30, 50000, "juan@email.com");
    persona.mostrarInfo();
    
    cout << "\n--- Modificando datos ---" << endl;
    
    // Intentar modificar con datos validos
    persona.setEdad(31);
    persona.setSalario(55000);
    persona.setEmail("juan.perez@empresa.com");
    
    cout << "\nDatos actualizados:" << endl;
    persona.mostrarInfo();
    
    cout << "\n--- Intentando modificar con datos invalidos ---" << endl;
    
    // Intentar modificar con datos invalidos
    persona.setEdad(-5);        // Edad invalida
    persona.setSalario(-1000);  // Salario invalido
    persona.setEmail("email_sin_arroba"); // Email invalido
    persona.setNombre("");      // Nombre vacio
    
    cout << "\nDatos despues de intentos invalidos:" << endl;
    persona.mostrarInfo();
    
    cout << "\n--- Usando metodos publicos ---" << endl;
    persona.darAumento(10);
    persona.cumplirAños();
    
    cout << "\nDatos finales:" << endl;
    persona.mostrarInfo();
    
    return 0;
}