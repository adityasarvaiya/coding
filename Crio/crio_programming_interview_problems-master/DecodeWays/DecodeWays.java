import java.io.*;
import java.util.*;
class DecodeWays {
    public int numDecodings(String s) { 
        // CRIO_SOLUTION_START_MODULE_L1_PROBLEMS
        int n = s.length();        
        int ways[] = new int[n];
        for(int i =0 ; i < n ; i++)
            ways[i] = -1;
        int answer  = findWays(0, n , ways , s);
        return answer; 
        // CRIO_SOLUTION_END_MODULE_L1_PROBLEMS
    }
    // CRIO_SOLUTION_START_MODULE_L1_PROBLEMS
    public int findWays(int index , int n ,  int ways[] , String s) {
        int mod = 1000000007;
        if(index <= n-1 && s.charAt(index) == '0') {
            return 0;
        }      
        if(index >= n-1) {
            return 1;
        }
        if(ways[index] != -1)
            return ways[index];
        int ans = findWays(index + 1 , n , ways , s)%mod;
        int firstDigit = s.charAt(index) - '0';
        int secondDigit = s.charAt(index + 1) - '0';
        if(10*firstDigit + secondDigit <= 26)
            ans = (ans%mod + findWays(index + 2 , n , ways , s)%mod)%mod;
        ways[index] = ans%mod;
        return ways[index];
    }
    // CRIO_SOLUTION_END_MODULE_L1_PROBLEMS
    public static void main(String args[]) {
        Scanner scanner = new Scanner(System.in);
        String s = scanner.nextLine();
        scanner.close();
        int result = new DecodeWays().numDecodings(s);
        System.out.println(result);
     }
}
