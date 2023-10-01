class Solution:
    def uniquePaths(self, m: int, n: int) -> int:
        row = [1] * n
        
        for i in range(m-1):
            new = [1] * n
            for ind in range(n-2, -1, -1):
                new[ind] = new[ind + 1] + row[ind]
            row = new
        
        return row[0]