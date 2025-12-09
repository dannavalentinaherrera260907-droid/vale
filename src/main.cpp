#include <iostream>
#include <sqlite3.h>

int main()
{
    sqlite3* db;

    // RUTA CORRECTA PARA TU PROYECTO
    int rc = sqlite3_open("db/inventory.db", &db);

    if (rc)
    {
        std::cout << "❌ No se pudo abrir la base de datos\n";
        std::cout << sqlite3_errmsg(db) << std::endl;
        return 1;
    }

    std::cout << "✅ Base de datos abierta correctamente\n\n";

    const char* sql =
        "SELECT id, name, type, quantity, min_stock, location, purchase_date, notes "
        "FROM components;";

    auto callback = [](void*, int columns, char** data, char**) -> int
    {
        std::cout << "-----------------------------\n";
        for (int i = 0; i < columns; i++)
        {
            std::cout << (data[i] ? data[i] : "NULL") << "\n";
        }
        return 0;
    };

    char* errMsg = nullptr;

    rc = sqlite3_exec(db, sql, callback, nullptr, &errMsg);

    if (rc != SQLITE_OK)
    {
        std::cout << "❌ Error SQL:\n";
        std::cout << errMsg << std::endl;
        sqlite3_free(errMsg);
    }
    else
    {
        std::cout << "\n✅ Consulta ejecutada correctamente\n";
    }

    sqlite3_close(db);
    return 0;
}
