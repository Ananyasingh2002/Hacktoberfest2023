# Python program to check whether the given number is Buzz Number or not. 

# function to check Buzz number. 
def isBuzz(num) : 
	
	# checking if the number 
	# ends with 7 and is divisible by 7 
	return (num % 10 == 7 or num % 7 == 0) 

# Conditional Statement 
n = int(input())
if (isBuzz(n)) : 
	print ("Buzz Number") 
else : 
	print ("Not a Buzz Number")
