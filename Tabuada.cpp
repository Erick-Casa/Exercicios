#include <stdio.h>
//
void calcular_e_printar_tabuada(int entrada, int n){
	
	int resultado = entrada * n;
	
	printf("%i vezes %i igual a %i \n", entrada, n, resultado);	
				
					}

int main(){
	int x = false;
	printf("%i", x);
	int entrada = 0;
	int contador = 1;
	//enquanto for true irá pedir entrada e calcular e printar tabuada
	while(true){
	//entrada do número que quer da tabuada e print sobre ele
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
