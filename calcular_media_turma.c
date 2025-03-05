//em loop:
//entrada 4 notas por aluno
//calcula m�dia aritm�tica 4 notas
//se m�dia maior ou igual a 7 ser� aprovado, se n�o reprovado, ser� printado nota e situa��o do aluno
//verificar se ir� continaur adicionando e se n�o for printar m�dia da turma

#include <stdio.h>
#include <stdbool.h>
#include <locale.h>

void entrada_notas(float *nota1, float *nota2, float *nota3, float *nota4){
	printf("Digite uma nota por linha:\n");
	scanf("%f", nota1);
	scanf("%f", nota2);
	scanf("%f", nota3);
	scanf("%f", nota4);
}

void calcular_media(float nota1, float nota2, float nota3, float nota4, float *media, float *nota_turma){
	float soma = nota1 + nota2 + nota3 + nota4;
	*media = soma / 4;
	
	*nota_turma += soma / 4;
}

void printar_aluno(float media){
	(media >= 7)? printf("Aprovado, m�dia: %.2f\n", media): printf("Reprovado, m�dia: %.2f\n", media);
}

bool continuar_loop(){
	int entrada = 0;
	printf("Adicionar outro aluno? 1- Sim, 2- N�o\n");
	scanf("%d", &entrada);
	
	switch(entrada){
		case 1:
			return true;
			break;
		case 2:
			return false;
			break;
		default:
			printf("Insira um valor correto!");
			return continuar_loop();
	} 
}

void printar_media_turma(float nota_turma, int quantidade_alunos){
	printf("M�dia da turma: %.2f", nota_turma / quantidade_alunos);	
}

int main(){
	setlocale(LC_ALL, "Portuguese_Brazil");
	
	float nota1, nota2, nota3, nota4, nota_turma, media = 0;
	int quantidade_alunos = 0;
	bool ativo = true;
	
	while(ativo){
		quantidade_alunos++	;
		entrada_notas(&nota1, &nota2, &nota3, &nota4);
		calcular_media(nota1, nota2, nota3, nota4, &media, &nota_turma);
		printar_aluno(media);
		ativo = continuar_loop();
	}
	printar_media_turma(nota_turma, quantidade_alunos);
	return 0;
}
