#ifndef EMPRESA_H
#define EMPRESA_H

#include "funcionario.h"

class Empresa {
    private:
        string nome;
        FuncionarioCaixa f1;
        FuncionarioCaixa f2;
    public:
        Empresa(string nome, FuncionarioCaixa f1, FuncionarioCaixa f2);
        string get_nome();
        void set_nome(string nome);
        FuncionarioCaixa get_f1();
        void set_f1(FuncionarioCaixa f1);
        FuncionarioCaixa get_f2();
        void set_f2(FuncionarioCaixa f2);
        void imprime_info();
};

#endif
