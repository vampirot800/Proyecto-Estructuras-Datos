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
#include "minerales.h"
#include "BST.h"
#include "mergeSort.h"
#include "roca_base.h"

using namespace std;


void menu(){

  cout<< "\nMenu:\n";
  cout<< "\n**Presione la tecla del numero de la opcion que desee:**\n";
  cout<< "\n1:Consultar Lista de Minerales\n";
  cout<< "2:Agregar Mineral\n";
  cout<< "3:Quitar Mineral\n";
  cout<< "4:Ordenar Lista\n";
  cout<< "5:Exportar archivo CSV\n";
  cout<< "6:Salir\n";
}

int main() {
  
  Minerales gestionadorMinerales;
  int opcion = 0;
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
      // Consultar Lista de Minerales
        break;
    
      case 2:
      // Agregar Mineral

        break;
      
      case 3:
      // Quitar Mineral

        break;
      
      case 4:
      // Ordenar Lista

        break;
      
      case 5:
      // Exportar archivo CSV

        break;
      
    }
  }
}