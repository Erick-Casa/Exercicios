/*Criar uma fun��o recursiva para inserir n�meros em um vetor din�mico e imprimir os n�meros armazenados nela.*/

#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include <stdbool.h>

int retornar_vetor_tamanho(int *ptr_vetor_tamanho){
	while(true){
		printf("Tamanho do vetor: ");
			
		if(scanf("%d", ptr_vetor_tamanho) != 1){ //verifica caracteres que n�o sejam inteiros
			while(getchar() != '\n'){			 // libera buffer
				continue;
			}
			printf("Digite um n�mero inteiro positivo!\n");
			continue;
		}
		
		if(*ptr_vetor_tamanho <= 0){
			printf("Digite um n�mero positivo!\n");
			continue;
		}	
		
		return *ptr_vetor_tamanho;
	}
}

void inserir_inteiros_vetor(int vetor_tamanho, int vetor[], int i){
	if(i == vetor_tamanho){
		return;
	}
	vetor[i] = i + 1;
	inserir_inteiros_vetor(vetor_tamanho, vetor, i + 1); 
}

void imprimir_vetor(int vetor_tamanho, int vetor[]){
	for(int i = 0; i < vetor_tamanho; i++){
		if(i > 0){
			printf(", ");
		}
		printf("%d", vetor[i]);
	}
}

int main(){
	setlocale(LC_ALL, "Portuguese_Brazil");
	
	int vetor_tamanho = 0;	
	int *vetor = (int*)malloc(retornar_vetor_tamanho(&vetor_tamanho) * sizeof(int));
	if(vetor == NULL){
		printf("Erro ao alocar mem�ria");
		return 0;
	}
	
	inserir_inteiros_vetor(vetor_tamanho, vetor, 0);
	imprimir_vetor(vetor_tamanho, vetor);
	
	free(vetor); //se torna inv�lido, se tentar acessar vai dar comportamento indefinido
	vetor = NULL;//evita problemas
	return 0;
}
