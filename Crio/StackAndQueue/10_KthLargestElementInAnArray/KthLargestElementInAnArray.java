import java.io.*;
import java.util.*;

class KthLargestElementInAnArray {
    // CRIO_SOLUTION_START_MODULE_L1_PROBLEMS
    public static int partition(int[] arr, int start, int end) {
        // Pick last element as pivot
        // Move all the elements greater than pivot towards left
        // And all the elements less than pivot towards right
        int pivot = arr[end], pivotloc = start;
        for (int i = start; i <= end; i++) {
            if (arr[i] > pivot) {
                int temp = arr[i];
                arr[i] = arr[pivotloc];
                arr[pivotloc] = temp;
                pivotloc++;
            }
        }

        int temp = arr[end];
        arr[end] = arr[pivotloc];
        arr[pivotloc] = temp;
        return pivotloc;
    }

    public static int kthLargest(int[] arr, int start, int end, int k) {
        // Partition the array taking last element as pivot
        // Check on which side the kth element lies and search there
        int part = partition(arr, start, end);
        if (part == k) {
            return arr[part];
        } else if (part < k) {
            return kthLargest(arr, part + 1, end, k);
        } else {
            return kthLargest(arr, start, part - 1, k);
        }
    }
    // CRIO_SOLUTION_END_MODULE_L1_PROBLEMS

    // Implement your solution by completing the below function
    public int findKthLargest(int[] nums, int k) {
        // CRIO_SOLUTION_START_MODULE_L1_PROBLEMS
        // Randomize the array so that the worst case complexity is not O(n^2)
        Random rand = new Random();
        for (int i = 1; i < nums.length; ++i) {
            int indexToSwap = rand.nextInt(nums.length);
            int temp = nums[i];
            nums[i] = nums[indexToSwap];
            nums[indexToSwap] = temp;
        }

        // Use Quick Select algorithm to find the kth Largest element
        return kthLargest(nums, 0, nums.length - 1, k - 1);
        // CRIO_SOLUTION_END_MODULE_L1_PROBLEMS
    }

    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        int n = scanner.nextInt();
        int nums[] = new int[n];
        for (int i = 0; i < n; ++i)
            nums[i] = scanner.nextInt();

        int k = scanner.nextInt();
        scanner.close();

        int result = new KthLargestElementInAnArray().findKthLargest(nums, k);
        System.out.println(result);
    }
}
