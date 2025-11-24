/*

Harold Arian Corimanya Arias
Codigo: 20242164J


4. Escribe un programa que realice la multiplicación de dos polinomios.

*Para este ejercicio tambien consideraremos a los terminos independientes(grado 0)

*/

#include <iostream>
#include <cmath>

using namespace std;

struct polinomio{
   int *coeficientes;
};


void MostarPolinomio(int *arr,int n){

    for(int i=0;i<=n;i++){
        cout<< arr[i] << "x^"<<i<<" ";
    }
}

int main(){
    polinomio p1,p2,pr;

    //para p1
    int n1 = 4;

    p1.coeficientes = new int[n1+1];
    //para p2
    int n2 = 3;
    p2.coeficientes = new int[n2+1];
    
    //polinomio resultado
    pr.coeficientes = new int[n1+n2+1];

    for(int i=0;i<=n1+n2+1;i++){
        pr.coeficientes[i] = 0;
    }

    cout << "Inserte coeficientes del primer polinomio "<<"(grado "<<n1<<") :";
    for(int i=0;i<=n1;i++){
      cin >> p1.coeficientes[i];
    }
    cout << "Inserte coeficientes del primer polinomio "<<"(grado "<<n2<<") :";
    for(int i=0;i<=n2;i++){
      cin >> p2.coeficientes[i];
    }
    
    for(int i=0;i<=n1;i++){
          for(int j=0;j<=n2;j++){
              pr.coeficientes[i+j] += p1.coeficientes[i] * p2.coeficientes[j];
          }
    }
    cout<<"Primer polinomio: "<<endl;
    MostarPolinomio(p1.coeficientes,n1);

    cout<<"\nSegundo polinomio: "<<endl;
    MostarPolinomio(p2.coeficientes,n2);

    cout<<"\nPolinomio resultado: "<<endl;
    MostarPolinomio(pr.coeficientes,n1+n2);
    

    // Se libera memoria
    delete[] p1.coeficientes;
    delete[] p2.coeficientes;

      
    return 0;
}

/*
Salida: 

Inserte coeficientes del primer polinomio (grado 4) :2 2 2 2 1
Inserte coeficientes del primer polinomio (grado 3) :1 4 3 2
Primer polinomio: 
2x^0 2x^1 2x^2 2x^3 1x^4 
Segundo polinomio: 
1x^0 4x^1 3x^2 2x^3 
Polinomio resultado: 
2x^0 10x^1 16x^2 20x^3 19x^4 14x^5 7x^6 2x^7 


*/
