#include<Foco.hpp>
#include<iostream>
using namespace std;
int main(int argc, char const *argv[])
{
    cout<<"HOLA MUNDO"<<endl;
    Foco foco;
    foco.encender();
    cout<<"EstadoFoco: "
    <<foco.LeerEstado()<<endl;
    return 0;
    foco.apagar();
    return 0;
}
