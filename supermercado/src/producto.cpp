#include "producto.h"

producto::producto()
    : nombres({"arroz", "huevo", "leche", "pan", "cafe"}),
      precios({15000, 18000, 12000, 1500, 13000}),
      cantidad({5, 12, 10, 4, 2}) {}

void producto::mostrar() {
    cout << "--- LISTA DE PRODUCTOS ---" << endl;
    for (int i = 0; i < nombres.size(); i++) {
        cout << i + 1 << ". " << nombres[i]
             << " - $" << precios[i]
             << " - Cantidad disponible: " << cantidad[i] << endl;
    }
    cout << endl;
}
