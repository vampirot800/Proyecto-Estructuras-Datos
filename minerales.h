/*
Programacion de estructuras de datos y algoritmos fundamentales 

-Proyecto: Gestionador de Rocas y Minerales
-Ramiro Flores Villarreal
-A01710879

minerales.h: clase mineral
*/

#ifndef MINERALES_H_
#define MINERALES_H_

#include <fstream>
#include <iomanip>
#include <iostream>
#include <sstream>
#include <string>
#include <fstream>
#include <vector>

#include "roca_base.h"
#include "BST.h"
#include "roca.h"

using namespace std;

//definicion de clase mineral con atributos y metodos
class Minerales{
private:

BST<Roca *> rocasTree; 
bool AddedRocas;
int contador;


public:

Minerales();

void importCSV(const string &archivo);
void saveCSV(const string &archivo);
//void addRoca(string nombre, int dureza, string valor);
void mergeSortRoca(string nombre, int dureza, string valor);
};

Minerales::Minerales() {
  AddedRocas = false;
  contador = 0;
}

void Minerales::importCSV(const string &archivo) {
  ifstream file(archivo);

  if (!file.is_open()) {
    cerr << "Error al cargar el archivo " << archivo << endl;
    return;
  }

  string primeraLinea;
  getline(file, primeraLinea);

  string linea;
  while (getline(file, linea)) {
    if (linea.empty()) {
      continue;
    }

    istringstream ss(linea);
    string nombre, valor;
    double dureza;

    // Verificar si la línea contiene al menos 3 campos
    if (getline(ss, nombre, ',') && getline(ss, valor, ',') && (ss >> dureza)) {
      // Crear el objeto Roca y agregarlo al BST
      Roca *nuevaRoca = nullptr;

      // Puedes utilizar algún mecanismo para decidir qué tipo de roca crear,
      // por ejemplo, aquí estoy creando instancias de una clase ficticia llamada RocaBase
      // pero deberías ajustarlo según la jerarquía real de tus clases derivadas de Roca.
      nuevaRoca = new RocaBase(nombre, dureza, valor);

      if (nuevaRoca != nullptr) {
        rocasTree.add(nuevaRoca);
      } else {
        cerr << "Error al crear el objeto Roca" << endl;
      }
    } else {
      // Manejar el error de formato de línea incorrecto
      cerr << "Error de formato en la línea: " << linea << endl;
    }
  }

  file.close();
}

  
  void Minerales::saveCSV(const string &archivo) {
        ofstream file(archivo, ios::trunc);
  
        if (!file.is_open()) {
            cerr << "Error al abrir archivo " << archivo << endl;
            return;
        }

      // Escribir la primera línea (encabezados)
      file << "Nombre,Dureza,Valor\n";

      // Obtener la lista ordenada de rocas
      vector<Roca *> rocasList;
      rocasTree.inorderToList(rocasList);

      // Recorrer la lista y escribir cada roca en el archivo CSV
      for (const auto &roca : rocasList) {
          file << roca->to_string() << "\n";
      }

      file.close();
  }

  void Minerales::mergeSortRoca(string nombre, int dureza, string valor){
  
  }

#endif