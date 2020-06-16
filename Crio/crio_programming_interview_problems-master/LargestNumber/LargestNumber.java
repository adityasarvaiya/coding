import java.util.*;
import java.util.Scanner;

class LargestNumber {
    public String largestNumber(int[] nums) {
        // CRIO_SOLUTION_START_MODULE_L2_PROBLEMS

        Comparator<String> byValue = new Comparator<String>() {
		@Override
		public int compare(String e1, String e2) {

            String s1 = e1 + e2;
            String s2 = e2 + e1;
            return s2.compareTo(s1);
		}
	   };

        String[] numbers = new String[nums.length];

        for (int i = 0; i < nums.length; ++i) {
            numbers[i] = new Integer(nums[i]).toString();
        }

        Arrays.sort(numbers, byValue);

        String res = "";
        for (int  i = 0; i < nums.length; ++i){
            //System.out.println(nums[i]);
            res = res + numbers[i];
        }

        if ((res.charAt(0) == '0') && (res.length() > 1)) {
            int i = 0;
            while ((res.charAt(i) == '0') && (i + 1  < res.length())) {
                ++i;
            }

            return res.substring(i, res.length());
        }

        return res;
        // CRIO_SOLUTION_END_MODULE_L2_PROBLEMS

        // CRIO_STUB_START_MODULE_L2_PROBLEMS

        // return "";

        // CRIO_STUB_END_MODULE_L2_PROBLEMS
    }

    public static void main(String args[]) {

        Scanner scanner = new Scanner(System.in);

        int n = scanner.nextInt();

        int nums[] = new int[n];

        for(int i = 0 ; i < n ;i++) {
            nums[i] = scanner.nextInt();
        }

        String result = new LargestNumber().largestNumber(nums);

        System.out.println(result);
    }

}
