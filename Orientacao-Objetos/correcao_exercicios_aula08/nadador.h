#ifndef NADADOR_H
#define NADADOR_H

#include "atleta.h"

using namespace std;

class Nadador: public Atleta {
    private:
        string categoria;
    public:
        Nadador(string nome, int idade, string categoria);
        Nadador() = default;
        string get_categoria() const;
        void set_categoria(string categoria);
        void imprime_info();
};

#endif
