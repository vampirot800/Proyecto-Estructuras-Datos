#ifndef ROCA_BASE_H_
#define ROCA_BASE_H_

#include "roca.h"

class RocaBase : public Roca {
public:
    // Constructor
    RocaBase(const string &nombre, double dureza, const string &valor);

    // Implement the pure virtual function
    string to_string() override;
};

// Constructor implementation
RocaBase::RocaBase(const string &nombre, double dureza, const string &valor)
    : Roca(nombre, dureza, valor) {
    // Any additional initialization if needed
}

// Implement the pure virtual function
string RocaBase::to_string() {
    stringstream ss;
    ss << getNombre() << "," << getDureza() << "," << getValor();
    return ss.str();
}

#endif  // ROCA_BASE_H_
