// Codigo 71: Algoritmo de Busqueda Binaria
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int busquedaBinaria(const vector<int>& arr, int objetivo) {
    int izquierda = 0;
    int derecha = arr.size() - 1;
    
    while (izquierda <= derecha) {
        int medio = izquierda + (derecha - izquierda) / 2;
        
        if (arr[medio] == objetivo) {
            return medio;
        }
        
        if (arr[medio] < objetivo) {
            izquierda = medio + 1;
        } else {
            derecha = medio - 1;
        }
    }
    
    return -1; // No encontrado
}

int main() {
    vector<int> numeros = {1, 3, 5, 7, 9, 11, 13, 15, 17, 19};
    int objetivo;
    
    cout << "=== BUSQUEDA BINARIA ===" << endl;
    cout << "Array ordenado: ";
    for (int num : numeros) {
        cout << num << " ";
    }
    cout << endl;
    
    cout << "Ingrese el numero a buscar: ";
    cin >> objetivo;
    
    int posicion = busquedaBinaria(numeros, objetivo);
    
    if (posicion != -1) {
        cout << "Numero encontrado en la posicion: " << posicion << endl;
    } else {
        cout << "Numero no encontrado" << endl;
    }
    
    return 0;
}

// Codigo 72: Algoritmos de Ordenamiento
#include <iostream>
#include <vector>
#include <chrono>
using namespace std;
using namespace std::chrono;

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

void ordenamientoSeleccion(vector<int>& arr) {
    int n = arr.size();
    for (int i = 0; i < n - 1; i++) {
        int minIdx = i;
        for (int j = i + 1; j < n; j++) {
            if (arr[j] < arr[minIdx]) {
                minIdx = j;
            }
        }
        swap(arr[i], arr[minIdx]);
    }
}

void ordenamientoInsercion(vector<int>& arr) {
    int n = arr.size();
    for (int i = 1; i < n; i++) {
        int clave = arr[i];
        int j = i - 1;
        
        while (j >= 0 && arr[j] > clave) {
            arr[j + 1] = arr[j];
            j--;
        }
        arr[j + 1] = clave;
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

void imprimirArray(const vector<int>& arr) {
    for (int num : arr) {
        cout << num << " ";
    }
    cout << endl;
}

vector<int> generarArrayAleatorio(int tamaño) {
    vector<int> arr(tamaño);
    for (int i = 0; i < tamaño; i++) {
        arr[i] = rand() % 100;
    }
    return arr;
}

int main() {
    srand(time(0));
    
    cout << "=== ALGORITMOS DE ORDENAMIENTO ===" << endl;
    
    vector<int> original = generarArrayAleatorio(10);
    cout << "Array original: ";
    imprimirArray(original);
    
    // Burbuja
    vector<int> arr1 = original;
    auto inicio = high_resolution_clock::now();
    ordenamientoBurbuja(arr1);
    auto fin = high_resolution_clock::now();
    auto duracion = duration_cast<microseconds>(fin - inicio);
    
    cout << "\nOrdenamiento Burbuja: ";
    imprimirArray(arr1);
    cout << "Tiempo: " << duracion.count() << " microsegundos" << endl;
    
    // Seleccion
    vector<int> arr2 = original;
    inicio = high_resolution_clock::now();
    ordenamientoSeleccion(arr2);
    fin = high_resolution_clock::now();
    duracion = duration_cast<microseconds>(fin - inicio);
    
    cout << "\nOrdenamiento Seleccion: ";
    imprimirArray(arr2);
    cout << "Tiempo: " << duracion.count() << " microsegundos" << endl;
    
    // Insercion
    vector<int> arr3 = original;
    inicio = high_resolution_clock::now();
    ordenamientoInsercion(arr3);
    fin = high_resolution_clock::now();
    duracion = duration_cast<microseconds>(fin - inicio);
    
    cout << "\nOrdenamiento Insercion: ";
    imprimirArray(arr3);
    cout << "Tiempo: " << duracion.count() << " microsegundos" << endl;
    
    // QuickSort
    vector<int> arr4 = original;
    inicio = high_resolution_clock::now();
    quickSort(arr4, 0, arr4.size() - 1);
    fin = high_resolution_clock::now();
    duracion = duration_cast<microseconds>(fin - inicio);
    
    cout << "\nQuickSort: ";
    imprimirArray(arr4);
    cout << "Tiempo: " << duracion.count() << " microsegundos" << endl;
    
    return 0;
}

// Codigo 73: Arbol Binario de Busqueda
#include <iostream>
using namespace std;

struct NodoArbol {
    int dato;
    NodoArbol* izquierdo;
    NodoArbol* derecho;
    
    NodoArbol(int valor) : dato(valor), izquierdo(nullptr), derecho(nullptr) {}
};

class ArbolBinarioBusqueda {
private:
    NodoArbol* raiz;
    
    NodoArbol* insertar(NodoArbol* nodo, int valor) {
        if (nodo == nullptr) {
            return new NodoArbol(valor);
        }
        
        if (valor < nodo->dato) {
            nodo->izquierdo = insertar(nodo->izquierdo, valor);
        } else if (valor > nodo->dato) {
            nodo->derecho = insertar(nodo->derecho, valor);
        }
        
        return nodo;
    }
    
    NodoArbol* buscar(NodoArbol* nodo, int valor) {
        if (nodo == nullptr || nodo->dato == valor) {
            return nodo;
        }
        
        if (valor < nodo->dato) {
            return buscar(nodo->izquierdo, valor);
        }
        
        return buscar(nodo->derecho, valor);
    }
    
    void inorden(NodoArbol* nodo) {
        if (nodo != nullptr) {
            inorden(nodo->izquierdo);
            cout << nodo->dato << " ";
            inorden(nodo->derecho);
        }
    }
    
    void preorden(NodoArbol* nodo) {
        if (nodo != nullptr) {
            cout << nodo->dato << " ";
            preorden(nodo->izquierdo);
            preorden(nodo->derecho);
        }
    }
    
    void postorden(NodoArbol* nodo) {
        if (nodo != nullptr) {
            postorden(nodo->izquierdo);
            postorden(nodo->derecho);
            cout << nodo->dato << " ";
        }
    }
    
    NodoArbol* encontrarMinimo(NodoArbol* nodo) {
        while (nodo->izquierdo != nullptr) {
            nodo = nodo->izquierdo;
        }
        return nodo;
    }
    
    NodoArbol* eliminar(NodoArbol* nodo, int valor) {
        if (nodo == nullptr) {
            return nodo;
        }
        
        if (valor < nodo->dato) {
            nodo->izquierdo = eliminar(nodo->izquierdo, valor);
        } else if (valor > nodo->dato) {
            nodo->derecho = eliminar(nodo->derecho, valor);
        } else {
            // Nodo a eliminar encontrado
            if (nodo->izquierdo == nullptr) {
                NodoArbol* temp = nodo->derecho;
                delete nodo;
                return temp;
            } else if (nodo->derecho == nullptr) {
                NodoArbol* temp = nodo->izquierdo;
                delete nodo;
                return temp;
            }
            
            // Nodo con dos hijos
            NodoArbol* temp = encontrarMinimo(nodo->derecho);
            nodo->dato = temp->dato;
            nodo->derecho = eliminar(nodo->derecho, temp->dato);
        }
        
        return nodo;
    }
    
    void destruir(NodoArbol* nodo) {
        if (nodo != nullptr) {
            destruir(nodo->izquierdo);
            destruir(nodo->derecho);
            delete nodo;
        }
    }
    
public:
    ArbolBinarioBusqueda() : raiz(nullptr) {}
    
    ~ArbolBinarioBusqueda() {
        destruir(raiz);
    }
    
    void insertar(int valor) {
        raiz = insertar(raiz, valor);
    }
    
    bool buscar(int valor) {
        return buscar(raiz, valor) != nullptr;
    }
    
    void eliminar(int valor) {
        raiz = eliminar(raiz, valor);
    }
    
    void mostrarInorden() {
        cout << "Inorden: ";
        inorden(raiz);
        cout << endl;
    }
    
    void mostrarPreorden() {
        cout << "Preorden: ";
        preorden(raiz);
        cout << endl;
    }
    
    void mostrarPostorden() {
        cout << "Postorden: ";
        postorden(raiz);
        cout << endl;
    }
};

int main() {
    cout << "=== ARBOL BINARIO DE BUSQUEDA ===" << endl;
    
    ArbolBinarioBusqueda arbol;
    int opcion, valor;
    
    do {
        cout << "\n--- MENU ARBOL ---" << endl;
        cout << "1. Insertar" << endl;
        cout << "2. Buscar" << endl;
        cout << "3. Eliminar" << endl;
        cout << "4. Mostrar recorridos" << endl;
        cout << "0. Salir" << endl;
        cout << "Opcion: ";
        cin >> opcion;
        
        switch (opcion) {
            case 1:
                cout << "Valor a insertar: ";
                cin >> valor;
                arbol.insertar(valor);
                cout << "Valor insertado" << endl;
                break;
                
            case 2:
                cout << "Valor a buscar: ";
                cin >> valor;
                if (arbol.buscar(valor)) {
                    cout << "Valor encontrado" << endl;
                } else {
                    cout << "Valor no encontrado" << endl;
                }
                break;
                
            case 3:
                cout << "Valor a eliminar: ";
                cin >> valor;
                arbol.eliminar(valor);
                cout << "Valor eliminado (si existia)" << endl;
                break;
                
            case 4:
                cout << "\nRecorridos del arbol:" << endl;
                arbol.mostrarInorden();
                arbol.mostrarPreorden();
                arbol.mostrarPostorden();
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

// Codigo 74: Algoritmo de Dijkstra
#include <iostream>
#include <vector>
#include <queue>
#include <climits>
using namespace std;

class Grafo {
private:
    int vertices;
    vector<vector<pair<int, int>>> adyacencia;
    
public:
    Grafo(int v) : vertices(v), adyacencia(v) {}
    
    void agregarArista(int origen, int destino, int peso) {
        adyacencia[origen].push_back({destino, peso});
        adyacencia[destino].push_back({origen, peso}); // Para grafo no dirigido
    }
    
    vector<int> dijkstra(int origen) {
        vector<int> distancia(vertices, INT_MAX);
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
        
        distancia[origen] = 0;
        pq.push({0, origen});
        
        while (!pq.empty()) {
            int u = pq.top().second;
            pq.pop();
            
            for (auto& arista : adyacencia[u]) {
                int v = arista.first;
                int peso = arista.second;
                
                if (distancia[u] + peso < distancia[v]) {
                    distancia[v] = distancia[u] + peso;
                    pq.push({distancia[v], v});
                }
            }
        }
        
        return distancia;
    }
    
    void mostrarGrafo() {
        cout << "\nRepresentacion del grafo:" << endl;
        for (int i = 0; i < vertices; i++) {
            cout << "Vertice " << i << ": ";
            for (auto& arista : adyacencia[i]) {
                cout << "(" << arista.first << ", peso: " << arista.second << ") ";
            }
            cout << endl;
        }
    }
};

int main() {
    cout << "=== ALGORITMO DE DIJKSTRA ===" << endl;
    
    // Crear grafo de ejemplo
    Grafo grafo(6);
    
    // Agregar aristas (origen, destino, peso)
    grafo.agregarArista(0, 1, 4);
    grafo.agregarArista(0, 2, 3);
    grafo.agregarArista(1, 2, 1);
    grafo.agregarArista(1, 3, 2);
    grafo.agregarArista(2, 3, 4);
    grafo.agregarArista(3, 4, 2);
    grafo.agregarArista(4, 5, 6);
    
    grafo.mostrarGrafo();
    
    int origen;
    cout << "\nIngrese el vertice de origen (0-5): ";
    cin >> origen;
    
    if (origen >= 0 && origen < 6) {
        vector<int> distancias = grafo.dijkstra(origen);
        
        cout << "\nDistancias mas cortas desde el vertice " << origen << ":" << endl;
        for (int i = 0; i < 6; i++) {
            if (distancias[i] == INT_MAX) {
                cout << "Vertice " << i << ": INF" << endl;
            } else {
                cout << "Vertice " << i << ": " << distancias[i] << endl;
            }
        }
    } else {
        cout << "Vertice invalido" << endl;
    }
    
    return 0;
}

// Codigo 75: Algoritmo de Floyd-Warshall
#include <iostream>
#include <vector>
#include <iomanip>
using namespace std;

const int INF = 1e9;

class GrafoFloyd {
private:
    int vertices;
    vector<vector<int>> matriz;
    
public:
    GrafoFloyd(int v) : vertices(v), matriz(v, vector<int>(v, INF)) {
        // Inicializar diagonal con ceros
        for (int i = 0; i < vertices; i++) {
            matriz[i][i] = 0;
        }
    }
    
    void agregarArista(int origen, int destino, int peso) {
        matriz[origen][destino] = peso;
    }
    
    void floydWarshall() {
        cout << "\nEjecutando algoritmo de Floyd-Warshall..." << endl;
        
        for (int k = 0; k < vertices; k++) {
            for (int i = 0; i < vertices; i++) {
                for (int j = 0; j < vertices; j++) {
                    if (matriz[i][k] != INF && matriz[k][j] != INF) {
                        matriz[i][j] = min(matriz[i][j], matriz[i][k] + matriz[k][j]);
                    }
                }
            }
        }
    }
    
    void mostrarMatriz(const string& titulo) {
        cout << "\n" << titulo << ":" << endl;
        cout << "    ";
        for (int i = 0; i < vertices; i++) {
            cout << setw(6) << i;
        }
        cout << endl;
        
        for (int i = 0; i < vertices; i++) {
            cout << setw(2) << i << ": ";
            for (int j = 0; j < vertices; j++) {
                if (matriz[i][j] == INF) {
                    cout << setw(6) << "INF";
                } else {
                    cout << setw(6) << matriz[i][j];
                }
            }
            cout << endl;
        }
    }
    
    void mostrarCamino(int origen, int destino) {
        if (matriz[origen][destino] == INF) {
            cout << "No hay camino de " << origen << " a " << destino << endl;
        } else {
            cout << "Distancia mas corta de " << origen << " a " << destino 
                 << ": " << matriz[origen][destino] << endl;
        }
    }
};

int main() {
    cout << "=== ALGORITMO DE FLOYD-WARSHALL ===" << endl;
    
    // Crear grafo dirigido de 4 vertices
    GrafoFloyd grafo(4);
    
    // Agregar aristas
    grafo.agregarArista(0, 1, 3);
    grafo.agregarArista(0, 3, 7);
    grafo.agregarArista(1, 0, 8);
    grafo.agregarArista(1, 2, 2);
    grafo.agregarArista(2, 0, 5);
    grafo.agregarArista(2, 3, 1);
    grafo.agregarArista(3, 0, 2);
    
    grafo.mostrarMatriz("Matriz de adyacencia inicial");
    
    grafo.floydWarshall();
    
    grafo.mostrarMatriz("Matriz de distancias minimas");
    
    // Mostrar algunos caminos especificos
    cout << "\nConsultas de caminos:" << endl;
    grafo.mostrarCamino(0, 2);
    grafo.mostrarCamino(1, 3);
    grafo.mostrarCamino(2, 1);
    
    return 0;
}

// Codigo 76: Hash Table (Tabla Hash)
#include <iostream>
#include <vector>
#include <list>
#include <string>
using namespace std;

template<typename K, typename V>
class TablaHash {
private:
    struct Par {
        K clave;
        V valor;
        
        Par(const K& k, const V& v) : clave(k), valor(v) {}
    };
    
    vector<list<Par>> tabla;
    int tamaño;
    int elementos;
    
    int hash(const K& clave) {
        return std::hash<K>{}(clave) % tamaño;
    }
    
    void redimensionar() {
        if (elementos > tamaño * 0.75) { // Factor de carga > 0.75
            vector<list<Par>> tablaAntigua = tabla;
            tamaño *= 2;
            tabla.clear();
            tabla.resize(tamaño);
            elementos = 0;
            
            // Reinsertar todos los elementos
            for (auto& lista : tablaAntigua) {
                for (auto& par : lista) {
                    insertar(par.clave, par.valor);
                }
            }
        }
    }
    
public:
    TablaHash(int tam = 10) : tamaño(tam), elementos(0) {
        tabla.resize(tamaño);
    }
    
    void insertar(const K& clave, const V& valor) {
        int indice = hash(clave);
        
        // Verificar si la clave ya existe
        for (auto& par : tabla[indice]) {
            if (par.clave == clave) {
                par.valor = valor; // Actualizar valor existente
                return;
            }
        }
        
        // Insertar nuevo par
        tabla[indice].emplace_back(clave, valor);
        elementos++;
        redimensionar();
    }
    
    bool buscar(const K& clave, V& valor) {
        int indice = hash(clave);
        
        for (auto& par : tabla[indice]) {
            if (par.clave == clave) {
                valor = par.valor;
                return true;
            }
        }
        
        return false;
    }
    
    bool eliminar(const K& clave) {
        int indice = hash(clave);
        
        auto& lista = tabla[indice];
        for (auto it = lista.begin(); it != lista.end(); ++it) {
            if (it->clave == clave) {
                lista.erase(it);
                elementos--;
                return true;
            }
        }
        
        return false;
    }
    
    void mostrarEstadisticas() {
        cout << "\nEstadisticas de la tabla hash:" << endl;
        cout << "Tamaño: " << tamaño << endl;
        cout << "Elementos: " << elementos << endl;
        cout << "Factor de carga: " << (double)elementos / tamaño << endl;
        
        int buckets_usados = 0;
        int max_colisiones = 0;
        
        for (int i = 0; i < tamaño; i++) {
            if (!tabla[i].empty()) {
                buckets_usados++;
                max_colisiones = max(max_colisiones, (int)tabla[i].size());
            }
        }
        
        cout << "Buckets usados: " << buckets_usados << " / " << tamaño << endl;
        cout << "Maximas colisiones en un bucket: " << max_colisiones << endl;
    }
    
    void mostrarContenido() {
        cout << "\nContenido de la tabla hash:" << endl;
        for (int i = 0; i < tamaño; i++) {
            if (!tabla[i].empty()) {
                cout << "Bucket " << i << ": ";
                for (auto& par : tabla[i]) {
                    cout << "(" << par.clave << ", " << par.valor << ") ";
                }
                cout << endl;
            }
        }
    }
};

int main() {
    cout << "=== TABLA HASH ===" << endl;
    
    TablaHash<string, int> tabla;
    int opcion;
    string clave;
    int valor;
    
    do {
        cout << "\n--- MENU TABLA HASH ---" << endl;
        cout << "1. Insertar" << endl;
        cout << "2. Buscar" << endl;
        cout << "3. Eliminar" << endl;
        cout << "4. Mostrar contenido" << endl;
        cout << "5. Mostrar estadisticas" << endl;
        cout << "0. Salir" << endl;
        cout << "Opcion: ";
        cin >> opcion;
        
        switch (opcion) {
            case 1:
                cout << "Clave: ";
                cin >> clave;
                cout << "Valor: ";
                cin >> valor;
                tabla.insertar(clave, valor);
                cout << "Elemento insertado" << endl;
                break;
                
            case 2:
                cout << "Clave a buscar: ";
                cin >> clave;
                if (tabla.buscar(clave, valor)) {
                    cout << "Clave encontrada. Valor: " << valor << endl;
                } else {
                    cout << "Clave no encontrada" << endl;
                }
                break;
                
            case 3:
                cout << "Clave a eliminar: ";
                cin >> clave;
                if (tabla.eliminar(clave)) {
                    cout << "Elemento eliminado" << endl;
                } else {
                    cout << "Clave no encontrada" << endl;
                }
                break;
                
            case 4:
                tabla.mostrarContenido();
                break;
                
            case 5:
                tabla.mostrarEstadisticas();
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

// Codigo 77: Algoritmo de Backtracking - Sudoku
#include <iostream>
#include <vector>
using namespace std;

class SudokuSolver {
private:
    vector<vector<int>> tablero;
    static const int TAMAÑO = 9;
    
    bool esSeguro(int fila, int col, int num) {
        // Verificar fila
        for (int x = 0; x < TAMAÑO; x++) {
            if (tablero[fila][x] == num) {
                return false;
            }
        }
        
        // Verificar columna
        for (int x = 0; x < TAMAÑO; x++) {
            if (tablero[x][col] == num) {
                return false;
            }
        }
        
        // Verificar cuadro 3x3
        int inicioFila = fila - fila % 3;
        int inicioCol = col - col % 3;
        for (int i = 0; i < 3; i++) {
            for (int j = 0; j < 3; j++) {
                if (tablero[i + inicioFila][j + inicioCol] == num) {
                    return false;
                }
            }
        }
        
        return true;
    }
    
    bool resolverSudoku() {
        int fila, col;
        
        // Encontrar celda vacia
        if (!encontrarCeldaVacia(fila, col)) {
            return true; // No hay celdas vacias, sudoku resuelto
        }
        
        // Probar numeros del 1 al 9
        for (int num = 1; num <= 9; num++) {
            if (esSeguro(fila, col, num)) {
                tablero[fila][col] = num;
                
                if (resolverSudoku()) {
                    return true;
                }
                
                // Backtrack
                tablero[fila][col] = 0;
            }
        }
        
        return false;
    }
    
    bool encontrarCeldaVacia(int& fila, int& col) {
        for (fila = 0; fila < TAMAÑO; fila++) {
            for (col = 0; col < TAMAÑO; col++) {
                if (tablero[fila][col] == 0) {
                    return true;
                }
            }
        }
        return false;
    }
    
public:
    SudokuSolver() {
        tablero.resize(TAMAÑO, vector<int>(TAMAÑO, 0));
    }
    
    void cargarTablero() {
        cout << "Ingrese el tablero de Sudoku (use 0 para celdas vacias):" << endl;
        for (int i = 0; i < TAMAÑO; i++) {
            cout << "Fila " << i + 1 << ": ";
            for (int j = 0; j < TAMAÑO; j++) {
                cin >> tablero[i][j];
            }
        }
    }
    
    void cargarEjemplo() {
        // Tablero de ejemplo
        vector<vector<int>> ejemplo = {
            {5, 3, 0, 0, 7, 0, 0, 0, 0},
            {6, 0, 0, 1, 9, 5, 0, 0, 0},
            {0, 9, 8, 0, 0, 0, 0, 6, 0},
            {8, 0, 0, 0, 6, 0, 0, 0, 3},
            {4, 0, 0, 8, 0, 3, 0, 0, 1},
            {7, 0, 0, 0, 2, 0, 0, 0, 6},
            {0, 6, 0, 0, 0, 0, 2, 8, 0},
            {0, 0, 0, 4, 1, 9, 0, 0, 5},
            {0, 0, 0, 0, 8, 0, 0, 7, 9}
        };
        tablero = ejemplo;
    }
    
    void mostrarTablero() {
        cout << "\n+-------+-------+-------+" << endl;
        for (int i = 0; i < TAMAÑO; i++) {
            cout << "| ";
            for (int j = 0; j < TAMAÑO; j++) {
                if (tablero[i][j] == 0) {
                    cout << ". ";
                } else {
                    cout << tablero[i][j] << " ";
                }
                if ((j + 1) % 3 == 0) {
                    cout << "| ";
                }
            }
            cout << endl;
            if ((i + 1) % 3 == 0) {
                cout << "+-------+-------+-------+" << endl;
            }
        }
    }
    
    bool resolver() {
        return resolverSudoku();
    }
};

int main() {
    cout << "=== SOLUCIONADOR DE SUDOKU ===" << endl;
    
    SudokuSolver solver;
    int opcion;
    
    cout << "1. Cargar tablero manualmente" << endl;
    cout << "2. Usar ejemplo predefinido" << endl;
    cout << "Opcion: ";
    cin >> opcion;
    
    if (opcion == 1) {
        solver.cargarTablero();
    } else {
        solver.cargarEjemplo();
    }
    
    cout << "\nTablero inicial:";
    solver.mostrarTablero();
    
    cout << "\nResolviendo sudoku..." << endl;
    if (solver.resolver()) {
        cout << "\nSudoku resuelto:";
        solver.mostrarTablero();
    } else {
        cout << "\nNo se pudo resolver el sudoku" << endl;
    }
    
    return 0;
}

// Codigo 78: Algoritmo Genetico Simple
#include <iostream>
#include <vector>
#include <random>
#include <algorithm>
using namespace std;

class AlgoritmoGenetico {
private:
    struct Individuo {
        vector<int> genes;
        double fitness;
        
        Individuo(int tamaño) : genes(tamaño), fitness(0) {}
    };
    
    vector<Individuo> poblacion;
    int tamañoPoblacion;
    int tamañoGenes;
    double tasaMutacion;
    random_device rd;
    mt19937 gen;
    
    double calcularFitness(const vector<int>& genes) {
        // Objetivo: maximizar la suma de los genes
        double suma = 0;
        for (int gen : genes) {
            suma += gen;
        }
        return suma;
    }
    
    void inicializarPoblacion() {
        uniform_int_distribution<int> dis(0, 1);
        
        for (int i = 0; i < tamañoPoblacion; i++) {
            for (int j = 0; j < tamañoGenes; j++) {
                poblacion[i].genes[j] = dis(gen);
            }
            poblacion[i].fitness = calcularFitness(poblacion[i].genes);
        }
    }
    
    Individuo seleccionarPadre() {
        // Seleccion por torneo
        uniform_int_distribution<int> dis(0, tamañoPoblacion - 1);
        
        int idx1 = dis(gen);
        int idx2 = dis(gen);
        
        return (poblacion[idx1].fitness > poblacion[idx2].fitness) ? 
               poblacion[idx1] : poblacion[idx2];
    }
    
    Individuo cruzar(const Individuo& padre1, const Individuo& padre2) {
        Individuo hijo(tamañoGenes);
        uniform_int_distribution<int> dis(1, tamañoGenes - 1);
        
        int puntoCorte = dis(gen);
        
        for (int i = 0; i < puntoCorte; i++) {
            hijo.genes[i] = padre1.genes[i];
        }
        for (int i = puntoCorte; i < tamañoGenes; i++) {
            hijo.genes[i] = padre2.genes[i];
        }
        
        return hijo;
    }
    
    void mutar(Individuo& individuo) {
        uniform_real_distribution<double> dis(0.0, 1.0);
        
        for (int i = 0; i < tamañoGenes; i++) {
            if (dis(gen) < tasaMutacion) {
                individuo.genes[i] = 1 - individuo.genes[i]; // Flip bit
            }
        }
    }
    
public:
    AlgoritmoGenetico(int tamPob, int tamGenes, double tasaMut) 
        : tamañoPoblacion(tamPob), tamañoGenes(tamGenes), tasaMutacion(tasaMut), gen(rd()) {
        poblacion.resize(tamañoPoblacion, Individuo(tamañoGenes));
    }
    
    void ejecutar(int generaciones) {
        inicializarPoblacion();
        
        cout << "Generacion 0:" << endl;
        mostrarMejor();
        
        for (int gen = 1; gen <= generaciones; gen++) {
            vector<Individuo> nuevaPoblacion;
            
            // Crear nueva generacion
            for (int i = 0; i < tamañoPoblacion; i++) {
                Individuo padre1 = seleccionarPadre();
                Individuo padre2 = seleccionarPadre();
                
                Individuo hijo = cruzar(padre1, padre2);
                mutar(hijo);
                
                hijo.fitness = calcularFitness(hijo.genes);
                nuevaPoblacion.push_back(hijo);
            }
            
            poblacion = nuevaPoblacion;
            
            if (gen % 10 == 0 || gen == generaciones) {
                cout << "\nGeneracion " << gen << ":" << endl;
                mostrarMejor();
                mostrarEstadisticas();
            }
        }
    }
    
    void mostrarMejor() {
        auto mejor = max_element(poblacion.begin(), poblacion.end(),
            [](const Individuo& a, const Individuo& b) {
                return a.fitness < b.fitness;
            });
        
        cout << "Mejor individuo - Fitness: " << mejor->fitness << ", Genes: ";
        for (int gen : mejor->genes) {
            cout << gen;
        }
        cout << endl;
    }
    
    void mostrarEstadisticas() {
        double sumaFitness = 0;
        double mejorFitness = poblacion[0].fitness;
        double peorFitness = poblacion[0].fitness;
        
        for (const auto& individuo : poblacion) {
            sumaFitness += individuo.fitness;
            mejorFitness = max(mejorFitness, individuo.fitness);
            peorFitness = min(peorFitness, individuo.fitness);
        }
        
        double promedioFitness = sumaFitness / tamañoPoblacion;
        
        cout << "Estadisticas - Mejor: " << mejorFitness 
             << ", Promedio: " << promedioFitness 
             << ", Peor: " << peorFitness << endl;
    }
};

int main() {
    cout << "=== ALGORITMO GENETICO SIMPLE ===" << endl;
    cout << "Objetivo: Maximizar la suma de bits (encontrar todos 1s)" << endl;
    
    int poblacion = 50;
    int genes = 20;
    double mutacion = 0.01;
    int generaciones = 100;
    
    cout << "\nParametros:" << endl;
    cout << "Tamaño poblacion: " << poblacion << endl;
    cout << "Tamaño genes: " << genes << endl;
    cout << "Tasa mutacion: " << mutacion << endl;
    cout << "Generaciones: " << generaciones << endl;
    
    AlgoritmoGenetico ag(poblacion, genes, mutacion);
    ag.ejecutar(generaciones);
    
    return 0;
}

// Codigo 79: Algoritmo A* (A estrella)
#include <iostream>
#include <vector>
#include <queue>
#include <cmath>
#include <map>
using namespace std;

struct Nodo {
    int x, y;
    double g, h, f;
    Nodo* padre;
    
    Nodo(int x, int y) : x(x), y(y), g(0), h(0), f(0), padre(nullptr) {}
    
    bool operator>(const Nodo& otro) const {
        return f > otro.f;
    }
};

class AEstrella {
private:
    vector<vector<int>> mapa;
    int filas, columnas;
    
    double calcularHeuristica(int x1, int y1, int x2, int y2) {
        // Distancia Manhattan
        return abs(x1 - x2) + abs(y1 - y2);
    }
    
    vector<Nodo*> obtenerVecinos(Nodo* nodo) {
        vector<Nodo*> vecinos;
        int dx[] = {-1, 1, 0, 0};
        int dy[] = {0, 0, -1, 1};
        
        for (int i = 0; i < 4; i++) {
            int nx = nodo->x + dx[i];
            int ny = nodo->y + dy[i];
            
            if (nx >= 0 && nx < filas && ny >= 0 && ny < columnas && mapa[nx][ny] == 0) {
                vecinos.push_back(new Nodo(nx, ny));
            }
        }
        
        return vecinos;
    }
    
public:
    AEstrella(vector<vector<int>>& m) : mapa(m) {
        filas = mapa.size();
        columnas = mapa[0].size();
    }
    
    vector<pair<int, int>> buscarCamino(int inicioX, int inicioY, int finX, int finY) {
        priority_queue<Nodo*, vector<Nodo*>, greater<Nodo*>> listaAbierta;
        map<pair<int, int>, bool> listaCerrada;
        map<pair<int, int>, Nodo*> nodos;
        
        Nodo* inicio = new Nodo(inicioX, inicioY);
        inicio->h = calcularHeuristica(inicioX, inicioY, finX, finY);
        inicio->f = inicio->h;
        
        listaAbierta.push(inicio);
        nodos[{inicioX, inicioY}] = inicio;
        
        while (!listaAbierta.empty()) {
            Nodo* actual = listaAbierta.top();
            listaAbierta.pop();
            
            pair<int, int> coordActual = {actual->x, actual->y};
            
            if (listaCerrada[coordActual]) {
                continue;
            }
            
            listaCerrada[coordActual] = true;
            
            // Verificar si llegamos al destino
            if (actual->x == finX && actual->y == finY) {
                vector<pair<int, int>> camino;
                Nodo* temp = actual;
                
                while (temp != nullptr) {
                    camino.push_back({temp->x, temp->y});
                    temp = temp->padre;
                }
                
                reverse(camino.begin(), camino.end());
                return camino;
            }
            
            vector<Nodo*> vecinos = obtenerVecinos(actual);
            
            for (Nodo* vecino : vecinos) {
                pair<int, int> coordVecino = {vecino->x, vecino->y};
                
                if (listaCerrada[coordVecino]) {
                    delete vecino;
                    continue;
                }
                
                double nuevoG = actual->g + 1;
                
                if (nodos.find(coordVecino) == nodos.end() || nuevoG < nodos[coordVecino]->g) {
                    vecino->g = nuevoG;
                    vecino->h = calcularHeuristica(vecino->x, vecino->y, finX, finY);
                    vecino->f = vecino->g + vecino->h;
                    vecino->padre = actual;
                    
                    if (nodos.find(coordVecino) != nodos.end()) {
                        delete nodos[coordVecino];
                    }
                    
                    nodos[coordVecino] = vecino;
                    listaAbierta.push(vecino);
                } else {
                    delete vecino;
                }
            }
        }
        
        return {}; // No se encontro camino
    }
    
    void mostrarMapa() {
        cout << "\nMapa (0 = libre, 1 = obstaculo):" << endl;
        for (int i = 0; i < filas; i++) {
            for (int j = 0; j < columnas; j++) {
                cout << mapa[i][j] << " ";
            }
            cout << endl;
        }
    }
    
    void mostrarCamino(const vector<pair<int, int>>& camino) {
        if (camino.empty()) {
            cout << "\nNo se encontro camino" << endl;
            return;
        }
        
        cout << "\nCamino encontrado:" << endl;
        for (int i = 0; i < camino.size(); i++) {
            cout << "(" << camino[i].first << ", " << camino[i].second << ")";
            if (i < camino.size() - 1) cout << " -> ";
        }
        cout << endl;
        
        // Mostrar mapa con camino
        vector<vector<char>> mapaConCamino(filas, vector<char>(columnas));
        
        for (int i = 0; i < filas; i++) {
            for (int j = 0; j < columnas; j++) {
                if (mapa[i][j] == 1) {
                    mapaConCamino[i][j] = '#'; // Obstaculo
                } else {
                    mapaConCamino[i][j] = '.'; // Libre
                }
            }
        }
        
        for (int i = 0; i < camino.size(); i++) {
            int x = camino[i].first;
            int y = camino[i].second;
            
            if (i == 0) {
                mapaConCamino[x][y] = 'S'; // Inicio
            } else if (i == camino.size() - 1) {
                mapaConCamino[x][y] = 'G'; // Meta
            } else {
                mapaConCamino[x][y] = '*'; // Camino
            }
        }
        
        cout << "\nMapa con camino:" << endl;
        for (int i = 0; i < filas; i++) {
            for (int j = 0; j < columnas; j++) {
                cout << mapaConCamino[i][j] << " ";
            }
            cout << endl;
        }
    }
};

int main() {
    cout << "=== ALGORITMO A* (A ESTRELLA) ===" << endl;
    
    // Crear mapa de ejemplo (0 = libre, 1 = obstaculo)
    vector<vector<int>> mapa = {
        {0, 0, 0, 1, 0, 0, 0, 0},
        {0, 1, 0, 1, 0, 1, 1, 0},
        {0, 1, 0, 0, 0, 0, 1, 0},
        {0, 1, 1, 1, 1, 0, 1, 0},
        {0, 0, 0, 0, 0, 0, 1, 0},
        {1, 1, 1, 1, 1, 0, 0, 0},
        {0, 0, 0, 0, 0, 0, 1, 0},
        {0, 1, 1, 1, 1, 1, 1, 0}
    };
    
    AEstrella pathfinder(mapa);
    pathfinder.mostrarMapa();
    
    int inicioX, inicioY, finX, finY;
    
    cout << "\nIngrese coordenadas de inicio (fila columna): ";
    cin >> inicioX >> inicioY;
    cout << "Ingrese coordenadas de destino (fila columna): ";
    cin >> finX >> finY;
    
    if (inicioX >= 0 && inicioX < 8 && inicioY >= 0 && inicioY < 8 &&
        finX >= 0 && finX < 8 && finY >= 0 && finY < 8 &&
        mapa[inicioX][inicioY] == 0 && mapa[finX][finY] == 0) {
        
        cout << "\nBuscando camino desde (" << inicioX << ", " << inicioY 
             << ") hasta (" << finX << ", " << finY << ")..." << endl;
        
        vector<pair<int, int>> camino = pathfinder.buscarCamino(inicioX, inicioY, finX, finY);
        pathfinder.mostrarCamino(camino);
        
    } else {
        cout << "Coordenadas invalidas o posiciones bloqueadas" << endl;
    }
    
    return 0;
}

// Codigo 80: Algoritmo de Kruskal (Arbol de Expansion Minima)
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

struct Arista {
    int origen, destino, peso;
    
    Arista(int o, int d, int p) : origen(o), destino(d), peso(p) {}
    
    bool operator<(const Arista& otra) const {
        return peso < otra.peso;
    }
};

class UnionFind {
private:
    vector<int> padre, rango;
    
public:
    UnionFind(int n) : padre(n), rango(n, 0) {
        for (int i = 0; i < n; i++) {
            padre[i] = i;
        }
    }
    
    int encontrar(int x) {
        if (padre[x] != x) {
            padre[x] = encontrar(padre[x]); // Compresion de camino
        }
        return padre[x];
    }
    
    bool unir(int x, int y) {
        int raizX = encontrar(x);
        int raizY = encontrar(y);
        
        if (raizX == raizY) {
            return false; // Ya estan en el mismo conjunto
        }
        
        // Union por rango
        if (rango[raizX] < rango[raizY]) {
            padre[raizX] = raizY;
        } else if (rango[raizX] > rango[raizY]) {
            padre[raizY] = raizX;
        } else {
            padre[raizY] = raizX;
            rango[raizX]++;
        }
        
        return true;
    }
};

class Kruskal {
private:
    int vertices;
    vector<Arista> aristas;
    
public:
    Kruskal(int v) : vertices(v) {}
    
    void agregarArista(int origen, int destino, int peso) {
        aristas.emplace_back(origen, destino, peso);
    }
    
    vector<Arista> encontrarMST() {
        vector<Arista> mst;
        UnionFind uf(vertices);
        
        // Ordenar aristas por peso
        sort(aristas.begin(), aristas.end());
        
        cout << "\nProcesando aristas en orden de peso:" << endl;
        
        for (const auto& arista : aristas) {
            cout << "Arista (" << arista.origen << ", " << arista.destino 
                 << ") peso: " << arista.peso;
            
            if (uf.unir(arista.origen, arista.destino)) {
                mst.push_back(arista);
                cout << " -> INCLUIDA" << endl;
                
                if (mst.size() == vertices - 1) {
                    break; // MST completo
                }
            } else {
                cout << " -> RECHAZADA (forma ciclo)" << endl;
            }
        }
        
        return mst;
    }
    
    void mostrarGrafo() {
        cout << "\nGrafo original:" << endl;
        cout << "Vertices: " << vertices << endl;
        cout << "Aristas:" << endl;
        
        for (const auto& arista : aristas) {
            cout << "(" << arista.origen << ", " << arista.destino 
                 << ") peso: " << arista.peso << endl;
        }
    }
    
    void mostrarMST(const vector<Arista>& mst) {
        if (mst.empty()) {
            cout << "\nNo se pudo crear el MST" << endl;
            return;
        }
        
        cout << "\n=== ARBOL DE EXPANSION MINIMA ===" << endl;
        
        int pesoTotal = 0;
        for (const auto& arista : mst) {
            cout << "(" << arista.origen << ", " << arista.destino 
                 << ") peso: " << arista.peso << endl;
            pesoTotal += arista.peso;
        }
        
        cout << "\nPeso total del MST: " << pesoTotal << endl;
        cout << "Numero de aristas en MST: " << mst.size() << endl;
    }
};

int main() {
    cout << "=== ALGORITMO DE KRUSKAL ===" << endl;
    cout << "Encontrar Arbol de Expansion Minima" << endl;
    
    // Crear grafo de ejemplo
    Kruskal grafo(6);
    
    // Agregar aristas (origen, destino, peso)
    grafo.agregarArista(0, 1, 4);
    grafo.agregarArista(0, 2, 3);
    grafo.agregarArista(1, 2, 1);
    grafo.agregarArista(1, 3, 2);
    grafo.agregarArista(2, 3, 4);
    grafo.agregarArista(3, 4, 2);
    grafo.agregarArista(4, 5, 6);
    grafo.agregarArista(1, 4, 3);
    grafo.agregarArista(2, 5, 5);
    
    grafo.mostrarGrafo();
    
    vector<Arista> mst = grafo.encontrarMST();
    grafo.mostrarMST(mst);
    
    return 0;
}