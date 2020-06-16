import java.io.*;
import java.util.*;

class MinimumWindowSubstring {
    // CRIO_SOLUTION_START_MODULE_L3_PROBLEMS
    public static boolean isValid(HashMap<Character,Integer> a,HashMap<Character,Integer> b) {
        for (Map.Entry<Character, Integer> entry : b.entrySet()) {
            if(!a.containsKey(entry.getKey())) {
                return false;
            }
            if(a.get(entry.getKey()) < entry.getValue()) {
                return false;
            }
        }
        return true;
    }
    // CRIO_SOLUTION_END_MODULE_L3_PROBLEMS

    public String minWindow(String s, String t) {
        // CRIO_SOLUTION_START_MODULE_L3_PROBLEMS
        HashMap<Character,Integer> countT = new HashMap<Character,Integer>();
        HashMap<Character,Integer> countS = new HashMap<Character,Integer>();
        
        
        for(int i = 0 ; i < t.length() ; ++i) {
            if(!countT.containsKey(t.charAt(i))) {
                countT.put(t.charAt(i) , 0);
            }
            countT.put(t.charAt(i) , countT.get(t.charAt(i)) + 1);   
        }
        
        int start = 0 , end = 0;
        int bestS = -1 , bestE = s.length();
        while(end < s.length()) {
            while(end < s.length() && !isValid(countS , countT)) {
                if(!countS.containsKey(s.charAt(end))) {
                    countS.put(s.charAt(end) , 0);
                }
                countS.put(s.charAt(end) , countS.get(s.charAt(end)) + 1);
                end++;
            }
            while(start < end && isValid(countS , countT)) {
                if((bestE - bestS) >= (end - start)) {
                    bestS = start;
                    bestE = end;
                }
                if(!countS.containsKey(s.charAt(start))) {
                    countS.put(s.charAt(start) , 0);
                }
                countS.put(s.charAt(start) , countS.get(s.charAt(start)) - 1);
                start++;
            }
        }
        String res = "";
        if(bestS != -1) {
            for(int i = bestS ; i < bestE; ++i) {
                res += s.charAt(i);
            }
        }
        return res;
        // CRIO_SOLUTION_END_MODULE_L3_PROBLEMS

        // CRIO_UNCOMMENT_START_MODULE_L3_PROBLEMS
        // return "";
        // CRIO_UNCOMMENT_END_MODULE_L3_PROBLEMS
    }

    public static void main(String[] args) {
        Scanner in = new Scanner(System.in);
        String s = in.next();
        String t = in.next();
        in.close();
        String result = new MinimumWindowSubstring().minWindow(s , t);
        System.out.println(result);
    }
}
