import java.io.*;
import java.util.*;

public class FactorialTrailingZeroes {
    // Implement your solution by completing the below function
    public int trailingZeroes(int n) {
        // CRIO_SOLUTION_START_MODULE_L1_PROBLEMS
        if (n / 5 == 0)
            return 0;
        return n / 5 + trailingZeroes(n / 5);
        // CRIO_SOLUTION_END_MODULE_L1_PROBLEMS

        // CRIO_UNCOMMENT_START_MODULE_L1_PROBLEMS
        //return -1;
        // CRIO_UNCOMMENT_END_MODULE_L1_PROBLEMS
    }

    public static void main(String[] args) throws IOException {
        Scanner scanner = new Scanner(System.in);
        int number = scanner.nextInt();
        scanner.close();
        int result = new FactorialTrailingZeroes().trailingZeroes(number);
        System.out.print(result);
    }
}
