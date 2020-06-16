import java.io.*;
import java.util.*;

class WordBreak {
    public boolean wordBreak(String s, List<String> wordDict) {
        // CRIO_SOLUTION_START_MODULE_L2_PROBLEMS
        int n = s.length();
        boolean[] dp = new boolean[n+1];
        dp[n] = true;
        HashSet<String> hashWordDict = new HashSet<String>();
        
        for(int i = 0 ; i < wordDict.size() ; ++i) {
            hashWordDict.add(wordDict.get(i));
        }
        
        for(int i = n-1 ; i >= 0 ; --i) {
            dp[i] = false;
            for(int j = i ; j < n ; ++j) {
                String subString = "";
                for(int k = i ; k <= j ; ++k) {
                    subString += s.charAt(k);
                }
                if(hashWordDict.contains(subString)) {
                    dp[i] = dp[i] || dp[j+1];
                }
            }
        }
        return dp[0];
        // CRIO_SOLUTION_END_MODULE_L2_PROBLEMS

        // CRIO_UNCOMMENT_START_MODULE_L2_PROBLEMS
        // return true;
        // CRIO_UNCOMMENT_END_MODULE_L2_PROBLEMS
    }

    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        String s = scanner.nextLine();
        
        int n = scanner.nextInt();
        List<String> wordDict = new ArrayList<String>();
        for(int i = 0 ; i < n ; ++i) {
            String word = scanner.next(); 
            wordDict.add(word);
        }
        scanner.close();

        boolean result = new WordBreak().wordBreak(s , wordDict);
        System.out.println(result);
    }
}
