//Danna Valentina Herrera y Juan Esteban Guaman
/**
 * parcial2.cpp
 * Simulación de dispositivos inteligentes (entrada, simulación y reporte).
 */

#include <iostream>
#include <string>
#include <vector>
#include <fstream>
#include <cstdlib>
#include <ctime>

using namespace std;

/**
 * @brief Clase que representa un dispositivo inteligente doméstico.
 */
class DispositivoInteligente {
private:
    string nombre;
    bool estado;
    float consumoEnergia;
    int id;
    static int contador;

public:
    DispositivoInteligente(string nombre, bool estado, float consumoEnergia)
        : nombre(nombre), estado(estado), consumoEnergia(consumoEnergia) {
        id = ++contador;
    }

    void encender() { estado = true; }
    void apagar()  { estado = false; }

    float simularUso(float horas) const {
        if (estado) return consumoEnergia * horas;
        return 0.0f;
    }

    void mostrarInfo() const {
        cout << "ID: " << id
             << " | Nombre: " << nombre
             << " | Estado: " << (estado ? "Encendido" : "Apagado")
             << " | Consumo base: " << consumoEnergia << " W/h" << endl;
    }

    int getId() const { return id; }
    string getNombre() const { return nombre; }
    float getConsumoBase() const { return consumoEnergia; }
    bool getEstado() const { return estado; }
};

int DispositivoInteligente::contador = 0;

class SistemaHogar {
private:
    vector<DispositivoInteligente> dispositivos;
    vector<float> consumosSimulados; 

public:
    void agregarDispositivo(const DispositivoInteligente &d) {
        dispositivos.push_back(d);
        consumosSimulados.push_back(0.0f);
    }

    void mostrarDispositivos() const {
        cout << "\n--- Lista de Dispositivos Inteligentes ---\n";
        for (const auto &d : dispositivos) d.mostrarInfo();
    }

    
    void simularFlujo() {
        if (dispositivos.empty()) {
            cout << "No hay dispositivos para simular.\n";
            return;
        }

        cout << "\n--- Simulación de flujo de dispositivos ---\n";
        srand(static_cast<unsigned>(time(nullptr)));

        for (size_t i = 0; i < dispositivos.size(); ++i) {
        
            int horas = 1 + rand() % 5;

            bool estabaEncendido = dispositivos[i].getEstado();

            float consumo = 0.0f;
            if (estabaEncendido) {
                consumo = dispositivos[i].simularUso(static_cast<float>(horas));
                cout << "⚪ " << dispositivos[i].getNombre()
                     << " (ID " << dispositivos[i].getId() << ") estuvo "
                     << horas << " h -> consumió " << consumo << " Wh.\n";
            } else {
                cout << "⚫ " << dispositivos[i].getNombre()
                     << " (ID " << dispositivos[i].getId() << ") estaba apagado -> 0 Wh.\n";
            }

            consumosSimulados[i] = consumo;
        }
    }

    void generarReporteTxt(const string &ruta = "reporte.txt") const {
        ofstream archivo(ruta);
        if (!archivo.is_open()) {
            cout << "Error: no se pudo crear " << ruta << endl;
            return;
        }

        archivo << "REPORTE DE CONSUMO DE DISPOSITIVOS\n";
        archivo << "----------------------------------\n";
        for (size_t i = 0; i < dispositivos.size(); ++i) {
            archivo << "ID: " << dispositivos[i].getId()
                    << " | Nombre: " << dispositivos[i].getNombre()
                    << " | Consumo simulado: " << consumosSimulados[i] << " Wh\n";
        }
        archivo.close();
        cout << "\n✅ Reporte generado en '" << ruta << "'.\n";
    }
};

int main() {
    SistemaHogar hogar;
    int cantidad = 0;

    cout << "¿Cuántos dispositivos desea registrar? ";
    if (!(cin >> cantidad) || cantidad <= 0) {
        cout << "Número inválido. Saliendo.\n";
        return 0;
    }
    cin.ignore();

    for (int i = 0; i < cantidad; ++i) {
        string nombre;
        int estadoInt;
        float consumo;

        cout << "\nDispositivo #" << (i + 1) << "\n";
        cout << "Nombre: ";
        getline(cin, nombre);

        cout << "¿Está encendido? (1=Sí, 0=No): ";
        while (!(cin >> estadoInt) || (estadoInt != 0 && estadoInt != 1)) {
            cin.clear();
            cin.ignore(10000, '\n');
            cout << "Ingrese 1 o 0: ";
        }

        cout << "Consumo en vatios/hora: ";
        while (!(cin >> consumo) || consumo < 0.0f) {
            cin.clear();
            cin.ignore(10000, '\n');
            cout << "Ingrese un consumo válido (número): ";
        }
        cin.ignore();

        DispositivoInteligente d(nombre, estadoInt == 1, consumo);
        hogar.agregarDispositivo(d);
    }

    hogar.mostrarDispositivos();

    hogar.simularFlujo();

    hogar.generarReporteTxt("reporte_consumo.txt");

    return 0;
}
