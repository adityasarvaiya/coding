import java.io.*;
import java.util.*;

class ShortestUnsortedContinuousSubarray {
    
    // Complete the function implementation below
    public int findUnsortedSubarrayLength(int[] nums) {
        if (nums.length == 0 || nums.length == 1) {
            return 0;
        }

        int length = nums.length;

        int start_of_unsorted = 0;
        int i = 0;

        // find the start of unsorted array
        while (i < length - 1) {
            if (nums[i] <= nums[i + 1]) {
                i++;
            } else {
                start_of_unsorted = i + 1;
                break;
            }
        }

        int j = length - 1;
        int end_of_unsorted = 0;

        while (j > 0) {
            if (nums[j] >= nums[j - 1]) {
                j--;
            } else {
                end_of_unsorted = j - 1;
                break;
            }
        }


        // find the max and min in the unsorted array
        int min = Math.min(nums[start_of_unsorted], nums[end_of_unsorted]);
        int max = Math.max(nums[start_of_unsorted], nums[end_of_unsorted]);

        for (int start = start_of_unsorted; start <= end_of_unsorted; start++) {
            min = nums[start] < min ? nums[start] : min;
            max = nums[start] > max ? nums[start] : max;
        }


        // find all the elements before the start of unsorted array that are smaller
        // than min
        int beginning_index_of_unsorted = start_of_unsorted;
        i = beginning_index_of_unsorted;
        while (i >= 0) {
            if (nums[i] > min) {
                beginning_index_of_unsorted = i;
            }
            i -= 1;
        }


        // find all the elements before the end of unsorted array that are smaller than
        // max
        int end_index_of_unsorted = end_of_unsorted;
        j = end_index_of_unsorted;
        while (j < length) {
            if (nums[j] < max) {
                end_index_of_unsorted = j;
            }
            j += 1;
        }


        int sum = end_index_of_unsorted - beginning_index_of_unsorted;

        if (sum > 0) {
            return sum + 1;
        } else {
            return sum;
        }
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