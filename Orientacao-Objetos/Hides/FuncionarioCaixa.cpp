#include <iostream>

#include "FuncionarioCaixa.h"
#include "Calculadora.h"

using namespace std;

FuncionarioCaixa::FuncionarioCaixa(string nome, string endereco, Calculadora calculadora): calculadora(calculadora)
{
    this->nome = nome;
    this->endereco = endereco;
    this->calculadora = calculadora;
}

string FuncionarioCaixa::GetNome()
{
    return nome;
}

string FuncionarioCaixa::GetEndereco()
{
    return endereco;
}

Calculadora FuncionarioCaixa::GetCalculadora()
{
    return calculadora;
}

void FuncionarioCaixa::SetNome(string nome)
{
    this->nome = nome;
}

void FuncionarioCaixa::SetEndereco(string endereco)
{
    this->endereco = endereco;
}

void FuncionarioCaixa::SetCalculadora(Calculadora calculadora)
{
    this->calculadora = calculadora;
}

float FuncionarioCaixa::Soma(float x, float y)
{
    return calculadora.Soma(x,y);
}

float FuncionarioCaixa::Subtrai(float x, float y)
{
    return calculadora.Subtrai(x,y);
}

float FuncionarioCaixa::Multiplica(float x, float y)
{
    return calculadora.Multiplica(x,y);
}

float FuncionarioCaixa::Divide(float x, float y)
{
    return calculadora.Divide(x,y);
}

int FuncionarioCaixa::eleva_ao_quadrado(int x)
{
    return calculadora.eleva_ao_quadrado(x);
}

int FuncionarioCaixa::eleva_ao_cubo(int x)
{
    return calculadora.eleva_ao_cubo(x);
}

void FuncionarioCaixa::imprime_info()
{
    cout << "Nome: " << GetNome() << endl;
    cout << "Endereço: " << GetEndereco() << endl;
    GetCalculadora().imprime_info();
}
