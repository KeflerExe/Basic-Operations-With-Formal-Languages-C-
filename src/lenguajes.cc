// Universidad de La Laguna
// Escuela Superior de Ingeniería y Tecnología
// Grado en Ingeniería Informática
// Asignatura: Computabilidad y Algoritmia
// Curso: 2º
// Práctica 2: Operaciones con lenguajes
// Autor: Joel Oscar Martín Gutiérrez
// Correo: alu0101473840@ull.es
// Fecha: 11/10/2022
// Archivo: lenguajes.cc
// Contiene la implementación de la clase Lenguajes encargada de crear objetos tipo cadena y de proporcionar métodos para los mismos.

#include "lenguajes.h"

// Método encargada de insertar cadenas en el lenguaje
void Lenguajes::InsertarCadenas(const Cadenas<std::string>& cadena) {
  cadenas_.insert(cadena);
}

// Método encargada de insertar el alfabeto en el lenguaje
void Lenguajes::InsertarAlfabeto(const Alfabetos<std::string>& alfabeto) {
  alfabeto_.insert(alfabeto);
}

// Método encargado de devolver el tamaño del set que contiene las cadenas
int Lenguajes::TamanioContenedorCadenas() const {
  return cadenas_.size(); 
}

// Método encargado de devolver el tamaño del set que contiene el alfabeto
int Lenguajes::TamanioContenedorAlfabeto() const {
  return alfabeto_.size(); 
}

// Método encargado de comprobar si el lenguaje tiene cadenas o no
bool Lenguajes::CompruebaSiNoTieneCadenas() const {
  return cadenas_.empty();
}

// Método encargado de retornar un iterador iniciado al principio del set de cadenas
std::set<Cadenas<std::string>>::iterator Lenguajes::InicioContenedorCadenas() const {
  return cadenas_.begin();
}

// Método encargado de retornar un iterador iniciado al principio del set de alfabeto
std::set<Alfabetos<std::string>>::iterator Lenguajes::InicioContenedorAlfabeto() const {
  return alfabeto_.begin();
}

// Sobrecarga del operador * para las potencias de lenguajes
Lenguajes operator*(const Lenguajes& lenguaje1, const Lenguajes& lenguaje2) {
  Lenguajes lenguaje_multiplicado;
  Cadenas<std::string> cadena_a_introducir;
  std::set<Cadenas<std::string>>::iterator iterador_set_cadenas = lenguaje1.InicioContenedorCadenas();
  for (int iterador1 = 0; iterador1 < lenguaje1.TamanioContenedorCadenas(); ++iterador1) {
    Cadenas<std::string> cadena_extraida_lenguaje1 = *iterador_set_cadenas;  
    std::set<Cadenas<std::string>>::iterator iterador_set_cadenas2 = lenguaje2.InicioContenedorCadenas();
    for (int iterador2 = 0; iterador2 < lenguaje2.TamanioContenedorCadenas(); ++iterador2) {
      Cadenas<std::string> cadena_extraida_lenguaje2 = *iterador_set_cadenas2;
      cadena_a_introducir = cadena_extraida_lenguaje1 + cadena_extraida_lenguaje2;
      lenguaje_multiplicado.InsertarCadenas(cadena_a_introducir);
      std::advance(iterador_set_cadenas2, 1);
    }
    std::advance(iterador_set_cadenas, 1);
  }
  return lenguaje_multiplicado;
}

// Método encargado de obtener la concatenación de dos lenguajes
Lenguajes Lenguajes::ConcatenaLenguajes(const Lenguajes& lenguaje2) const {
  Lenguajes lenguaje_concatenado;
  if (CompruebaSiNoTieneCadenas() == true ) {
    return lenguaje_concatenado;
  } 
  if (lenguaje2.CompruebaSiNoTieneCadenas() == true ) {
    return lenguaje_concatenado;
  } 
  Cadenas<std::string> cadena_a_introducir;
  std::set<Cadenas<std::string>>::iterator iterador_set_cadenas = InicioContenedorCadenas();
  for (int iterador1 = 0; iterador1 < TamanioContenedorCadenas(); ++iterador1) {
    Cadenas<std::string> cadena_extraida_lenguaje1 = *iterador_set_cadenas;  
    std::set<Cadenas<std::string>>::iterator iterador_set_cadenas2 = lenguaje2.InicioContenedorCadenas();
    for (int iterador2 = 0; iterador2 < lenguaje2.TamanioContenedorCadenas(); ++iterador2) {
      Cadenas<std::string> cadena_extraida_lenguaje2 = *iterador_set_cadenas2;
      cadena_a_introducir = cadena_extraida_lenguaje1 + cadena_extraida_lenguaje2;
      lenguaje_concatenado.InsertarCadenas(cadena_a_introducir);
      std::advance(iterador_set_cadenas2, 1);
    }
    std::advance(iterador_set_cadenas, 1);
  }
  Alfabetos<std::string> alfabeto_a_introducir;;
  std::set<Alfabetos<std::string>>::iterator iterador_set_alfabeto = InicioContenedorAlfabeto();
  for (int iterador1 = 0; iterador1 < TamanioContenedorAlfabeto(); ++iterador1) {
    Alfabetos<std::string> alfabeto_extraido_lenguaje1 = *iterador_set_alfabeto;  
    std::set<Alfabetos<std::string>>::iterator iterador_set_alfabeto2 = lenguaje2.InicioContenedorAlfabeto();
    for (int iterador2 = 0; iterador2 < lenguaje2.TamanioContenedorAlfabeto(); ++iterador2) {
      Alfabetos<std::string> alfabeto_extraido_lenguaje2 = *iterador_set_alfabeto2;
      alfabeto_a_introducir = alfabeto_extraido_lenguaje1 + alfabeto_extraido_lenguaje2;
      lenguaje_concatenado.InsertarAlfabeto(alfabeto_a_introducir);
      std::advance(iterador_set_alfabeto2, 1);
    }
    std::advance(iterador_set_alfabeto, 1);
  }
  if (lenguaje_concatenado.CompruebaSiNoTieneCadenas() == true) {
    lenguaje_concatenado.alfabeto_.clear();
  }
  return lenguaje_concatenado;
}

// Método encargado de obtener la unión de dos lenguajes
Lenguajes Lenguajes::UnionLenguajes(const Lenguajes& lenguaje2) const {
  Lenguajes lenguaje_unido;
  if (CompruebaSiNoTieneCadenas() == true ) {
    lenguaje_unido.cadenas_ = lenguaje2.cadenas_;
    lenguaje_unido.alfabeto_ = lenguaje2.alfabeto_;
    return lenguaje_unido;
  } 
  if (lenguaje2.CompruebaSiNoTieneCadenas() == true ) {
    lenguaje_unido.cadenas_ = cadenas_;
    lenguaje_unido.alfabeto_ = alfabeto_;
    return lenguaje_unido;
  } 
  std::set<Cadenas<std::string>>::iterator iterador_set_cadenas = InicioContenedorCadenas();
  for (int iterador = 0; iterador < TamanioContenedorCadenas(); ++iterador) {
    Cadenas<std::string> cadena_extraida_lenguaje = *iterador_set_cadenas;
    lenguaje_unido.InsertarCadenas(cadena_extraida_lenguaje);
    std::advance(iterador_set_cadenas, 1);
  }
  std::set<Cadenas<std::string>>::iterator iterador_set_cadenas2 = lenguaje2.InicioContenedorCadenas();
  for (int iterador = 0; iterador < lenguaje2.TamanioContenedorCadenas(); ++iterador) {
    Cadenas<std::string> cadena_extraida_lenguaje2 = *iterador_set_cadenas2;
    lenguaje_unido.InsertarCadenas(cadena_extraida_lenguaje2);
    std::advance(iterador_set_cadenas2, 1);
  }
  std::set<Alfabetos<std::string>>::iterator iterador_set_alfabetos = InicioContenedorAlfabeto();
  for (int iterador = 0; iterador < TamanioContenedorAlfabeto(); ++iterador) {
    Alfabetos<std::string> alfabeto_extraido_lenguaje = *iterador_set_alfabetos;
    lenguaje_unido.InsertarAlfabeto(alfabeto_extraido_lenguaje);
    std::advance(iterador_set_alfabetos, 1);
  }
  std::set<Alfabetos<std::string>>::iterator iterador_set_alfabetos2 = lenguaje2.InicioContenedorAlfabeto();
  for (int iterador = 0; iterador < lenguaje2.TamanioContenedorAlfabeto(); ++iterador) {
    Alfabetos<std::string> alfabeto_extraido_lenguaje2 = *iterador_set_alfabetos2;
    lenguaje_unido.InsertarAlfabeto(alfabeto_extraido_lenguaje2);
    std::advance(iterador_set_alfabetos2, 1);
  }
  if (lenguaje_unido.CompruebaSiNoTieneCadenas() == true) {
    lenguaje_unido.alfabeto_.clear();
  }
  return lenguaje_unido;
}

// Método encargado de obtener la intersección de dos lenguajes
Lenguajes Lenguajes::InterseccionLenguajes(const Lenguajes& lenguaje2) const {
  Lenguajes lenguaje_interseccion;
  if (CompruebaSiNoTieneCadenas() == true ) {
    return lenguaje_interseccion;
  } 
  if (lenguaje2.CompruebaSiNoTieneCadenas() == true ) {
    return lenguaje_interseccion;
  } 
  std::set<Cadenas<std::string>>::iterator iterador_set_cadenas = InicioContenedorCadenas();
  for (int iterador1 = 0; iterador1 < TamanioContenedorCadenas(); ++iterador1) {
    Cadenas<std::string> cadena_extraida_lenguaje1 = *iterador_set_cadenas;
    std::set<Cadenas<std::string>>::iterator iterador_set_cadenas2 = lenguaje2.InicioContenedorCadenas();
    for (int iterador2 = 0; iterador2 < lenguaje2.TamanioContenedorCadenas(); ++iterador2) {
      Cadenas<std::string> cadena_extraida_lenguaje2 = *iterador_set_cadenas2;
      if (cadena_extraida_lenguaje1 == cadena_extraida_lenguaje2) {
        lenguaje_interseccion.InsertarCadenas(cadena_extraida_lenguaje1);
      }
      std::advance(iterador_set_cadenas2, 1);
    }
    std::advance(iterador_set_cadenas, 1);
  }
  lenguaje_interseccion.alfabeto_ = alfabeto_;
  if (lenguaje_interseccion.CompruebaSiNoTieneCadenas() == true) {
    lenguaje_interseccion.alfabeto_.clear();
  } 
  return lenguaje_interseccion;
}

// Método encargado de obtener la diferencia de dos lenguajes
Lenguajes Lenguajes::DiferenciaLenguajes(const Lenguajes& lenguaje2) const {
  Lenguajes lenguaje_diferencia;
  if (CompruebaSiNoTieneCadenas() == true ) {
    return lenguaje_diferencia;
  } 
  if (lenguaje2.CompruebaSiNoTieneCadenas() == true ) {
    lenguaje_diferencia.cadenas_ = cadenas_;
    lenguaje_diferencia.alfabeto_ = alfabeto_;
    return lenguaje_diferencia;
  } 
  std::set<Cadenas<std::string>>::iterator iterador_set = InicioContenedorCadenas();
  for (int iterador1 = 0; iterador1 < TamanioContenedorCadenas(); ++iterador1) {
    bool misma_cadena_encontrada = false;
    Cadenas<std::string> cadena_extraida_lenguaje1 = *iterador_set;
    std::set<Cadenas<std::string>>::iterator iterador_set2 = lenguaje2.InicioContenedorCadenas();
    for (int iterador2 = 0; iterador2 < lenguaje2.TamanioContenedorCadenas(); ++iterador2) {
      Cadenas<std::string> cadena_extraida_lenguaje2 = *iterador_set2;
      if (cadena_extraida_lenguaje1 == cadena_extraida_lenguaje2) {
        misma_cadena_encontrada = true;
        break;
      }
      std::advance(iterador_set2, 1);
    }
    if (misma_cadena_encontrada == false) {
      lenguaje_diferencia.InsertarCadenas(cadena_extraida_lenguaje1);
    }
    std::advance(iterador_set, 1);
  }
  lenguaje_diferencia.alfabeto_ = alfabeto_;
  if (lenguaje_diferencia.CompruebaSiNoTieneCadenas() == true) {
    lenguaje_diferencia.alfabeto_.clear();
  } 
  return lenguaje_diferencia;
}

// Método encargado de obtener la inversa de un lenguaje
Lenguajes Lenguajes::LenguajeInverso() const {
  Lenguajes lenguaje_inverso;
  if (CompruebaSiNoTieneCadenas() == true ) {
    return lenguaje_inverso;
  } 
  std::set<Cadenas<std::string>>::iterator iterador_set = InicioContenedorCadenas();
  for (int iterador = 0; iterador < TamanioContenedorCadenas(); ++iterador) {
    Cadenas<std::string> cadena_extraida_lenguaje = *iterador_set;
    cadena_extraida_lenguaje.InvierteLaCadena();
    lenguaje_inverso.InsertarCadenas(cadena_extraida_lenguaje);
    std::advance(iterador_set, 1);
  }
  lenguaje_inverso.alfabeto_ = alfabeto_;
  return lenguaje_inverso;
}

// Método encargado de obtener la potencia de un lenguaje
Lenguajes Lenguajes::PotenciaDeLenguaje(const int numero_potencias) const {
  Lenguajes lenguaje_potencias;
  Lenguajes lenguaje_auxiliar;
  if (CompruebaSiNoTieneCadenas() == true ) {
    return lenguaje_potencias;
  } 
  if (numero_potencias == 0) {
    std::string ampersan = "&";
    Cadenas<std::string> cadena_vacia;
    cadena_vacia.push_back(ampersan);
    lenguaje_potencias.InsertarCadenas(cadena_vacia);
    lenguaje_potencias.alfabeto_ = alfabeto_;
    return lenguaje_potencias;
  }
  if (numero_potencias == 1) {
    lenguaje_potencias.cadenas_ = cadenas_;
    lenguaje_potencias.alfabeto_ = alfabeto_;
    return lenguaje_potencias;
  }
  lenguaje_auxiliar.cadenas_ = cadenas_;
  lenguaje_potencias.cadenas_ = cadenas_;
  for (int iterador = 1; iterador < numero_potencias; ++iterador) {
    lenguaje_potencias = lenguaje_potencias * lenguaje_auxiliar;
  }
  lenguaje_potencias.alfabeto_ = alfabeto_;
  if (lenguaje_potencias.CompruebaSiNoTieneCadenas() == true) {
    lenguaje_potencias.alfabeto_.clear();
  } 
  return lenguaje_potencias;
}

bool Lenguajes::CompruebaSiEstaContenido(const Lenguajes& lenguaje2) const {
  if (lenguaje2.cadenas_.empty() == true && cadenas_.empty() == false) {
    return false;
  }
  if (lenguaje2.cadenas_.empty() == false && cadenas_.empty() == true) {
    return false;
  }
  int numero_cadenas_contenidas{0};
  std::set<Cadenas<std::string>>::iterator iterador_set_cadenas2 = lenguaje2.InicioContenedorCadenas();
  for (int iterador1 = 0; iterador1 < lenguaje2.TamanioContenedorCadenas(); ++iterador1) {
    Cadenas<std::string> cadena_extraida_lenguaje2 = *iterador_set_cadenas2;  
    std::set<Cadenas<std::string>>::iterator iterador_set_cadenas = InicioContenedorCadenas();
    for (int iterador2 = 0; iterador2 < TamanioContenedorCadenas(); ++iterador2) {
      Cadenas<std::string> cadena_extraida_lenguaje1 = *iterador_set_cadenas;
      if (cadena_extraida_lenguaje2 == cadena_extraida_lenguaje1) {
        numero_cadenas_contenidas += 1;
      }
      std::advance(iterador_set_cadenas, 1);
    }
    std::advance(iterador_set_cadenas2, 1);
  }
  if (numero_cadenas_contenidas == lenguaje2.TamanioContenedorCadenas()) {
    return true;
  } else {
    return false;
  }
}


// Método encargado de limpiar el contenido de un lenguaje y dejar vacíos sus atributos
void Lenguajes::Borrar() {
  cadenas_.clear();
  alfabeto_.clear();
}

// Sobrecarga del operador << para la impresión de los lenguajes
std::ofstream& operator<<(std::ofstream& salida, const Lenguajes& lenguaje) {
  std::set<Alfabetos<std::string>>::iterator iterador_set_alfabeto = lenguaje.InicioContenedorAlfabeto();
  salida << "{ ";
  for (int iterador1 = 0; iterador1 < lenguaje.TamanioContenedorAlfabeto(); ++iterador1) {
    Alfabetos<std::string> alfabeto_extraido_lenguaje = *iterador_set_alfabeto;
    salida << alfabeto_extraido_lenguaje;
    std::advance(iterador_set_alfabeto, 1);
  }
  salida << "} ";
  salida << "{ ";
  std::set<Cadenas<std::string>>::iterator iterador_set_cadenas = lenguaje.InicioContenedorCadenas();
  for (int iterador1 = 0; iterador1 < lenguaje.TamanioContenedorCadenas(); ++iterador1) {
    Cadenas<std::string> cadena_extraida_lenguaje = *iterador_set_cadenas;
    salida << cadena_extraida_lenguaje << " ";
    std::advance(iterador_set_cadenas, 1);
  }
  salida << "}";
  return salida;
}