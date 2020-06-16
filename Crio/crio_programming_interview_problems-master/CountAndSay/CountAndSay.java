import java.io.*;
import java.util.*;
// CRIO_SOLUTION_START_MODULE_L1_PROBLEMS
import javafx.util.Pair;
// CRIO_SOLUTION_END_MODULE_L1_PROBLEMS

public class CountAndSay {
    // CRIO_SOLUTION_START_MODULE_L1_PROBLEMS
    private Pair<Integer, Integer> findNumberOfConsecutiveNumbers(String s, int i) {
        char strToFind = s.charAt(i);
        int numOccurence = 0;
        while (i < s.length() && s.charAt(i) == strToFind) {
            numOccurence += 1;
            i += 1;
        }
        return new Pair<Integer, Integer>(numOccurence, i);
    }
    // CRIO_SOLUTION_END_MODULE_L1_PROBLEMS

    // Implement your solution by completing the below function
    public String countAndSay(int n) {
        // CRIO_SOLUTION_START_MODULE_L1_PROBLEMS
        String string = "1";
        if (n == 1)
            return "1";

        for (int i = 2; i <= n; ++i) {
            int index = 0;
            String resultString = "";
            while (index < string.length()) {
                Pair<Integer, Integer> pair = findNumberOfConsecutiveNumbers(string, index);
                char intergerValue = string.charAt(index);
                resultString = resultString + pair.getKey() + intergerValue;
                index = pair.getValue();
            }
            string = resultString;
        }
        return string;
        // CRIO_SOLUTION_END_MODULE_L1_PROBLEMS

        // CRIO_UNCOMMENT_START_MODULE_L1_PROBLEMS
        //return "";
        // CRIO_UNCOMMENT_END_MODULE_L1_PROBLEMS
    }

    public static void main(String[] args) throws IOException {
        Scanner scanner = new Scanner(System.in);
        int num = scanner.nextInt();
        scanner.close();
        String result = new CountAndSay().countAndSay(num);
        System.out.print(result);
    }
}
