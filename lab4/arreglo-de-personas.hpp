#pragma once
#include "persona.hpp"
class ArregloDePersonas
{
private:
    Persona *persona_;
    size_t tam_;
    size_t tam_mem_;
    void CopyArr(const Persona *from, Persona *to, const size_t size);

public:
    ArregloDePersonas(const Persona kPersonas[], const size_t kTam);
    ArregloDePersonas(const ArregloDePersonas &kObj);
    ArregloDePersonas();
    void Resize(const size_t kTam);
    void PushBack(const Persona &kPersona);
    void Insert(const size_t kPos, const Persona &kPersona);
    void Remove(const size_t kPos);
    void Clear();

    const size_t GetSize();
    ~ArregloDePersonas();
};

