def f(n):
    if n == 0:
        return 1
    elif n == 1:
        return 3
    else:
        return (n - 1) * f(n - 1) + f(n - 2) + 2

n = int(input())
print('f({}) = {}'.format(n ,f(n)))