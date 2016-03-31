/*
 * Autor: Francisco Enrique Córdova González
 * Descripción: Esta es una librería que contiene
 * una estructura llamada caja2 que se utiliza
 * para la elaboración de la clase grafo.
*/
#pragma once
#include "nodo.hpp"
#include "prototipo.hpp"
template <typename _InputIter> struct nodo_aux {
  nodo<_InputIter> *_nodo;
  float acomulado;
  nodo_aux<_InputIter> *ant, *sig;
};
