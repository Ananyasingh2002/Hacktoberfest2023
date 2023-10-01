#Checking whether a word is an anagram

def anagram(a, b):
    
    d = {}

    for alphabet in a:

        if alphabet not in d:
            d[alphabet] = 1

        else:
            d[alphabet] += 1
    
    for alphabet in b:

        if alphabet in d:
            d[alphabet] -= 1

        else:
            break

    check = 0

    for i in d.values():

        if i != 0:
            check = 1

    if check == 1:
        return False
    
    else:
        return True
            

print(anagram('angle', 'angel'))