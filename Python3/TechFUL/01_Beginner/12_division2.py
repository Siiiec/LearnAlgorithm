a = int(input())
b = int(input())

divf = a / b
div = a // b

if divf == div:
    print('{:.1f}'.format(div))
else:
    print(divf)