x = int(input("Entre com x: "))
if x % 2 == 0:
    x = x + 1
    if x % 3 == 0:
        x = x - 1
print(x)