from crio.io import PrintMatrix

class Solution:
    def __init__(self, matrix):
        self.matrix = matrix

    def rotateImage(self):
    # CRIO_SOLUTION_START_MODULE_L1_PROBLEMS
        n = len(self.matrix[0])        
        for i in range(n // 2 + n % 2):
            for j in range(n // 2):
                tmp = self.matrix[n - 1 - j][i]
                self.matrix[n - 1 - j][i] = self.matrix[n - 1 - i][n - j - 1]
                self.matrix[n - 1 - i][n - j - 1] = self.matrix[j][n - 1 -i]
                self.matrix[j][n - 1 - i] = self.matrix[i][j]
                self.matrix[i][j] = tmp
    # CRIO_SOLUTION_END_MODULE_L1_PROBLEMS

if __name__ == '__main__':
    n = int(input())
    matrix = []
    for i in range(n):
        nums = input().split()
        nums = [int(i) for i in nums]
        matrix.append(nums)
    sol = Solution(matrix)
    sol.rotateImage()
    PrintMatrix.SquareMatrix(sol.matrix)

