def abc(dia_semana):
    j = 0
    end = []
    carac_endereco = []
    if dia_semana == 'segunda' or dia_semana == 'terca':
        while j < n_enderecos:
            mi = 0
            ma = 0
            carac_endereco.append('')
            carac_endereco[j] = str(list(endereco[j]))
            mi = sum(1 for g in endereco[j] if g.islower())
            ma = sum(1 for g in endereco[j] if g.isupper())
            if dia_semana == 'segunda':
                end.append(mi)
            elif dia_semana == 'terca':
                end.append(ma)
            j += 1

        if dia_semana == 'segunda':
            z = [x for _, x in sorted(zip(end, endereco))]
            return z
        elif dia_semana == 'terca':
            z = [x for _, x in sorted(zip(end, endereco), reverse=True)]
            return z

    elif dia_semana == 'quarta':
        while j < n_enderecos:
            pertence_alfabeto = sum(1 for h in endereco[j] if h.isalpha())
            end.append(pertence_alfabeto)
            j += 1
        z = [x for _, x in sorted(zip(end, endereco))]
        return z

    elif dia_semana == 'quinta':
        n_palavras = []
        while j < n_enderecos:
            palavras = endereco[j].split(' ')
            n_palavras.append(len(palavras))
            j += 1
        z = [x for _, x in sorted(zip(n_palavras, endereco))]
        return z

    elif dia_semana == 'sexta':
        soma_ascii = []
        while j < n_enderecos:
            soma_ascii.append(sum(ord(p) for p in endereco[j]))
            j += 1
        z = [x for _, x in sorted(zip(soma_ascii, endereco), reverse=True)]
        return z


semana = input()
semana = semana.split(' ')
dia_semana = semana[0].lower()
n_enderecos = int(semana[1])
endereco = []
i = 0
n = 0

while i < n_enderecos:
    endereco.append(input())
    i += 1

print(*abc(dia_semana), sep='\n')
