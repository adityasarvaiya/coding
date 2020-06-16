import java.io.*;
import java.util.*;

class ShortestUnsortedContinuousSubarray {
    
    // Complete the function implementation below
    public int findUnsortedSubarrayLength(int[] nums) {
        // CRIO_SOLUTION_START_MODULE_L1_PROBLEMS
        int n = nums.length, beg = -1, end = -2, min = nums[n-1], max = nums[0];
        for (int i = 1; i < n; i++) {
            max = Math.max(max, nums[i]);
            min = Math.min(min, nums[n-1-i]);
            if (nums[i] < max) end = i;
            if (nums[n-1-i] > min) beg = n-1-i; 
        }
        return end - beg + 1;
        // CRIO_SOLUTION_END_MODULE_L1_PROBLEMS
    }

    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        int n = scanner.nextInt();
        int nums[] = new int[n];
        for(int i = 0 ; i < n; i++) {
            nums[i] = scanner.nextInt();
        }
        int result = new ShortestUnsortedContinuousSubarray().findUnsortedSubarrayLength(nums);
        System.out.println(result);
    }
}