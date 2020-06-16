import java.util.*;

public class FirstMissingPositive {
    public int firstMissingPositive(int[] nums) {
        // CRIO_SOLUTION_START_MODULE_L1_PROBLEMS
        HashSet<Integer> positiveIntegers = new HashSet<Integer>();
        for(int i = 0 ; i < nums.length ; ++i) {
            if(nums[i] > 0) {
                positiveIntegers.add(nums[i]);
            }
        }
        int res = 1;
        while(positiveIntegers.contains(res)) {
            res++;
        }
        return res;
        // CRIO_SOLUTION_END_MODULE_L1_PROBLEMS
    }

    public static void main(String[] args) {
        Scanner in = new Scanner(System.in);
        int n = in.nextInt();
        int[] nums = new int[n];
        for(int i = 0 ; i < n ; ++i) {
            nums[i] = in.nextInt();
        }
        int result = new FirstMissingPositive().firstMissingPositive(nums);
        System.out.println(result);
    }
}

