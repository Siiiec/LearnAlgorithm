n = int(input())
gen = ('*' * (i) + '-' * (n - i) for i in range(n + 1))

for s in gen:
    print(s)