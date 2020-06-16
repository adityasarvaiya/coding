import java.io.*;
import java.util.*;

public class PlusOne {
    // Implement your solution by completing the below function
    public int[] plusOne(int[] digits) {
        // CRIO_SOLUTION_START_MODULE_L1_PROBLEMS
        int carry = 0;
        digits[digits.length - 1] += 1;
        for (int i = digits.length - 1; i >= 0; i--) {
            int sum = digits[i] + carry;
            digits[i] = sum % 10;
            if (sum > 9)
                carry = 1;
            else
                carry = 0;
        }

        if (carry > 0) {
            int[] result = new int[1 + digits.length];
            System.arraycopy(new int[] { carry }, 0, result, 0, 1);
            System.arraycopy(digits, 0, result, 1, digits.length);
            return result;
        }
        return digits;
        // CRIO_SOLUTION_END_MODULE_L1_PROBLEMS

        // CRIO_UNCOMMENT_START_MODULE_L1_PROBLEMS
        //return new int[]{0};
        // CRIO_UNCOMMENT_END_MODULE_L1_PROBLEMS
    }

    public static void main(String[] args) throws IOException {
        BufferedReader in = new BufferedReader(new InputStreamReader(System.in));
        String[] input = in.readLine().split(" ");
        int[] digits = new int[input.length];
        for (int i = 0; i < input.length; ++i) {
            digits[i] = Integer.parseInt(input[i]);
        }

        int[] result = new PlusOne().plusOne(digits);
        for (int i = 0; i < result.length; ++i) {
            System.out.print(result[i]);
            if (i != result.length - 1)
                System.out.print(" ");
        }
    }
}