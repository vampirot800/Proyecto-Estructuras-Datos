/*
Programacion de estructuras de datos y algoritmos fundamentales 

-Proyecto: Gestionador de Rocas y Minerales
-Ramiro Flores Villarreal
-A01710879

clase leerCSV.h
*/

#ifndef LEERCSV_H
#define LEERCSV_H

#include <iostream>
#include <fstream>
#include <vector>
#include <string>

using namespace std;

class LeerCSV {
public:
    LeerCSV(){};
    vector<vector<string>> leerCSV(const string, char);
};

vector<vector<string>> LeerCSV::leerCSV(const string filename, char separator = ',') {

  vector<vector<string>> data;
  ifstream file(filename);

  if (!file.is_open())
  {
    cout << "Error opening file" << endl;
    return data;
  }

  string line;
  while (getline(file, line))
  {

    vector<string> row;
    string word = "";

    for (auto x : line)
    {
      if (x == separator)
      {
        row.push_back(word);
        word = "";
      }
      else
      {
        word = word + x;
      }
    }

    // Push the last word
    row.push_back(word);

    // Push the row
    data.push_back(row);
  }

  // Close the file
  file.close();

  // Return the data
  return data;
}

#endif 