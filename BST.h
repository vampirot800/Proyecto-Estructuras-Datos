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
#include <queue>

using namespace std;

template <class T> class BST;
template <class T> class TreeNode;

template <class T> class TreeNode {
private:
  // Atributos
  T value;
  TreeNode *left, *right;
  TreeNode<T> *succesor();

public:
  // Constructores
  TreeNode(T);
  TreeNode(T, TreeNode<T> *, TreeNode<T> *);

  // Métodos
  void add(T);
  bool find(T);

  // Métodos auxiliares
  void preOrder(stringstream &) const;
  void inOrder(stringstream &) const;
  void postOrder(stringstream &) const;
  void lvlByLvl(TreeNode<T> *, stringstream &) const;

  // Clases amigas
  friend class BST<T>;
};

// Constructores

template <class T> TreeNode<T>::TreeNode(T val)
{
  value = val;
  left = NULL;
  right = NULL;
}

template <class T>
TreeNode<T>::TreeNode(T val, TreeNode<T> *le, TreeNode<T> *ri)
{
  value = val;
  left = le;
  right = ri;
}

// Métodos

template <class T> void TreeNode<T>::add(T val)
{
  TreeNode<T> * nuevo_nodo = new TreeNode<T>(val);

  if (val <= value)
  {
    if (left == NULL)
    {
      left = nuevo_nodo;
    } 
    else
    {
      left->add(val);
    }
  }
  else
  {
    if (right == NULL)
    {
      right = nuevo_nodo;
    }
    else
    {
      right->add(val);
    }
  }
}

//Algoritmo de busqueda de nodo
template <class T> bool TreeNode<T>::find(T val)
{
  if (val == value) 
  {
    return true;
  }

  if(val < value) 
  {
    if (left == NULL) // Con esto ya no se sigue 
    {
      return false;
    }
    return left->find(val); // Regresamos resultado de la busqueda
  } 
  else
  {
    if (right == NULL) // Con esto ya no se sigue
    {
      return false; 
    }
    return right->find(val); // Regresamos resultado de la busqueda
  }

}

// Métodos auxiliares

template <class T> void TreeNode<T>::preOrder(stringstream &aux) const
{
  // Nodo
  aux << value;

  // Izquierda
  if (left != 0)
  {
    aux << " ";
    left->preOrder(aux);
  }

  // Derecha
  if (right != 0)
  {
    aux << " ";
    right->preOrder(aux);
  }
}

template <class T> void TreeNode<T>::inOrder(stringstream &aux) const
{
  // Izquierda
  if (left != 0)
  {
    left->inOrder(aux);
    aux << " "; // Mover este espacio después del recorrido izquierdo
  }

  // Nodo
  aux << value;

  // Derecha
  if (right != 0)
  {
    aux << " "; // Mover este espacio antes del recorrido derecho
    right->inOrder(aux);
  }
}

template <class T> void TreeNode<T>::postOrder(stringstream &aux) const
{
  // Izquierda
  if (left != 0)
  {
    left->postOrder(aux);
    aux << " "; // Mover este espacio después del recorrido izquierdo
  }

  // Derecha
  if (right != 0)
  {
    right->postOrder(aux);
    aux << " "; // Mover este espacio después del recorrido derecho
  }

  // Nodo
  aux << value;
}

template <class T> void TreeNode<T>::lvlByLvl(TreeNode<T> *root, stringstream &aux) const
{
  queue<TreeNode<T>*> nodesQueue;
  nodesQueue.push(root);
  bool isFirst = true;

  while (!nodesQueue.empty())
  {
    TreeNode<T>* current = nodesQueue.front();
    nodesQueue.pop();

    if (isFirst)
    {
      isFirst = false;
      aux << current->value; // Agrega el valor del nodo actual
    }
    else
    {
      aux << " " << current->value; // Agrega el valor del nodo actual
    }

    if (current->left != nullptr)
      nodesQueue.push(current->left); // Agrega el nodo izquierdo a la cola

    if (current->right != nullptr)
      nodesQueue.push(current->right); // Agrega el nodo derecho a la cola
  }
}

// -----------------------------------------------

template <class T> class BST {
private:
  // Atributos
  TreeNode<T> *root;
public:
  // Constructor y destructor
  BST();
  ~BST();
  void destroyTree(TreeNode<T>*);

  // Métodos
  bool empty() const;
  void add(T);
  string visit();
  int height();
  string ancestors(T);
  int whatlevelamI(T);

  // Métodos auxiliares
  string preOrder();
  string inOrder();
  string postOrder();
  string lvlByLvl();
  int calculateHeight(TreeNode<T>*);
};

// Constructor y destructor

template <class T> BST<T>::BST() : root(0) {}

template <class T> BST<T>::~BST()
{
  // Llama a una función auxiliar para liberar la memoria de los nodos
  // y sus descendientes de manera recursiva.
  destroyTree(root);
}

// Función auxiliar para liberar la memoria de los nodos de manera recursiva.
template <class T> void BST<T>::destroyTree(TreeNode<T>* node)
{
  if (node != nullptr)
  {
    destroyTree(node->left);
    destroyTree(node->right);
    delete node;
  }
}

// Métodos

// Comprueba si la raiz está vacía
template <class T> bool BST<T>::empty() const
{
  if (root == NULL)
  {
    return true;
  }
  return false;
}

//Añadir nodo al arbol
template <class T> void BST<T>::add(T val)
{
  if (empty())
  {
    TreeNode<T> * nuevo_nodo = new TreeNode<T>(val);
    root = nuevo_nodo;
  }
  else
  {
    root->add(val);
  }
}

// Despliega los datos
template <class T> string BST<T>::visit()
{
  return preOrder() + "\n" + inOrder() + "\n" + postOrder() + "\n" + lvlByLvl();
}

// Devuelve la altura
template <class T> int BST<T>::height()
{
  return calculateHeight(root);
}

// Enlista los ancestros de un dato
template <class T> string BST<T>::ancestors(T val)
{
  stringstream ss;
  TreeNode<T>* current = root;
  bool found = false;
  bool isFirst = true;

  ss << "[";

  while (current != nullptr)
  {
    if (current->value == val)
    {
      found = true;
      break;
    }

    if (isFirst) // Es el primer valor ingresado
    {
      isFirst = false;
      ss << current->value; // Agrega el valor actual a la cadena
    }
    else
    {
      ss << " " << current->value; // Agrega el valor actual a la cadena
    }

    if (val < current->value)
      current = current->left; // Mueve hacia el subárbol izquierdo
    else
      current = current->right; // Mueve hacia el subárbol derecho
  }

  ss << "]";

  if (!found)
    return "[]"; // Valor no encontrado en el árbol

  return ss.str(); // Devuelve la cadena de ancestros
}

// Obtiene el valor del nivel del nodo actual
template <class T> int BST<T>::whatlevelamI(T val)
{
  int level = 1;
  TreeNode<T>* current = root;

  while (current != nullptr)
  {
    if (current->value == val)
      return level; // Devuelve el nivel del nodo si se encuentra

    level++;
    if (val < current->value)
      current = current->left; // Mueve hacia el subárbol izquierdo
    else
      current = current->right; // Mueve hacia el subárbol derecho
  }

  return -1; // Valor no encontrado en el árbol
}

// Métodos auxiliares

template <class T> string BST<T>::preOrder()
{
  std::stringstream aux;

  aux << "[";

  if (!empty())
  {
    root->preOrder(aux);
  }
  aux << "]";

  return aux.str();
}

template <class T> string BST<T>::inOrder()
{
  std::stringstream aux;

  aux << "[";
  if (!empty()) {
    root->inOrder(aux);
  }
  aux << "]";
  return aux.str();
}

template <class T> string BST<T>::postOrder()
{
  std::stringstream aux;

  aux << "[";
  if (!empty()) {
    root->postOrder(aux);
  }
  aux << "]";
  return aux.str();
}

template <class T> string BST<T>::lvlByLvl()
{
  std::stringstream aux;

  aux << "[";
  if (!empty()) {
    root->lvlByLvl(root, aux);
  }
  aux << "]";
  return aux.str();
}

// Función auxiliar para calcular la altura de un nodo
template <class T> int BST<T>::calculateHeight(TreeNode<T>* node)
{
  if (node == nullptr)
  {
    return 0;
  }

  int leftHeight = calculateHeight(node->left);
  int rightHeight = calculateHeight(node->right);

  return max(leftHeight, rightHeight) + 1;
}

#endif
