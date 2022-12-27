Material = input("Entre com o material: ")
Ponto_fusao = float(input("Entre com o ponto de fusão(°C): "))
Ponto_ebulicao = float(input("Entre com o ponto de ebulição(°C): "))
Temperatura_atual = (float(input("Entre com a temperatura atual(°F): "))-32)/1.8
Estado_fisico = ''
if Temperatura_atual < Ponto_fusao:
    Estado_fisico = 'Solido'
if Temperatura_atual >= Ponto_fusao:
    Estado_fisico = 'Liquido'
if Temperatura_atual >= Ponto_ebulicao:
    Estado_fisico = 'Gasoso'

Ponto_fusao = round(Ponto_fusao, 2)
Ponto_fusao = '%.2f' % Ponto_fusao
Ponto_ebulicao = round(Ponto_ebulicao, 2)
Ponto_ebulicao = '%.2f' % Ponto_ebulicao
Temperatura_atual = round(Temperatura_atual, 2)
Temperatura_atual = '%.2f' % Temperatura_atual

print('Material:', Material)
print('Ponto de fusao (Celsius):', Ponto_fusao)
print('Ponto de ebulicao (Celsius):', Ponto_ebulicao)
print('Temperatura atual (Celsius):', Temperatura_atual)
print('Estado fisico do material:', Estado_fisico)