/**
 * @file main.cpp
 * @brief Programa principal del sistema de supermercado ECI PA.
 *
 * Este archivo implementa la lógica general del sistema, permitiendo:
 * - Registrar y gestionar múltiples usuarios.
 * - Visualizar la lista de productos disponibles.
 * - Agregar, eliminar y mostrar productos en el carrito de compras.
 * - Guardar y visualizar el historial de compras de cada usuario.
 *
 * Combina las clases `producto`, `itemcarrito` y `Usuario` para crear
 * una simulación sencilla de un sistema de ventas en consola.
 *
 */

#include "../include/usuario.h"
#include <iostream>
using namespace std;

/**
 * @brief Función principal del programa.
 *
 * Controla el menú general de la aplicación y las operaciones principales:
 * registro de usuarios, compras, historial y visualización de productos.
 *
 * @return 0 al finalizar la ejecución correctamente.
 */
int main() {
    vector<Usuario> usuarios;          ///< Lista de usuarios registrados.
    producto lista;                    ///< Catálogo de productos disponibles.
    itemcarrito item;                  ///< Objeto auxiliar para manipular el carrito.
    vector<itemcarrito> carrito;       ///< Carrito de compras temporal del usuario.
    string nombreUsuario;              ///< Nombre del usuario actual.
    int opcionUsuario = -1;            ///< Índice del usuario seleccionado.
    char opcionMenu;                   ///< Opción elegida en el menú principal.

    cout << "SUPERMERCADO ECI PA\n";

    while (true) {
        cout << "\n1. Registrar nuevo usuario\n";
        cout << "2. Seleccionar usuario existente\n";
        cout << "3. Ver lista de productos\n";
        cout << "4. Salir\n";
        cout << "Elige una opción: ";
        cin >> opcionMenu;

        // --- Registrar nuevo usuario ---
        if (opcionMenu == '1') {
            cout << "Ingrese el nombre del nuevo usuario: ";
            cin >> nombreUsuario;
            usuarios.push_back(Usuario(nombreUsuario));
            cout << "Usuario " << nombreUsuario << " registrado correctamente.\n";
        }

        // --- Seleccionar usuario existente ---
        else if (opcionMenu == '2') {
            if (usuarios.empty()) {
                cout << "No hay usuarios registrados.\n";
                continue;
            }

            cout << "\nUsuarios disponibles:\n";
            for (int i = 0; i < usuarios.size(); i++)
                cout << i + 1 << ". " << usuarios[i].getNombre() << endl;

            cout << "Seleccione un usuario por número: ";
            cin >> opcionUsuario;

            if (opcionUsuario < 1 || opcionUsuario > usuarios.size()) {
                cout << "Opción inválida.\n";
                continue;
            }

            Usuario &user = usuarios[opcionUsuario - 1];
            cout << "\nBienvenido, " << user.getNombre() << ".\n";
            carrito.clear();

            char opcionCompra;
            do {
                cout << "\n1. Agregar productos al carrito\n";
                cout << "2. Mostrar carrito\n";
                cout << "3. Eliminar producto del carrito\n";
                cout << "4. Finalizar compra y guardar\n";
                cout << "5. Ver historial de compras\n";
                cout << "6. Ver lista de productos\n";
                cout << "7. Cerrar sesión\n";
                cout << "Elige una opción: ";
                cin >> opcionCompra;

                switch (opcionCompra) {
                    case '1':
                        item.agregarAlCarrito(carrito);
                        break;
                    case '2':
                        item.mostrarCarrito(carrito);
                        break;
                    case '3':
                        item.eliminarProducto(carrito);
                        break;
                    case '4':
                        if (carrito.empty())
                            cout << "No hay productos en el carrito.\n";
                        else {
                            user.guardarCompra(carrito);
                            carrito.clear();
                        }
                        break;
                    case '5':
                        user.mostrarHistorial();
                        break;
                    case '6':
                        lista.mostrar();
                        break;
                    case '7':
                        cout << "Sesión cerrada.\n";
                        break;
                    default:
                        cout << "Opción no válida.\n";
                }
            } while (opcionCompra != '7');
        }

        // --- Mostrar lista de productos ---
        else if (opcionMenu == '3') {
            lista.mostrar();
        }

        // --- Salir del programa ---
        else if (opcionMenu == '4') {
            cout << "Gracias.\n";
            break;
        }

        else {
            cout << "Opción no válida.\n";
        }
    }

    return 0;
}
