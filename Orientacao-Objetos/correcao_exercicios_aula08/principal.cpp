#include <iostream>
#include "atleta.h"
#include "data.h"
#include "nadador.h"
#include "corredor.h"
#include "competicao.h"
#include "info_atleta.h"

using namespace std;

int main() {
    Data data_compet(24, 11, 2024);
    Competicao compet("Correr é show", data_compet);
    compet.imprime_data();
    cout << "\n";

    Nadador n("Cielo", 36, "Borboleta");
    n.imprime_info();
    cout << "\n";

    Corredor c("Josenildo", 91, 68, compet);
    data_compet.set_dia(23);
    compet.set_data(data_compet);
    compet.imprime_data();
    c.set_competicao(compet);
    cout << "\n";

    Data data_nova_compet(31, 12, 2024);
    Competicao nova_compet("São Silvestre", data_nova_compet);
    Corredor ca("Petrolina", 100, 60, nova_compet);
    ca.imprime_info();
    cout << "\n";

    Atleta* a;
    Nadador nn;
    Corredor cn;
    int opcao;
    cout << "Informe 1 para cadastrar um nadador e 2 para cadastrar um corredor: ";
    cin >> opcao;
    string nome;
    int idade;
    if(opcao == 1) {
        string categoria;
        
        cout << "O atleta a ser cadastrado é um nadador" << endl;
        cout << "Informe o nome: ";
        cin >> nome;
        cout << "Informe a idade: ";
        cin >> idade;
        cout << "Informe a categoria: ";
        cin >> categoria;
        
        nn = Nadador(nome, idade, categoria);
        a = &nn;
    }
    else {
        double peso;
        cout << "O atleta a ser cadastrado é um corredor" << endl;
        cout << "Informe o nome: ";
        cin >> nome;
        cout << "Informe a idade: ";
        cin >> idade;
        cout << "Informe o peso: ";
        cin >> peso;

        cn = Corredor(nome, idade, peso, nova_compet);
        a = &cn;
    }

    InformacoesAtleta info;
    info.imprime_exclusivos_atleta(a);
    info.imprime_informacoes_atleta(a);

    if(Nadador* ntemp = dynamic_cast<Nadador*>(a)) {
        ntemp->set_categoria("Livre");
    }
    else if(Corredor* ctemp = dynamic_cast<Corredor*>(a)) {
        ctemp->set_peso(89.0);
    }
    info.imprime_informacoes_atleta(a);

    return 0;
}

