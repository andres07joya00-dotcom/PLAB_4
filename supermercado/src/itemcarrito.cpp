#include "../include/itemcarrito.h"

itemcarrito::itemcarrito() : pro(""), cant(0), pretot(0) {}
itemcarrito::itemcarrito(string _producto, int _cant, int _pretot)
    : pro(_producto), cant(_cant), pretot(_pretot) {}

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

string itemcarrito::getProducto() const { return pro; }
int itemcarrito::getCantidad() const { return cant; }
int itemcarrito::getTotal() const { return pretot; }
