#GERAL:
#labirinto com grade 5x5 que o jogador navega
#há alguns tesouros aleatórios que aumentam a pontuação e armadilhas que diminuem sua vida
#objetivo é coletar tesouro principal antes de ficar sem vidas

#REGRAS:
#labirinto 5x5, com posições com coordenadas 0-4, jogador começa na 0,0
#só tesouro principal que vence o jogo, tesouro em posição aleatória
#há armadilhas espalhadas que fazem o jogador perder 1 vida se pisar nelas
#tesouros secundários que aumentam a pontuação do jogador em 3 posições
#jogador se move com comandos cima, baixo, esquerda, direita sem sair do labirinto
#cada movimento mostrar posição atual e pontuação
#informar se jogador acionou armadilha ou coletou tesouro principal secundário

import random

#gerar labirinto com anhinhamento de compreensões de lista
tamanho_grade = 5
labirinto = [[0 for elemento in range(tamanho_grade)] for elemento in range(tamanho_grade)]
labirinto[0][0] = "J"


#gerar indices aleatórios x,y que serão as coordenadas e verifica se não há repetições delas e criar mapa
def gerar_labirinto():
    
    y_indices = (random.randint(0,4), random.randint(0,4), random.randint(0,4), random.randint(0,4),
                                    random.randint(0,4), random.randint(0,4), random.randint(0,4))

    
    x_indices = (random.randint(0,4), random.randint(0,4), random.randint(0,4), random.randint(0,4),
                                       random.randint(0,4), random.randint(0,4), random.randint(0,4))
   
    quantidade_indices_aleatorios = len(y_indices) #quantidade de coordenadas

    #for de acordo com comprimento da lista de coordenadas aleatórias
    #junta os x,y de mesmo indice em cada lista juntos em tuplas pra virarem coordenadas
    #compara comprimento da lista com lista convertida em tupla e se nenhuma tupla está na coordenada do jogador (0,0)
    #verificar se jogador não sumirá ao gerar mapa    

    lista_tuplas_coordenadas = []
    for n in range(0, quantidade_indices_aleatorios):
        lista_tuplas_coordenadas.append((y_indices[n], x_indices[n]))

    if len(lista_tuplas_coordenadas) == len(set(lista_tuplas_coordenadas)) and all(t != (0,0) for t in lista_tuplas_coordenadas):
        pass

    else:
        print("Duplicou ou gerou no J, geração refeita")
        gerar_labirinto()        
        return

    #contadores de quantos elementos já foram adicionados de cada tipo           

    tesouro_principal = 0
    tesouro_secundario = 0
    armadilhas = 0
    
    #para cada coordenada:
        #colocar um tesouro principal, tesouro secundário ou armadilha no labirinto
        #verificar se não e no lugar do "J"

    for i in range(0, quantidade_indices_aleatorios):                       
            if tesouro_principal == 0:
                print("tesouro_principal")
                
                labirinto[y_indices[i]][x_indices[i]] = "T"
                tesouro_principal += 1
              
            elif tesouro_secundario < 3:
                print("tesouro_secundario")
                labirinto[y_indices[i]][x_indices[i]] = "S"
                tesouro_secundario += 1
                
            elif armadilhas < 3:
                print("armadilhas")
                labirinto[y_indices[i]][x_indices[i]] = "A"
                armadilhas += 1

            else:
                print("mais quantidade do que precisa")
    print("")
                        


def mostrar_labirinto():
    for lista in labirinto:
        print(" ".join(str(caractere) for caractere in lista))


#códigos predefinids para quando pegar tesouro ou acionar armadilha

pontos = 0
vidas = 2
posicao = (0,0)
pegou_tesouro = False

def pegou_tesouro_principal():
    global pontos, vidas, pegou_tesouro
    print(f"FIM DE JOGO. Pontos: {pontos} Vidas: {vidas}")
    pegou_tesouro = True

def pegou_tesouro_secundario():
    global pontos, vidas
    pontos += 100
    print("Coletou tesouro secundário, +100 pontos")
    print(f"Pontos: {pontos}")

def acionou_armadilha():
    global pontos, vidas
    vidas -= 1
    print("Acionou armadilha, -1 de vida")
    print(f"Vidas: {vidas}")
    if vidas == 0:
        print("SEM VIDAS, FIM DE JOGO")
        



#detecta com loops for e move o jogador para outro indice esquerda, direita, baixo, cima sem ser pro vazio
#se tocar no "T" ganha o jogo se tocar no "S" ganha pontos, se tocar no "A" perde vida, se chegar 0 de vida perde,
#cada movimento mostrar posição atual e pontuação
#informar se jogador acionou armadilha ou coletou tesouro principal secundário


def mover_jogador_e_calculos():
    global pontos, vidas, posicao

    for indice_lista, lista in enumerate(labirinto):
        for indice_elemento, elemento in enumerate(lista):
            if elemento == "J":
                print("")
                entrada = input("esquerda, direita, baixo ou cima? ")
                print("")
                print("-------------------------------------------------")
                if entrada == "direita" or entrada == "d" and indice_elemento + 1 <= 4:
                    if lista[indice_elemento + 1] == "T":
                        pegou_tesouro_principal()
                        
                    if lista[indice_elemento + 1] == "S":
                        pegou_tesouro_secundario()
                        
                    if lista[indice_elemento + 1] == "A":
                        acionou_armadilha()

                    lista[indice_elemento] = 0       #Deixa espaço do J vazio com o 0
                    lista[indice_elemento + 1] = "J" #Coloca J na posição na mesma lista
                    posicao = (indice_lista, indice_elemento) 
                    return 

                elif entrada == "esquerda" or entrada == "e" or entrada == "a" and indice_elemento - 1 >= 0:
                    if lista[indice_elemento - 1] == "T":
                        pegou_tesouro_principal()
                        
                    if lista[indice_elemento - 1] == "S":
                        pegou_tesouro_secundario()

                    if lista[indice_elemento - 1] == "A":
                        acionou_armadilha()

                    lista[indice_elemento] = 0       #Deixa espaço do J vazio com o 0
                    lista[indice_elemento - 1] = "J" #Coloca J na posição na mesma lista
                    posicao = (indice_lista, indice_elemento)
                    return

                elif entrada == "baixo" or entrada == "b" or entrada == "s" and indice_lista + 1 <= 4:
                    if labirinto[indice_lista + 1][indice_elemento] == "T":
                        pegou_tesouro_principal()

                    if labirinto[indice_lista + 1][indice_elemento] == "S":
                        pegou_tesouro_secundario()

                    if labirinto[indice_lista + 1][indice_elemento] == "A":
                        acionou_armadilha()
                        
                    lista[indice_elemento] = 0        #Deixa espaço do J vazio com o 0
                    labirinto[indice_lista + 1][indice_elemento] = "J" #Coloca J na posição em outra lista
                    posicao = (indice_lista, indice_elemento)
                    return

                elif entrada == "cima" or entrada == "c" or entrada == "w" and indice_lista - 1 >= 0:
                    if labirinto[indice_lista - 1][indice_elemento] == "T":
                        pegou_tesouro_principal()

                    if labirinto[indice_lista - 1][indice_elemento] == "S":
                        pegou_tesouro_secundario()

                    if labirinto[indice_lista - 1][indice_elemento] == "A":
                        acionou_armadilha()
                        
                    lista[indice_elemento] = 0        #Deixa espaço do J vazio com o 0
                    labirinto[indice_lista - 1][indice_elemento] = "J" #Coloca J na posição em outra lista
                    posicao = (indice_lista, indice_elemento)
                    return

                else:
                    print("Escreva um comando válido e não ande pro vazio!")
                    mover_jogador_e_calculos()
                    return


#gera labirinto aleatório, entra no loop, mostra o labirinto, move o jogador e calcula pontos e vidas
#while True enquanto houver vidas e tesouro principal não for pego (FALSE)

gerar_labirinto()
while vidas != 0 and pegou_tesouro == False:
    mostrar_labirinto()
    mover_jogador_e_calculos()
    print(f"Posição : {posicao} Pontos: {pontos} Vida: {vidas}")



