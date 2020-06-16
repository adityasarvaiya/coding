import java.io.*;
import java.util.*;

class ShortestUnsortedContinuousSubarray {
    
    // Complete the function implementation below
public int findUnsortedSubarrayLength(int[] nums) {
    int i = 0;
    int j = nums.length -1;
    int min = 99999999;
    int max = -99999999;
    if (j == 0 ) {
        return 0;
    }

    while (i < nums.length -1 && nums[i] <= nums[i+1] ) {
        i++;
    }

    while (j > 0 && nums[j-1] <= nums[j]) {
        j--;
    }

    if(j==0 && i==nums.length -1) {
        return 0;
    }

    for (int st = i; st < j+1; st++) { 
        min = java.lang.Math.min(min, nums[st]);
        max = java.lang.Math.max(max, nums[st]);
    }

    // System.out.println(i);
    // System.out.println(j);
    // System.out.println(min);
    // System.out.println(max);

    int start = i-1;
    int end = j+1;

    while (start >= 0) {
        if (nums[start] > min) {
            i--;
            start--;
        }
        else {
            break;
        }
    }

    while (end < nums.length) {
        if (nums[end] < max) {
            j++;
            end++;
        }
        else {
            break;
        }
    }

    // System.out.println(i);
    // System.out.println(j);

    return j-i+1;
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