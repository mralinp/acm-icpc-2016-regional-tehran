while(True):
    n, m = list(map(int, input().split(" ")))
    if (n == 0 and m == 0):
        break
    coustomer = list(map(int, input().split(" ")))
    # print (coustomer)
    counter = 0
    for i in range(m):
        l = list(map(int, input().split(" ")))
        counter += 1
        for i in range(n):
            if(l[i] > coustomer[i]):
                counter -= 1
                break
    print (counter)
