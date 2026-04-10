#include <iostream>
#include <fstream>
#include <istream>
#include "FuncCC.h"
using namespace std;
unsigned int Capacidad=0;
    char* Cadena = nullptr;                                        //un arreglo dinamico para almacenar los caracteres incluyendo los espacios, el arreglo se redimensionará según sea necesario
    unsigned int contador = 0;   
    unsigned int NuevoContador=0;                                               //para el nuevo arreglo comprimido
    char*CadenaComprimida = nullptr;                                //arreglo donde almacenare la nueva cadena comrpimida, se redimencionara segun sea necesario
    char*CaracRepetidos = nullptr;

int main() {
std::ifstream archivo("C:\\Users\\ojeda\\Desktop\\XD.txt");
   // if (archivo.is_open()) {
   //     leerTexto(Cadena, contador, Capacidad, archivo);
for (int i=0; i<contador; i++){
    cout<<Cadena[i];
    }
   //     archivo.close();
 //       delete[] Cadena;
 //   } else {
 //       cout << "No se pudo abrir el archivo." << endl;
 //   }
   leerTexto(Cadena,contador,Capacidad,cin);
    comprimirRLE(Cadena,contador,CadenaComprimida,CaracRepetidos,NuevoContador,Capacidad);
    delete[] Cadena;
    ImprimirCadena(CadenaComprimida, CaracRepetidos, NuevoContador);
  //  descomprimirRLE(CadenaComprimida, CaracRepetidos);
    int CantidadDeRotaciones;
for (int k=0; k<NuevoContador; k++){
bin(CadenaComprimida[k]);
cout<<endl;
}

    do
    {
        cout<<"Ingrese un numero menor a 8 para las rotaciones: "<<endl;
        cin>>CantidadDeRotaciones;
    } while (CantidadDeRotaciones>7);
RotarBits(CadenaComprimida, NuevoContador, CantidadDeRotaciones);
 /*   for (int j=0; j<contador; j++){
    bin(CadenaComprimida[j]);
    cout<<"Byte"<<endl;

    for (int i=0;i<CantidadDeRotaciones;i++){
        if ((CadenaComprimida[j]&1<<7)){ 
            CadenaComprimida[j]<<=1;
            CadenaComprimida[j]|=1;
            bin(CadenaComprimida[j]);
            cout<<endl;
            continue;
        }
        CadenaComprimida[j]<<=1;
            bin(CadenaComprimida[j]);
            cout<<endl;
    }
    }*/








    delete[] CadenaComprimida;
    delete[] CaracRepetidos;//libero memoria */













        return 0;
}


