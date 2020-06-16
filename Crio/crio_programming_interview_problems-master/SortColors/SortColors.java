import java.io.*;
import java.util.*;

class SortColors {
    public void sortColors(int[] nums) {
        // CRIO_SOLUTION_START_MODULE_L1_PROBLEMS
        int cnt0 = 0, cnt1 = 0, cnt2 = 0;
        for (int i = 0; i < nums.length; i++) {
            if (nums[i] == 0)
                cnt0++;
            if (nums[i] == 1)
                cnt1++;
            if (nums[i] == 2)
                cnt2++;
        }
        int i = 0;
        while (cnt0 > 0) {
            nums[i] = 0;
            i++;
            cnt0--;
        }
        while (cnt1 > 0) {
            nums[i] = 1;
            i++;
            cnt1--;
        }
        while (cnt2 > 0) {
            nums[i] = 2;
            i++;
            cnt2--;
        }
        // CRIO_SOLUTION_END_MODULE_L1_PROBLEMS
    }

    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        int n = scanner.nextInt();
        int nums[] = new int[n];
        for (int i = 0; i < n; i++)
            nums[i] = scanner.nextInt();
        scanner.close();

        SortColors result = new SortColors();
        result.sortColors(nums);
        for (int i = 0; i < nums.length; i++)
            System.out.printf("%d ", nums[i]);
    }
}