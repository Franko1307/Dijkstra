/*
 * Autor: Francisco Enrique Córdova González
 * Descripción: Librería que simula una lista de nodos en c++
*/
#pragma once
#include "lista_arco.hpp"
#include "nodo.hpp"
#include "prototipo.hpp"
template <typename T> class lista_nodo {
  DONDE donde;
  nodo<T> *principio,*anterior,*agregado;

public:
  lista_nodo() : principio(NULL), anterior(NULL), agregado(NULL),donde(INICIO){}
  ~lista_nodo();
  bool buscar(T);
  void agregar(T);
  void borrar(T);
  void pintar();
  nodo<T> *obtener_agregado(){return agregado;}
};
template <typename T> lista_nodo<T>::~lista_nodo() {
  nodo<T> *aux;
  while (principio) {
    aux = principio;
    principio = aux->sig;
    delete aux->saliente;
    delete aux;
  }
}
template <typename T> bool lista_nodo<T>::buscar(T id) {
  if (!principio) {
    donde = INICIO;
    return false;
  }
  nodo<T> *iterador = principio;
  while (iterador) {
    if (iterador->id_nodo < id) {
      anterior = iterador;
      iterador = anterior->sig;
    } else if (iterador->id_nodo == id) {
      agregado = iterador;
      return true;
    } else {
      if (iterador != principio) donde = MIFA;
      else donde = INICIO;
      return false;
    }
  }
  donde = MIFA;
  return false;
}
template <typename T> void lista_nodo<T>::agregar(T id) {
  if (buscar(id)) return;
  nodo<T> *_nodo = new nodo<T>;
  _nodo->id_nodo = id;
  _nodo->bandera = 0;
  _nodo->ruta_corta = 0;
  _nodo->ant = NULL;
  _nodo->saliente = new lista_arco<T>;
  if (donde == MIFA) {
    _nodo->sig = anterior->sig;
    anterior->sig = _nodo;
  } else {
    _nodo->sig = principio;
    principio = _nodo;
  }
  agregado = _nodo;
}
template <typename T> void lista_nodo<T>::pintar() {
  nodo<T> *p = principio;
  while (p) {
    std::cout << "Nodo: " << p->id_nodo << std::endl;
    std::cout << "Salientes: ";
    p->saliente->pintar();
    std::cout << std::endl;
    p = p->sig;
  }
}
