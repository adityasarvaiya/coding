class Solution {
    // TODO: CRIO_TASK_MODULE_L1_PROBLEMS
    // complete the below function implementation
    public boolean searchMatrix(int[][] matrix, int target) {
        // CRIO_SOLUTION_START_MODULE_L1_PROBLEMS
        if(matrix.length == 0) {
            return false;
        }
        int i = 0, j = matrix[0].length - 1;
        while(i < matrix.length && j >= 0) {
            if(matrix[i][j] > target) {
                j--;
            } else if(matrix[i][j] < target) {
                i++;
            } else {
                return true;
            }
        }
        return false;
        // CRIO_SOLUTION_END_MODULE_L1_PROBLEMS
    }
}
