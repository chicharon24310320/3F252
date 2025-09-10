#pragma once
#include<EstadoFoco.hpp>

class Foco
{
private:
    EstadoFoco estado;

public:
    Foco() {}
    ~Foco() {}
    void encender() { estado = true; }
    void apagar() { estado = false; }
    EstadoFoco LeerEstado()
    {
        return estado;
    }
};