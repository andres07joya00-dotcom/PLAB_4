#ifndef USUARIO_H
#define USUARIO_H

#include "itemcarrito.h"

class Usuario {
private:
    string nombre;
    vector<vector<itemcarrito> > historialCompras;

public:
    Usuario(string _nombre);
    string getNombre() const;
    void guardarCompra(const vector<itemcarrito> &carrito);
    void mostrarHistorial();
};

#endif

