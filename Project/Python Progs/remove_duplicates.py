''' 
Given a SORTED array, remove all the duplicates from the array.

Input - [0,0,1,1,1,2,2,3,3,4]
Output - [0,1,2,3,4]
'''

def Remove_Duplicates(L1):

    i = 1
    check = L1[0]

    while i < len(L1):

        if check == L1[i]:
            L1.pop(i)
            i -= 1

        else:
            check = L1[i]

        i += 1

    print(L1)

Remove_Duplicates( [0, 0, 1, 1, 1, 2, 2, 3, 3, 4] )