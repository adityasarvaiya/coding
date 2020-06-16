import java.util.Scanner;

class LongestPalindromicSubstring {
    public static String longestPalindromicSubstring(String s) {        
        // CRIO_SOLUTION_START_MODULE_L1_PROBLEMS

        int n = s.length();
        if(n <= 1) {
            return s;
        }
        int[][] isPalindrome = new int[n][n];
        for(int i = 0 ; i < n ; ++i) {
            for(int j = 0 ; j < n ; ++j) {
                if(i >= j) {
                    isPalindrome[i][j] = 1;
                } else {
                    isPalindrome[i][j] = 0;
                }
            }
        }
        int maxLength = 0;
        int maxLengthPos = 0;
        
        
        for(int j = 1 ; j < n ; ++j) {
            for(int i = 0 ; i+j < n ; ++i) {
                isPalindrome[i][i+j] = 0;
                if(s.charAt(i) == s.charAt(i+j)) {
                    isPalindrome[i][i+j] =  isPalindrome[i+1][i+j-1];
                }
                if(isPalindrome[i][i+j] == 1) {
                    maxLength = j;
                    maxLengthPos = i;
                }
            }
        }
        String maxString = "";
        for(int i = maxLengthPos ; i <= maxLengthPos + maxLength ; ++i) {
            maxString += s.charAt(i);
        }
        return maxString;
        // CRIO_SOLUTION_END_MODULE_L1_PROBLEMS
    }

    public static void main(String[] args) {
        Scanner in = new Scanner(System.in);
        String s = in.nextLine();
        String result = new LongestPalindromicSubstring().longestPalindromicSubstring(s);
        System.out.println(result);
    }
}