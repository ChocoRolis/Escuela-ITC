sum = 0

for i in range(1, 1000):
    sum += (i**i) % 10000000000
    sum %= 10000000000

print(sum)

# 9110846700