#include "arreglo-de-personas.hpp"
#include "persona.hpp"

ArregloDePersonas::ArregloDePersonas() : persona_(nullptr), tam_mem_(0), tam_(0) {}
ArregloDePersonas::ArregloDePersonas(const ArregloDePersonas &kObj)
{
    persona_ = kObj.tam_ > 0 ? new Persona[kObj.tam_mem_] : nullptr;
    tam_ = kObj.tam_;
    tam_mem_ = kObj.tam_mem_;
    if (tam_ > 0)
        CopyArr(kObj.persona_, persona_, tam_);
}
void ArregloDePersonas::CopyArr(const Persona *from, Persona *to, const size_t size)
{
    for (size_t i = 0; i < size; ++i)
    {
        *(to++) = *(from++);
    }
}
ArregloDePersonas::ArregloDePersonas(const Persona kPersonas[], const size_t kTam)
{
    tam_ = kTam;
    tam_mem_ = 2 * kTam;
    persona_ = new Persona[tam_mem_];
    CopyArr(kPersonas, persona_, kTam);
}
ArregloDePersonas::~ArregloDePersonas()
{
    delete[] persona_;
}
void ArregloDePersonas::Resize(const size_t kTam)
{
    if (tam_mem_ == 0)
    {
        if (kTam > 0)
        {
            tam_mem_ = 2 * kTam;
            persona_ = new Persona[tam_mem_];
            tam_ = kTam;
        }
    }
    else
    {
        if (tam_mem_ >= kTam)
        {
            tam_ = kTam;
        }
        else
        {
            tam_mem_ = 2 * kTam;
            Persona *temp = new Persona[tam_mem_];
            CopyArr(persona_, temp, tam_);
            delete[] persona_;
            persona_ = temp;
            tam_ = kTam;
        }
    }
}
void ArregloDePersonas::Remove(const size_t kPos)
{
    CopyArr(persona_ + kPos + 1, persona_ + kPos, tam_ - kPos - 1);
    --tam_;
}
void ArregloDePersonas::Insert(const size_t kPos, const Persona &kPersona)
{
    if (tam_ < tam_mem_)
    {
        for (Persona *p = persona_ + tam_; p != persona_ + kPos; --p)
        {
            CopyArr(p - 1, p, 1);
        }
        *(persona_ + kPos) = kPersona;
    }
    else
    {
        Resize(tam_mem_ + 1);
        Insert(kPos, kPersona);
    }
}
void ArregloDePersonas::PushBack(const Persona &kPersona)
{
    if (tam_ < tam_mem_)
    {
        *(persona_ + tam_) = kPersona;
    }
    else
    {
        Resize(tam_ + 1);
        PushBack(kPersona);
    }
}
void ArregloDePersonas::Clear()
{
    delete[] persona_;
    persona_ = new Persona[tam_mem_];
}
const size_t ArregloDePersonas::GetSize() { return tam_; }
