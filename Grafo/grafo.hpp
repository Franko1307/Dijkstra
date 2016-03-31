/*
 * Autor: Francisco Enrique Córdova González
 * Descripción: Librería que simula una lista de nodos en c++
*/
#pragma once
#include "lista_nodo.hpp"
#include "lista_aux.hpp"
template <typename T> class grafica {
  lista_nodo<T> *A;
  lista_aux<T> *B;
public:
  grafica();
  ~grafica();
  bool dijkstra(T,T);
  void ruta_corta(){B->pintar();};
  void agregar(T,T,float);
  void pintar() {A->pintar();}
};
template <typename T> grafica<T>::grafica() {
  A = new lista_nodo<T>;
  B = new lista_aux<T>;
}
template <typename T> grafica<T>::~grafica() {
  delete A;
  delete B;
}
template <typename T> void grafica<T>::agregar(T nodo_1, T nodo_2, float l) {
  arco<T> *p;
  nodo<T> *q;

  A->agregar(nodo_1);
  q = A->obtener_agregado();
  q->saliente->agregar(nodo_2);
  p = q->saliente->obtener_agregado();
  A->agregar(nodo_2);
  q = A->obtener_agregado();
  p->dir_nodo = q;
  p->long_nodo = l;
}
template <typename T>bool  grafica<T>::dijkstra(T a, T b) {
  if (!A->buscar(b) || !A->buscar(a)) return false;
  nodo<T> *iterador = A->obtener_agregado();
  while (iterador) {
    iterador->bandera = 2;
    if (iterador->id_nodo == b) {
      delete B;
      B = new lista_aux<T>;
      while (iterador) {
        B->agregar(iterador,iterador->ruta_corta);
        iterador = iterador->ant;
      }
      return true;
    }
    iterador->saliente->iniciar_recorrido();
    arco<T> *iterador_2 = iterador->saliente->recorrer();
    while (iterador_2) {
      if (iterador_2->dir_nodo->bandera == 0) {
        iterador_2->dir_nodo->bandera = 1;
        iterador_2->dir_nodo->ant = iterador;
        iterador_2->dir_nodo->ruta_corta = iterador_2->long_nodo + iterador->ruta_corta;
        B->agregar(iterador_2->dir_nodo,iterador_2->dir_nodo->ruta_corta);
        iterador_2->dir_nodo->lugar = B->obtener_agregado();
      } else if (iterador_2->dir_nodo->bandera == 1
              && iterador_2->dir_nodo->ruta_corta > iterador_2->long_nodo + iterador->ruta_corta){

        iterador_2->dir_nodo->ant = iterador;
        iterador_2->dir_nodo->ruta_corta = iterador->ruta_corta + iterador_2->long_nodo;
        B->ajustar(iterador_2->dir_nodo->lugar, iterador_2->dir_nodo->ruta_corta);
      }

      iterador_2 = iterador->saliente->recorrer();

    }
    iterador = B->sacar_primero();
  }
}
