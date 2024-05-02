// Universidad de La Laguna
// Escuela Superior de Ingeniería y Tecnología
// Grado en Ingeniería Informática
// Asignatura: Computabilidad y Algoritmia
// Curso: 2º
// Práctica 2: Operaciones con lenguajes
// Autor: Joel Oscar Martín Gutiérrez
// Correo: alu0101473840@ull.es
// Fecha: 11/10/2022
// Archivo: lenguajes.h
// Contiene la clase Lenguaje encargada de crear objetos tipo lenguaje y de proporcionar métodos para los mismos.

#include <iostream>
#include <string>
#include <fstream>
#include <vector>
#include <set>

#include "cadenas.h"
#include "alfabetos.h"

#ifndef LENGUAJES_H
#define LENGUAJES_H

// Clase Lenguajes, encargada de crear y manejar los objetos tipo Lenguajes
class Lenguajes {  
 public:
  // Constructores
  Lenguajes() : cadenas_{}, alfabeto_{}  {}  
  
  // Métodos para modificar u obtener información del atributo cadenas_ o alfabeto_ 
  void InsertarCadenas(const Cadenas<std::string>& cadena);
  void InsertarAlfabeto(const Alfabetos<std::string>& alfabeto);
  int TamanioContenedorCadenas() const;
  int TamanioContenedorAlfabeto() const;
  bool CompruebaSiNoTieneCadenas() const;
  void Borrar();
  std::set<Cadenas<std::string>>::iterator InicioContenedorCadenas() const;
  std::set<Alfabetos<std::string>>::iterator InicioContenedorAlfabeto() const;

  // Métodos de operación correspondientes a las 6 operaciones disponibles con lenguajes.
  Lenguajes ConcatenaLenguajes(const Lenguajes& lenguaje2) const;
  Lenguajes UnionLenguajes(const Lenguajes& lenguaje2) const;
  Lenguajes InterseccionLenguajes(const Lenguajes& lenguaje2) const;
  Lenguajes DiferenciaLenguajes(const Lenguajes& lenguaje2) const;
  Lenguajes LenguajeInverso() const;
  Lenguajes PotenciaDeLenguaje(const int numero_potencias) const;
  bool CompruebaSiEstaContenido (const Lenguajes& lenguaje2) const;

  // Sobrecarga de operadores
  bool operator<(const Lenguajes& lenguaje) const {
    return cadenas_ < lenguaje.cadenas_;
  }
  friend std::ofstream& operator<<(std::ofstream& salida, const Lenguajes& cadena);
 private:
  std::set<Cadenas<std::string>> cadenas_;
  std::set<Alfabetos<std::string>> alfabeto_;
};

void LectorDeDatos(const std::string linea_extraida, const std::string nombre_archivo_origen, Alfabetos<std::string>& alfabeto, Simbolo& simbolo, Cadenas<std::string>& cadena, Lenguajes& lenguajes);

#endif