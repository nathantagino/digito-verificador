#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <locale.h>

// Função para calcular a soma dos dï¿½gitos de uma string
int soma_digitos(const char *codigo) {
    int soma = 0;
    for (int i = 0; codigo[i] != '\0'; i++) {
        if (isdigit(codigo[i])) {
            soma += codigo[i] - '0';
        }
    }
    return soma;
}

int main() {
	setlocale(LC_ALL, "Portuguese");
    char codigo[100];  // Buffer para armazenar o código de inscriï¿½ï¿½o do usuï¿½rio
    char verificador[100];  // Buffer para armazenar o cï¿½digo verificador

    printf("Digite o cï¿½digo de inscriï¿½ï¿½o: ");
    scanf("%s", codigo);

    int len = strlen(codigo);

    // Gerar o cï¿½digo verificador espelhando o cï¿½digo original
    for (int i = 0; i < len; i++) {
        verificador[i] = codigo[len - 1 - i];
    }
    verificador[len] = '\0';  // Adicionar o terminador de string

    // Calcular as somas dos dï¿½gitos
    int soma_codigo = soma_digitos(codigo);
    int soma_verificador = soma_digitos(verificador);

    // Exibir o cï¿½digo de inscriï¿½ï¿½o original e o cï¿½digo verificador
    printf("Cï¿½digo original: %s\n", codigo);
    printf("Cï¿½digo verificador: %s\n", verificador);

    // Exibir as somas dos dï¿½gitos
    printf("Soma dos dï¿½gitos do cï¿½digo original: %d\n", soma_codigo);
    printf("Soma dos dï¿½gitos do cï¿½digo verificador: %d\n", soma_verificador);

    // Verificar se as somas sï¿½o iguais
    if (soma_codigo == soma_verificador) {
        printf("Resultado: Vï¿½lido\n");
    } else {
        printf("Resultado: Invï¿½lido\n");
    }

    return 0;
}

