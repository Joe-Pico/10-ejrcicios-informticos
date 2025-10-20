// Codigo 81: STL Containers - Vector
#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric>
using namespace std;

int main() {
    cout << "=== STL VECTOR ===" << endl;
    
    // Crear vector
    vector<int> v1 = {1, 3, 5, 7, 9};
    vector<int> v2(5, 10); // 5 elementos con valor 10
    vector<int> v3;
    
    cout << "Vector v1: ";
    for (int x : v1) cout << x << " ";
    cout << endl;
    
    cout << "Vector v2: ";
    for (int x : v2) cout << x << " ";
    cout << endl;
    
    // Operaciones basicas
    v3.push_back(100);
    v3.push_back(200);
    v3.insert(v3.begin() + 1, 150);
    
    cout << "Vector v3 despues de inserciones: ";
    for (int x : v3) cout << x << " ";
    cout << endl;
    
    // Acceso a elementos
    cout << "Primer elemento de v1: " << v1.front() << endl;
    cout << "Ultimo elemento de v1: " << v1.back() << endl;
    cout << "Elemento en posicion 2 de v1: " << v1[2] << endl;
    
    // Informacion del vector
    cout << "Tamaño de v1: " << v1.size() << endl;
    cout << "Capacidad de v1: " << v1.capacity() << endl;
    cout << "Esta vacio v3? " << (v3.empty() ? "Si" : "No") << endl;
    
    // Algoritmos STL
    sort(v1.begin(), v1.end(), greater<int>());
    cout << "v1 ordenado descendente: ";
    for (int x : v1) cout << x << " ";
    cout << endl;
    
    int suma = accumulate(v1.begin(), v1.end(), 0);
    cout << "Suma de elementos en v1: " << suma << endl;
    
    auto it = find(v1.begin(), v1.end(), 5);
    if (it != v1.end()) {
        cout << "Elemento 5 encontrado en posicion: " << distance(v1.begin(), it) << endl;
    }
    
    return 0;
}

// Codigo 82: STL Containers - Map y Set
#include <iostream>
#include <map>
#include <set>
#include <string>
using namespace std;

int main() {
    cout << "=== STL MAP Y SET ===" << endl;
    
    // MAP
    cout << "\n--- MAP ---" << endl;
    map<string, int> edades;
    
    // Insertar elementos
    edades["Ana"] = 25;
    edades["Carlos"] = 30;
    edades.insert({"Diana", 28});
    edades.emplace("Eduardo", 35);
    
    cout << "Edades:" << endl;
    for (const auto& par : edades) {
        cout << par.first << ": " << par.second << " años" << endl;
    }
    
    // Buscar elementos
    string nombre = "Carlos";
    auto it = edades.find(nombre);
    if (it != edades.end()) {
        cout << nombre << " tiene " << it->second << " años" << endl;
    }
    
    // Verificar existencia
    if (edades.count("Ana") > 0) {
        cout << "Ana esta en el mapa" << endl;
    }
    
    // SET
    cout << "\n--- SET ---" << endl;
    set<int> numeros = {5, 2, 8, 1, 9, 2, 5}; // Elementos duplicados se eliminan
    
    cout << "Conjunto de numeros (ordenados automaticamente): ";
    for (int x : numeros) {
        cout << x << " ";
    }
    cout << endl;
    
    // Insertar y buscar
    numeros.insert(3);
    numeros.insert(7);
    
    if (numeros.find(5) != numeros.end()) {
        cout << "El numero 5 esta en el conjunto" << endl;
    }
    
    // MULTIMAP y MULTISET
    cout << "\n--- MULTIMAP ---" << endl;
    multimap<string, string> contactos;
    contactos.insert({"Juan", "123-456"});
    contactos.insert({"Juan", "987-654"});
    contactos.insert({"Maria", "555-123"});
    
    cout << "Contactos de Juan:" << endl;
    auto rango = contactos.equal_range("Juan");
    for (auto it = rango.first; it != rango.second; ++it) {
        cout << "  " << it->second << endl;
    }
    
    return 0;
}

// Codigo 83: STL Algorithms
#include <iostream>
#include <vector>
#include <algorithm>
#include <functional>
#include <numeric>
using namespace std;

int main() {
    cout << "=== STL ALGORITHMS ===" << endl;
    
    vector<int> numeros = {5, 2, 8, 1, 9, 3, 7, 4, 6};
    
    cout << "Vector original: ";
    for (int x : numeros) cout << x << " ";
    cout << endl;
    
    // ALGORITMOS DE ORDENAMIENTO
    cout << "\n--- ORDENAMIENTO ---" << endl;
    
    vector<int> copia1 = numeros;
    sort(copia1.begin(), copia1.end());
    cout << "Ordenado ascendente: ";
    for (int x : copia1) cout << x << " ";
    cout << endl;
    
    vector<int> copia2 = numeros;
    sort(copia2.begin(), copia2.end(), greater<int>());
    cout << "Ordenado descendente: ";
    for (int x : copia2) cout << x << " ";
    cout << endl;
    
    // ALGORITMOS DE BUSQUEDA
    cout << "\n--- BUSQUEDA ---" << endl;
    
    auto it = find(numeros.begin(), numeros.end(), 5);
    if (it != numeros.end()) {
        cout << "Elemento 5 encontrado en posicion: " << distance(numeros.begin(), it) << endl;
    }
    
    int cuenta = count(numeros.begin(), numeros.end(), 5);
    cout << "El numero 5 aparece " << cuenta << " veces" << endl;
    
    int pares = count_if(numeros.begin(), numeros.end(), [](int x) { return x % 2 == 0; });
    cout << "Numeros pares: " << pares << endl;
    
    // ALGORITMOS DE TRANSFORMACION
    cout << "\n--- TRANSFORMACION ---" << endl;
    
    vector<int> cuadrados(numeros.size());
    transform(numeros.begin(), numeros.end(), cuadrados.begin(), [](int x) { return x * x; });
    cout << "Cuadrados: ";
    for (int x : cuadrados) cout << x << " ";
    cout << endl;
    
    // ALGORITMOS NUMERICOS
    cout << "\n--- ALGORITMOS NUMERICOS ---" << endl;
    
    int suma = accumulate(numeros.begin(), numeros.end(), 0);
    cout << "Suma: " << suma << endl;
    
    int producto = accumulate(numeros.begin(), numeros.end(), 1, multiplies<int>());
    cout << "Producto: " << producto << endl;
    
    auto minmax = minmax_element(numeros.begin(), numeros.end());
    cout << "Minimo: " << *minmax.first << ", Maximo: " << *minmax.second << endl;
    
    // ALGORITMOS DE MANIPULACION
    cout << "\n--- MANIPULACION ---" << endl;
    
    vector<int> copia3 = numeros;
    reverse(copia3.begin(), copia3.end());
    cout << "Invertido: ";
    for (int x : copia3) cout << x << " ";
    cout << endl;
    
    vector<int> copia4 = numeros;
    random_shuffle(copia4.begin(), copia4.end());
    cout << "Mezclado: ";
    for (int x : copia4) cout << x << " ";
    cout << endl;
    
    vector<int> copia5 = numeros;
    auto new_end = unique(copia5.begin(), copia5.end());
    copia5.erase(new_end, copia5.end());
    cout << "Sin duplicados consecutivos: ";
    for (int x : copia5) cout << x << " ";
    cout << endl;
    
    return 0;
}

// Codigo 84: STL Iterators
#include <iostream>
#include <vector>
#include <list>
#include <iterator>
using namespace std;

int main() {
    cout << "=== STL ITERATORS ===" << endl;
    
    vector<int> v = {1, 2, 3, 4, 5};
    list<string> l = {"a", "b", "c", "d"};
    
    // ITERADORES BASICOS
    cout << "\n--- Iteradores Basicos ---" << endl;
    
    cout << "Vector con iterador forward: ";
    for (auto it = v.begin(); it != v.end(); ++it) {
        cout << *it << " ";
    }
    cout << endl;
    
    cout << "Vector con iterador reverse: ";
    for (auto it = v.rbegin(); it != v.rend(); ++it) {
        cout << *it << " ";
    }
    cout << endl;
    
    // MODIFICACION A TRAVES DE ITERADORES
    cout << "\n--- Modificacion ---" << endl;
    
    for (auto it = v.begin(); it != v.end(); ++it) {
        *it *= 2;
    }
    
    cout << "Vector multiplicado por 2: ";
    for (int x : v) cout << x << " ";
    cout << endl;
    
    // ITERADORES DE INSERCION
    cout << "\n--- Iteradores de Insercion ---" << endl;
    
    vector<int> destino;
    
    // Back inserter
    copy(v.begin(), v.end(), back_inserter(destino));
    cout << "Copiado con back_inserter: ";
    for (int x : destino) cout << x << " ";
    cout << endl;
    
    // Insert iterator
    vector<int> v2 = {100, 200};
    copy(v.begin(), v.begin() + 3, inserter(v2, v2.begin() + 1));
    cout << "Insertado en posicion especifica: ";
    for (int x : v2) cout << x << " ";
    cout << endl;
    
    // ITERADORES DE STREAM
    cout << "\n--- Iteradores de Stream ---" << endl;
    
    cout << "Elementos separados por comas: ";
    copy(v.begin(), v.end(), ostream_iterator<int>(cout, ", "));
    cout << endl;
    
    // ADVANCE Y DISTANCE
    cout << "\n--- Advance y Distance ---" << endl;
    
    auto it = v.begin();
    advance(it, 3);
    cout << "Elemento en posicion 3: " << *it << endl;
    
    auto dist = distance(v.begin(), it);
    cout << "Distancia desde begin: " << dist << endl;
    
    // ITERADORES CON LISTA
    cout << "\n--- Iteradores con Lista ---" << endl;
    
    cout << "Lista: ";
    for (auto it = l.begin(); it != l.end(); ++it) {
        cout << *it << " ";
    }
    cout << endl;
    
    // Insertar en medio de la lista
    auto list_it = l.begin();
    advance(list_it, 2);
    l.insert(list_it, "NUEVO");
    
    cout << "Lista despues de insercion: ";
    for (const string& s : l) cout << s << " ";
    cout << endl;
    
    return 0;
}

// Codigo 85: STL Function Objects y Lambdas
#include <iostream>
#include <vector>
#include <algorithm>
#include <functional>
using namespace std;

// Function object personalizado
struct Multiplicador {
    int factor;
    
    Multiplicador(int f) : factor(f) {}
    
    int operator()(int x) const {
        return x * factor;
    }
};

// Predicado personalizado
struct EsMayorQue {
    int valor;
    
    EsMayorQue(int v) : valor(v) {}
    
    bool operator()(int x) const {
        return x > valor;
    }
};

int main() {
    cout << "=== FUNCTION OBJECTS Y LAMBDAS ===" << endl;
    
    vector<int> numeros = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    
    cout << "Vector original: ";
    for (int x : numeros) cout << x << " ";
    cout << endl;
    
    // FUNCTION OBJECTS PREDEFINIDOS
    cout << "\n--- Function Objects Predefinidos ---" << endl;
    
    vector<int> copia1 = numeros;
    sort(copia1.begin(), copia1.end(), greater<int>());
    cout << "Ordenado con greater: ";
    for (int x : copia1) cout << x << " ";
    cout << endl;
    
    // FUNCTION OBJECTS PERSONALIZADOS
    cout << "\n--- Function Objects Personalizados ---" << endl;
    
    vector<int> multiplicados(numeros.size());
    transform(numeros.begin(), numeros.end(), multiplicados.begin(), Multiplicador(3));
    cout << "Multiplicados por 3: ";
    for (int x : multiplicados) cout << x << " ";
    cout << endl;
    
    int cuenta = count_if(numeros.begin(), numeros.end(), EsMayorQue(5));
    cout << "Numeros mayores que 5: " << cuenta << endl;
    
    // LAMBDAS
    cout << "\n--- Lambdas ---" << endl;
    
    // Lambda simple
    auto cuadrado = [](int x) { return x * x; };
    vector<int> cuadrados(numeros.size());
    transform(numeros.begin(), numeros.end(), cuadrados.begin(), cuadrado);
    cout << "Cuadrados con lambda: ";
    for (int x : cuadrados) cout << x << " ";
    cout << endl;
    
    // Lambda con captura
    int limite = 6;
    auto esMenorQue = [limite](int x) { return x < limite; };
    int menores = count_if(numeros.begin(), numeros.end(), esMenorQue);
    cout << "Numeros menores que " << limite << ": " << menores << endl;
    
    // Lambda con captura por referencia
    int suma = 0;
    for_each(numeros.begin(), numeros.end(), [&suma](int x) { suma += x; });
    cout << "Suma calculada con lambda: " << suma << endl;
    
    // Lambda para filtrar
    vector<int> pares;
    copy_if(numeros.begin(), numeros.end(), back_inserter(pares), [](int x) { return x % 2 == 0; });
    cout << "Numeros pares: ";
    for (int x : pares) cout << x << " ";
    cout << endl;
    
    // Lambda compleja
    auto procesador = [](vector<int>& v, function<int(int)> func) {
        transform(v.begin(), v.end(), v.begin(), func);
    };
    
    vector<int> copia2 = numeros;
    procesador(copia2, [](int x) { return x * x + 1; });
    cout << "Procesado con lambda compleja (x^2 + 1): ";
    for (int x : copia2) cout << x << " ";
    cout << endl;
    
    return 0;
}

// Codigo 86: STL String y String Algorithms
#include <iostream>
#include <string>
#include <algorithm>
#include <sstream>
#include <vector>
using namespace std;

int main() {
    cout << "=== STL STRING Y ALGORITMOS ===" << endl;
    
    // CONSTRUCCION DE STRINGS
    cout << "\n--- Construccion de Strings ---" << endl;
    
    string s1 = "Hola";
    string s2("Mundo");
    string s3(5, 'A'); // "AAAAA"
    string s4(s1); // Copia
    
    cout << "s1: " << s1 << endl;
    cout << "s2: " << s2 << endl;
    cout << "s3: " << s3 << endl;
    cout << "s4: " << s4 << endl;
    
    // OPERACIONES BASICAS
    cout << "\n--- Operaciones Basicas ---" << endl;
    
    string frase = s1 + " " + s2;
    cout << "Concatenacion: " << frase << endl;
    
    frase += " con C++";
    cout << "Append: " << frase << endl;
    
    cout << "Longitud: " << frase.length() << endl;
    cout << "Caracter en posicion 5: " << frase[5] << endl;
    
    // BUSQUEDA
    cout << "\n--- Busqueda ---" << endl;
    
    size_t pos = frase.find("Mundo");
    if (pos != string::npos) {
        cout << "'Mundo' encontrado en posicion: " << pos << endl;
    }
    
    pos = frase.find_last_of('o');
    cout << "Ultima 'o' en posicion: " << pos << endl;
    
    // EXTRACCION Y MODIFICACION
    cout << "\n--- Extraccion y Modificacion ---" << endl;
    
    string subcadena = frase.substr(5, 5); // Desde posicion 5, 5 caracteres
    cout << "Subcadena: " << subcadena << endl;
    
    string copia = frase;
    copia.replace(0, 4, "Saludos");
    cout << "Reemplazado: " << copia << endl;
    
    // TRANSFORMACIONES
    cout << "\n--- Transformaciones ---" << endl;
    
    string mayusculas = frase;
    transform(mayusculas.begin(), mayusculas.end(), mayusculas.begin(), ::toupper);
    cout << "Mayusculas: " << mayusculas << endl;
    
    string minusculas = frase;
    transform(minusculas.begin(), minusculas.end(), minusculas.begin(), ::tolower);
    cout << "Minusculas: " << minusculas << endl;
    
    // ALGORITMOS CON STRINGS
    cout << "\n--- Algoritmos con Strings ---" << endl;
    
    string texto = "abcdefghijklmnop";
    cout << "Texto original: " << texto << endl;
    
    reverse(texto.begin(), texto.end());
    cout << "Texto invertido: " << texto << endl;
    
    // Contar vocales
    string prueba = "Esta es una prueba de conteo";
    int vocales = count_if(prueba.begin(), prueba.end(), [](char c) {
        c = tolower(c);
        return c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u';
    });
    cout << "Vocales en '" << prueba << "': " << vocales << endl;
    
    // STRINGSTREAM
    cout << "\n--- StringStream ---" << endl;
    
    stringstream ss;
    ss << "Numero: " << 42 << ", Pi: " << 3.14159;
    cout << "StringStream: " << ss.str() << endl;
    
    // Separar por espacios
    string linea = "uno dos tres cuatro cinco";
    stringstream iss(linea);
    vector<string> palabras;
    string palabra;
    
    while (iss >> palabra) {
        palabras.push_back(palabra);
    }
    
    cout << "Palabras separadas: ";
    for (const string& p : palabras) {
        cout << "[" << p << "] ";
    }
    cout << endl;
    
    return 0;
}

// Codigo 87: STL Smart Pointers (C++11/14/17)
#include <iostream>
#include <memory>
#include <vector>
#include <string>
using namespace std;

class Recurso {
private:
    string nombre;
    int id;
    
public:
    Recurso(const string& n, int i) : nombre(n), id(i) {
        cout << "Recurso '" << nombre << "' (ID: " << id << ") creado" << endl;
    }
    
    ~Recurso() {
        cout << "Recurso '" << nombre << "' (ID: " << id << ") destruido" << endl;
    }
    
    void usar() {
        cout << "Usando recurso '" << nombre << "' (ID: " << id << ")" << endl;
    }
    
    string getNombre() const { return nombre; }
    int getId() const { return id; }
};

void demoUniquePtr() {
    cout << "\n=== UNIQUE_PTR ===" << endl;
    
    // Crear unique_ptr
    auto ptr1 = make_unique<Recurso>("UniqueRecurso1", 1);
    ptr1->usar();
    
    // Transferir propiedad
    auto ptr2 = move(ptr1);
    
    if (!ptr1) {
        cout << "ptr1 ya no posee el recurso" << endl;
    }
    
    if (ptr2) {
        cout << "ptr2 ahora posee el recurso" << endl;
        ptr2->usar();
    }
    
    // Crear array de unique_ptr
    auto arr = make_unique<int[]>(5);
    for (int i = 0; i < 5; i++) {
        arr[i] = i * i;
    }
    
    cout << "Array de unique_ptr: ";
    for (int i = 0; i < 5; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;
}

void demoSharedPtr() {
    cout << "\n=== SHARED_PTR ===" << endl;
    
    // Crear shared_ptr
    auto ptr1 = make_shared<Recurso>("SharedRecurso1", 2);
    cout << "Contador de referencias: " << ptr1.use_count() << endl;
    
    {
        auto ptr2 = ptr1; // Copia el shared_ptr
        cout << "Contador de referencias en bloque interno: " << ptr1.use_count() << endl;
        
        auto ptr3 = ptr1;
        cout << "Contador con ptr3: " << ptr1.use_count() << endl;
        
        ptr2->usar();
        ptr3->usar();
        
        // ptr2 y ptr3 se destruyen al salir del bloque
    }
    
    cout << "Contador despues del bloque: " << ptr1.use_count() << endl;
    ptr1->usar();
    
    // Vector de shared_ptr
    vector<shared_ptr<Recurso>> recursos;
    recursos.push_back(make_shared<Recurso>("Recurso_A", 10));
    recursos.push_back(make_shared<Recurso>("Recurso_B", 11));
    recursos.push_back(ptr1); // Compartir el recurso existente
    
    cout << "\nRecursos en vector:" << endl;
    for (auto& r : recursos) {
        r->usar();
        cout << "  Referencias: " << r.use_count() << endl;
    }
}

void demoWeakPtr() {
    cout << "\n=== WEAK_PTR ===" << endl;
    
    shared_ptr<Recurso> shared;
    weak_ptr<Recurso> weak;
    
    {
        shared = make_shared<Recurso>("WeakRecurso1", 3);
        weak = shared;
        
        cout << "Referencias de shared: " << shared.use_count() << endl;
        cout << "weak_ptr expirado? " << (weak.expired() ? "Si" : "No") << endl;
        
        // Usar weak_ptr
        if (auto locked = weak.lock()) {
            locked->usar();
            cout << "Acceso exitoso via weak_ptr" << endl;
        }
    }
    
    // shared sale del scope pero aun existe
    cout << "Referencias despues del bloque: " << shared.use_count() << endl;
    
    // Destruir el shared_ptr
    shared.reset();
    
    cout << "weak_ptr expirado despues de reset? " << (weak.expired() ? "Si" : "No") << endl;
    
    // Intentar acceder via weak_ptr
    if (auto locked = weak.lock()) {
        locked->usar();
        cout << "Acceso via weak_ptr" << endl;
    } else {
        cout << "No se puede acceder, el recurso ya no existe" << endl;
    }
}

class Padre;
class Hijo;

class Padre {
public:
    string nombre;
    vector<shared_ptr<Hijo>> hijos;
    
    Padre(const string& n) : nombre(n) {
        cout << "Padre '" << nombre << "' creado" << endl;
    }
    
    ~Padre() {
        cout << "Padre '" << nombre << "' destruido" << endl;
    }
    
    void agregarHijo(shared_ptr<Hijo> hijo);
};

class Hijo {
public:
    string nombre;
    weak_ptr<Padre> padre; // Usar weak_ptr para evitar ciclos
    
    Hijo(const string& n) : nombre(n) {
        cout << "Hijo '" << nombre << "' creado" << endl;
    }
    
    ~Hijo() {
        cout << "Hijo '" << nombre << "' destruido" << endl;
    }
};

void Padre::agregarHijo(shared_ptr<Hijo> hijo) {
    hijos.push_back(hijo);
    hijo->padre = shared_from_this();
}

void demoCiclosYWeakPtr() {
    cout << "\n=== EVITAR CICLOS CON WEAK_PTR ===" << endl;
    
    {
        auto padre = make_shared<Padre>("Papa");
        auto hijo1 = make_shared<Hijo>("Hijo1");
        auto hijo2 = make_shared<Hijo>("Hijo2");
        
        padre->agregarHijo(hijo1);
        padre->agregarHijo(hijo2);
        
        cout << "Referencias del padre: " << padre.use_count() << endl;
        cout << "Referencias del hijo1: " << hijo1.use_count() << endl;
        
        // Los objetos se destruiran correctamente al salir del scope
    }
    
    cout << "Todos los objetos destruidos correctamente" << endl;
}

int main() {
    cout << "=== STL SMART POINTERS ===" << endl;
    
    demoUniquePtr();
    demoSharedPtr();
    demoWeakPtr();
    demoCiclosYWeakPtr();
    
    cout << "\nPrograma terminado" << endl;
    
    return 0;
}

// Codigo 88: STL Containers Avanzados
#include <iostream>
#include <deque>
#include <queue>
#include <stack>
#include <unordered_map>
#include <unordered_set>
using namespace std;

int main() {
    cout << "=== STL CONTAINERS AVANZADOS ===" << endl;
    
    // DEQUE
    cout << "\n--- DEQUE ---" << endl;
    deque<int> dq = {3, 4, 5};
    
    dq.push_front(2);
    dq.push_front(1);
    dq.push_back(6);
    dq.push_back(7);
    
    cout << "Deque: ";
    for (int x : dq) cout << x << " ";
    cout << endl;
    
    cout << "Primer elemento: " << dq.front() << endl;
    cout << "Ultimo elemento: " << dq.back() << endl;
    
    dq.pop_front();
    dq.pop_back();
    
    cout << "Despues de pop_front y pop_back: ";
    for (int x : dq) cout << x << " ";
    cout << endl;
    
    // STACK
    cout << "\n--- STACK ---" << endl;
    stack<string> pila;
    
    pila.push("Primero");
    pila.push("Segundo");
    pila.push("Tercero");
    
    cout << "Tamaño de la pila: " << pila.size() << endl;
    
    while (!pila.empty()) {
        cout << "Pop: " << pila.top() << endl;
        pila.pop();
    }
    
    // QUEUE
    cout << "\n--- QUEUE ---" << endl;
    queue<int> cola;
    
    for (int i = 1; i <= 5; i++) {
        cola.push(i * 10);
        cout << "Enqueue: " << i * 10 << endl;
    }
    
    cout << "Tamaño de la cola: " << cola.size() << endl;
    
    while (!cola.empty()) {
        cout << "Dequeue: " << cola.front() << endl;
        cola.pop();
    }
    
    // PRIORITY_QUEUE
    cout << "\n--- PRIORITY_QUEUE ---" << endl;
    priority_queue<int> pq; // Max-heap por defecto
    
    vector<int> valores = {3, 1, 4, 1, 5, 9, 2, 6};
    for (int v : valores) {
        pq.push(v);
        cout << "Insertado: " << v << endl;
    }
    
    cout << "Extrayendo en orden de prioridad (mayor a menor):" << endl;
    while (!pq.empty()) {
        cout << pq.top() << " ";
        pq.pop();
    }
    cout << endl;
    
    // Priority queue con orden personalizado (min-heap)
    priority_queue<int, vector<int>, greater<int>> min_pq;
    for (int v : valores) {
        min_pq.push(v);
    }
    
    cout << "Min-heap (menor a mayor):" << endl;
    while (!min_pq.empty()) {
        cout << min_pq.top() << " ";
        min_pq.pop();
    }
    cout << endl;
    
    // UNORDERED_MAP (Hash Map)
    cout << "\n--- UNORDERED_MAP ---" << endl;
    unordered_map<string, int> hash_map;
    
    hash_map["manzana"] = 5;
    hash_map["banana"] = 3;
    hash_map["naranja"] = 8;
    hash_map.insert({"uva", 12});
    
    cout << "Hash Map (orden no garantizado):" << endl;
    for (const auto& par : hash_map) {
        cout << par.first << ": " << par.second << endl;
    }
    
    // Busqueda rapida O(1) promedio
    string fruta = "banana";
    auto it = hash_map.find(fruta);
    if (it != hash_map.end()) {
        cout << "Encontrado " << fruta << ": " << it->second << endl;
    }
    
    cout << "Factores de carga:" << endl;
    cout << "  Tamaño: " << hash_map.size() << endl;
    cout << "  Buckets: " << hash_map.bucket_count() << endl;
    cout << "  Factor de carga: " << hash_map.load_factor() << endl;
    
    // UNORDERED_SET (Hash Set)
    cout << "\n--- UNORDERED_SET ---" << endl;
    unordered_set<int> hash_set = {5, 2, 8, 1, 9, 2, 5}; // Duplicados eliminados
    
    cout << "Hash Set (elementos unicos, orden no garantizado): ";
    for (int x : hash_set) {
        cout << x << " ";
    }
    cout << endl;
    
    // Insercion y busqueda O(1) promedio
    hash_set.insert(15);
    hash_set.insert(3);
    
    if (hash_set.find(8) != hash_set.end()) {
        cout << "El numero 8 esta en el set" << endl;
    }
    
    if (hash_set.count(10) == 0) {
        cout << "El numero 10 NO esta en el set" << endl;
    }
    
    return 0;
}

// Codigo 89: STL Parallel Algorithms (C++17)
#include <iostream>
#include <vector>
#include <algorithm>
#include <execution>
#include <chrono>
#include <random>
using namespace std;
using namespace std::chrono;

int main() {
    cout << "=== STL PARALLEL ALGORITHMS (C++17) ===" << endl;
    
    // Generar datos de prueba
    const size_t SIZE = 1000000;
    vector<int> datos(SIZE);
    
    random_device rd;
    mt19937 gen(rd());
    uniform_int_distribution<int> dis(1, 1000);
    
    generate(datos.begin(), datos.end(), [&]() { return dis(gen); });
    
    cout << "Generados " << SIZE << " elementos aleatorios" << endl;
    
    // ORDENAMIENTO SECUENCIAL VS PARALELO
    cout << "\n--- Comparacion de Ordenamiento ---" << endl;
    
    // Ordenamiento secuencial
    vector<int> datos_seq = datos;
    auto inicio = high_resolution_clock::now();
    sort(datos_seq.begin(), datos_seq.end());
    auto fin = high_resolution_clock::now();
    auto duracion_seq = duration_cast<milliseconds>(fin - inicio);
    
    cout << "Ordenamiento secuencial: " << duracion_seq.count() << " ms" << endl;
    
    // Ordenamiento paralelo
    vector<int> datos_par = datos;
    inicio = high_resolution_clock::now();
    sort(execution::par, datos_par.begin(), datos_par.end());
    fin = high_resolution_clock::now();
    auto duracion_par = duration_cast<milliseconds>(fin - inicio);
    
    cout << "Ordenamiento paralelo: " << duracion_par.count() << " ms" << endl;
    
    if (duracion_seq.count() > 0) {
        double speedup = (double)duracion_seq.count() / duracion_par.count();
        cout << "Speedup: " << speedup << "x" << endl;
    }
    
    // Verificar que ambos resultados son iguales
    bool iguales = equal(datos_seq.begin(), datos_seq.end(), datos_par.begin());
    cout << "Resultados iguales: " << (iguales ? "Si" : "No") << endl;
    
    // BUSQUEDA PARALELA
    cout << "\n--- Busqueda Paralela ---" << endl;
    
    int objetivo = 500;
    
    // Busqueda secuencial
    inicio = high_resolution_clock::now();
    auto it_seq = find(datos_seq.begin(), datos_seq.end(), objetivo);
    fin = high_resolution_clock::now();
    duracion_seq = duration_cast<microseconds>(fin - inicio);
    
    // Busqueda paralela
    inicio = high_resolution_clock::now();
    auto it_par = find(execution::par, datos_par.begin(), datos_par.end(), objetivo);
    fin = high_resolution_clock::now();
    duracion_par = duration_cast<microseconds>(fin - inicio);
    
    cout << "Busqueda secuencial: " << duracion_seq.count() << " microsegundos" << endl;
    cout << "Busqueda paralela: " << duracion_par.count() << " microsegundos" << endl;
    
    // TRANSFORMACION PARALELA
    cout << "\n--- Transformacion Paralela ---" << endl;
    
    vector<int> cuadrados_seq(SIZE);
    vector<int> cuadrados_par(SIZE);
    
    // Transformacion secuencial
    inicio = high_resolution_clock::now();
    transform(datos.begin(), datos.end(), cuadrados_seq.begin(), [](int x) { return x * x; });
    fin = high_resolution_clock::now();
    duracion_seq = duration_cast<milliseconds>(fin - inicio);
    
    // Transformacion paralela
    inicio = high_resolution_clock::now();
    transform(execution::par, datos.begin(), datos.end(), cuadrados_par.begin(), [](int x) { return x * x; });
    fin = high_resolution_clock::now();
    duracion_par = duration_cast<milliseconds>(fin - inicio);
    
    cout << "Transform secuencial: " << duracion_seq.count() << " ms" << endl;
    cout << "Transform paralelo: " << duracion_par.count() << " ms" << endl;
    
    // FOR_EACH PARALELO
    cout << "\n--- For_Each Paralelo ---" << endl;
    
    vector<int> datos_modificar = datos;
    
    // Modificar todos los elementos en paralelo
    for_each(execution::par, datos_modificar.begin(), datos_modificar.end(), 
             [](int& x) { x = x * 2 + 1; });
    
    cout << "Todos los elementos modificados en paralelo" << endl;
    
    // REDUCE PARALELO
    cout << "\n--- Reduce Paralelo ---" << endl;
    
    // Suma secuencial
    inicio = high_resolution_clock::now();
    long long suma_seq = 0;
    for (int x : datos) {
        suma_seq += x;
    }
    fin = high_resolution_clock::now();
    duracion_seq = duration_cast<microseconds>(fin - inicio);
    
    // Suma paralela
    inicio = high_resolution_clock::now();
    long long suma_par = reduce(execution::par, datos.begin(), datos.end(), 0LL);
    fin = high_resolution_clock::now();
    duracion_par = duration_cast<microseconds>(fin - inicio);
    
    cout << "Suma secuencial: " << suma_seq << " (" << duracion_seq.count() << " us)" << endl;
    cout << "Suma paralela: " << suma_par << " (" << duracion_par.count() << " us)" << endl;
    cout << "Resultados iguales: " << (suma_seq == suma_par ? "Si" : "No") << endl;
    
    // CONTEO PARALELO
    cout << "\n--- Conteo Paralelo ---" << endl;
    
    int limite = 500;
    
    // Contar elementos mayores que limite
    size_t count_seq = count_if(datos.begin(), datos.end(), [limite](int x) { return x > limite; });
    size_t count_par = count_if(execution::par, datos.begin(), datos.end(), [limite](int x) { return x > limite; });
    
    cout << "Elementos > " << limite << " (secuencial): " << count_seq << endl;
    cout << "Elementos > " << limite << " (paralelo): " << count_par << endl;
    
    return 0;
}

// Codigo 90: STL Ranges (C++20)
#include <iostream>
#include <vector>
#include <ranges>
#include <algorithm>
#include <string>
using namespace std;
using namespace std::ranges;

int main() {
    cout << "=== STL RANGES (C++20) ===" << endl;
    
    vector<int> numeros = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    
    cout << "Vector original: ";
    for (int x : numeros) cout << x << " ";
    cout << endl;
    
    // VIEWS BASICOS
    cout << "\n--- Views Basicos ---" << endl;
    
    // Filter view
    auto pares = numeros | views::filter([](int x) { return x % 2 == 0; });
    cout << "Numeros pares: ";
    for (int x : pares) cout << x << " ";
    cout << endl;
    
    // Transform view
    auto cuadrados = numeros | views::transform([](int x) { return x * x; });
    cout << "Cuadrados: ";
    for (int x : cuadrados) cout << x << " ";
    cout << endl;
    
    // Take view
    auto primeros5 = numeros | views::take(5);
    cout << "Primeros 5: ";
    for (int x : primeros5) cout << x << " ";
    cout << endl;
    
    // Drop view
    auto sin_primeros3 = numeros | views::drop(3);
    cout << "Sin primeros 3: ";
    for (int x : sin_primeros3) cout << x << " ";
    cout << endl;
    
    // COMPOSICION DE VIEWS
    cout << "\n--- Composicion de Views ---" << endl;
    
    // Combinar multiples operaciones
    auto resultado = numeros 
        | views::filter([](int x) { return x > 3; })  // Filtrar > 3
        | views::transform([](int x) { return x * 2; }) // Multiplicar por 2
        | views::take(4);                               // Tomar primeros 4
    
    cout << "Numeros > 3, multiplicados por 2, primeros 4: ";
    for (int x : resultado) cout << x << " ";
    cout << endl;
    
    // VIEWS CON STRINGS
    cout << "\n--- Views con Strings ---" << endl;
    
    vector<string> palabras = {"hola", "mundo", "c++", "ranges", "son", "geniales"};
    
    // Filtrar palabras largas y convertir a mayusculas
    auto palabras_largas = palabras 
        | views::filter([](const string& s) { return s.length() > 3; })
        | views::transform([](const string& s) {
            string resultado = s;
            transform(resultado.begin(), resultado.end(), resultado.begin(), ::toupper);
            return resultado;
        });
    
    cout << "Palabras largas en mayusculas: ";
    for (const auto& palabra : palabras_largas) {
        cout << palabra << " ";
    }
    cout << endl;
    
    // RANGES ALGORITHMS
    cout << "\n--- Ranges Algorithms ---" << endl;
    
    vector<int> datos = {9, 3, 7, 1, 5, 2, 8, 4, 6};
    
    cout << "Datos originales: ";
    for (int x : datos) cout << x << " ";
    cout << endl;
    
    // Sort con ranges
    sort(datos);
    cout << "Ordenados: ";
    for (int x : datos) cout << x << " ";
    cout << endl;
    
    // Find con ranges
    auto it = find(datos, 5);
    if (it != datos.end()) {
        cout << "Elemento 5 encontrado" << endl;
    }
    
    // Count_if con ranges
    auto count = count_if(datos, [](int x) { return x > 5; });
    cout << "Elementos > 5: " << count << endl;
    
    // GENERATE VIEWS
    cout << "\n--- Generate Views ---" << endl;
    
    // Iota view (secuencia numerica)
    auto secuencia = views::iota(1, 11); // Numeros del 1 al 10
    cout << "Secuencia 1-10: ";
    for (int x : secuencia) cout << x << " ";
    cout << endl;
    
    // Repeat view
    auto repetidos = views::repeat(42) | views::take(5);
    cout << "Repetir 42, 5 veces: ";
    for (int x : repetidos) cout << x << " ";
    cout << endl;
    
    // EJEMPLO COMPLEJO
    cout << "\n--- Ejemplo Complejo ---" << endl;
    
    // Generar numeros del 1 al 100, filtrar multiplos de 3 o 5,
    // elevar al cuadrado, tomar primeros 10
    auto fibonacci_like = views::iota(1, 101)
        | views::filter([](int x) { return x % 3 == 0 || x % 5 == 0; })
        | views::transform([](int x) { return x * x; })
        | views::take(10);
    
    cout << "Cuadrados de multiplos de 3 o 5 (primeros 10): ";
    for (int x : fibonacci_like) cout << x << " ";
    cout << endl;
    
    // RANGES CON CONTENEDORES PERSONALIZADOS
    cout << "\n--- Conversion a Contenedores ---" << endl;
    
    // Convertir view a vector
    auto pares_vector = numeros 
        | views::filter([](int x) { return x % 2 == 0; })
        | to<vector>();
    
    cout << "Pares en vector: ";
    for (int x : pares_vector) cout << x << " ";
    cout << endl;
    
    cout << "Tipo del contenedor: vector<int>" << endl;
    cout << "Tamaño: " << pares_vector.size() << endl;
    
    return 0;
}