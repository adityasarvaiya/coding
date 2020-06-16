import java.io.*;
import java.util.*;

public class HappyNumber {
    public String happyNumber(int n) {
        // CRIO_SOLUTION_START_MODULE_L1_PROBLEMS
        HashSet<Integer> set = new HashSet<Integer>();
        set.add(n);
        while (n != 1) {
            int result = 0;
            while (n != 0) {
                result += Math.pow(n % 10, 2);
                n /= 10;
            }
            if (set.contains(result)) {
                return "false";
            }
            set.add(result);
            n = result;
        }
        return "true";
        // CRIO_SOLUTION_END_MODULE_L1_PROBLEMS

    }

    public static void main(String[] args) throws IOException {
        Scanner scanner = new Scanner(System.in);
        int number = scanner.nextInt();
        scanner.close();
        String result = new HappyNumber().happyNumber(number);
        System.out.print(result);
    }
}
