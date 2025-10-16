//Danna Valentina Herrera y Juan Esteban Guamán

#include <iostream>
#include <vector>
#include <iomanip>
using namespace std;

vector<vector<int>> generarTrianguloPascal(int numRows) {
    vector<vector<int>> triangle;

    if (numRows == 0) return triangle;

    triangle.push_back({1});

    for (int i = 1; i < numRows; i++) {
        vector<int> prevRow = triangle[i - 1];
        vector<int> currRow;

        currRow.push_back(1);
        for (int j = 1; j < i; j++) {
            currRow.push_back(prevRow[j - 1] + prevRow[j]);
        }
        currRow.push_back(1);

        triangle.push_back(currRow);
    }

    return triangle;
}


void imprimirTriangulo60(const vector<vector<int>>& triangle) {
    int n = triangle.size();

    int anchoMax = 0;
    for (auto fila : triangle)
        for (int num : fila)
            anchoMax = max(anchoMax, (int)to_string(num).length());

    int espacio = anchoMax + 2;

    cout << "\n";
    for (int i = 0; i < n; i++) {
        
        cout << string((n - i - 1) * espacio / 2, ' ');

        for (int j = 0; j < triangle[i].size(); j++) {
            cout << setw(anchoMax) << triangle[i][j];

            cout << string(espacio, ' ');
        }
        cout << "\n\n";
    }
}

int main() {
    int filas;
    cout << "🔺 TRIÁNGULO DE PASCAL (ALINEADO 60°) 🔺\n";
    cout << "Ingrese el número de filas: ";
    cin >> filas;

    if (filas <= 0) {
        cout << "Debe ingresar un número mayor que 0.\n";
        return 0;
    }

    vector<vector<int>> triangulo = generarTrianguloPascal(filas);

    cout << "\nTriángulo de Pascal con " << filas << " filas:\n";
    imprimirTriangulo60(triangulo);

    cout << "Fila " << filas << ": ";
    for (int num : triangulo[filas - 1]) {
        cout << num << " ";
    }
    cout << "\n";

    return 0;
}
