#include <iostream>
#include <cmath>
using namespace std;

int main(){
    double a, b, c, d, e, f;
    cout << "Enter coefficients a, b, c, d, e and f: ";
    cin >> a >> b >> c >> d >> e >> f;
    
    double D = a * e - b * d;
    double Dx = c * e - b * f;
    double Dy = a * f - c * d;
    
    if (D != 0) {
        double x = Dx / D;
        double y = Dy / D;
        cout << "x is " << x << " and y is " << y << endl;
    } else {
        if (Dx == 0 && Dy == 0) {
            cout << "The system has infinitely many solutions." << endl;
        } else {
            cout << "The system has no solution." << endl;
        }
    }
    
    return 0;
}