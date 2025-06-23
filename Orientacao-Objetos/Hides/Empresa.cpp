#include <iostream>

#include "FuncionarioCaixa.h"
#include "Empresa.h"

using namespace std;

Empresa::Empresa(string nome, FuncionarioCaixa funcionario1, FuncionarioCaixa funcionario2) : funcionario1(funcionario1), funcionario2(funcionario2)
{
    this->nome = nome;
    this->funcionario1 = funcionario1;
    this->funcionario2 = funcionario1;
}

string Empresa::SetNome(string nome)
{
    this->nome = nome;
}

FuncionarioCaixa Empresa::SetFuncionario1(FuncionarioCaixa funcionario1)
{
    this->funcionario1 = funcionario1;
}

FuncionarioCaixa Empresa::SetFuncionario2(FuncionarioCaixa funcionario2)
{
    this->funcionario2 = funcionario2;
}

string Empresa::GetNome()
{
    return nome;
}

FuncionarioCaixa Empresa::GetFuncionario1()
{
    return funcionario1;
}

FuncionarioCaixa Empresa::GetFuncionario2()
{
    return funcionario2;
}

void Empresa::ImprimeInfo()
{
    cout << "Nome da empresa: " << GetNome() << endl;
    GetFuncionario1().imprime_info();
    GetFuncionario2().imprime_info();
}




