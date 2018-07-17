import math

def nCr(n,r):
    f = math.factorial
    return f(n) / f(r) / f(n-r)

t = input()

s = input()
sl = s.split(" ")

even = 0
odd = 0

for si in sl:
    if int(si[-1]) % 2 == 0:
        even += 1
    else:
        odd +=1

combi = [i for i in range(odd + 1) if i % 2 == 0]

a = 0

for c in combi:
    a += nCr(odd, c)


b = a * pow(2, even)
print(int(b - 1))