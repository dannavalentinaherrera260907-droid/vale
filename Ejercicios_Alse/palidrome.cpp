//Danna Valentina Herrrera Ortiz y Juan Esteban Guamán Lancheros
#include <iostream>
using namespace std;

class Solution {
public:
    bool isPalindrome(int x) {
       
        if (x < 0) return false;

        long reversed = 0;
        int original = x;

        while (x != 0) {
            int digit = x % 10;
            reversed = reversed * 10 + digit;
            x /= 10;
        }

        return original == reversed;
    }
};

int main() {
    Solution sol;
    int x;

    cout << "Ingrese un número: ";
    cin >> x;

    if (sol.isPalindrome(x))
        cout << "true" << endl;
    else
        cout << "false" << endl;

    return 0;
}
