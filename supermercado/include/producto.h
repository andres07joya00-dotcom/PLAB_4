#ifndef PRODUCTO_H
#define PRODUCTO_H

#include <iostream>
#include <vector>
#include <string>
using namespace std;

class producto {
protected:
    vector<string> nombres;
    vector<int> precios;
    vector<int> cantidad;

public:
    producto();
    void mostrar();
    const vector<string>& getNombres() const;
    const vector<int>& getPrecios() const;
};

#endif

