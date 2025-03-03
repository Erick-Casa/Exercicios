#include <stdio.h>

void calcular_e_printar_tabuada(int entrada, int contador){
	int resultado = entrada * contador;
	
	printf("%i vezes %i igual a %i \n", entrada, contador, resultado);	
	}

int main(){
	int entrada = 0;
	int contador = 1;

	while(1){ 	//enquanto for true irá pedir entrada, calcular e printar tabuada

	contador = 1;
	printf("\nInsira o numero que voce quer a tabuada: ");
	scanf("%i", &entrada);
	printf("\nTabuada do numero %i: \n \n", entrada);
	
	//enquanto váriavel do contador for menor ou igual a 10 calcule o número do contador, printa e aumente em 1 o contador
	while(contador <= 10) {
	
		calcular_e_printar_tabuada(entrada, contador);
		contador += 1;
			}
		}
	return 0;
	}
