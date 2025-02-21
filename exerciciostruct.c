#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

struct Pessoa {
    char nome[20];
    char cpf[12];  
    int idade;
};

int validarCPF(const char *cpf) {
	
    if (strlen(cpf) != 11) {
        return 0;
    }
    
    for (int i = 0; i < 11; i++) {
        if (!isdigit(cpf[i])) {
            return 0;
        }
    }

    return 1;  
}

int validarIdade(int idade) {
    return idade >= 0 && idade <= 120;  
}

void preencherPessoas(struct Pessoa *pessoas) {
    for (int i = 0; i < 5; i++) {
        printf("\n Digite o nome da pessoa %d: ", i + 1);
        scanf("%19s", pessoas[i].nome); 

        do {
            printf("\n Digite o CPF da pessoa %d (apenas numeros): ", i + 1);
            scanf("%11s", pessoas[i].cpf);  

            if (!validarCPF(pessoas[i].cpf)) {
                printf("CPF inválido, tente novamente.\n");
            }
        } while (!validarCPF(pessoas[i].cpf));  

        do {
            printf("\n Digite a idade da pessoa %d (0 a 120): ", i + 1);
            scanf("%d", &pessoas[i].idade);

            if (!validarIdade(pessoas[i].idade)) {
                printf("Idade inválida, tente novamente: \n");
            }
        } while (!validarIdade(pessoas[i].idade)); 

        printf("\n");
    }
}

	void imprimirPessoas(struct Pessoa *pessoas) {
    for (int i = 0; i < 5; i++) {
        printf("Cadastro da pessoa %d:\n", i + 1);
        printf("Nome: %s\n", pessoas[i].nome);
        printf("CPF: %s\n", pessoas[i].cpf);
        printf("Idade: %d\n", pessoas[i].idade);
        printf("\n");
    }
}

int main() {
    struct Pessoa *pessoas;

    pessoas = (struct Pessoa *)malloc(5 * sizeof(struct Pessoa));

    if (pessoas == NULL) {
        printf("Erro de alocação de memória\n");
        return 1;
    }

    preencherPessoas(pessoas);
    imprimirPessoas(pessoas);

    free(pessoas);

    return 0;
}
