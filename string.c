/*Pe�a ao usu�rio para inserir seu nome completo (utilizando a fun��o fgets()).
Exiba uma mensagem cumprimentando o usu�rio, incluindo seu nome.
Conte o n�mero de caracteres no nome (desconsidere o caractere de nova linha que � lido pela fgets()).
Exiba o n�mero de caracteres do nome do usu�rio.
Exiba o nome do usu�rio em letras mai�sculas.*/

#include <stdio.h>
#include <string.h>
#include <locale.h>

void pedir_nome(char *nome, int size){
	printf("Digite seu nome completo: ");
	fgets(nome, size, stdin);
	printf("Ol�, %s", nome);
}

int main(){
	setlocale(LC_ALL, "Portuguese_Brazil");
	
	char nome[2];
	
	pedir_nome(nome, sizeof(nome));

	return 0;
}
