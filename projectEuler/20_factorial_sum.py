num = 100
sum = 0

for i in range(99, 0, -1):
    num *= i

while num != 0:
    sum += num % 10
    num //= 10

print(sum)
