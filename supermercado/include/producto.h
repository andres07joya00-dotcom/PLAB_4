/**
 * @file producto.h
 * @brief Declaración de la clase producto, que gestiona la información base de los productos disponibles.
 *
 * La clase `producto` almacena listas (vectores) con los nombres, precios y cantidades
 * disponibles de los productos. Sirve como clase base para `itemcarrito`, desde la cual
 * se extienden las funcionalidades relacionadas con el carrito de compras.
 *
 * 
 */

#ifndef PRODUCTO_H
#define PRODUCTO_H

#include <iostream>
#include <vector>
#include <string>
using namespace std;

/**
 * @class producto
 * @brief Clase base que representa la información general de los productos.
 *
 * Contiene vectores con los nombres, precios y cantidades de productos.
 * Ofrece métodos para mostrar la información y acceder a los datos.
 */
class producto {
protected:
    vector<string> nombres;  /**< Lista de nombres de productos disponibles. */
    vector<int> precios;     /**< Lista de precios correspondientes a cada producto. */
    vector<int> cantidad;    /**< Lista de cantidades disponibles por producto. */

public:
    /**
     * @brief Constructor por defecto.
     *
     * Inicializa los vectores de nombres, precios y cantidades vacíos.
     */
    producto();

    /**
     * @brief Muestra la lista de productos disponibles.
     *
     * Imprime en consola los nombres, precios y cantidades almacenados en los vectores.
     */
    void mostrar();

    /**
     * @brief Obtiene el vector de nombres de productos.
     * @return Referencia constante al vector de nombres.
     */
    const vector<string>& getNombres() const;

    /**
     * @brief Obtiene el vector de precios de productos.
     * @return Referencia constante al vector de precios.
     */
    const vector<int>& getPrecios() const;
};

#endif // PRODUCTO_H
