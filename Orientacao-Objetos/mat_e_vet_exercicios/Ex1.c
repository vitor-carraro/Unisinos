#include<stdio.h>
#define TAM_MAX 11

int main (){

int g[TAM_MAX], g2[TAM_MAX], g3[TAM_MAX], g4[TAM_MAX];

for (int i = 0, n1 = 10; i < TAM_MAX; i++, n1--){
    g[i] = n1;
}

for (int i = 0, valorInicial = 0, razao = 1; i < TAM_MAX; i++,razao = razao + 2){
    g2[i] = valorInicial;
    valorInicial = valorInicial + razao;
}

for(int i = 0, j = 10; i < TAM_MAX; i++){
    if (i < 5)
    {
        g3[i] = i + 1;
    }else if(i == 5){
        g3[i] = i + 5;
    }else{
        g3[i] = i + j;
        j--;
    }
    
}

for(int i = 0, valorInicial = 3, razao = 1; i < TAM_MAX; i++, razao + 2){
    g4[i] = valorInicial + razao;
}

printf("Primeiro Grupo:\n");
imprime_vetor(10, g);
printf("Segundo Grupo:\n");
imprime_vetor(11, g2);
printf("Terceiro Grupo:\n");
imprime_vetor(10, g3);
printf("Quarto Grupo:\n");
imprime_vetor(10, g4);

return 0;
}


void imprime_vetor(int tamanho, int vetor[TAM_MAX]) {

for (int i = 0; i < tamanho; i++) {

printf("%d\n", vetor[i]);

}

}
