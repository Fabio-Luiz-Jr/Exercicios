def pre_aritmetica():
    for x in entrada_dividida:  # Remove o sinal de '+' da entrada.
        if x == '+':
            entrada_dividida.remove('+')
    y = 0
    for x in entrada_dividida:  # Se for o caso, troca a variavel por seu valor.
        if x in variaveis:
            entrada_dividida[y] = variaveis.get(x)
        y += 1
    z = 0
    while z < len(entrada_dividida):  # Une o sinal de '+' com o próximo número.
        if entrada_dividida[z] == '-':
            for x in str(entrada_dividida[z + 1]):
                if x == '-':
                    entrada_dividida[z] = str(entrada_dividida[z + 1]).strip('-')
                    break
                else:
                    entrada_dividida[z] = '-' + str(entrada_dividida[z + 1])
                    break
            entrada_dividida.pop(z + 1)
        z += 1
    return entrada_dividida


def booleana(entrada_dividida):  # Para todos os casos, soma todos os números antes e depois da operação de booleana ->
    z = 0  # -> e depois a calcula, retornando '1' ou '0'.
    while z < len(entrada_dividida):
        if entrada_dividida[z] == '<':
            entrada_dividida_1 = entrada_dividida[:z]
            entrada_dividida_2 = entrada_dividida[z + 1:]
            if sum(map(int, entrada_dividida_1)) < sum(map(int, entrada_dividida_2)):
                return "1"
            else:
                return "0"

        elif entrada_dividida[z] == '>':
            y = 0
            for x in entrada_dividida:
                if x in variaveis:
                    entrada_dividida[y] = variaveis.get(x)
                y += 1
            entrada_dividida_1 = entrada_dividida[:z]
            entrada_dividida_2 = entrada_dividida[z + 1:]
            if sum(map(int, entrada_dividida_1)) > sum(map(int, entrada_dividida_2)):
                return "1"
            else:
                return "0"
        elif entrada_dividida[z] == '<=':
            entrada_dividida_1 = entrada_dividida[:z]
            entrada_dividida_2 = entrada_dividida[z + 1:]
            if sum(map(int, entrada_dividida_1)) <= sum(map(int, entrada_dividida_2)):
                return "1"
            else:
                return "0"

        elif entrada_dividida[z] == '>=':
            entrada_dividida_1 = entrada_dividida[:z]
            entrada_dividida_2 = entrada_dividida[z + 1:]
            if sum(map(int, entrada_dividida_1)) >= sum(map(int, entrada_dividida_2)):
                return "1"
            else:
                return "0"
        elif entrada_dividida[z] == '!=':
            entrada_dividida_1 = entrada_dividida[:z]
            entrada_dividida_2 = entrada_dividida[z + 1:]
            if sum(map(int, entrada_dividida_1)) != sum(map(int, entrada_dividida_2)):
                return "1"
            else:
                return "0"

        elif entrada_dividida[z] == '==':
            entrada_dividida_1 = entrada_dividida[:z]
            entrada_dividida_2 = entrada_dividida[z + 1:]
            if sum(map(int, entrada_dividida_1)) == sum(map(int, entrada_dividida_2)):
                return "1"
            else:
                return "0"
        z += 1


def calcula_variavel():  # Calcula o valor da variável
    variavel.append(entrada_dividida[0])  # Salva a variável da entrada em uma nova variável
    entrada_dividida.pop(0)  # Elimina a variavel da entrada
    entrada_dividida.pop(0)  # Elimina o sinal '=' da entrada
    pre_aritmetica()
    w = len(variavel) - 1
    if "AND" in entrada_dividida or "OR" in entrada_dividida:
        variaveis[variavel[w]] = calcula_boo_composta()
    elif "<" in entrada_dividida or ">" in entrada_dividida or "<=" in entrada_dividida or ">=" in \
            entrada_dividida or "!=" in entrada_dividida or "==" in entrada_dividida:
        variaveis[variavel[w]] = booleana(entrada_dividida)
    else:  # Para os 3 casos do if, calcula o define um valor para uma variável salva no dicionário 'variaveis'.
        variaveis[variavel[w]] = (sum(map(int, pre_aritmetica())))


def calcula_aritmetica():  # Retorna um valor calculado de forma aritmética.
    return sum(map(int, pre_aritmetica()))


def calcula_boo():  # Retorna um valor booleano de '1' ou '0'.
    pre_aritmetica()
    return booleana(entrada_dividida)


def calcula_boo_composta():  # Retorna um valor booleano de '1' ou '0'.
    entrada_dividida = pre_aritmetica()
    entrada_dividida2 = entrada_dividida
    boo_comp = []
    p = 0
    n = -1
    while p < len(entrada_dividida2):
        if entrada_dividida2[p] == 'AND' or entrada_dividida2[p] == 'OR':
            entrada_dividida = entrada_dividida2[n + 1:p]
            if " < " in entrada_dividida or " > " in entrada_dividida or " <= " in entrada_dividida or " >= " \
                    in entrada_dividida or " != " in entrada_dividida or " == " in entrada_dividida:
                boo_comp.append(sum(map(int, entrada_dividida)))
                boo_comp.append(entrada_dividida2[p])
            else:
                boo_comp.append(booleana(entrada_dividida))  # Retorna um valor da booleana simples, se for o caso.
                boo_comp.append(entrada_dividida2[p])
            n = p
        p += 1
        if n != p and p == len(entrada_dividida2):
            entrada_dividida = entrada_dividida2[n + 1:p]
            if " < " in entrada_dividida or " > " in entrada_dividida or " <= " in entrada_dividida or " >= " \
                    in entrada_dividida or " != " in entrada_dividida or " == " in entrada_dividida:
                boo_comp.append(sum(map(int, entrada_dividida)))
            else:
                boo_comp.append(booleana(entrada_dividida))
    g = 0
    for x in boo_comp:
        if x != "AND" and x != "OR":
            boo_comp[g] = int(boo_comp[g])
        g += 1
    while len(boo_comp) > 1:  # Calcula a booleana composta.
        p = 0
        while p < len(boo_comp):
            if boo_comp[p] == 'AND' or boo_comp[p] == 'OR':
                if boo_comp[p] == 'AND':
                    boo_comp[p + 1] = boo_comp[p - 1] and boo_comp[p + 1]
                    boo_comp[p - 1] = "apagar"
                    boo_comp[p] = "apagar"
                if boo_comp[p] == 'OR':
                    boo_comp[p + 1] = boo_comp[p - 1] or boo_comp[p + 1]
                    boo_comp[p - 1] = "apagar"
                    boo_comp[p] = "apagar"
            for h in boo_comp:
                if h == "apagar":
                    boo_comp.remove("apagar")
            for x in boo_comp:
                if x == "apagar":
                    boo_comp.remove("apagar")
            p += 1
    return boo_comp[0]


variavel = []
variaveis = {}
while True:  # Repete o código até não ter mais entradas.
    try:  # Mostra uma mensagem quando não tem mais entradas.
        try:  # Retorna o erro de referência quando ocorrer.
            entrada = input()
            entrada_dividida = entrada.split(" ")
            teste_erro_2 = entrada.split(" ")
            if " = " in entrada:  # Calcula a variável.
                teste_erro = list(entrada)
                if teste_erro[0].isalpha():
                    for x in teste_erro_2[0]:
                        if x.isalpha() or x.isalnum():
                            pass
                        else:
                            try:  # Retorna o erro de sintaxe quando ocorrer.
                                erro = 1 / 0
                            except:
                                entrada_erro = entrada.split(" ")
                                print("Erro de sintaxe:", entrada_erro[0], "nao e um nome permitido para uma variavel.")
                    calcula_variavel()

                else:
                    try:  # Retorna o erro de sintaxe quando ocorrer.
                        erro = 1 / 0
                    except:
                        entrada_erro = entrada.split(" ")
                        print("Erro de sintaxe:", entrada_erro[0], "nao e um nome permitido para uma variavel.")
            elif " AND " in entrada or " OR " in entrada:  # Retorna o valor da booleana complexa
                print(calcula_boo_composta())
            elif " < " in entrada or " > " in entrada or " <= " in entrada or " >= " in entrada or \
                    ' != ' in entrada or " == " in entrada:  # Retorna o valor da booleana
                print(calcula_boo())
            else:  # Retorna a conta aritmética
                print(calcula_aritmetica())
        except ValueError as error:
            erro1 = str(error)
            erro2 = list(erro1)
            if erro2[41] == "-":
                print("Erro de referencia: a variavel", ''.join(erro2[42:-1]), "nao foi definida.")
            else:
                print("Erro de referencia: a variavel", ''.join(erro2[41:-1]), "nao foi definida.")
    except EOFError:
        print("Encerrando... Bye-bye.")
        break
