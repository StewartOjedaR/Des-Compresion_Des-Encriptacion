#include <iostream>
#include <fstream>
#include "FuncCC.h"
using namespace std;
int main() {
/*istream& entrada
//    ArregloString(Cadena, cin);                                                //funcion que lee bien sea un texto de entrada o un archivo .txt, el texto se almacena en un arreglo dinamico que se redimensiona segun sea necesario, el contador se utiliza para llevar un registro de la cantidad de caracteres ingresados y la capacidad se utiliza para determinar cuándo es necesario redimensionar el arreglo
    comprimirRLE(Cadena,CadenaComprimida,CaracRepetidos);  //Funcion que comprime la cadena utilizando el algoritmo RLE, se recorre el arreglo de caracteres y se cuenta cuantas veces se repite cada caracter, se almacena el caracter comprimido en un nuevo arreglo y la cantidad de repeticiones en otro arreglo, ambos arreglos se redimensionan segun sea necesario, el nuevo contado se utiliza para llevar un registro de la cantidad de caracteres comprimidos y la capacidad se utiliza para determinar cuando sea necesario redimencionar los arreglos
    delete[] Cadena;//libero memoria del arreglo original ya que no se necesita mas
    //ImprimirCadenaRLE(CadenaComprimida, CaracRepetidos, NuevoContador);                        //funcion que imprime la cadena comprimida, se recorre el arreglo de caracteres cmprimidos y se imprime cada caracter seguido de la cantidad de repeticiones, se utiliza el nuevo contador para determinar la cantidad de caracteres comprimidos a imprimir
    descomprimirRLE(CadenaComprimida, CaracRepetidos);                                      //funcion qque descomprime la cadena comprimida, se recorre el arreglo de caracteres comprimidos y se imprime cada caracter repetido la cantidad de veces indicada en el arreglo de repeticiones
  //  ImprimirCadenaRLE(CadenaComprimida, CaracRepetidos); 
    int CantidadDeRotaciones;                                                                //variable para almacenar la cantidad de rotaciones que el usuario desea realizar en los bits de los caracteres comprimidos 
    do                                                                                //ciclo do-while para solicitar al usuario la cantidad de rotaciones a realizar en los bits de los caracteres comprimidos, se valida que el numero ingresado sea menor a 8 ya que un byte tiene 8 bits y no se pueden rotar maas de 7 posiciones sin volver al estado original
    {
        cout<<"\nIngrese un numero menor a 8 para las rotaciones: "<<endl;                //
        cin>>CantidadDeRotaciones;                                                       // 
    } while (CantidadDeRotaciones>7);                                                  //condion para validar que el numero ingresado sea menor a 8
RotarBits(CadenaComprimida, CantidadDeRotaciones);                      //funcion que rota los bits de cada caracter comprimido, se recorre el arreglo de cada caracter comprimido y se realiza la rotacion de bits segun la cantidad de rotaciones indicada por el usuario, se utiliza el nuevo contador para determinar la cantidad de caracteres comprimidos a rotar

*/




ifstream archivo("XD.txt");
char** matriz=crearMatriz(archivo);
for (int i=0; matriz[i][0]!='\0';i++){
for (int j=0; matriz[i][j]!='\0';j++){
    cout<<matriz[i][j];
}

}



        return 0;
}


 /*   for (int j=0; j<contador; j++){// ciclo for para ver cada byte del arreglo, solo utilizado como ayuda visual para verificar que la funcion de rotacion de bits este funcionando correctamente

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


/*for (int k=0; k<NuevoContador; k++){                                                        //ciclo for para imprimir los bits de cada caractercomrpimido, se utilio como ayuda visual
bin(CadenaComprimida[k]);
cout<<endl;
}
*/
