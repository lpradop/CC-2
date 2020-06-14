#pragma once
#include <string>
class Persona
{
private:
    std::string nombre_;
    std::string apellido_;
    unsigned int edad_;

public:
    Persona();
    Persona(std::string nombre, std::string apellido, unsigned int edad);
    std::string GetNombre();
    std::string GetApellido();
    unsigned int GetEdad();
    void SetNombre(std::string nombre);
    void SetApellido(std::string apellido);
    void SetEdad(unsigned int edad);
};
