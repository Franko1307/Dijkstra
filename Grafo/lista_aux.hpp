/*
 * Autor: Francisco Enrique Córdova González
 * Descripción: Librería que simula una lista de arcos en c++
*/
#pragma once
#include <iostream>
#include "nodo.hpp"
#include "prototipo.hpp"
template <typename T> class lista_aux {
private:
  DONDE donde;
  nodo_aux<T> *principio;
  nodo_aux<T> *anterior;
  nodo_aux<T> *agregado;
  nodo_aux<T> *final;
  bool buscar(float);
public:
  lista_aux(): donde(VACIO),principio(NULL),anterior(NULL),agregado(NULL){}
  ~lista_aux();
  void agregar(nodo<T>*,float);
  void pintar();
  nodo_aux<T> *obtener_agregado(){return agregado;}
  void ajustar(nodo_aux<T>*, float);
  nodo<T> *sacar_primero();
};
template <typename T> lista_aux<T>::~lista_aux() {
  nodo_aux<T> *aux;
  while (principio) {
    aux = principio;
    principio = aux->sig;
    delete aux;
  }
}
template <typename T> bool lista_aux<T>::buscar(float var) {
  if (!principio) {
    donde = VACIO;
    agregado = NULL;
    anterior = NULL;
    return false;
  }
  nodo_aux<T> *iterador = principio;
  while (iterador) {
    if (iterador->acomulado < var) {
      anterior = iterador;
      iterador = iterador->sig;
    } else if (iterador->acomulado == var){
      if (principio == iterador) donde = INICIO;
      else donde = MITAD;
      agregado = iterador;
      return true;
    } else {
      if (principio == iterador) donde = INICIO;
      else donde = MITAD;
      return false;
    }
  }
  donde = FINAL;
  return false;
}
template <typename T> void lista_aux<T>::agregar(nodo<T>* _nodo, float l) {
  if (buscar(l));
  nodo_aux<T> *nuevo = new nodo_aux<T>;
  nuevo->_nodo = _nodo;
  nuevo->acomulado = l;
  if (donde == MITAD) {
    nuevo->sig = anterior->sig;
    nuevo->ant = anterior;
    anterior->sig = nuevo;
    nuevo->sig->ant = nuevo;
  } else if (donde == FINAL) {
    nuevo->sig = NULL;
    nuevo->ant = final;
    final->sig = nuevo;
    final = nuevo;
  } else if (donde == INICIO){
    nuevo->sig = principio;
    nuevo->ant = NULL;
    principio->ant = nuevo;
    principio = nuevo;
  } else if (donde == VACIO) {
    nuevo->sig = NULL;
    nuevo->ant = NULL;
    principio = nuevo;
    final = nuevo;
  }
  agregado = nuevo;
}
template <typename T> void lista_aux<T>::ajustar(nodo_aux<T> *_nodo , float l) {
  _nodo->acomulado = l;
  if (_nodo->ant == NULL) return;
  if (_nodo->ant->acomulado <= l) return;

  nodo_aux<T> *nodo_menor = _nodo->ant;

  while (nodo_menor) {
    if (nodo_menor->acomulado > l) nodo_menor = nodo_menor->ant;
    else break;
  }
  if (_nodo->sig) {
    _nodo->ant->sig = _nodo->sig;
    _nodo->sig->ant = _nodo->ant;
  } else {
    _nodo->ant->sig = _nodo->sig;
  }
  if (nodo_menor) {
    _nodo->sig = nodo_menor->sig;
    _nodo->ant = nodo_menor;
    nodo_menor->sig = _nodo;
    _nodo->sig->ant = _nodo;
  } else {
    _nodo->sig = principio;
    _nodo->ant = NULL;
    principio->ant = _nodo;
    principio = principio->sig;
  }
}
template <typename T> nodo<T> *lista_aux<T>::sacar_primero() {
  if (!principio) return NULL;
  nodo_aux<T> *aux = principio;

  principio = principio->sig;

  if (principio) principio->ant = NULL;

  nodo<T> *aux_2 = aux->_nodo;

  aux_2->lugar = NULL;
  delete aux;
  return aux_2;
}
template <typename T> void lista_aux<T>::pintar() {
  nodo_aux<T> *iterador = principio;
  std::cout << "[  ";
  while (iterador) {
    std::cout << iterador->_nodo->id_nodo << "->";
    iterador = iterador->sig;
  }
  std::cout << "\b\b  ]" << std::endl;
}
