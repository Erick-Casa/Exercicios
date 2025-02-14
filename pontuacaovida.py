#solicita ao usuário entrada "ganhou" ou "perdeu"
#atualiza pontuação e pontos de vida de acordo com regras
#exibe pontuação e números de vidas a cada desafio
#termina quando vida chegar a 0 e mostra pontuaçao final

#Regras:
#O jogador começa com 3 vidas e 0 pontos.
#Se o jogador ganhar um desafio, ele recebe 10 pontos.
#Se o jogador perder um desafio, ele perde 1 vida.
#Se o jogador atingir 50 pontos, ele ganha uma vida extra.
#O jogo termina quando as vidas chegam a 0.

pontuacao = 0
vidas = 3

def pontuacao_vida():
    global pontuacao, vidas

    while True:
        print("Pontuação:", pontuacao, "Vidas:", vidas)
        entrada = input("ganhou ou perdeu o desafio? ")
        entrada = entrada.lower()

        if entrada == "ganhou":
            pontuacao += 10

            if pontuacao % 50 == 0 and pontuacao != 0:
                vidas += 1
                continue

        elif entrada == "perdeu":
            vidas -= 1

            if vidas == 0:
                print("GAME OVER -", "Pontuaçao Final:", pontuacao)
                break

            else:
                continue

        else:
            print("Entrada Inválida")
            continue
    

pontuacao_vida()

