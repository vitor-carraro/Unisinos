#ifndef Calculadora_H
#define Calculadora_H

using namespace std;

class Calculadora
{
private:
    int memoria;
    string cor;
public:
    Calculadora(string cor);
    void SetMemoria(int memoria);
    int GetMemoria();
    void SetCor(string cor);
    string GetCor();
    float Soma(float x, float y);
    float Subtrai(float x, float y);
    float Multiplica(float x, float y);
    float Divide(float x, float y);
    int eleva_ao_quadrado(int x);
    int eleva_ao_cubo(int x);
    void imprime_info();
};

#endif

