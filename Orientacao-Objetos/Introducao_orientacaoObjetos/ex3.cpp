#include <iostream>

using namespace std;

class Mochila{

    public:
        Mochila(double _largura, double _comprimento, double _altura, string _nome, bool _temComputador);
        void imprime_info();
        double calcularVolume(double largura, double comprimento, double altura);

    private:
        double largura;
        int comprimento;
        int altura;
        string nome;
        bool temComputador;
};

Mochila::Mochila(double _largura, double _comprimento, double _altura, string _nome, bool _temComputador){
            largura = _largura;
            comprimento = _comprimento;
            altura = _altura;
            nome = _nome;
            temComputador = _temComputador;
        }

void Mochila::imprime_info()
{
    cout << "nome: " << nome << endl;
    cout << "largura: " << largura << endl;
    cout << "altura: " << altura << endl;
    cout << "comprimento: " << comprimento << endl;
    cout << "comprimento: " << calcularVolume(largura, altura, comprimento) << endl;
    if(temComputador){
        cout << "Tem computador na mochila tenha cuidado!" << endl << endl;
    }else{
        cout << "Não tem computador na mochila" << endl << endl;
    }
}

double Mochila::calcularVolume(double largura, double comprimento, double altura)
{
    double volume = largura * comprimento * altura;
    return volume;
}

int main(){

    Mochila M1(3.3, 4.2, 1.0, "mochila vitor", true);
    Mochila M2(3.8, 2.2, 4.8, "mochila barbara", false);
    Mochila M3(3.9, 4.1, 4.5, "mochila pedro", false);

    M1.imprime_info();
    M2.imprime_info();
    M3.imprime_info();
    
}


