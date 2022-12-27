def registra_pessoas(registro_p):  # Divide a entrada em dois valores (característica e valor).
    a, b = registro_p.split(': ')
    return a, b


def registra_evidencias(registro_e):  # Divide a entrada em dois valores (característica e valor).
    c, d = registro_e.split(': ')
    return c, d


def define_suspeitos():
    suspeitos = []
    n = 0
    while n < len(lista_pessoas):  # Vê se a pessoa tem todas as evidências.
        if len([x for x in lista_pessoas[n] if x in evidencias]) == len(evidencias):
            if len([x for x in lista_pessoas[n].values() if x in evidencias.values()]) == len(evidencias):
                suspeitos.append(lista_pessoas[n].get('Nome'))  # Adiciona pessoa na lista de suspeitos.
        n += 1
    suspeitos_finais = sorted(suspeitos)
    if len(suspeitos_finais) == 0:  # Quando não tiver nenhum suspeito (retorna uma mensagem ->
        print('Nenhum suspeito(a) com essas caracteristicas foi identificado(a).')  # -> predefinida).
        return None
    if len(suspeitos_finais) == 1:  # Quando tiver apenas um suspeito (retorna uma mensagem predefinida e o nome do  ->
        print('Suspeito(a):')  # -> suspeito).
        print(suspeitos_finais[0])
        return None
    print('Suspeitos(as):')  # Quando tiver mais de um suspeito (retorna uma mensagem predefinida e o nome dos ->
    print(*suspeitos_finais, sep="\n")  # -> suspeitos.
    return None


entrada = '-'
lista_pessoas = []
evidencias = {}
while entrada != '---':  # Fica em um loop para registrar todas as pessoas e evidências (loop quebra quando a entrada ->
    if entrada == '-':  # -> for '---').
        pessoas = {}
        while entrada != '--':
            entrada = input()
            if entrada != '-' and entrada != '--':
                categoria_p, valor_p = registra_pessoas(entrada)
                pessoas[categoria_p] = valor_p
            else:
                lista_pessoas.append(pessoas)  # Registra todas as pessoas em uma lista de dicionários.
                pessoas = {}
    if entrada == '--':
        while entrada != '---':
            entrada = input()
            if entrada != '--' and entrada != '---':
                categoria_e, valor_e = registra_evidencias(entrada)
                evidencias[categoria_e] = valor_e  # Registra todas as evidências em um dicionário.
define_suspeitos()
