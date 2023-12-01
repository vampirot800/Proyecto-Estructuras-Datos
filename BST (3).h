/*
Programacion de estructuras de datos y algoritmos fundamentales 

-Proyecto: Gestionador de Rocas y Minerales
-Ramiro Flores Villarreal
-A01710879

BST: Arbol de Busqueda Binaria
*/

#ifndef BST_H_
#define BST_H_

#include <iostream>
#include <sstream>
#include <string>
#include <vector>

using namespace std;

template <class T> class BST;

// Clase Nodo de Árbol
template <class T> class TreeNode {
private:

  TreeNode<T> *root;
  void inorderToList(vector<T>& result, TreeNode<T>* current) const;

    T value;
    TreeNode *left, *right;

    // Función privada para encontrar el sucesor de un nodo
    TreeNode<T> *successor();

public:
    // Constructores
    TreeNode(T);
    TreeNode(T, TreeNode<T> *, TreeNode<T> *);

    void add(T);
    bool find(T);
    void remove(T);
    void removeChilds();
    void inorder(stringstream &) const;

    friend class BST<T>;
};

// Constructor de Nodo de Árbol con nulos
template <class T>
TreeNode<T>::TreeNode(T val)
{
    value = val;
    left = nullptr;
    right = nullptr;
}

// Constructor de Nodos de Árbol con izquierdo y derecho
template <class T>
TreeNode<T>::TreeNode(T val, TreeNode<T> *le, TreeNode<T> *ri)
{
    value = val;
    left = le;
    right = ri;
}

// Función Agregar
template <class T>
void TreeNode<T>::add(T val)
{
    if (val->get_numRocas() < value->get_numRocas())
   {
      if (left == NULL) {
        TreeNode<T> *new_node = new TreeNode<T>(val);
        left = new_node;
      } else {
        left->add(val);
      }
      } else {
        if (right == NULL) {
          TreeNode<T> *new_node = new TreeNode<T>(val);
          right = new_node;
      } else {
          right->add(val);
      }
    }
}

template <class T>
bool TreeNode<T>::find(T val) {
    if (val == value) {
        return true;
    }
    if (val < value) {
        if (left == NULL) {
            return false;
        }
        return left->find(val);
    } else {
        if (right == NULL) {
            return false;
        }
        return right->find(val);
    }
}

// Función pública para eliminar un nodo del árbol
template <class T> void TreeNode<T>::remove(T val) {
  if (val == value) {
    if (left == nullptr && right == nullptr) {
      delete this;
    } else if (left != nullptr && right == nullptr) {
      TreeNode<T> *temp = left;
      value = temp->value;
      left = temp->left;
      right = temp->right;
      temp->left = nullptr;
      temp->right = nullptr;
      delete temp;
    } else if (left == nullptr && right != nullptr) {
      TreeNode<T> *temp = right;
      value = temp->value;
      left = temp->left;
      right = temp->right;
      temp->left = nullptr;
      temp->right = nullptr;
      delete temp;
    } else {
      TreeNode<T> *successor = left->successor();
      value = successor->value;
      left->remove(successor->value);
    }
  } else if (val < value) {
    if (left != nullptr) {
      left->remove(val);
    }
  } else {
    if (right != nullptr) {
      right->remove(val);
    }
  }
}

// Función  para eliminar un nodo y ajustar el árbol
template <class T> void TreeNode<T>::removeChilds() {
  if (left != nullptr) {
    left->removeChilds();
    delete left;
    left = nullptr;
  }
  if (right != nullptr) {
    right->removeChilds();
    delete right;
    right = nullptr;
  }
}

// Función pública para recorrer el árbol en orden y guardar los valores en un stringstream
template <class T>
void TreeNode<T>::inorder(stringstream &ss) const
{
    if (left != nullptr)
    {
        left->inorder(ss);
    }
    ss << value << " ";
    if (right != nullptr)
    {
        right->inorder(ss);
    }
}

// Clase BST
template <class T>
class BST
{
private:
    TreeNode<T> *root;

public:
    // Constructor
    BST() : root(nullptr) {}

    //Destructor
    ~BST() { removeAll();}

// Funciones públicas

    //void inorderToList(vector<T>& result) const;


    void add(T val)
    {
        if (root == nullptr)
        {
            root = new TreeNode<T>(val);
        }
        else
        {
            root->add(val);
        }
    }

    bool find(T val) const
    {
        if (root == nullptr)
        {
            return false;
        }
        return root->find(val);
    }
    bool empty() const {
        return (root == nullptr);
    }

    void remove(T val)
    {
        if (root != nullptr)
        {
            if (root->value->getNombre() == val->getNombre())
            {
                root->removeChilds();
            }
            else
            {
                root->remove(val);
            }
        }
    }

    string inorder() const
    {
        stringstream ss;
        if (root != nullptr)
        {
            root->inorder(ss);
        }
        return ss.str();
    }


    void removeAll() {
      if (!empty()) {
          root->removeChilds();
          delete root;
          root = nullptr;
      }
}
    void inorderA(vector<T>& result, TreeNode<T>* current) const {
      if (current != nullptr) {
          inorderA(result, current->left);  


          result.push_back(current->value);

          inorderA(result, current->right);  
      }
  }
    void inorderA(vector<T>& result) const {
inorderA(result, root);
}

};

#endif