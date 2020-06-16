import java.io.*;
import java.util.*;

class DivideTwoIntegers {
    // Implement your solution by completing the below function
    public int divide(int dividend, int divisor) {
        // CRIO_SOLUTION_START_MODULE_L2_PROBLEMS
        int sign = ((divisor < 0) ^ (dividend < 0)) ? -1 : 1;
        long pDividend = Math.abs((long) dividend);
        long pDivisor = Math.abs((long) divisor);

        int result = 0;
        while (pDividend >= pDivisor) {
            int numShift = 0;
            while (pDividend >= (pDivisor << numShift))
                numShift++;

            numShift--;
            result += 1 << numShift;
            pDividend -= pDivisor << numShift;
        }

        return sign * result;
        // CRIO_SOLUTION_END_MODULE_L2_PROBLEMS

        // CRIO_UNCOMMENT_START_MODULE_L2_PROBLEMS
        // return 0;
        // CRIO_UNCOMMENT_END_MODULE_L2_PROBLEMS
    }

    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);

        int dividend = scanner.nextInt();
        int divisor = scanner.nextInt();
        scanner.close();

        int result = new DivideTwoIntegers().divide(dividend, divisor);
        System.out.println(result);
    }
}
