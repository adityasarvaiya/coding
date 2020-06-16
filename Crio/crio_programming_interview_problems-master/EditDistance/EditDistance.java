import java.util.*;
public class EditDistance {
    static int editDistance(String s1, String s2){
        // CRIO_SOLUTION_START_MODULE_L1_PROBLEMS
        int m = s1.length();
        int n = s2.length();
        int dp[][] = new int[m+1][n+1];
        for (int i = 0; i <= m; i++) {
            for (int j = 0; j <= n; j++) {
                if(i==0) dp[0][j] = j;
                else if(j==0) dp[i][0] = i;
                else if(s1.charAt(i-1)==s2.charAt(j-1)){
                    dp[i][j] = dp[i-1][j-1];
                }
                else{
                    dp[i][j] = 1+ Math.min(dp[i-1][j-1],Math.min(dp[i-1][j],dp[i][j-1]));
                }
            }
        }
        return dp[m][n];
        // CRIO_SOLUTION_END_MODULE_L1_PROBLEMS
    }
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        String s1 = sc.next(); 
        String s2 = sc.next(); 
        int ans = editDistance(s1, s2);
        System.out.print(ans);
        sc.close();
    }
}
