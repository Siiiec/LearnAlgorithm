y = int(input())

isLeap = True

if y % 4 == 0:
    if y % 400 == 0:
        pass
    elif y % 100 == 0:
        isLeap = False
else:
    isLeap = False

print('{}年は{}年です'.format(y, 'うるう' if isLeap else '平'))