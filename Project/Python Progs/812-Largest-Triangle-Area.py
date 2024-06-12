import math
class Solution:
    def fun(self, points):
        n = len(points)
        maxArea = 0
        for i in range(n):
            for j in range(i + 1, n):
                for k in range(j + 1, n):
                    d1 = math.sqrt((points[i][0] - points[j][0]) ** 2 + (points[i][1] - points[j][1]) ** 2)
                    d2 = math.sqrt((points[j][0] - points[k][0]) ** 2 + (points[j][1] - points[k][1]) ** 2)
                    d3 = math.sqrt((points[i][0] - points[k][0]) ** 2 + (points[i][1] - points[k][1]) ** 2)
                    s = (d1 + d2 + d3) / 2.00000
                    area = math.sqrt(s * (s - d1) * (s - d2) * (s - d3))
                    if maxArea < area:
                        maxArea = area
        return maxArea
solution = Solution()
points = [[0,0],[0,1],[1,0],[0,2],[2,0]]
result = solution.fun(points)
print(result)
