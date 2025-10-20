// Codigo 51: Clase Rectangulo
#include <iostream>
using namespace std;

class Rectangulo {
private:
    double base;
    double altura;
    
public:
    // Constructor
    Rectangulo(double b, double a) : base(b), altura(a) {}
    
    // Metodos para calcular area y perimetro
    double calcularArea() {
        return base * altura;
    }
    
    double calcularPerimetro() {
        return 2 * (base + altura);
    }
    
    // Getters
    double getBase() { return base; }
    double getAltura() { return altura; }
    
    // Setters
    void setBase(double b) { base = b; }
    void setAltura(double a) { altura = a; }
};

int main() {
    double base, altura;
    
    cout << "Ingrese la base del rectangulo: ";
    cin >> base;
    cout << "Ingrese la altura del rectangulo: ";
    cin >> altura;
    
    Rectangulo rect(base, altura);
    
    cout << "\nDatos del rectangulo:" << endl;
    cout << "Base: " << rect.getBase() << endl;
    cout << "Altura: " << rect.getAltura() << endl;
    cout << "Area: " << rect.calcularArea() << endl;
    cout << "Perimetro: " << rect.calcularPerimetro() << endl;
    
    return 0;
}

// Codigo 52: Clase Estudiante
#include <iostream>
#include <string>
#include <vector>
using namespace std;

class Estudiante {
private:
    string nombre;
    int edad;
    vector<double> calificaciones;
    
public:
    // Constructor
    Estudiante(string n, int e) : nombre(n), edad(e) {}
    
    // Metodos para agregar calificaciones
    void agregarCalificacion(double calificacion) {
        calificaciones.push_back(calificacion);
    }
    
    // Calcular promedio
    double calcularPromedio() {
        if (calificaciones.empty()) return 0.0;
        
        double suma = 0.0;
        for (double cal : calificaciones) {
            suma += cal;
        }
        return suma / calificaciones.size();
    }
    
    // Mostrar información
    void mostrarInfo() {
        cout << "Nombre: " << nombre << endl;
        cout << "Edad: " << edad << endl;
        cout << "Calificaciones: ";
        for (double cal : calificaciones) {
            cout << cal << " ";
        }
        cout << endl;
        cout << "Promedio: " << calcularPromedio() << endl;
    }
    
    // Getters
    string getNombre() { return nombre; }
    int getEdad() { return edad; }
};

int main() {
    string nombre;
    int edad, numCalificaciones;
    double calificacion;
    
    cout << "Ingrese nombre del estudiante: ";
    getline(cin, nombre);
    cout << "Ingrese edad: ";
    cin >> edad;
    
    Estudiante estudiante(nombre, edad);
    
    cout << "Ingrese numero de calificaciones: ";
    cin >> numCalificaciones;
    
    for (int i = 0; i < numCalificaciones; i++) {
        cout << "Calificacion " << i + 1 << ": ";
        cin >> calificacion;
        estudiante.agregarCalificacion(calificacion);
    }
    
    cout << "\nInformacion del estudiante:" << endl;
    estudiante.mostrarInfo();
    
    return 0;
}

// Codigo 53: Clase Cuenta Bancaria
#include <iostream>
#include <string>
using namespace std;

class CuentaBancaria {
private:
    string numeroCuenta;
    string titular;
    double saldo;
    
public:
    // Constructor
    CuentaBancaria(string numero, string nombre, double saldoInicial = 0.0) 
        : numeroCuenta(numero), titular(nombre), saldo(saldoInicial) {}
    
    // Metodo para depositar
    void depositar(double cantidad) {
        if (cantidad > 0) {
            saldo += cantidad;
            cout << "Deposito realizado. Nuevo saldo: $" << saldo << endl;
        } else {
            cout << "Cantidad invalida para deposito" << endl;
        }
    }
    
    // Metodo para retirar
    void retirar(double cantidad) {
        if (cantidad > 0 && cantidad <= saldo) {
            saldo -= cantidad;
            cout << "Retiro realizado. Nuevo saldo: $" << saldo << endl;
        } else if (cantidad > saldo) {
            cout << "Fondos insuficientes" << endl;
        } else {
            cout << "Cantidad invalida para retiro" << endl;
        }
    }
    
    // Consultar saldo
    double consultarSaldo() {
        return saldo;
    }
    
    // Mostrar información de la cuenta
    void mostrarInfo() {
        cout << "Numero de cuenta: " << numeroCuenta << endl;
        cout << "Titular: " << titular << endl;
        cout << "Saldo actual: $" << saldo << endl;
    }
};

int main() {
    string numero, titular;
    double saldoInicial;
    int opcion;
    double cantidad;
    
    cout << "Ingrese numero de cuenta: ";
    cin >> numero;
    cin.ignore(); // Limpiar buffer
    cout << "Ingrese nombre del titular: ";
    getline(cin, titular);
    cout << "Ingrese saldo inicial: $";
    cin >> saldoInicial;
    
    CuentaBancaria cuenta(numero, titular, saldoInicial);
    
    do {
        cout << "\n=== MENU BANCARIO ===" << endl;
        cout << "1. Depositar" << endl;
        cout << "2. Retirar" << endl;
        cout << "3. Consultar saldo" << endl;
        cout << "4. Mostrar informacion" << endl;
        cout << "0. Salir" << endl;
        cout << "Opcion: ";
        cin >> opcion;
        
        switch (opcion) {
            case 1:
                cout << "Cantidad a depositar: $";
                cin >> cantidad;
                cuenta.depositar(cantidad);
                break;
            case 2:
                cout << "Cantidad a retirar: $";
                cin >> cantidad;
                cuenta.retirar(cantidad);
                break;
            case 3:
                cout << "Saldo actual: $" << cuenta.consultarSaldo() << endl;
                break;
            case 4:
                cuenta.mostrarInfo();
                break;
            case 0:
                cout << "Gracias por usar nuestros servicios" << endl;
                break;
            default:
                cout << "Opcion invalida" << endl;
        }
    } while (opcion != 0);
    
    return 0;
}

// Codigo 54: Herencia - Figuras Geometricas
#include <iostream>
#include <cmath>
using namespace std;

class Figura {
protected:
    string nombre;
    
public:
    Figura(string n) : nombre(n) {}
    
    virtual double calcularArea() = 0;
    virtual double calcularPerimetro() = 0;
    
    string getNombre() { return nombre; }
    
    virtual void mostrarInfo() {
        cout << "Figura: " << nombre << endl;
        cout << "Area: " << calcularArea() << endl;
        cout << "Perimetro: " << calcularPerimetro() << endl;
    }
};

class Circulo : public Figura {
private:
    double radio;
    const double PI = 3.14159265359;
    
public:
    Circulo(double r) : Figura("Circulo"), radio(r) {}
    
    double calcularArea() override {
        return PI * radio * radio;
    }
    
    double calcularPerimetro() override {
        return 2 * PI * radio;
    }
};

class Rectangulo : public Figura {
private:
    double base, altura;
    
public:
    Rectangulo(double b, double a) : Figura("Rectangulo"), base(b), altura(a) {}
    
    double calcularArea() override {
        return base * altura;
    }
    
    double calcularPerimetro() override {
        return 2 * (base + altura);
    }
};

class Triangulo : public Figura {
private:
    double lado1, lado2, lado3;
    
public:
    Triangulo(double l1, double l2, double l3) 
        : Figura("Triangulo"), lado1(l1), lado2(l2), lado3(l3) {}
    
    double calcularArea() override {
        // Formula de Heron
        double s = (lado1 + lado2 + lado3) / 2;
        return sqrt(s * (s - lado1) * (s - lado2) * (s - lado3));
    }
    
    double calcularPerimetro() override {
        return lado1 + lado2 + lado3;
    }
};

int main() {
    int opcion;
    
    cout << "Seleccione una figura:" << endl;
    cout << "1. Circulo" << endl;
    cout << "2. Rectangulo" << endl;
    cout << "3. Triangulo" << endl;
    cout << "Opcion: ";
    cin >> opcion;
    
    Figura* figura = nullptr;
    
    switch (opcion) {
        case 1: {
            double radio;
            cout << "Ingrese el radio: ";
            cin >> radio;
            figura = new Circulo(radio);
            break;
        }
        case 2: {
            double base, altura;
            cout << "Ingrese base y altura: ";
            cin >> base >> altura;
            figura = new Rectangulo(base, altura);
            break;
        }
        case 3: {
            double l1, l2, l3;
            cout << "Ingrese los tres lados: ";
            cin >> l1 >> l2 >> l3;
            figura = new Triangulo(l1, l2, l3);
            break;
        }
        default:
            cout << "Opcion invalida" << endl;
            return 1;
    }
    
    cout << "\nInformacion de la figura:" << endl;
    figura->mostrarInfo();
    
    delete figura;
    return 0;
}

// Codigo 55: Polimorfismo
#include <iostream>
#include <vector>
#include <memory>
using namespace std;

// Reutilizamos las clases del ejemplo anterior
class Figura {
protected:
    string nombre;
    
public:
    Figura(string n) : nombre(n) {}
    virtual ~Figura() {}
    
    virtual double calcularArea() = 0;
    virtual double calcularPerimetro() = 0;
    
    string getNombre() { return nombre; }
    
    virtual void mostrarInfo() {
        cout << "Figura: " << nombre << endl;
        cout << "Area: " << calcularArea() << endl;
        cout << "Perimetro: " << calcularPerimetro() << endl;
    }
};

class Circulo : public Figura {
private:
    double radio;
    const double PI = 3.14159265359;
    
public:
    Circulo(double r) : Figura("Circulo"), radio(r) {}
    
    double calcularArea() override {
        return PI * radio * radio;
    }
    
    double calcularPerimetro() override {
        return 2 * PI * radio;
    }
};

class Rectangulo : public Figura {
private:
    double base, altura;
    
public:
    Rectangulo(double b, double a) : Figura("Rectangulo"), base(b), altura(a) {}
    
    double calcularArea() override {
        return base * altura;
    }
    
    double calcularPerimetro() override {
        return 2 * (base + altura);
    }
};

int main() {
    vector<unique_ptr<Figura>> figuras;
    
    // Crear diferentes figuras
    figuras.push_back(make_unique<Circulo>(5.0));
    figuras.push_back(make_unique<Rectangulo>(4.0, 6.0));
    figuras.push_back(make_unique<Circulo>(3.0));
    figuras.push_back(make_unique<Rectangulo>(2.5, 8.0));
    
    cout << "Informacion de todas las figuras:" << endl;
    cout << "==================================" << endl;
    
    double areaTotal = 0.0;
    double perimetroTotal = 0.0;
    
    for (int i = 0; i < figuras.size(); i++) {
        cout << "\nFigura " << i + 1 << ":" << endl;
        figuras[i]->mostrarInfo();
        
        areaTotal += figuras[i]->calcularArea();
        perimetroTotal += figuras[i]->calcularPerimetro();
    }
    
    cout << "\n==================================" << endl;
    cout << "Area total de todas las figuras: " << areaTotal << endl;
    cout << "Perimetro total de todas las figuras: " << perimetroTotal << endl;
    
    return 0;
}