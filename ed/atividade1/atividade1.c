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
int fim = -1;
typedef hospede hotel[MAX_HOSPEDES];

void mostrarMenu();
void erroMensagem();
void maisPesado(hotel pessoa);
void menosPesado(hotel pessoa);
void mostrarPessoa(hotel pessoa);
hotel inserirPessoa(hotel pessoa);
hotel removerPessoa(hotel pessoa);
void numeroPessoas(hotel pessoa);
void listarPessoas(hotel pessoa);

int main() {
	hotel pessoa;
	char opMenu;
	
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
                pessoa = inserirPessoa(pessoa);
                break;
            case 53:
                pessoa = removerPessoa(pessoa);
                break;
            case 54:
                numeroPessoas(pessoa);
                break;
            case 55:
                listarPessoas(pessoa);
                break;
            default:    
		        erroMensagem();
        }
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
        for (int i=0; i<fim; i++) {
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
        for (int i=0; i<fim; i++) {
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
    int codigoDig;
    printf("3 - Consulta pessoa\n");
	printf("Digite o codigo da pessoa procurada");
    scanf("%d", &codigoDig);
    
    if (fim == -1) {
        printf("Nao ha pessoas cadastradas.");
    }
    else {
        int encontrada = -1;

        for (int i=0; i<fim; i++) {
            if (pessoa[i].codigo == codigoDig) {
                i = fim;
                encontrada = i;
            }
        }

        if (encontrada != -1) {
            printf("\tpeso: %f\n", pessoa[encontrada].peso);
            printf("\tcodigo: %c\n", pessoa[encontrada].sexo);
        } else {
            printf("Nao ha pessoas com o codigo informado.");
        }
    }

    system("pause");
}

pessoa inserirPessoa(hotel pessoa) {
    printf("4 - Inserir Pessoa\n");

    if (fim == 9) {
        printf("Nao e possivel inserir mais pessoas.");
    } else {
        int codigoDig;
        float pesoDig;
        char sexoDig;

        printf("Digite o codigo da pessoa a ser inserida: ");
        scanf("%d", &codigoDig);

        printf("Digite o codigo da pessoa a ser inserida: ");
        scanf("%d", &pesoDig);

        printf("Digite o codigo da pessoa a ser inserida: ");
        sexoDig = getch();

        fim++;

        pessoa[fim].codigo = codigoDig;
        pessoa[fim].peso = pesoDig;
        pessoa[fim].sexo = sexoDig;

        printf("\n\n###PESSOA INSERIDA###");
    }

    system("pause");

    return pessoa;
}

hotel removerPessoa(hotel pessoa) {
    printf("5 - remover Pessoa\n");

    int codigoDig, encontrada = -1;
    
    if (fim == -1) {
        printf("Nao ha pessoas cadastradas.");
    } else {
        int encontrada = -1;
        printf("Digite o codigo da pessoa a ser removida: ");
        scanf("%d", &codigoDig);

        for (int i = 0; i <= fim; i++) {
            if (pessoa[i].codigo == codigoDig) {
                encontrada = i;
                break;
            }
        }

        if (encontrada != -1) {
            for (int i = encontrada; i < fim; i++) {
                pessoa[i].codigo = pessoa[i + 1].codigo;
                pessoa[i].peso = pessoa[i + 1].peso;
                pessoa[i].sexo = pessoa[i + 1].sexo;
            }
            pessoa[fim].codigo = NULL;
            pessoa[fim].peso = NULL;
            pessoa[fim].sexo = NULL;

            fim--;

            printf("\n\n###PESSOA REMOVIDA###");
        } else {
            printf("Nao ha pessoas com o codigo informado.");
        }
    }

    system("pause");

    return pessoa;
}

void numeroPessoas(hotel pessoa) {
    printf("6 - Numero de Pessoas\n");
    
    if (fim == -1) {
        printf("Nao ha pessoas cadastradas.");
    } else {
        printf("\n\nExistem %d pessoa(s) cadastrada(s).", (fim + 1));
    }

    system("pause");
}

void listarPessoas(hotel pessoa) {
    printf("7 - Mostrar Pessoas\n");

    if (fim == -1) {
        printf("Nao ha pessoas cadastradas.");
    } else {
        printf("\n###LISTA DE PESSOAS###");
        for (int i = 0; i <= fim; i++) {
            printf("\tcodigo: %d\n", pessoa[i].codigo);
            printf("\tpeso: %f\n", pessoa[i].peso);
            printf("\tcodigo: %c\n", pessoa[i].sexo);
        }
        printf("###      FIM       ###");
    }

    system("pause");
}
