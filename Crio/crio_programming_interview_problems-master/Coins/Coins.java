import java.util.*;

public class Coins {
    //CRIO_SOLUTION_START_MODULE_L1_PROBLEMS
    int ways[][],coins[];
    int countWaysUtil(int idx , int n) {
        int mod = 1000000007;
        if(n < 0) {
            return 0;
        }
        if(idx == 4) {
            if(n == 0) {
                return 1;
            }
            return 0;
        }
        if(ways[idx][n] != -1) {
            return ways[idx][n];
        }
        int ans = (countWaysUtil(idx, n-coins[idx])%mod + countWaysUtil(idx+1, n)%mod)%mod;
        return ways[idx][n] = ans;
    }
    //CRIO_SOLUTION_END_MODULE_L1_PROBLEMS
    int countWays(int n) {
        //CRIO_SOLUTION_START_MODULE_L1_PROBLEMS
        ways = new int[5][n+1];
        coins = new int[5];
        coins[0] = 1;
        coins[1] = 5;
        coins[2] = 10;
        coins[3] = 25; 
        for(int i = 0 ; i < 5 ; i++) {
            for(int j = 0 ; j <= n ; j++) {
                ways[i][j] = -1;
            }
        }
        return countWaysUtil(0, n);
        //CRIO_SOLUTION_END_MODULE_L1_PROBLEMS
    }
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        Coins result = new Coins();
        int n = scanner.nextInt();
        int answer = result.countWays(n);
        System.out.println(answer);
        scanner.close();
    }
}