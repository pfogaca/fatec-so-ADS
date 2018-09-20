#include <stdio.h>
#include <stdlib.h>
#include <conio.h>

//Paulo Sergio Muller Fogaca
//Jorge de Assuncao Gomes

#define MAX_HOSPEDES 10;

typedef struct {
	int codigo;
	float peso;
	char sexo;
} hospede;

typedef hospede hotel[MAX_HOSPEDES];

int main() {
	hotel pessoa;
	char opMenu;
	int fim;
	
	do {
		mostrarMenu();
		opMenu = getch();
        switch(opMenu)
        {
            case 49:
                maisPesado(pessoa);
                break;
            case 50:
                menosPesado(pessoa);
                break;
            case 51:
                mostrarPessoa(pessoa);
                break;
            case 52:
                inserirPessoa(pessoa);
                break;
            case 53:
                removerPessoa(pessoa);
                break;
            case 54:
                numeroPessoas(pessoa);
                break;
            case 55:
                listarPessoas(pessoa);
                break;
            default:    
				erroMensagem();
	} while (opMenu != 56);
	
	printf("###FINALIZANDO###\n");
    system("pause");
	
	return 0;
}

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

void maisPesado(hotel pessoa) {
    printf("1 - Pessoa mais pesada\n");
    if (fim == -1) {
        printf("Nao ha nenhuma pessoa no momento.");
    }
    else {
        float pesoMinimo = -1.0f;
        int indice;
        for (i=0; i<fim; i++) {
            if (pessoa[i].peso > pesoMinimo) {
                pesoMinimo = pessoa[i].peso;
                indice = i;
            }
        }
        printf("1 - Pessoa mais pesada\n");
        printf("\tcodigo: %d\n", pessoa[indice].codigo);
        printf("\tpeso: %f\n", pessoa[indice].peso);
        printf("\tcodigo: %c\n", pessoa[indice].sexo);
    }
    system("pause");
}

void menosPesado(hotel pessoa) {
    printf("2 - Pessoa menos pesada\n");
    if (fim == -1) {
        printf("Nao ha nenhuma pessoa no momento.");
    }
    else {
        float pesoMinimo = -1.0f;
        int indice;
        for (i=0; i<fim; i++) {
            if (pessoa[i].peso > pesoMinimo) {
                pesoMinimo = pessoa[i].peso;
                indice = i;
            }
        }
        printf("1 - Pessoa menos pesada\n");
        printf("\tcodigo: %d\n", pessoa[indice].codigo);
        printf("\tpeso: %f\n", pessoa[indice].peso);
        printf("\tcodigo: %c\n", pessoa[indice].sexo);
    }
    system("pause");
}

void mostrarPessoa(hotel pessoa) {
    printf("3 - Consulta pessoa\n");
    system("pause");
}

void inserirPessoa(hotel pessoa) {
    printf("4 - Inserir Pessoa\n");
    system("pause");
}

void removerPessoa(hotel pessoa) {
    printf("5 - remover Pessoa\n");
    system("pause");
}

void numeroPessoas(hotel pessoa) {
    //intf("6 - Numero de Pessoas\n;
    //system("pause");
    
}

void listarPessoas(hotel pessoa) {
    printf("7 - Mostrar Pessoas\n");
    system("pause");
}
