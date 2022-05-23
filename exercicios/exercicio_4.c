#include "exercicio_4.h"
#include <stdio.h>
#include <stdlib.h>

void mostrarItinerario(int *vet, int tam){
    int i;
    for(i = 0; i<tam; i++){
        printf("%d ", vet[i]);
    }
    printf("\n");
}

void mostrarMatriz(int **matriz, int n_cidades) {
    int i, j;
    for (i = 0; i < n_cidades; i++){
        for (j = 0; j < n_cidades; j++) {
            printf("%d ", matriz[i][j]);
        }
        printf("\n");
    }

    printf("\n");
}

int * criarItinerario(int t_itinerario, int n_cidades){
    int i, *itinerario;
    itinerario = malloc(t_itinerario * sizeof (int));
    if(itinerario){
        for(i = 0; i<t_itinerario; i++){
            itinerario[i] = rand() %n_cidades;
        }
    }
    mostrarItinerario(itinerario, t_itinerario);
    return itinerario;
}

int * alocaMatriz(int n_cidades){
    int i, j, valor, **precos;
    precos = malloc (n_cidades * sizeof (int*));
    for (i=0; i < n_cidades; i++)
        precos[i] = malloc (n_cidades * sizeof (int)) ;

    for (i=0; i < n_cidades; i++) {
        for (j = 0; j < n_cidades; j++) {
            printf("Digite o valor para a viagem entre %d e %d", i, j);
            scanf("%d", &valor);
            precos[i][j] = valor;
        }
    }

    return precos;
}

int custo_cidades (int* cidades, int n_cidades, int** m){
    int i, total;
    for(i = 0; i<n_cidades; i++){
        if(i+1 == n_cidades)
            break;
        printf("De %d para %d \n", cidades[i], cidades[i+1]);
        printf("valor = %d \n", m[cidades[i]][cidades[i+1]]);
        total += m[cidades[i]][cidades[i+1]];
    }
    return total;
}

int exercicio_4(){
    int i, total, *itinerario, t_itinerario, n_cidades, **m;

    //Criar tabela de precos
    printf("Digite o numero de cidades");
    scanf("%d", &n_cidades);
    m = alocaMatriz(n_cidades);
    mostrarMatriz(m, n_cidades);

    //Criar o itinerario
    printf("Digite o numero de viagens a ser feita");
    scanf("%d", &t_itinerario);
    printf("O itinerario eh: \n");
    itinerario = criarItinerario(t_itinerario, n_cidades);

    //Calcular o custo
    total = custo_cidades(itinerario, t_itinerario, m);
    printf("O total eh %d", total);

    return 0;
}