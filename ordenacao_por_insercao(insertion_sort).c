#include <stdio.h>

#define TAM 10

void ordenacao_por_insercao(int vetor[]){ //ordem crescente	
	for(int i = 1; i < TAM; i++){  //seleciona elemento atual a partir do segundo, copia seu valor e cria contador j com valor i - 1
		int chave = vetor[i];
		int j = i - 1;			  // tira 1 para iterar elementos anteriores
		
		while(j >= 0 && vetor[j] > chave){  //verifica se elementos anteriores do atual são maiores e se forem fazem eles se moverem para a direita
			vetor[j + 1] = vetor[j];
			--j;						    //decrementa j
		}
		vetor[j + 1] = chave;			    //move valor chave para o que sobrou do indice j e devolve o + 1
	}
}

void imprimir_vetor(int vetor[]){
	for(int i = 0; i < TAM; i++){
		printf("%d", vetor[i]);
		if(i < TAM - 1){
			printf(", ");
		}
	}
}

int main(){
	int vetor[TAM] = {14,5,3,6,3,7,1,89,11,54};
	
	ordenacao_por_insercao(vetor);
	imprimir_vetor(vetor);
	
	return 0;
}
