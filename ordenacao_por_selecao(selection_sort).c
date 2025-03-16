#include <stdio.h>

#define TAM 10

void ordenar_por_selecao(int vetor[]){ //crescente, seleciona menor elemento, troca-o pelo primeiro elemento, segundo menor pelo segundo elemento...	
	int menor_int = vetor[0];
	int menor_int_i = 0;
	int temporario = 0;
	

	for(int j = 0; j < TAM; j++){ //itera TAM vezes/elemento atual
		menor_int = vetor[j];
		menor_int_i = j;
		
		for(int i = j + 1; i < TAM; i++){ //Pega menor número
			if(vetor[i] < menor_int){
			menor_int = vetor[i];
			menor_int_i = i;
			}			
		}
		
		if(menor_int < vetor[j]){  //troca pelo primeiro elemento ou subsequente
			temporario = vetor[j];
			vetor[j] = vetor[menor_int_i];
			vetor[menor_int_i] = temporario;
		}					
	}
}

void imprimir_vetor(int vetor[]){
	for(int i = 0; i < TAM; i++){
		printf("%d, ", vetor[i]);
	}
}

int main(){
	int vetor[TAM] = {5,4,63,6,3,78,4,5,6,1};
	
	ordenar_por_selecao(vetor);
	imprimir_vetor(vetor);
	
	return 0;
}
