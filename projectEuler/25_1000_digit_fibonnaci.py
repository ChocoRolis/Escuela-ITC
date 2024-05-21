num1 = 1
num2 = 1
cont = 2

while num1 // 10**999 == 0:
    tmp = num1
    num1 = num1 + num2
    num2 = tmp

    cont += 1


print(cont)
