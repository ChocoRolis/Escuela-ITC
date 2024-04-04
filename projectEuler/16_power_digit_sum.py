num = 2**1000
cont = 0

while num != 0:
    cont += num % 10
    num //= 10

print(cont)
