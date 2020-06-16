import java.io.*;
import java.util.*;

public class ReverseInteger {
    // Implement your solution by completing the below function
    public int reverse(int x) {
        // CRIO_SOLUTION_START_MODULE_L1_PROBLEMS
        long reversedNumber = 0;
        while (x != 0) {
            reversedNumber = (reversedNumber * 10) + (x % 10);
            x = x / 10;
        }
        if (reversedNumber <= Integer.MAX_VALUE && reversedNumber >= Integer.MIN_VALUE)
            return (int) reversedNumber;
        else
            return 0;
        // CRIO_SOLUTION_END_MODULE_L1_PROBLEMS

        // CRIO_UNCOMMENT_START_MODULE_L1_PROBLEMS
        //return 0;
        // CRIO_UNCOMMENT_END_MODULE_L1_PROBLEMS
    }

    public static void main(String[] args) throws IOException {
        Scanner scanner = new Scanner(System.in);
        int number = scanner.nextInt();
        scanner.close();

        int result = new ReverseInteger().reverse(number);
        System.out.print(result);
    }
}
