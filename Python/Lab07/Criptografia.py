def codificar():
    j = 0
    k = 0
    x = 1
    while x <= L:
        if (x % 2) == 0:  # Executa se estiver lendo uma linha par
            ahnil = Linha[j][::-1]  # Inverte as letras
            lista_caracteres = ahnil
            lista_ascii = [ord(character) for character in lista_caracteres]  # Transforma caracteres em código ASCII
            lista_codificada = ['{:o}'.format(n) for n in lista_ascii]  # Transforma os códigos ASCII em octal
            while k < len(lista_codificada):
                if E > len(lista_codificada[k]):
                    lista_codificada[k] = lista_codificada[k].zfill(E)  # Preenche com "0" quando nescessário
                k += 1
            print("".join(lista_codificada))
            k = 0
        else:  # Executa se estiver lendo uma linha ímpar
            lista_caracteres = Linha[j]
            lista_ascii = [ord(character) for character in lista_caracteres]  # Transforma caracteres em código ASCII
            lista_codificada = ['{:X}'.format(n) for n in lista_ascii]  # Transforma os códigos ASCII em octal
            while k < len(lista_codificada):
                if E > len(lista_codificada[k]):
                    lista_codificada[k] = lista_codificada[k].zfill(E)  # Preenche com "0" quando nescessário
                k += 1
            print("".join(lista_codificada))
            k = 0
        j += 1
        x += 1


def decodificar():
    j = 0
    k = 0
    x = 1
    while x <= L:
        lista_ascii = []
        palavra = []
        if (x % 2) == 0:  # Executa se estiver lendo uma linha par
            lista_octal = [Linha[j][p:p + E] for p in range(0, len(Linha[j]), E)]  # Quebra o código em uma lista
            while k < len(lista_octal):
                lista_ascii.append(int(lista_octal[k], 8))  # Converte o octal em ASCII
                palavra.append(chr(lista_ascii[k]))  # Converte o ASCII em letras e espaços
                k += 1
            palavra = palavra[::-1]  # Inverte as letras
            print("".join(palavra))
            k = 0
        else:  # Executa se estiver lendo uma linha ímpar
            lista_hexa = [Linha[j][p:p + E] for p in range(0, len(Linha[j]), E)]  # Quebra o código em uma lista
            while k < len(lista_hexa):
                lista_ascii.append(int(lista_hexa[k], 16))  # Converte o hexadecimal em ASCII
                palavra.append(chr(lista_ascii[k]))  # Converte o ASCII em letras e espaços
                k += 1
            print("".join(palavra))
            k = 0
        j += 1
        x += 1


MEL = input()  # Pega M, E e L
mel_split = MEL.split()
M = mel_split[0]
E = int(mel_split[1])
L = int(mel_split[2])
i = 0
Linha = []
while i < L:
    Linha.append(input())
    i += 1
if M == "1":  # Decide se vai codificar ou decodificar
    codificar()
elif M == "2":
    decodificar()
