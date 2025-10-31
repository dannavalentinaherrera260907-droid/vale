//Danna Valentina Herrera y Juan Esteban Guaman
#include <iostream>
#include <string>
#include <vector>
#include <fstream>
using namespace std;

/**
 * @brief Clase que representa un dispositivo inteligente doméstico.
 */
class DispositivoInteligente {
private:
    string nombre;          ///< Nombre del dispositivo
    bool estado;            ///< Estado (true encendido / false apagado)
    float consumoEnergia;   ///< Consumo en Wh
    bool controlBloqueado;  ///< Indica si el control remoto está bloqueado
    int id;                 ///< Identificador del dispositivo

public:
    /**
     * @brief Constructor que inicializa todos los atributos.
     * @param _id ID del dispositivo.
     * @param nom Nombre del dispositivo.
     * @param est Estado inicial (encendido/apagado).
     * @param consumo Consumo en Wh.
     */
    DispositivoInteligente(int _id, string nom, bool est, float consumo) {
        id = _id;
        nombre = nom;
        estado = est;
        consumoEnergia = consumo;
        controlBloqueado = false;
    }

    /**
     * @brief Enciende el dispositivo si no está bloqueado.
     */
    void encender() {
        if (!controlBloqueado) {
            estado = true;
            cout << nombre << " encendido." << endl;
        } else {
            cout << "No se puede encender, control bloqueado." << endl;
        }
    }

    /**
     * @brief Apaga el dispositivo.
     */
    void apagar() {
        estado = false;
        cout << nombre << " apagado." << endl;
    }

    /**
     * @brief Calcula el consumo total según las horas de uso.
     * @param horas Tiempo de uso en horas.
     * @return Energía total consumida (Wh).
     */
    float medirConsumo(float horas) {
        if (estado) {
            float total = consumoEnergia * horas;
            cout << nombre << " consumió " << total << " Wh" << endl;
            return total;
        } else {
            cout << nombre << " está apagado, sin consumo." << endl;
            return 0;
        }
    }

    /**
     * @brief Bloquea el control remoto del dispositivo.
     */
    void bloquearControlRemoto() {
        controlBloqueado = true;
        cout << "Control remoto bloqueado para " << nombre << endl;
    }

    /**
     * @brief Muestra información general del dispositivo.
     */
    void mostrarInfo() {
        cout << "ID: " << id
             << " | Nombre: " << nombre
             << " | Estado: " << (estado ? "Encendido" : "Apagado")
             << " | Consumo: " << consumoEnergia << " Wh" << endl;
    }

    /**
     * @brief Devuelve el ID del dispositivo.
     */
    int getId() { return id; }

    /**
     * @brief Devuelve el nombre del dispositivo.
     */
    string getNombre() { return nombre; }
};

// ---------------------------------------------------------------
// Aplicación principal (simulación de varios dispositivos)
// ---------------------------------------------------------------
int main() {
    // Crear vector de dispositivos inteligentes
    vector<DispositivoInteligente> dispositivos;

    // Agregar algunos dispositivos simulados
    dispositivos.push_back(DispositivoInteligente(1, "Luz sala", false, 60.0));
    dispositivos.push_back(DispositivoInteligente(2, "Televisor", true, 120.5));

    // Simular acciones
    for (auto &d : dispositivos) {
        d.mostrarInfo();
        d.encender();
    }

    cout << "\n--- Simulación de consumo ---" << endl;

    // Simular lectura de datos (horas de uso)
    float horasUso[] = {2.5, 4.0};
    vector<float> consumosTotales;

    for (size_t i = 0; i < dispositivos.size(); i++) {
        float energia = dispositivos[i].medirConsumo(horasUso[i]);
        consumosTotales.push_back(energia);
    }

    // Generar reporte en archivo .txt
    ofstream reporte("reporte_consumo.txt");
    if (reporte.is_open()) {
        reporte << "REPORTE DE CONSUMO DE DISPOSITIVOS\n";
        reporte << "----------------------------------\n";
        for (size_t i = 0; i < dispositivos.size(); i++) {
            reporte << "ID: " << dispositivos[i].getId()
                    << " | Nombre: " << dispositivos[i].getNombre()
                    << " | Consumo total: " << consumosTotales[i] << " Wh\n";
        }
        reporte.close();
        cout << "\nReporte generado: reporte_consumo.txt ✅" << endl;
    } else {
        cout << "Error al crear el archivo de reporte." << endl;
    }

    return 0;
}
