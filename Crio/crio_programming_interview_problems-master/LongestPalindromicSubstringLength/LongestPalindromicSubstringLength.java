import java.util.*;
public class LongestPalindromicSubstringLength  
{ 
    static int longestPalindromicSubstringLength(String str) { 
// CRIO_SOLUTION_START_MODULE_L1_PROBLEMS
        int n = str.length();
        boolean table[][] = new boolean[n][n]; 
        int maxLength = 1; 
        for (int i = 0; i < n; ++i) 
            table[i][i] = true; 
        int start = 0; 
        for (int i = 0; i < n - 1; ++i) { 
            if (str.charAt(i) == str.charAt(i + 1)) { 
                table[i][i + 1] = true; 
                start = i; 
                maxLength = 2; 
            } 
        } 
        for (int k = 3; k <= n; ++k) { 
            for (int i = 0; i < n - k + 1; ++i)  
            {  
                int j = i + k - 1; 
                if (table[i + 1][j - 1] && str.charAt(i) == str.charAt(j)) { 
                    table[i][j] = true; 
                    if (k > maxLength) { 
                        start = i; 
                        maxLength = k; 
                    } 
                } 
            } 
        } 
        return maxLength;
// CRIO_SOLUTION_END_MODULE_L1_PROBLEMS
    } 
    public static void main(String[] args) { 
        Scanner sc = new Scanner(System.in);
        int t= sc.nextInt();
        for(int tests=0;tests<t;tests++)
        {
            int n= sc.nextInt();
            String s= sc.next();
            System.out.println(longestPalindromicSubstringLength(s));
        }
    } 
}
