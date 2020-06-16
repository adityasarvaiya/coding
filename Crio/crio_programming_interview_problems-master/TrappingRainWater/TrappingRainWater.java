import java.io.*;
import java.util.*;
class TrappingRainWater {
    // TODO: CRIO_TASK_MODULE_L3_PROBLEMS
    // complete the below function implementation
    public int trap(int[] height) {
        // CRIO_SOLUTION_START_MODULE_L3_PROBLEMS
        int n = height.length;
        if(n == 0)
            return 0;
        int left[] = new int[n];
        int right[] = new int[n];
        right[n-1] = height[n-1];
        left[0] = height[0];
        for(int i = 1 ; i < n ; i++) {
            left[i] = (left[i-1]  < height[i] ? height[i] : left[i-1]);
        }
        for(int i = n-2; i >=0 ; i--) {
            right[i] = (right[i+1] < height[i] ? height[i] : right[i+1]);
        }
        int ans= 0;
        for(int i = 1 ; i < n-1 ; i++) {
            int temp = (left[i-1] < right[i+1] ? left[i-1] : right[i+1]);
            ans = ans + (temp - height[i] < 0 ? 0 : temp - height[i]);
        }
        return ans;
        // CRIO_SOLUTION_END_MODULE_L3_PROBLEMS
        // CRIO_UNCOMMENT_START_MODULE_L3_PROBLEMS
        // return 0;
        // CRIO_UNCOMMENT_END_MODULE_L3_PROBLEMS
    }
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        int n = scanner.nextInt();
        int height[] = new int[n];
        for(int i = 0 ; i < n ; i++) {
            height[i] = scanner.nextInt();
        }
        scanner.close();
        int result = new TrappingRainWater().trap(height);
        System.out.println(result);  
    }
}