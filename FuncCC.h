#ifndef FUNCCC_H
#define FUNCCC_H
#include <iostream>
#include <fstream>
using namespace std;
// Función para redimensionar el arreglo
void redimensionar(char*& arreglo,unsigned int& capacidad,unsigned int nuevaCapacidad,unsigned int contador) {
    char* pArregloCopia = new char[nuevaCapacidad];
    
    // Copiar elementos existentes
    for (unsigned int i = 0; i < contador; i++) {
        pArregloCopia[i] = arreglo[i];
    }
    delete[] arreglo;
    arreglo = pArregloCopia;
    capacidad = nuevaCapacidad;
}


void ImprimirCadenaRLE(char *CadenaComprimida, char *CaracRepetidos,unsigned short NuevoContador){
for  (int i=0; i<NuevoContador; i++){
    cout << CadenaComprimida[i]<<int(CaracRepetidos[i]);
}}


void leerTexto(char*& Cadena, unsigned int& contador,unsigned int& capacidad,ifstream& entrada, const char* mensaje = "Ingresa texto (Enter para terminar): ") {
    if (capacidad == 0) capacidad = 1;
    Cadena = new char[capacidad];
    contador = 0;
    char Caracter;
    if (&entrada == &cin) cout << mensaje;
        while (entrada.get(Caracter)) {                               // Lee un caracter a la vez, el bucle continúa hasta que se presiona Enter (caracter de nueva línea)
        if (&entrada == &cin && Caracter == '\n'){ break;}
        if (contador >= capacidad) {                                            //Si el contador alcanza o supera la capacidad actual del arreglo, es necesario redimensionar el arreglo para acomodar más caracteres
            redimensionar(Cadena, capacidad, capacidad +1, contador);          // Copia el viejo arreglo, libera el viejo arreglo y crea uno nuevo con la nueva capacidad
        }
        Cadena[contador++] = Caracter;                                          // Almacena el caracter ingresado en el arreglo y luego incrementa el contador para la próxima posición del arreglo
    }
    
    // Agregar el caracter nulo al final
    if (contador >= capacidad) {
        redimensionar(Cadena, capacidad, capacidad + 1, contador);
    } 
    Cadena[contador] = '\0';
}


void comprimirRLE(const char* Cadena, unsigned int contador, char*& CadenaComprimida, char*& CaracRepetidos, unsigned int& NuevoContador,unsigned int& capacidad) {
    capacidad = 0;
    NuevoContador = 0;
    unsigned short repeticiones = 1;
    
    CadenaComprimida = new char[capacidad];
    CaracRepetidos = new char[capacidad];
    
      for (int i=0; i < contador; i++){                                           //contardor para recorrer el arreglo de caracteres
        if (NuevoContador>=capacidad){
            redimensionar(CadenaComprimida, capacidad, capacidad+1, NuevoContador); //redimensiono el arreglo comprimido si el contador alcanza o supera la capacidad actual del arreglo
            redimensionar(CaracRepetidos, capacidad, capacidad+1, NuevoContador);
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
}



// Función para descomprimir RLE
void descomprimirRLE(const char* CadenaComprimida, const char* CaracRepetidos) {
  for (int i = 0; i < sizeof(CadenaComprimida); i++) {
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


void RotarBits(char *CadenaComprimida, unsigned int contador, unsigned int CantidadDeRotaciones){
    for (int j=0; j<contador; j++){
    bin(CadenaComprimida[j]);
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
