// Universidad de La Laguna
// Escuela Superior de Ingeniería y Tecnología
// Grado en Ingeniería Informática
// Asignatura: Computabilidad y Algoritmia
// Curso: 2º
// Práctica 2: Operaciones con lenguajes
// Autor: Joel Oscar Martín Gutiérrez
// Correo: alu0101473840@ull.es
// Fecha: 11/10/2022
// Archivo: cadenas_main.cc
// Contiene la función main del proyecto que usa las clases Cadenas, Alfabeto, Simbolos y Lenguajes
// para realizar las diferentes operaciones requeridas por el usuario

#include <iostream>
#include <string>
#include <fstream>
#include <vector>
#include <cassert>

#include "cadenas.h"
#include "alfabetos.h"
#include "lenguajes.h"

// Función main: encargada de crear los objetos de las clases y de llamar al resto de funciones y métodos necesarios para el funcionamiento del programa.
int main(int argc, char *argv[]) {
  Usage(argc, argv);
  std::string nombre_archivo_origen1 = argv[1];
  std::string nombre_archivo_origen2 = argv[2];
  std::string nombre_archivo_destino = argv[3];
  int opcode = atoi(argv[4]);
  Alfabetos<std::string> alfabeto;
  Simbolo simbolo;
  Cadenas<std::string> cadena;
  Lenguajes lenguaje1;
  Lenguajes lenguaje2;
  std::ifstream archivo_origen1;
  std::ifstream archivo_origen2;
  std::string linea_extraida_archivo1;
  std::string linea_extraida_archivo2;
  CompruebaNumeroDeLineas(nombre_archivo_origen1, nombre_archivo_origen2);
  switch (opcode) {
    case 1: {
      archivo_origen1.open(nombre_archivo_origen1);
      archivo_origen2.open(nombre_archivo_origen2);
      while (true) {
        getline(archivo_origen1, linea_extraida_archivo1); 
        getline(archivo_origen2, linea_extraida_archivo2); 
        LectorDeDatos(linea_extraida_archivo1, nombre_archivo_origen1, alfabeto, simbolo, cadena, lenguaje1);
        LectorDeDatos(linea_extraida_archivo2, nombre_archivo_origen2, alfabeto, simbolo, cadena, lenguaje2);
        Lenguajes lenguaje_concatenado;
        lenguaje_concatenado = lenguaje1.ConcatenaLenguajes(lenguaje2);
        std::ofstream archivo_destino;
        archivo_destino.open(nombre_archivo_destino, std::ios_base::app);
        archivo_destino << lenguaje_concatenado << std::endl;
        archivo_destino.close();
        alfabeto.Borrar();
        cadena.Borrar();
        lenguaje1.Borrar();
        lenguaje2.Borrar();
        if (archivo_origen1.eof()) {
          break;
        }
      }
      archivo_origen1.close();
      archivo_origen2.close();
      break;
    }
    case 2: {
      archivo_origen1.open(nombre_archivo_origen1);
      archivo_origen2.open(nombre_archivo_origen2);
      while (true) {
        getline(archivo_origen1, linea_extraida_archivo1); 
        getline(archivo_origen2, linea_extraida_archivo2); 
        LectorDeDatos(linea_extraida_archivo1, nombre_archivo_origen1, alfabeto, simbolo, cadena, lenguaje1);
        LectorDeDatos(linea_extraida_archivo2, nombre_archivo_origen2, alfabeto, simbolo, cadena, lenguaje2);
        Lenguajes lenguaje_unido;
        lenguaje_unido = lenguaje1.UnionLenguajes(lenguaje2);
        std::ofstream archivo_destino;
        archivo_destino.open(nombre_archivo_destino, std::ios_base::app);
        archivo_destino << lenguaje_unido << std::endl;
        archivo_destino.close();
        alfabeto.Borrar();
        cadena.Borrar();
        lenguaje1.Borrar();
        lenguaje2.Borrar();
        if (archivo_origen1.eof()) {
          break;
        }
      }
      archivo_origen1.close();
      archivo_origen2.close();
      break;
    }
    case 3: {
      archivo_origen1.open(nombre_archivo_origen1);
      archivo_origen2.open(nombre_archivo_origen2);
      while (true) {
        getline(archivo_origen1, linea_extraida_archivo1); 
        getline(archivo_origen2, linea_extraida_archivo2); 
        LectorDeDatos(linea_extraida_archivo1, nombre_archivo_origen1, alfabeto, simbolo, cadena, lenguaje1);
        LectorDeDatos(linea_extraida_archivo2, nombre_archivo_origen2, alfabeto, simbolo, cadena, lenguaje2);
        Lenguajes lenguaje_interseccion;
        lenguaje_interseccion = lenguaje1.InterseccionLenguajes(lenguaje2);
        std::ofstream archivo_destino;
        archivo_destino.open(nombre_archivo_destino, std::ios_base::app);
        archivo_destino << lenguaje_interseccion << std::endl;
        archivo_destino.close();
        alfabeto.Borrar();
        cadena.Borrar();
        lenguaje1.Borrar();
        lenguaje2.Borrar();
        if (archivo_origen1.eof()) {
          break;
        }
      }
      archivo_origen1.close();
      archivo_origen2.close();
      break;
    }
    case 4: {
      archivo_origen1.open(nombre_archivo_origen1);
      archivo_origen2.open(nombre_archivo_origen2);
      while (true) {
        getline(archivo_origen1, linea_extraida_archivo1); 
        getline(archivo_origen2, linea_extraida_archivo2); 
        LectorDeDatos(linea_extraida_archivo1, nombre_archivo_origen1, alfabeto, simbolo, cadena, lenguaje1);
        LectorDeDatos(linea_extraida_archivo2, nombre_archivo_origen2, alfabeto, simbolo, cadena, lenguaje2);
        Lenguajes lenguaje_diferencia;
        lenguaje_diferencia = lenguaje1.DiferenciaLenguajes(lenguaje2);
        std::ofstream archivo_destino;
        archivo_destino.open(nombre_archivo_destino, std::ios_base::app);
        archivo_destino << lenguaje_diferencia << std::endl;
        archivo_destino.close();
        alfabeto.Borrar();
        cadena.Borrar();
        lenguaje1.Borrar();
        lenguaje2.Borrar();
        if (archivo_origen1.eof()) {
          break;
        }
      }
      archivo_origen1.close();
      archivo_origen2.close();
      break;
    }
    case 5: {
      archivo_origen1.open(nombre_archivo_origen1);
      while (true) {
        getline(archivo_origen1, linea_extraida_archivo1); 
        LectorDeDatos(linea_extraida_archivo1, nombre_archivo_origen1, alfabeto, simbolo, cadena, lenguaje1);
        Lenguajes lenguaje_inverso;
        lenguaje_inverso = lenguaje1.LenguajeInverso();
        std::ofstream archivo_destino;
        archivo_destino.open(nombre_archivo_destino, std::ios_base::app);
        archivo_destino << lenguaje_inverso << std::endl;
        archivo_destino.close();
        alfabeto.Borrar();
        cadena.Borrar();
        lenguaje1.Borrar();
        if (archivo_origen1.eof()) {
          break;
        }
      }
      archivo_origen1.close();
      break;
    }
    case 6: {
      int numero_potencias{0};
      std::cout << "Introduzca el valor de potencia que desea calcular." << std::endl;
      std::cin >> numero_potencias;
      archivo_origen1.open(nombre_archivo_origen1);
      while (true) {
        getline(archivo_origen1, linea_extraida_archivo1); 
        LectorDeDatos(linea_extraida_archivo1, nombre_archivo_origen1, alfabeto, simbolo, cadena, lenguaje1);
        Lenguajes lenguaje_potencia;
        std::ofstream archivo_destino;
        lenguaje_potencia = lenguaje1.PotenciaDeLenguaje(numero_potencias);
        archivo_destino.open(nombre_archivo_destino, std::ios_base::app);
        archivo_destino << lenguaje_potencia << std::endl;
        archivo_destino.close();
        alfabeto.Borrar();
        cadena.Borrar();
        lenguaje1.Borrar();
        if (archivo_origen1.eof()) {
          break;
        }
      }
      archivo_origen1.close();
      break;
    }
    case 7: {
      archivo_origen1.open(nombre_archivo_origen1);
      archivo_origen2.open(nombre_archivo_origen2);
      while (true) {
        getline(archivo_origen1, linea_extraida_archivo1); 
        getline(archivo_origen2, linea_extraida_archivo2); 
        LectorDeDatos(linea_extraida_archivo1, nombre_archivo_origen1, alfabeto, simbolo, cadena, lenguaje1);
        LectorDeDatos(linea_extraida_archivo2, nombre_archivo_origen2, alfabeto, simbolo, cadena, lenguaje2);
        bool esta_contenido;
        esta_contenido = lenguaje1.CompruebaSiEstaContenido(lenguaje2);
        if (esta_contenido == false) {
          std::cout << "El lenguaje no está contenido." << std::endl;
        } else {
          std::cout << "El lenguaje está contenido." << std::endl;
        }
        alfabeto.Borrar();
        cadena.Borrar();
        lenguaje1.Borrar();
        lenguaje2.Borrar();
        if (archivo_origen1.eof()) {
          break;
        }
      }
      archivo_origen1.close();
      archivo_origen2.close();
      break;
    }
    default: {
      std::cout << "Número de operación no válido, introduzca ./cadenas_main --help para más información." << std::endl;
      exit(EXIT_FAILURE);
    }
  }
}