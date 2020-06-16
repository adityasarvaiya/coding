import java.io.*;
import java.util.*;

public class FindPeakElement {
    // Implement your solution by completing the below function
    public int findPeakElement(int[] nums) {
        // CRIO_SOLUTION_START_MODULE_L2_PROBLEMS
        int left = 0, right = nums.length - 1;
        while (left < right) {
            int mid = left + ((right - left) / 2);
            if (nums[mid] > nums[mid + 1])
                right = mid;
            else
                left = mid + 1;
        }
        return left;
        // CRIO_SOLUTION_END_MODULE_L2_PROBLEMS

        // CRIO_UNCOMMENT_START_MODULE_L2_PROBLEMS
        //return 0;
        // CRIO_UNCOMMENT_END_MODULE_L2_PROBLEMS
    }

    public static void main(String[] args) throws IOException {
        Scanner scanner = new Scanner(System.in);

        int[] nums = new int[scanner.nextInt()];
        for (int i = 0; i < nums.length; i++)
            nums[i] = scanner.nextInt();
        scanner.close();

        int peakElement = new FindPeakElement().findPeakElement(nums);
        System.out.print(peakElement);
    }
}