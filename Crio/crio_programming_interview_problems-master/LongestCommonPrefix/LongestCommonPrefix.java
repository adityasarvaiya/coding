import java.io.*;
import java.util.*;

public class LongestCommonPrefix {
    public String longestCommonPrefix(String[] strs) {
        // CRIO_SOLUTION_START_MODULE_L1_PROBLEMS
        if (strs.length < 1)
            return "";
        StringBuilder prefixStringBuilder = new StringBuilder("");

        // find min length string
        int min = Integer.MAX_VALUE;
        for (String s : strs) {
            if (s.length() < min)
                min = s.length();
        }

        for (int i = 0; i < min; i++) {
            boolean prefixCharMatch = true;
            char ch = strs[0].charAt(i);
            for (String s : strs) {
                if (ch != s.charAt(i)) {
                    prefixCharMatch = false;
                    break;
                }
            }
            if (prefixCharMatch == true)
                prefixStringBuilder.append(ch);
            else
                break;
        }

        return prefixStringBuilder.toString();
        // CRIO_SOLUTION_END_MODULE_L1_PROBLEMS
    }

    public static void main(String[] args) throws IOException {
        BufferedReader in = new BufferedReader(new InputStreamReader(System.in));
        String[] strings = in.readLine().split(" ");
        String prefixString = new LongestCommonPrefix().longestCommonPrefix(strings);
        System.out.print(prefixString);
    }
}