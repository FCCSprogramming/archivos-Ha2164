/*

Harold Arian Corimanya Arias
Codigo: 20242164J


3. El estado peruano en su política de combatir el cambio climático desea monitorear la
superficie de las principales lagunas del país, para ello en base a imágenes satelitales ha podido
triangular la región que ocupa cada laguna. Dicha información se almacena en archivos de texto con
el siguiente formato:

- En la primera línea se tiene el número de triángulos (nt).
- En la segunda línea está el número de vértices (nv).
- En las siguientes nv líneas están las coordenadas de los vértices.
- En las siguientes nt líneas esta la numeración de los vértices de los triángulos.

Escriba un programa en C++ que lea el archivo laguna.txt en el formato descrito, calcule el área total
de la laguna y almacene el resultado en el archivo area.txt.

*/

#include <iostream>
#include <fstream>
#include <cmath> // para valor absoluto
#include <iomanip> // decimales
using namespace std;

int main() {
    ifstream Leer("laguna.txt");
    if (!Leer.is_open()) {
        cerr << "No se pudo abrir \n";
    }
    
    // Se lee el numero de triangulos y vertices
    int nt, nv;
    Leer >> nt >> nv; 

    double* x = new double[nv];
    double* y = new double[nv];
   

    // Se lee y almacena cada coordernada de los vertices

    for (int i=0;i<nv;i++)
        Leer >> x[i] >> y[i];


    // Se lee y almacena el orden numerico de cada triangulo
    // Usamos un arreglo 1D

    int* tri = new int[nt * 3];
    
    for (int i=0;i<nt;i++) {
        int a,b,c;
        Leer >> a >> b >> c;      
        tri[i*3+0] = a - 1;   // Para obtener el indice adecuado
        tri[i*3+1] = b - 1;
        tri[i*3+2] = c - 1;
    }

    Leer.close();

    double area_total = 0.0;
    for (int i=0;i<nt;i++) {

        int ind1 = tri[i*3+0];
        int ind2 = tri[i*3+1];
        int ind3 = tri[i*3+2];

        double x1 = x[ind1], y1 = y[ind1];
        double x2 = x[ind2], y2 = y[ind2];
        double x3 = x[ind3], y3 = y[ind3];

        double area = fabs( x1*(y3 - y2) + x2*(y1 - y3) + x3*(y2 - y1) ) / 2.0;
        area_total += area;
    }

    ofstream Escribir("area.txt");

    if (!Escribir.is_open()) {
        cout << "Error, el archivo no pudo crearse\n";
    }
    else{

    Escribir <<"Area total: "<< fixed << setprecision(2) << area_total << '\n';

    cout<<"Se escribio en el archivo exitosamente!"<<endl;
    }

    Escribir.close();

    delete[] x;
    delete[] y;
    delete[] tri;
    return 0;
}

/*
Se modifico el archivo lagunas.txt para que tenga el mismo sentido que la imagen

El archivo area.txt muestra el valor de 1.75 .

*/
