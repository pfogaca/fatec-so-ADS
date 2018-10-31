// atividade2.c
//Paulo Sergio Muller Fogaca
//Jorge de Assuncao Gomes

#include <stdio.h>
#include <stdlib.h>
#include <conio.h>

struct regLista
{
    int valor;
    struct regLista *prox;
};

int main()
{
    int numero;
    struct regLista *inicio, *aux, *ant;

    inicio = NULL;

    while (1)
    {
        printf("Informe o número");
        scanf("%d", &numero);

        if (numero < 0) {
            break
        }

        aux = (struct regLista *) malloc(sizeof(struct regLista));

        aux->valor = numero;
        aux->prox = NULL;

        if (inicio == NULL) {
            inicio = aux;
        } else {
            ant->prox;
        }

        ant = aux;
    }

    printf("\n\n\nConteudo da lista:\n");

    aux = inicio;
    while (aux != NULL) {
        printf("%d\n", aux->valor);

        aux = aux->prox;
    }

    return 0;
}
