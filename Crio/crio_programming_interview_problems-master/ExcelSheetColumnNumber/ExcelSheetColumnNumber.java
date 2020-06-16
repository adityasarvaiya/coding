import java.io.*;
import java.util.*;

class ExcelSheetColumnNumber {
    // Implement your solution by completing the below function
    public int titleToNumber(String s) {
        // CRIO_SOLUTION_START_MODULE_L1_PROBLEMS
        int res = 0;
        int n = s.length();
        // reverse iteration
        for (int i = 0; i < n; ++i) {
            res = res * 26 + (s.charAt(i) - 'A' + 1);
        }
        return res;
        // CRIO_SOLUTION_END_MODULE_L1_PROBLEMS

        // CRIO_UNCOMMENT_START_MODULE_L1_PROBLEMS
        //return 0;
        // CRIO_UNCOMMENT_END_MODULE_L1_PROBLEMS
    }

    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        String inputString = scanner.next();
        scanner.close();
        int result = new ExcelSheetColumnNumber().titleToNumber(inputString);
        System.out.println(result);
    }
}
