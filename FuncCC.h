#ifndef FUNCCC_H
#define FUNCCC_H
#include <iostream>
using namespace std;
// Función para redimensionar el arreglo
void redimensionar(char*& arreglo, int& capacidad, int nuevaCapacidad, int contador) {
    char* pArregloCopia = new char[nuevaCapacidad];
    
    // Copiar elementos existentes
    for (int i = 0; i < contador; i++) {
        pArregloCopia[i] = arreglo[i];
    }
    delete[] arreglo;
    arreglo = pArregloCopia;
    capacidad = nuevaCapacidad;
}




#endif // FUNCCC_H
