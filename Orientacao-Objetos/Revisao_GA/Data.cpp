#include <iostream>

#include "Data.h"

using namespace std;

Data::Data(int dia, int mes, int ano)
{
    this ->dia = dia;
    this ->mes = mes;
    this ->ano = ano;
}

void Data::SetDia(int dia){
    this->dia = dia;
}

void Data::SetMes(int mes){
    this->mes = mes;
}

void Data::SetAno(int ano){
    this->ano = ano;
}

int Data::GetDia(){
    return dia;
}

int Data::GetMes(){
    return mes;
}

int Data::GetAno(){
    return ano;
}

void Data::imprime_data(){
    cout << dia << "/" << mes << "/" << ano;
}
