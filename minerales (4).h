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
#include <vector>
#include <fstream>

#include "BST.h"
#include "roca.h"
#include "mergeSort.h"
#include "roca_base.h"
#include "leerCSV.h"

using namespace std;

// Definicion de clase mineral con atributos y metodos
class Minerales {
private:
    BST<Roca *> rocasTree;
    bool AddedRocas;
    int contador;

public:
    Minerales();
    vector<Roca*> leerCSV(const string&, char);
    void escribeCSV(const string &, const vector<vector<string>> &);
    void addRoca(string, double, string);;
    void displayRocas(); 
    // void infoArbol(vector<Roca> &rocas);
};

Minerales::Minerales() {
    AddedRocas = false;
    contador = 0;
}

vector<Roca*> Minerales::leerCSV(const string& filename, char separator = ',') {

  LeerCSV csv;
  vector<Roca*> rocas;

  vector<vector<string>> data = csv.leerCSV("./rocas.csv", ',');

  for (int i = 0; i < data.size(); i++) {
    rocas[i] = new RocaBase(data[i][0], stod(data[i][2]), data[i][2]);
  }

  cout << "Archivo CSV correctamente procesado" << endl;
  return rocas;
}


void Minerales::escribeCSV(const string &filename, const vector<vector<string>> &dataInput) {
  ofstream file(filename, ios::app); // Abrir en modo de añadir al final del archivo

  LeerCSV csv;

  // Si no se puede abrir el archivo, mostrar un mensaje de error
  if (!file.is_open()) {
    cout << "Error opening file" << endl;
    return;
  }

  // Escribe los nuevos datos al final del archivo
  for (auto row : dataInput) {
    for (auto word : row) {
      file << word << ",";
    }
    file << "\n";
  }

  file.close();
}


void Minerales::addRoca(string nombre, double dureza, string valor) {

  // Vector de datos
  vector<string> datos = {nombre, to_string(dureza), valor};

  // Objeto roca
  Roca* newRoca = new RocaBase(nombre, dureza, valor);

  // Añade al arbol
  rocasTree.add(newRoca);

  // Añade al archivo
  escribeCSV("./rocas.csv", {datos});
}

void Minerales::displayRocas() {
  LeerCSV csv;
  vector<vector<string>> data = csv.leerCSV("./rocas.csv", ',');

  for (int i = 0; i < data.size(); i++) {
    cout << data[i][0] << " - " << data[i][1] << " - " << data[i][2] << endl;
  }
}

/*
void Minerales::infoArbol(vector<Roca> &rocas)
{
  if (!rocasTree.empty())
  {
    // Utiliza el método inOrder para obtener las rocas ordenadas
    stringstream ss(rocasTree.inOrder());
    string nombre, dureza, valor;

    while (ss >> nombre >> dureza >> valor)
    {
      // Crea objetos Roca y añádelos al vector
      rocas.push_back(RocaBase(nombre, stoi(dureza), valor));
    }
  }
}
*/


#endif 