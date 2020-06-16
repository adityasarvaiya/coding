import java.io.*;
import java.util.*;

class LargestRectangleInHistogram {
    
    public int largestRectangleArea(int[] heights) {
        // CRIO_SOLUTION_START_MODULE_L3_PROBLEMS
        int n = heights.length;
        if(n == 0) {
            return 0;
        }
        int[] nextSmaller = new int[n];
        Stack<Integer> S = new Stack<Integer>();
        Stack<Integer> position = new Stack<Integer>();
        for(int i = 0 ; i < n ; ++i) {
            if(S.empty()) {
                S.push(heights[i]);
                position.push(i);
                continue;
            }
            
            while(!S.empty() && S.peek() > heights[i]) {
                int cur = position.pop();
                S.pop();
                nextSmaller[cur] = i;
            }
            
            S.push(heights[i]);
            position.push(i);
        }
        
        while(!S.empty()) {
            int cur = position.pop();
            S.pop();
            nextSmaller[cur] = n;
        }
        
        int[] prevSmaller = new int[n];
        S = new Stack<Integer>();
        position = new Stack<Integer>();
        for(int i = n-1 ; i >= 0 ; --i) {
            if(S.empty()) {
                S.push(heights[i]);
                position.push(i);
                continue;
            }

            while(!S.empty() && S.peek() > heights[i]) {
                int cur = position.pop();
                S.pop();
                prevSmaller[cur] = i;
            }

            S.push(heights[i]);
            position.push(i);
        }

        while(!S.empty()) {
            int cur = position.pop();
            S.pop();
            prevSmaller[cur] = -1;
        }
        
        int maxArea = 0;
        for(int i = 0 ; i < n ; ++i) {
            int curArea = (int)(heights[i]) * (int)(nextSmaller[i] - prevSmaller[i] - 1);
            if(curArea > maxArea) {
                maxArea = curArea;
            }
        }
        return maxArea;
        // CRIO_SOLUTION_END_MODULE_L3_PROBLEMS

        // CRIO_UNCOMMENT_START_MODULE_L3_PROBLEMS
        // return 0;
        // CRIO_UNCOMMENT_END_MODULE_L3_PROBLEMS
    }

    public static void main(String[] args) {
        Scanner in = new Scanner(System.in);
        int n = in.nextInt();
        int[] heights = new int[n];

        for(int i = 0 ; i < n ; ++i) {
            heights[i] = in.nextInt();
        }
        in.close();
        
        int result = new LargestRectangleInHistogram().largestRectangleArea(heights);
        System.out.println(result);
    }
}