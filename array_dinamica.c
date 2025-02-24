/*Alocar memória para um vetor de inteiros de tamanho n escolhido pelo usuário usando malloc.
Preencher o vetor com valores inseridos pelo usuário.
Exibir os valores armazenados no vetor.
Liberar a memória alocada usando free.*/

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <locale.h>

int n = 0;
int *array = 0;

void inicializar_array(){

	printf("Escolha a quantidade de elementos da array: ");
	scanf("%d", &n);
	
	array = malloc(n * sizeof(int));
}

void escolher_valores(){

	for(int i = 0; i < n; i++){
		printf("Escolha o próximo número da array: ");
		scanf("%d", &array[i]);
		
	}
}

void imprimir_array(){

	for(int i = 0; i < n; i++){
		printf("%d, ", array[i]);
			
	}
}

int main(){
	
	setlocale(LC_ALL, "Portuguese_Brazil");
	
	while(true){
	
		inicializar_array();
		escolher_valores();
		imprimir_array();
		free(array);
	}	

	return 0;
}
