// Universidad de La Laguna
// Escuela Superior de Ingeniería y Tecnología
// Grado en Ingeniería Informática
// Asignatura: Computabilidad y Algoritmia
// Curso: 2º
// Práctica 2: Operaciones con lenguajes
// Autor: Joel Oscar Martín Gutiérrez
// Correo: alu0101473840@ull.es
// Fecha: 11/10/2022
// Archivo: cadenas_func.cc
// Contiene las diferentes funciones que son llamadas desde el main encargadas de realizar ciertas funciones como extraer datos, comprobar que cadena y alfabeto coincidan etc...

#include <iostream>
#include <string>
#include <fstream>
#include <vector>

#include "cadenas.h"
#include "alfabetos.h"
#include "lenguajes.h"

// Función encargada de comprobar que ambos ficheros de entrada contienen la misma cantidad de lenguajes.
void CompruebaNumeroDeLineas(const std::string nombre_archivo_origen1, const std::string nombre_archivo_origen2) {
  std::string string_auxiliar;
  std::ifstream archivo_origen1;
  std::ifstream archivo_origen2;
  int numero_lineas_archivo1 = 0;
  int numero_lineas_archivo2 = 0;
  archivo_origen1.open(nombre_archivo_origen1);
  while (getline(archivo_origen1, string_auxiliar)) {
    ++numero_lineas_archivo1;
  }
  archivo_origen1.close();
  archivo_origen2.open(nombre_archivo_origen2);
  while (getline(archivo_origen2, string_auxiliar)) {
    ++numero_lineas_archivo2;
  }
  archivo_origen2.close();
  if (numero_lineas_archivo1 != numero_lineas_archivo2) {
    std::cout << "Fallo crítico: ambos ficheros no contienen la misma cantidad de lenguajes." << std::endl;
    exit(EXIT_FAILURE);
  }
}

/*
 * La función ComprobacionCadenaYAlfabeto es la encargada de comprobar que no hay ningún símbolo en la cadena que no se encuentre en el alfabeto y 
 * de que no se repitan 2 símbolos en el alfabeto. En caso de que alguno de los dos casos se cumpla saltará un mensaje de error indicándolo y se detendrá el programa.
 */
void ComprobacionCadenaYAlfabeto(const Alfabetos<std::string>& alfabeto, const Cadenas<std::string>& cadena) {
  for (int iterador = 0; iterador < cadena.LongitudDeCadena(); ++iterador) {
    bool mismo_simbolo_encontrado = false;
    for (int iterador2 = 0; iterador2 < alfabeto.TamanioVector(); ++iterador2) {
      if(cadena[iterador] == alfabeto[iterador2]) {
        mismo_simbolo_encontrado = true;
        break;
      }
    }
    if(mismo_simbolo_encontrado == false) {
      std::cout << "Fallo crítico: la cadena \"" << cadena << "\" contiene caracteres no incluidos en el alfabeto \"" << alfabeto << "\"" << std::endl;
      exit(EXIT_FAILURE);
    }
  }
  for (int iterador = 0; iterador < alfabeto.TamanioVector(); ++iterador) {
    bool mismo_simbolo_encontrado = false;
    for (int iterador2 = 0; iterador2 < alfabeto.TamanioVector(); ++iterador2) {
      if(iterador != iterador2 && alfabeto[iterador] == alfabeto[iterador2]) {
        mismo_simbolo_encontrado = true;
        break;
      }
    }
    if(mismo_simbolo_encontrado == true) {
      std::cout << "Fallo crítico: el alfabeto \"" << alfabeto << "\" contiene caracteres repetidos" << std::endl;
      exit(EXIT_FAILURE);
    }
  }
}

// Esta función calcula cuantos simbolos del total de simbolos del alfabeto se encuentran en la cadena.
int CompruebaElNumeroDeSimbolosEnCadena(const Cadenas<std::string> cadena, const Alfabetos<std::string> alfabeto) {
  int numero_de_simbolos_totales{0};
  for (int iterador1 = 0; iterador1 < alfabeto.TamanioVector(); ++iterador1) {
    for (int iterador2 = 0; iterador2 < cadena.LongitudDeCadena(); ++iterador2) {
      if (alfabeto[iterador1] == cadena[iterador2]) {
        numero_de_simbolos_totales += 1;
        break;
      }
    }
  }
  return numero_de_simbolos_totales;
}

// Esta función recibe la línea extraída del fichero y su objetivo es extraer de dicha línea la cadena, alfabeto y símbolos encontrados en ella.
void LectorDeDatos(const std::string linea_extraida, const std::string nombre_archivo_origen, Alfabetos<std::string>& alfabeto, Simbolo& simbolo, Cadenas<std::string>& cadena, Lenguajes& lenguajes) {
  int iterador1 = 0;
  char simbolo_extraido;
  int posicion_final_alfabeto{0};
  posicion_final_alfabeto = linea_extraida.find_first_of("}");
  while (iterador1 < posicion_final_alfabeto - 1) {
    ++iterador1;
    if (linea_extraida[iterador1] != ' ') {
      simbolo_extraido = linea_extraida[iterador1];
      if (simbolo_extraido == '&' || simbolo_extraido == '{' || simbolo_extraido == '}') {
        std::cout << "Fallo crítico: el alfabeto de un lenguaje no puede contener el símbolo \"&\", \"{\" o \"}\"." << std::endl;
        exit(EXIT_FAILURE);
      }
      std::string simbolo_extraido_string(1, simbolo_extraido);
      simbolo.set_simbolo(simbolo_extraido_string);
      alfabeto.push_back(simbolo.get_simbolo());
      simbolo.Borrar(); 
    } 
  }
  lenguajes.InsertarAlfabeto(alfabeto);
  iterador1 += 4;
  simbolo.Borrar();
  while (iterador1 < linea_extraida.size() - 1) {
    ++iterador1;
    if (linea_extraida[iterador1] != ' ') {
      simbolo_extraido = linea_extraida[iterador1];
      std::string simbolo_extraido_string(1, simbolo_extraido);
      simbolo.set_simbolo(simbolo_extraido_string);
      cadena.push_back(simbolo.get_simbolo());
      simbolo.Borrar();
    } else {
      lenguajes.InsertarCadenas(cadena);
      cadena.Borrar();
    }
  }
  alfabeto.Borrar();
  cadena.Borrar();
}

/*
 * Comprueba que los argumentos introducidos por línea de comandos sean los 
 * correctos, además de proporcionar ayuda en caso de que el usuario no sepa como se han de introducir los argumentos.
 */
void Usage(int argc, char *argv[]) {
  if (argc != 5) {
    std::string parametro_introducido = argv[1];
    if (parametro_introducido == "--help") {
      std::cout << "--Cadenas" << std::endl;
      std::cout << "Modo de uso: ./cadenas_main fichero_entrada1 fichero_entrada2 fichero_salida opcode" << std::endl;
      std::cout << "fichero_entrada1: Fichero de texto de origen donde se encuentran los diferentes lenguajes" << std::endl;
      std::cout << "fichero_entrada2: Fichero de texto de origen donde se encuentran los diferentes lenguajes" << std::endl;
      std::cout << "fichero_salida:  Fichero de texto de destino donde se va a escribir el resultado de las operaciones" << std::endl;
      std::cout << "opcode:  operación a realizar con los datos extraidos de los ficheros" << std::endl;
      std::cout << "Pudiendo el opcode tomar los siguientes valores:" << std::endl;
      std::cout << "opcode = 1: calcula la concatenación entre dos lenguajes." << std::endl;
      std::cout << "opcode = 2: calcula la unión entre dos lenguajes." << std::endl;
      std::cout << "opcode = 3: calcula la intersección entre dos lenguajes." << std::endl;
      std::cout << "opcode = 4: calcula la diferencia entre dos lenguajes." << std::endl;
      std::cout << "opcode = 5: calcula la inversa de un lenguaje." << std::endl;
      std::cout << "opcode = 6: calcula la potencia de un lenguaje." << std::endl;
      std::cout << "opcode = 7: comprueba si el segundo lenguaje esta contenido en el primero." <<  std::endl;
      exit(EXIT_SUCCESS);
    } else {
      std::cout << "--Cadenas " << std::endl;
      std::cout << "Modo de uso: ./cadenas_main fichero_entrada1 fichero_entrada2 fichero_salida opcode" << std::endl << "Pruebe ./cadenas_main --help para más información" << std::endl;
      exit(EXIT_FAILURE);
    }
  }   
}