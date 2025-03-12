/*Crie um programa que leia duas matrizes 3x3 de números inteiros e calcule a soma dessas matrizes, exibindo o resultado.*/

#include <stdio.h>

#define TAM 3

void soma_matrizes(int matriz1[TAM][TAM], int matriz2[TAM][TAM]){
	int soma = 0;
	
	for(int l=0; l<3; l++){     //linha
		for(int e=0; e<3; e++){ //elemento/coluna
			soma += matriz1[l][e] + matriz2[l][e];
		}
	}
	printf("%d", soma);
}

int main(){
	int matriz1[TAM][TAM] = {
		{1,1,1},
		{1,1,1},
		{1,1,1}};
		
	int matriz2[TAM][TAM] = {
		{1,1,1},
		{1,1,1},
		{1,1,1}};
	
	soma_matrizes(matriz1, matriz2);
	
	return 0;
}
