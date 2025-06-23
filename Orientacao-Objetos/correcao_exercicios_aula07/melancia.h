#ifndef MELANCIA_H
#define MELANCIA_H

#include "fruta.h"

using namespace std;

class Melancia: public Fruta {
    private:
        double preco_adicional;
        bool estacao;
    public:
        Melancia(double preco, double preco_adicional, bool estacao);
        double get_preco_adicional() const;
        void set_preco_adicional(double preco_adicional);
        bool eh_estacao() const;
        void set_estacao(bool estacao);
        double calcula_preco_final();
};

#endif
