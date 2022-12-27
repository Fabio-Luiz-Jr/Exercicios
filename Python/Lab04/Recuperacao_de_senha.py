def n_tentativas(t):
    n_t = 0
    semelhanca = 0
    while n_t < t:
        i = 0
        senha = input()
        senha = list(senha)
        numero_senha = len(senha)
        if numero_senha == numero_caracteres:
            if senha == senha_mestra:
                situacao = "Senha reconhecida. Desativando defesas..."
                return situacao
            else:
                while i < numero_caracteres:
                    if senha[i] == senha_mestra[i]:
                        semelhanca += 1
                    i += 1
                print("Senha incorreta\nSemelhanca:", semelhanca)
                print("Tentativas restantes:", t - n_t - 1, "\n")
                semelhanca = 0
        else:
            print("Senha incorreta\nSemelhanca: Erro: quantidade de digitos incongruente")
            print("Tentativas restantes:", t - n_t - 1, "\n")
        n_t += 1
        if n_t == t:
            situacao = "Tentativas esgotadas. Acionando defesas..."
            return situacao


entrada = input()
senhamestra_e_t = entrada.split(' ')
senha_mestra = senhamestra_e_t[0]
t = int(senhamestra_e_t[1])
senha_mestra = list(senha_mestra)
numero_caracteres = len(senha_mestra)
print(n_tentativas(t))
