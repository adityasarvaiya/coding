import java.io.*;
import java.util.*;

class MedianOfTwoSortedArrays {


    public double findMedianSortedArrays(int[] nums1, int[] nums2 , int m, int n) {
        // CRIO_SOLUTION_START_MODULE_L1_PROBLEMS
        if (m > n) {
            return findMedianSortedArrays(nums2, nums1, n, m);
        }
        int low = 0, high = m, total = (m + n + 1) / 2;
        while (low <= high) {
            int partA = (low + high) / 2;
            int partB = total - partA;
            int maxLeftA = (partA == 0) ? Integer.MIN_VALUE : nums1[partA - 1];
            int maxLeftB = (partB == 0) ? Integer.MIN_VALUE : nums2[partB - 1];
            int minRightA = (partA == m) ? Integer.MAX_VALUE : nums1[partA];
            int minRightB = (partB == n) ? Integer.MAX_VALUE : nums2[partB];
            if (maxLeftA <= minRightB && maxLeftB <= minRightA) {
                if ((m + n) % 2 == 0) {
                    double ans = Math.max(maxLeftA, maxLeftB) + Math.min(minRightA, minRightB);
                    ans = ans / 2.0;
                    return ans;
                } else {
                    double ans = Math.max(maxLeftA, maxLeftB);
                    return ans;

                }
            } else {
                if (maxLeftA > minRightB) {
                    high = partA - 1;
                } else {
                    low = partA + 1;
                }
            }
        }
        return 0.0;
        // CRIO_SOLUTION_END_MODULE_L1_PROBLEMS
    }

    public static void main(String args[]) throws IOException {
        Scanner scanner = new Scanner(System.in);
        int m = scanner.nextInt();
        int nums1[] = new int[m];
        for (int i = 0 ; i < m ; i++) {
            nums1[i] = scanner.nextInt();
        }
        int n = scanner.nextInt();
        int nums2[] = new int[n];
        for (int i = 0 ; i < n ; i++) {
            nums2[i] = scanner.nextInt();
        }
        int q = scanner.nextInt();
        for (int i = 0 ; i < q ; i++) {
            int size1 = scanner.nextInt();
            int size2 = scanner.nextInt();
            double result = new MedianOfTwoSortedArrays().findMedianSortedArrays(nums1, nums2, size1, size2);
            System.out.println(result);
        }
        scanner.close();
    }
}