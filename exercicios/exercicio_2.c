//
// Created by Alexandre on 5/22/2022.
//

#include "exercicio_2.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int * criaVetorDe1A10(int tam){
    int i, *vet;
    vet = malloc(tam * sizeof (int));
    if(vet){
        for(i = 0; i<tam; i++){
            vet[i] = rand() %10;
        }
    }
    return vet;
}

void mostrarVetor(int *vet, int tam){
    int i;
    for(i = 0; i<tam; i++){
        printf("%d ", vet[i]);
    }
    printf("\n");
}

int * multiplicarVetor(int *vet_1, int *vet_2, int tam_1, int tam_2){
    int i, j, p, *result;
    p=0;
    result = malloc((tam_1*tam_2) * sizeof (int));
    for(i = 0; i<tam_1; i++){
        for(j = 0; j<tam_2; j++){
            result[p] = vet_1[i]*vet_2[j];
            p++;
        }
    }
    return result;
}

int exercicio_2() {
    int *vetor_1, *vetor_2, *vetor_resultado, tam_1, tam_2, lim, i;
    printf("Digite o tamanho do vetor 1");
    scanf("%d", &tam_1);
    vetor_1 = criaVetorDe1A10(tam_1);
    mostrarVetor(vetor_1, tam_1);

    printf("Digite o tamanho do vetor 2");
    scanf("%d", &tam_2);
    vetor_2 = criaVetorDe1A10(tam_2);
    mostrarVetor(vetor_2, tam_2);

    vetor_resultado = multiplicarVetor(vetor_1, vetor_2, tam_1, tam_2);
    mostrarVetor(vetor_resultado, tam_1*tam_2);

    return 0;
}
