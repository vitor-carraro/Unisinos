#include <stdio.h>

#define TAM_MAX 10

void main() {

    int vetor[TAM_MAX], *pvet = NULL;

    pvet = vetor;

    for(int i = 0; i < TAM_MAX; i++, pvet++){
        printf("Posição [%d]: ", i);
        scanf("%d", pvet);
        *pvet = *pvet * 10;
    }

    pvet = vetor;

    for(int i = 0; i < TAM_MAX; i++, pvet++){
        printf("Valor final posição [%d]: %d\n", i, *pvet);
    }
    
   
}

