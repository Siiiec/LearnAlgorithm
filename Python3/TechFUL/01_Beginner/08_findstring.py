import re

def find_str(pattern, str):
    return len(re.findall(pattern, str))

str = input()
find = input()
print('文字列 : ', str, sep='')
print('検索文字列 : ', find, sep='')
print(find ,'の出現回数 : ', find_str(find, str), sep='')