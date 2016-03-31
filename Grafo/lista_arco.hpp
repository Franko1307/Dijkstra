/*
 * Autor: Francisco Enrique Córdova González
 * Descripción: Librería que simula una lista de arcos en c++
*/
#pragma once
#include <iostream>
#include "arco.hpp"
#include "prototipo.hpp"

template <typename T> class lista_arco {
private:
  DONDE donde;
  arco<T> *principio;
  arco<T> *anterior;
  arco<T> *agregado;
  arco<T> *lugar;
  bool buscar(T);
public:
  lista_arco(): donde(INICIO),principio(NULL),anterior(NULL),agregado(NULL),lugar(NULL){}
  ~lista_arco();
  void agregar(T);
  void pintar();
  arco<T> *obtener_agregado(){return agregado;}
  arco<T> *primer_arco(){return principio;}
  arco<T> *Lugar() {return lugar;}
  arco<T> *recorrer();
  void iniciar_recorrido() {lugar = principio;}

};
template <typename T> lista_arco<T>::~lista_arco() {
  arco<T> *aux;
  while (principio) {
    aux = principio;
    principio = aux->sig;
    delete aux;
  }
}
template <typename T> arco<T> *lista_arco<T>::recorrer() {
  arco<T> *aux = lugar;
  if (aux) lugar = lugar->sig;
  return aux;
}
template <typename T> bool lista_arco<T>::buscar(T id) {
  if (!principio) {
    donde = INICIO;
    return false;
  }
  arco<T> *iterador = principio;
  while (iterador) {
    if (iterador->id_nodo < id) {
      anterior = iterador;
      iterador = anterior->sig;
    } else if (iterador->id_nodo == id){
      agregado = iterador;
      return true;
    }
    else {
      if (iterador != principio) donde = MIFA;
      else donde = INICIO;
      return false;
    }
  }
  donde = MIFA;
  return false;
}
template <typename T> void lista_arco<T>::agregar(T id) {
  if (buscar(id)) return;
  arco<T> *iterador = new arco<T>;
  iterador->id_nodo = id;
  if (donde == MIFA) {
    iterador->sig = anterior->sig;
    anterior->sig = iterador;
  } else {
    iterador->sig = principio;
    principio = iterador;
  }
  agregado = iterador;
}
template <typename T> void lista_arco<T>::pintar() {
  std::cout << "[ ";
  arco<T> *iterador = principio;
  while (iterador) {
    std::cout << iterador->id_nodo << "{" << iterador->long_nodo << "},";
    iterador = iterador->sig;
  }
  std::cout << "\b ]" << std::endl;
}
