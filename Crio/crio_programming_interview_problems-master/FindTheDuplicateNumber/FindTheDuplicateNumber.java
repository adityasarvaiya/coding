import java.io.*;
import java.util.*;

// CRIO_SOLUTION_SUB_OPTIMAL

//This can be solved in O(n)
class FindTheDuplicateNumber {
		// TODO: CRIO_TASK_MODULE_L2_PROBLEMS
		// complete the below function implementation
	    public int findDuplicate(int[] nums) {
	    // CRIO_SOLUTION_START_MODULE_L2_PROBLEMS
      	Arrays.sort(nums);
      	int ans = 0;
        for(int i = 0 ; i < nums.length - 1; i++) {
            if(nums[i] == nums[i+1]) {
            	ans = nums[i];
            	// break;
            }
        }
        return ans;
        // CRIO_SOLUTION_END_MODULE_L2_PROBLEMS
        // CRIO_UNCOMMENT_START_MODULE_L2_PROBLEMS
        // return 0;
        // CRIO_UNCOMMENT_END_MODULE_L2_PROBLEMS
    }
    public static void main(String args[]) {
    	Scanner scanner = new Scanner(System.in);
        int n = scanner.nextInt();
        int nums[] = new int[n + 1];
        for(int i = 0 ; i < nums.length ;i++) {
        	nums[i] = scanner.nextInt();
        }
        scanner.close();
        int result = new FindTheDuplicateNumber().findDuplicate(nums);
        System.out.println(result);
    }
}
