/*
Programacion de estructuras de datos y algoritmos fundamentales 

-Proyecto: Gestionador de Rocas y Minerales
-Ramiro Flores Villarreal
-A01710879

roca.h: clase roca
*/

#ifndef ROCA_H_
#define ROCA_H_


#include <sstream>
#include <string>


using namespace std;

//definicion de clase mineral con atributos y metodos
class Roca{



  protected:

    int numRocas;
    string nombre;
    double dureza;
    string valor;


  public:
    //Constructor default
    Roca();
    //Constructor 
    Roca(const string &nombre, double dureza, const string &valor) {}
    

    //funcion to string
    virtual string to_string() = 0;

    virtual int get_numRocas() const = 0;

    string to_string() const {
      stringstream ss;
      ss << nombre << "," << dureza << "," << valor;
      return ss.str();
      }

    void set_numRocas(int rocas);
      bool operator<(const Roca& other) const {
        return this->get_numRocas() < other.get_numRocas();
      }

      bool operator>(const Roca& other) const {
        return this->get_numRocas() > other.get_numRocas();
      }

      bool operator==(const Roca& other) const {
        return this->get_numRocas() == other.get_numRocas();
      }

    
    
    string getNombre() const {
        // Implementación de la función getNombre
        return nombre;
    }
    
    double getDureza() const {
        // Implementación de la función getDureza
        return dureza;
    }
    
    string getValor() const {
        // Implementación de la función getValor
        return valor;
    }

};
    void Roca::set_numRocas(int rocas) {
      numRocas = rocas;
    }

#endif
