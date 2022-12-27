def cria_campo(linhas, colunas):
    campo = []
    for x in range(linhas):
        campo.append(["Vazio" for y in range(colunas)])
    return campo


def calcula_magia(linhas, colunas, casas, i, submagia):
    if casas == 1:
        submagia.append(0)
        return submagia
    elif 2 ** i * 2 ** i > casas > 0:
        while i > 0:
            if linhas % 2 ** (i - 1) == 0 and colunas % 2 ** (i - 1) == 0:
                submagia.append(i - 1)
                return calcula_magia(linhas, colunas, (casas - (2 ** (i - 1) * 2 ** (i - 1))), i - 1, submagia)
            else:
                i -= 1
    elif 2 ** i * 2 ** i == casas:
        while i > 0:
            if linhas % 2 ** (i - 1) == 0 and colunas % 2 ** (i - 1) == 0:
                submagia.append(i - 1)
                return calcula_magia(linhas, colunas, (casas - (2 ** (i - 1) * 2 ** (i - 1))), i - 1, submagia)
            else:
                i -= 1
    elif casas == 0:
        return submagia
    else:
        return calcula_magia(linhas, colunas, casas, i + 1, submagia)


#def ajusta_submagias(linhas, colunas, campo, submagia):
#    for z in range(submagia):
#        for v in range(linhas):
#            w = 0
#            while w <= colunas:
#                if campo[v][w] == "Ocupado":
#                    if w < colunas:
#                        w += 1
#
#                if 2 ** submagia[z] > linhas and 2 ** submagia[z] > colunas:
#                    submagia[z] -= 1
#                    z -= 1
#                else:
#                    for x in range(2 ** submagia[z]):
#                        for y in range(2 ** submagia[z]):
#                                campo[x][y] = "Ocupado"
#
linhas, colunas = map(int, input().split(' '))
print("---")
print("Grimorio de Teraf L'are")
print("---")
campo = cria_campo(linhas, colunas)
casas = linhas * colunas
submagia = calcula_magia(linhas, colunas, casas, 0, [])
#ajusta_submagias(linhas, colunas, campo, submagia)
total_submagias = []
submagias = []
for x in submagia:
    if x not in submagias:
        submagias.append(x)
        total_submagias.append(1)
    else:
        total_submagias[len(total_submagias) - 1] += 1
submagias.reverse()
total_submagias.reverse()
if linhas > 1 and colunas > 1:
    x = 0
    while x < len(total_submagias):
        if total_submagias[x] % 2 == 0:
            if total_submagias[x] % 4 == 0:
                total_submagias[x] -= 4
                if x + 1 == len(total_submagias):
                    total_submagias.append(0)
                    submagias.append(submagias[x - 1] + 1)
                total_submagias[x + 1] += 1
                y = 0
                while y < len(submagias):
                    if total_submagias[y] == 0:
                        total_submagias.pop(0)
                        submagias.pop(0)
                    else:
                        y += 1
        else:
            x += 1
for x in range(len(submagias)):
    print(total_submagias[x], "submagia(s) de nivel", submagias[x])
print("---")
total = 0
print("Total de submagia(s) conjurada(s):", sum(total_submagias))
for i in range(len(submagias)):
    total += total_submagias[i] * 2 ** submagias[i]
print("Total de PM gasto:", total)
print("---")
