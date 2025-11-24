/*

Harold Arian Corimanya Arias
Codigo: 20242164J


1. Un bus puede transportar diariamente entre 500 y 700 pasajeros. Considere un arreglo A
que contiene valores aleatorios del número de pasajeros por cada día del año, asuma que el año tiene
12 meses de 30 días.

Escriba un programa que utilice un puntero a estructuras para crear un listado del número de
pasajeros y fechas en la que el bus estuvo a un 95% o más de su capacidad máxima. El listado puede
utilizar la siguiente definición de estructura:

*/


#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;

struct TFECHA{

    int dia,mes;
};

struct TCARGA{

    int numpasajeros;
    TFECHA* fecha;

};

int main(){
     
    srand(time(NULL));

    int min = 0.95 * 700; // mayor o igual al 95%
	const int MES = 12;
    const int DIA = 30;

    int A[MES][DIA] ;

    for(int i=0;i<MES;i++){
        for(int j=0;j<DIA;j++){
            A[i][j] = 500 + rand()%201; // valores entre 500 y 700
        }
    }

    int cant = 0;
    for(int i=0;i<MES;i++){
        for(int j=0;j<DIA;j++){
            if(A[i][j] >= min ){
                cant++;
            }
        }
    }

    cout<<"Se encontraron " <<cant<< " dias con carga minima de " << min << " pasajeros"<<endl;
	
    TCARGA* Lista = new TCARGA[cant];
    TFECHA* fechas = new TFECHA[cant];

    int k = 0;
    for(int i=0;i<MES;i++){
        for(int j=0;j<DIA;j++){
            if(A[i][j] >= min ){
                fechas[k].dia = i + 1;   
                fechas[k].mes = j + 1;   
                Lista[k].numpasajeros = A[i][j];
                Lista[k].fecha = &fechas[k]; 
                k++;
            }
        }
    }

     for (int i = 0; i < cant; i++) {
    cout <<Lista[i].fecha->mes<< " / " <<Lista[i].fecha->dia<<" : "<<Lista[i].numpasajeros<<" pasajeros"<<endl;
    }

    // Se libera memoria
    delete[] fechas;
    delete[] Lista;
	
	return 0;
}

/*

Salida( ejemplo con 95% ): 

Se encontraron 68 dias con carga minima de 665 pasajeros

7 / 1 : 670 pasajeros
11 / 1 : 695 pasajeros
23 / 1 : 670 pasajeros
29 / 1 : 688 pasajeros
30 / 1 : 698 pasajeros
7 / 2 : 699 pasajeros
9 / 2 : 686 pasajeros
15 / 2 : 690 pasajeros
19 / 2 : 671 pasajeros
26 / 2 : 699 pasajeros
3 / 3 : 694 pasajeros
4 / 3 : 698 pasajeros
11 / 3 : 683 pasajeros
16 / 3 : 690 pasajeros
21 / 3 : 682 pasajeros
25 / 3 : 680 pasajeros
26 / 3 : 676 pasajeros
30 / 3 : 689 pasajeros
2 / 4 : 675 pasajeros
3 / 4 : 674 pasajeros
10 / 4 : 698 pasajeros
14 / 4 : 696 pasajeros
15 / 4 : 680 pasajeros
18 / 4 : 674 pasajeros
4 / 5 : 674 pasajeros
8 / 5 : 674 pasajeros
9 / 5 : 666 pasajeros
11 / 5 : 696 pasajeros
13 / 5 : 678 pasajeros
16 / 5 : 699 pasajeros
18 / 5 : 674 pasajeros
2 / 6 : 666 pasajeros
17 / 6 : 684 pasajeros
21 / 6 : 686 pasajeros
25 / 6 : 685 pasajeros
28 / 6 : 677 pasajeros
29 / 6 : 690 pasajeros
8 / 7 : 686 pasajeros
19 / 7 : 675 pasajeros
21 / 7 : 669 pasajeros
2 / 8 : 688 pasajeros
4 / 8 : 667 pasajeros
5 / 8 : 696 pasajeros
13 / 8 : 669 pasajeros
25 / 8 : 677 pasajeros
27 / 8 : 699 pasajeros
30 / 8 : 688 pasajeros
5 / 9 : 683 pasajeros
7 / 9 : 679 pasajeros
20 / 9 : 700 pasajeros
22 / 9 : 695 pasajeros
25 / 9 : 682 pasajeros
28 / 9 : 692 pasajeros
8 / 10 : 680 pasajeros
17 / 10 : 680 pasajeros
22 / 10 : 672 pasajeros
26 / 10 : 680 pasajeros
29 / 10 : 680 pasajeros
2 / 11 : 692 pasajeros
5 / 11 : 697 pasajeros
9 / 11 : 665 pasajeros
15 / 11 : 673 pasajeros
25 / 11 : 669 pasajeros
28 / 11 : 666 pasajeros
1 / 12 : 683 pasajeros
4 / 12 : 667 pasajeros
14 / 12 : 673 pasajeros
23 / 12 : 688 pasajeros


*/