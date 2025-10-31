/**
 * @file usuario.h
 * @brief Declaración de la clase Usuario, que representa un cliente con historial de compras.
 *
 * La clase `Usuario` almacena el nombre del cliente y un historial de compras,
 * donde cada compra se compone de un conjunto (vector) de objetos `itemcarrito`.
 * Permite registrar nuevas compras y visualizar el historial completo.
 *
 */

#ifndef USUARIO_H
#define USUARIO_H

#include "itemcarrito.h"
#include <string>
#include <vector>
using namespace std;

/**
 * @class Usuario
 * @brief Representa un usuario o cliente del sistema de compras.
 *
 * Cada usuario posee un nombre y un historial de compras.
 * Cada compra se almacena como un vector de objetos `itemcarrito`,
 * permitiendo registrar y mostrar las compras realizadas.
 */
class Usuario {
private:
    string nombre;  /**< Nombre del usuario o cliente. */
    vector<vector<itemcarrito> > historialCompras;  /**< Historial de compras del usuario. */

public:
    /**
     * @brief Constructor que inicializa el usuario con su nombre.
     * @param _nombre Nombre del usuario.
     */
    Usuario(string _nombre);

    /**
     * @brief Obtiene el nombre del usuario.
     * @return Nombre del usuario (`string`).
     */
    string getNombre() const;

    /**
     * @brief Guarda una nueva compra en el historial del usuario.
     *
     * Cada compra se almacena como un vector de objetos `itemcarrito`.
     *
     * @param carrito Carrito de compra que contiene los productos adquiridos.
     */
    void guardarCompra(const vector<itemcarrito> &carrito);

    /**
     * @brief Muestra el historial completo de compras del usuario.
     *
     * Recorre y muestra todas las compras realizadas por el usuario,
     * junto con los productos de cada una.
     */
    void mostrarHistorial();
};

#endif // USUARIO_H

