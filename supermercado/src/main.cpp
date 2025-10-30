#include "usuario.h"

int main() {
    Usuario user("Andrés");
    itemcarrito item;
    vector<itemcarrito> carrito;
    char opcion;

    cout << "Bienvenido al supermercado virtual, Andrés.\n";
    item.mostrar();

    do {
        cout << "\n1. Agregar productos al carrito\n";
        cout << "2. Mostrar carrito\n";
        cout << "3. Eliminar producto del carrito\n";
        cout << "4. Finalizar compra y guardar en historial\n";
        cout << "5. Ver historial de compras\n";
        cout << "6. Salir\n";
        cout << "Elige una opción: ";
        cin >> opcion;

        switch (opcion) {
            case '1':
                item.carrito(carrito);
                break;
            case '2':
                item.mostrarCarrito(carrito);
                break;
            case '3':
                item.eliminarProducto(carrito);
                break;
            case '4':
                if (carrito.empty()) {
                    cout << "No hay productos en el carrito.\n";
                } else {
                    user.guardarCompra(carrito);
                    carrito.clear();
                }
                break;
            case '5':
                user.mostrarHistorial();
                break;
            case '6':
                cout << "Gracias por su compra. ¡Vuelva pronto!\n";
                break;
            default:
                cout << "Opción no válida.\n";
        }

    } while (opcion != '6');

    return 0;
}
