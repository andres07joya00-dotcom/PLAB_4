#include "../include/usuario.h"

Usuario::Usuario(string _nombre) : nombre(_nombre) {}

string Usuario::getNombre() const { return nombre; }

void Usuario::guardarCompra(const vector<itemcarrito> &carrito) {
    historialCompras.push_back(carrito);
    cout << "Compra guardada en el historial de " << nombre << ".\n";
}

void Usuario::mostrarHistorial() {
    cout << "\n=== HISTORIAL DE COMPRAS DE " << nombre << " ===\n";
    if (historialCompras.empty()) {
        cout << "No hay compras registradas.\n";
        return;
    }
    for (int i = 0; i < historialCompras.size(); i++) {
        cout << "Compra #" << i + 1 << ":\n";
        int total = 0;
        for (auto &item : historialCompras[i]) {
            cout << "- " << item.getProducto() << " x" << item.getCantidad()
                 << " ($" << item.getTotal() << ")\n";
            total += item.getTotal();
        }
        cout << "Total compra: $" << total << "\n\n";
    }
}

