/*
Programacion de estructuras de datos y algoritmos fundamentales 

-Proyecto: Gestionador de Rocas y Minerales
-Ramiro Flores Villarreal
-A01710879

clase roca base hereda de roca
*/

#ifndef ROCA_BASE_H_
#define ROCA_BASE_H_

#include "roca.h"

class RocaBase : public Roca {
public:
    // Constructor
    RocaBase(const string &nombre, double dureza, const string &valor);

    // funciones pure virtual
    string to_string() override;

    int get_numRocas() const override;
};

// Constructor
RocaBase::RocaBase(const string &nombre, double dureza, const string &valor)
    : Roca(nombre, dureza, valor) {
    
}


string RocaBase::to_string() {
    stringstream ss;
    ss << getNombre() << "," << getDureza() << "," << getValor();
    return ss.str();
}

int RocaBase::get_numRocas() const{
    return numRocas;
}
#endif  // ROCA_BASE_H_
