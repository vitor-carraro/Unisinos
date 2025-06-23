#ifndef EMPRESA_H
#define EMPRESA_H

#include "FuncionarioCaixa.h"

using namespace std;

class Empresa
{
private:
    string nome;
    FuncionarioCaixa funcionario1;
    FuncionarioCaixa funcionario2;
public:
    Empresa(string nome, FuncionarioCaixa funcionario1, FuncionarioCaixa funcionario2);
    string SetNome(string nome);
    FuncionarioCaixa SetFuncionario1(FuncionarioCaixa funcionario1);
    FuncionarioCaixa SetFuncionario2(FuncionarioCaixa funcionario2);
    string GetNome();
    FuncionarioCaixa GetFuncionario1();
    FuncionarioCaixa GetFuncionario2();
    void ImprimeInfo();

};

#endif

