#include <iostream>
#include "grafo.hpp"

int main() {
  grafica<int> A;
  A.agregar(1,2,1);
  A.agregar(1,3,2);
  A.agregar(1,4,2);
  A.agregar(2,3,1);
  A.agregar(2,5,2);
  A.agregar(3,5,2);
  A.agregar(3,6,3);
  A.agregar(4,3,1);
  A.agregar(4,6,1);
  A.agregar(5,7,4);
  A.agregar(6,5,1);
  A.agregar(6,7,1);
  A.agregar(6,7,1);
  A.pintar();
  A.dijkstra(1,7);
  A.ruta_corta();
  grafica<int> B;
  B.agregar(1,2,1);
  B.agregar(1,3,1);
  B.agregar(1,4,1);
  B.agregar(2,3,1);
  B.agregar(4,3,1);
  B.agregar(5,3,1);
  B.dijkstra(1,5);
  B.ruta_corta();
  grafica<int> C;
  C.agregar(1,2,1);
  C.agregar(1,3,2);
  C.agregar(1,4,3);
  C.agregar(3,2,1);
  C.agregar(3,6,1);
  C.agregar(4,3,1);
  C.agregar(4,6,2);
  C.agregar(6,5,1);
  C.dijkstra(1,2);
  C.ruta_corta();
  return 0;
}
