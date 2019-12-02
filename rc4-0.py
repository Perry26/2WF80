from itertools import product

def rc4(k, l, numbytes):
    S = [None]*256
    for i in range(0, 256):
        S[i] = i
    j=0
    for i in range(0, 256):
        j = (j + S[i] + k[i % l]) % 256
        dummy = S[i] 
        S[i] = S[j]
        S[j] = dummy

    i = 0
    j = 0
    result = [None]*numbytes
    for n in range(numbytes):
        i = (i+1) % 256
        j = (j + S[i]) % 256
        dummy = S[i] 
        S[i] = S[j]
        S[j] = dummy
        c = S [ (S[i] + S[j]) % 256 ]
        result[n] = c
    return result

def bruteForce():
    key = [80, 0, 0, 0, 0]
    outputSequence  = [130, 189, 254, 192, 238, 132, 216, 132, 82, 173]
    for a,b,c,d in product(range(256),range(256),range(256),range(256)):
        key[1] = a
        key[2] = b
        key[3] = c
        key[4] = d
        if (c == 0 and d == 0):
            print( "{}, {}, {}, {}".format(a,b,c,d) )
        out = rc4(key, 5, 10)
        if (out == outputSequence):
            print("Done: " + str(key))
            return

bruteForce()
