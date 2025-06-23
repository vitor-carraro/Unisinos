#ifndef DATA_H
#define DATA_H

using namespace std;

class Data
{
private:
    int dia;
    int mes;
    int ano;
public:
    Data(int dia, int mes, int ano);
    void SetDia(int dia);
    void SetMes(int mes);
    void SetAno(int ano);
    int GetDia();
    int GetMes();
    int GetAno();
    void imprime_data();
};

#endif
