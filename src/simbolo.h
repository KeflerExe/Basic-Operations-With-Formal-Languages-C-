// Universidad de La Laguna
// Escuela Superior de Ingeniería y Tecnología
// Grado en Ingeniería Informática
// Asignatura: Computabilidad y Algoritmia
// Curso: 2º
// Práctica 2: Operaciones con lenguajes
// Autor: Joel Oscar Martín Gutiérrez
// Correo: alu0101473840@ull.es
// Fecha: 11/10/2022
// Archivo: simbolo.h
// Contiene la clase Simbolos encargada de crear objetos tipo simbolo y de proporcionar métodos para los mismos.

#include <iostream>
#include <string>
#include <fstream>
#include <vector>

#ifndef SIMBOLO_H
#define SIMBOLO_H

// Clase Simbolos, encargada de crear y manejar los objetos tipo Simbolos
class Simbolo {  
 public:
  // Constructores
  Simbolo() : simbolo_{} {}  
  Simbolo(const std::string& simbolo) : simbolo_{simbolo} {}
  
  // Getter y setter
  std::string get_simbolo(void) const { return simbolo_; }
  void set_simbolo(const std::string& data) { simbolo_ = data; }

  // Métodos para modificar el atributo simbolo_
  void Borrar();
 private:
  std::string simbolo_;
};

#endif