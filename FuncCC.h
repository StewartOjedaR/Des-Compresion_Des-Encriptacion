#ifndef FUNCCC_H
#define FUNCCC_H

#include <iostream>
#include <fstream>
using namespace std;
static unsigned short cantSufijos = 1; // sabre cuantos caracteres comparar antes de agregar un nodo
struct Nodo
{
    char *sufijo;
    unsigned int indice;
    unsigned int posicion;
    Nodo *siguiente;
};
class Diccionario
{
private:
    Nodo *cabeza;

public:
    Diccionario::Diccionario() { cabeza = nullptr; }
    void agregarNodo(unsigned int _indice, char *_sufijo);
    void mostrarNodo(Nodo *Nodo, int _indice, char _sufijo);
};

void Diccionario::agregarNodo(unsigned int _indice, char *_sufijo)
{
    Nodo *nuevoNodo = new Nodo();   //|nuevo nodo para almacenar:
    nuevoNodo->indice = _indice;    //|indice del diccionario
    nuevoNodo->sufijo = _sufijo;    //|
    nuevoNodo->siguiente = nullptr; //|el siguiente nodo nulo
    if (cabeza == nullptr)
    {                       // si el nodo cabeza no apunta todavia a nada
        cabeza = nuevoNodo; // cabeza apuntara a nuevo nodo y sus dttos
    }
    else
    {
        Nodo *aux = cabeza;               // un nodo auxiliar para encontrar el ultimo nodo de la lista
        while (aux->siguiente != nullptr) // hasta que el nodo siguiente de aux sea nullptr
        {
            aux = aux->siguiente; // el nodo aux tiene dentro un nodo apuntando al siguiente, entonces como la condicion lo dejollegar significa que siguiente es un nodo valido asi que lo asigno a la mismo aux, asi hasta que el nodo que tenga aux->siguiente=nullptr pues al asignarse, en el la siguiente iteracion quedara en la ultima posicion de la lista
        }
        aux->siguiente = nuevoNodo; // una vez aux->siguiente==nullptr, le asigno el nuevo nodo a aux->siguiente
    }
};
// leer el txt
// guardar el txt por renglon en una matriz
void leerTxt(const char archivoTXT[])
{

    std::ifstream archivo(archivoTXT); // leer un archivo de texto, se utiliza la clase ifstream para abrir el archivo y se pasa como argumento a la funcion leerTexto, el archivo debe estar en la misma carpeta que el programa o se debe especificar la ruta completa del archivo
    if (archivo.is_open())
    {
        //   char**matrizTexto=crearMatriz(archivo)
        archivo.close();
    }
    else
    {
        cout << "No se pudo abrir el archivo." << endl;
    }
}
// leer cada renglon
// por renglon, leer cada caracter e ir agregando en los nodos, en cada posicion veo si esta en el nodo y la agrego,
//
bool estaEnDiccionario(char *, char *, Nodo *, int posiciones);
void guardarString();
void cargarString();

char *linea();

// Funcion para redimensionar el arreglo
void redimensionar(char *&arreglo, unsigned int capacidad, unsigned int nuevaCapacidad, unsigned int contador)
{
    char *pArregloCopia = new char[nuevaCapacidad];

    // Copiar elementos existentes
    for (unsigned int i = 0; i < contador; i++)
    {
        pArregloCopia[i] = arreglo[i];
    }
    //  delete[] arreglo;
    arreglo = nullptr;
    arreglo = pArregloCopia;
    capacidad = nuevaCapacidad;
}

void ImprimirCadenaRLE(char *CadenaComprimida, char *CaracRepetidos)
{
    int contador = 0;
    for (int i = 0; i < i + 1; i++)
    {
        if (CadenaComprimida[i] == '\0')
            break;
        contador++;
    }

    for (int i = 0; i < contador; i++)
    {
        cout << CadenaComprimida[i] << int(CaracRepetidos[i]);
    }
}

// Funcion para insertar renglon
char **insertarRenglon(char **matriz, char *linea, int numLineas)
{
    // Crear nueva matriz con una fila de mas
    char **nuevaMatriz = new char *[numLineas + 1];

    // Copiar punteros de filas anteriores
    for (int i = 0; i < numLineas; i++)
    {
        nuevaMatriz[i] = matriz[i];
    }

    // Insertar el nuevo renglon
    nuevaMatriz[numLineas] = new char[1024];
    for (int i = 0; i < 1024; i++)
    {
        nuevaMatriz[numLineas][i] = linea[i];
    }

    // Liberar la matriz antigua (solo el arreglo de punteros, no las filas)
    if (numLineas > 0)
    {
        delete[] matriz;
    }

    return nuevaMatriz; // devolver la nueva matriz
}

// Funcion para crear matriz desde un archivo
char **crearMatriz(istream &archivo)
{
    char caracter;                   // variable para almacenar temporalmente un caracter
    short contCaract = 0;            // contador de caracteres por linea
    int contLineas = 0;              // contador de lineas
    char *lineaAux = new char[1024]; // una linea auxiliar con 1024(lo que hay en una linea)
    for (int i = 0; i < 1024; i++)
    { // todos los datos nulos
        lineaAux[i] = '\0';
    }
    char **matriz = nullptr; // Matriz aun sin apuntar a memoria
    while (archivo.get(caracter))
    { // ciclo while para obtener cada caracter del archivo de texto
        if (caracter == '\n')
        {                                                           // condicion para saber cuando hay un cambio de linea
            lineaAux[contCaract] = '\0';                            // Aseguro ultimo caracter nulo
            matriz = insertarRenglon(matriz, lineaAux, contLineas); // inserta un nuevo renglon en la matriz
            contLineas++;
            contCaract = 0;
            for (int i = 0; i < 1024; i++)
            { // Reiniciar linea Auxiliar
                lineaAux[i] = '\0';
            }
        }
        else
        {
            lineaAux[contCaract++] = caracter; // asigna el caracter a la posicion correspondiente en el arreglo
        }
    }

    // si no termina en '\n'
    if (contCaract > 0)
    {
        lineaAux[contCaract] = '\0';
        matriz = insertarRenglon(matriz, lineaAux, contLineas);
        contLineas++;
    }

    delete[] lineaAux; // Liberar buffer auxiliar
    return matriz;
}

void ArregloString(char*& Cadena,istream& entrada, const char* mensaje = "Ingresa texto (Enter para terminar): ") {
    int Capacidad = 1;
    int*ptrCapacidad=&Capacidad;
    Cadena = new char[Capacidad];
    unsigned int contador = 0;
    char Caracter;
    if (&entrada == &cin) cout << mensaje;
        while (entrada.get(Caracter)) {                               // Lee un caracter a la vez, el bucle continúa hasta que se presiona Enter (caracter de nueva linea)
        if (&entrada == &cin && Caracter == '\n'){ break;}
        if (contador >= Capacidad) {                                            //Si el contador alcanza o supera la capacidad actual del arreglo, es necesario redimensionar el arreglo para acomodar mas caracteres
            redimensionar(Cadena, Capacidad, Capacidad*2, contador);          // Copia el viejo arreglo, libera el viejo arreglo y crea uno nuevo con la nueva capacidad
            Capacidad *= 2; // Incrementa la capacidad para la proxima vez que se necesite redimensionar el arreglo, en este caso se incrementa por dos para evitar desperdiciar memoria
        }
        Cadena[contador++] = Caracter;                                          // Almacena el caracter ingresado en el arreglo y luego incrementa el contador para la próxima posición del arreglo
    }
    
    // Agregar el caracter nulo al final
    if (contador >= Capacidad) {
        redimensionar(Cadena, Capacidad, Capacidad +1, contador);
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



// Funcion para descomprimir RLE
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
