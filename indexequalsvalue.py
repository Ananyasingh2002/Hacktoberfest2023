def valueEqualToIndices(numArray, n):

    lis=[]

    for i in range(n):

        if i== numArray[i]:

            lis.append(numArray[i])

    if len(lis)>0:

        return lis

    else:

        lis.append(-1)

        return lis
