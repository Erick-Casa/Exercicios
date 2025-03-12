/*Peça ao usuário para inserir duas strings.
Exiba o tamanho de ambas as strings usando função do string.h
Copie a primeira string para uma nova variável usando função do string.h
Concatene a segunda string ao final da cópia usando função do string.h
Compare as strings originais e exiba se elas são iguais ou diferentes usando função do string.h*/

#include <stdio.h>
#include <string.h>
#include <locale.h>
#include <stdbool.h>

void entrada(char *string1, char *string2, int sizeof1, int sizeof2){
	while(true){
		printf("Digite uma palavra ou frase: ");
		fgets(string1, sizeof1, stdin);
		string1[strcspn(string1, "\n")] = '\0'; //remove quebra de linha \n colcoada pelo fgets ao apertar enter
		
		if(strlen(string1) > 500){ //verifica se string é maior que 500 pra não dar erro a hora de concatenar as 2
			printf("String longa demais, recomece!\n");
			continue;}
		
		printf("Digite uma palavra ou frase: ");
		fgets(string2, sizeof2, stdin);
		string2[strcspn(string2, "\n")] = '\0';
		
		if(strlen(string2) > 500){
			printf("String longa demais, recomeçe!\n");
			continue;
		}		
		break;		
	}
}

void exibir_tamanho(char *string1, char *string2){
	printf("Tamanho da string 1: %zu\n", strlen(string1));
	printf("Tamanho da string 2: %zu\n", strlen(string2));
}
	
void copia_concatena(char *string1, char *string2){
	char nova_string[1001];
	strcpy(nova_string, string1);
	printf("Nova variável: %s\n", nova_string);
	
	strcat(nova_string, string2);
	printf("Concatenada: %s\n", nova_string);
}

void comparacao(char *string1, char *string2){
	int comparacao_n = strncmp(string1, string2, 3); //compara 3 primeiros caracteres
	int comparacao = strcmp(string1, string2); //comapra todos os caracteres

	if(comparacao > 0){
		printf("A primeira string tem uma ordem alfabetica (lexicografia) maior segundo ASCII\n");			
	}
	else if(comparacao < 0){
			printf("A segunda string tem uma ordem alfabetica (lexicografia) maior segundo ASCII\n");
		}
		else{
		printf("As strings são de mesma ordem alfabetica (lexicografia) segundo ASCII\n");
		}
	
	if(comparacao_n > 0){
		printf("Os 3 caracteres da primeira string tem uma ordem alfabetica (lexicografia) maior segundo ASCII");			
	}
	else if(comparacao_n < 0){
			printf("Os 3 caracteres da segunda string tem uma ordem alfabetica (lexicografia) maior segundo ASCII");
		}
		else{
		printf("Os 3 caracteres das strings são de mesma ordem alfabetica (lexicografia) segundo ASCII");
		}			
}

int main(){
	setlocale(LC_ALL, "Portuguese_Brazil");
	char string1[1001], string2[1001];

	entrada(string1, string2, sizeof(string1), sizeof(string2));
	exibir_tamanho(string1, string2);
	copia_concatena(string1, string2);
	comparacao(string1, string2);
			
	return 0;
}