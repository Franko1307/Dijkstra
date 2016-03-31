/*
 * Autor: Francisco Enrique Córdova González
 * Descripción: Esta es una librería que contiene
 * una estructura llamada caja1 que se utiliza
 * para la elaboración de la clase grafo.
*/

#pragma once
#include "nodo.hpp"
template <typename _InputIter> struct arco{
  _InputIter id_nodo;
  nodo<_InputIter> *dir_nodo;
  float long_nodo;
  arco<_InputIter> *sig;
};
