import java.util.Scanner;

class JumpGame {
    
    public String canJump(int[] nums) {

        // CRIO_SOLUTION_START_MODULE_L1_PROBLEMS

        int n = nums.length;
        int mini = n-1;
        for(int i = n-2 ; i >= 0 ; i--) {
            if(nums[i] + i >= mini) {
                mini = i;
            }
        }

        if(mini == 0) {
            return "true";
        }
        return "false";

        // CRIO_SOLUTION_END_MODULE_L1_PROBLEMS

    }

    public static void main(String args[]) {
        
        Scanner scanner = new Scanner(System.in);

        int n = scanner.nextInt();

        int nums[] = new int[n];

        for(int i = 0 ; i < n ;i++) {
            nums[i] = scanner.nextInt();
        }

        String result = new JumpGame().canJump(nums);

        System.out.println(result);


    }
}
