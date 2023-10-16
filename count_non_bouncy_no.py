# import reduce function from functools
from functools import reduce


# define a function to 
# calculate nCr 
def nCr(n, k):

# this approach is based on 
# approach of stars and bar method
# using reduce and lambda function
# to calculate number & denom
number = reduce(lambda x, y: x * y,
				list(range(n, n - k, -1))) 
denom = reduce(lambda x, y: x * y,
				list(range(1, k + 1)))	 

# denom root of number will be the final result
return number // denom	 

# Driver Code
# input value of k
k = 6

# calculating r using function call
r = int((nCr(k + 10, 10) +
		nCr(k + 9, 9) 
		- 2 - 10 * k))

# print final result
print(r % (1000000000 + 7))	 
