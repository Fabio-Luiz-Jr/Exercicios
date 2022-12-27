from math import sqrt


def registra_esconderijo(x_y_juntos):  # Registra as coordenadas de todos os esconderijos.
    x, y = map(int, x_y_juntos.split(' '))
    coords_esconderijo = (x, y)
    return coords_esconderijo


def maior_dist_yi(lista_esconderijos, eixo_y):  # Calcula a maior distância para cada yi.
    maior_distancia_p_yi = {}
    yi = eixo_y - 1
    while yi > 0:
        maior_distancia = 0
        for k in range(len(lista_esconderijos)):
            x, y = lista_esconderijos[k]
            distancia = sqrt((0 - x) ** 2 + (yi - y) ** 2)  # Calcula a distância de cada ponto yi até cada esconderijo.
            if distancia > maior_distancia:  # Seleciona a maior distância para cada ponto yi.
                maior_distancia = distancia
                maior_distancia_p_yi[yi] = maior_distancia
        yi -= 1
    return list(maior_distancia_p_yi.items())


def ordem_crescente(lista_a_calcular):  # Ordena de forma crescente os pontos yi com base em sua distância até o ->
    for i in range(len(lista_a_calcular)):  # -> esconderijo mais distante.
        min = i
        for j in range(i + 1, len(lista_a_calcular)):
            if lista_a_calcular[j][1] < lista_a_calcular[min][1]:
                min = j
        lista_a_calcular[i], lista_a_calcular[min] = lista_a_calcular[min], lista_a_calcular[i]
    return lista_a_calcular[0][0]  # Retorna o ponto yi com a menor distância.


entrada = ''
while entrada != '0 0':  # Repete o código desde que a entrada seja diferente de '0 0'.
    u = 0
    lista_esconderijos = []
    entrada = input()
    if entrada != '0 0':
        N, Y = map(int, entrada.split(' '))
        while u < N:  # Loop para registrar N esconderijos.
            entrada = input()
            lista_esconderijos.append(registra_esconderijo(entrada))
            u += 1
        lista_maior_dist_yi = maior_dist_yi(lista_esconderijos, Y)
        print(ordem_crescente(lista_maior_dist_yi))
