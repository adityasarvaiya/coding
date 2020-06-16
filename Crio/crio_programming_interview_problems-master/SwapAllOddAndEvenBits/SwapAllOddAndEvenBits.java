import java.io.*;
import java.util.*;

class SwapAllOddAndEvenBits {
    
    // Complete the function below
    public long swapBits(long n) {
        // CRIO_SOLUTION_START_MODULE_L1_PROBLEMS
        long even_bits = n & 0xAAAAAAAA;
        long odd_bits = n & 0x55555555;
        even_bits >>= 1;
        odd_bits <<= 1;
        return (even_bits | odd_bits);
        // CRIO_SOLUTION_END_MODULE_L1_PROBLEMS
    }

    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        long n = scanner.nextLong();
        scanner.close();
        long result = new SwapAllOddAndEvenBits().swapBits(n);
        System.out.println(result);
    }
}
