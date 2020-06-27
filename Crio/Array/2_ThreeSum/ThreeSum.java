import java.util.Scanner;
import java.util.*;

class ThreeSum {

    // CRIO_SOLUTION_START_MODULE_L1_PROBLEMS
    public List<List<Integer>> twoSum(Integer[] nums, Integer start, Integer end, Integer sum) {

        List<List<Integer>> res = new ArrayList<>();
        Integer p1 = start;
        Integer p2 = end;

        while (p1 < p2) {
            Integer total = nums[p1] + nums[p2];

            if (total > sum) {
                --p2;
            } else if (total < sum ) {
                ++p1;
            } else {
                List<Integer> onePair = new ArrayList<>();
                int n1 = nums[p1];
                int n2 = nums[p2];
                onePair.add(nums[p1]);
                onePair.add(nums[p2]);

                while (n1 == nums[p1] && p1 < p2) {
                    ++p1;
                }
                --p2;
                res.add(onePair);
            }
        }

        return res;
    }
    // CRIO_SOLUTION_END_MODULE_L1_PROBLEMS

    public List<List<Integer>> threeSum(Integer[] nums) {
        List<List<Integer>> result = new ArrayList<>();
        // CRIO_SOLUTION_START_MODULE_L1_PROBLEMS

        Arrays.sort(nums);

        for (Integer p1 = 0; p1 + 2 < nums.length; ) {
            List<List<Integer>> twoSumPairs = twoSum(nums, p1 + 1, nums.length - 1, 0 - nums[p1]);

            if (twoSumPairs.size() == 0)
                ++p1;
            else {
                for (int i = 0; i < twoSumPairs.size(); ++i) {
                    List<Integer> pair = twoSumPairs.get(i);
                    pair.add(nums[p1]);
                    result.add(pair);
                    Integer firstNumber = nums[p1];
                }

                Integer firstNumber = nums[p1];
                while ((firstNumber == nums[p1]) && (p1 + 2 < nums.length)) {
                    ++p1;
                }
            }
        }

        // CRIO_SOLUTION_END_MODULE_L1_PROBLEMS

        return result;
    }


    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);

        Integer n = scanner.nextInt();

        Integer nums[] = new Integer[n];

        for(Integer i = 0 ; i < n ;i++) {
            nums[i] = scanner.nextInt();
        }

        List<List<Integer>> result = new ThreeSum().threeSum(nums);

        for (Integer i = 0; i < result.size(); ++i) {
            System.out.printf("%d %d %d\n", result.get(i).get(0), result.get(i).get(1), result.get(i).get(2));
        }
    }
};
