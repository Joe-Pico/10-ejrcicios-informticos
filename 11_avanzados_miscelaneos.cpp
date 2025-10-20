// Codigo 91: Multithreading Basico
#include <iostream>
#include <thread>
#include <mutex>
#include <vector>
#include <chrono>
using namespace std;

mutex mtx;
int contador_global = 0;

void incrementar(int id, int incrementos) {
    for (int i = 0; i < incrementos; i++) {
        {
            lock_guard<mutex> lock(mtx);
            contador_global++;
            cout << "Hilo " << id << " incremento contador a: " << contador_global << endl;
        }
        this_thread::sleep_for(chrono::milliseconds(10));
    }
}

void trabajador(int id, int duracion) {
    cout << "Hilo " << id << " iniciado" << endl;
    this_thread::sleep_for(chrono::seconds(duracion));
    cout << "Hilo " << id << " terminado" << endl;
}

int main() {
    cout << "=== MULTITHREADING BASICO ===" << endl;
    
    // Crear multiples hilos
    cout << "\n--- Multiples Hilos Simples ---" << endl;
    
    vector<thread> hilos;
    
    for (int i = 1; i <= 3; i++) {
        hilos.emplace_back(trabajador, i, i);
    }
    
    // Esperar a que todos terminen
    for (auto& hilo : hilos) {
        hilo.join();
    }
    
    cout << "Todos los hilos simples terminaron" << endl;
    
    // Hilos con mutex
    cout << "\n--- Hilos con Mutex ---" << endl;
    
    vector<thread> hilos_mutex;
    
    for (int i = 1; i <= 3; i++) {
        hilos_mutex.emplace_back(incrementar, i, 5);
    }
    
    for (auto& hilo : hilos_mutex) {
        hilo.join();
    }
    
    cout << "Contador final: " << contador_global << endl;
    
    // Obtener info del hardware
    cout << "\n--- Informacion del Hardware ---" << endl;
    cout << "Hilos de hardware disponibles: " << thread::hardware_concurrency() << endl;
    
    return 0;
}

// Codigo 92: Manejo de Archivos Avanzado
#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <vector>
#include <iomanip>
using namespace std;

struct Estudiante {
    string nombre;
    int edad;
    double promedio;
    
    Estudiante() = default;
    Estudiante(const string& n, int e, double p) : nombre(n), edad(e), promedio(p) {}
};

class ManejadorArchivos {
public:
    static void escribirTexto(const string& archivo, const vector<string>& lineas) {
        ofstream file(archivo);
        if (!file.is_open()) {
            throw runtime_error("No se pudo abrir el archivo para escritura: " + archivo);
        }
        
        for (const auto& linea : lineas) {
            file << linea << endl;
        }
        
        cout << "Archivo de texto escrito: " << archivo << endl;
    }
    
    static vector<string> leerTexto(const string& archivo) {
        ifstream file(archivo);
        if (!file.is_open()) {
            throw runtime_error("No se pudo abrir el archivo para lectura: " + archivo);
        }
        
        vector<string> lineas;
        string linea;
        
        while (getline(file, linea)) {
            lineas.push_back(linea);
        }
        
        cout << "Archivo de texto leido: " << archivo << " (" << lineas.size() << " lineas)" << endl;
        return lineas;
    }
    
    static void escribirCSV(const string& archivo, const vector<Estudiante>& estudiantes) {
        ofstream file(archivo);
        if (!file.is_open()) {
            throw runtime_error("No se pudo crear CSV: " + archivo);
        }
        
        // Encabezados
        file << "Nombre,Edad,Promedio" << endl;
        
        // Datos
        for (const auto& est : estudiantes) {
            file << est.nombre << "," << est.edad << "," << fixed << setprecision(2) << est.promedio << endl;
        }
        
        cout << "Archivo CSV escrito: " << archivo << endl;
    }
    
    static vector<Estudiante> leerCSV(const string& archivo) {
        ifstream file(archivo);
        if (!file.is_open()) {
            throw runtime_error("No se pudo leer CSV: " + archivo);
        }
        
        vector<Estudiante> estudiantes;
        string linea;
        
        // Saltar encabezados
        getline(file, linea);
        
        while (getline(file, linea)) {
            stringstream ss(linea);
            string nombre, edad_str, promedio_str;
            
            getline(ss, nombre, ',');
            getline(ss, edad_str, ',');
            getline(ss, promedio_str);
            
            if (!nombre.empty() && !edad_str.empty() && !promedio_str.empty()) {
                estudiantes.emplace_back(nombre, stoi(edad_str), stod(promedio_str));
            }
        }
        
        cout << "CSV leido: " << archivo << " (" << estudiantes.size() << " estudiantes)" << endl;
        return estudiantes;
    }
    
    static void escribirBinario(const string& archivo, const vector<int>& datos) {
        ofstream file(archivo, ios::binary);
        if (!file.is_open()) {
            throw runtime_error("No se pudo crear archivo binario: " + archivo);
        }
        
        size_t tamano = datos.size();
        file.write(reinterpret_cast<const char*>(&tamano), sizeof(tamano));
        file.write(reinterpret_cast<const char*>(datos.data()), tamano * sizeof(int));
        
        cout << "Archivo binario escrito: " << archivo << " (" << tamano << " enteros)" << endl;
    }
    
    static vector<int> leerBinario(const string& archivo) {
        ifstream file(archivo, ios::binary);
        if (!file.is_open()) {
            throw runtime_error("No se pudo leer archivo binario: " + archivo);
        }
        
        size_t tamano;
        file.read(reinterpret_cast<char*>(&tamano), sizeof(tamano));
        
        vector<int> datos(tamano);
        file.read(reinterpret_cast<char*>(datos.data()), tamano * sizeof(int));
        
        cout << "Archivo binario leido: " << archivo << " (" << tamano << " enteros)" << endl;
        return datos;
    }
    
    static void analizarArchivo(const string& archivo) {
        ifstream file(archivo, ios::ate | ios::binary);
        if (!file.is_open()) {
            cout << "No se pudo analizar: " << archivo << endl;
            return;
        }
        
        auto tamano = file.tellg();
        file.seekg(0);
        
        cout << "\nAnalisis de archivo: " << archivo << endl;
        cout << "Tamaño: " << tamano << " bytes" << endl;
        
        if (tamano > 0) {
            string contenido((istreambuf_iterator<char>(file)), istreambuf_iterator<char>());
            
            int lineas = count(contenido.begin(), contenido.end(), '\n') + 1;
            int palabras = 0;
            stringstream ss(contenido);
            string palabra;
            
            while (ss >> palabra) {
                palabras++;
            }
            
            cout << "Lineas: " << lineas << endl;
            cout << "Palabras: " << palabras << endl;
            cout << "Caracteres: " << contenido.length() << endl;
        }
    }
};

int main() {
    cout << "=== MANEJO DE ARCHIVOS AVANZADO ===" << endl;
    
    try {
        // Archivos de texto
        cout << "\n--- Archivos de Texto ---" << endl;
        vector<string> lineas = {
            "Esta es la primera linea",
            "Segunda linea del archivo",
            "Tercera linea con mas contenido",
            "Ultima linea del ejemplo"
        };
        
        ManejadorArchivos::escribirTexto("ejemplo.txt", lineas);
        auto lineas_leidas = ManejadorArchivos::leerTexto("ejemplo.txt");
        
        cout << "Contenido leido:" << endl;
        for (const auto& linea : lineas_leidas) {
            cout << "  " << linea << endl;
        }
        
        // Archivos CSV
        cout << "\n--- Archivos CSV ---" << endl;
        vector<Estudiante> estudiantes = {
            {"Ana Garcia", 20, 8.5},
            {"Carlos Lopez", 22, 7.8},
            {"Diana Martinez", 19, 9.2},
            {"Eduardo Ruiz", 21, 6.9}
        };
        
        ManejadorArchivos::escribirCSV("estudiantes.csv", estudiantes);
        auto estudiantes_leidos = ManejadorArchivos::leerCSV("estudiantes.csv");
        
        cout << "Estudiantes leidos:" << endl;
        for (const auto& est : estudiantes_leidos) {
            cout << "  " << est.nombre << " (" << est.edad << " años) - Promedio: " << est.promedio << endl;
        }
        
        // Archivos binarios
        cout << "\n--- Archivos Binarios ---" << endl;
        vector<int> datos_binarios = {1, 2, 3, 4, 5, 100, 200, 300, 400, 500};
        
        ManejadorArchivos::escribirBinario("datos.bin", datos_binarios);
        auto datos_leidos = ManejadorArchivos::leerBinario("datos.bin");
        
        cout << "Datos binarios leidos: ";
        for (int dato : datos_leidos) {
            cout << dato << " ";
        }
        cout << endl;
        
        // Analisis de archivos
        cout << "\n--- Analisis de Archivos ---" << endl;
        ManejadorArchivos::analizarArchivo("ejemplo.txt");
        ManejadorArchivos::analizarArchivo("estudiantes.csv");
        
    } catch (const exception& e) {
        cout << "Error: " << e.what() << endl;
    }
    
    return 0;
}

// Codigo 93: Templates Avanzados y Metaprogramacion
#include <iostream>
#include <type_traits>
#include <string>
#include <vector>
using namespace std;

// Template de funcion basico
template<typename T>
T maximo(T a, T b) {
    return (a > b) ? a : b;
}

// Template especializado
template<>
const char* maximo<const char*>(const char* a, const char* b) {
    return (strcmp(a, b) > 0) ? a : b;
}

// Template de clase con multiples parametros
template<typename T, int TAMAÑO>
class Array {
private:
    T datos[TAMAÑO];
    
public:
    Array() {
        for (int i = 0; i < TAMAÑO; i++) {
            datos[i] = T{}; // Inicializacion por defecto
        }
    }
    
    T& operator[](int index) {
        if (index >= 0 && index < TAMAÑO) {
            return datos[index];
        }
        throw out_of_range("Indice fuera de rango");
    }
    
    const T& operator[](int index) const {
        if (index >= 0 && index < TAMAÑO) {
            return datos[index];
        }
        throw out_of_range("Indice fuera de rango");
    }
    
    constexpr int size() const { return TAMAÑO; }
    
    void llenar(const T& valor) {
        for (int i = 0; i < TAMAÑO; i++) {
            datos[i] = valor;
        }
    }
    
    void mostrar() const {
        cout << "Array[" << TAMAÑO << "]: ";
        for (int i = 0; i < TAMAÑO; i++) {
            cout << datos[i] << " ";
        }
        cout << endl;
    }
};

// Template variadic
template<typename T>
void imprimir(T&& valor) {
    cout << valor << endl;
}

template<typename T, typename... Args>
void imprimir(T&& primero, Args&&... resto) {
    cout << primero << " ";
    imprimir(resto...);
}

// SFINAE (Substitution Failure Is Not An Error)
template<typename T>
typename enable_if<is_integral<T>::value, T>::type
factorial(T n) {
    if (n <= 1) return 1;
    return n * factorial(n - 1);
}

template<typename T>
typename enable_if<is_floating_point<T>::value, T>::type
factorial(T n) {
    // Version especializada para flotantes
    return gamma(n + 1); // Requiere <cmath> y libreria matematica
}

// Type traits personalizados
template<typename T>
struct es_string : false_type {};

template<>
struct es_string<string> : true_type {};

template<>
struct es_string<const char*> : true_type {};

// Template con enable_if personalizado
template<typename T>
typename enable_if<es_string<T>::value, void>::type
procesar_string(const T& str) {
    cout << "Procesando string: " << str << endl;
}

template<typename T>
typename enable_if<!es_string<T>::value, void>::type
procesar_string(const T& valor) {
    cout << "Procesando no-string: " << valor << endl;
}

// Template recursivo para calcular potencias en tiempo de compilacion
template<int base, int exponente>
struct Potencia {
    static constexpr int valor = base * Potencia<base, exponente - 1>::valor;
};

template<int base>
struct Potencia<base, 0> {
    static constexpr int valor = 1;
};

// Perfect forwarding
template<typename Func, typename... Args>
auto ejecutar_funcion(Func&& func, Args&&... args) -> decltype(func(forward<Args>(args)...)) {
    cout << "Ejecutando funcion..." << endl;
    return func(forward<Args>(args)...);
}

// Funcion de ejemplo para perfect forwarding
int sumar(int a, int b) {
    return a + b;
}

string concatenar(const string& a, const string& b) {
    return a + b;
}

int main() {
    cout << "=== TEMPLATES AVANZADOS Y METAPROGRAMACION ===" << endl;
    
    // Templates basicos
    cout << "\n--- Templates Basicos ---" << endl;
    cout << "Maximo de 10 y 20: " << maximo(10, 20) << endl;
    cout << "Maximo de 3.14 y 2.71: " << maximo(3.14, 2.71) << endl;
    cout << "Maximo de strings: " << maximo(string("abc"), string("xyz")) << endl;
    
    // Template de clase
    cout << "\n--- Template de Clase ---" << endl;
    Array<int, 5> arr_int;
    arr_int.llenar(42);
    arr_int[2] = 100;
    arr_int.mostrar();
    
    Array<string, 3> arr_string;
    arr_string[0] = "Hola";
    arr_string[1] = "Mundo";
    arr_string[2] = "C++";
    arr_string.mostrar();
    
    // Templates variadicos
    cout << "\n--- Templates Variadicos ---" << endl;
    imprimir("Hola", "mundo", 42, 3.14, "C++");
    
    // SFINAE y type traits
    cout << "\n--- SFINAE y Type Traits ---" << endl;
    cout << "Factorial de 5: " << factorial(5) << endl;
    
    cout << "es_string<string>: " << es_string<string>::value << endl;
    cout << "es_string<int>: " << es_string<int>::value << endl;
    cout << "es_string<const char*>: " << es_string<const char*>::value << endl;
    
    procesar_string(string("Hola mundo"));
    procesar_string(42);
    
    // Metaprogramacion en tiempo de compilacion
    cout << "\n--- Metaprogramacion en Tiempo de Compilacion ---" << endl;
    cout << "2^8 = " << Potencia<2, 8>::valor << endl;
    cout << "3^4 = " << Potencia<3, 4>::valor << endl;
    cout << "5^3 = " << Potencia<5, 3>::valor << endl;
    
    // Perfect forwarding
    cout << "\n--- Perfect Forwarding ---" << endl;
    int resultado_suma = ejecutar_funcion(sumar, 10, 20);
    cout << "Resultado suma: " << resultado_suma << endl;
    
    string resultado_concat = ejecutar_funcion(concatenar, string("Hola "), string("mundo"));
    cout << "Resultado concatenacion: " << resultado_concat << endl;
    
    // Type traits de la biblioteca estandar
    cout << "\n--- Type Traits de la Biblioteca Estandar ---" << endl;
    cout << "is_integral<int>: " << is_integral<int>::value << endl;
    cout << "is_floating_point<double>: " << is_floating_point<double>::value << endl;
    cout << "is_pointer<int*>: " << is_pointer<int*>::value << endl;
    cout << "is_const<const int>: " << is_const<const int>::value << endl;
    
    return 0;
}

// Codigo 94: Expresiones Regulares
#include <iostream>
#include <regex>
#include <string>
#include <vector>
using namespace std;

int main() {
    cout << "=== EXPRESIONES REGULARES ===" << endl;
    
    // VALIDACION BASICA
    cout << "\n--- Validacion Basica ---" << endl;
    
    string email = "usuario@ejemplo.com";
    string email_malo = "email_invalido";
    
    regex patron_email(R"([a-zA-Z0-9._%+-]+@[a-zA-Z0-9.-]+\.[a-zA-Z]{2,})");
    
    cout << "Email '" << email << "' es valido: " << regex_match(email, patron_email) << endl;
    cout << "Email '" << email_malo << "' es valido: " << regex_match(email_malo, patron_email) << endl;
    
    // VALIDACION DE TELEFONO
    cout << "\n--- Validacion de Telefono ---" << endl;
    
    vector<string> telefonos = {
        "+1-555-123-4567",
        "(555) 123-4567",
        "555.123.4567",
        "5551234567",
        "123-45-67" // Invalido
    };
    
    regex patron_telefono(R"((\+?1[-.]?)?\(?([0-9]{3})\)?[-.]?([0-9]{3})[-.]?([0-9]{4}))");
    
    for (const string& tel : telefonos) {
        bool valido = regex_match(tel, patron_telefono);
        cout << "Telefono '" << tel << "' es valido: " << (valido ? "Si" : "No") << endl;
    }
    
    // BUSQUEDA Y EXTRACCION
    cout << "\n--- Busqueda y Extraccion ---" << endl;
    
    string texto = "Contactame en juan@empresa.com o maria@universidad.edu para mas informacion.";
    regex patron_busqueda_email(R"([a-zA-Z0-9._%+-]+@[a-zA-Z0-9.-]+\.[a-zA-Z]{2,})");
    
    cout << "Texto: " << texto << endl;
    cout << "Emails encontrados:" << endl;
    
    sregex_iterator inicio(texto.begin(), texto.end(), patron_busqueda_email);
    sregex_iterator fin;
    
    for (sregex_iterator it = inicio; it != fin; ++it) {
        smatch match = *it;
        cout << "  " << match.str() << endl;
    }
    
    // GRUPOS DE CAPTURA
    cout << "\n--- Grupos de Captura ---" << endl;
    
    string fecha = "15/03/2024";
    regex patron_fecha(R"((\d{1,2})/(\d{1,2})/(\d{4}))");
    smatch resultado;
    
    if (regex_match(fecha, resultado, patron_fecha)) {
        cout << "Fecha completa: " << resultado[0] << endl;
        cout << "Dia: " << resultado[1] << endl;
        cout << "Mes: " << resultado[2] << endl;
        cout << "Año: " << resultado[3] << endl;
    }
    
    // REEMPLAZO
    cout << "\n--- Reemplazo ---" << endl;
    
    string texto_con_numeros = "Tengo 25 años y mi hermana tiene 30 años.";
    regex patron_numeros(R"(\d+)");
    
    cout << "Texto original: " << texto_con_numeros << endl;
    
    // Reemplazar todos los numeros con [NUMERO]
    string texto_reemplazado = regex_replace(texto_con_numeros, patron_numeros, "[NUMERO]");
    cout << "Texto reemplazado: " << texto_reemplazado << endl;
    
    // Reemplazo con grupos de captura
    string texto_formato = "John Doe nacio el 15-03-1990";
    regex patron_fecha_guion(R"((\d{2})-(\d{2})-(\d{4}))");
    
    string fecha_reformateada = regex_replace(texto_formato, patron_fecha_guion, "$3/$2/$1");
    cout << "Fecha reformateada: " << fecha_reformateada << endl;
    
    // VALIDACION DE CONTRASEÑA
    cout << "\n--- Validacion de Contraseña ---" << endl;
    
    vector<string> contraseñas = {
        "MiContraseña123!",
        "password",
        "12345678",
        "Abc123!",
        "ContraseñaSegura2024#"
    };
    
    // Al menos 8 caracteres, una mayuscula, una minuscula, un numero y un simbolo
    regex patron_contraseña(R"(^(?=.*[a-z])(?=.*[A-Z])(?=.*\d)(?=.*[@$!%*?&])[A-Za-z\d@$!%*?&]{8,}$)");
    
    for (const string& pass : contraseñas) {
        bool segura = regex_match(pass, patron_contraseña);
        cout << "Contraseña '" << pass << "' es segura: " << (segura ? "Si" : "No") << endl;
    }
    
    // SEPARAR TEXTO
    cout << "\n--- Separar Texto ---" << endl;
    
    string csv = "nombre,edad,ciudad,profesion";
    regex patron_coma(",");
    
    cout << "CSV: " << csv << endl;
    cout << "Campos separados:" << endl;
    
    sregex_token_iterator token_inicio(csv.begin(), csv.end(), patron_coma, -1);
    sregex_token_iterator token_fin;
    
    int contador = 1;
    for (sregex_token_iterator it = token_inicio; it != token_fin; ++it) {
        cout << "  Campo " << contador++ << ": " << *it << endl;
    }
    
    // VALIDACION DE URL
    cout << "\n--- Validacion de URL ---" << endl;
    
    vector<string> urls = {
        "https://www.ejemplo.com",
        "http://sitio.org/pagina",
        "ftp://servidor.com/archivo.txt",
        "www.sitio.com", // Sin protocolo
        "https://" // Incompleta
    };
    
    regex patron_url(R"(^(https?|ftp)://[^\s/$.?#].[^\s]*$)");
    
    for (const string& url : urls) {
        bool valida = regex_match(url, patron_url);
        cout << "URL '" << url << "' es valida: " << (valida ? "Si" : "No") << endl;
    }
    
    return 0;
}

// Codigo 95: Design Patterns - Singleton, Factory, Observer
#include <iostream>
#include <vector>
#include <memory>
#include <string>
#include <algorithm>
using namespace std;

// SINGLETON PATTERN
class Logger {
private:
    static Logger* instancia;
    vector<string> logs;
    
    // Constructor privado
    Logger() = default;
    
public:
    // Eliminar constructor de copia y operador de asignacion
    Logger(const Logger&) = delete;
    Logger& operator=(const Logger&) = delete;
    
    static Logger* obtenerInstancia() {
        if (instancia == nullptr) {
            instancia = new Logger();
        }
        return instancia;
    }
    
    void log(const string& mensaje) {
        logs.push_back(mensaje);
        cout << "[LOG] " << mensaje << endl;
    }
    
    void mostrarLogs() {
        cout << "\n--- Historial de Logs ---" << endl;
        for (size_t i = 0; i < logs.size(); i++) {
            cout << i + 1 << ". " << logs[i] << endl;
        }
    }
    
    static void destruir() {
        delete instancia;
        instancia = nullptr;
    }
};

// Inicializar miembro estatico
Logger* Logger::instancia = nullptr;

// FACTORY PATTERN
class Vehiculo {
public:
    virtual ~Vehiculo() = default;
    virtual void describir() = 0;
    virtual string getTipo() = 0;
};

class Auto : public Vehiculo {
public:
    void describir() override {
        cout << "Soy un auto con 4 ruedas" << endl;
    }
    
    string getTipo() override {
        return "Auto";
    }
};

class Motocicleta : public Vehiculo {
public:
    void describir() override {
        cout << "Soy una motocicleta con 2 ruedas" << endl;
    }
    
    string getTipo() override {
        return "Motocicleta";
    }
};

class Camion : public Vehiculo {
public:
    void describir() override {
        cout << "Soy un camion de carga" << endl;
    }
    
    string getTipo() override {
        return "Camion";
    }
};

class FabricaVehiculos {
public:
    static unique_ptr<Vehiculo> crearVehiculo(const string& tipo) {
        if (tipo == "auto") {
            return make_unique<Auto>();
        } else if (tipo == "moto") {
            return make_unique<Motocicleta>();
        } else if (tipo == "camion") {
            return make_unique<Camion>();
        }
        return nullptr;
    }
    
    static vector<string> tiposDisponibles() {
        return {"auto", "moto", "camion"};
    }
};

// OBSERVER PATTERN
class Observer {
public:
    virtual ~Observer() = default;
    virtual void actualizar(const string& mensaje) = 0;
    virtual string getNombre() = 0;
};

class Subject {
private:
    vector<Observer*> observadores;
    string estado;
    
public:
    void agregarObservador(Observer* obs) {
        observadores.push_back(obs);
        cout << "Observador " << obs->getNombre() << " agregado" << endl;
    }
    
    void removerObservador(Observer* obs) {
        auto it = find(observadores.begin(), observadores.end(), obs);
        if (it != observadores.end()) {
            observadores.erase(it);
            cout << "Observador " << obs->getNombre() << " removido" << endl;
        }
    }
    
    void notificarObservadores() {
        for (Observer* obs : observadores) {
            obs->actualizar(estado);
        }
    }
    
    void cambiarEstado(const string& nuevoEstado) {
        estado = nuevoEstado;
        cout << "\nEstado cambiado a: " << estado << endl;
        notificarObservadores();
    }
    
    string getEstado() const {
        return estado;
    }
};

class ObservadorConcreto : public Observer {
private:
    string nombre;
    
public:
    ObservadorConcreto(const string& n) : nombre(n) {}
    
    void actualizar(const string& mensaje) override {
        cout << "  [" << nombre << "] Recibido: " << mensaje << endl;
    }
    
    string getNombre() override {
        return nombre;
    }
};

int main() {
    cout << "=== DESIGN PATTERNS ===" << endl;
    
    // SINGLETON PATTERN
    cout << "\n--- SINGLETON PATTERN ---" << endl;
    
    Logger* logger1 = Logger::obtenerInstancia();
    Logger* logger2 = Logger::obtenerInstancia();
    
    cout << "¿Son la misma instancia? " << (logger1 == logger2 ? "Si" : "No") << endl;
    
    logger1->log("Aplicacion iniciada");
    logger2->log("Usuario logueado");
    logger1->log("Datos guardados");
    
    logger1->mostrarLogs();
    
    // FACTORY PATTERN
    cout << "\n--- FACTORY PATTERN ---" << endl;
    
    auto tipos = FabricaVehiculos::tiposDisponibles();
    cout << "Tipos de vehiculos disponibles: ";
    for (const string& tipo : tipos) {
        cout << tipo << " ";
    }
    cout << endl;
    
    vector<unique_ptr<Vehiculo>> vehiculos;
    
    for (const string& tipo : tipos) {
        auto vehiculo = FabricaVehiculos::crearVehiculo(tipo);
        if (vehiculo) {
            cout << "\nCreado vehiculo tipo: " << vehiculo->getTipo() << endl;
            vehiculo->describir();
            vehiculos.push_back(move(vehiculo));
        }
    }
    
    // OBSERVER PATTERN
    cout << "\n--- OBSERVER PATTERN ---" << endl;
    
    Subject subject;
    
    ObservadorConcreto obs1("Monitor Sistema");
    ObservadorConcreto obs2("Logger Eventos");
    ObservadorConcreto obs3("Notificador Email");
    
    subject.agregarObservador(&obs1);
    subject.agregarObservador(&obs2);
    subject.agregarObservador(&obs3);
    
    subject.cambiarEstado("Sistema funcionando normalmente");
    subject.cambiarEstado("Alerta: Uso de CPU alto");
    
    subject.removerObservador(&obs2);
    subject.cambiarEstado("Sistema optimizado");
    
    // Cleanup
    Logger::destruir();
    
    return 0;
}

// Codigo 96: Concurrencia Avanzada
#include <iostream>
#include <thread>
#include <mutex>
#include <condition_variable>
#include <future>
#include <queue>
#include <atomic>
#include <chrono>
using namespace std;

// PRODUCTOR-CONSUMIDOR
class ProducerConsumer {
private:
    queue<int> buffer;
    mutex mtx;
    condition_variable cv_producer, cv_consumer;
    static const size_t MAX_SIZE = 5;
    bool terminado = false;
    
public:
    void producir(int id, int items) {
        for (int i = 0; i < items; i++) {
            unique_lock<mutex> lock(mtx);
            
            // Esperar hasta que haya espacio
            cv_producer.wait(lock, [this] { return buffer.size() < MAX_SIZE; });
            
            int item = id * 100 + i;
            buffer.push(item);
            cout << "Productor " << id << " produjo: " << item << " (buffer: " << buffer.size() << ")" << endl;
            
            cv_consumer.notify_one();
            lock.unlock();
            
            this_thread::sleep_for(chrono::milliseconds(100));
        }
    }
    
    void consumir(int id, int items) {
        for (int i = 0; i < items; i++) {
            unique_lock<mutex> lock(mtx);
            
            // Esperar hasta que haya items
            cv_consumer.wait(lock, [this] { return !buffer.empty() || terminado; });
            
            if (!buffer.empty()) {
                int item = buffer.front();
                buffer.pop();
                cout << "  Consumidor " << id << " consumio: " << item << " (buffer: " << buffer.size() << ")" << endl;
                
                cv_producer.notify_one();
            }
            
            lock.unlock();
            this_thread::sleep_for(chrono::milliseconds(150));
        }
    }
    
    void terminar() {
        lock_guard<mutex> lock(mtx);
        terminado = true;
        cv_consumer.notify_all();
    }
};

// FUTURES Y PROMISES
int calcular_fibonacci(int n) {
    if (n <= 1) return n;
    return calcular_fibonacci(n - 1) + calcular_fibonacci(n - 2);
}

int operacion_lenta(int segundos) {
    this_thread::sleep_for(chrono::seconds(segundos));
    return segundos * 10;
}

// ATOMIC OPERATIONS
atomic<int> contador_atomico{0};

void incrementar_atomico(int incrementos) {
    for (int i = 0; i < incrementos; i++) {
        contador_atomico.fetch_add(1);
        // O simplemente: contador_atomico++;
    }
}

int main() {
    cout << "=== CONCURRENCIA AVANZADA ===" << endl;
    
    // PRODUCTOR-CONSUMIDOR
    cout << "\n--- Patron Productor-Consumidor ---" << endl;
    
    ProducerConsumer pc;
    
    vector<thread> hilos;
    
    // Crear productores y consumidores
    hilos.emplace_back(&ProducerConsumer::producir, &pc, 1, 3);
    hilos.emplace_back(&ProducerConsumer::producir, &pc, 2, 3);
    hilos.emplace_back(&ProducerConsumer::consumir, &pc, 1, 3);
    hilos.emplace_back(&ProducerConsumer::consumir, &pc, 2, 3);
    
    // Esperar a que terminen
    for (auto& hilo : hilos) {
        hilo.join();
    }
    
    pc.terminar();
    
    // FUTURES Y ASYNC
    cout << "\n--- Futures y Async ---" << endl;
    
    // Ejecutar tareas asincronas
    auto future1 = async(launch::async, calcular_fibonacci, 35);
    auto future2 = async(launch::async, operacion_lenta, 2);
    auto future3 = async(launch::async, operacion_lenta, 1);
    
    cout << "Tareas iniciadas asincrónicamente..." << endl;
    
    // Hacer otras cosas mientras se ejecutan
    for (int i = 0; i < 5; i++) {
        cout << "Haciendo otra tarea... " << i << endl;
        this_thread::sleep_for(chrono::milliseconds(300));
    }
    
    // Obtener resultados
    cout << "\nObteniendo resultados:" << endl;
    cout << "Fibonacci(35): " << future1.get() << endl;
    cout << "Operacion lenta (2s): " << future2.get() << endl;
    cout << "Operacion lenta (1s): " << future3.get() << endl;
    
    // PROMISES
    cout << "\n--- Promises ---" << endl;
    
    promise<int> promesa;
    future<int> futuro = promesa.get_future();
    
    thread hilo_promesa([&promesa]() {
        this_thread::sleep_for(chrono::seconds(1));
        cout << "Estableciendo valor en promise..." << endl;
        promesa.set_value(42);
    });
    
    cout << "Esperando resultado de promise..." << endl;
    int resultado_promesa = futuro.get();
    cout << "Resultado de promise: " << resultado_promesa << endl;
    
    hilo_promesa.join();
    
    // OPERACIONES ATOMICAS
    cout << "\n--- Operaciones Atomicas ---" << endl;
    
    vector<thread> hilos_atomicos;
    
    // Crear varios hilos que incrementan el contador atomico
    for (int i = 0; i < 5; i++) {
        hilos_atomicos.emplace_back(incrementar_atomico, 1000);
    }
    
    // Esperar a que terminen
    for (auto& hilo : hilos_atomicos) {
        hilo.join();
    }
    
    cout << "Valor final del contador atomico: " << contador_atomico.load() << endl;
    cout << "Valor esperado: 5000" << endl;
    
    // SHARED_FUTURE
    cout << "\n--- Shared Future ---" << endl;
    
    auto shared_future = async(launch::async, []() {
        this_thread::sleep_for(chrono::seconds(1));
        return string("Resultado compartido");
    }).share();
    
    vector<thread> hilos_compartidos;
    
    for (int i = 0; i < 3; i++) {
        hilos_compartidos.emplace_back([shared_future, i]() {
            string resultado = shared_future.get();
            cout << "Hilo " << i << " obtuvo: " << resultado << endl;
        });
    }
    
    for (auto& hilo : hilos_compartidos) {
        hilo.join();
    }
    
    return 0;
}

// Codigo 97: Networking Basico
#include <iostream>
#include <string>
#include <vector>
#include <sstream>

// Simulacion de networking (no usa sockets reales por simplicidad)
// En un entorno real, usarias <sys/socket.h> en Unix o <winsock2.h> en Windows

using namespace std;

// Simulacion de una conexion de red
class ConexionRed {
private:
    string servidor;
    int puerto;
    bool conectado;
    vector<string> mensajes_enviados;
    vector<string> mensajes_recibidos;
    
public:
    ConexionRed(const string& serv, int p) : servidor(serv), puerto(p), conectado(false) {}
    
    bool conectar() {
        cout << "Conectando a " << servidor << ":" << puerto << "..." << endl;
        // Simulacion de conexion
        conectado = true;
        cout << "Conexion establecida" << endl;
        return true;
    }
    
    void desconectar() {
        if (conectado) {
            cout << "Desconectando de " << servidor << ":" << puerto << endl;
            conectado = false;
        }
    }
    
    bool enviarMensaje(const string& mensaje) {
        if (!conectado) {
            cout << "Error: No hay conexion" << endl;
            return false;
        }
        
        mensajes_enviados.push_back(mensaje);
        cout << "[ENVIADO] " << mensaje << endl;
        
        // Simular respuesta del servidor
        string respuesta = "OK: " + mensaje;
        mensajes_recibidos.push_back(respuesta);
        
        return true;
    }
    
    string recibirMensaje() {
        if (!mensajes_recibidos.empty()) {
            string mensaje = mensajes_recibidos.back();
            mensajes_recibidos.pop_back();
            cout << "[RECIBIDO] " << mensaje << endl;
            return mensaje;
        }
        return "";
    }
    
    void mostrarEstadisticas() {
        cout << "\n--- Estadisticas de Conexion ---" << endl;
        cout << "Servidor: " << servidor << ":" << puerto << endl;
        cout << "Estado: " << (conectado ? "Conectado" : "Desconectado") << endl;
        cout << "Mensajes enviados: " << mensajes_enviados.size() << endl;
        cout << "Mensajes recibidos: " << mensajes_recibidos.size() << endl;
    }
    
    bool estaConectado() const {
        return conectado;
    }
};

// Simulacion de un servidor HTTP simple
class ServidorHTTP {
private:
    int puerto;
    bool ejecutandose;
    vector<string> logs;
    
public:
    ServidorHTTP(int p) : puerto(p), ejecutandose(false) {}
    
    void iniciar() {
        cout << "Iniciando servidor HTTP en puerto " << puerto << "..." << endl;
        ejecutandose = true;
        logs.push_back("Servidor iniciado en puerto " + to_string(puerto));
    }
    
    void detener() {
        if (ejecutandose) {
            cout << "Deteniendo servidor HTTP..." << endl;
            ejecutandose = false;
            logs.push_back("Servidor detenido");
        }
    }
    
    string procesarPeticion(const string& metodo, const string& ruta) {
        if (!ejecutandose) {
            return "HTTP/1.1 503 Service Unavailable";
        }
        
        string log_entry = metodo + " " + ruta;
        logs.push_back(log_entry);
        
        cout << "[SERVIDOR] " << log_entry << endl;
        
        if (metodo == "GET") {
            if (ruta == "/") {
                return "HTTP/1.1 200 OK\nContent-Type: text/html\n\n<h1>Pagina de Inicio</h1>";
            } else if (ruta == "/about") {
                return "HTTP/1.1 200 OK\nContent-Type: text/html\n\n<h1>Acerca de Nosotros</h1>";
            } else {
                return "HTTP/1.1 404 Not Found\nContent-Type: text/html\n\n<h1>Pagina no encontrada</h1>";
            }
        } else if (metodo == "POST") {
            return "HTTP/1.1 200 OK\nContent-Type: text/html\n\n<h1>Datos recibidos</h1>";
        }
        
        return "HTTP/1.1 405 Method Not Allowed";
    }
    
    void mostrarLogs() {
        cout << "\n--- Logs del Servidor ---" << endl;
        for (size_t i = 0; i < logs.size(); i++) {
            cout << i + 1 << ". " << logs[i] << endl;
        }
    }
};

// Cliente HTTP simple
class ClienteHTTP {
private:
    string servidor;
    
public:
    ClienteHTTP(const string& serv) : servidor(serv) {}
    
    string hacerPeticion(const string& metodo, const string& ruta) {
        cout << "[CLIENTE] Enviando " << metodo << " " << ruta << " a " << servidor << endl;
        
        // En un cliente real, aqui se haria la conexion TCP y se enviaria la peticion HTTP
        // Por simplicidad, simulamos la respuesta
        
        if (metodo == "GET" && ruta == "/") {
            return "HTTP/1.1 200 OK\nPagina de inicio recibida";
        } else if (metodo == "GET" && ruta == "/api/data") {
            return "HTTP/1.1 200 OK\n{\"data\": \"informacion\", \"status\": \"success\"}";
        }
        
        return "HTTP/1.1 404 Not Found";
    }
};

// Utilidad para parsear URLs
struct URL {
    string protocolo;
    string servidor;
    int puerto;
    string ruta;
    
    static URL parsear(const string& url) {
        URL resultado;
        
        size_t pos_protocolo = url.find("://");
        if (pos_protocolo != string::npos) {
            resultado.protocolo = url.substr(0, pos_protocolo);
            
            size_t inicio_servidor = pos_protocolo + 3;
            size_t pos_puerto = url.find(":", inicio_servidor);
            size_t pos_ruta = url.find("/", inicio_servidor);
            
            if (pos_puerto != string::npos && (pos_ruta == string::npos || pos_puerto < pos_ruta)) {
                resultado.servidor = url.substr(inicio_servidor, pos_puerto - inicio_servidor);
                
                size_t fin_puerto = (pos_ruta != string::npos) ? pos_ruta : url.length();
                resultado.puerto = stoi(url.substr(pos_puerto + 1, fin_puerto - pos_puerto - 1));
            } else {
                size_t fin_servidor = (pos_ruta != string::npos) ? pos_ruta : url.length();
                resultado.servidor = url.substr(inicio_servidor, fin_servidor - inicio_servidor);
                resultado.puerto = (resultado.protocolo == "https") ? 443 : 80;
            }
            
            if (pos_ruta != string::npos) {
                resultado.ruta = url.substr(pos_ruta);
            } else {
                resultado.ruta = "/";
            }
        }
        
        return resultado;
    }
    
    void mostrar() {
        cout << "Protocolo: " << protocolo << endl;
        cout << "Servidor: " << servidor << endl;
        cout << "Puerto: " << puerto << endl;
        cout << "Ruta: " << ruta << endl;
    }
};

int main() {
    cout << "=== NETWORKING BASICO ===" << endl;
    
    // CONEXION DE RED SIMULADA
    cout << "\n--- Conexion de Red ---" << endl;
    
    ConexionRed conexion("servidor.ejemplo.com", 8080);
    
    if (conexion.conectar()) {
        conexion.enviarMensaje("Hola servidor");
        conexion.enviarMensaje("¿Como estas?");
        conexion.enviarMensaje("Enviando datos importantes");
        
        // Recibir respuestas
        for (int i = 0; i < 3; i++) {
            conexion.recibirMensaje();
        }
        
        conexion.mostrarEstadisticas();
        conexion.desconectar();
    }
    
    // SERVIDOR HTTP SIMULADO
    cout << "\n--- Servidor HTTP ---" << endl;
    
    ServidorHTTP servidor(8080);
    servidor.iniciar();
    
    // Simular peticiones
    vector<pair<string, string>> peticiones = {
        {"GET", "/"},
        {"GET", "/about"},
        {"GET", "/contacto"},
        {"POST", "/datos"},
        {"PUT", "/actualizar"}
    };
    
    for (const auto& peticion : peticiones) {
        string respuesta = servidor.procesarPeticion(peticion.first, peticion.second);
        cout << "Respuesta: " << respuesta.substr(0, 20) << "..." << endl;
    }
    
    servidor.mostrarLogs();
    servidor.detener();
    
    // CLIENTE HTTP
    cout << "\n--- Cliente HTTP ---" << endl;
    
    ClienteHTTP cliente("api.ejemplo.com");
    
    vector<pair<string, string>> peticiones_cliente = {
        {"GET", "/"},
        {"GET", "/api/data"},
        {"GET", "/api/users"}
    };
    
    for (const auto& peticion : peticiones_cliente) {
        string respuesta = cliente.hacerPeticion(peticion.first, peticion.second);
        cout << "Respuesta cliente: " << respuesta.substr(0, 30) << "..." << endl;
    }
    
    // PARSEO DE URLs
    cout << "\n--- Parseo de URLs ---" << endl;
    
    vector<string> urls = {
        "https://www.ejemplo.com:8080/api/datos",
        "http://servidor.com/index.html",
        "ftp://files.com:21/archivo.txt",
        "https://api.servicio.com/v1/users"
    };
    
    for (const string& url_str : urls) {
        cout << "\nParseando URL: " << url_str << endl;
        URL url = URL::parsear(url_str);
        url.mostrar();
    }
    
    return 0;
}

// Codigo 98: Optimizacion y Profiling
#include <iostream>
#include <vector>
#include <chrono>
#include <algorithm>
#include <random>
#include <cmath>
using namespace std;
using namespace std::chrono;

// Clase para medir tiempo de ejecucion
class Timer {
private:
    high_resolution_clock::time_point inicio;
    string nombre;
    
public:
    Timer(const string& n) : nombre(n) {
        inicio = high_resolution_clock::now();
    }
    
    ~Timer() {
        auto fin = high_resolution_clock::now();
        auto duracion = duration_cast<microseconds>(fin - inicio);
        cout << "[" << nombre << "] Tiempo: " << duracion.count() << " microsegundos" << endl;
    }
};

// Macro para medir tiempo facilmente
#define MEDIR_TIEMPO(nombre) Timer timer(nombre)

// Algoritmos para comparar rendimiento
namespace Algoritmos {
    // Busqueda lineal vs binaria
    int busquedaLineal(const vector<int>& arr, int objetivo) {
        for (size_t i = 0; i < arr.size(); i++) {
            if (arr[i] == objetivo) {
                return i;
            }
        }
        return -1;
    }
    
    int busquedaBinaria(const vector<int>& arr, int objetivo) {
        int izq = 0, der = arr.size() - 1;
        
        while (izq <= der) {
            int medio = izq + (der - izq) / 2;
            
            if (arr[medio] == objetivo) {
                return medio;
            } else if (arr[medio] < objetivo) {
                izq = medio + 1;
            } else {
                der = medio - 1;
            }
        }
        
        return -1;
    }
    
    // Ordenamiento: Burbuja vs QuickSort
    void ordenamientoBurbuja(vector<int>& arr) {
        int n = arr.size();
        for (int i = 0; i < n - 1; i++) {
            for (int j = 0; j < n - i - 1; j++) {
                if (arr[j] > arr[j + 1]) {
                    swap(arr[j], arr[j + 1]);
                }
            }
        }
    }
    
    void quickSort(vector<int>& arr, int bajo, int alto) {
        if (bajo < alto) {
            int pi = partition(arr, bajo, alto);
            quickSort(arr, bajo, pi - 1);
            quickSort(arr, pi + 1, alto);
        }
    }
    
    int partition(vector<int>& arr, int bajo, int alto) {
        int pivote = arr[alto];
        int i = bajo - 1;
        
        for (int j = bajo; j <= alto - 1; j++) {
            if (arr[j] < pivote) {
                i++;
                swap(arr[i], arr[j]);
            }
        }
        swap(arr[i + 1], arr[alto]);
        return i + 1;
    }
    
    // Calculo de numeros primos: Ingenuo vs Criba
    vector<int> primosIngenuo(int limite) {
        vector<int> primos;
        
        for (int num = 2; num <= limite; num++) {
            bool esPrimo = true;
            for (int i = 2; i * i <= num; i++) {
                if (num % i == 0) {
                    esPrimo = false;
                    break;
                }
            }
            if (esPrimo) {
                primos.push_back(num);
            }
        }
        
        return primos;
    }
    
    vector<int> cribaEratostenes(int limite) {
        vector<bool> esPrimo(limite + 1, true);
        vector<int> primos;
        
        esPrimo[0] = esPrimo[1] = false;
        
        for (int i = 2; i * i <= limite; i++) {
            if (esPrimo[i]) {
                for (int j = i * i; j <= limite; j += i) {
                    esPrimo[j] = false;
                }
            }
        }
        
        for (int i = 2; i <= limite; i++) {
            if (esPrimo[i]) {
                primos.push_back(i);
            }
        }
        
        return primos;
    }
}

// Optimizaciones de memoria
namespace OptimizacionMemoria {
    // Comparar vector vs lista para diferentes operaciones
    void benchmarkVector(int operaciones) {
        MEDIR_TIEMPO("Vector - Insercion al final");
        vector<int> v;
        v.reserve(operaciones); // Optimizacion: reservar memoria
        
        for (int i = 0; i < operaciones; i++) {
            v.push_back(i);
        }
    }
    
    void benchmarkVectorSinReserva(int operaciones) {
        MEDIR_TIEMPO("Vector - Sin reserva");
        vector<int> v;
        
        for (int i = 0; i < operaciones; i++) {
            v.push_back(i);
        }
    }
    
    void benchmarkAccesoMemoria() {
        const int FILAS = 1000;
        const int COLS = 1000;
        
        vector<vector<int>> matriz(FILAS, vector<int>(COLS, 1));
        
        // Acceso por filas (cache-friendly)
        {
            MEDIR_TIEMPO("Acceso por filas (cache-friendly)");
            long long suma = 0;
            for (int i = 0; i < FILAS; i++) {
                for (int j = 0; j < COLS; j++) {
                    suma += matriz[i][j];
                }
            }
        }
        
        // Acceso por columnas (cache-unfriendly)
        {
            MEDIR_TIEMPO("Acceso por columnas (cache-unfriendly)");
            long long suma = 0;
            for (int j = 0; j < COLS; j++) {
                for (int i = 0; i < FILAS; i++) {
                    suma += matriz[i][j];
                }
            }
        }
    }
}

// Optimizacion de algoritmos matematicos
namespace OptimizacionMatematica {
    // Potencia: Iterativo vs Exponenciacion rapida
    long long potenciaIterativa(int base, int exp) {
        long long resultado = 1;
        for (int i = 0; i < exp; i++) {
            resultado *= base;
        }
        return resultado;
    }
    
    long long potenciaRapida(int base, int exp) {
        long long resultado = 1;
        long long b = base;
        
        while (exp > 0) {
            if (exp % 2 == 1) {
                resultado *= b;
            }
            b *= b;
            exp /= 2;
        }
        
        return resultado;
    }
    
    // Fibonacci: Recursivo vs Iterativo vs Memoization
    int fibonacciRecursivo(int n) {
        if (n <= 1) return n;
        return fibonacciRecursivo(n - 1) + fibonacciRecursivo(n - 2);
    }
    
    int fibonacciIterativo(int n) {
        if (n <= 1) return n;
        
        int a = 0, b = 1, c;
        for (int i = 2; i <= n; i++) {
            c = a + b;
            a = b;
            b = c;
        }
        return b;
    }
    
    unordered_map<int, int> memo;
    
    int fibonacciMemoization(int n) {
        if (n <= 1) return n;
        
        if (memo.find(n) != memo.end()) {
            return memo[n];
        }
        
        memo[n] = fibonacciMemoization(n - 1) + fibonacciMemoization(n - 2);
        return memo[n];
    }
}

int main() {
    cout << "=== OPTIMIZACION Y PROFILING ===" << endl;
    
    // COMPARACION DE ALGORITMOS DE BUSQUEDA
    cout << "\n--- Busqueda: Lineal vs Binaria ---" << endl;
    
    // Generar datos ordenados
    vector<int> datos_ordenados(100000);
    iota(datos_ordenados.begin(), datos_ordenados.end(), 1);
    
    int objetivo = 75000;
    
    {
        MEDIR_TIEMPO("Busqueda Lineal");
        int pos = Algoritmos::busquedaLineal(datos_ordenados, objetivo);
        cout << "  Posicion encontrada: " << pos << endl;
    }
    
    {
        MEDIR_TIEMPO("Busqueda Binaria");
        int pos = Algoritmos::busquedaBinaria(datos_ordenados, objetivo);
        cout << "  Posicion encontrada: " << pos << endl;
    }
    
    // COMPARACION DE ALGORITMOS DE ORDENAMIENTO
    cout << "\n--- Ordenamiento: Burbuja vs QuickSort vs STL ---" << endl;
    
    const int TAMAÑO = 10000;
    vector<int> datos_aleatorios(TAMAÑO);
    
    random_device rd;
    mt19937 gen(rd());
    uniform_int_distribution<> dis(1, TAMAÑO);
    
    generate(datos_aleatorios.begin(), datos_aleatorios.end(), [&]() { return dis(gen); });
    
    {
        vector<int> copia = datos_aleatorios;
        MEDIR_TIEMPO("Ordenamiento Burbuja");
        Algoritmos::ordenamientoBurbuja(copia);
    }
    
    {
        vector<int> copia = datos_aleatorios;
        MEDIR_TIEMPO("QuickSort");
        Algoritmos::quickSort(copia, 0, copia.size() - 1);
    }
    
    {
        vector<int> copia = datos_aleatorios;
        MEDIR_TIEMPO("STL sort");
        sort(copia.begin(), copia.end());
    }
    
    // COMPARACION DE CALCULO DE PRIMOS
    cout << "\n--- Primos: Ingenuo vs Criba de Eratostenes ---" << endl;
    
    const int LIMITE_PRIMOS = 10000;
    
    {
        MEDIR_TIEMPO("Algoritmo Ingenuo");
        auto primos = Algoritmos::primosIngenuo(LIMITE_PRIMOS);
        cout << "  Primos encontrados: " << primos.size() << endl;
    }
    
    {
        MEDIR_TIEMPO("Criba de Eratostenes");
        auto primos = Algoritmos::cribaEratostenes(LIMITE_PRIMOS);
        cout << "  Primos encontrados: " << primos.size() << endl;
    }
    
    // OPTIMIZACIONES DE MEMORIA
    cout << "\n--- Optimizaciones de Memoria ---" << endl;
    
    OptimizacionMemoria::benchmarkVectorSinReserva(100000);
    OptimizacionMemoria::benchmarkVector(100000);
    OptimizacionMemoria::benchmarkAccesoMemoria();
    
    // OPTIMIZACIONES MATEMATICAS
    cout << "\n--- Optimizaciones Matematicas ---" << endl;
    
    {
        MEDIR_TIEMPO("Potencia Iterativa (2^20)");
        auto resultado = OptimizacionMatematica::potenciaIterativa(2, 20);
        cout << "  Resultado: " << resultado << endl;
    }
    
    {
        MEDIR_TIEMPO("Potencia Rapida (2^20)");
        auto resultado = OptimizacionMatematica::potenciaRapida(2, 20);
        cout << "  Resultado: " << resultado << endl;
    }
    
    // Fibonacci (solo numeros pequeños para recursivo)
    const int FIB_N = 35;
    
    {
        MEDIR_TIEMPO("Fibonacci Recursivo");
        auto resultado = OptimizacionMatematica::fibonacciRecursivo(FIB_N);
        cout << "  Fibonacci(" << FIB_N << ") = " << resultado << endl;
    }
    
    {
        MEDIR_TIEMPO("Fibonacci Iterativo");
        auto resultado = OptimizacionMatematica::fibonacciIterativo(FIB_N);
        cout << "  Fibonacci(" << FIB_N << ") = " << resultado << endl;
    }
    
    {
        OptimizacionMatematica::memo.clear();
        MEDIR_TIEMPO("Fibonacci Memoization");
        auto resultado = OptimizacionMatematica::fibonacciMemoization(FIB_N);
        cout << "  Fibonacci(" << FIB_N << ") = " << resultado << endl;
    }
    
    return 0;
}

// Codigo 99: Manejo de Errores y Debugging
#include <iostream>
#include <stdexcept>
#include <string>
#include <vector>
#include <fstream>
#include <cassert>
#include <memory>
using namespace std;

// Clase de excepcion personalizada
class MiExcepcion : public exception {
private:
    string mensaje;
    int codigo_error;
    
public:
    MiExcepcion(const string& msg, int codigo = 0) : mensaje(msg), codigo_error(codigo) {}
    
    const char* what() const noexcept override {
        return mensaje.c_str();
    }
    
    int getCodigo() const {
        return codigo_error;
    }
};

// Clase para demostrar RAII y manejo seguro de recursos
class RecursoSeguro {
private:
    int* datos;
    size_t tamaño;
    string nombre;
    
public:
    RecursoSeguro(const string& n, size_t t) : nombre(n), tamaño(t) {
        if (t == 0) {
            throw invalid_argument("Tamaño no puede ser cero");
        }
        
        datos = new(nothrow) int[tamaño];
        if (!datos) {
            throw bad_alloc();
        }
        
        // Inicializar datos
        for (size_t i = 0; i < tamaño; i++) {
            datos[i] = static_cast<int>(i);
        }
        
        cout << "Recurso '" << nombre << "' creado (tamaño: " << tamaño << ")" << endl;
    }
    
    // Constructor de copia
    RecursoSeguro(const RecursoSeguro& otro) : nombre(otro.nombre + "_copia"), tamaño(otro.tamaño) {
        datos = new int[tamaño];
        copy(otro.datos, otro.datos + tamaño, datos);
        cout << "Recurso copiado: " << nombre << endl;
    }
    
    // Operador de asignacion
    RecursoSeguro& operator=(const RecursoSeguro& otro) {
        if (this != &otro) {
            delete[] datos;
            
            nombre = otro.nombre + "_asignado";
            tamaño = otro.tamaño;
            datos = new int[tamaño];
            copy(otro.datos, otro.datos + tamaño, datos);
            
            cout << "Recurso asignado: " << nombre << endl;
        }
        return *this;
    }
    
    // Destructor
    ~RecursoSeguro() {
        delete[] datos;
        cout << "Recurso '" << nombre << "' destruido" << endl;
    }
    
    int& operator[](size_t index) {
        if (index >= tamaño) {
            throw out_of_range("Indice fuera de rango: " + to_string(index));
        }
        return datos[index];
    }
    
    const int& operator[](size_t index) const {
        if (index >= tamaño) {
            throw out_of_range("Indice fuera de rango: " + to_string(index));
        }
        return datos[index];
    }
    
    size_t getTamaño() const { return tamaño; }
    string getNombre() const { return nombre; }
    
    void procesarDatos() {
        if (!datos) {
            throw runtime_error("Datos no inicializados");
        }
        
        try {
            for (size_t i = 0; i < tamaño; i++) {
                datos[i] *= 2;
                
                // Simular condicion de error
                if (datos[i] > 100 && datos[i] % 7 == 0) {
                    throw MiExcepcion("Valor problematico encontrado: " + to_string(datos[i]), 500);
                }
            }
        } catch (const MiExcepcion& e) {
            cout << "Error en procesamiento: " << e.what() << " (Codigo: " << e.getCodigo() << ")" << endl;
            throw; // Re-lanzar la excepcion
        }
    }
};

// Funciones para demostrar diferentes tipos de errores
namespace ErroresComunes {
    void divisionPorCero(int a, int b) {
        if (b == 0) {
            throw invalid_argument("Division por cero no permitida");
        }
        cout << a << " / " << b << " = " << a / b << endl;
    }
    
    void accesoArreglo(vector<int>& arr, size_t index) {
        try {
            cout << "Elemento en posicion " << index << ": " << arr.at(index) << endl;
        } catch (const out_of_range& e) {
            cout << "Error de acceso: " << e.what() << endl;
            throw; // Re-lanzar para manejo en nivel superior
        }
    }
    
    void manejoArchivos(const string& nombre_archivo) {
        ifstream archivo(nombre_archivo);
        
        if (!archivo.is_open()) {
            throw runtime_error("No se pudo abrir el archivo: " + nombre_archivo);
        }
        
        string linea;
        int numero_linea = 0;
        
        try {
            while (getline(archivo, linea)) {
                numero_linea++;
                
                if (linea.empty()) {
                    cout << "Advertencia: Linea " << numero_linea << " esta vacia" << endl;
                }
                
                // Simular error de procesamiento
                if (linea.find("ERROR") != string::npos) {
                    throw runtime_error("Error encontrado en linea " + to_string(numero_linea) + ": " + linea);
                }
            }
        } catch (const exception& e) {
            cout << "Error procesando archivo: " << e.what() << endl;
            throw;
        }
    }
    
    void memoriaInsuficiente() {
        try {
            // Intentar asignar una cantidad muy grande de memoria
            size_t tamaño_grande = 1000000000; // 1GB de ints
            vector<int> gran_vector(tamaño_grande);
            
            cout << "Memoria asignada exitosamente" << endl;
            
        } catch (const bad_alloc& e) {
            cout << "Error de memoria: " << e.what() << endl;
            throw;
        }
    }
}

// Sistema de logging para debugging
class Logger {
private:
    static Logger* instancia;
    vector<string> logs;
    
    Logger() = default;
    
public:
    static Logger* obtenerInstancia() {
        if (!instancia) {
            instancia = new Logger();
        }
        return instancia;
    }
    
    void debug(const string& mensaje) {
        string log_entry = "[DEBUG] " + mensaje;
        logs.push_back(log_entry);
        cout << log_entry << endl;
    }
    
    void info(const string& mensaje) {
        string log_entry = "[INFO] " + mensaje;
        logs.push_back(log_entry);
        cout << log_entry << endl;
    }
    
    void warning(const string& mensaje) {
        string log_entry = "[WARNING] " + mensaje;
        logs.push_back(log_entry);
        cout << log_entry << endl;
    }
    
    void error(const string& mensaje) {
        string log_entry = "[ERROR] " + mensaje;
        logs.push_back(log_entry);
        cout << log_entry << endl;
    }
    
    void mostrarLogs() {
        cout << "\n--- Historial de Logs ---" << endl;
        for (size_t i = 0; i < logs.size(); i++) {
            cout << i + 1 << ". " << logs[i] << endl;
        }
    }
};

Logger* Logger::instancia = nullptr;

// Macros para debugging
#ifdef DEBUG
    #define DEBUG_PRINT(x) cout << "[DEBUG] " << x << endl
    #define DEBUG_VAR(var) cout << "[DEBUG] " << #var << " = " << var << endl
#else
    #define DEBUG_PRINT(x)
    #define DEBUG_VAR(var)
#endif

int main() {
    cout << "=== MANEJO DE ERRORES Y DEBUGGING ===" << endl;
    
    Logger* logger = Logger::obtenerInstancia();
    
    // MANEJO BASICO DE EXCEPCIONES
    cout << "\n--- Manejo Basico de Excepciones ---" << endl;
    
    try {
        logger->info("Iniciando pruebas de manejo de errores");
        
        // Test 1: Division por cero
        logger->debug("Probando division por cero");
        ErroresComunes::divisionPorCero(10, 2);
        ErroresComunes::divisionPorCero(10, 0); // Esto lanzara excepcion
        
    } catch (const invalid_argument& e) {
        logger->error("Argumento invalido: " + string(e.what()));
    } catch (const exception& e) {
        logger->error("Error general: " + string(e.what()));
    }
    
    // MANEJO DE ACCESO A ARREGLOS
    cout << "\n--- Acceso Seguro a Arreglos ---" << endl;
    
    try {
        vector<int> numeros = {1, 2, 3, 4, 5};
        
        ErroresComunes::accesoArreglo(numeros, 2); // OK
        ErroresComunes::accesoArreglo(numeros, 10); // Error
        
    } catch (const out_of_range& e) {
        logger->error("Indice fuera de rango capturado en main");
    }
    
    // RAII Y MANEJO SEGURO DE RECURSOS
    cout << "\n--- RAII y Recursos Seguros ---" << endl;
    
    try {
        {
            RecursoSeguro recurso1("TestRecurso", 10);
            
            // Acceso seguro
            recurso1[5] = 100;
            cout << "Valor en posicion 5: " << recurso1[5] << endl;
            
            // Procesamiento que puede fallar
            recurso1.procesarDatos();
            
            // Acceso fuera de rango
            recurso1[20] = 50; // Esto lanzara excepcion
            
        } // recurso1 se destruye automaticamente aqui
        
    } catch (const MiExcepcion& e) {
        logger->error("Excepcion personalizada: " + string(e.what()) + " (Codigo: " + to_string(e.getCodigo()) + ")");
    } catch (const out_of_range& e) {
        logger->error("Fuera de rango: " + string(e.what()));
    } catch (const exception& e) {
        logger->error("Error en manejo de recursos: " + string(e.what()));
    }
    
    // SMART POINTERS PARA SEGURIDAD
    cout << "\n--- Smart Pointers para Seguridad ---" << endl;
    
    try {
        auto recurso_smart = make_unique<RecursoSeguro>("SmartRecurso", 5);
        
        (*recurso_smart)[2] = 42;
        cout << "Valor con smart pointer: " << (*recurso_smart)[2] << endl;
        
        // Transferir propiedad
        auto otro_recurso = move(recurso_smart);
        
        if (!recurso_smart) {
            logger->info("Propiedad transferida correctamente");
        }
        
        // otro_recurso se destruye automaticamente
        
    } catch (const exception& e) {
        logger->error("Error con smart pointers: " + string(e.what()));
    }
    
    // MULTIPLES NIVELES DE EXCEPCION
    cout << "\n--- Multiples Niveles de Excepcion ---" << endl;
    
    try {
        try {
            try {
                throw runtime_error("Error en nivel profundo");
            } catch (const runtime_error& e) {
                logger->warning("Capturado en nivel 1: " + string(e.what()));
                throw invalid_argument("Error transformado en nivel 1");
            }
        } catch (const invalid_argument& e) {
            logger->warning("Capturado en nivel 2: " + string(e.what()));
            throw logic_error("Error final en nivel 2");
        }
    } catch (const logic_error& e) {
        logger->error("Error final capturado: " + string(e.what()));
    }
    
    // ASSERTIONS PARA DEBUGGING
    cout << "\n--- Assertions ---" << endl;
    
    int x = 10;
    int y = 5;
    
    DEBUG_VAR(x);
    DEBUG_VAR(y);
    
    assert(x > y); // OK
    logger->debug("Assertion x > y paso");
    
    // assert(x < y); // Esto causaria terminacion del programa en debug
    
    // MANEJO DE ERRORES DE MEMORIA
    cout << "\n--- Manejo de Errores de Memoria ---" << endl;
    
    try {
        logger->info("Intentando asignar memoria grande...");
        // ErroresComunes::memoriaInsuficiente(); // Comentado para evitar problemas
        logger->info("Asignacion de memoria simulada");
        
    } catch (const bad_alloc& e) {
        logger->error("Error de memoria capturado: " + string(e.what()));
    }
    
    // RESUMEN
    cout << "\n--- Resumen de Logs ---" << endl;
    logger->mostrarLogs();
    
    logger->info("Programa completado exitosamente");
    
    return 0;
}

// Codigo 100: Proyecto Completo - Sistema de Gestion
#include <iostream>
#include <vector>
#include <map>
#include <string>
#include <memory>
#include <algorithm>
#include <fstream>
#include <sstream>
#include <iomanip>
#include <chrono>
using namespace std;

// Sistema completo de gestion con todas las caracteristicas avanzadas de C++

// Clase base abstracta
class Persona {
protected:
    static int siguiente_id;
    int id;
    string nombre;
    string email;
    
public:
    Persona(const string& n, const string& e) : nombre(n), email(e) {
        id = ++siguiente_id;
    }
    
    virtual ~Persona() = default;
    
    // Metodos virtuales puros
    virtual void mostrarInfo() const = 0;
    virtual string getTipo() const = 0;
    virtual double calcularSalario() const = 0;
    
    // Getters
    int getId() const { return id; }
    string getNombre() const { return nombre; }
    string getEmail() const { return email; }
    
    // Setters con validacion
    void setNombre(const string& n) {
        if (!n.empty()) nombre = n;
    }
    
    void setEmail(const string& e) {
        if (e.find('@') != string::npos) email = e;
    }
};

int Persona::siguiente_id = 0;

// Clases derivadas
class Empleado : public Persona {
protected:
    double salario_base;
    string departamento;
    
public:
    Empleado(const string& n, const string& e, double s, const string& d) 
        : Persona(n, e), salario_base(s), departamento(d) {}
    
    void mostrarInfo() const override {
        cout << "[" << getTipo() << "] ID: " << id << ", Nombre: " << nombre 
             << ", Email: " << email << ", Salario: $" << fixed << setprecision(2) << calcularSalario()
             << ", Depto: " << departamento << endl;
    }
    
    string getTipo() const override { return "Empleado"; }
    
    double calcularSalario() const override {
        return salario_base;
    }
    
    // Getters especificos
    double getSalarioBase() const { return salario_base; }
    string getDepartamento() const { return departamento; }
};

class Gerente : public Empleado {
private:
    double bono_gerencial;
    vector<shared_ptr<Empleado>> equipo;
    
public:
    Gerente(const string& n, const string& e, double s, const string& d, double b)
        : Empleado(n, e, s, d), bono_gerencial(b) {}
    
    string getTipo() const override { return "Gerente"; }
    
    double calcularSalario() const override {
        return salario_base + bono_gerencial + (equipo.size() * 500); // Bono por empleado
    }
    
    void agregarEmpleado(shared_ptr<Empleado> emp) {
        equipo.push_back(emp);
    }
    
    void mostrarEquipo() const {
        cout << "Equipo de " << nombre << ":" << endl;
        for (const auto& emp : equipo) {
            cout << "  - " << emp->getNombre() << " (" << emp->getDepartamento() << ")" << endl;
        }
    }
    
    size_t getTamañoEquipo() const { return equipo.size(); }
};

class Consultor : public Persona {
private:
    double tarifa_por_hora;
    int horas_trabajadas;
    
public:
    Consultor(const string& n, const string& e, double t) 
        : Persona(n, e), tarifa_por_hora(t), horas_trabajadas(0) {}
    
    void mostrarInfo() const override {
        cout << "[" << getTipo() << "] ID: " << id << ", Nombre: " << nombre 
             << ", Email: " << email << ", Tarifa: $" << tarifa_por_hora 
             << "/hr, Horas: " << horas_trabajadas << ", Total: $" << calcularSalario() << endl;
    }
    
    string getTipo() const override { return "Consultor"; }
    
    double calcularSalario() const override {
        return tarifa_por_hora * horas_trabajadas;
    }
    
    void registrarHoras(int horas) {
        if (horas > 0) horas_trabajadas += horas;
    }
    
    int getHorasTrabajadas() const { return horas_trabajadas; }
};

// Template para estadisticas
template<typename T>
class Estadisticas {
public:
    static double promedio(const vector<T>& datos) {
        if (datos.empty()) return 0.0;
        
        T suma = T{};
        for (const T& dato : datos) {
            suma += dato;
        }
        return static_cast<double>(suma) / datos.size();
    }
    
    static T maximo(const vector<T>& datos) {
        if (datos.empty()) return T{};
        return *max_element(datos.begin(), datos.end());
    }
    
    static T minimo(const vector<T>& datos) {
        if (datos.empty()) return T{};
        return *min_element(datos.begin(), datos.end());
    }
};

// Sistema de gestion principal
class SistemaGestion {
private:
    vector<shared_ptr<Persona>> personas;
    map<string, vector<shared_ptr<Persona>>> por_departamento;
    
public:
    // Agregar personas al sistema
    void agregarPersona(shared_ptr<Persona> persona) {
        personas.push_back(persona);
        
        // Organizar por departamento si es empleado
        if (auto empleado = dynamic_pointer_cast<Empleado>(persona)) {
            por_departamento[empleado->getDepartamento()].push_back(persona);
        }
        
        cout << "Agregado: " << persona->getNombre() << " (" << persona->getTipo() << ")" << endl;
    }
    
    // Buscar persona por ID
    shared_ptr<Persona> buscarPorId(int id) {
        auto it = find_if(personas.begin(), personas.end(),
            [id](const shared_ptr<Persona>& p) { return p->getId() == id; });
        
        return (it != personas.end()) ? *it : nullptr;
    }
    
    // Buscar personas por nombre
    vector<shared_ptr<Persona>> buscarPorNombre(const string& nombre) {
        vector<shared_ptr<Persona>> resultados;
        
        copy_if(personas.begin(), personas.end(), back_inserter(resultados),
            [&nombre](const shared_ptr<Persona>& p) {
                return p->getNombre().find(nombre) != string::npos;
            });
        
        return resultados;
    }
    
    // Mostrar todas las personas
    void mostrarTodas() const {
        cout << "\n=== LISTADO COMPLETO ===" << endl;
        for (const auto& persona : personas) {
            persona->mostrarInfo();
        }
    }
    
    // Mostrar por departamento
    void mostrarPorDepartamento(const string& depto) const {
        cout << "\n=== DEPARTAMENTO: " << depto << " ===" << endl;
        
        auto it = por_departamento.find(depto);
        if (it != por_departamento.end()) {
            for (const auto& persona : it->second) {
                persona->mostrarInfo();
            }
        } else {
            cout << "Departamento no encontrado" << endl;
        }
    }
    
    // Estadisticas de salarios
    void mostrarEstadisticasSalarios() const {
        cout << "\n=== ESTADISTICAS DE SALARIOS ===" << endl;
        
        vector<double> salarios;
        for (const auto& persona : personas) {
            salarios.push_back(persona->calcularSalario());
        }
        
        if (!salarios.empty()) {
            cout << "Promedio: $" << fixed << setprecision(2) << Estadisticas<double>::promedio(salarios) << endl;
            cout << "Maximo: $" << Estadisticas<double>::maximo(salarios) << endl;
            cout << "Minimo: $" << Estadisticas<double>::minimo(salarios) << endl;
            cout << "Total empleados: " << personas.size() << endl;
        }
    }
    
    // Mostrar estadisticas por tipo
    void mostrarEstadisticasPorTipo() const {
        cout << "\n=== ESTADISTICAS POR TIPO ===" << endl;
        
        map<string, int> conteo_tipos;
        map<string, double> salario_tipos;
        
        for (const auto& persona : personas) {
            string tipo = persona->getTipo();
            conteo_tipos[tipo]++;
            salario_tipos[tipo] += persona->calcularSalario();
        }
        
        for (const auto& [tipo, cantidad] : conteo_tipos) {
            double promedio = salario_tipos[tipo] / cantidad;
            cout << tipo << ": " << cantidad << " personas, Salario promedio: $" 
                 << fixed << setprecision(2) << promedio << endl;
        }
    }
    
    // Guardar en archivo
    void guardarEnArchivo(const string& archivo) const {
        ofstream file(archivo);
        if (!file.is_open()) {
            throw runtime_error("No se pudo crear el archivo: " + archivo);
        }
        
        file << "ID,Tipo,Nombre,Email,Salario,Departamento" << endl;
        
        for (const auto& persona : personas) {
            file << persona->getId() << "," << persona->getTipo() << "," 
                 << persona->getNombre() << "," << persona->getEmail() << "," 
                 << fixed << setprecision(2) << persona->calcularSalario();
            
            if (auto empleado = dynamic_pointer_cast<Empleado>(persona)) {
                file << "," << empleado->getDepartamento();
            } else {
                file << ",N/A";
            }
            
            file << endl;
        }
        
        cout << "Datos guardados en: " << archivo << endl;
    }
    
    // Generar reporte completo
    void generarReporte() const {
        auto now = chrono::system_clock::now();
        auto time_t = chrono::system_clock::to_time_t(now);
        
        cout << "\n" << string(50, '=') << endl;
        cout << "REPORTE DEL SISTEMA DE GESTION" << endl;
        cout << "Fecha: " << put_time(localtime(&time_t), "%Y-%m-%d %H:%M:%S") << endl;
        cout << string(50, '=') << endl;
        
        mostrarTodas();
        mostrarEstadisticasSalarios();
        mostrarEstadisticasPorTipo();
        
        cout << string(50, '=') << endl;
    }
    
    // Obtener total de personas
    size_t getTotalPersonas() const {
        return personas.size();
    }
    
    // Limpiar sistema
    void limpiar() {
        personas.clear();
        por_departamento.clear();
        cout << "Sistema limpiado" << endl;
    }
};

int main() {
    cout << "=== SISTEMA DE GESTION COMPLETO ===" << endl;
    cout << "Proyecto Final - Codigo 100" << endl;
    
    try {
        SistemaGestion sistema;
        
        // Crear empleados
        auto emp1 = make_shared<Empleado>("Ana Garcia", "ana@empresa.com", 50000, "IT");
        auto emp2 = make_shared<Empleado>("Carlos Lopez", "carlos@empresa.com", 45000, "IT");
        auto emp3 = make_shared<Empleado>("Diana Martinez", "diana@empresa.com", 48000, "Ventas");
        auto emp4 = make_shared<Empleado>("Eduardo Ruiz", "eduardo@empresa.com", 52000, "Ventas");
        
        // Crear gerentes
        auto gerente1 = make_shared<Gerente>("Maria Rodriguez", "maria@empresa.com", 80000, "IT", 15000);
        auto gerente2 = make_shared<Gerente>("Jorge Mendez", "jorge@empresa.com", 75000, "Ventas", 12000);
        
        // Crear consultores
        auto cons1 = make_shared<Consultor>("Sofia Chen", "sofia@consultor.com", 150);
        auto cons2 = make_shared<Consultor>("Roberto Silva", "roberto@consultor.com", 120);
        
        // Agregar al sistema
        sistema.agregarPersona(emp1);
        sistema.agregarPersona(emp2);
        sistema.agregarPersona(emp3);
        sistema.agregarPersona(emp4);
        sistema.agregarPersona(gerente1);
        sistema.agregarPersona(gerente2);
        sistema.agregarPersona(cons1);
        sistema.agregarPersona(cons2);
        
        // Configurar equipos de gerentes
        gerente1->agregarEmpleado(emp1);
        gerente1->agregarEmpleado(emp2);
        gerente2->agregarEmpleado(emp3);
        gerente2->agregarEmpleado(emp4);
        
        // Registrar horas de consultores
        cons1->registrarHoras(40);
        cons2->registrarHoras(35);
        
        // Mostrar informacion
        cout << "\nTotal de personas en el sistema: " << sistema.getTotalPersonas() << endl;
        
        // Busquedas
        cout << "\n--- BUSQUEDAS ---" << endl;
        auto persona_encontrada = sistema.buscarPorId(3);
        if (persona_encontrada) {
            cout << "Persona con ID 3: ";
            persona_encontrada->mostrarInfo();
        }
        
        auto personas_ana = sistema.buscarPorNombre("Ana");
        cout << "Personas con 'Ana' en el nombre: " << personas_ana.size() << endl;
        
        // Mostrar por departamento
        sistema.mostrarPorDepartamento("IT");
        sistema.mostrarPorDepartamento("Ventas");
        
        // Mostrar equipos de gerentes
        cout << "\n--- EQUIPOS ---" << endl;
        gerente1->mostrarEquipo();
        gerente2->mostrarEquipo();
        
        // Generar reporte completo
        sistema.generarReporte();
        
        // Guardar en archivo
        sistema.guardarEnArchivo("empleados.csv");
        
        cout << "\n=== SISTEMA COMPLETADO EXITOSAMENTE ===" << endl;
        cout << "Este es el codigo #100 de la coleccion!" << endl;
        
    } catch (const exception& e) {
        cout << "Error en el sistema: " << e.what() << endl;
    }
    
    return 0;
}