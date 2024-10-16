import random


peso_caixa = 150 # capacidade maxima de uma caixa
itens = [100,100,100,100,100,100,100,100,100,100,99,99,99,99,99,99,99,99,99,99,99,99,99,98,98,98,98,98,98,98,98,97,97,97,97,97,97,97,97,97,97,97,96,96,96,96,96,96,96,95,95,95,95,95,95,95,95,95,95,95,95,95,95,95,94,94,94,94,94,94,94,94,94,94,94,94,94,94,93,93,93,93,93,93,93,93,93,93,93,93,93,92,92,92,92,92,92,92,92,92,92,92,92,92,91,91,91,91,91,91,91,91,91,91,91,91,90,90,90,90,90,90,90,90,90,90,90,90,90,90,89,89,89,89,89,89,89,89,89,88,88,88,88,88,88,88,88,88,88,88,88,88,88,88,87,87,87,87,87,87,87,87,87,87,87,86,86,86,86,86,86,86,86,86,86,86,86,86,86,86,86,86,85,85,85,85,85,85,85,85,85,85,85,85,84,84,84,84,84,84,84,84,84,84,84,84,83,83,83,83,83,83,83,83,83,82,82,82,82,82,82,82,82,82,82,81,81,81,81,81,81,81,81,81,81,81,81,81,80,80,80,80,80,80,80,80,80,80,80,80,79,79,79,79,79,79,79,79,78,78,78,78,78,78,78,78,78,78,78,78,78,78,77,77,77,77,77,77,77,77,77,77,76,76,76,76,76,76,76,76,76,76,76,76,76,75,75,75,75,75,75,75,75,75,75,75,75,75,75,75,75,74,74,74,74,74,74,74,74,73,73,73,73,73,73,73,73,73,73,72,72,72,72,72,72,72,72,72,72,72,72,72,71,71,71,71,71,71,71,71,71,71,71,71,70,70,70,70,70,70,70,69,69,69,69,69,69,69,69,69,69,69,69,69,69,69,69,69,69,68,68,68,68,68,68,68,68,68,68,68,68,68,68,67,67,67,67,67,67,67,67,67,67,67,66,66,66,66,66,66,66,66,66,66,66,66,66,65,65,65,65,65,65,65,65,65,65,65,65,65,64,64,64,64,64,64,64,64,64,64,63,63,63,63,63,63,63,63,63,62,62,62,62,62,62,62,62,62,62,61,61,61,61,61,61,61,61,61,61,61,61,61,61,60,60,60,60,60,60,60,59,59,59,59,59,59,59,59,59,59,59,59,59,59,59,59,59,58,58,58,58,58,58,58,58,58,58,58,57,57,57,57,57,57,57,57,57,57,57,57,57,57,56,56,56,56,56,56,56,56,56,56,56,56,56,56,56,55,55,55,55,55,55,55,55,55,55,55,55,55,55,55,55,55,55,55,55,54,54,54,54,54,54,54,54,54,54,54,54,54,54,54,53,53,53,53,53,53,53,53,53,53,52,52,52,52,52,52,52,52,51,51,51,51,51,51,51,51,51,51,50,50,50,50,50,50,50,50,50,50,49,49,49,49,49,49,49,49,49,49,49,49,49,48,48,48,48,48,48,48,48,48,48,48,48,48,48,47,47,47,47,47,47,47,47,47,47,47,46,46,46,46,46,46,46,46,46,45,45,45,45,45,45,45,45,45,45,45,45,45,44,44,44,44,44,44,44,44,44,44,44,44,43,43,43,43,43,43,43,43,43,43,43,43,43,43,43,43,43,43,43,42,42,42,42,42,42,42,41,41,41,41,41,41,41,41,41,41,40,40,40,40,40,40,40,40,40,40,40,40,40,39,39,39,39,39,39,39,39,39,39,39,39,39,39,39,39,38,38,38,38,38,38,38,38,38,37,37,37,37,37,37,37,37,37,37,36,36,36,36,36,36,36,36,36,36,36,36,35,35,35,35,35,35,35,35,35,35,35,35,35,34,34,34,34,34,34,34,34,34,34,34,34,34,34,34,34,34,33,33,33,33,33,33,33,33,33,33,33,33,33,33,33,33,33,33,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,31,31,31,31,31,31,31,31,31,31,31,30,30,30,30,30,30,30,29,29,29,29,29,29,29,29,29,29,28,28,28,28,28,28,28,28,28,28,27,27,27,27,27,27,27,27,27,27,26,26,26,26,26,26,26,26,26,26,26,26,26,26,26,26,26,26,25,25,25,25,25,25,25,25,25,25,25,24,24,24,24,24,24,24,24,24,24,24,24,24,24,24,24,24,24,24,23,23,23,23,23,23,23,23,23,23,23,23,23,23,22,22,22,22,22,22,22,22,22,22,22,22,22,22,22,21,21,21,21,21,21,21,21,21,21,21,21,21,21,21,20,20,20,20,20,20,20,20,20,20,20,20,20,20,20,20,20,20] # peso de cada item a ser empacotado
Num_interacao = 100 # numero maximo de interacoes

def gula(itens):
    caixas = [] # itens dentro da minha caixa
    for item in itens: # andar por todos os itens
        check = False # saber se o item foi ou não colocado em uma caixa ja existente
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
    caixas = solucao_gulosa
    check = True
    while check: # o while ira ser executado enquanto ouver uma como distribuir os itens para outras caixas
        check = False
        #caixas = [caixa[:] for caixa in solucao_gulosa] # cria uma copia idependente das caixas
        ale_posi = random.choice(range(len(caixas))) # posicao de alguma caixa
        ale_item = random.choice(caixas[ale_posi]) # algum item da caixa na posicao ale_posi
        for i in range(len(caixas)): # ando por todas a caixas
            soma_itens = sum(caixas[i]) # soma do peso de cada  item 
            # if para chegar se a caixas nao e a caixa aleatoria 
            if i != ale_posi and soma_itens + ale_item <= peso_caixa: # peso da caixa + item que quero adicionar tem que ser menhor ou igual ao peso_caixa
                caixas[i].append(ale_item) # colocando o item aleatorio em uma caixa
                caixas[ale_posi].remove(ale_item) # removendo o item aleatorio da sua caixa de origem
                check = True # item trocado com sucesso
                break
        if len(caixas[ale_posi]) == 0: # se o size da caixa que eu estou tirando os itens for igual a 0 nao ha mais nenhum item nessa caixa
            caixas.pop(ale_posi) # removendo a caixa vazia
            break
    return caixas # retorna os novos arranjos de caixas

def grasp(itens, Num_interacao):
    melhor_caixas = []
    Melhor_solucao = len(itens) # primeira melhor solucao
    for _ in range(Num_interacao): # fazer todas as interacoes
        item_aleatorio = random.sample(itens, len(itens)) # embaralho os itens
        solucao_gulosa = gula(item_aleatorio) # solucao gulosa
        BL = busca_local(solucao_gulosa) # montar novos melhores arranjos de caixasa
        if len(BL) < Melhor_solucao: # comparo a solucao BL com a melhor solucao que eu tenho
            Melhor_solucao = len(BL) # faço Melhor_solucao receber a melhor solucao encontrada de caixas
            melhor_caixas = BL
    return Melhor_solucao, melhor_caixas # retorno o numero de caixas para empacotar todos os itens

solucao, caixas = grasp(itens, Num_interacao)
print(f"Numero de caixas: {solucao}")
for i, caixa in enumerate(caixas):
        print(f"Bin {i + 1}: {caixa}")
