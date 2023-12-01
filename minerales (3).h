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

using namespace std;

// Definicion de clase mineral con atributos y metodos
class Minerales {
private:
    BST<Roca *> rocasTree;
    bool AddedRocas;
    int contador;

public:
    Minerales();
    void importCSV(const string &archivo);
    void saveCSV(const string &archivo);
    void addRoca(string nombre, double dureza, string valor);
    void mergeSortRoca();
    void displayRocas() const;
    void removeAll(); 
};

Minerales::Minerales() {
    AddedRocas = false;
    contador = 0;
}
void Minerales::removeAll() {
    rocasTree.removeAll();
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

        if (getline(ss, nombre, ',') && getline(ss, valor, ',') && (ss >> dureza)) {
            // Crear el objeto Roca y agregarlo al BST
            Roca *nuevaRoca = nullptr;

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
    rocasTree.inorderA(rocasList);

    // Recorrer la lista y escribir cada roca en el archivo CSV
    for (const auto &roca : rocasList) {
        file << roca->to_string() << "\n";
    }

    file.close();
}

void Minerales::addRoca(string nombre, double dureza, string valor) {
    Roca *nuevaRoca = new RocaBase(nombre, dureza, valor);

    if (nuevaRoca != nullptr) {
        rocasTree.add(nuevaRoca);
        AddedRocas = true;
        contador++;
    } else {
        cerr << "Error al crear el objeto Roca" << endl;
    }
}

void Minerales::mergeSortRoca() {
    if (rocasTree.empty()) {
        cout << "No hay rocas para ordenar." << endl;
        return;
    }

   
    vector<Roca *> RocaList;
    rocasTree.inorderA(RocaList);

    MergeSort<Roca *> sort;
    sort.sort(RocaList);

    // Vuelve a construir el árbol con el vector ordenado
    rocasTree.removeAll();
    for (Roca *roca : RocaList) {
      rocasTree.add(roca);
    }
  }

void Minerales::displayRocas() const {
    if (rocasTree.empty()) {
        cout << "No hay Rocas para mostrar." << endl;
    } else {
        cout << "Lista de Rocas:" << endl;

        vector<Roca *> rocasList;
        rocasTree.inorderA(rocasList);

        for (const auto &roca : rocasList) {
            cout << roca->to_string() << endl;
        }
    }
}

#endif // MINERALES_H_
