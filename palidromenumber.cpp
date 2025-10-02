
#include <iostream>
#include <string>
#include <functional>
#include <map>
#include <cstdlib>

using namespace std;

//Danna Valentina Herrera Ortiz y Juan Esteban Guamán Lancheros

using Operation = function<float(float, float)>;

int main(int argc, char* argv[]) {
    if (argc != 4) {
        cerr << "Error: Se requieren exactamente 3 argumentos.\n";
        cerr << "Uso: " << argv[0] << " <numero1> <operador> <numero2>\n";
        return 1;
    }

    try {
        float num1 = stof(argv[1]);
        string op = argv[2];
        float num2 = stof(argv[3]);

        
        map<string, Operation> operaciones;
        operaciones["+"] = [](float a, float b) { return a + b; };
        operaciones["-"] = [](float a, float b) { return a - b; };
        operaciones["*"] = [](float a, float b) { return a * b; };
        operaciones["x"] = [](float a, float b) { return a * b; };
        operaciones["/"] = [](float a, float b) { 
            if (b == 0) throw runtime_error("Error: Division por cero.");
            return a / b; 
        };

        if (operaciones.find(op) == operaciones.end()) {
            cerr << "Error: Operador no reconocido (" << op << "). Use +, -, *, x o /\n";
            return 1;
        }

        float resultado = operaciones[op](num1, num2);
        cout << "Resultado: " << resultado << endl;

    } catch (const invalid_argument& e) {
        cerr << "Error: Argumento invalido, asegurese de ingresar numeros correctos.\n";
        return 1;
    } catch (const runtime_error& e) {
        cerr << e.what() << endl;
        return 1;
    }

    return 0;
}
