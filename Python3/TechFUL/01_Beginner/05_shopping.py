if __name__ == '__main__':
    kakaku = int(input())
    kosuu = int(input())
    print('{}円の商品を{}個買いました。  \n合計金額は{}円です。  '\
        .format(kakaku, kosuu, kakaku * kosuu), end='')