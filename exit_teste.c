// testando exit()

#include <stdio.h>
#include <stdlib.h>
#include <locale.h>

int main(){
	setlocale(LC_ALL, "Portuguese_Brazil");
	
	int valor = 0;
	
	printf("Escreva um n�mero positivo: ");
	scanf("%d", &valor);
	
	if(valor < 0){
		printf("N�mero negativo, saindo do programa");
		exit(EXIT_FAILURE);
	}
	
	printf("Continuando programa");

exit(EXIT_SUCCESS);
}
