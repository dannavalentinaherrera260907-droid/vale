//Danna Valentina Herrera y Juan Esteban Guaman

#include <iostream>
#include <vector>
#include <string>
using namespace std;


class Vehiculo {
protected:
    string marca;
    string modelo;
    string placa;
    bool disponible;

public:
    Vehiculo(string m, string mo, string p)
        : marca(m), modelo(mo), placa(p), disponible(true) {}

    virtual ~Vehiculo() {}

    virtual void mostrarInformacion() const {
        cout << "Marca: " << marca << " | Modelo: " << modelo 
             << " | Placa: " << placa;
    }

    bool estaDisponible() const { return disponible; }

    void alquilar() { disponible = false; }

    void devolver() { disponible = true; }

    string getPlaca() const { return placa; }
};


class Auto : public Vehiculo {
    int capacidadPasajeros;

public:
    Auto(string m, string mo, string p, int cap)
        : Vehiculo(m, mo, p), capacidadPasajeros(cap) {}

    void mostrarInformacion() const override {
        cout << "[AUTO] ";
        Vehiculo::mostrarInformacion();
        cout << " | Capacidad: " << capacidadPasajeros << " pasajeros";
        if (estaDisponible())
            cout << " | Estado: Disponible";
        else
            cout << " | Estado: Alquilado";
        cout << endl;
    }
};


class Bicicleta : public Vehiculo {
    string tipo; 

public:
    Bicicleta(string m, string mo, string p, string t)
        : Vehiculo(m, mo, p), tipo(t) {}

    void mostrarInformacion() const override {
        cout << "[BICICLETA] ";
        Vehiculo::mostrarInformacion();
        cout << " | Tipo: " << tipo;
        if (estaDisponible())
            cout << " | Estado: Disponible";
        else
            cout << " | Estado: Alquilado";
        cout << endl;
    }
};


class SistemaAlquiler {
    vector<Vehiculo*> vehiculos;

public:
    ~SistemaAlquiler() {
        for (auto v : vehiculos)
            delete v;
    }

    void registrarVehiculo(Vehiculo* v) {
        vehiculos.push_back(v);
        cout << "✅ Vehículo registrado exitosamente.\n";
    }

    void mostrarVehiculosDisponibles() const {
        cout << "\n🚘 Vehículos disponibles:\n";
        for (auto v : vehiculos)
            if (v->estaDisponible())
                v->mostrarInformacion();
    }

    void alquilarVehiculo(const string& placa) {
        for (auto v : vehiculos) {
            if (v->getPlaca() == placa) {
                if (v->estaDisponible()) {
                    v->alquilar();
                    cout << "✅ Vehículo " << placa << " alquilado exitosamente.\n";
                } else {
                    cout << "❌ El vehículo ya está alquilado.\n";
                }
                return;
            }
        }
        cout << "❌ Vehículo no encontrado.\n";
    }

    void devolverVehiculo(const string& placa) {
        for (auto v : vehiculos) {
            if (v->getPlaca() == placa) {
                if (!v->estaDisponible()) {
                    v->devolver();
                    cout << "✅ Vehículo " << placa << " devuelto correctamente.\n";
                } else {
                    cout << "❌ El vehículo ya está disponible.\n";
                }
                return;
            }
        }
        cout << "❌ Vehículo no encontrado.\n";
    }

    void mostrarTodosVehiculos() const {
        cout << "\n📋 Lista completa de vehículos:\n";
        for (auto v : vehiculos)
            v->mostrarInformacion();
    }
};


int main() {
    SistemaAlquiler sistema;
    int opcion;

    do {
        cout << "\n===== 🚗 SISTEMA DE ALQUILER DE VEHÍCULOS =====\n";
        cout << "1. Registrar Auto\n";
        cout << "2. Registrar Bicicleta\n";
        cout << "3. Mostrar Vehículos Disponibles\n";
        cout << "4. Alquilar Vehículo\n";
        cout << "5. Devolver Vehículo\n";
        cout << "6. Mostrar Todos los Vehículos\n";
        cout << "0. Salir\n";
        cout << "Seleccione una opción: ";
        cin >> opcion;
        cin.ignore();

        if (opcion == 1) {
            string marca, modelo, placa;
            int capacidad;
            cout << "Marca: "; getline(cin, marca);
            cout << "Modelo: "; getline(cin, modelo);
            cout << "Placa: "; getline(cin, placa);
            cout << "Capacidad de pasajeros: "; cin >> capacidad;
            sistema.registrarVehiculo(new Auto(marca, modelo, placa, capacidad));
        } 
        else if (opcion == 2) {
            string marca, modelo, placa, tipo;
            cout << "Marca: "; getline(cin, marca);
            cout << "Modelo: "; getline(cin, modelo);
            cout << "Referencia: "; getline(cin, placa);
            cout << "Tipo (montaña/urbana/etc.): "; getline(cin, tipo);
            sistema.registrarVehiculo(new Bicicleta(marca, modelo, placa, tipo));
        } 
        else if (opcion == 3) {
            sistema.mostrarVehiculosDisponibles();
        } 
        else if (opcion == 4) {
            string placa;
            cout << "Ingrese la placa del vehículo a alquilar: ";
            getline(cin, placa);
            sistema.alquilarVehiculo(placa);
        } 
        else if (opcion == 5) {
            string placa;
            cout << "Ingrese la placa del vehículo a devolver: ";
            getline(cin, placa);
            sistema.devolverVehiculo(placa);
        } 
        else if (opcion == 6) {
            sistema.mostrarTodosVehiculos();
        }

    } while (opcion != 0);

    cout << "👋 Gracias por usar el sistema.\n";
    return 0;
}
