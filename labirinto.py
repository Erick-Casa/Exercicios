#labirinto com paredes # e espaço em branco caminho livre(grid 5x5?)
#personagem P
#saída S
#mover o P até o S pelo espaços livres

#imprmir labirinto
#mover P com verificação se o espaço é livre ou não
#vencer se chegar no S

labirinto =[
    ["#","#","#","#","#"],
    ["#"," "," "," ","S"],
    ["#"," ","#","#","#"],
    ["#"," "," ","P","#"],
    ["#","#","#","#","#"]
            ]

labirinto2 =[
    ["#","#","#","#","#","#","#","#","#","#"],
    ["#","P"," "," "," "," "," "," ","#","#"],
    ["#"," ","#","#","#","#","#","#"," ","#"],
    ["#"," "," "," "," "," ","#"," "," ","#"],
    ["#","#","#"," ","#"," "," "," "," ","#"],
    ["#"," "," "," ","#","#"," "," "," ","#"],
    ["#"," "," "," "," "," ","#","#"," ","#"],
    ["#"," ","#","#","#","#"," ","#"," ","#"],
    ["#"," "," "," "," "," "," ","#"," ","#"],
    ["#","#","#","#","#","#","#","#","S","#"]
            ]

def mostrar_labirinto(labirinto_atual):
    for lista in labirinto_atual:
        print(" ".join(lista))


#para cada lista na lista labirinto para cada caractere em cada lista se for caractere P:
#pegar índice, entrada do usuário para mover e verificar se tem parede ou não
#se chegar no S ganha o jogo

lab1 = True
lab2 = False
saiu = False

def mover_personagem(labirinto_atual):
    global saiu, lab1, lab2
    
    for indice_lista, lista in enumerate(labirinto_atual):
        for indice_caractere, caractere in enumerate(lista):

            if caractere == "P":
                x, y = indice_caractere, indice_lista
                entrada = input("escolha para onde mover WASD: ")
 
                if entrada == "A" and labirinto_atual[indice_lista][x - 1] != "#":
                    if labirinto_atual[indice_lista][x - 1] == "S":
                        saiu = True
                        return
                    lista.pop(x)
                    lista.insert(x - 1, caractere)
                    return

                elif entrada == "D" and labirinto_atual[indice_lista][x + 1] != "#":
                    if labirinto_atual[indice_lista][x + 1] == "S":
                        saiu = True
                        return
                    lista.pop(x)
                    lista.insert(x + 1, caractere)
                    return


                if entrada == "W" and labirinto_atual[y - 1][x] != "#":
                    if labirinto_atual[y - 1][x] == "S":
                        saiu = True
                        return
                    lista.pop(x)
                    lista.insert(x, " ")

                    labirinto_atual[y - 1].pop(x)
                    labirinto_atual[y - 1].insert(x, "P")
                    return


                if entrada == "S" and labirinto_atual[y + 1][x] != "#":
                    if labirinto_atual[y + 1][x] == "S":
                        saiu = True
                        return
                    lista.pop(x)
                    lista.insert(x, " ")

                    labirinto_atual[y + 1].pop(x)
                    labirinto_atual[y + 1].insert(x, "P")
                    return


def mudar_labirinto(lab_atual):
    global saiu, lab1, lab2
    if saiu == True and lab1 == True:
        lab1 = False
        lab2 = True
        saiu = False
    elif saiu == True and lab2 == True:
        lab2 = False
        saiu = False
                        

#loop enquanto o labirinto atual estiver True
#funções de mostrar labirinto atual e mover personagem
#condições para quando sair do labirinto ir para outro



while lab1 == True:
    mostrar_labirinto(labirinto)
    mover_personagem(labirinto)
    mudar_labirinto()


while lab2 == True:
    mostrar_labirinto(labirinto2)
    mover_personagem(labirinto2)
    mudar_labirinto()
    
print("PARABÉNS")



