//
// Created by Alexandre on 5/22/2022.
//

#include "exercicio_1.h"
#include <stdio.h>
#include <stdlib.h>

int * criaVetor(int tam, int lim){
    int i, *vet;
    vet = malloc(tam * sizeof (int));
    if(vet){
        for(i = 0; i<tam; i++){
            *(vet+i) = rand() %lim;
        }
    }
    return vet;
}

int * expandeVetor(int *v, int tam, int n, int lim){
    int *vet, i;
    vet = realloc(v, tam);
    if(vet){
        for(i = n; i<tam; i++){
            *(vet+i) = rand() %lim;
        }
    }
    return vet;
}

int exercicio_1(){
    int *vetor, tam, lim, i;

    printf("Digite o tamanho do vetor");
    scanf("%d", &tam);
    printf("Digite o limite dos valores");
    scanf("%d", &lim);
    vetor = criaVetor(tam, lim);
    for(i = 0; i<tam; i++){
        printf("%d ", vetor[i]);
    }

    printf("Digite o novo tamanho do vetor");
    scanf("%d", &tam);
    vetor = expandeVetor(vetor, tam, i, lim);
    for(i = 0; i<tam; i++){
        printf("%d ", vetor[i]);
    }


    return 0;
}



