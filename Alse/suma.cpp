#include <iostream>
using namespace std;

int main() {
    int n;

    cout << "Ingrese la cantidad de elementos del arreglo: ";
    cin >> n;

    int arreglo[n];   // Declaramos el arreglo de tamaño n
    int suma = 0;

    // Ingreso de datos
    cout << "Ingrese los " << n << " elementos del arreglo:" << endl;
    for (int i = 0; i < n; i++) {
        cin >> arreglo[i];
        suma += arreglo[i]; // Vamos sumando directamente
    }

    // Resultado
    cout << "La suma de los elementos del arreglo es: " << suma << endl;

    return 0;
}
