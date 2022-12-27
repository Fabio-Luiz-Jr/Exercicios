numero_linha_coluna = int(input())
peca_coluna_linha = input()
pcl = peca_coluna_linha.split(' ')
i = 1
j = 0
k = 0
casas = []
fileira = []
super_repeticao = 0
while super_repeticao < numero_linha_coluna:
    numero_linha = numero_linha_coluna - super_repeticao
    coluna = str((chr(96 + i)))
    linha = str(numero_linha)
    teste = coluna + linha
    casas.append(teste)
    fileira.append(casas[i - 1])
    i += 1
    if i > numero_linha_coluna:
        del casas[:]
        super_repeticao += 1
        i = 1
i = 0
n_casas = numero_linha_coluna * numero_linha_coluna
while i < n_casas:
    if j == numero_linha_coluna:
        j = 0
        k += 1
    if pcl[0] == "Torre":
        if (pcl[1] + pcl[2]) == fileira[i]:
            fileira[i] = 'o'
        elif (pcl[1] + str((numero_linha_coluna - k))) == fileira[i]:
            fileira[i] = 'x'
        elif (chr(97 + j) + pcl[2]) == fileira[i]:
            fileira[i] = 'x'
        else:
            fileira[i] = '-'

    i += 1
    j += 1

i = 0
j = 0
k = 0
while i < numero_linha_coluna:
    print(numero_linha_coluna - i, end=' ')
    i += 1
    while k < numero_linha_coluna - 1:
        print(fileira[n_casas - (n_casas - j)], end=' ')
        j += 1
        k += 1
        if k == numero_linha_coluna - 1:
            print(fileira[n_casas - (n_casas - j)])
            j += 1
    k = 0


i = 1
print(' ', end=' ')
while i <= numero_linha_coluna:
    print(chr(96 + i), end=' ')
    i += 1