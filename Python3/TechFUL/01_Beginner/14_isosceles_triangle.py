n = int(input())

tri = ('*' * i for i in range(1, n + 1))
irt = ('*' * i for i in range(n - 1, 0, -1))

for t in tri:
    print(t)

for t in irt:
    print(t)