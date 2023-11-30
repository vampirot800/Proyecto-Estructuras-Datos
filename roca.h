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

    string nombre;
    double dureza;
    string valor;

  public:
    //Constructor default
    Roca();
    //Constructor default
    Roca(const string& nombre,double dureza, string valor);

    //funcion to string
    virtual string to_string() = 0;

    string to_string() const {
      stringstream ss;
      ss << nombre << "," << dureza << "," << valor;
      return ss.str();
      }

    //Getters/Setters
    string getNombre() const;

    void setNombre(const string& nom);


    double getDureza() const;
    
    void setDureza(double& dur);

    
    double getValor() const;
    
    void setValor(string& val);
  
  
};

#endif