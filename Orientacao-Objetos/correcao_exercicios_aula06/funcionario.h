#ifndef FUNCIONARIO_H
#define FUNCIONARIO_H

#include "calculadora.h"

using namespace std;

class FuncionarioCaixa {
    private:
        string nome;
        string endereco;
        Calculadora calculadora;
    public:
        FuncionarioCaixa(string nome, string endereco, Calculadora calculadora);
        string get_nome();
        void set_nome(string nome);
        string get_endereco();
        void set_endereco(string endereco);
        Calculadora get_calculadora();
        void set_calculadora(Calculadora calculadora);
        float soma(float valor1, float valor2);
        float subtrai(float valor1, float valor2);
        float multiplica(float valor1, float valor2);
        float divide(float valor1, float valor2);
        int eleva_ao_quadrado(int valor);
        int eleva_ao_cubo(int valor);
        void imprime_info();
};

#endif
