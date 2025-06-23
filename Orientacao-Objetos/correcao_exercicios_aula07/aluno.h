#ifndef ALUNO_H
#define ALUNO_H

#include "pessoa.h"

using namespace std;

class Aluno: public Pessoa {
    private:
        double nota;
    public:
        Aluno(string nome, int idade, double nota);
        double get_nota() const;
        void set_nota(double nota);
        void imprime_dados();
};

#endif
