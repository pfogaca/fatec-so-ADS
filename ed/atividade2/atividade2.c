/******************************************************************************

                            Online C Compiler.
                Code, Compile, Run and Debug C program online.
Write your code in this editor and press "Run" button to compile and execute it.

*******************************************************************************/
// atividade2.c
//Paulo Sergio Muller Fogaca
//Jorge de Assuncao Gomes

#include <stdio.h>
#include <stdlib.h>
#include <conio.h>

typedef struct regLista
{
    int valor;
    struct regLista *prox;
} regLista;

//
// acrescenta um item ao fim da lista retorna o indice deste item
//
int acrescentar(regLista *inicio, int valor) {
    regLista *aux, *ant;
    
    aux = (regLista *) malloc(sizeof(regLista));
    aux->valor = valor;

    if (inicio == NULL) {
        inicio = aux;
        return 0;
    } else {
        int indice = 0;
        ant = inicio;
        while (ant->prox != NULL) { indice++; ant = ant->prox; }
        ant->prox = aux;
        return indice;
    }
}

//
// insere um item no indice especificado lista retorna o indice deste item;
// se o indice for maior que o tamanho da lista, o valor é acrescentado ao fim.
//
int inserir(regLista *inicio, int indice, int valor) {
    regLista *aux, *ant;
    
    aux = (regLista *) malloc(sizeof(regLista));
    aux->valor = valor;

    if (inicio == NULL) {
        inicio = aux;
        return 0;
    } else {
        int pos = 0;
        ant = inicio;

        while (ant->prox != NULL && pos < indice) { pos++; ant = ant->prox; }
        if (ant->prox != NULL) { aux->prox = ant->prox; }
        ant->prox = aux;

        return pos;
    }
}

//
// retorna o valor to item no indice especificado, e -1 se a lista estiver
// vazia ou se o indice estiver fora da faixa.
//
int consultar(regLista *inicio, int indice) {
    regLista *ant;

    if (inicio == NULL || indice < 0) {
        return -1;
    } else if (indice == 0) {
        return inicio ->valor;
    } else {
        int pos = 0;
        ant = inicio;

        while (ant->prox != NULL && pos < indice) {
            pos++;
            ant = ant->prox;
        }

        return ant->valor;
    }
}

//
// retorna o número de itens na lista especificada.
//
int comprimento(regLista *inicio) {
    regLista *ant;

    if (inicio == NULL) {
        return 0;
    } else {
        int pos = 1;
        ant = inicio;

        while (ant->prox != NULL) { pos++; ant = ant->prox; }
        return pos;
    }
}


int main()
{
    int numero;
    regLista *inicio, *aux, *ant;

    inicio = NULL;

    while (1)
    {
        printf("Informe o número");
        scanf("%d", &numero);

        if (numero < 0) {
            break;
        }

        aux = (regLista *) malloc(sizeof(regLista));

        aux->valor = numero;
        aux->prox = NULL;

        if (inicio == NULL) {
            inicio = aux;
        } else {
            ant->prox = aux;
        }

        ant = aux;
    }

    printf("\n\nComprimento da lista: %d\n", comprimento(inicio));
    printf("\n\nItem 3 da lista: %d\n", consultar(inicio, 3));

    // printf("\n\n\nConteudo da lista:\n");

    // aux = inicio;
    // while (aux != NULL) {
    //     printf("%d\n", aux->valor);

    //     aux = aux->prox;
    // }

    return 0;
}
