#include <iostream>
#include <cmath>
#include <string>
//Integrantes del grupo: Dana Valentina Herrera Ortiz, Juan Esteban Guaman

using namespace std;


struct Point {
    double x;
    double y; 
};

double calcular(Point p1){
    return sqrt(p1.x * p1.x + p1.y * p1.y);
}

void leer(Point puntos[], int n){
    string res;
    cout<< "Desea ingresar los puntos manualmente? (s/n)"<< endl;
    cin>> res;

    if (res=="s"){
        for (int i=0;i<n;i++){
            cout<<"Ingrese las coordenadas del punto "<< i+1 <<" (Escribir como: x(espacio)y):";
            cin>> puntos[i].x >>puntos[i].y;
        }
    }else{
        puntos[0]={0,0};
        puntos[1]={3,4};
        puntos[2]={6,8};
        puntos[3]={-10,-1};
        puntos[4]={2,2};
    }

}

double calcularmayor(Point puntos[], int n, int &indiceMayorMagnitud){
    double mayor=0.0;
    indiceMayorMagnitud=-1;
    for (int i=0; i<n; i++){
        double ma=calcular(puntos[i]);
        if (ma>mayor){
            mayor=ma;
            indiceMayorMagnitud=i;
        }
    }
    return mayor;
}

void mostrar(Point puntos[], int indiceMayorMagnitud, double magnitud){
    if (indiceMayorMagnitud != -1){
        cout<< "El valor de la magnitud es :"<< magnitud << endl;
        cout << "El punto indice de mayor magnitud es: "<< indiceMayorMagnitud << endl;

    }else {
        cout<<"No se encontraron puntos validos" << endl;
    }
}

int main(){
    int numpuntos=5;
    Point puntos[numpuntos];
    int indicemayor;
    double magnitudmayor;

    leer(puntos, numpuntos);
    magnitudmayor= calcularmayor(puntos, numpuntos, indicemayor);
    mostrar(puntos, indicemayor, magnitudmayor);

    return 0;

}