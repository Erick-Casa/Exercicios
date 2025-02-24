/*Alocar mem�ria para um vetor de inteiros de tamanho n escolhido pelo usu�rio usando malloc.
Preencher o vetor com valores inseridos pelo usu�rio.
Exibir os valores armazenados no vetor.
Liberar a mem�ria alocada usando free.*/

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
		printf("Escolha o pr�ximo n�mero da array: ");
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
