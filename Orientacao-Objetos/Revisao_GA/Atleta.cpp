#include<iostream>

#include "Atleta.h"

using namespace std;

Atleta::Atleta(string nome, int idade){
    this->nome = nome;
    this->idade = idade;
}

void Atleta::SetNome(string nome){
    this->nome = nome;
}

void Atleta::SetIdade(int idade){
    this->idade = idade;
}

string Atleta::GetNome(){
    return nome;
}

int Atleta::GetIdade(){
    return idade;
}

void Atleta::imprime_info(){
    cout << "O nome do atleta é: " << nome << endl;
    cout << "A idade do atleta é: " << idade << endl;
}