/* Pe�a ao usu�rio para inserir 5 n�meros inteiros.
Armazene esses n�meros em um vetor.
Exiba os n�meros inseridos na ordem original e na ordem inversa.*/

#include <stdio.h>
#include <locale.h>

void pedir_numeros(int *numeros){
	for(int i = 0; i != 5; i++){
		printf("Digite o n�mero %d: ", i+1);
		scanf("%d", &numeros[i]);		
	}
}

void exibir_numeros(int *numeros){
	printf("N�meros em ordem: ");
	for(int i = 0; i != 5; i++){
		printf("%d, ", numeros[i]);
		if()
	}
	printf("N�meros em ordem invertida: ");
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
