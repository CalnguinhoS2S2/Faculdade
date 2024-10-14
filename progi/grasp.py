import random

caixas = [] # itens dentro da minha caixa
itens = [] # peso de cada item a ser empacotado
Num_interacao = 100 # numero maximo de interações

#--------------ler arquivo------------
peso_caixa = int(input()) # capacidade maxima de uma caixa
while True:
    item = input()
    if item == "":
        break
    itens.append(int(item))
#-------------------------------------

def gula(itens):
    for item in itens: # andar por todos os itens
        check = False # saber se o item foi ou não colocado em uma caixa já existente
        for caixa in caixas: # andar por cada caixa
            soma_itens = sum(caixa) # soma o peso de cada item 
            if soma_itens + item <= peso_caixa: # posso colocar esse novo item dentro da minha caixa
                caixa.append(item) # colocando esse item na minha caixa
                check = True # item foi colocado
                break
        if check==False: # criar uma nova caixa para colocar o item
            caixas.append([item])
    return caixas # retorno as coixas que eu montei com os seu pacotes

def busca_local(solucao_gulosa):
    check = True
    while check: # o while ira ser executado enquanto ouver uma como distribuir os itens para outras caixas
        check = False
        for i in range(len(caixas)): # olhando para uma caixa
            for j in range(i+1, len(caixas)): # andando por por caixa+1 para ver se posso fazer uma troca de item
                for item in caixas[i]: # olhando para cada item da caixa
                    soma_itens = sum(caixas[j])
                    if soma_itens + item <= peso_caixa: # posso colocar o meu item em outra caixa
                        caixas[j].append(item) # colocando o item em outra caixa
                        caixas[i].append(item) # removendo o item da antiga caixa
                        check = True
                        break
                if len(caixas[i])==0: # caixa vazia
                    caixas.pop(i) # removendo caixa vazia
                    break
    return caixas # retorna os novos arranjos de caixas

def grasp(itens, Num_interacao):
    Melhor_solucao = len(itens) # inicia a melhor solução com todos os itens
    for _ in range(Num_interacao): # fazer todas as interações
        item_aleatorio = random.sample(itens, len(itens)) # embaralho os itens
        solucao_gulosa = gula(item_aleatorio) # solução gulosa
        BL = busca_local(solucao_gulosa) # montar novos melhores arranjos de caixas
        if len(BL) < Melhor_solucao: # comparo a solução BL com a melhor solução que eu tenho
            Melhor_solucao = len(BL) # faço Melhor_solucao receber a melhor solução encontrada de caixas
    return Melhor_solucao # retorno o numero de caixas para empacotar todos os itens

solucao = grasp(itens, Num_interacao)
print(solucao)
