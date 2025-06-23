#include <iostream>
#include "empresa.h"
#include "funcionario.h"

Empresa::Empresa(string nome, FuncionarioCaixa f1, FuncionarioCaixa f2): f1(f1), f2(f2) {
    this->nome = nome;
}

string Empresa::get_nome() {
    return this->nome;
}

void Empresa::set_nome(string nome) {
    this->nome = nome;
}

FuncionarioCaixa Empresa::get_f1() {
    return this->f1;
}

void Empresa::set_f1(FuncionarioCaixa f1) {
    this->f1 = f1;
}

FuncionarioCaixa Empresa::get_f2() {
    return this->f2;
}

void Empresa::set_f2(FuncionarioCaixa f2) {
    this->f2 = f2;
}

void Empresa::imprime_info() {
    cout << "======== EMPRESA: " << get_nome() << " ========" << endl;
    cout << "PRIMEIRO FUNCIONÁRIO" << endl;
    f1.imprime_info(); 
    cout << "\nSEGUNDO FUNCIONÁRIO" << endl;
    f2.imprime_info();
}

