import java.io.*;
import java.util.*;

public class ValidPalindrome {
    // Implement your solution by completing the below function
    public String isPalindrome(String s) {
        // CRIO_SOLUTION_START_MODULE_L1_PROBLEMS
        if (s.length() == 0)
            return "true";
        s = s.replaceAll("[^a-zA-Z0-9]", "");
        s = s.toLowerCase();
        for (int i = 0, j = s.length() - 1; i <= j; ++i, j--) {
            if (Character.isAlphabetic(s.charAt(i)) || Character.isDigit(s.charAt(i)))
                if (s.charAt(i) != s.charAt(j))
                    return "false";
        }
        return "true";
        // CRIO_SOLUTION_END_MODULE_L1_PROBLEMS
    }

    public static void main(String[] args) throws IOException {
        BufferedReader in = new BufferedReader(new InputStreamReader(System.in));
        String line = in.readLine();

        String result = new ValidPalindrome().isPalindrome(line);
        System.out.print(result);
    }
}