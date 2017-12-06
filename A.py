while(True):
    a = float(input())
    if(a == 0):
        break
    if(a <= 5000000):
        if(a > 1000000):
            print (int(a*(0.9)))
        else:
            print (int(a))
    else:
        print (int(a*(0.8)))
