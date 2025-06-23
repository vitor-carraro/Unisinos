#ifndef NADADOR_H
#define NADADOR_H

#include "Atleta.h"

using namespace std;

class Nadador : public Atleta 
{
private:
    string categoria;
public:
    Nadador(string nome, int idade, string categoria);
    void SetCategoria();
    string GetCategoria();
    void imprime_info();
};

#endif
