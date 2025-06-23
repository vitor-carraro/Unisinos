#ifndef CORREDOR_H
#define CORREDOR_H

#include "atleta.h"
#include "competicao.h"

using namespace std;

class Corredor: public Atleta {
    private:
        double peso;
        Competicao competicao;
    public:
        Corredor(string nome, int idade, double peso, Competicao competicao);
        Corredor() = default;
        double get_peso() const;
        void set_peso(double peso);
        Competicao get_competicao() const;
        void set_competicao(Competicao competicao);
        void imprime_competicao();
        void imprime_info();
};

#endif
