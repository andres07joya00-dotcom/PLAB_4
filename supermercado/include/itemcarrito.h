#ifndef ITEMCARRITO_H
#define ITEMCARRITO_H

#include "producto.h"

class itemcarrito : public producto {
private:
    string pro;
    int cant;
    int pretot;

public:
    itemcarrito();
    itemcarrito(string _producto, int _cant, int _pretot);

    void agregarAlCarrito(vector<itemcarrito> &carrito);
    void eliminarProducto(vector<itemcarrito> &carrito);
    void mostrarCarrito(const vector<itemcarrito> &carrito);

    string getProducto() const;
    int getCantidad() const;
    int getTotal() const;
};

#endif
