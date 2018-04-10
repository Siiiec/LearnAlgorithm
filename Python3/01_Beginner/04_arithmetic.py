if __name__ == '__main__':
    x = int(input())
    y = int(input())
    print('x = {}'.format(x))
    print('y = {}'.format(y))
    print('x + y = {}'.format(x + y))
    print('x - y = {}'.format(x - y))
    print('x * y = {}'.format(x * y))
    div = x // y if y != 0 else 'DIV/0!'
    print('x / y = {}'.format(div))
    mod = x % y if y != 0 else 'DIV/0!'
    print('x % y = {}'.format(mod))