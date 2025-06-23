#ifndef COMPETICAO_H
#define COMPETICAO_H
#include "data.h"

using namespace std;

class Competicao {
    private:
        string nome;
        Data data;
    public:
        Competicao(string nome, Data data);
        Competicao() = default;
        string get_nome() const;
        void set_nome(string nome);
        Data get_data() const;
        void set_data(Data data);
        void imprime_data();
};

#endif
