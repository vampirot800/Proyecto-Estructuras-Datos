/*
Programacion de estructuras de datos y algoritmos fundamentales 

-Proyecto: Gestionador de Rocas y Minerales
-Ramiro Flores Villarreal
-A01710879

mergeSort: Algoritmo de ordenamiento Merge
*/

#ifndef MERGESORT_H_
#define MERGESORT_H_

#include <vector>
#include <iostream>
#include <list>

using namespace std;

template <class T>
class MergeSort {
private:
    void copyArray(vector<T> &, vector<T> &, int, int);
    void mergeArray(vector<T> &, vector<T> &, int, int, int);
    void mergeSplit(vector<T> &, vector<T> &, int, int);

public:
    vector<T> sort(vector<T> &);
};

template <class T>
vector<T> MergeSort<T>::sort(vector<T> &v) {
    vector<T> tmp(v.size());
    mergeSplit(v, tmp, 0, v.size() - 1);
    return v;
}

template <class T>
void MergeSort<T>::mergeSplit(vector<T> &A, vector<T> &B, int low, int high) {
    if (high > low) {
        int mid = (low + high) / 2;
        mergeSplit(A, B, low, mid);
        mergeSplit(A, B, mid + 1, high);
        mergeArray(A, B, low, mid, high);
    }
}

template <class T>
void MergeSort<T>::mergeArray(vector<T> &A, vector<T> &B, int low, int mid, int high) {
    int pos_1a_parte = low;
    int fin_1a_parte = mid;
    int pos_2da_parte = mid + 1;
    int fin_2da_parte = high;

    for (int i = pos_1a_parte; i <= fin_2da_parte; i++) {
        if ((A[pos_1a_parte] < A[pos_2da_parte] && pos_1a_parte <= fin_1a_parte) ||
            pos_2da_parte > fin_2da_parte) {
            B[i] = A[pos_1a_parte];
            pos_1a_parte++;
        } else {
            B[i] = A[pos_2da_parte];
            pos_2da_parte++;
        }
    }

    copyArray(A, B, low, high);
}

template <class T>
void MergeSort<T>::copyArray(vector<T> &A, vector<T> &B, int low, int high) {
    for (int i = low; i <= high; i++) {
        A[i] = B[i];
    }
}

#endif
