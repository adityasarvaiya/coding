import java.io.*;
import java.util.*;

public class TwoSum {

    public int[] twoSum(int[] nums, int target) {
        // CRIO_SOLUTION_START_MODULE_L1_PROBLEMS
        Map<Integer, Integer> complements = new HashMap<>();

        for (int i = 0; i < nums.length; i++) {
            int complement = target - nums[i];
            if (complements.containsKey(complement))
                return new int[] { complements.get(complement), i };
            complements.put(nums[i], i);
        }
        return new int[] { -1, -1 };
        // CRIO_SOLUTION_END_MODULE_L1_PROBLEMS
    }

    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);

        int[] numbers = new int[scanner.nextInt()];
        for (int i = 0; i < numbers.length; i++)
            numbers[i] = scanner.nextInt();
        int target = scanner.nextInt();
        scanner.close();

        int[] complements = new TwoSum().twoSum(numbers, target);
        System.out.print(complements[0] + " " + complements[1]);
    }
}