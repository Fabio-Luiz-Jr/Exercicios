def cria_matriz(m, n):  # Monta as matrizes separando em "Ma" a matriz maior e "Me" a menor.
    if m < n:
        for x in range(m):
            Me.append(input().split(' '))
        for x in range(n):
            Ma.append(input().split(' '))
    else:
        for x in range(m):
            Ma.append(input().split(' '))
        for x in range(n):
            Me.append(input().split(' '))
    p = 0
    while p < len(Ma):
        Ma[p] = [int(x) for x in Ma[p]]
        p += 1
    q = 0
    while q < len(Me):
        Me[q] = [int(x) for x in Me[q]]
        q += 1
    return Ma, Me


def calc_super_mtx(interseccao):  # Define o menor tamanho possível para a super-matriz.
    cria_matriz(m, n)
    p = 0
    while p < len(Me):
        q = 0
        while q < len(Ma):
            interseccao += len([x for x in Me[p] if x in Ma[q]])
            q += 1
        p += 1
    if interseccao == len(Me) ** 2:  # Retorna o tamanho da super-matriz quando uma matriz está dentro de outra.
        print(len(Ma), "x", len(Ma))
        return None
    if interseccao == 1:  # Retorna o tamanho da super-matriz quando apenas 1 número é igual.
        print(m + n - 1, "x", m + n - 1)
        return None
    p = 0
    while p < len(Ma):
        if len([x for x in Me[0] if x in Ma[p]]) != 0:  # Calcula o tamanho da super-matriz quando pelo menos 1 ->
            linha = len(Me) + p  # -> número da primeira linha da matriz menor está dentro da matriz maior.
            coluna = len(Ma) + len(Me) - len([x for x in Me[0] if x in Ma[p]])
        elif len([x for x in Me[len(Me) - 1] if x in Ma[p]]) != 0:  # Calcula o tamanho da super-matriz quando pelo ->
            if len([x for x in Me[0] if x in Ma[0]]) != 0:  # -> menos 1 número da última linha da matriz menor está ->
                linha = len(Ma)  # -> dentro da matriz maior.
            elif len([x for x in Me[len(Me) - 1] if x in Ma[len(Ma) - 1]]) != 0:
                linha = len(Ma)
            else:
                if p == (len(Me) + 1):
                    linha = len(Ma)
                else:
                    linha = len(Me) + len(Ma) - 1 - p
                if p == len(Me):
                    linha += 1
            coluna = len(Ma) + len(Me) - len([x for x in Me[len(Me) - 1] if x in Ma[p]])
        p += 1
    p = 0
    linha_igual = 0
    while p < len(Me):  # Calcula o tamanho da super-matriz quando a primeira ou última linha da menor matriz está ->
        q = 0  # -> dentro da maior matriz.
        while q < len(Ma):
            if Me[p][0] in Ma[q] or Me[p][len(Me) - 1] in Ma[q]:
                linha_igual += 1
            q += 1
        p += 1
    if linha_igual == len(Me):
        linha = len(Ma)
    print(linha, "x", coluna)  # Retorna o tamanho da super-matriz caso não tenha anteriormente.
    return None


m = 1
n = 1
while m != 0 and n != 0:  # Calcula o tamanho da super-matriz caso "m" e "n" sejam diferentes de "0".
    v_inter = 0
    entrada = input().split(' ')
    m = int(entrada[0])
    n = int(entrada[1])
    if m != 0 and n != 0:
        Ma = []
        Me = []
        calc_super_mtx(v_inter)
