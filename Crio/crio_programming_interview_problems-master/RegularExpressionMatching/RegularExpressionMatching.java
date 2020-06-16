import java.io.*;
import java.util.*;

class RegularExpressionMatching {
    // complete the below function implementation
    public String isMatch(String s, String p) {
        // CRIO_SOLUTION_START_MODULE_L1_PROBLEMS
        int dp[][] = new int[s.length() + 5][p.length()+5];
        for(int i = 0 ; i < s.length() + 5 ; i++) {
            for(int j = 0 ;j < p.length() + 5 ; j++) {
                dp[i][j] = -1;
            }
        }
                int answer = rec(0 , 0 , s, p , dp);
        if(answer == 1) {
            return "true";
        }
        return "false";
        // CRIO_SOLUTION_END_MODULE_L1_PROBLEMS
    }
     // CRIO_SOLUTION_START_MODULE_L1_PROBLEMS
    public int rec(int i , int j , String s , String p , int dp[][]) {
    if(i == s.length()) {
        if(j == p.length()) {
            return 1;
        } else {
            if(j + 1 < p.length() && p.charAt(j+1) == '*') {
                return dp[i][j] = rec(i, j + 2 , s , p , dp);
            }
            if(j < p.length() && p.charAt(j) == '*') {
                return dp[i][j] = rec(i, j + 1 , s , p , dp);
            }
            return 0;
        }
    }
    if(dp[i][j] != -1) {
        return dp[i][j];
    }
    int a = 0 , b = 0 , c = 0;
    if(j + 1 < p.length() && p.charAt(j+1) == '*') {
            c = rec(i, j + 2 , s , p , dp);
    }
    if(i < s.length() && j < p.length()) {
    if(s.charAt(i) == p.charAt(j)){
        a = rec(i+1 , j+1 , s , p , dp);
    }
    else {
        if(p.charAt(j) == '.') {
            a = rec(i +1 , j + 1 , s , p , dp);
        }
        else {
            if(p.charAt(j) == '*') {
                a = rec(i , j + 1 , s , p , dp);
                if(j-1 >= 0){
                if(s.charAt(i) == p.charAt(j-1) || p.charAt(j-1) == '.') {
                b = rec(i + 1 , j , s , p , dp);
                c = rec(i + 1 , j + 1 , s , p , dp);
                }
                }
            }
        }
    }
    }
    return dp[i][j] = (a | b | c);
    }
    // CRIO_SOLUTION_END_MODULE_L1_PROBLEMS
    public static void main(String[] args) {
    	Scanner scanner = new Scanner(System.in);
    	String s = scanner.next();
    	String p = scanner.next();
    	String result = new RegularExpressionMatching().isMatch(s,p);
    	System.out.println(result);
    }
}
