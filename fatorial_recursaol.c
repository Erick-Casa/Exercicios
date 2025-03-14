/*O exerc�cio vai calcular o fatorial de um n�mero usando recurs�o.
A fun��o vai retornar o fatorial e ser� chamada, atribuindo o valor a uma vari�vel no main.*/

#include <stdio.h>
#include <locale.h>

void pedir_entrada(int *numero){
	printf("N�mero para calcular fatorial: ");
	scanf("%d", numero);
	
	if(*numero < 0){
		printf("N�o insira n�meros negativos!\n");
		pedir_entrada(numero);
	}
}

int calcular_fatorial(int numero){
	if(numero == 0 || numero == 1){
		return 1;
	}
	return numero * calcular_fatorial(numero - 1);
}

void saida_resultado(long long int resultado_fatorial){
	printf("Fatorial: %lld", resultado_fatorial);	
}

int main(){
	setlocale(LC_ALL, "Portuguese_Brazil");
	int numero = 0; //numero para usar no fatorial e contador no calcular_fatorial
	long long int resultado_fatorial = 0; //chamar fun��o fatorial com resultado
	
	pedir_entrada(&numero);
	resultado_fatorial = calcular_fatorial(numero); 
	saida_resultado(resultado_fatorial);
	
	return 0;
}
