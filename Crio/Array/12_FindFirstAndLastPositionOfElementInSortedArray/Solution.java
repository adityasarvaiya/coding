import java.util.*;

public class Solution {
    public int[] findFirstAndLastPositionOfElementInSortedArray(int[] nums, int target) {
        // CRIO_SOLUTION_START_MODULE_L1_PROBLEMS
        int n = nums.length;
        int low = 0 , high = n - 1;
        while(high - low > 10) {
            int mid = (low + high)/2;
            if(nums[mid] == target) {
                high = mid;
            }
            else {
                if(nums[mid] > target) {
                    high = mid -1;
                }
                else {
                    low = mid + 1;
                }
            }
        }
        int first = -1 , last = -1;
        for(int i = low ; i <= high ; i++) {
            if(nums[i] == target) {
                first = i;
                break;
            }
        }
        low = 0 ;
        high = n-1;
        int answer[] = new int[2];
        while(high - low > 10) {
            int mid = (low + high)/2;
            if(nums[mid] == target) {
                low = mid;
            }
            else {
                if(nums[mid] < target) {
                    low = mid  + 1;
                }
                else {
                    high = mid - 1;
                }
            }
        }
        for(int i = high ; i >= low ; i--) {
            if(nums[i] == target) {
                last = i;
                break;
            }
        }
        answer[0] = first;
        answer[1] = last;
        return answer;
        // CRIO_SOLUTION_END_MODULE_L1_PROBLEMS
    }
}
