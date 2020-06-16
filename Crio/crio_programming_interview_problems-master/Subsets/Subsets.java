import java.io.*;
import java.util.*;

class Subsets {
  // TODO: CRIO_TASK_MODULE_L2_PROBLEMS
  // complete the below function implementation
  public List<List<Integer>> subsets(int[] nums) {
    // CRIO_SOLUTION_START_MODULE_L2_PROBLEMS
    List<List<Integer>> allSubsets = new ArrayList<List<Integer>>();
    for(int i = 0 ; i < 1 << nums.length ; ++i) {
      ArrayList<Integer> subset = new ArrayList<Integer>();

      for(int j = 0 ; j < nums.length ; ++j) {
        if(((i >> j)&1) == 1) {
          subset.add(nums[j]);
        }
      }

      allSubsets.add(subset);
    }
    return allSubsets;
    // CRIO_SOLUTION_END_MODULE_L2_PROBLEMS

    // CRIO_UNCOMMENT_START_MODULE_L2_PROBLEMS
    // return null;
    // CRIO_UNCOMMENT_END_MODULE_L2_PROBLEMS
  }
  public static void main(String[] args) {
    Scanner scanner = new Scanner(System.in);

    int n = scanner.nextInt();
    int[] nums = new int[n];

    for(int i = 0 ; i < n ; ++i) {
      nums[i] = scanner.nextInt();
    }
    scanner.close();

    List<List<Integer>> result = new Subsets().subsets(nums);
    System.out.println(result.size());
    for(int i = 0 ; i < result.size() ; ++i) {
      if(result.get(i).size() == 0) {
        System.out.println("null");
        continue;
      }
      for(int j = 0 ; j < result.get(i).size() ; ++j) {
        System.out.printf("%d " , result.get(i).get(j));
      }
      System.out.println();
    }
  }
}
