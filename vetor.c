/* Peça ao usuário para inserir 5 números inteiros.
Armazene esses números em um vetor.
Exiba os números inseridos na ordem original e na ordem inversa.*/

#include <stdio.h>
#include <locale.h>

void pedir_numeros(int *numeros){
	for(int i = 0; i != 5; i++){
		printf("Digite o número %d: ", i+1);
		scanf("%d", &numeros[i]);		
	}
}

void exibir_numeros(int *numeros){
	printf("Números em ordem: ");
	for(int i = 0; i != 5; i++){
		printf("%d, ", numeros[i]);
		if()
	}
	printf("Números em ordem invertida: ");
	for(int i = 4; i != -1; i--){
		printf("%d, ", numeros[i]);
	}
}

int main(){
	setlocale(LC_ALL, "Portuguese_Brazil");
	
	int numeros[5] = {0,0,0,0,0};
	
	pedir_numeros(numeros);
	exibir_numeros(numeros);
	
	return 0;
}
