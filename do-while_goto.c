//teste com do-while e goto, verificar n�mero positivo

#include <stdio.h>

int main() {
    int entrada = 0;
    
    /*do {  
        printf("Escreva um n�mero positivo:\n");
        scanf("%d", &entrada);        
    } while (entrada < 0);*/
    
    verificar_positivo:
    	
	printf("Escreva um numero positivo: ");
	scanf("%d", &entrada);
	
	if(entrada < 0){
		goto verificar_positivo;
	}
	printf("Numero positivo: %d\n", entrada);
    
	return 0;
}
