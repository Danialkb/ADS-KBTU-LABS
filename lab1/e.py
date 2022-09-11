import math
a = list(map(int, input().split()))
b = list(map(int, input().split()))
cnt = 0
bound = math.pow(10, 6)
while True:
    if cnt >= bound:
        print('blin nichya')
        break
    elif len(a) == 0:
        print("Nursik", cnt)
        break
    elif len(b) == 0:
        print("Boris", cnt)
        break
    elif a[0] > b[0]:
        tmp = a[0]
        a.pop(0)
        a.append(tmp)
        a.append(b[0])
        b.pop(0)
    elif len(b) != 0 and b[0] > a[0]:
        tmp = b[0]
        b.pop(0)
        b.append(a[0])
        b.append(tmp)
        a.pop(0)
    cnt += 1

    