def checkARMno(num):
    sum=0
    for i in str(num):
        sum+=int(i)**3
    if num==sum:
        print("It is a amrstrong number")
    if num!=sum:
        print("not a amrstong number")
a=int(input("enter a number:"))
checkARMno(a) 