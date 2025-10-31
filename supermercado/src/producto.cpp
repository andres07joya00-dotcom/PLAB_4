/**
 * @file producto.cpp
 * @brief Implementación de la clase producto, que gestiona la información base de los productos disponibles.
 *
 * Este archivo define los métodos de la clase `producto`, encargada de
 * inicializar, mostrar y proveer acceso a los datos de productos.
 *
 */

#include "../include/producto.h"
#include <iostream>
using namespace std;

/**
 * @brief Constructor por defecto de la clase producto.
 *
 * Inicializa los vectores con una lista de productos predefinidos,
 * incluyendo su nombre, precio y cantidad disponible.
 *
 * Los valores por defecto son:
 * - arroz → $15,000 → 5 unidades  
 * - huevo → $18,000 → 12 unidades  
 * - leche → $12,000 → 10 unidades  
 * - pan   → $1,500  → 4 unidades  
 * - café  → $13,000 → 2 unidades  
 */
producto::producto()
    : nombres({"arroz", "huevo", "leche", "pan", "cafe"}),
      precios({15000, 18000, 12000, 1500, 13000}),
      cantidad({5, 12, 10, 4, 2}) {}

/**
 * @brief Muestra la lista de productos disponibles.
 *
 * Imprime en consola el nombre, el precio y la cantidad disponible de cada producto.
 */
void producto::mostrar() {
    cout << "\n--- LISTA DE PRODUCTOS DISPONIBLES ---" << endl;
    for (int i = 0; i < nombres.size(); i++) {
        cout << i + 1 << ". " << nombres[i]
             << " - $" << precios[i]
             << " - Cantidad: " << cantidad[i] << endl;
    }
    cout << endl;
}

/**
 * @brief Obtiene la lista de nombres de los productos.
 * @return Referencia constante al vector de nombres (`vector<string>`).
 */
const vector<string>& producto::getNombres() const { return nombres; }

/**
 * @brief Obtiene la lista de precios de los productos.
 * @return Referencia constante al vector de precios (`vector<int>`).
 */
const vector<int>& producto::getPrecios() const { return precios; }
