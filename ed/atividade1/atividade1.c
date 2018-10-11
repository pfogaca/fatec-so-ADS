/******************************************************************************

                            Online C Compiler.
                Code, Compile, Run and Debug C program online.
Write your code in this editor and press "Run" button to compile and execute it.

*******************************************************************************/

#include <stdio.h>
#include <stdlib.h>
#include <conio.h>

//Paulo Sergio Muller Fogaca
//Jorge de Assuncao Gomes

#define MAX_HOSPEDES 10

typedef struct {
	int codigo;
	float peso;
	char sexo;
} hospede;

typedef hospede hotel[MAX_HOSPEDES];

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

	printf("###ATENCAO###\n");
    printf("Opcao invalida\n");
    printf("Tecle Enter para tentar novamente\n");
    system("pause");
}

void maisPesado(hotel *pessoa, int *fim) {
    printf("1 - Pessoa mais pesada\n");
    if (*fim == -1) {
        printf("Nao ha nenhuma pessoa no momento.");
    }
    else {
        float pesoMinimo = -1.0f;
        int indice;
        for (int i=0; i<*fim; i++) {
            if (pessoa[i]->peso > pesoMinimo) {
                pesoMinimo = pessoa[i]->peso;
                indice = i;
            }
        }
        printf("1 - Pessoa mais pesada\n");
        printf("\tcodigo: %d\n", pessoa[indice]->codigo);
        printf("\tpeso: %f\n", pessoa[indice]->peso);
        printf("\tcodigo: %c\n", pessoa[indice]->sexo);
    }
    system("pause");
}

void menosPesado(hotel *pessoa, int *fim) {
    printf("2 - Pessoa menos pesada\n");
    if (*fim == -1) {
        printf("Nao ha nenhuma pessoa no momento.");
    }
    else {
        float pesoMinimo = -1.0f;
        int indice;
        for (int i=0; i<*fim; i++) {
            if (pessoa[i]->peso > pesoMinimo) {
                pesoMinimo = pessoa[i]->peso;
                indice = i;
            }
        }
        printf("2 - Pessoa menos pesada\n");
        printf("\tcodigo: %d\n", pessoa[indice]->codigo);
        printf("\tpeso: %f\n", pessoa[indice]->peso);
        printf("\tcodigo: %c\n", pessoa[indice]->sexo);
    }
    system("pause");
}

void mostrarPessoa(hotel *pessoa, int *fim) {
    int codigoDig;
    printf("3 - Consulta pessoa\n");
	printf("Digite o codigo da pessoa procurada");
    scanf("%d", &codigoDig);

    if (*fim == -1) {
        printf("Nao ha pessoas cadastradas.");
    }
    else {
        int encontrada = -1;

        for (int i=0; i<*fim; i++) {
            if (pessoa[i]->codigo == codigoDig) {
                i = *fim;
                encontrada = i;
            }
        }

        if (encontrada != -1) {
            printf("\tpeso: %f\n", pessoa[encontrada]->peso);
            printf("\tcodigo: %c\n", pessoa[encontrada]->sexo);
        } else {
            printf("Nao ha pessoas com o codigo informado.");
        }
    }

    system("pause");
}

void inserirPessoa(hotel *pessoa, int *fim) {
    printf("4 - Inserir Pessoa\n");

    if (*fim == 9) {
        printf("Nao e possivel inserir mais pessoas.");
    } else {
        int codigoDig;
        float pesoDig;
        char sexoDig;

        printf("Digite o codigo da pessoa a ser inserida: ");
        scanf("%i", &codigoDig);

        printf("Digite o peso da pessoa a ser inserida: ");
        scanf("%f", &pesoDig);

        printf("Digite o sexo da pessoa a ser inserida: ");
        sexoDig = getch();

        *fim = *fim + 1;

        pessoa[*fim]->codigo = codigoDig;
        pessoa[*fim]->peso = pesoDig;
        pessoa[*fim]->sexo = sexoDig;

        printf("\n\n###PESSOA INSERIDA###");
    }

    system("pause");
}

void removerPessoa(hotel *pessoa, int *fim) {
    printf("5 - remover Pessoa\n");

    int codigoDig, encontrada = -1;

    hotel retorno;

    if (*fim == -1) {
        printf("Nao ha pessoas cadastradas.");
    } else {
        printf("Digite o codigo da pessoa a ser removida: ");
        scanf("%d", &codigoDig);

        for (int i = 0; i <= *fim; i++) {
            if (pessoa[i]->codigo == codigoDig) {
                encontrada = i;
                break;
            }
        }

        if (encontrada != -1) {
            for (int i = encontrada; i < *fim; i++) {
                pessoa[i]->codigo = pessoa[i + 1]->codigo;
                pessoa[i]->peso = pessoa[i + 1]->peso;
                pessoa[i]->sexo = pessoa[i + 1]->sexo;
            }
            pessoa[*fim]->codigo = 0;
            pessoa[*fim]->peso = 0;
            pessoa[*fim]->sexo = '\0';

            *fim = *fim - 1;

            printf("\n\n###PESSOA REMOVIDA###");
        } else {
            printf("Nao ha pessoas com o codigo informado.");
        }
    }

    system("pause");
}

void numeroPessoas(hotel *pessoa, int *fim) {
    printf("6 - Numero de Pessoas\n");

    if (*fim == -1) {
        printf("Nao ha pessoas cadastradas.");
    } else {
        printf("\n\nExistem %d pessoa(s) cadastrada(s).", (*fim + 1));
    }

    system("pause");
}

void listarPessoas(hotel *pessoa, int *fim) {
    printf("7 - Mostrar Pessoas\n");

    if (*fim == -1) {
        printf("Nao ha pessoas cadastradas.");
    } else {
        printf("\n###LISTA DE PESSOAS###");
        for (int i = 0; i <= *fim; i++) {
            printf("\tcodigo: %d\n", pessoa[i]->codigo);
            printf("\tpeso: %f\n", pessoa[i]->peso);
            printf("\tcodigo: %c\n", pessoa[i]->sexo);
        }
        printf("###      FIM       ###");
    }

    system("pause");
}


int main() {
	hotel pessoa;
	int opMenu;
    int fim = -1;

	do {
		mostrarMenu();
		scanf("%i", &opMenu);
        switch(opMenu)
        {
            case 1:
                maisPesado(&pessoa, &fim);
                break;
            case 2:
                menosPesado(&pessoa, &fim);
                break;
            case 3:
                mostrarPessoa(&pessoa, &fim);
                break;
            case 4:
                inserirPessoa(&pessoa, &fim);
                break;
            case 5:
                removerPessoa(&pessoa, &fim);
                break;
            case 6:
                numeroPessoas(&pessoa, &fim);
                break;
            case 7:
                listarPessoas(&pessoa, &fim);
                break;
            default:
		        erroMensagem();
        }
	} while (opMenu != 8);

	printf("###FINALIZANDO###\n");
    system("pause");

	return 0;
}
