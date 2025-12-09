#include <iostream>
#include <vector>
using namespace std;

int main() {
    int n; 
    cout << "Ingrese la cantidad de numeros en el arreglo: ";
    cin >> n;

    vector<int> nums(n); 
    cout << "Ingrese los numeros del arreglo:" << endl;
    for (int i = 0; i < n; i++) {
        cin >> nums[i];
    }

    int target;
    cout << "Ingrese el numero objetivo: ";
    cin >> target;

    int indice1 = -1, indice2 = -1;

    for (int i = 0; i < nums.size(); i++) {
        for (int j = i + 1; j < nums.size(); j++) {
            if (nums[i] + nums[j] == target) {
                indice1 = i;
                indice2 = j;
            }
        }
    }

    if (indice1 != -1 && indice2 != -1) {
        cout << "Los indices son: [" << indice1 << "," << indice2 << "]" << endl;
        cout << "Los numeros que suman " << target << " son: "
             << nums[indice1] << " y " << nums[indice2] << endl;
    } else {
        cout << "No se encontro ninguna pareja que sume el objetivo." << endl;
    }

    return 0;
}