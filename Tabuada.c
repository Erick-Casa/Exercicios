#include <stdio.h>

void calcular_e_printar_tabuada(int entrada, int contador){
	int resultado = entrada * contador;
	
	printf("%i vezes %i igual a %i \n", entrada, contador, resultado);	
	}

int main(){
	int entrada = 0;

	while(1){ 	//enquanto for true ir� pedir entrada, calcular e printar tabuada

	printf("\nInsira o numero que voce quer a tabuada: ");
	scanf("%i", &entrada);
	printf("\nTabuada do numero %i: \n \n", entrada);
	
	//enquanto contador for menor ou igual a 10 calcule o n�mero do contador, printa e aumente em 1 o contador
	for(int contador = 1; contador <= 10; contador++) {
	
		calcular_e_printar_tabuada(entrada, contador);
			}
		}
	return 0;
	}
