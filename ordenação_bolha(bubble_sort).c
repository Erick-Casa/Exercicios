/*Solicite ao usu�rio um n�mero N (tamanho do vetor),
leia N n�meros inteiros
e os ordene em ordem crescente usando o algoritmo de ordena��o bolha.
No final, exiba o vetor ordenado.*/

#include <stdio.h>
#include <stdlib.h>
#include <locale.h>

void ler_tamanho_vetor(int *vetor_tamanho, int **vetor){
	printf("Digite o tamanho do vetor: ");
	scanf("%d", vetor_tamanho);
	
	if(*vetor_tamanho < 0){
		printf("Digite um n�mero positivo!\n");
		ler_tamanho_vetor(vetor_tamanho, vetor);
		return;
	}
	
	*vetor = (int*)realloc(*vetor, *vetor_tamanho * sizeof(int));
	if(*vetor == NULL){
		printf("Erro ao realocar mem�ria\n");
		ler_tamanho_vetor(vetor_tamanho, vetor);
		return;
	}
	
	//printf("%d\n", *vetor_tamanho);	    ///debugar
}

void ler_numeros_vetor(int vetor_tamanho, int vetor[]){
	for(int i = 0; i < vetor_tamanho; i++){
		printf("Digite o n�mero %d do vetor: ", i + 1);
		scanf("%d", &vetor[i]);
		//printf("%d\n", vetor[i]);    ///debugar
	}
}

void ordenacao_bolha(int vetor_tamanho, int vetor[]){    //ordenar ordem crescente
	int temporario = 0;

	for(int n = 0; n < vetor_tamanho -1; n++){  //cada n�mero
		for(int c = 0; c < vetor_tamanho -1 - n; c++){ //cada compara��o de um n�mero com os outroscomparativo
			if(vetor[c] > vetor[c + 1]){
				temporario = vetor[c];
				vetor[c] = vetor[c + 1];
				vetor[c + 1] = temporario;
			}
		}	
	}
}

void imprimir_vetor(int vetor_tamanho, int vetor[]){
	printf("Vetor ordenado ordem crescente: ");
	for(int i = 0; i < vetor_tamanho; i++){
		if(i > 0){
			printf(", ");
		}
		printf("%d", vetor[i]);	
	}
}

int main(){
	setlocale(LC_ALL,"Portuguese_Brazil");
	
	int vetor_tamanho = 0;
	int *vetor = NULL;
	
	ler_tamanho_vetor(&vetor_tamanho, &vetor);
	ler_numeros_vetor(vetor_tamanho, vetor);
	ordenacao_bolha(vetor_tamanho, vetor);
	imprimir_vetor(vetor_tamanho, vetor);
	
	free(vetor);
	vetor = NULL;
	
	return 0;
}
