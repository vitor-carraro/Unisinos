#include<iostream>

#include "Competicao.h"

using namespace std;

Competicao::Competicao(string nome, Data data) : data(data){
    this->nome = nome;
    this->data = data;
}

void Competicao::SetNome(string nome){
    this->nome = nome;
}

void Competicao::SetData(Data data){
    this->data = data;
}

string Competicao::GetNome(){
    return nome;
}

Data Competicao::GetData(){
    return data;
}

void Competicao::imprime_data(){
    data.imprime_data();
}