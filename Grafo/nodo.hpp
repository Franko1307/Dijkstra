/*
 * Autor: Francisco Enrique Córdova González
 * Descripción: Esta es una librería que contiene
 * una estructura llamada caja2 que se utiliza
 * para la elaboración de la clase grafo.
*/
#pragma once
#include "prototipo.hpp"
#include "nodo_aux.hpp"
template <typename _InputIter> struct nodo{
  _InputIter id_nodo;
  int bandera; //0 al iniciar, 1 si es tocado por el algoritmo y 2 si es definitivo
  float ruta_corta;
  nodo<_InputIter> *ant;
  nodo<_InputIter> *sig;
  nodo_aux<_InputIter> *lugar;
  lista_arco<_InputIter> *saliente;

};
