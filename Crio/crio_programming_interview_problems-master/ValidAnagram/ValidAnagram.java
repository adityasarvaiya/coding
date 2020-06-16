import java.io.*;
import java.util.*;

public class ValidAnagram {
    // Implement your solution by completing the below function
    public boolean isAnagram(String s, String t) {
        // CRIO_SOLUTION_START_MODULE_L1_PROBLEMS
        if (s.length() != t.length())
            return false;

        HashMap<Character, Integer> s_counts = new HashMap<Character, Integer>();
        for (int i = 0; i < s.length(); ++i) {
            if (s_counts.containsKey(s.charAt(i)))
                s_counts.put(s.charAt(i), s_counts.get(s.charAt(i)) + 1);
            else
                s_counts.put(s.charAt(i), 1);
        }

        HashMap<Character, Integer> t_counts = new HashMap<Character, Integer>();
        for (int i = 0; i < t.length(); ++i) {
            if (t_counts.containsKey(t.charAt(i)))
                t_counts.put(t.charAt(i), t_counts.get(t.charAt(i)) + 1);
            else
                t_counts.put(t.charAt(i), 1);
        }

        return s_counts.equals(t_counts);
        // CRIO_SOLUTION_END_MODULE_L1_PROBLEMS

        // CRIO_UNCOMMENT_START_MODULE_L1_PROBLEMS
        //return false;
        // CRIO_UNCOMMENT_END_MODULE_L1_PROBLEMS
    }

    public static void main(String[] args) throws IOException {
        BufferedReader in = new BufferedReader(new InputStreamReader(System.in));
        String s = in.readLine();
        String t = in.readLine();

        boolean result = new ValidAnagram().isAnagram(s, t);
        System.out.print(String.valueOf(result));
    }
}