/*
Programacion de estructuras de datos y algoritmos fundamentales 

-Proyecto: Gestionador de Rocas y Minerales
-Ramiro Flores Villarreal
-A01710879

main.cpp
*/
#ifndef LEERCSV_H_
#define LEERCSV_H_

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
#include "leerCSV.h"

using namespace std;

void menu(){

  cout<< "\nMenu:\n";
  cout<< "\n**Presione la tecla del numero de la opcion que desee:**\n";
  cout<< "\n1:Consultar Lista de Minerales\n";
  cout<< "2:Agregar Mineral\n";
  cout<< "3:Guardar Nuevo Archivo CSV\n";
  cout<< "4:Salir\n";
  /*
  cout<< "4:Ordenar Lista\n";
  cout<< "5:Guardar archivo CSV\n";
  cout<< "6:Salir\n";
  */
}


int main() {
  string nombre;
  double dureza;
  string valor;
  int opcion = 0;

  Minerales gestionadorMinerales;

  gestionadorMinerales.displayRocas();


  cout << "----------------------------------------------------------\n";
  cout << "Bienvenido al Gestionador de Rocas y Minerales!\n";
  cout << "----------------------------------------------------------\n";
  cout << "Este programa es capaz de gestionar una lista de minerales";
  cout << "\ncon nombre, dureza y valor, haciendo uso de clases, un";
  cout << "\narbol de busqueda binaria, y un merge sort, entre otras";
  cout << "\nfunciones\n";
  cout << "----------------------------------------------------------\n";

  // Ciclo para que el propgrama siga corriendo mientras no elija 6
  while (opcion < 4 && opcion > -1)
  {
    menu();

    cin >> opcion;


    switch (opcion) {
    //Mostrar lista de usuario
      case 1:
        cout << "Esta opcion mostrara la lista inicial de \n Minerales predeterminada" << endl;
        cout <<"Presiona enter para confirmar"<< endl;
        cin.ignore(); // Limpiar el búfer de entrada
        cin.get();

        gestionadorMinerales.displayRocas();
        break;
        break;

      case 2:
      // Agregar Mineral
        cout << "Ingrese el nombre: ";
        cin >> nombre;

        cout << "Ingrese la dureza(0-10): ";
        cin >> dureza;

        cout << "Ingrese el valor (Alto, Medio, Bajo): ";
        cin >> valor;
        gestionadorMinerales.addRoca(nombre, dureza, valor);
        break;

      case 3:
      {
          cout << "Ingrese el nombre del archivo CSV: ";
          string filename;
          cin >> filename;

          // Obtener la información del árbol de rocas
          vector<Roca> rocas;
          // gestionadorMinerales.infoArbol(rocas);

          // Leer información del archivo CSV existente
          string existingFilename;
          cout << "Ingrese el nombre del archivo CSV existente: ";
          cin >> existingFilename;

          LeerCSV csv;
          vector<vector<string>> existingData = csv.leerCSV(existingFilename, ',');

          // Crear un vector de datos y agregar la información del archivo existente
          vector<vector<string>> data;

          for (const auto &row : existingData)
          {
              vector<string> fila = {row[0], row[1], row[2]};
              data.push_back(fila);
          }

          // Escribir el archivo CSV
          gestionadorMinerales.escribeCSV(filename, data);
          cout << "Archivo CSV creado exitosamente.\n";
      }
      break;

      //Comentada por cambios de funcionamiento en el codigo
      /*case 4:
      //Borra la lista de Minerales del arbol
        gestionadorMinerales.removeAll();
        cout << "Lista de Rocas eliminada correctamente." << endl;
        break;
      default:
        break;*/

      //Comentada por complicaciones de codigo
      /*case 5: 
      // Ordenar Lista
      gestionadorMinerales.mergeSortRoca();
        break;
        */

    }
  }

}
#endif