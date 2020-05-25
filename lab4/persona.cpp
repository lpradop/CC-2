#include <string>
#include "persona.hpp"

Persona::Persona() : nombre_(""), apellido_(""), edad_(0) {}

Persona::Persona(std::string nombre, std::string apellido, unsigned int edad) : nombre_(nombre), apellido_(apellido), edad_(edad) {}
std::string Persona::GetNombre() { return nombre_; }
std::string Persona::GetApellido() { return apellido_; }

unsigned int Persona::GetEdad() { return edad_; }
void Persona::SetApellido(std::string apellido) { apellido_ = apellido; }
void Persona::SetNombre(std::string nombre) { nombre_ = nombre; }
void Persona::SetEdad(unsigned int edad)
{
    edad_ = edad;
}