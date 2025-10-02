#include <iostream>
using namespace std;

//Danna Valentina Herrera y Juan Esteban Guamán

// Función que calcula el MCD usando el algoritmo de Euclides
int mcd(int a, int b) {
    while (b != 0) {
        int resto = a % b;
        a = b;
        b = resto;
    }
    return a;
}

int main() {
    int num1, num2;

    cout << "Ingrese el primer numero: ";
    cin >> num1;
    cout << "Ingrese el segundo numero: ";
    cin >> num2;

    cout << "El MCD de " << num1 << " y " << num2 << " es: " << mcd(num1, num2) << endl;

    return 0;
}
