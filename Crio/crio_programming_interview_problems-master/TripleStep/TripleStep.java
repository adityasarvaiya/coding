import java.util.*;

class TripleStep {
// CRIO_SOLUTION_START_MODULE_L1_PROBLEMS
    int ways[];
    int mod = 1000000007;
    int countWays(int n) {

        if(ways[n] != -1) {
            return ways[n];
        }
        int ans = countWays(n-1)%mod;
        ans += countWays(n-2)%mod;
        ans %= mod;
        ans += countWays(n-3)%mod;
        ans %= mod;
        return ways[n] = ans%mod;
    }
// CRIO_SOLUTION_END_MODULE_L1_PROBLEMS
    int numberOfWays(int n) {
// CRIO_SOLUTION_START_MODULE_L1_PROBLEMS
        ways = new int[n+4];
        for(int i = 0; i <= n ; i++) {
            ways[i] = -1;
        }
        ways[0] = 1;
        ways[1] = 1;
        ways[2] = 2;
        return countWays(n)%mod;
// CRIO_SOLUTION_END_MODULE_L1_PROBLEMS
    }
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        int n = scanner.nextInt();
        TripleStep tripleStep = new TripleStep();
        int result = tripleStep.numberOfWays(n);
        System.out.println(result);
        scanner.close();
    }
}
