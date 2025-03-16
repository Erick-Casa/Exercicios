/*Pe�a ao usu�rio para inserir um n�mero n, que representar� o tamanho de um vetor.
Pe�a ao usu�rio para inserir n valores inteiros e armazene-os em um vetor.
Implemente uma fun��o recursiva que calcule a soma dos elementos do vetor.
Implemente uma fun��o que receba um n�mero por valor e retorne o dobro desse n�mero.
Implemente uma fun��o que receba um n�mero por refer�ncia e dobre seu valor diretamente.
Exiba os resultados no final.*/

#include <stdio.h>
#include <stdlib.h>
#include <locale.h>

int* obter_vetor(int *vetor_tamanho){	
	printf("Insira o tamanho do vetor: ");
	scanf("%d", vetor_tamanho);
	
	int *vetor = (int*)malloc(*vetor_tamanho * sizeof(int)); //inicializa ponteiro malloc e verifica
	if(vetor == NULL){
		printf("Erro ao alocar mem�ria");
		return NULL;
	}
	
	for(int i = 0; i < *vetor_tamanho; i++){
		printf("Insira o pr�ximo n�mero inteiro do vetor: ");
		scanf("%d", &vetor[i]);
	}

	return vetor;
}

int somar_vetor(int vetor_tamanho, int vetor[], int i){
	if(i == vetor_tamanho){
		return 0;
	}
	
	return vetor[i] + somar_vetor(vetor_tamanho, vetor, i+1);
}

int dobrar_numero(int *numero){
	return *numero * 2;
}

void exibir_resultados(int vetor_tamanho, int vetor[], int soma_vetor, int numero_dobrado){
	printf("Tamanho do vetor: %d\n", vetor_tamanho); 
	
	printf("Vetor: ");
	for(int i = 0; i < vetor_tamanho; i++){    //printar elementos vetor
		if(i > 0){
			printf(", ");
		}
		printf("%d", vetor[i]);
	}
	printf("\n");	
	
	printf("Soma: %d", soma_vetor);
	
	printf("\nN�mero Dobrado: %d", numero_dobrado);	
}

int main(){
	setlocale(LC_ALL, "Portuguese_Brazil");
	
	int vetor_tamanho = 0;
	int *vetor = obter_vetor(&vetor_tamanho);
	int soma_vetor = somar_vetor(vetor_tamanho, vetor, 0); 	
	int numero_dobrado = dobrar_numero(&soma_vetor);
	exibir_resultados(vetor_tamanho, vetor, soma_vetor, numero_dobrado);

	
	if(vetor != NULL){
		free(vetor);
		vetor = NULL;		
	}

	return 0;
}
