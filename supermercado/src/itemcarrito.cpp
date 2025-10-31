/**
 * @file itemcarrito.cpp
 * @brief Implementación de la clase itemcarrito, que gestiona los productos añadidos al carrito de compras.
 *
 * Este archivo define los métodos que permiten agregar, eliminar y mostrar
 * los productos dentro del carrito, así como acceder a los atributos del ítem.
 *
 */

#include "../include/itemcarrito.h"
#include <iostream>
using namespace std;

/**
 * @brief Constructor por defecto.
 *
 * Inicializa los atributos del ítem con valores vacíos o en cero.
 */
itemcarrito::itemcarrito() : pro(""), cant(0), pretot(0) {}

/**
 * @brief Constructor con parámetros.
 *
 * Inicializa un objeto `itemcarrito` con los valores indicados.
 *
 * @param _producto Nombre del producto.
 * @param _cant Cantidad de unidades del producto.
 * @param _pretot Precio total (precio unitario * cantidad).
 */
itemcarrito::itemcarrito(string _producto, int _cant, int _pretot)
    : pro(_producto), cant(_cant), pretot(_pretot) {}

/**
 * @brief Agrega productos al carrito de compras.
 *
 * Permite al usuario ingresar manualmente los nombres de los productos y sus cantidades.
 * Verifica si el producto existe en la lista heredada de `producto`, calcula el precio total
 * y lo añade al vector de ítems del carrito.
 *
 * @param carrito Referencia al vector de ítems donde se almacenan los productos seleccionados.
 * @note Requiere que los vectores `nombres` y `precios` heredados de `producto` estén inicializados.
 */
void itemcarrito::agregarAlCarrito(vector<itemcarrito> &carrito) {
    char opc = 's';
    while (opc == 's' || opc == 'S') {
        string pro;
        int cant, pre = 0, pretot;
        bool encontrado = false;

        cout << "Ingresa el producto a llevar: ";
        cin >> pro;
        cout << "Ingresa la cantidad: ";
        cin >> cant;

        for (int i = 0; i < nombres.size(); i++) {
            if (pro == nombres[i]) {
                pre = precios[i];
                encontrado = true;
                break;
            }
        }

        if (!encontrado) {
            cout << "Producto no encontrado.\n";
        } else {
            pretot = cant * pre;
            carrito.push_back(itemcarrito(pro, cant, pretot));
            cout << "Producto agregado exitosamente.\n";
        }

        cout << "¿Desea agregar otro producto? (s/n): ";
        cin >> opc;
    }
}

/**
 * @brief Elimina un producto del carrito.
 *
 * Solicita al usuario el nombre de un producto y, si lo encuentra en el carrito,
 * lo elimina del vector.
 *
 * @param carrito Referencia al vector de ítems del carrito.
 */
void itemcarrito::eliminarProducto(vector<itemcarrito> &carrito) {
    if (carrito.empty()) {
        cout << "El carrito está vacío.\n";
        return;
    }

    string nombreEliminar;
    cout << "Ingrese el nombre del producto que desea eliminar: ";
    cin >> nombreEliminar;

    bool eliminado = false;
    for (auto it = carrito.begin(); it != carrito.end(); ++it) {
        if (it->getProducto() == nombreEliminar) {
            carrito.erase(it);
            eliminado = true;
            cout << "Producto eliminado del carrito.\n";
            break;
        }
    }

    if (!eliminado)
        cout << "El producto no se encontró en el carrito.\n";
}

/**
 * @brief Muestra el contenido actual del carrito de compras.
 *
 * Recorre el vector de ítems e imprime los datos de cada producto: nombre, cantidad y total.
 * También muestra el total general de la compra.
 *
 * @param carrito Vector constante que contiene los ítems del carrito.
 */
void itemcarrito::mostrarCarrito(const vector<itemcarrito> &carrito) {
    cout << "\n--- CARRITO DE COMPRAS ---" << endl;
    if (carrito.empty()) {
        cout << "El carrito está vacío.\n";
        return;
    }

    int totalGeneral = 0;
    for (int i = 0; i < carrito.size(); i++) {
        cout << i + 1 << ". " << carrito[i].getProducto()
             << " - Cant: " << carrito[i].getCantidad()
             << " - Total: $" << carrito[i].getTotal() << endl;
        totalGeneral += carrito[i].getTotal();
    }

    cout << "---------------------------\n";
    cout << "TOTAL GENERAL: $" << totalGeneral << endl;
}

/**
 * @brief Obtiene el nombre del producto.
 * @return Nombre del producto (`string`).
 */
string itemcarrito::getProducto() const { return pro; }

/**
 * @brief Obtiene la cantidad del producto.
 * @return Cantidad (`int`).
 */
int itemcarrito::getCantidad() const { return cant; }

/**
 * @brief Obtiene el precio total del producto.
 * @return Precio total (`int`).
 */
int itemcarrito::getTotal() const { return pretot; }

