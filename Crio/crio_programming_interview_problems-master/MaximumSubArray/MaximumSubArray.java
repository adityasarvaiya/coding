import java.io.*;
import java.util.*;

public class MaximumSubArray {
    // Implement your solution by completing the below function
    public int maxSubArray(int[] nums) {
        // CRIO_SOLUTION_START_MODULE_L1_PROBLEMS
        int n = nums.length;
        int currSum = nums[0], maxSum = nums[0];

        for (int i = 1; i < n; ++i) {
            currSum = Math.max(nums[i], currSum + nums[i]);
            maxSum = Math.max(maxSum, currSum);
        }
        return maxSum;
        // CRIO_SOLUTION_END_MODULE_L1_PROBLEMS

        // CRIO_UNCOMMENT_START_MODULE_L1_PROBLEMS
        //return Integer.MIN_VALUE;
        // CRIO_UNCOMMENT_END_MODULE_L1_PROBLEMS
    }

    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);

        int[] nums = new int[scanner.nextInt()];
        for (int i = 0; i < nums.length; i++)
            nums[i] = scanner.nextInt();
        scanner.close();

        int result = new MaximumSubArray().maxSubArray(nums);
        System.out.print(Integer.toString(result));
    }
}
