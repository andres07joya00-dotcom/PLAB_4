/**
 * @file usuario.cpp
 * @brief Implementación de la clase Usuario, que administra los datos y el historial de compras de un cliente.
 *
 * Este archivo define los métodos de la clase `Usuario`, encargada de manejar el
 * nombre del cliente, almacenar sus compras y mostrar el historial completo.
 *
 */

#include "../include/usuario.h"
#include <iostream>
using namespace std;

/**
 * @brief Constructor de la clase Usuario.
 *
 * Inicializa el objeto con el nombre del usuario proporcionado.
 *
 * @param _nombre Nombre del usuario o cliente.
 */
Usuario::Usuario(string _nombre) : nombre(_nombre) {}

/**
 * @brief Obtiene el nombre del usuario.
 * @return Nombre del usuario (`string`).
 */
string Usuario::getNombre() const { return nombre; }

/**
 * @brief Guarda una compra en el historial del usuario.
 *
 * Añade un nuevo vector de objetos `itemcarrito` al historial de compras.
 * Cada vector representa una compra completa (carrito finalizado).
 *
 * @param carrito Vector que contiene los productos comprados.
 * @note Se asume que el vector `carrito` contiene ítems válidos y con totales calculados.
 */
void Usuario::guardarCompra(const vector<itemcarrito> &carrito) {
    historialCompras.push_back(carrito);
    cout << "Compra guardada en el historial de " << nombre << ".\n";
}

/**
 * @brief Muestra el historial de compras del usuario.
 *
 * Recorre todas las compras almacenadas y muestra los productos, cantidades y totales
 * de cada una. También indica el total de cada compra.
 */
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
            cout << "- " << item.getProducto()
                 << " x" << item.getCantidad()
                 << " ($" << item.getTotal() << ")\n";
            total += item.getTotal();
        }

        cout << "Total compra: $" << total << "\n\n";
    }
}

