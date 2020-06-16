import java.util.Scanner;
import java.util.*;

class GenerateParentheses {
    // CRIO_SOLUTION_START_MODULE_L2_PROBLEMS

    void paren(String str, int left, int right, List<String> result) {

        if (left > right)
            return;

        if ((left == 0) && (right == 0)) {
            //System.out.println(str);
            result.add(str);
            return;
        }

        if (left != 0) {
            paren(str + "(", left-1, right, result);
        }
        if (right != 0) {
            paren(str + ")", left, right-1, result);
        }
    }
    // CRIO_SOLUTION_END_MODULE_L2_PROBLEMS

    public List<String> generateParenthesis(int n) {
        List<String> result = new ArrayList<>();

        // CRIO_SOLUTION_START_MODULE_L2_PROBLEMS
        paren("", n, n, result);
        // CRIO_SOLUTION_END_MODULE_L2_PROBLEMS

        return result;
    }

    public static void main(String args[]) {

        Scanner scanner = new Scanner(System.in);

        int n = scanner.nextInt();
        List<String> result = new GenerateParentheses().generateParenthesis(n);

        for (int i = 0; i < result.size(); ++i)
            System.out.println(result.get(i));
    }
}
