/* verificar_notas_m�dias
   Entrada de n�merso de notas at� o usu�rio decidir parar e entrada da m�dia para ser aprovado
   calcula a m�dia, imprime se foi aprovado pela m�dia da nota e tem op��o para fechar programa  */

#include <stdio.h>
                                              

float notas[6] = {0,0,0,0,0,0};
float media, nota_corte = 0;
int sair = 1; //1 � o mesmo que verdadeiro
int indice = 0;

void pedir_notas(){
	for(indice; indice< 6; indice++){
		printf("Digite a nota: ");
		scanf("%f", &notas[indice]);
		printf("%f\n", notas[indice]);
		
		printf("Adicionar mais notas? Sim- 0, Nao- 1: ");
		scanf("%d", &sair);
				  }
	printf("Qual a nota de corte? ");
	scanf("%f", &nota_corte);
					   } 
			 
void calcular_notas(){
	media = notas[0] + notas[1] + notas[2] + notas[3] + notas[4] + notas[6];
	media = media / 6;
	printf("Media: %f\n", media);		 
					 }

void aprovacao(){
	if(media >= nota_corte){
		printf("APROVADO");	 
			 			   }
    						   	
	else{
		printf("REPROVADO");	
		}
				}

int main(){
	while(1){
		pedir_notas();
		calcular_notas();
	    aprovacao();
			   }		
	return 0;
         } 
