import java.io.*;
import java.util.*;
class UniquePaths {
    public int uniquePaths(int m, int n) {
        // CRIO_SOLUTION_START_MODULE_L1_PROBLEMS
        int numberOfWays[][] = new int[m][n];
        int mod = 1000000007;
        for(int i = 0 ; i  < m  ; i++) {
            numberOfWays[i][0] = 1;
        }
        for(int i = 0 ; i < n ; i++) {
            numberOfWays[0][i] = 1;
        }
        for(int i = 1 ; i < m ; i++) {
            for(int j = 1 ; j < n ; j++) {
                numberOfWays[i][j] = (numberOfWays[i-1][j]%mod + numberOfWays[i][j-1]%mod)%mod;
            }
        }
        return (numberOfWays[m-1][n-1]%mod);
        // CRIO_SOLUTION_END_MODULE_L1_PROBLEMS
    }
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        int n = scanner.nextInt();
        int m = scanner.nextInt();
        scanner.close();
        int result = new UniquePaths().uniquePaths(m , n);
        System.out.println(result);
    }
}