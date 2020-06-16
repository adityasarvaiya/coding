import java.io.*;
import java.util.*;

public class ValidParenthesis {
    public boolean isValid(String s) {
        // CRIO_SOLUTION_START_MODULE_L1_PROBLEMS
        Stack<Character> stack = new Stack<Character>();
        int len = s.length();
        for (int i = 0; i < len; i++) {
            if (s.charAt(i) == '(' || s.charAt(i) == '{' || s.charAt(i) == '[')
                stack.push(s.charAt(i));
            else if (!stack.empty()) {
                if ((s.charAt(i) == ')' && stack.peek() == '(') || (s.charAt(i) == '}' && stack.peek() == '{')
                        || (s.charAt(i) == ']' && stack.peek() == '[')) {
                    stack.pop();
                } else {
                    return false;
                }
            } else {
                return false;
            }
        }
        if (!stack.empty())
            return false;

        return true;
        // CRIO_SOLUTION_END_MODULE_L1_PROBLEMS
    }

    public static void main(String[] args) throws IOException {
        BufferedReader in = new BufferedReader(new InputStreamReader(System.in));
        String parenthesis = in.readLine();

        boolean result = new ValidParenthesis().isValid(parenthesis);
        System.out.print(String.valueOf(result));
    }
}
