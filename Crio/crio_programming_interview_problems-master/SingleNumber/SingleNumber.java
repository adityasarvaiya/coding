import java.io.*;
import java.util.*;

public class SingleNumber {
    public int singleNumber(int[] nums) {
        // CRIO_SOLUTION_START_MODULE_L1_PROBLEMS
        int num = 0;
        for (int n : nums)
            num ^= n;
        return num;
        // CRIO_SOLUTION_END_MODULE_L1_PROBLEMS

        // CRIO_UNCOMMENT_START_MODULE_L1_PROBLEMS
        //return -1;
        // CRIO_UNCOMMENT_END_MODULE_L1_PROBLEMS
    }

    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);

        int[] numbers = new int[scanner.nextInt()];
        for (int i = 0; i < numbers.length; i++)
            numbers[i] = scanner.nextInt();
        scanner.close();

        int uniqueNumber = new SingleNumber().singleNumber(numbers);
        System.out.print(Integer.toString(uniqueNumber));
    }
}