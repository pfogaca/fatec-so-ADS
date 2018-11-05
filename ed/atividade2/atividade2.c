// atividade2.c
//Paulo Sergio Muller Fogaca
//Jorge de Assuncao Gomes

#include <stdio.h>
#include <stdlib.h>
#include <conio.h>

typedef struct {
	int codigo;
	float peso;
	char sexo;
} hospede;

typedef struct regLista
{
    hospede *pessoa;
    struct regLista *prox;
} regLista;

void mostrarMenu() {
	system("cls");

	printf("###Digite a opcao:###\n");
    printf("#1 - Mais pesado\n");
    printf("#2 - Menos pesado\n");
    printf("#3 - Consultar pessoa\n");
    printf("#4 - Inserir pessoa\n");
    printf("#5 - Remover pessoa\n");
    printf("#6 - Numero de pessoas\n");
    printf("#7 - Mostrar pessoas\n");
    printf("#8 - Fim\n");
}

void erroMensagem() {
	system("cls");

	printf("\n\n###ATENCAO###\n");
    printf("Opcao invalida\n");
    printf("Tecle Enter para tentar novamente\n");
    system("pause");
}

void maisPesado(regLista *inicio) {
	regLista *aux, *encontrado;
	
	aux = (regLista *) malloc(sizeof(regLista));
	aux = inicio;
	
	encontrado = (regLista *) malloc(sizeof(regLista));
	
    if (aux->pessoa->codigo == 0) {
        printf("\n\nNao ha nenhuma pessoa no momento.\n\n");
    } else {
        float pesoMinimo = -1.0f;
		
		while (aux != NULL) {
			if (aux->pessoa->peso > pesoMinimo) {
                pesoMinimo = aux->pessoa->peso;
                encontrado = aux;
            }
			
			aux = aux->prox;
		}
		
        printf("1 - Pessoa mais pesada\n");
        printf("\tcodigo: %d\n", encontrado->pessoa->codigo);
        printf("\tpeso: %f\n", encontrado->pessoa->peso);
        printf("\tcodigo: %c\n", encontrado->pessoa->sexo);
    }
    system("pause");
}

void menosPesado(regLista *inicio) {
    regLista *aux, *encontrado;
	
	aux = (regLista *) malloc(sizeof(regLista));
	aux = inicio;
	
	encontrado = (regLista *) malloc(sizeof(regLista));
	
    if (aux->pessoa->codigo == 0) {
        printf("\n\nNao ha nenhuma pessoa no momento.\n\n");
    } else {
        float pesoMinimo = 100000.0f;
		
		while (aux != NULL) {
			if (aux->pessoa->peso < pesoMinimo) {
                pesoMinimo = aux->pessoa->peso;
                encontrado = aux;
            }
			
			aux = aux->prox;
		}
		
        printf("2 - Pessoa menos pesada\n");
        printf("\tcodigo: %d\n", encontrado->pessoa->codigo);
        printf("\tpeso: %f\n", encontrado->pessoa->peso);
        printf("\tcodigo: %c\n", encontrado->pessoa->sexo);
    }
    system("pause");
}

void mostrarPessoa(regLista *inicio) {
    int codigoDig;
    printf("3 - Consulta pessoa\n");
	printf("Digite o codigo da pessoa procurada: ");
    scanf("%d", &codigoDig);

	regLista *aux, *encontrado;
	
	aux = (regLista *) malloc(sizeof(regLista));
	aux = inicio;
	
	encontrado = (regLista *) malloc(sizeof(regLista));
	encontrado = NULL;
	
    if (aux->pessoa->codigo == 0) {
        printf("Nao ha pessoas cadastradas.");
    } else {
		while (aux != NULL) {
			if (aux->pessoa->codigo == codigoDig) {
                encontrado = aux;
				break;
            }
			
			aux = aux->prox;
		}

        if (encontrado != NULL) {
            printf("\tcodigo: %d\n", encontrado->pessoa->codigo);
			printf("\tpeso: %f\n", encontrado->pessoa->peso);
			printf("\tcodigo: %c\n", encontrado->pessoa->sexo);
        } else {
            printf("\n\nNao ha pessoas com o codigo informado.\n\n");
        }
    }

    system("pause");
}

void inserirPessoa(regLista *inicio) {
    printf("4 - Inserir Pessoa\n");
	
	regLista *aux, *inserido;
	hospede *inseridoPessoa;
	
	aux = (regLista *) malloc(sizeof(regLista));
	aux = inicio;

    inseridoPessoa = (hospede *) malloc(sizeof(hospede));
	
	inserido = (regLista *) malloc(sizeof(regLista));
	inserido->prox = NULL;

    int codigoDig;
    float pesoDig;
    char sexoDig;

	printf("Digite o codigo da pessoa a ser inserida: ");
	scanf("%i", &codigoDig);
    
	printf("Digite o peso da pessoa a ser inserida: ");    
	scanf("%f", &pesoDig);

    printf("Digite o sexo da pessoa a ser inserida: ");
    sexoDig = getch();

    inseridoPessoa->codigo = codigoDig;
    inseridoPessoa->peso = pesoDig;
    inseridoPessoa->sexo = sexoDig;
    
    if (aux->pessoa->codigo == 0) {
        aux->pessoa = inseridoPessoa;
    } else {
        inserido->pessoa = inseridoPessoa;
        
        while (aux->prox != NULL) {	
		    aux = aux->prox;
        }
        
        aux->prox = inserido;
	}

    printf("\n\n###PESSOA INSERIDA###\n\n");

    system("pause");
}

void removerPessoa(regLista *inicio) {
    printf("5 - remover Pessoa\n");

    int codigoDig;
    regLista *aux, *encontrado, *ant;
	
	aux = (regLista *) malloc(sizeof(regLista));
	aux = inicio;
	
	ant = (regLista *) malloc(sizeof(regLista));
	ant = inicio;
	
	encontrado = (regLista *) malloc(sizeof(regLista));
	encontrado = NULL;
	
    if (aux->pessoa->codigo == 0) {
        printf("Nao ha pessoas cadastradas.");
    } else {
		int codigoDig;
		printf("Digite o codigo da pessoa a ser removida: ");
		scanf("%d", &codigoDig);
	
		while (aux != NULL) {
			if (aux->pessoa->codigo == codigoDig) {
                encontrado = aux;
				break;
            }
			
			ant = aux;
			aux = aux->prox;
		}

        if (encontrado != NULL) {
            ant->prox = encontrado->prox;
			printf("\n\n###PESSOA REMOVIDA###\n\n");
        } else {
            printf("\n\nNao ha pessoas com o codigo informado.\n\n");
        }
    }

    system("pause");
}

void numeroPessoas(regLista *inicio) {
    printf("6 - Numero de Pessoas\n");
	
	regLista *aux;
	int numero = 0;
	
	aux = (regLista *) malloc(sizeof(regLista));
	aux = inicio;

    if (aux->pessoa->codigo == 0) {
        printf("\n\nNao ha pessoas cadastradas.\n\n");
    } else {
        while (aux != NULL) {	
		    aux = aux->prox;
		    numero++;
	    }
	    
        printf("\n\nExistem %d pessoa(s) cadastrada(s).\n\n", numero);
    }

    system("pause");
}

void listarPessoas(regLista *inicio) {
    printf("7 - Mostrar Pessoas\n");

	regLista *aux;
	int numero = 0;
	
	aux = (regLista *) malloc(sizeof(regLista));
	aux = inicio;
	
    if (aux->pessoa->codigo == 0) {
        printf("Nao ha pessoas cadastradas.");
    } else {
        printf("\n###LISTA DE PESSOAS###\n\n");
        while (aux != NULL) {	
			printf("\tcodigo: %d\n", aux->pessoa->codigo);
			printf("\tpeso: %f\n", aux->pessoa->peso);
			printf("\tcodigo: %c\n\n", aux->pessoa->sexo);
			
			aux = aux->prox;
		}
        printf("\n\n###      FIM       ###\n\n");
    }

    system("pause");
}

int main() {
	regLista inicio;
	hospede pessoaIni;
	int opMenu;
	
	pessoaIni.codigo = 0;
	pessoaIni.sexo = 0;
	pessoaIni.peso = 0;
	
	inicio.pessoa = &pessoaIni;
	inicio.prox = NULL;

	do {
		mostrarMenu();
		scanf("%i", &opMenu);
        switch(opMenu)
        {
            case 1:
                maisPesado(&inicio);
                break;
            case 2:
                menosPesado(&inicio);
                break;
            case 3:
                mostrarPessoa(&inicio);
                break;
            case 4:
                inserirPessoa(&inicio);
                break;
            case 5:
                removerPessoa(&inicio);
                break;
            case 6:
                numeroPessoas(&inicio);
                break;
            case 7:
                listarPessoas(&inicio);
                break;
            case 8:
                break;
            default:
		        erroMensagem();
		        break;
        }
	} while (opMenu != 8);

	printf("\n\n###FINALIZANDO###\n\n");
    system("pause");

	return 0;
}
