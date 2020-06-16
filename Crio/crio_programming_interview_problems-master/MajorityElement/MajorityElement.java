import java.io.*;
import java.util.*;

public class MajorityElement {
    // Implement your solution by completing the below function
    public int majorityElement(int[] nums) {
        // CRIO_SOLUTION_START_MODULE_L1_PROBLEMS
        int floor = (int) Math.floor(nums.length / 2);
        if (floor == 0)
            return nums[0];
        HashMap<Integer, Integer> counts = new HashMap<Integer, Integer>();
        for (int num : nums) {
            if (counts.containsKey(num)) {
                counts.put(num, counts.get(num) + 1);
                if (counts.get(num) > floor)
                    return num;
            } else
                counts.put(num, 1);
        }
        return -1;
        // CRIO_SOLUTION_END_MODULE_L1_PROBLEMS
    }

    public static void main(String[] args) throws IOException {
        Scanner scanner = new Scanner(System.in);

        int[] numbers = new int[scanner.nextInt()];
        for (int i = 0; i < numbers.length; i++)
            numbers[i] = scanner.nextInt();
        scanner.close();

        int result = new MajorityElement().majorityElement(numbers);
        System.out.print(Integer.toString(result));
    }
}
