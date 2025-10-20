// Codigo 41: Longitud de Cadena
#include <iostream>
#include <string>
using namespace std;

int longitudCadena(const string& str) {
    int longitud = 0;
    for (char c : str) {
        longitud++;
    }
    return longitud;
}

int main() {
    string cadena;
    
    cout << "Ingrese una cadena: ";
    getline(cin, cadena);
    
    int longitud = longitudCadena(cadena);
    cout << "Longitud de la cadena: " << longitud << endl;
    
    return 0;
}

// Codigo 42: Inversion de Cadena
#include <iostream>
#include <string>
using namespace std;

string invertirCadena(string str) {
    int inicio = 0;
    int fin = str.length() - 1;
    
    while (inicio < fin) {
        char temp = str[inicio];
        str[inicio] = str[fin];
        str[fin] = temp;
        inicio++;
        fin--;
    }
    
    return str;
}

int main() {
    string cadena;
    
    cout << "Ingrese una cadena: ";
    getline(cin, cadena);
    
    string cadenaInvertida = invertirCadena(cadena);
    
    cout << "Cadena original: " << cadena << endl;
    cout << "Cadena invertida: " << cadenaInvertida << endl;
    
    return 0;
}

// Codigo 43: Conteo de Vocales
#include <iostream>
#include <string>
#include <cctype>
using namespace std;

int contarVocales(const string& str) {
    int contador = 0;
    
    for (char c : str) {
        char minuscula = tolower(c);
        if (minuscula == 'a' || minuscula == 'e' || minuscula == 'i' || 
            minuscula == 'o' || minuscula == 'u') {
            contador++;
        }
    }
    
    return contador;
}

int main() {
    string cadena;
    
    cout << "Ingrese una cadena: ";
    getline(cin, cadena);
    
    int vocales = contarVocales(cadena);
    cout << "Numero de vocales: " << vocales << endl;
    
    return 0;
}

// Codigo 44: Comparacion de Cadenas
#include <iostream>
#include <string>
using namespace std;

int compararCadenas(const string& str1, const string& str2) {
    int i = 0;
    while (i < str1.length() && i < str2.length()) {
        if (str1[i] < str2[i]) {
            return -1; // str1 < str2
        } else if (str1[i] > str2[i]) {
            return 1;  // str1 > str2
        }
        i++;
    }
    
    if (str1.length() < str2.length()) {
        return -1;
    } else if (str1.length() > str2.length()) {
        return 1;
    }
    
    return 0; // Iguales
}

int main() {
    string cadena1, cadena2;
    
    cout << "Ingrese primera cadena: ";
    getline(cin, cadena1);
    cout << "Ingrese segunda cadena: ";
    getline(cin, cadena2);
    
    int resultado = compararCadenas(cadena1, cadena2);
    
    if (resultado == 0) {
        cout << "Las cadenas son iguales" << endl;
    } else if (resultado < 0) {
        cout << "Primera cadena es menor que la segunda" << endl;
    } else {
        cout << "Primera cadena es mayor que la segunda" << endl;
    }
    
    return 0;
}

// Codigo 45: Cadena Palindromo
#include <iostream>
#include <string>
#include <cctype>
using namespace std;

bool esPalindromo(string str) {
    // Convertir a minusculas y eliminar espacios
    string limpia = "";
    for (char c : str) {
        if (isalnum(c)) {
            limpia += tolower(c);
        }
    }
    
    int inicio = 0;
    int fin = limpia.length() - 1;
    
    while (inicio < fin) {
        if (limpia[inicio] != limpia[fin]) {
            return false;
        }
        inicio++;
        fin--;
    }
    
    return true;
}

int main() {
    string cadena;
    
    cout << "Ingrese una cadena: ";
    getline(cin, cadena);
    
    if (esPalindromo(cadena)) {
        cout << "\"" << cadena << "\" es un palindromo" << endl;
    } else {
        cout << "\"" << cadena << "\" no es un palindromo" << endl;
    }
    
    return 0;
}

// Codigo 46: Frecuencia de Caracteres
#include <iostream>
#include <string>
#include <map>
using namespace std;

int main() {
    string cadena;
    map<char, int> frecuencia;
    
    cout << "Ingrese una cadena: ";
    getline(cin, cadena);
    
    // Contar frecuencia de cada caracter
    for (char c : cadena) {
        if (c != ' ') { // Ignorar espacios
            frecuencia[c]++;
        }
    }
    
    cout << "\nFrecuencia de caracteres:" << endl;
    for (auto par : frecuencia) {
        cout << "'" << par.first << "': " << par.second << " veces" << endl;
    }
    
    return 0;
}

// Codigo 47: Conversion Mayusculas/Minusculas
#include <iostream>
#include <string>
#include <cctype>
using namespace std;

string aMayusculas(string str) {
    for (int i = 0; i < str.length(); i++) {
        str[i] = toupper(str[i]);
    }
    return str;
}

string aMinusculas(string str) {
    for (int i = 0; i < str.length(); i++) {
        str[i] = tolower(str[i]);
    }
    return str;
}

string alternarCaso(string str) {
    for (int i = 0; i < str.length(); i++) {
        if (i % 2 == 0) {
            str[i] = toupper(str[i]);
        } else {
            str[i] = tolower(str[i]);
        }
    }
    return str;
}

int main() {
    string cadena;
    
    cout << "Ingrese una cadena: ";
    getline(cin, cadena);
    
    cout << "Original: " << cadena << endl;
    cout << "Mayusculas: " << aMayusculas(cadena) << endl;
    cout << "Minusculas: " << aMinusculas(cadena) << endl;
    cout << "Alternado: " << alternarCaso(cadena) << endl;
    
    return 0;
}

// Codigo 48: Eliminacion de Espacios
#include <iostream>
#include <string>
using namespace std;

string eliminarEspacios(const string& str) {
    string resultado = "";
    
    for (char c : str) {
        if (c != ' ') {
            resultado += c;
        }
    }
    
    return resultado;
}

string eliminarEspaciosExtra(const string& str) {
    string resultado = "";
    bool espacioAnterior = false;
    
    for (char c : str) {
        if (c == ' ') {
            if (!espacioAnterior) {
                resultado += c;
                espacioAnterior = true;
            }
        } else {
            resultado += c;
            espacioAnterior = false;
        }
    }
    
    return resultado;
}

int main() {
    string cadena;
    
    cout << "Ingrese una cadena con espacios: ";
    getline(cin, cadena);
    
    cout << "Original: \"" << cadena << "\"" << endl;
    cout << "Sin espacios: \"" << eliminarEspacios(cadena) << "\"" << endl;
    cout << "Sin espacios extra: \"" << eliminarEspaciosExtra(cadena) << "\"" << endl;
    
    return 0;
}

// Codigo 49: Busqueda de Subcadena
#include <iostream>
#include <string>
using namespace std;

int buscarSubcadena(const string& cadena, const string& subcadena) {
    if (subcadena.length() > cadena.length()) {
        return -1;
    }
    
    for (int i = 0; i <= cadena.length() - subcadena.length(); i++) {
        bool encontrada = true;
        
        for (int j = 0; j < subcadena.length(); j++) {
            if (cadena[i + j] != subcadena[j]) {
                encontrada = false;
                break;
            }
        }
        
        if (encontrada) {
            return i; // Retorna la posicion donde inicia la subcadena
        }
    }
    
    return -1; // No encontrada
}

int main() {
    string cadena, subcadena;
    
    cout << "Ingrese la cadena principal: ";
    getline(cin, cadena);
    cout << "Ingrese la subcadena a buscar: ";
    getline(cin, subcadena);
    
    int posicion = buscarSubcadena(cadena, subcadena);
    
    if (posicion != -1) {
        cout << "Subcadena encontrada en posicion: " << posicion << endl;
    } else {
        cout << "Subcadena no encontrada" << endl;
    }
    
    return 0;
}

// Codigo 50: Anagrama
#include <iostream>
#include <string>
#include <algorithm>
#include <cctype>
using namespace std;

string limpiarCadena(string str) {
    string limpia = "";
    for (char c : str) {
        if (isalpha(c)) {
            limpia += tolower(c);
        }
    }
    return limpia;
}

bool sonAnagramas(string str1, string str2) {
    // Limpiar y normalizar las cadenas
    str1 = limpiarCadena(str1);
    str2 = limpiarCadena(str2);
    
    // Si tienen diferente longitud, no pueden ser anagramas
    if (str1.length() != str2.length()) {
        return false;
    }
    
    // Ordenar ambas cadenas
    sort(str1.begin(), str1.end());
    sort(str2.begin(), str2.end());
    
    // Comparar las cadenas ordenadas
    return str1 == str2;
}

int main() {
    string cadena1, cadena2;
    
    cout << "Ingrese primera cadena: ";
    getline(cin, cadena1);
    cout << "Ingrese segunda cadena: ";
    getline(cin, cadena2);
    
    if (sonAnagramas(cadena1, cadena2)) {
        cout << "\"" << cadena1 << "\" y \"" << cadena2 << "\" son anagramas" << endl;
    } else {
        cout << "\"" << cadena1 << "\" y \"" << cadena2 << "\" no son anagramas" << endl;
    }
    
    return 0;
}