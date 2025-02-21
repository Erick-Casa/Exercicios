/* verificar_notas_médias
   Entrada de númerso de notas até o usuário decidir parar e entrada da média para ser aprovado
   calcula a média, imprime se foi aprovado pela média da nota e tem opção para fechar programa  */

#include <stdio.h>
                                              

float notas[6] = {0,0,0,0,0,0};
float media, nota_corte = 0;
int sair = 1; //1 é o mesmo que verdadeiro
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
