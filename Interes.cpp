#include <iostream>
#include <cmath>
#include <iomanip>  

// Danna Valentina Herrera y Juan Esteban Guamán

using namespace std;

int main() {
    double ci;   
    double t;    
    int i;       
    double c1;
    double c2;
    double cf;   

    cout << "Bienvenido al programa para calcular el interes compuesto" << endl;
    cout << "Ingrese el capital inicial: ";
    cin >> ci;
    cout << "Ingrese la tasa de interes (decimal): ";
    cin >> t;
    cout << "Ingrese el periodo de ahorros (anios): ";
    cin >> i;

    c1 = 1 + t;
    c2 = pow(c1, i); 
    cf = ci * c2;

    
    cout << fixed << setprecision(2);
    cout << "El capital final es de " << cf << endl;

    return 0;
}
