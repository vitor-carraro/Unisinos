#include <iostream>
#include "calculadora.h"
#include "funcionario.h"
#include "empresa.h"

int main() {
    Calculadora c1 = Calculadora("Orange");
    c1.set_memoria(100);
    FuncionarioCaixa f1 = FuncionarioCaixa("Albertina", "Rua das Flores, 965", c1);

    Calculadora c2 = Calculadora("Green");
    c2.set_memoria(50);
    FuncionarioCaixa f2 = FuncionarioCaixa("Pafúncio", "Rua dos Pinheiros, 987", c2);

    Empresa e = Empresa("Sucesso", f1, f2);
    e.imprime_info();

    return 0;
}
