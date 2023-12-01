/*
Programacion de estructuras de datos y algoritmos fundamentales 

-Proyecto: Gestionador de Rocas y Minerales
-Ramiro Flores Villarreal
-A01710879

main.cpp
*/


#include <fstream>
#include <limits>
#include <iomanip>

#include <iostream>
#include <string>

#include "roca.h"
#include "BST.h"
#include "mergeSort.h"
#include "roca_base.h"
#include "minerales.h"

using namespace std;

void menu(){

  cout<< "\nMenu:\n";
  cout<< "\n**Presione la tecla del numero de la opcion que desee:**\n";
  cout<< "\n1:Consultar Lista de Minerales\n";
  cout<< "2:Agregar Mineral\n";
  cout<< "3:Quitar Mineral\n";
  cout<< "4:Ordenar Lista\n";
  cout<< "5:Guardar archivo CSV\n";
  cout<< "6:Salir\n";
}

int main() {
  string nombre;
  double dureza;
  string valor;
  int opcion = 0;
  
  Minerales gestionadorMinerales;
  
  gestionadorMinerales.importCSV("rocas.csv");

  cout << "----------------------------------------------------------\n";
  cout << "Bienvenido al Gestionador de Rocas y Minerales!\n";
  cout << "----------------------------------------------------------\n";
  cout << "Este programa es capaz de gestionar una lista de minerales";
  cout << "\ncon nombre, dureza y valor, haciendo uso de clases, un";
  cout << "\narbol de busqueda binaria, y un merge sort, entre otras";
  cout << "\nfunciones\n";
  cout << "----------------------------------------------------------\n";

// Ciclo para que el propgrama siga corriendo mientras no elija 6
  while (opcion < 5 && opcion > -1)
  {
    menu();
    cin >> opcion;


    switch (opcion) {

      case 1:
        gestionadorMinerales.displayRocas();
        break;
        break;

      case 2:
      // Agregar Mineral
        cout << "Ingrese el nombre: ";
        cin >> nombre;

        cout << "Ingrese la dureza: ";
        cin >> dureza;

        cout << "Ingrese el valor: ";
        cin >> valor;
        gestionadorMinerales.addRoca(nombre, dureza, valor);
        break;

      case 3:
      // Borrar lista
      gestionadorMinerales.removeAll();
      cout << "Lista de Rocas eliminada correctamente." << endl;
      break;

      case 4:
      // Ordenar Lista
      gestionadorMinerales.mergeSortRoca();
        break;

      case 5:
      // Guardar a archivo CSV
      gestionadorMinerales.saveCSV("rocas.h");
        break;

    }
  }
}