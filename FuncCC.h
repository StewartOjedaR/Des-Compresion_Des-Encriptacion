#ifndef FUNCCC_H
#define FUNCCC_H
#include <iostream>
#include <fstream>
using namespace std;
// Función para redimensionar el arreglo
void redimensionar(char*& arreglo,unsigned int capacidad,unsigned int nuevaCapacidad,unsigned int contador) {
    char* pArregloCopia = new char[nuevaCapacidad];
    
    // Copiar elementos existentes
    for (unsigned int i = 0; i < contador; i++) {
        pArregloCopia[i] = arreglo[i];
    }
  //  delete[] arreglo;
    arreglo = nullptr;
    arreglo = pArregloCopia;
    capacidad = nuevaCapacidad;
}


void ImprimirCadenaRLE(char *CadenaComprimida, char *CaracRepetidos){
int contador = 0;
for (int i =0; i<i+1; i++){
if (CadenaComprimida[i]== '\0') break;
contador++;
}

for  (int i=0; i<contador; i++){
    cout << CadenaComprimida[i]<<int(CaracRepetidos[i]);
}}


void ArregloString(char*& Cadena,istream& entrada, const char* mensaje = "Ingresa texto (Enter para terminar): ") {
    int Capacidad = 1;
    int*ptrCapacidad=&Capacidad;
    Cadena = new char[Capacidad];
    unsigned int contador = 0;
    char Caracter;
    if (&entrada == &cin) cout << mensaje;
        while (entrada.get(Caracter)) {                               // Lee un caracter a la vez, el bucle continúa hasta que se presiona Enter (caracter de nueva línea)
        if (&entrada == &cin && Caracter == '\n'){ break;}
        if (contador >= Capacidad) {                                            //Si el contador alcanza o supera la capacidad actual del arreglo, es necesario redimensionar el arreglo para acomodar más caracteres
            redimensionar(Cadena, Capacidad, Capacidad +1, contador);          // Copia el viejo arreglo, libera el viejo arreglo y crea uno nuevo con la nueva capacidad
            Capacidad++; // Incrementa la capacidad para la proxima vez que se necesite redimensionar el arreglo, en este caso se incrementa de uno en uno para evitar desperdiciar memoria
        }
        Cadena[contador++] = Caracter;                                          // Almacena el caracter ingresado en el arreglo y luego incrementa el contador para la próxima posición del arreglo
    }
    
    // Agregar el caracter nulo al final
    if (contador >= Capacidad) {
        redimensionar(Cadena, Capacidad, Capacidad + 1, contador);
    } 
    Cadena[contador] = '\0';
}


void comprimirRLE(const char* Cadena, char*& CadenaComprimida, char*& CaracRepetidos) {
int  capacidad = 0;
int contador = 0;
for (int i =0; i<i+1; i++){
if (Cadena[i]== '\0') break;
contador++;
}

    int NuevoContador = 0;
    unsigned short repeticiones = 1;
    
 //   CadenaComprimida = new char[capacidad];
 //   CaracRepetidos = new char[capacidad];
    
      for (int i=0; i < contador; i++){                                           //contardor para recorrer el arreglo de caracteres
        if (NuevoContador>=capacidad){
            redimensionar(CadenaComprimida, capacidad, capacidad+1, NuevoContador); //redimensiono el arreglo comprimido si el contador alcanza o supera la capacidad actual del arreglo
            redimensionar(CaracRepetidos, capacidad, capacidad+1, NuevoContador);
            capacidad++;
        }
        if ( (i+1) < contador &&Cadena[i]==Cadena[i+1]){
           repeticiones++; continue; //si el caracter actual es igual al siguiente, incremento el contador de repeticiones y continuo con la siguiente iteracion del bucle para seguir contando las repeticiones de ese caracter 
        }
        else {
            CadenaComprimida[NuevoContador]=Cadena[i];
            CaracRepetidos[NuevoContador]=char(repeticiones);
            NuevoContador++;
            repeticiones=1;
        }
    }
    if (contador >= capacidad) {
        redimensionar(CadenaComprimida, capacidad, capacidad + 1, contador);
        redimensionar(CaracRepetidos, capacidad, capacidad + 1, contador);
    } 
    CadenaComprimida[contador] = '\0';
}



// Función para descomprimir RLE
void descomprimirRLE(const char* CadenaComprimida, const char* CaracRepetidos) {
int contador = 0;
for (int i =0; i<i+1; i++){
if (CaracRepetidos[i]== '\0') break;
contador++;
}
  for (int i = 0; i < contador; i++) {
    for (int j = 0; j < int(CaracRepetidos[i]); j++) {
       cout << CadenaComprimida[i];
    }
  }
}


void bin(char a){
for (int i=(sizeof(a)*8)-1;i>=0;i--){
    if ((a>>i)&1==1){
       cout<<'1';
    }else{ 
      cout<<'0';
    } if (i%4==0){
}}
}


void RotarBits(char *CadenaComprimida, unsigned int CantidadDeRotaciones){
int contador = 0;
for (int i =0; i<i+1; i++){
if (CadenaComprimida[i]== '\0') break;
contador++;
}


   for (int j=0; j<contador; j++){
  //  bin(CadenaComprimida[j]);
 //   cout<<"Byte"<<endl;

    for (int i=0;i<CantidadDeRotaciones;i++){
        if ((CadenaComprimida[j]&1<<7)){ 
            CadenaComprimida[j]<<=1;
            CadenaComprimida[j]|=1;
     //       bin(CadenaComprimida[j]);
   //         cout<<endl;
            continue;
        }
        CadenaComprimida[j]<<=1;
      //      bin(CadenaComprimida[j]);
     //       cout<<endl;
    }
    }


}
#endif // FUNCCC_H
