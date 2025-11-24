/*

Harold Arian Corimanya Arias
Codigo: 20242164J


2. Escriba un programa en C++ cuya función main() tenga la forma:

int main() {
 escribirFibonacciBinario();
 leerFibonacciBinario();
 return 0;
}

a) La función escribirFibonacciBinario() escribe en el archivo binario fibonacci.bin los 20
primeros términos de la sucesión de Fibonacci.

b) La función leerFibonacciBinario() lee desde el archivo binario fibonacci.bin los términos
guardados en el item anterior y los imprime en pantalla.

Al ejecutar, la salida debe ser EXACTAMENTE igual a la figura.


*/


#include <iostream>
#include <fstream>
#include <string>
using namespace std;

void fibonacci(int n){
    int a = 0,b = 1,c;
    for(int i=0;i<n;i++){
        cout << "termino "<<i+1<<": "<<a<<endl;
        c = a + b;
        a = b;
        b = c;
    }
}

void escribirFibonacciBinario(){
  

    ofstream f("Fibonacci.bin");
    if (!f.is_open()) {
        cout << "Error, el archivo no pudo crearse\n";
    }

    else{

    cout<<"Funcion escribirFibonacciBinario: "<<endl;

    int n = 20;
    int a = 0,b = 1,c;
    for(int i=0;i<n;i++){
        f << "termino "<<i+1<<": "<<a<<endl;
        c = a + b;
        a = b;
        b = c;
    }
    cout<<"Terminos de fibonacci escritos en el archivo correctamente."<<endl;

    }

    f.close();

}

void LeerFibonacciBinario(){  
    ifstream f("Fibonacci.bin");

    if (!f.is_open()) {
        cerr << "No se pudo abrir \n";
     }

    else{

    cout<<"LeerFibonacciBinario: "<<endl;

    string linea;
     while(getline(f,linea)){
           cout << linea << endl;
    }

    }

    f.close();
    
}

int main(){
   escribirFibonacciBinario();
   LeerFibonacciBinario();
   return 0;

}

/*
Salida:

Funcion escribirFibonacciBinario: 
Terminos de fibonacci escritos en el archivo correctamente.
LeerFibonacciBinario: 
termino 1: 0
termino 2: 1
termino 3: 1
termino 4: 2
termino 5: 3
termino 6: 5
termino 7: 8
termino 8: 13
termino 9: 21
termino 10: 34
termino 11: 55
termino 12: 89
termino 13: 144
termino 14: 233
termino 15: 377
termino 16: 610
termino 17: 987
termino 18: 1597
termino 19: 2584
termino 20: 4181

*/