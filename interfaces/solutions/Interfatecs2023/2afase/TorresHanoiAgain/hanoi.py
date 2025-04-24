n = int(input())
torre = input().replace(" ", "").strip()
x = int(torre, 2)
#y = int("1"*len(torre), 2)
y = 2**n - 1

torre = set(torre)
print(torre)
print(len(torre))
print(x, y)

print(y-x)
