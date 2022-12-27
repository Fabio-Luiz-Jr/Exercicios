from math import sqrt


def cria_matriz(linha, coluna):  # Cria uma matriz com M linhas e N colunas.
    matriz = []
    z = 0
    while z < linha:
        matriz.append(['-' for x in range(coluna)])  # Coloca um '-' em cada casa da matriz.
        z += 1
    return matriz


def escreve_quadrado(tela_pintada, i, j, l, p, q):  # Coloca o quadrado na tela.
    while p < len(tela_pintada):  # Repete enquanto p (linha / coordenada x) for menor que o número de linhas da tela.
        if p < int(i - (l - 1)/2):  # Vai para a próxima linha, caso o quadrado não esteja nela.
            return escreve_quadrado(tela_pintada, i, j, l, p + 1, q)
        elif p > int(i + (l - 1)/2):  # Retorna a tela pintada, caso tenha passado o quadrado.
            return tela_pintada
        if q < int(j - (l - 1)/2):  # Vai para a próxima coluna, caso o quadrado não esteja nela.
            return escreve_quadrado(tela_pintada, i, j, l, p, q + 1)
        elif q > int(j + (l - 1)/2):  # Caso a coluna tenha passado o quadrado, ele vai para a próxima linha e ->
            return escreve_quadrado(tela_pintada, i, j, l, p + 1, 0)  # -> primeira coluna.
        else:
            if p > len(tela_pintada) - 1 or q > len(tela_pintada[0]) - 1:  # Não faz nada se o ponto (p, q) estiver->
                pass  # -> fora da tela.
            else:  # Coloca um 'x' no ponto (p, q).
                tela_pintada[p][q] = 'x'
            q += 1
    return tela_pintada  # Retorna a tela com o quadrado "pintado" nela.


def escreve_circulo(tela_pintada, i, j, r, p, q):  # Coloca o circulo na tela.
    while p < len(tela_pintada):  # Repete enquanto p (linha / coordenada x) for menor que o número de linhas da tela.
        if p < i - r:  # Vai para a próxima linha, caso o circulo não estiver nela.
            return escreve_circulo(tela_pintada, i, j, r, p + 1, q)
        elif p > i + r:  # Retorna a tela pintada, caso tenha passado o circulo.
            return tela_pintada
        if q < j - r:  # Vai para a próxima coluna, caso o circulo não estiver nela.
            return escreve_circulo(tela_pintada, i, j, r, p, q + 1)
        elif q > j + r:  # Caso a coluna tenha passado o circulo, ele vai para a próxima linha e primeira coluna.
            return escreve_circulo(tela_pintada, i, j, r, p + 1, 0)
        distancia = sqrt((p - i) ** 2 + (q - j) ** 2)  # Calcula a distância entre o ponto (p, q) e o centro do circulo.
        if distancia > r:  # Se a distância for maior que o raio do circulo ele vai para a próxima coluna.
            return escreve_circulo(tela_pintada, i, j, r, p, q + 1)
        else:
            if p > len(tela_pintada) - 1 or q > len(tela_pintada[0]) - 1:  # Não faz nada se o ponto (p, q) estiver->
                pass  # -> fora da tela.
            else:  # Coloca um 'x' no ponto (p, q).
                tela_pintada[p][q] = 'x'
            q += 1
    return tela_pintada  # Retorna a tela com o circulo "pintado" nela.


M, N = map(int, input().split(' '))  # Registra o número de linhas e colunas da tela.
tela = cria_matriz(M, N)
Q = int(input())  # Define o número de formas geométricas a "pintar" na tela.
Rept = 0
while Rept < Q:  # Repete da linha 58 até 66 Q vezes.
    p = 0
    q = 0
    forma_geo, i, j, l_r = input().split(' ')  # Registra a forma geométrica, seu ponto central e seu raio ou lado.
    if forma_geo == 'quadrado':
        tela = escreve_quadrado(tela, int(i), int(j), int(l_r), p, q)  # Coloca o quadrado na tela.
    if forma_geo == 'circulo':
        tela = escreve_circulo(tela, int(i), int(j), int(l_r), p, q)  # Coloca o circulo na tela.
    Rept += 1
for x in range(len(tela)):  # Imprimi a tela.
    print(' '.join(tela[x]))
