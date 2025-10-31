/**
 * @file itemcarrito.h
 * @brief Declaración de la clase itemcarrito, que representa un producto dentro del carrito de compras.
 *
 * Esta clase hereda de la clase `producto` y agrega información relacionada con la cantidad
 * de productos y el precio total correspondiente a esa cantidad. Además, provee métodos
 * para administrar un vector de ítems en el carrito, como agregar, eliminar y mostrar productos.
 *
 */

#ifndef ITEMCARRITO_H
#define ITEMCARRITO_H

#include "producto.h"
#include <vector>
#include <string>
using namespace std;

/**
 * @class itemcarrito
 * @brief Representa un producto añadido al carrito de compras.
 *
 * Hereda de la clase `producto` y añade atributos específicos del carrito,
 * como la cantidad de unidades y el precio total. También gestiona la
 * manipulación de una colección de ítems.
 */
class itemcarrito : public producto {
private:
    string pro;   /**< Nombre del producto en el carrito. */
    int cant;     /**< Cantidad de unidades del producto. */
    int pretot;   /**< Precio total del producto (precio unitario * cantidad). */

public:
    /**
     * @brief Constructor por defecto.
     *
     * Inicializa los atributos del producto del carrito con valores predeterminados.
     */
    itemcarrito();

    /**
     * @brief Constructor con parámetros.
     * @param _producto Nombre del producto.
     * @param _cant Cantidad del producto.
     * @param _pretot Precio total del producto.
     */
    itemcarrito(string _producto, int _cant, int _pretot);

    /**
     * @brief Agrega un nuevo producto al carrito.
     *
     * Inserta un nuevo objeto `itemcarrito` dentro del vector de productos.
     *
     * @param carrito Referencia al vector que almacena los ítems del carrito.
     */
    void agregarAlCarrito(vector<itemcarrito> &carrito);

    /**
     * @brief Elimina un producto del carrito.
     *
     * Busca y elimina del vector el producto que coincida con el nombre almacenado en `pro`.
     *
     * @param carrito Referencia al vector de ítems del carrito.
     */
    void eliminarProducto(vector<itemcarrito> &carrito);

    /**
     * @brief Muestra los productos del carrito.
     *
     * Imprime en consola la información de todos los productos contenidos en el vector.
     *
     * @param carrito Vector constante con los ítems del carrito.
     */
    void mostrarCarrito(const vector<itemcarrito> &carrito);

    /**
     * @brief Obtiene el nombre del producto.
     * @return Nombre del producto (`string`).
     */
    string getProducto() const;

    /**
     * @brief Obtiene la cantidad del producto.
     * @return Cantidad (`int`).
     */
    int getCantidad() const;

    /**
     * @brief Obtiene el precio total del producto.
     * @return Precio total (`int`).
     */
    int getTotal() const;
};

#endif // ITEMCARRITO_H
