nome_canal = input()
quantidade_anotacoes = int(input())
anotacoes_trienio = 0
i = 0
data_anotacao = []
ano_anotacao = []
quantidade_visualizacoes = []
total_trienio = 0
total_2018 = 0
total_2019 = 0
total_2020 = 0
numero_entradas_2018 = 0
numero_entradas_2019 = 0
numero_entradas_2020 = 0
while i < quantidade_anotacoes:
    data_anotacao.append(input())
    quantidade_visualizacoes.append(int(input()))
    i += 1

i = 0

while i < quantidade_anotacoes:
    ano_anotacao.append(data_anotacao[i][0:4])
    if ano_anotacao[i] == "2018":
        total_2018 += quantidade_visualizacoes[i]
        anotacoes_trienio += 1
        numero_entradas_2018 += 1
    elif ano_anotacao[i] == "2019":
        total_2019 += quantidade_visualizacoes[i]
        anotacoes_trienio += 1
        numero_entradas_2019 += 1
    elif ano_anotacao[i] == "2020":
        total_2020 += quantidade_visualizacoes[i]
        anotacoes_trienio += 1
        numero_entradas_2020 += 1
    i += 1
total_trienio = total_2018 + total_2019 + total_2020
media_trienio = '%.2f' % (total_trienio / anotacoes_trienio)
if total_trienio != 0:
    porcentagem_2018 = '%.2f' % ((100 * total_2018) / total_trienio)
    porcentagem_2019 = '%.2f' % ((100 * total_2019) / total_trienio)
    porcentagem_2020 = '%.2f' % ((100 * total_2020) / total_trienio)
else:
    porcentagem_2018 = "indeterminada"
    porcentagem_2019 = "indeterminada"
    porcentagem_2020 = "indeterminada"
media_2018 = '%.2f' % (total_2018 / numero_entradas_2018)
media_2019 = '%.2f' % (total_2019 / numero_entradas_2019)
media_2020 = '%.2f' % (total_2020 / numero_entradas_2020)
print("Canal:", nome_canal)
print("Total de views do trienio:", total_trienio)
print("Media de views do trienio:", media_trienio)
print()
print("2018")
print("Total:", total_2018)
print("Porcentagem das views do trienio:", porcentagem_2018)
print("Media:", media_2018)
print()
print("2019")
print("Total:", total_2019)
print("Porcentagem das views do trienio:", porcentagem_2019)
print("Media:", media_2019)
print()
print("2020")
print("Total:", total_2020)
print("Porcentagem das views do trienio:", porcentagem_2020)
print("Media:", media_2020)