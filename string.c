/*Peça ao usuário para inserir seu nome completo (utilizando a função fgets()).
Exiba uma mensagem cumprimentando o usuário, incluindo seu nome.
Conte o número de caracteres no nome (desconsidere o caractere de nova linha que é lido pela fgets()).
Exiba o número de caracteres do nome do usuário.
Exiba o nome do usuário em letras maiúsculas.*/

#include <stdio.h>
#include <string.h>
#include <locale.h>

void pedir_nome(char *nome, int size){
	printf("Digite seu nome completo: ");
	fgets(nome, size, stdin);
	printf("Olá, %s", nome);
}

int main(){
	setlocale(LC_ALL, "Portuguese_Brazil");
	
	char nome[2];
	
	pedir_nome(nome, sizeof(nome));

	return 0;
}
