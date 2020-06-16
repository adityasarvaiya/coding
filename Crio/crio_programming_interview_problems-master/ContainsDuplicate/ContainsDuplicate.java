import java.io.*;
import java.util.*;

public class ContainsDuplicate {
    // Implement your solution by completing the below function
    public boolean containsDuplicate(int[] nums) {
        // CRIO_SOLUTION_START_MODULE_L1_PROBLEMS
        Set<Integer> set = new HashSet<Integer>();
        for (int num : nums) {
            if (set.contains(num))
                return true;
            set.add(num);
        }
        return false;
        // CRIO_SOLUTION_END_MODULE_L1_PROBLEMS

        // CRIO_UNCOMMENT_START_MODULE_L1_PROBLEMS
        //return -1;
        // CRIO_UNCOMMENT_END_MODULE_L1_PROBLEMS
    }

    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        int[] nums = new int[scanner.nextInt()];
        for (int i = 0; i < nums.length; i++)
            nums[i] = scanner.nextInt();
        scanner.close();

        boolean result = new ContainsDuplicate().containsDuplicate(nums);
        System.out.print(String.valueOf(result));
    }
}