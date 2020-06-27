import java.util.*;

class LongestSubstringWithoutRepeatingCharacter {
    public int lengthOfLongestSubstring(String s) {
        // CRIO_SOLUTION_START_MODULE_L1_PROBLEMS
        int longestSubstring = 0;
        int n = s.length();

        for(int i = 0 ; i < n ; ++i){
            HashSet<Character> marked = new HashSet<Character>();
            int right = i;
            while(right < n && !marked.contains(s.charAt(right))) {
                marked.add(s.charAt(right));
                right++;
            }
            longestSubstring = Math.max(longestSubstring , right - i);
        }
        return longestSubstring;
        // CRIO_SOLUTION_END_MODULE_L1_PROBLEMS
    }
    public static void main(String[] args) {
        Scanner in = new Scanner(System.in);
        String s = in.nextLine();
        int result = new LongestSubstringWithoutRepeatingCharacter().lengthOfLongestSubstring(s);
        System.out.println(result);
    }
}
