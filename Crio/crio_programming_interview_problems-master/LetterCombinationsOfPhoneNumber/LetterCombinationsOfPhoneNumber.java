import java.io.*;
import java.util.*;
import java.lang.*;

public class LetterCombinationsOfPhoneNumber {
    // CRIO_SOLUTION_START_MODULE_L1_PROBLEMS
    Map<String, String> phone = new HashMap<String, String>() {
        {
            put("2", "abc");
            put("3", "def");
            put("4", "ghi");
            put("5", "jkl");
            put("6", "mno");
            put("7", "pqrs");
            put("8", "tuv");
            put("9", "wxyz");
        }
    };
    List<String> output = new ArrayList<String>();

    public void backtrack(String combination, String next_digits) {
        if (next_digits.length() == 0)
            output.add(combination);

        else {
            String digit = next_digits.substring(0, 1);
            String letters = phone.get(digit);
            for (int i = 0; i < letters.length(); i++) {
                String letter = phone.get(digit).substring(i, i + 1);
                backtrack(combination + letter, next_digits.substring(1));
            }
        }
    }
    // CRIO_SOLUTION_END_MODULE_L1_PROBLEMS

    public List<String> letterCombinationsOfPhoneNumber(String digits) {
        // CRIO_SOLUTION_START_MODULE_L1_PROBLEMS
        if (digits.contains("1"))
            return new ArrayList<String>();
        if (digits.length() != 0)
            backtrack("", digits);
        return output;
        // CRIO_SOLUTION_END_MODULE_L1_PROBLEMS

    }

    public static void main(String[] args) throws IOException {
        BufferedReader in = new BufferedReader(new InputStreamReader(System.in));
        String line = in.readLine();
        List<String> combinations = new LetterCombinationsOfPhoneNumber().letterCombinationsOfPhoneNumber(line);
        for (String cmbn : combinations)
            System.out.print(cmbn + " ");
    }
}