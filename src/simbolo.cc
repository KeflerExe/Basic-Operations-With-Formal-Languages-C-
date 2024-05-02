// Universidad de La Laguna
// Escuela Superior de Ingeniería y Tecnología
// Grado en Ingeniería Informática
// Asignatura: Computabilidad y Algoritmia
// Curso: 2º
// Práctica 2: Operaciones con lenguajes
// Autor: Joel Oscar Martín Gutiérrez
// Correo: alu0101473840@ull.es
// Fecha: 11/10/2022
// Archivo: simbolo.cc
// Contiene la definicion de la clase Simbolo encargada de crear objetos tipo simbolo y de proporcionar métodos para los mismos.

#include "simbolo.h"

// Método encargado de dejar la string simbolo_ vacia
void Simbolo::Borrar() {
  simbolo_.clear();
}