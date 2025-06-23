#include <iostream>

using namespace std;

class Pessoa{

    public:
        Pessoa(string _nome, int _idade, double _altura, int _qntIrmaos, string _endereco);
        void imprime_info();
        bool is_filho_unico();

    private:
        string nome;
        int idade;
        double altura;
        int qntIrmaos;
        string endereco;
};

Pessoa::Pessoa(string _nome, int _idade, double _altura, int _qntIrmaos, string _endereco){
            nome = _nome;
            idade = _idade;
            altura = _altura;
            qntIrmaos = _qntIrmaos;
            endereco = _endereco;
        }

void Pessoa::imprime_info()
{
    cout << "nome: " << nome << endl;
    cout << "idade: " << idade << endl;
    cout << "altura: " << altura << endl;
    cout << "qnt de irmaos: " << qntIrmaos << endl;
    cout << "endereço: " << endereco << endl;
    if(is_filho_unico()){
        cout << "Filho(a) único(a)" << endl << endl;
    }else{
        cout << "Não é filho(a) único(a)" << endl << endl;
    }
}

bool Pessoa::is_filho_unico()
{
    if (qntIrmaos < 1){
        return true;
    }
    else{
        return false;
    }
}

int main(){

    Pessoa p1("vitor", 20, 1.83, 1, "Rua dinamarca 114");
    Pessoa p2("barbara", 21, 1.60, 0, "Rua autria 114");
    Pessoa p3("pedro", 17, 1.78, 4, "Rua grecia 114");

    p1.imprime_info();
    p2.imprime_info();
    p3.imprime_info();
    
}


