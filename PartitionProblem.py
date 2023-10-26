def isSubsetSum(arr, n, sum, dp):
 
    # Base Cases
    if (sum == 0):
        return True
    if (n == 0 and sum != 0):
        return False
 
    # return solved subproblem
    if (dp[n][sum] != -1):
        return dp[n][sum]
 
    # If last element is greater than sum, then
    # ignore it
    if (arr[n - 1] > sum):
        return isSubsetSum(arr, n - 1, sum, dp)
 
        # else, check if sum can be obtained by any of
        # the following
        # (a) including the last element
        # (b) excluding the last element
 
    # also store the subproblem in dp matrix
    dp[n][sum] = isSubsetSum(
        arr, n - 1, sum, dp) or isSubsetSum(arr, n - 1, sum - arr[n - 1], dp)
 
    return dp[n][sum]
 
# Returns true if arr[] can be partitioned in two
# subsets of equal sum, otherwise false
 
 
def findPartiion(arr, n):
 
    # Calculate sum of the elements in array
    sum = 0
    for i in range(n):
        sum += arr[i]
 
    # If sum is odd, there cannot be two subsets
    # with equal sum
    if (sum % 2 != 0):
        return False
 
    # To store overlapping subproblems
    dp = [[-1]*(sum+1) for i in range(n+1)]
 
    # Find if there is subset with sum equal to
    # half of total sum
    return isSubsetSum(arr, n, sum // 2, dp)
 
# Driver code
 
 
arr = [3, 1, 5, 9, 12]
n = len(arr)
 
# Function call
if (findPartiion(arr, n) == True):
    print("Can be divided into two subsets of equal sum")
else:
    print("Can not be divided into two subsets of equal sum")
 
arr2 = [3, 1, 5, 9, 14]
n2 = len(arr2)
 
if (findPartiion(arr2, n2) == True):
    print("Can be divided into two subsets of equal sum")
else:
    print("Can not be divided into two subsets of equal sum")
