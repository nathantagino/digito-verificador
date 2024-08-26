#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <locale.h>

// Fun��o para calcular a soma dos d�gitos de uma string
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
    char codigo[100];  // Buffer para armazenar o c�digo de inscri��o do usu�rio
    char verificador[100];  // Buffer para armazenar o c�digo verificador

    printf("Digite o c�digo de inscri��o: ");
    scanf("%s", codigo);

    int len = strlen(codigo);

    // Gerar o c�digo verificador espelhando o c�digo original
    for (int i = 0; i < len; i++) {
        verificador[i] = codigo[len - 1 - i];
    }
    verificador[len] = '\0';  // Adicionar o terminador de string

    // Calcular as somas dos d�gitos
    int soma_codigo = soma_digitos(codigo);
    int soma_verificador = soma_digitos(verificador);

    // Exibir o c�digo de inscri��o original e o c�digo verificador
    printf("C�digo original: %s\n", codigo);
    printf("C�digo verificador: %s\n", verificador);

    // Exibir as somas dos d�gitos
    printf("Soma dos d�gitos do c�digo original: %d\n", soma_codigo);
    printf("Soma dos d�gitos do c�digo verificador: %d\n", soma_verificador);

    // Verificar se as somas s�o iguais
    if (soma_codigo == soma_verificador) {
        printf("Resultado: V�lido\n");
    } else {
        printf("Resultado: Inv�lido\n");
    }

    return 0;
}

