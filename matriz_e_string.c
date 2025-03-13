/*Peça ao usuário a quantidade de nomes que deseja armazenar.
Aloque dinamicamente uma matriz de caracteres para armazenar N nomes de no máximo 50 caracteres cada.
Permita que o usuário insira os nomes.
Utilize funções da string.h para:
Exibir o nome mais longo
Ordenar os nomes em ordem alfabética e exibir
Criar uma string concatenada com todos os nomes
Copiar o primeiro nome para uma variável separada*/

#include <stdio.h>
#include <locale.h>
#include <string.h>

#define MAX_CARACTERES 50

void pedir_nomes(int *quantidade_nomes){
	printf("Quantos nomes você deseja armazenar? ");
	scanf("%d", quantidade_nomes);
	getchar();
}

void inserir_nomes(int quantidade_nomes, char nomes[quantidade_nomes][MAX_CARACTERES+1] ){
		for(int l=0; l<quantidade_nomes; l++){ 	 //linha
			printf("Escreva o nome %d: ", l+1);
			fgets(nomes[l], MAX_CARACTERES+1, stdin);
			nomes[l][strcspn(nomes[l], "\n")] = '\0';
	}	
}

void exibir_maior_nome(int quantidade_nomes, char nomes[quantidade_nomes][MAX_CARACTERES+1]){ 
	int maior_tamanho = 0;
	char maior_nome[MAX_CARACTERES];
	
	for(int i=0; i<quantidade_nomes; i++){
		if(strlen(nomes[i]) > maior_tamanho){
			maior_tamanho = strlen(nomes[i]);
			strcpy(maior_nome, nomes[i]);		
		}
	}
	printf("Maior nome: %s\n", maior_nome);
}

void ordenar_nomes(int quantidade_nomes, char nomes[quantidade_nomes][MAX_CARACTERES+1]){
	char temporario[MAX_CARACTERES];

	for(int l=0; l<quantidade_nomes-1; l++){

		for(int i=0; i<quantidade_nomes-1; i++){ //-1 para não comparar com valor inexistente
			if(strcmp(nomes[i], nomes[i+1]) > 0){ 
				strcpy(temporario, nomes[i]); //copia pra temporario
				strcpy(nomes[i], nomes[i+1]);
				strcpy(nomes[i+1], temporario);
			}	
		}				
	}
	printf("Ordem alfabética: ");
	for(int i=0; i<quantidade_nomes; i++){ //printador
		printf("%s, ", nomes[i]);
	}
}

void concatenar_nomes(int quantidade_nomes, char nomes[quantidade_nomes][MAX_CARACTERES+1]){
	char concatenada[MAX_CARACTERES * quantidade_nomes];
	concatenada[0] = '\0';
	for(int i=0; i<quantidade_nomes; i++){
		strcat(concatenada, nomes[i]);
	}
	printf("\nNomes concatenados: %s\n", concatenada);
}

void nova_variavel(char nomes[][MAX_CARACTERES+1]){
	char variavel_separada[MAX_CARACTERES];
	strcpy(variavel_separada, nomes[0]);
	printf("Nome copiado: %s", variavel_separada);
}

int main(){
	setlocale(LC_ALL, "Portuguese_Brazil");
	
	int quantidade_nomes = 0;
	
	pedir_nomes(&quantidade_nomes);	
	
	char nomes[quantidade_nomes][MAX_CARACTERES+1];
	
	inserir_nomes(quantidade_nomes, nomes);
	exibir_maior_nome(quantidade_nomes, nomes);
	ordenar_nomes(quantidade_nomes, nomes);
	concatenar_nomes(quantidade_nomes, nomes);
	nova_variavel( nomes);
	
	return 0;
}
