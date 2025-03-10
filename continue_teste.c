//entrada n�mero N inteiro positivo printar todos n�meros �mpares de 1 at� N usando comando continue para pular pares

#include <stdio.h>
#include <locale.h>

void entrada(int *n){
	printf("Digite um n�mero inteiro positivo: ");
	scanf("%d", n);
}

void calcular(int *n){
	for(int i = 1; i <= *n; i++){
		if(i % 2 == 0){
			continue;
		}
		else{
			printf("%d\n", i);
		}
	}
}

int main(){
	setlocale(LC_ALL,"Portuguese_Brazil");
	
	int n = 0;
	int *p_n = &n;
	
	entrada(p_n);
	calcular(p_n);	

	return 0;
}
