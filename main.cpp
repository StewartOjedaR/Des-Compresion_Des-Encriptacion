#include <iostream>
#include "FuncCC.h"
using namespace std;


int main() {
    int capacidad = 1;
    char* arreglo = new char[capacidad];
    int contador = 0;
    char entrada;
    cout << "Ingresa texto (Enter para terminar): ";
    while (cin.get(entrada) && entrada != '\n') {
        if (contador >= capacidad) {
            redimensionar(arreglo, capacidad, capacidad +1, contador);// Copia el viejo arreglo, libera el viejo arreglo y crea uno nuevo con la nueva capacidad
        }
        arreglo[contador++] = entrada;
    }
   // cout << "\n";
    for (int i = 0; i < contador; i++) 
    cout << arreglo[i];
    //cout << "\" (tamaño: " << contador << ", capacidad: " << capacidad << ")" << endl;
    
    delete[] arreglo;
    return 0;
}