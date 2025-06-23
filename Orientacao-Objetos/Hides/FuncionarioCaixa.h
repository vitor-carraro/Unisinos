#ifndef FUNCIONARIOCAIXA_H
#define FUNCIONARIOCAIXA_H

#include "Calculadora.h" 

using namespace std;

class FuncionarioCaixa
{
private:
    string nome;
    string endereco;
    Calculadora calculadora;
public:
    FuncionarioCaixa(string nome, string endereco, Calculadora calculadora);
    string GetNome();
    string GetEndereco();
    Calculadora GetCalculadora();
    void SetNome(string nome);
    void SetEndereco(string endereco);
    void SetCalculadora(Calculadora calculadora);
    float Soma(float x, float y);
    float Subtrai(float x, float y);
    float Multiplica(float x, float y);
    float Divide(float x, float y);
    int eleva_ao_quadrado(int x);
    int eleva_ao_cubo(int x);
    void imprime_info();
};

#endif




