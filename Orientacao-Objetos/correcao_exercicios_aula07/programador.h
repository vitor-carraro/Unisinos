#ifndef PROGRAMADOR_H
#define PROGRAMADOR_H

#include "pessoa.h"

using namespace std;

class Programador: public Pessoa {
    private:
        string linguagem;
    public:
        Programador(string nome, int idade, string linguagem);
        string get_linguagem() const;
        void set_linguagem(string linguagem);
        void imprime_dados();
};

#endif
