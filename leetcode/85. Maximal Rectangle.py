class Solution:
    def maximalRectangle(self, matrix):
        def hist(heights):
            stack, ans = [], 0
            for i, h in enumerate(heights + [0]):
                while stack and heights[stack[-1]] >= h:
                    H = heights[stack.pop()]
                    W = i if not stack else i-stack[-1]-1
                    ans = max(ans, H*W)
                stack.append(i)
            return ans
        
        if not matrix or not matrix[0]: return 0
        m, n, ans = len(matrix[0]), len(matrix), 0
        row = [0]*m
        for i in range(n):
            for j in range(m):
                row[j] = 0 if matrix[i][j] == "0" else row[j] + 1
            ans = max(ans, hist(row))
            
        return ans
