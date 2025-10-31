#include "../include/usuario.h"

int main() {
    vector<Usuario> usuarios;
    producto lista;
    itemcarrito item;
    vector<itemcarrito> carrito;
    string nombreUsuario;
    int opcionUsuario = -1;
    char opcionMenu;

    cout << "SUPERMERCADO ECI PA\n";

    while (true) {
        cout << "\n1. Registrar nuevo usuario\n";
        cout << "2. Seleccionar usuario existente\n";
        cout << "3. Ver lista de productos\n";
        cout << "4. Salir\n";
        cout << "Elige una opcion: ";
        cin >> opcionMenu;

        if (opcionMenu == '1') {
            cout << "Ingrese el nombre del nuevo usuario: ";
            cin >> nombreUsuario;
            usuarios.push_back(Usuario(nombreUsuario));
            cout << "Usuario " << nombreUsuario << " registrado correctamente.\n";
        }

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
                    case '1': item.agregarAlCarrito(carrito); break;
                    case '2': item.mostrarCarrito(carrito); break;
                    case '3': item.eliminarProducto(carrito); break;
                    case '4':
                        if (carrito.empty())
                            cout << "No hay productos en el carrito.\n";
                        else {
                            user.guardarCompra(carrito);
                            carrito.clear();
                        }
                        break;
                    case '5': user.mostrarHistorial(); break;
                    case '6': lista.mostrar(); break;
                    case '7': cout << "Sesión cerrada.\n"; break;
                    default: cout << "Opción no válida.\n";
                }
            } while (opcionCompra != '7');
        }

        else if (opcionMenu == '3') {
            lista.mostrar();
        }

        else if (opcionMenu == '4') {
            cout << "Gracias.\n";
            break;
        }

        else {
            cout << "Opción no valida.\n";
        }
    }

    return 0;
}
